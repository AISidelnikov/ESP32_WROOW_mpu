#include "spi.h"

static const char *TAG = "MAIN";
static esp_err_t error;
static spi_device_interface_config_t stm32;
static spi_device_handle_t  stm32Handle;
int mpu[MPU_ARRAY] = {0};

void app_main() {
    spi_init(&stm32, &stm32Handle);


    for(;;) {
        error = spi_read(mpu, MPU_ARRAY, &stm32Handle);
        ESP_LOGI(TAG,"SPI READ DATA: %d ", error);
        vTaskDelay(250 / portTICK_PERIOD_MS);
    }
}