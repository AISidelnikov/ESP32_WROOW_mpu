#ifndef _WIFI_H_
#define _WIFI_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include <esp_http_server.h>

#include "esp_wifi.h"
#include "esp_event.h"
#include "freertos/event_groups.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include "esp_netif.h"
#include "driver/gpio.h"
#include <lwip/sockets.h>
#include <lwip/sys.h>
#include <lwip/api.h>
#include <lwip/netdb.h>

#define SSID      ("HUAWEI-0413DP")
#define PASS      ("78GkRR59")
#define EXAMPLE_ESP_MAXIMUM_RETRY  3

#define WIFI_CONNECTED_BIT BIT0
#define WIFI_FAIL_BIT      BIT1

#define LED_PIN 2

static void event_handler(void* arg, esp_event_base_t event_base, int32_t event_id, void* event_data);
void wifi_init(void);
esp_err_t send_web_page(httpd_req_t *req);
esp_err_t get_req_handler(httpd_req_t *req);
esp_err_t led_on_handler(httpd_req_t *req);
esp_err_t led_off_handler(httpd_req_t *req);
httpd_handle_t setup_server(void);

#endif