const int TheLed=13;
int inVal = 0;

void setup(void)
{
    pinMode(TheLed,OUTPUT);
    Serial.begin(9600);
}

void loop(void)
{  
    if(Serial.available() > 0)
    {
         inVal = Serial.read();
         Serial.flush();
         //Serial.println(inVal);
        if(inVal == 'a')
        {
            digitalWrite(TheLed,HIGH);
        }
        else if(inVal == 'b')
        {
            digitalWrite(TheLed,LOW);
        } 
        else
        {
            digitalWrite(TheLed,HIGH);
        }
    }
}
