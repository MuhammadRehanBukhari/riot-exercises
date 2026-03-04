#include <stdio.h>
#include "ztimer.h"
#include "board.h"

int main(void)
{
    puts("Starting my custom LED blink program");

    /* blink LED 10 times with 1 second delay */
    for (int i = 0; i < 10; i++) {
        LED0_TOGGLE;                      // turn LED ON/OFF
        puts("LED toggled");
        ztimer_sleep(ZTIMER_SEC, 1);      // wait 1 second
    }

    puts("Program finished");

    return 0;
}
