#ifndef SENSOR_FUNCTIONS
#define SENSOR_FUNCTIONS

// #include "DHT.h" 
// #include "ESP32Time.h"
// #include "driver/rtc_io.h"

// #include "camera_functions.h"
// #include "memory_functions.h"




// RTC_DATA_ATTR int bootCount = 0;

// #define DHTTYPE DHT11
// #define DHTPIN GPIO_NUM_0//--------------------->>>>> choose different pin 2 works


//!!!!!!! DHT dht(DHTPIN, DHTTYPE); 


// float tempVal = 37.0; 
// float humidityVal = 56.4;

// //ESP32Time rtc;
// ESP32Time rtc(3600);  // offset in seconds GMT+1
 
// // int pictureNumber = 0;
// void RTC_set_date(int hours, int minutes, int seconds, int day, int month, int year){
//     rtc.setTime(hours, minutes, seconds, day,month, year);
// }

// void sensorInit(){
//     dht.begin();
// }

// String getImageName(){
//     String path = "";
//     do{
//           // Take sensor readings
//         tempVal = dht.readTemperature();
//         humidityVal = dht.readHumidity();
//     }
//     while (isnan(tempVal) || isnan(humidityVal));

//     path = "/picture" + String(getNumEEPROM()) + "_" + String(tempVal) + "_" + String(humidityVal) +".jpg";

//     return path;
// }

// void captureDataPicture(){

//     String path = getImageName();
//     takePicture(path);
//     addToImageList(path);

// }

// String getFakeImageName(){
//     String path = "";
//     path = "/picture" + String(getNumEEPROM()) + "_" + String(tempVal) + "_" + String(humidityVal) +".jpg";
//     return path;

    
// }



// void captureFakeDataPicture(){
//     String path = getFakeImageName();
//     takePicture(path);
//     addToImageList(path);

// }




#endif