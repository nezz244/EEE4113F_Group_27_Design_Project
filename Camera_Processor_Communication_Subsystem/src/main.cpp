#include <Arduino.h>

// SD Card
#include "FS.h"                // SD Card ESP32
#include "SD_MMC.h"            // SD Card ESP32

// internal buffer
#include <SPIFFS.h>
#include <FS.h>

// include functions
#include "website_functions.h"
#include "camera_functions.h"
#include "memory_functions.h"
// #include "sensor_functions.h"
// #include "eeprom_functions.h"
// #include "sleep_functions.h"

#define MOTION_SENSOR_MODE
// #define TIMER_MODE


#define uS_TO_S_FACTOR 1000000  /* Conversion factor for micro seconds to seconds */
#define TIME_TO_SLEEP  60        /* Time ESP32 will go to sleep (in seconds) */

#define PWDN_GPIO_NUM     32
#define RESET_GPIO_NUM    -1
#define XCLK_GPIO_NUM      0
#define SIOD_GPIO_NUM     26
#define SIOC_GPIO_NUM     27
#define Y9_GPIO_NUM       35
#define Y8_GPIO_NUM       34
#define Y7_GPIO_NUM       39
#define Y6_GPIO_NUM       36
#define Y5_GPIO_NUM       21
#define Y4_GPIO_NUM       19
#define Y3_GPIO_NUM       18
#define Y2_GPIO_NUM        5
#define VSYNC_GPIO_NUM    25
#define HREF_GPIO_NUM     23
#define PCLK_GPIO_NUM     22


void setup() {
   WRITE_PERI_REG(RTC_CNTL_BROWN_OUT_REG, 0); //disable brownout detector
  Serial.begin(115200);

  // // Turns off the ESP32-CAM white on-board LED (flash) connected to GPIO 4
  // pinMode(4, OUTPUT);
  // digitalWrite(4, LOW);
  // rtc_gpio_hold_en(GPIO_NUM_4);
  
  camInit();
  initialiseSPIFFS();
  initialiseSD();

  

#ifdef MOTION_SENSOR_MODE

  esp_sleep_enable_ext0_wakeup(GPIO_NUM_13, 0);
  esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP * uS_TO_S_FACTOR);

  esp_sleep_wakeup_cause_t wakeup_reason = esp_sleep_get_wakeup_cause();
  switch(wakeup_reason){
    // case ESP_SLEEP_WAKEUP_EXT0 : camToSD(); break;
    case ESP_SLEEP_WAKEUP_EXT0 : captureFakeDataPicture(); break;
    case ESP_SLEEP_WAKEUP_TIMER : hostNetwork(); break;
    case ESP_SLEEP_WAKEUP_ULP : Serial.println("Wakeup caused by ULP program"); break;
    default : Serial.printf("Wakeup was not caused by deep sleep: %d\n",wakeup_reason); break;
  }
#endif

#ifdef TIMER_MODE
  esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP * uS_TO_S_FACTOR);
  captureFakeDataPicture();
  hostNetwork();
  
#endif

  
  Serial.println("Going to sleep now");
  delay(1000);
  esp_deep_sleep_start();
}

void loop() {
  // put your main code here, to run repeatedly:
}