//
// Created by ruslan on 9/14/24.
//

#include "gpio_blink.h"
#include "esp_log.h"


#include "driver/gpio.h"
#include "hal/gpio_types.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"


#define delay(x) vTaskDelay(x / portTICK_PERIOD_MS);

_Noreturn void gpio_blink(void) {

    gpio_config_t gpioConfig = {
        .mode = GPIO_MODE_OUTPUT,
        .pin_bit_mask = (1ULL << 2),
    };

    gpio_config(&gpioConfig);

    while (1) {
        gpio_set_level(GPIO_NUM_2, 0);
        delay(1000);
        printf("led ON!\n");

        gpio_set_level(GPIO_NUM_2, 1);
        delay(1000);
        printf("led OFF!\n");
    }
}

