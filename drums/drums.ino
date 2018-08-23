#include <SimpleSDAudio.h>
// variables and constants used.
int snare;
int tom1;
int tom2;
int floortom;
int cymbal;
int highhat;
//////////////////////
const int snarepin=A0;
const int tom1pin=A2;
const int tom2pin=A4;
const int floortompin=A6;
const int cymbalpin=A8;
const int highhatpin=A10;
const int threshold = 500;

void setup()
{
  Serial.begin(9600);
 
  if (!SdPlay.init(SSDA_MODE_FULLRATE | SSDA_MODE_MONO | SSDA_MODE_AUTOWORKER)) {
    Serial.println("Error initializing");
    Serial.print("  Last error: ");
    Serial.println(SdPlay.getLastError());
    while(1); // Error while initialization of SD card -> stop.
  } 
  
  setFile("startup.raw");
  SdPlay.play();
  delay(1000);
  Serial.println("Setup finished");
  delay(1000);
}

void setFile(char * fileName)
{
  if(!SdPlay.setFile(fileName)) {
    Serial.print("Error setting file: ");
    Serial.println(fileName);
  }   
}

void playFile(char * fileName)
{
    setFile(fileName);
    SdPlay.play();
    Serial.println(fileName);
    delay(100);
//    while(!SdPlay.isStopped()) {
//  ; // no SdPlay.worker() required anymore :-)
//  }
}

void loop()
{
  snare=analogRead(snarepin);
  tom1=analogRead(tom1pin);
  tom2=analogRead(tom2pin);
  floortom=analogRead(floortompin);
  cymbal=analogRead(cymbalpin);
  highhat=analogRead(highhatpin);

  if (snare>threshold)
  {
    playFile("snare.raw");
  }else
  if (tom1>threshold)
  {
    playFile("tom1.raw");
  }else
  if (tom2>threshold)
  {
    playFile("tom2.raw");
  }else
  if (floortom>threshold)
  {
    playFile("floortom.raw");
  }else
  if (cymbal>threshold)
  {
    playFile("cymbal.raw");
  }else      
  if (highhat>threshold)
  {
    playFile("highhat.raw");
  }  
}
