#include <QTRSensors.h>

QTRSensors qtr; 
const uint8_t SensorCount = 8;
uint16_t sensorValues[SensorCount];

float Kp = 0.07; 
float Ki = 0;
float Kd = 0;
float P=0;
float I=0;
float D=0;

int lastError = 0;

const uint8_t maxSpeedLeft = 250;
const uint8_t maxSpeedRight = 250;
const uint8_t baseSpeedLeft = 90;
const uint8_t baseSpeedRight = 90;

int leftForward = 5;  //INB
int leftBackward = 4; //INA
int rightForward = 6;  //INC
int rightBackward = 7;  //IND
int leftSpeedPin = 10;
int rightSpeedPin = 11;

bool onoff = false;

void setup() 
{
  Serial.begin(9600);

  qtr.setTypeAnalog();
  qtr.setSensorPins((const uint8_t[]){A0, A1, A2, A3, A4, A5, A6, A7}, SensorCount);

  pinMode(leftForward, OUTPUT);
  pinMode(leftBackward, OUTPUT);
  pinMode(rightForward, OUTPUT);
  pinMode(rightBackward, OUTPUT);
  pinMode(leftSpeedPin, OUTPUT);
  pinMode(rightSpeedPin, OUTPUT);

  delay(500);
  pinMode(LED_BUILTIN, OUTPUT);
  calibration();
  delay(1000);
}



void loop()
{
  if (Serial.available())
  {
    while(Serial.available() == 0);
    valueRead();
  }
  if (onoff == true)
  {
    robotControl();
  }
  else if(onoff == false)
  {
    Move(0,0);
  }
}




