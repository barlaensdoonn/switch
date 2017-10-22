#!/usr/bin/python3
# gpio basic with Power Switch Tail (PWST)
# 8/3/17
# updated 10/21/17

# must start pigpio as daemon before running scripts: sudo pigpiod
# succesful calls to pigpio methods seem to return 0
# this sketch has pi's gpio pin 7 connected to PWST's 1 [+in] and ground to PWST's 2 [-in]

import os
import time
import logging
import gpio_util


def get_dir_path():
    '''get absolute path to script's directory'''
    return os.path.dirname(os.path.realpath(__file__))


def initialize_logger():
    log_path = os.path.join(get_dir_path(), '/ignore/logs/gpio_basic.log')
    logging.basicConfig(filename=log_path, format='%(asctime)s %(levelname)s %(message)s', datefmt='%Y/%m/%d %H:%M:%S', level=logging.DEBUG)
    logging.debug('<> <> <> <> <> <> <> <> <> <> <> <>')


if __name__ == '__main__':
    initialize_logger()

    try:
        switch = 7  # gpio pin controlling relay
        pi = gpio_util.initialize_pigpiod(switch)
        time.sleep(1)

        logging.debug('writing pin 7 high')
        pi.write(7, 1)
        time.sleep(3)

        logging.debug('writing pin 7 low')
        pi.write(7, 0)
    except Exception as e:
        logging.exception('exception encountered, printing traceback:')
    except KeyboardInterrupt:
        logging.info('...user exit received...')
