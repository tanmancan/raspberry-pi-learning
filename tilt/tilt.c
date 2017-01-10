#include <wiringPi.h>
#include <stdio.h>

const int LedPin = 0;
const int TiltPin = 1;

int main(void)
{
  if (wiringPiSetup() == -1) {
    printf("Wiring pi failed to load\n");
    return -1;
  }

  pinMode(LedPin, OUTPUT);
  pinMode(TiltPin, INPUT);

  while(1) {
    int x = digitalRead(TiltPin);
    printf("%d\n", x);
    if (x == 0) {
      digitalWrite(LedPin, LOW);
      printf("led off\n");
    }else {
      digitalWrite(LedPin, HIGH);
      printf("led on\n");
    }
  }

  return 0;
}
