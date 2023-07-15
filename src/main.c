#include "uart.h"

// static const char *TAG = "MAIN";
// static esp_err_t error;

void app_main() {
    uart_init();
    xTaskCreate(rx_task, "uart_rx_task", 1024*2, NULL, configMAX_PRIORITIES-1, NULL);
    xTaskCreate(tx_task, "uart_tx_task", 1024*2, NULL, configMAX_PRIORITIES-2, NULL);
}