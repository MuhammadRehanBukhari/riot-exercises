/*
 * Copyright (C) 2022 HAW Hamburg
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1.
 */

#include <stdio.h>

#include "ztimer.h"
#include "board.h"

void message_callback(void *argument)
{
    char *message = (char *)argument;
    puts(message);
}

int main(void)
{
    puts("This is a timers example");

    /* timer message after 2 seconds */
    ztimer_t timeout;
    timeout.callback = message_callback;
    timeout.arg = "Timeout!";
    ztimer_set(ZTIMER_SEC, &timeout, 2);

    /* blink LED 10 times with 1 second interval */
    for (int i = 0; i < 10; i++) {
        LED0_TOGGLE;
        ztimer_sleep(ZTIMER_MSEC, 1000);
    }

    puts("Blinking finished");

    return 0;
}
