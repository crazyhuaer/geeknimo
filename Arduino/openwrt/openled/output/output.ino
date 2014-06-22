
int val;

void setup(void)
{
   pinMode(13,OUTPUT);
   digitalWrite(13,LOW);
  Serial.begin(9600); 
}


void loop(void)
{
  //Serial.println("123456");
  //Serial.print(0x31);
  //Serial.flush();
  if(Serial.available() > 0)
  {
    val = Serial.read();
    Serial.flush();
    if (val == 0x31)
    {
     digitalWrite(13,HIGH);
    } 
    else
      digitalWrite(13,LOW);
    
  }
  delay(1000);
}
