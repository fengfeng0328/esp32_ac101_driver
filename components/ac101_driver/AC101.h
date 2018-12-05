/*
 * AC101.h
 *
 *  Created on: 2018年1月9日
 *      Author: ai-thinker
 */

#ifndef MAIN_AC101_H_
#define MAIN_AC101_H_

#include "stdint.h"
#define AC101_ADDR	0x1a   //0011010
#define PA_EN_PIN   21
#define PA_EN_PIN_SEL      (1ULL<<PA_EN_PIN)

/*
 * @AC101 I2C Init
 * @return
 *     - ESP_OK Success
 *     - ESP_FAIL Fail
 * */
esp_err_t AC101_i2c_master_init();

void I2C_init();
esp_err_t AC101_init();
void mic_init(void);
uint16_t AC101_read_Reg(uint8_t reg) ;
esp_err_t AC101_Write_Reg(uint8_t reg, uint16_t val);

/*
 * @Please Input Volume Between 0 and 100
 * */
esp_err_t ac101_set_spk_volume(uint8_t volume);


void init_gpio_PA(int en);
void enable_PA(int en);
void codec_mute(int en);


#endif /* MAIN_AC101_H_ */
