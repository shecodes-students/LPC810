// Toggle I/O pins as fast as possible for doing timing measurements.
// See http://jeelabs.org/2014/11/26/getting-started-final-episode/

#include "LPC8xx.h"

void wait() {
    for (int count = 0; count < 2000000; ++count)
	    __ASM("");                      // waste time while drawing current
}

int main () {
    //LPC_SWM->PINENABLE0 |= (1<<2); // disable SWCLK (makes pin 3 a GPIO pin)
    LPC_GPIO_PORT->DIR0 |= 1+2+16; // set PIO0_0, _1 and _4 as outputs


    while (true) {

	    LPC_GPIO_PORT->B0[0] = 1;               // set GPIO 3 high (pin 3)
	    wait();
	    LPC_GPIO_PORT->B0[0] = 0;
	    wait();
	    LPC_GPIO_PORT->B0[1] = 1;               // set GPIO 3 high (pin 3)
	    wait();
	    LPC_GPIO_PORT->B0[1] = 0;               // set GPIO 3 high (pin 3)
	    wait();
	    LPC_GPIO_PORT->B0[4] = 1;               // set GPIO 3 high (pin 3)
	    wait();
	    LPC_GPIO_PORT->B0[4] = 0;               // set GPIO 3 high (pin 3)
	    wait();
	};
}

