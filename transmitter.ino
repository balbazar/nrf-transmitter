#include  <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"

RF24 radio(7, 8);
int bufferSize = 32;
const byte address[6] = "00002";

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

void loop() {
  char bufferArray [bufferSize] = "";
  
  while(Serial.available() > 0){
    String readLine = Serial.readString();
    Serial.println(readLine);
    readLine.toCharArray(bufferArray,bufferSize);
  }
  Serial.println("gonderdi");
  const char text[] = "Hello World";
  radio.write(&text, sizeof(text));
  delay(1000);

}
