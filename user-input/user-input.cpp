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
    std::cout << "Turn lights on or off?\n";
    std::cin >> usrinput;

    std::cout << endl << endl;

    std::cout << "You entered...\n";
    std::cout << usrinput << std::endl;

    std::cout << endl << endl;

    if (usrinput == "on" || usrinput == "On" || usrinput == "ON")
    {
      std::cout << "Turning lights on...\n";
      std::cout << endl << endl;
      digitalWrite(LedPin, LOW);
    } else if (usrinput == "off" || usrinput == "Off" || usrinput == "OFF")
    {
      std::cout << "Turning lights off...\n";
      std::cout << endl << endl;
      digitalWrite(LedPin, HIGH);
    } else if (usrinput != "on" || usrinput != "off")
    {
      std::cout << "Please only enter a yes or no response.\n";
      std::cout << endl << endl;
    }

  }

  return 0;
}
