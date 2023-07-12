#include "spi.h"

static const char *TAG = "MAIN";
static esp_err_t error;

void app_main() {
    
    for(;;) {
         vTaskDelay(100 / portTICK_PERIOD_MS);
    }
}