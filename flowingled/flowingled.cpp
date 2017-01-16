#include <wiringPi.h>
#include <stdio.h>
#include <iostream>

int main(void) {
  if (wiringPiSetup() == -1)
  {
    std::cout << "Wiring pi did not load...\n";
    return -1;
  }

  for (int i = 0; i < 4; ++i)
  {
    pinMode(i, OUTPUT);
  }

  while (1) {
    for (int i = 0; i < 4; i++)
    {
      digitalWrite(i, LOW);
      delay(100);
    }

    for (int i = 0; i < 4; i++)
    {
      digitalWrite(i, HIGH);
      delay(100);
    }
  }
}
