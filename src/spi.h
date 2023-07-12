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

#define MISO 12
#define MOSI 13
#define SCLK 14


#endif