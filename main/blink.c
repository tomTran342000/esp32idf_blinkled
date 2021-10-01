#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "sdkconfig.h"

#define BLINK_GPIO1 2
#define BLINK_GPIO2 0

void app_main(void)
{
    gpio_reset_pin(BLINK_GPIO1);
    gpio_reset_pin(BLINK_GPIO2);
    /* Set the GPIO as a push/pull output */
    gpio_set_direction(BLINK_GPIO1, GPIO_MODE_OUTPUT);
    gpio_set_direction(BLINK_GPIO2, GPIO_MODE_OUTPUT);
    while(1) {
        /* Blink off (output low) */
        printf("Turning off the LED\n");
        gpio_set_level(BLINK_GPIO1, 0);
        gpio_set_level(BLINK_GPIO2, 0);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        /* Blink on (output high) */
        printf("Turning on the LED\n");
        gpio_set_level(BLINK_GPIO1, 1);
        gpio_set_level(BLINK_GPIO2, 1);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}