#include <stdio.h>
#include <string.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "esp_log.h"

#include "stepper_task.h"

static const char *TAG = "main";

TaskHandle_t pvTask1 = NULL;
TaskHandle_t pvTask2 = NULL;

void app_main(void)
{
    /* DevKits3  */
    static stepper_conf_t task1_conf = {
        .name = "Task 1",
        .speed = 100,

        .stepper_driver_conf.direction_pin = GPIO_NUM_12,
        .stepper_driver_conf.step_pin = GPIO_NUM_8,
        .stepper_driver_conf.enable_pin = GPIO_NUM_9,
        .stepper_driver_conf.uart_port = UART_NUM_1,
        .stepper_driver_conf.rx_pin = GPIO_NUM_18,
        .stepper_driver_conf.tx_pin = GPIO_NUM_17,
        .stepper_driver_conf.baud_rate = 115200,
        .stepper_driver_conf.channel = RMT_CHANNEL_0,
    };
    /*
    static stepper_conf_t task2_conf = {
        .name = "Task 2",
        .speed = 200,

        .stepper_driver_conf.direction_pin = GPIO_NUM_4,
        .stepper_driver_conf.step_pin = GPIO_NUM_5,
        .stepper_driver_conf.enable_pin = GPIO_NUM_18,
        .stepper_driver_conf.uart_port = UART_NUM_2,
        .stepper_driver_conf.rx_pin = GPIO_NUM_16,
        .stepper_driver_conf.tx_pin = GPIO_NUM_17,
        .stepper_driver_conf.baud_rate = 115200,
        .stepper_driver_conf.channel = RMT_CHANNEL_1
    };
    */
    ESP_LOGI(TAG, "Starting Task 1");
    xTaskCreatePinnedToCore(&stepper_task, "Task 1", 4096, &task1_conf, 5, &pvTask1, 1);

    // ESP_LOGI(TAG, "Starting Task 2");
    // xTaskCreatePinnedToCore(&stepper_task, "Task 2", 4096,  &task2_conf, 5, &pvTask2, 1);
}
