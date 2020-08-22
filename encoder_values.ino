#include "rotEncoder.h"

RotEncoder rotE(11, 10, 12);// swPin , clkPin , dtPin
RotEncoder rotE2(6, 8, 7);// swPin , clkPin , dtPin

unsigned long printDelay;
void setup() 
{
  Serial.begin(9600); 
}

void loop() 
{
  int count1 = rotE.pushCounter();
  int rotVal1 = rotE.rotVal();

  int count2 = rotE2.pushCounter();
  int rotVal2 = rotE2.rotVal();
  
  if(millis() - printDelay > 1000)
  {
    Serial.print("starting.. ");
    Serial.print(count1);
    Serial.print("  ");
    Serial.print(rotVal1);
    Serial.print(" | ");
    Serial.print(count2);
    Serial.print("  ");
    Serial.print(rotVal2);
    
    Serial.println();
    printDelay = millis();
  }
}
