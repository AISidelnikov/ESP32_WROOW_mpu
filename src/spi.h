#ifndef __SPI_H
#define __SPI_H

#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <driver/gpio.h>
#include <driver/spi_master.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"

#include "esp_err.h"
#include "esp_log.h"

#define SPI_CLOCK_SPEED_HZ 100000
#define SPI_DUTY_CYCLE_POS 128

#define HMISO 12
#define HMOSI 13
#define HSCLK 14
#define HCS 15

#define MPU_ARRAY 7

void spi_init(spi_device_interface_config_t *devices_p, spi_device_handle_t *spiHandle);
esp_err_t  spi_read(unsigned char *array, uint8_t lengthAdrray, spi_device_handle_t *spiHandle_p);
#endif