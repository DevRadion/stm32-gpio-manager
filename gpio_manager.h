#ifndef _GPIO_MANAGER_H
#define _GPIO_MANAGER_H

#include "stm32f3xx_ll_gpio.h"
#include <stddef.h>

typedef struct {
	GPIO_TypeDef *port;
	uint32_t pin;
} GPIOPin;

typedef struct {
	GPIOPin gpio;
	uint32_t pull;
	uint32_t mode;
} GPIOPinConfig;

void gpio_manager_init_pin(GPIOPinConfig* pin_config);

void gpio_manager_init_pins(GPIOPinConfig* pin_configs, size_t pin_count);

#endif // !_GPIO_MANAGER_H
