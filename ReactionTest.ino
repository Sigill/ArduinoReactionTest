#include <StopWatch.h>
#include <Wire.h>
#include <SeeedGrayOLED.h>

// This sketch will measure your reaction time to a visual signal.
// When the led turns ON, press the switch as quickly as possible.
// Your average reaction time will be averaged over 8 attempts.

// Oled screen connected to any I2C port.
// Any input digital sensor (a switch for example) connected to D2.
// Led connected to port D3.
const int sensor = 2;
const int signal = 3;

void setup() {
  pinMode(sensor, INPUT);
  pinMode(signal, OUTPUT);
  
  Wire.begin();
  SeeedGrayOled.init();             //initialize SEEED OLED display
  SeeedGrayOled.clearDisplay();     //Clear Display.
  SeeedGrayOled.setNormalDisplay(); //Set Normal Display Mode
  SeeedGrayOled.setVerticalMode();  // Set to vertical mode for displaying text
  SeeedGrayOled.setGrayLevel(12);
}

void loop() { 
  int v = 0;
  
  for(int i = 0; i < 8; ++i) {
    StopWatch watch(StopWatch::MILLIS);
    int d = random(2000, 6000);
    long timeout = millis() + d;
    boolean startAgain = false;
    
    while(true) {
      if(millis() >= timeout)
        break;
        
      if(digitalRead(sensor)) {
        SeeedGrayOled.setTextXY(10, 0);
        SeeedGrayOled.putString("Too soon!");
        delay(1000);
        startAgain = true;
        break;
      }
    }
    
    if(startAgain) {
      --i;
    } else {
      watch.start();
      digitalWrite(signal, 1);
      while(!digitalRead(sensor));
      watch.stop();
      digitalWrite(signal, 0);
      v += watch.elapsed();
      SeeedGrayOled.setTextXY(i, 0);
      SeeedGrayOled.putNumber(watch.elapsed());
    }
    delay(500);
  }
  
  SeeedGrayOled.setTextXY(11, 0);
  SeeedGrayOled.putNumber(v >> 3);
  while(!digitalRead(sensor));
  
  for(int i = 0; i < 8; ++i) {
    SeeedGrayOled.setTextXY(i, 0);
    SeeedGrayOled.putString("         ");
  }
}
