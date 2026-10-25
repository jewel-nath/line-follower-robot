void robotControl()
{
   int error = readSensor();
  PIDcontrol(error);
}

void PIDcontrol(int error) 
{
  P = error;
  I = I + error;
  D = error - lastError;
  lastError = error;
  int motorSpeed = P*Kp + I*Ki + D*Kd;
  
  int motorSpeedLeft, motorSpeedRight; 
  motorSpeedLeft = baseSpeedLeft + motorSpeed;
  motorSpeedRight = baseSpeedRight - motorSpeed;
  
  Move(motorSpeedLeft, motorSpeedRight);  
}
