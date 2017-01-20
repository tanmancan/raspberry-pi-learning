#include <wiringPi.h>
#include <stdio.h>
#include <iostream>

long SegCode;

int main(void) {
  if (wiringPiSetup() < 0)
  {
    std::cout << "Wiring Pi did not setup...\n";
  }

  for (int i = 0; i < 8; i++)
  {
    pinMode(i, OUTPUT);
  }

  while(1) {
    std::cout << "Enter value...\n";
    std::cin >> SegCode;
    std::cout << std::endl;
    std::cout << "You entered...\n";
    std::cout << SegCode << std::endl;

    digitalWriteByte(SegCode);
  }

  return 0;
}
