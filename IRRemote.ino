#include <IRremote.h>

int lm=9;//pin 9 of arduino to pin 7 of l293d
int lmr=8;//pin 8 of arduino to pin 2 of l293d 
int rm=10;//pin 10 of arduino to pin 10 of l293d
int rmr=11;//pin 11 of arduino to pin 15 of l293d

int RECV_PIN = 7;//pin 6 of arduino to data pin of ir receiver

void setup()
{
  pinMode(lm,OUTPUT);
  pinMode(lmr,OUTPUT);
  pinMode(rm,OUTPUT);
  pinMode(rmr,OUTPUT);
  Serial.begin(9600);
  IrReceiver.begin(RECV_PIN, ENABLE_LED_FEEDBACK); // Start the receiver
}

void loop()
{
  if (IrReceiver.decode())
    {
     //Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
     IrReceiver.resume(); // Receive the next value
    }
   //bot moves front
    if(IrReceiver.decodedIRData.decodedRawData==0xE718FF00)
    {
      digitalWrite(lm,LOW);
      digitalWrite(lmr,HIGH);
      digitalWrite(rm,HIGH);
      digitalWrite(rmr,LOW);
      Serial.println("Front");
    }
    //bot moves back
    if(IrReceiver.decodedIRData.decodedRawData==0xAD52FF00)
    {
      digitalWrite(lm,HIGH);
      digitalWrite(lmr,LOW);
      digitalWrite(rm,LOW);
      digitalWrite(rmr,HIGH);
      Serial.println("Back");
    }
    //bot moves left
     if(IrReceiver.decodedIRData.decodedRawData==0xF708FF00)
    {
      digitalWrite(lm,LOW);
      digitalWrite(lmr,HIGH);
      digitalWrite(rm,HIGH);
      digitalWrite(rmr,HIGH);
      Serial.println("Left");
    }
    //bot moves right
     if(IrReceiver.decodedIRData.decodedRawData==0xA55AFF00)
    {
      digitalWrite(lm,HIGH);
      digitalWrite(lmr,HIGH);
      digitalWrite(rm,HIGH);
      digitalWrite(rmr,LOW);
      Serial.println("Right");
    }
    //bot stops
    if(IrReceiver.decodedIRData.decodedRawData==0xE31CFF00)
    {
      digitalWrite(lm,HIGH);
      digitalWrite(lmr,HIGH);
      digitalWrite(rm,HIGH);
      digitalWrite(rmr,HIGH);
      Serial.println("Stop");
    }
}