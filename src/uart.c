#include "uart.h"

int num = 0;

void uart_init(void) {
    const uart_config_t uart_cfg = {
        .baud_rate = 115200,
        .data_bits = UART_DATA_8_BITS,
        .parity = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
        .source_clk = UART_SCLK_APB,
    };

    uart_driver_install(UART, RX_BUF_SIZE, 0, 0, NULL, 0);
    uart_param_config(UART, &uart_cfg);
    uart_set_pin(UART, TXD_PIN, RXD_PIN, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);
}


void tx_task(void *arg) {
    char *tx_data = (char*)malloc(100);
    for(;;) {
        sprintf(tx_data, "Hello world index = %d\r\n", num++);
        uart_write_bytes(UART, tx_data, strlen(tx_data));
        vTaskDelay(2000/portTICK_PERIOD_MS);
    }
}

void rx_task(void *arg) {
    static const char *RX_TASK_TAG = "RX_TASK";
    esp_log_level_set(RX_TASK_TAG, ESP_LOG_INFO);
    uint8_t *data = (uint8_t*)malloc(RX_BUF_SIZE+1);
    for(;;) {
        const int rx_bytes = uart_read_bytes(UART, data, 55, 500/portTICK_PERIOD_MS);
        if(rx_bytes > 0) {
            data[rx_bytes] = 0;
            ESP_LOGI(RX_TASK_TAG, "Read %d bytes: %s", rx_bytes, data);
        }
    }
    free(data);
}