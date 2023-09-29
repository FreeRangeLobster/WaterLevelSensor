#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for SSD1306 display connected using I2C
#define OLED_RESET     -1 // Reset pin
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


#define echoPin 18 // attach pin GPIO18 to pin Echo of JSN-SR04
#define trigPin 5 // attach pin GPIO5 ESP32 to pin Trig of JSN-SR04
#define Enable_pin 15
#define LED 2

long duration; // Variable to store time taken to the pulse
// to reach the receiver
int distance; // Variable to store distance calculated using formula

void setup() {
  // Serial Communication is starting with 9600 of
  // baudrate speed
  Serial.begin(115200);
  // The text to be printed in the serial monitor
  Serial.println("Distance measurement using JSN-SR04T");
  delay(500);



  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT

  pinMode(Enable_pin, OUTPUT);
  digitalWrite(Enable_pin, LOW);  
  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH); 
}


void loop() {
  while (Serial.available())
  {
    display.clearDisplay();
    int PWM_master = Serial.parseInt();           
    int duty_cycle = map(PWM_master, 0, 1023, 0, 255); 
    Serial.println(duty_cycle);


    
    

    digitalWrite(LED, HIGH); 
    delay(500);
    digitalWrite(LED, LOW); 
    delay(500);

  }

}