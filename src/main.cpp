#include "mbed.h"
#include "rtos.h"
#include "TextLCD.h"

DigitalIn btn(PA_0);
AnalogIn pot(PA_1);

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
      while (true) {
      for ( int i=0; i<8; i++ ){
        if (pot>=0.6){
          delay = 220 - round(200*pot);
          light(*leds[i],delay);
          }
        else if(pot<=0.4){
          delay = 20 + round(200*pot);
          light(*leds[7-i],delay);
          }
        else {
          Thread::wait(100);
        }

      }
    }
}
