#include <wiringPi.h>
#include <stdio.h>
#include <iostream>

const in LedPin = 0;

int main(void) {
  if (wiringPiSetup() == -1)
  {
    std::cout << "Wiring pi did not work...\n";
    return -1;
  }

  pinMode(LedPin, PWM_OUTPUT);

  while(1) {
    for (int i = 0; i < 1024; i++)
    {
      pwmWrite(LedPin, i);
      delay(5);
    }
    for (int i = 1023; i >= 0; i--)
    {
      pwmWrite(LedPin, i);
      delay(5);
    }
  }

}
