#include <pcmConfig.h>
#include <pcmRF.h>
#include <TMRpcm.h>
#include <SD.h>

#define MOSI 11
#define CS 10
#define SCK 13
#define MISO 12
#define _speakerPin 9
#define buttonPin 2
#define ledPin 13

#define Song_Name "Bruh_Sound_Effect.wav"
#define SD_Success "success.wav"
#define SD_Fail "fail.wav"

TMRpcm tmrpcm;
int buttonState = 0;
void setup() 
{
  // put your setup code here, to run once:
  tmrpcm.speakerPin = _speakerPin;
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  
  Serial.begin(9600);
  if(SD.begin(CS))
  {
    tmrpcm.play(SD_Success);
    Serial.println("Successfully read SD-card");
  }
  if(!SD.begin(CS))
  {
    Serial.println("Failed to read SD-card");
  }
}

void loop() 
{
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(buttonPin);

  if(buttonState == HIGH)
  {
  digitalWrite(ledPin, HIGH);
  tmrpcm.play(Song_Name);
  }
}
