#include <Arduino.h>
#include <SPI.h>
#include <TFT_eSPI.h>
#include <lvgl.h>
#include "display.h"
#include "lv_app/Bcat_circle_pro_1.h"
#include "lv_app/Bcat_circle_pro_2.h"
#include "HardwareSerial.h"
#include "math.h"
#include <stdarg.h>
#include "wavelib/wavelib.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include "hsmodel.cc"
#include <TensorFlowLite_ESP32.h>
#include "tensorflow/lite/c/common.h"
#include "tensorflow/lite/micro/all_ops_resolver.h"
#include "tensorflow/lite/micro/micro_error_reporter.h"
#include "tensorflow/lite/micro/micro_interpreter.h"
#include "tensorflow/lite/schema/schema_generated.h"
#include "Bcat_circle_pro_1.h"
#include <utility>

#define button 34 // 切换页面

// 模型数组
extern const unsigned char model[];
extern const unsigned int model_len;
//创建内存区
constexpr int tensor_arena_size = 2 * 1024;
uint8_t tensor_arena[tensor_arena_size];

void mySerial_test(bool state);
void wave_show(bool state);
void zScoreTransform(float* array, int size);
void minMaxNormalize(std::vector<float>& data);
void daubechies_wavelet_transform(double* data, int length, int J);
std::pair<int, int> analyzeData(float arr[], int n);

HardwareSerial hsSerial(1);
Display screen;

String str = "";
String hsstr = "";
String version = "1.0.1";
uint32_t chipId = 0;

int changepage();
int changepage_2(int Peaks,int Rate);
int getchipID();
int errormessage = 0;
int numPeaks;
int heartRate;
float hsdata[2000];
double hsdata_double[2000];
bool isDataCollectionRunning = false;
bool isFirstPageDisplayed = true;

//初始化函数
void setup()
{

  Serial.begin(115200);
  hsSerial.begin(115200, SERIAL_8N1, 16, 17);//16:RX2 17:TX2 传感器通讯
  
  screen.init();
  pinMode(button, INPUT); // 翻页按钮
  bcat_creat_circle_pro_2();
  set_current_screen(BCAT_NW_FIRST_SCREEN);
  getchipID();

  hsSerial.println("AT+ST:1\r\n");
  delay(50);
  hsSerial.println("AT+BL:0\r\n");
  delay(50);
  hsSerial.println("AT+KF:1\r\n");
  delay(50);

  // 创建错误报告器
  tflite::MicroErrorReporter error_reporter;

  // 创建模型
  const tflite::Model* model = tflite::GetModel(model);
  if (model->version() != TFLITE_SCHEMA_VERSION) {
    //error_reporter.Report("Model schema version mismatch:", args);
    return;
  }

  // 创建操作解析器
  tflite::MicroMutableOpResolver<1> resolver;

  // 创建解释器
  tflite::MicroInterpreter interpreter(model, resolver, tensor_arena, tensor_arena_size, &error_reporter);
  TfLiteStatus status = interpreter.AllocateTensors();
  if (status != kTfLiteOk) {
    //error_reporter.Report("Failed to allocate tensors", args);
    return;
  }

  // 获取输入和输出张量
  TfLiteTensor* input = interpreter.input(0);
  TfLiteTensor* output = interpreter.output(0);

  status = interpreter.Invoke();
  if (status != kTfLiteOk) {
    //error_reporter.Report("Failed to invoke interpreter", args);
    return;
  }
}

//主函数
void loop()
{
  lv_task_handler();

  if (isFirstPageDisplayed && !isDataCollectionRunning) {
        if (digitalRead(button) == LOW) {
            hsSerial.println("AT+ST:1\r\n");
            delay(100);
            wave_show(true);

            //采集信号Min-Max标准化处理
            std::vector<float> data(hsdata, hsdata + 2000);
            minMaxNormalize(data);
            std::copy(data.begin(), data.end(), hsdata);
            isDataCollectionRunning = true;
            mySerial_test(true);

            // 调用函数进行小波变换
            /*for(int i = 0; i < 2000; i++) {
              hsdata_double[i] = static_cast<double>(hsdata[i]);
            }
            daubechies_wavelet_transform(hsdata_double, 2000, 7);*/

            /*处理,得到结论*/
            std::pair<int, int> result = analyzeData(hsdata, 2500);
            numPeaks = result.first;
            heartRate = result.second;

            // 数据采集完成后，翻转到下一页
            if (BCAT_NW_FIRST_SCREEN == get_current_screen() && !bcat_circle_pro_2_done())
                return;
            else if (BCAT_NW_SECOND_SCREEN == get_current_screen() && !bcat_circle_pro_1_done())
                return;
            isFirstPageDisplayed = false;
            isDataCollectionRunning = false;    
            changepage_2(numPeaks, heartRate);
            
        }
    }
  else if (!isFirstPageDisplayed) {
        if (digitalRead(button) == LOW) {
            // 长按按钮，翻转到第一页
            if (BCAT_NW_FIRST_SCREEN == get_current_screen() && !bcat_circle_pro_2_done())
                return;
            else if (BCAT_NW_SECOND_SCREEN == get_current_screen() && !bcat_circle_pro_1_done())
                return;
            isFirstPageDisplayed = true;
            changepage_2(numPeaks, heartRate);
            delay(200);
        }
    }  
}

void wave_show(bool state)
{
  int counts = 2500;
  int currentCount = 0;
  if(state == true)
  {
    while(hsSerial.available() > 0 || counts >= 0)
    {
      char incomingChar = (char)hsSerial.read();
      if (incomingChar == '\n') 
        {
          int index = hsstr.indexOf("U2:");
          if (index != -1) 
          {
            //采集数据处理
            String numStr = hsstr.substring(index + 3); // 从 "U2:" 后面的位置开始截取子串
            float num = numStr.toFloat(); // 执行数学运算
            float result = num * 3.300 / 387; //3.3V下的387为基准值
            //采集数据储存
            if(currentCount < 2000){
              hsdata[currentCount] = result;//存入数组
              currentCount++;
            }
            //采集数据整理发送
            String formattedNumStr = "/*" + String(result, 3) + "," + String(counts) + "*/";//以特定协议进行波形显示
            Serial.println(formattedNumStr); // 打印数字部分
          }   
          counts --;
          hsstr = "";  
        } 
      else 
        hsstr += incomingChar;

      if(counts <= 0)
      {
        hsSerial.println("AT+ST:0\r\n");
        delay(100);
        while (hsSerial.available() > 0) 
          char c = hsSerial.read();  // 读取并丢弃缓冲区中的数据
        return;
      }
    }
  }
  return;
}

void zScoreTransform(float* array, int size) {
    // 计算平均值
    float sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += array[i];
    }
    float mean = sum / size;

    // 计算标准差
    float sq_diff_sum = 0;
    for (int i = 0; i < size; ++i) {
        sq_diff_sum += (array[i] - mean) * (array[i] - mean);
    }
    float std_dev = sqrt(sq_diff_sum / size);

    // 防止除以零
    std_dev += 1e-7;

    // 应用Z-score变换
    for (int i = 0; i < size; ++i) {
        array[i] = (array[i] - mean) / std_dev;
    }
}

int changepage() // 翻页
{
  int button2StateTime = 0;
  if (digitalRead(button) == LOW)
  {
    button2StateTime = millis();
  }
  while (digitalRead(button) == LOW)
  {
    if (millis() - button2StateTime >= 1000)
    {
      if (BCAT_NW_FIRST_SCREEN == get_current_screen())
      {
          bcat_circle_pro_2_noready();
          bcat_screen_out_all(lv_scr_act(), 0);
          set_current_screen(BCAT_NW_SECOND_SCREEN);
          bcat_creat_circle_pro_1();
          
      }
      else if (BCAT_NW_SECOND_SCREEN == get_current_screen())
      {
          bcat_circle_pro_1_noready();
          bcat_reset_heart();
          bcat_screen_out_all(lv_scr_act(), 0);
          set_current_screen(BCAT_NW_FIRST_SCREEN); 
          bcat_creat_circle_pro_2();     
          bcat_set_value_id(chipId);
      }
      break;
    }
  }
  return 0;
}

// Min-Max Normalization函数
void minMaxNormalize(std::vector<float>& data) {
    float minVal = *min_element(data.begin(), data.end());
    float maxVal = *max_element(data.begin(), data.end());

    for (auto& value : data) {
        value = 2 * (value - minVal) / (maxVal - minVal) - 1;
    }
}

int changepage_2(int Peaks,int Rate) // 翻页
{
  if (BCAT_NW_FIRST_SCREEN == get_current_screen())
      {
          bcat_circle_pro_2_noready();
          bcat_screen_out_all(lv_scr_act(), 0);
          set_current_screen(BCAT_NW_SECOND_SCREEN);
          bcat_creat_circle_pro_1();
          set_value_1(Rate);
          set_value_2(Rate);
      }
      else if (BCAT_NW_SECOND_SCREEN == get_current_screen())
      {
          bcat_circle_pro_1_noready();
          bcat_reset_heart();
          bcat_screen_out_all(lv_scr_act(), 0);
          set_current_screen(BCAT_NW_FIRST_SCREEN); 
          bcat_creat_circle_pro_2();     
          bcat_set_value_id(chipId);
      }
  return 0;
}

//获取ESP32标识符
int getchipID()
{
  for (int i = 0; i < 17; i = i + 8)
  {
    chipId |= ((ESP.getEfuseMac() >> (40 - i)) & 0xff) << i;
  }
  Serial.println(chipId);
  return 0;
}

void mySerial_test(bool state)
{
  if(state == true)
  {
    for(int i = 0 ; i < 2000 ; ++i){
      String formattedNumStr = "/*" + String(hsdata[i]) + "*/";//以特定协议进行波形显示
      Serial.println(formattedNumStr); // 打印数字部分
    }
    
  }
  return;
}

void daubechies_wavelet_transform(double* data, int length, int J) {
    wave_object obj; // 创建一个wavelet对象
    wt_object wt; // 创建一个小波变换对象

    // 初始化wavelet对象为Daubechies小波，使用4个小波系数
    obj = wave_init("db7");

    // 执行小波变换
    wt = wt_init(obj, "dwt", length, J);
    setDWTExtension(wt, "sym");
    setWTConv(wt, "direct");

    dwt(wt, data);

    // 这时，wt->output就包含了小波变换的结果
    for(int i = 0; i < length; i++) {
      String daubechiesdata = "/*" + String(wt->output[i]) + "*/";
      Serial.println(daubechiesdata); // 打印数字部分
    }
    // 记得在完成后释放对象
    wave_free(obj);
    wt_free(wt);
}

#include <vector>
#include <utility>

std::pair<int, int> analyzeData(float arr[], int n) {
    std::vector<int> peaks;
     for(int i = 1; i < n - 1; ) {
        if(arr[i] > 0.75 && arr[i] >= arr[i - 1] && arr[i] >= arr[i + 1] && arr[i] >= arr[i + 2] && arr[i] >= arr[i - 2]) {
            peaks.push_back(i);
            // 找到峰值后跳过接下来的400个点
            i += 180;
        } else {
            // 如果没有找到峰值，只移动到下一个点
            i++;
        }
    }
    int numPeaks = peaks.size();
    int peakInterval = 0;
    if(numPeaks > 1) {
        peakInterval = 60000 / (peaks[1] - peaks[0]);
    }
    return std::make_pair(numPeaks, peakInterval);
}