#include <wiringPi.h>
#include <stdio.h>

#define Led 0

int main(void)
{
  if (wiringPiSetup() == -1) {
    printf("setup wiringPi failed !\n");
    return -1;
  }

  pinMode(Led, OUTPUT);

  while(1) {
    digitalWrite(Led, LOW);
    printf("led on...\n");
    delay(500);
    digitalWrite(Led, HIGH);
    printf("...led off\n");
    delay(500);
  }

  return 0;
}
