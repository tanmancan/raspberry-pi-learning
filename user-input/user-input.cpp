#include <wiringPi.h>
#include <stdio.h>
#include <iostream>
#include <string>

const int LedPin = 0;

int main(void) {
  if (wiringPiSetup() == -1)
  {
    std::cout << "Wiring pi did not setup correclty\n";
    return -1;
  }

  pinMode(LedPin, OUTPUT);

  std::string usrinput;

  while(1)
  {
    std::cout << "Turn lights on or off?" << std::endl;
    std::cin >> usrinput;

    if (usrinput == "on")
    {
      std::cout << "Turning lights on..." << std::endl;
      digitalWrite(LedPin, LOW);
    } else if (usrinput == "off")
    {
      std::cout << "Turning lights off..." << std::endl;
      digitalWrite(LedPin, HIGH);
    }

    std::cout << usrinput << std::endl;
  }

  return 0;
}
