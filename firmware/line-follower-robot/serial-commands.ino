void valueRead()  
{
  String s = Serial.readString();

  if(s[0]=='1')
  {
    Serial.println("On....");
    onoff = 1;
  }
  else if(s[0]=='0')
  {
    Serial.println("Off....");
    onoff = 0;
  }
  else
  {
    String c = s.substring(0,2);    
    String number = s.substring(2);

    float v = number.toFloat();
    Serial.print(c + " -> " + String(v));
    
      if(c=="kp") 
        Kp = v;
      else if(c=="ki")
        Ki = v;
      else if(c=="kd")
        Kd = v;
  }
}