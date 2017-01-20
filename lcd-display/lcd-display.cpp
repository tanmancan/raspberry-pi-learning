#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <lcd.h>

const unsigned char Buff[] = "Hellow World!";
const unsigned char myBuff[] = "HI!";

int main(void)
{
  if (wiringPiSetup() < 0)
  {
    std::cout << "Wiring Pi did not setup...\n";
  }

  int fd;

  fd = lcdInit(2,16,4,5,4,0,1,2,3,4,5,6,7);
  if (fd == -1) {
    std::cout << "LCD Init failed\n";
    return 1;
  }

  lcdClear(fd);

  lcdPosition(fd, 0, 0);
  lcdPuts(fd, "Hello There!");

  lcdPosition(fd, 0, 1);
  lcdPuts(fd, "How is it going?");

  while(1) {
    for(int i=0;i<sizeof(Buff)-1;i++) {
      lcdPosition(fd, i, 1);
      lcdPutchar(fd, *(Buff+1));
      delay(200);
    }
    lcdPosition(fd, 0, 1);
    lcdClear(fd);
    for(int i=0;i<16;i++) {
      lcdPosition(fd, i, 0);
      lcdPutchar(fd, *(myBuff+1));
      delay(100);
    }
  }

  return 0;
}
