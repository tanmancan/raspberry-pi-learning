#include <wiringPi.h>
#include <stdio.h>

#define Beeper 0

int main(void)
{
  if (wiringPiSetup() == -1) {
    printf("wiringPi failed to load");
    return -1;
  }

  pinMode(Beeper, OUTPUT);

  while(1) {
    digitalWrite(Beeper, LOW);
    printf("Beeper LOW");
    delay(100);
    digitalWrite(Beeper, HIGH);
    printf("Beeper High");
    delay(100);
  }

  return 0;
}
