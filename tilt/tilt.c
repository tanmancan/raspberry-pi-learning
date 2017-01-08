#include <wiringPi.h>
#include <stdio.h>

#define LedPin 0
#define TiltPin 1

int main(void)
{
  if (wiringPiSetup() == -1) {
    printf("Wiring pi failed to load\n");
    return -1;
  }

  pinMode(LedPin, OUTPUT);
  pinMode(TiltPin, INPUT);

  while(1) {
    if (digitalRead(TiltPin == 0)) {
      digitalWrite(LedPin, LOW);
      printf("Led is on\n");
    }else {
      digitalWrite(LedPin, HIGH);
      printf("Led Off\n");
    }
  }

  return 0;
}
