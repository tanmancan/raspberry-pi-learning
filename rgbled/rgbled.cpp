#include <wiringPi.h>
#include <softPwm.h>
#include <stdio.h>
#include <iostream>

const int LedRed = 0;
const int LedGreen = 1;
const int LedBlue = 2;


void ledPwmCreate(void) {
  softPwmCreate(LedRed,  0, 100);
  softPwmCreate(LedGreen,0, 100);
  softPwmCreate(LedBlue, 0, 100);
}

int main(void) {
  if(wiringPiSetup() < 0){
    std::cout << "WiringPi did not initialize...\n";
    return -1;
  }

  ledPwmCreate();

  while(1){
    for(int i = 0; i < 100; i++){
      softPwmWrite(LedRed,   100 - i);
      softPwmWrite(LedGreen, 0 + i);
      softPwmWrite(LedBlue,  100 - i);
      delay(100);
    }
  }

  return 0;
}
