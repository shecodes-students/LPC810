// Toggle I/O pins as fast as possible for doing timing measurements.
// See http://jeelabs.org/2014/11/26/getting-started-final-episode/

#include "LPC8xx.h"

int main () {
    LPC_SWM->PINENABLE0 |= (1<<2); // disable SWCLK (makes pin 3 a GPIO pin)
    LPC_GPIO_PORT->DIR0 |= (1<<3); // set PIO0_3 as output

    while (true) {
		for (int count = 0; count < 2000000; ++count)
			__ASM("");                      // waste time while drawing current
		LPC_GPIO_PORT->B0[3] = 1;               // set GPIO 3 high (pin 3)
		for (int count = 0; count < 2000000; ++count)
			__ASM("");                      // waste time while drawing current
		LPC_GPIO_PORT->B0[3] = 0;
	};
}
