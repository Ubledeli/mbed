#include "mbed.h"
#include "rtos.h"

DigitalIn btn(PA_0);

int light(DigitalOut &led,int delay){
  led = !led;
  Thread::wait(delay);
  led = !led;
  return 0;
}
int main() {
  DigitalOut *leds[8];
      for ( int i=0; i<8; i++ )
      {
          leds[i] = new DigitalOut(PinName(PE_8+i));
      }
int delay = 50;
int m = -1;
    while (true) {
      for ( int i=0; i<8; i++ ){
        delay+=m;
        light(*leds[i],delay);
        if (btn ){
          //int a = (i + 4) % 8;
          //light(*leds[(i + 4) % 8],delay);
          delay = 20;
        }
      }
      if (delay > 100){
        m = -1;
      }
      else if (delay < 20){
        m = 1;
      }
    }
}
