#include "mbed.h"
#include "rtos.h"

#include "TextLCD.h"
#include "DebounceIn.h"
#include "StepperMotorUni.h"
#include "RPG.h"
#include "KeyPad.h"

RPG rotary(PA_1,PC_3,PC_1);
DebounceIn btn(PA_0);
AnalogIn pot(PA_1);
TextLCD lcd(PD_0, PD_2, PD_4, PD_6, PB_3, PB_5); // rs, e, d4-d7
Timer t;

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
int p =0;
int dir = 0;
bool down = false;
int delay = 5;
      while (true) {
        dir = rotary.dir();
        Thread::wait(delay);
        p += dir;
        lcd.printf("%d        \n                ",p,0,0);
        if (rotary.pb())
        {
            p = 0;
        }
        /*
          while(btn){
            if (!down){
              t.start();
              lcd.printf("%d\n                ",p,0,0);
              p++;
            }
             down = true;


          }
          t.stop();
          down = false;
          Thread::wait(delay);
          */
        //  lcd.printf("    \n");
/*
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
*/
    }
}
