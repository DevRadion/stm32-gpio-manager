#include "gpio_manager.h"
#include "stm32f3xx_ll_bus.h"

void gpio_manager_enable_clock(GPIO_TypeDef* port);

void gpio_manager_init_pin(GPIOPinConfig* pin_config)
{
	gpio_manager_enable_clock(pin_config->gpio.port);
	
	// Configure GPIO pin mode
	LL_GPIO_SetPinMode(pin_config->gpio.port, pin_config->gpio.pin, pin_config->mode);

	// Configure GPIO pin pull-up/pull-down
	LL_GPIO_SetPinPull(pin_config->gpio.port, pin_config->gpio.pin, pin_config->pull);
}

void gpio_manager_init_pins(GPIOPinConfig* pin_configs, size_t pin_count)
{
	for (int i = 0; i < pin_count-1; i++)
	{
		gpio_manager_init_pin(&pin_configs[i]);
	}
}

void gpio_manager_enable_clock(GPIO_TypeDef* port)
{
	if (port == GPIOA) {
		LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOA);
	}
	else if (port == GPIOB) {
		LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOB);
	}
	else if (port == GPIOC) {
		LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOC);
	}
}