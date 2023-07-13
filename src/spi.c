#include "spi.h"

static const char *TAG_SPI = "SPI";
static esp_err_t error;


void spi_init(spi_device_interface_config_t *devices_p, spi_device_handle_t *spiHandle) {
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

    devices_p->address_bits = 0;
    devices_p->command_bits = 0;
    devices_p->dummy_bits = 0;
    devices_p->mode = 0;
    devices_p->duty_cycle_pos = SPI_DUTY_CYCLE_POS;
    devices_p->clock_speed_hz = SPI_CLOCK_SPEED_HZ;
    devices_p->spics_io_num = HCS;
    devices_p->queue_size = 1;
    devices_p->pre_cb = NULL;
    devices_p->post_cb = NULL;
    // stm32.flags = SPI_DEVICE_HALFDUPLEX;   
    
    error = spi_bus_add_device(HSPI_HOST, devices_p, spiHandle);
    ESP_LOGI(TAG_SPI,"SPI BUS ADD STM32: %d ", error);
}

esp_err_t  spi_read(unsigned char *array, uint8_t lengthAdrray, spi_device_handle_t *spiHandle_p) {
    spi_transaction_t trans = {
        .addr = 0,
        .cmd = 0,
        .length = 8*lengthAdrray,
        .rxlength = 8*lengthAdrray,
        .rx_buffer = array,
    };
    error = spi_device_transmit(*spiHandle_p, &trans);
    ESP_LOGI(TAG_SPI,"SPI TRANSMIT: %d ", error);
    return error;
}