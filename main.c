
#include <stdbool.h>
#include <errno.h>
#include <string.h>
#include <time.h>

#include <applibs/log.h>
#include <applibs/gpio.h>
#include <hw/template_appliance.h>

#include "Delay.h" // External Library

#define TIMER_uS 100000


int main(void)
{
    /* 
    --- Including external library with Azure Sphere ---
    - Required to update CMakeLists.txt
    - Required to add #include
    - Allows use external reference function in main.c
    */ 

    int fd = GPIO_OpenAsOutput(TEMPLATE_LED, GPIO_OutputMode_PushPull, GPIO_Value_High);

    while (true) {
        GPIO_SetValue(fd, GPIO_Value_Low);
        usleep(TIMER_uS); // external function
        GPIO_SetValue(fd, GPIO_Value_High);
        usleep(TIMER_uS); // external function
    }
}