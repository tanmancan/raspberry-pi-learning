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
    std::cout << "off = 0\n";
    std::cout << "a = 2\n";
    std::cout << "b = 4\n";
    std::cout << "c = 8\n";
    std::cout << "d = 16\n";
    std::cout << "e = 32\n";
    std::cout << "f = 64\n";
    std::cout << "g = 128\n";
    std::cout << "--------\n";
    std::cout << "a+ = 1\n";
    std::cout << "b+ = 3\n";
    std::cout << "c+ = 7\n";
    std::cout << "d+ = 15\n";
    std::cout << "e+ = 31\n";
    std::cout << "f+ = 63\n";
    std::cout << "g+ = 127\n";
    std::cout << "--------\n";

    std::cin >> SegCode;
    std::cout << std::endl;
    std::cout << "You entered...\n";
    std::cout << SegCode << std::endl;

    digitalWriteByte(SegCode);
  }

  return 0;
}
