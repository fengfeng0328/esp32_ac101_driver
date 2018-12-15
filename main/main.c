#include <stdio.h>
#include <stdlib.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "driver/i2s.h"
#include "nvs_flash.h"

#include "AC101_DRV.h"
#include "AC101_CFG.h"

static void alexa__AC101_task(void *pvParameters)
{
	char buf[2048];
	int recv_len=0;
	i2s_start(I2S_NUM_0);
//	Codec_Mute(1);
	while(1)
	{
		recv_len=i2s_read_bytes(I2S_NUM_0,buf,2048,0);
		vTaskDelay(10 / portTICK_PERIOD_MS);
		i2s_write_bytes(I2S_NUM_0,buf,recv_len,0);
	}
}

void app_main() {
	esp_err_t ret = nvs_flash_init();
	if (ret == ESP_ERR_NVS_NO_FREE_PAGES
			|| ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
		ESP_ERROR_CHECK(nvs_flash_erase());
		ret = nvs_flash_init();
	}
	ESP_ERROR_CHECK(ret);

//	audio_recorder_AC101_init_16KHZ_16BIT_1CHANNEL();
//	SET_AudioFormats(0,44100,16,2);
	audio_recorder_AC101_init_44KHZ_16BIT_2CHANNEL();
//	SET_AudioFormats(0,8000,16,2);
	xTaskCreatePinnedToCore(&alexa__AC101_task, "alexa__AC101_task", 8096, NULL,
			2, NULL, 1);
}

