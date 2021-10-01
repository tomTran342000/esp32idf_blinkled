#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "sdkconfig.h"

#define BLINK_GPIO1 2
#define BLINK_GPIO2 0

int count = 0;

void blink_led(void *led){
    gpio_pad_select_gpio(BLINK_GPIO1);
    gpio_pad_select_gpio(BLINK_GPIO2);
    gpio_set_direction(BLINK_GPIO1, GPIO_MODE_OUTPUT);
    gpio_set_direction(BLINK_GPIO2, GPIO_MODE_OUTPUT);
    
    while (1)
    {
        gpio_set_level(BLINK_GPIO1,0);
        gpio_set_level(BLINK_GPIO2,1);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        count++;
        gpio_set_level(BLINK_GPIO1,1);
        gpio_set_level(BLINK_GPIO2,0);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
    
    
}

void app_main(void)
{
    xTaskCreate(&blink_led,"blink_led",512,NULL,5,NULL);
}