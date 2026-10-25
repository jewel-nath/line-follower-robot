void Move(int speedLeft, int speedRight) 
{
  // if(speedLeft || speedRight)
  //   Serial.println("Speed " + String(speedLeft) + " " + String(speedRight));
  if(speedLeft < 0)
  {
    speedLeft = 0 - speedLeft;
    digitalWrite(leftBackward, HIGH);
    digitalWrite(leftForward, LOW);
  }
  else
  {
    digitalWrite(leftBackward, LOW);
    digitalWrite(leftForward, HIGH);
  }

  if(speedRight < 0)
  {
    speedRight = 0 - speedRight;
    digitalWrite(rightBackward, HIGH);
    digitalWrite(rightForward, LOW);
  }
  else
  {
    digitalWrite(rightBackward, LOW);
    digitalWrite(rightForward, HIGH);
  }

  if(speedLeft > maxSpeedLeft)
    speedLeft = maxSpeedLeft;
  if(speedRight > maxSpeedRight)
    speedRight = maxSpeedRight;

  analogWrite(leftSpeedPin, speedLeft);
  analogWrite(rightSpeedPin, speedRight);
}