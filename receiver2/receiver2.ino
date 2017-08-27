/* 
Created by Yvan / https://Brainy-Bits.com

This code is in the public domain...
You can: copy it, use it, modify it, share it or just plain ignore it!
Thx!

*/


// NRF24L01 Module Tutorial - Code for Receiver using Arduino UNO

//Include needed Libraries at beginning
#include "nRF24L01.h" // NRF24L01 library created by TMRh20 https://github.com/TMRh20/RF24
#include "RF24.h"
#include "SPI.h"

#define LED_PIN 6

int ReceivedMessage[1] = {000}; // Used to store value received by the NRF24L01

RF24 radio(7,8); // NRF24L01 used SPI pins + Pin 7 and 8 on the UNO

const uint64_t pipe = 0xE6E6E6E6E6E6; // Needs to be the same for communicating between 2 NRF24L01 


void setup(void){

  Serial.begin(115200);
  Serial.println(F("MultiNodes SLAVE"));
  
radio.begin(); // Start the NRF24L01

radio.openReadingPipe(1,pipe); // Get NRF24L01 ready to receive

radio.startListening(); // Listen to see if information received

pinMode(LED_PIN, OUTPUT); // Set RGB Stick UNO pin to an OUTPUT
}

void loop(void){

while (radio.available())
{
  radio.read(ReceivedMessage, 1); // Read information from the NRF24L01
  
  if (ReceivedMessage[0] == 111) // Indicates switch is pressed
  {
                // If an ack with payload was received
                Serial.print("Got response ");
                Serial.print(ReceivedMessage[0]);
                Serial.print("\n");
            
  }
  else
  {
                  // If an ack with payload was received
                Serial.print("Got response ");
                Serial.print(ReceivedMessage[0]);
                Serial.print("\n");
  }
  delay(1000);
  }
}
