char val;
int nowSwitchState=0;
int beforeSwitchState=0;
int relayState=0;
void setup() {
  pinMode(13, OUTPUT); 
  pinMode(4,INPUT);
  Serial.begin(9600);  
  digitalWrite(13,LOW);
}
void loop() 
{
  nowSwitchState=digitalRead(4);
  if(nowSwitchState==beforeSwitchState)
  {
    //digitalWrite(13,HIGH);
    if( Serial.available() )       // if data is available to read
     {
    val = Serial.read();         // read it and store it in 'val'
     }
     if( val == 'H' )  
       {
   relayState=HIGH;
    digitalWrite(13, relayState);
       }// turn ON the LED
      else if(val=='L')
      {
        relayState=LOW;
    digitalWrite(13, relayState);
    //switchState=LOW;
     }// otherwise turn it OFF
  }
  else if(nowSwitchState!=beforeSwitchState)
  {
    beforeSwitchState=nowSwitchState;
    digitalWrite(13,!relayState);
  if( Serial.available() )       // if data is available to read
  {
    val = Serial.read();         // read it and store it in 'val'
  }
  if( val == 'H' )  
  {// if 'H' was received
    relayState=HIGH;
    digitalWrite(13, relayState);
  }// turn ON the LED
  else if(val=='L')
  {
    relayState=LOW;
    digitalWrite(13, relayState);
  }// otherwise turn it OFF
  
  delay(100);  
  }// wait 100ms for next reading
}