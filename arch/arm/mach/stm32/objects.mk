#
#	STM32 Platform objects
#
MACH_STM32_OBJECTS += $(BUILD_DIR)/arch/arm/mach/stm32/stm32.o			# Provides machine description.
MACH_STM32_OBJECTS += $(BUILD_DIR)/arch/arm/mach/stm32/startup.o
MACH_STM32_OBJECTS += $(BUILD_DIR)/arch/arm/mach/stm32/uart.o
MACH_STM32_OBJECTS += $(BUILD_DIR)/arch/arm/mach/stm32/timer.o
MACH_STM32_OBJECTS += $(BUILD_DIR)/arch/arm/mach/stm32/gpio.o


#
#	STM32 HAL drivers.
#
MACH_STM32_OBJECTS += $(BUILD_DIR)/arch/arm/mach/stm32/hal/stm32f1xx_hal_uart.o
MACH_STM32_OBJECTS += $(BUILD_DIR)/arch/arm/mach/stm32/hal/stm32f1xx_hal_usart.o

$(MACH_STM32_OBJECTS): CFLAGS += -I $(BASE)/arch/arm/mach/stm32/hal/inc/ -D STM32F100xB
$(MACH_STM32_OBJECTS): CFLAGS += -I $(BASE)/arch/arm/mach/stm32/CMSIS/Include

MACH_STM32_OBJECTS += $(MACH_STM32_OBJECTS-y)

$(MACH_STM32_OBJECTS): MODULE_NAME="HAL"
#$(MACH_STM32_OBJECTS): CFLAGS += -D BT_CONFIG_MACH_ZYNQ_SYSCLOCK_FREQ=$(BT_CONFIG_MACH_ZYNQ_SYSCLOCK_FREQ)
#$(MACH_STM32_OBJECTS): CFLAGS += -D BT_CONFIG_MACH_ZYNQ_SYSTICK_TIMER_ID=$(BT_CONFIG_MACH_ZYNQ_SYSTICK_TIMER_ID)
#$(MACH_STM32_OBJECTS): CFLAGS += -D BT_CONFIG_MACH_ZYNQ_BOOT_UART_ID=$(BT_CONFIG_MACH_ZYNQ_BOOT_UART_ID)

$(MACH_STM32_OBJECTS): CFLAGS += -DBT_CONFIG_ARCH_ARM_NVIC_BASE=$(BT_CONFIG_ARCH_ARM_NVIC_BASE)
$(MACH_STM32_OBJECTS): CFLAGS += -DBT_CONFIG_ARCH_ARM_NVIC_TOTAL_IRQS=$(BT_CONFIG_ARCH_ARM_NVIC_TOTAL_IRQS)
$(MACH_STM32_OBJECTS): CFLAGS += -DBT_CONFIG_MACH_STM32_TOTAL_GPIOS=$(BT_CONFIG_MACH_STM32_TOTAL_GPIOS)
$(MACH_STM32_OBJECTS): CFLAGS += -DBT_CONFIG_MACH_STM32_GPIO_BASE=$(BT_CONFIG_MACH_STM32_GPIO_BASE)

OBJECTS += $(MACH_STM32_OBJECTS)
