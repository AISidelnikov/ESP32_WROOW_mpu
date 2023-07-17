#include "uart.h"
#include "wifi.h"

static const char *TAG = "MAIN";
// static esp_err_t error;
extern int led_state;

void app_main() {
    uart_init();

    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
      ESP_ERROR_CHECK(nvs_flash_erase());
      ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);

    ESP_LOGI(TAG, "ESP_WIFI_MODE_STA");
    wifi_init();
    // xTaskCreate(rx_task, "uart_rx_task", 1024*2, NULL, configMAX_PRIORITIES-1, NULL);
    // xTaskCreate(tx_task, "uart_tx_task", 1024*2, NULL, configMAX_PRIORITIES-2, NULL);
    esp_rom_gpio_pad_select_gpio(LED_PIN);
    gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);

    led_state = 0;
    ESP_LOGI(TAG, "LED Control Web Server is running ... ...\n");
    setup_server();
}