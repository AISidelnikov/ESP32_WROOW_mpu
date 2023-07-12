#include "spi.h"

static const char *TAG_SPI = "SPI";
static esp_err_t error;

static spi_device_interface_config_t stm32;
static spi_device_handle_t  stm32Handle;

void spi_init(void) {
    spi_bus_config_t hbuscfg = {
        .miso_io_num = HMISO,
        .mosi_io_num = HMOSI,
        .sclk_io_num = HSCLK,
        .quadwp_io_num = -1,
        .quadhd_io_num = -1,
        .flags = SPICOMMON_BUSFLAG_MASTER,
    };

    error = spi_bus_initialize(HSPI_HOST, &hbuscfg, SPI_DMA_CH1);
    ESP_LOGI(TAG_SPI, "HSPI init: %d ", error);

    stm32.address_bits = 0;
    stm32.command_bits = 0;
    stm32.dummy_bits = 0;
    stm32.mode = 0;
    stm32.duty_cycle_pos = SPI_DUTY_CYCLE_POS;
    stm32.clock_speed_hz = SPI_CLOCK_SPEED_HZ;
    stm32.spics_io_num = HCS;
    stm32.queue_size = 1;
    stm32.pre_cb = NULL;
    stm32.post_cb = NULL;
    stm32.flags = SPI_DEVICE_HALFDUPLEX;   
    
    error = spi_bus_add_device(HSPI_HOST, &stm32, &stm32Handle);
    ESP_LOGI(TAG_SPI,"SPI BUS ADD STM32: %d ", error);
}

void spi_read(void) {
    
}