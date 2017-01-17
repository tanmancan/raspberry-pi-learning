#include <wiringPi.h>
#include <stdio.h>
#include <iostream>

const int LedPin = 1;

int main(void) {
  if (wiringPiSetup() == -1)
  {
    std::cout << "Wiring pi did not work...\n";
    return -1;
  }

  pinMode(LedPin, PWM_OUTPUT);

  while(1) {
    for (int i = 0; i < 701; i++)
    {
      pwmWrite(LedPin, i);
      delay(1);
    }
    delay(1000);
    for (int i = 700; i >= 0; i--)
    {
      pwmWrite(LedPin, i);
      delay(1);
    }
  }

}
