
int readSensor()
{
  uint16_t position = qtr.readLineBlack(sensorValues);

  // Serial.println(position);
  int error = 3500 - position;
  return error;
}