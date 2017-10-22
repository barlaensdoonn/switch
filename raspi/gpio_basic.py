#!/usr/bin/python3
# gpio basic with Power Switch Tail (PWST)
# 8/3/17
# updated 10/21/17

# must start pigpio as daemon before running scripts: sudo pigpiod
# succesful calls to pigpio methods seem to return 0
# this sketch has pi's gpio pin 7 connected to PWST's 1 [+in] and ground to PWST's 2 [-in]

import time
import gpio_util


if __name__ == '__main__':
    switch = 7  # gpio pin controlling relay
    pi = gpio_util.initialize_pigpiod(switch)
    time.sleep(1)

    pi.write(7, 1)  # write pin 7 high
    time.sleep(3)
    pi.write(7, 0)  # write pin 7 low
