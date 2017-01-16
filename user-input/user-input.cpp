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
  int pinStatus;

  while(1)
  {
    pinStatus = digitalRead(LedPin);
    std::cout << "Pin status\n" << pinStatus << std::endl;

    std::cout << "===========================\n";
    std::cout << "Turn lights on or off?\n";
    std::cin >> usrinput;

    std::cout << std::endl;

    std::cout << "You entered...\n";
    std::cout << usrinput << std::endl << std::endl;

    if (usrinput == "on" || usrinput == "On" || usrinput == "ON")
    {
      if (pinStatus == 0)
      {
        std::cout << "Led is already on...\n\n";
      }else {
        std::cout << "Turning lights on...\n\n";
        digitalWrite(LedPin, LOW);
      }
    } else if (usrinput == "off" || usrinput == "Off" || usrinput == "OFF")
    {
      if (pinStatus == 1)
      {
        std::cout << "Led is already off...\n\n";
      }else {
        std::cout << "Turning lights off...\n\n";
        digitalWrite(LedPin, HIGH);
      }
    } else if (usrinput != "on" || usrinput != "off")
    {
      std::cout << "Please only enter a yes or no response.\n\n";
    }
    std::cout << "===========================\n";
  }

  return 0;
}
