void robotControl()
{
   int error = readSensor();
  //SpecialCase
  // while(sensorValues[0]>=500 && sensorValues[1]>=500 && sensorValues[2]>=500 && sensorValues[3]>=500 && sensorValues[4]>=500){ // A case when the line follower leaves the line
  //   if(previousError>0){       //Turn left if the line was to the left before
  //     Move(0,0);
  //   }
  //   else{
  //     Move(0,0); // Else turn right
  //   }
  //   position = qtr.readLineBlack(sensorValues);
  // }
  
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
