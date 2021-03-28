################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
G:/103C8/E62_LAB_03_LCD_Driver_EP2/LCD_lib/koibitoex_lcd2.c 

OBJS += \
./LCD_lib/koibitoex_lcd2.o 

C_DEPS += \
./LCD_lib/koibitoex_lcd2.d 


# Each subdirectory must supply rules for building sources it contributes
LCD_lib/koibitoex_lcd2.o: G:/103C8/E62_LAB_03_LCD_Driver_EP2/LCD_lib/koibitoex_lcd2.c LCD_lib/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F303xC -c -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/CMSIS/Include -I"G:/103C8/E62_LAB_03_LCD_Driver_EP2/LCD_lib" -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"LCD_lib/koibitoex_lcd2.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

