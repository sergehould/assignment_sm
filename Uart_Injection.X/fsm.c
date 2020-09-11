#include <xc.h>
#include "common/Tick.h"
#include "common/console.h"

#define PB1  _RD6
#define PB2  _RD7

void task1(void) {
	static unsigned long lastTick;		
 	static enum {SM_IDLE,SM_TOGGLE} state=0;

   	switch(state){
		case SM_IDLE:
            if(TickGet()-lastTick > TICK_SECOND/5){
                state = SM_TOGGLE;
			}
            else state = SM_IDLE;
			break;

        case SM_TOGGLE:
            fprintf2(_UART1, "toggling\n");
            lastTick=TickGet();
            state = SM_IDLE;
			break;	
	}
}
