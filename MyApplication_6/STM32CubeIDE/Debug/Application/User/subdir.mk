################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application/User/adc.c \
../Application/User/bme680.c \
../Application/User/cli.c \
../Application/User/clock.c \
../Application/User/crc.c \
../Application/User/dma.c \
../Application/User/fmc.c \
C:/Users/al3xa/STM32CubeIDE/BochCareerCamp/Team1_Repo_LAST/Team1-stanislav/MyApplication_6/Core/Src/freertos.c \
../Application/User/gpio.c \
../Application/User/i2c.c \
../Application/User/ltdc.c \
C:/Users/al3xa/STM32CubeIDE/BochCareerCamp/Team1_Repo_LAST/Team1-stanislav/MyApplication_6/Core/Src/main.c \
../Application/User/spi.c \
C:/Users/al3xa/STM32CubeIDE/BochCareerCamp/Team1_Repo_LAST/Team1-stanislav/MyApplication_6/Core/Src/stm32f4xx_hal_msp.c \
C:/Users/al3xa/STM32CubeIDE/BochCareerCamp/Team1_Repo_LAST/Team1-stanislav/MyApplication_6/Core/Src/stm32f4xx_hal_timebase_tim.c \
C:/Users/al3xa/STM32CubeIDE/BochCareerCamp/Team1_Repo_LAST/Team1-stanislav/MyApplication_6/Core/Src/stm32f4xx_it.c \
../Application/User/syscalls.c \
../Application/User/sysmem.c \
../Application/User/temp_sens.c \
../Application/User/uart.c \
../Application/User/utilities.c 

C_DEPS += \
./Application/User/adc.d \
./Application/User/bme680.d \
./Application/User/cli.d \
./Application/User/clock.d \
./Application/User/crc.d \
./Application/User/dma.d \
./Application/User/fmc.d \
./Application/User/freertos.d \
./Application/User/gpio.d \
./Application/User/i2c.d \
./Application/User/ltdc.d \
./Application/User/main.d \
./Application/User/spi.d \
./Application/User/stm32f4xx_hal_msp.d \
./Application/User/stm32f4xx_hal_timebase_tim.d \
./Application/User/stm32f4xx_it.d \
./Application/User/syscalls.d \
./Application/User/sysmem.d \
./Application/User/temp_sens.d \
./Application/User/uart.d \
./Application/User/utilities.d 

OBJS += \
./Application/User/adc.o \
./Application/User/bme680.o \
./Application/User/cli.o \
./Application/User/clock.o \
./Application/User/crc.o \
./Application/User/dma.o \
./Application/User/fmc.o \
./Application/User/freertos.o \
./Application/User/gpio.o \
./Application/User/i2c.o \
./Application/User/ltdc.o \
./Application/User/main.o \
./Application/User/spi.o \
./Application/User/stm32f4xx_hal_msp.o \
./Application/User/stm32f4xx_hal_timebase_tim.o \
./Application/User/stm32f4xx_it.o \
./Application/User/syscalls.o \
./Application/User/sysmem.o \
./Application/User/temp_sens.o \
./Application/User/uart.o \
./Application/User/utilities.o 


# Each subdirectory must supply rules for building sources it contributes
Application/User/%.o Application/User/%.su Application/User/%.cyclo: ../Application/User/%.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DUSE_BPP=16 -DDEBUG -DSTM32F429xx -c -I../../Core/Inc -I../../Drivers/CMSIS/Include -I../../Drivers/BSP -I../../TouchGFX/target -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../TouchGFX/App -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../../TouchGFX/target/generated -I../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Middlewares/ST/touchgfx/framework/include -I../../TouchGFX/generated/fonts/include -I../../TouchGFX/generated/gui_generated/include -I../../TouchGFX/generated/images/include -I../../TouchGFX/generated/texts/include -I../../TouchGFX/gui/include -I../../TouchGFX/generated/videos/include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/freertos.o: C:/Users/al3xa/STM32CubeIDE/BochCareerCamp/Team1_Repo_LAST/Team1-stanislav/MyApplication_6/Core/Src/freertos.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DUSE_BPP=16 -DDEBUG -DSTM32F429xx -c -I../../Core/Inc -I../../Drivers/CMSIS/Include -I../../Drivers/BSP -I../../TouchGFX/target -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../TouchGFX/App -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../../TouchGFX/target/generated -I../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Middlewares/ST/touchgfx/framework/include -I../../TouchGFX/generated/fonts/include -I../../TouchGFX/generated/gui_generated/include -I../../TouchGFX/generated/images/include -I../../TouchGFX/generated/texts/include -I../../TouchGFX/gui/include -I../../TouchGFX/generated/videos/include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/main.o: C:/Users/al3xa/STM32CubeIDE/BochCareerCamp/Team1_Repo_LAST/Team1-stanislav/MyApplication_6/Core/Src/main.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DUSE_BPP=16 -DDEBUG -DSTM32F429xx -c -I../../Core/Inc -I../../Drivers/CMSIS/Include -I../../Drivers/BSP -I../../TouchGFX/target -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../TouchGFX/App -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../../TouchGFX/target/generated -I../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Middlewares/ST/touchgfx/framework/include -I../../TouchGFX/generated/fonts/include -I../../TouchGFX/generated/gui_generated/include -I../../TouchGFX/generated/images/include -I../../TouchGFX/generated/texts/include -I../../TouchGFX/gui/include -I../../TouchGFX/generated/videos/include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/stm32f4xx_hal_msp.o: C:/Users/al3xa/STM32CubeIDE/BochCareerCamp/Team1_Repo_LAST/Team1-stanislav/MyApplication_6/Core/Src/stm32f4xx_hal_msp.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DUSE_BPP=16 -DDEBUG -DSTM32F429xx -c -I../../Core/Inc -I../../Drivers/CMSIS/Include -I../../Drivers/BSP -I../../TouchGFX/target -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../TouchGFX/App -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../../TouchGFX/target/generated -I../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Middlewares/ST/touchgfx/framework/include -I../../TouchGFX/generated/fonts/include -I../../TouchGFX/generated/gui_generated/include -I../../TouchGFX/generated/images/include -I../../TouchGFX/generated/texts/include -I../../TouchGFX/gui/include -I../../TouchGFX/generated/videos/include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/stm32f4xx_hal_timebase_tim.o: C:/Users/al3xa/STM32CubeIDE/BochCareerCamp/Team1_Repo_LAST/Team1-stanislav/MyApplication_6/Core/Src/stm32f4xx_hal_timebase_tim.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DUSE_BPP=16 -DDEBUG -DSTM32F429xx -c -I../../Core/Inc -I../../Drivers/CMSIS/Include -I../../Drivers/BSP -I../../TouchGFX/target -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../TouchGFX/App -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../../TouchGFX/target/generated -I../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Middlewares/ST/touchgfx/framework/include -I../../TouchGFX/generated/fonts/include -I../../TouchGFX/generated/gui_generated/include -I../../TouchGFX/generated/images/include -I../../TouchGFX/generated/texts/include -I../../TouchGFX/gui/include -I../../TouchGFX/generated/videos/include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/stm32f4xx_it.o: C:/Users/al3xa/STM32CubeIDE/BochCareerCamp/Team1_Repo_LAST/Team1-stanislav/MyApplication_6/Core/Src/stm32f4xx_it.c Application/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DUSE_BPP=16 -DDEBUG -DSTM32F429xx -c -I../../Core/Inc -I../../Drivers/CMSIS/Include -I../../Drivers/BSP -I../../TouchGFX/target -I../../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../../TouchGFX/App -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../../TouchGFX/target/generated -I../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../../Drivers/STM32F4xx_HAL_Driver/Inc -I../../Middlewares/ST/touchgfx/framework/include -I../../TouchGFX/generated/fonts/include -I../../TouchGFX/generated/gui_generated/include -I../../TouchGFX/generated/images/include -I../../TouchGFX/generated/texts/include -I../../TouchGFX/gui/include -I../../TouchGFX/generated/videos/include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-User

clean-Application-2f-User:
	-$(RM) ./Application/User/adc.cyclo ./Application/User/adc.d ./Application/User/adc.o ./Application/User/adc.su ./Application/User/bme680.cyclo ./Application/User/bme680.d ./Application/User/bme680.o ./Application/User/bme680.su ./Application/User/cli.cyclo ./Application/User/cli.d ./Application/User/cli.o ./Application/User/cli.su ./Application/User/clock.cyclo ./Application/User/clock.d ./Application/User/clock.o ./Application/User/clock.su ./Application/User/crc.cyclo ./Application/User/crc.d ./Application/User/crc.o ./Application/User/crc.su ./Application/User/dma.cyclo ./Application/User/dma.d ./Application/User/dma.o ./Application/User/dma.su ./Application/User/fmc.cyclo ./Application/User/fmc.d ./Application/User/fmc.o ./Application/User/fmc.su ./Application/User/freertos.cyclo ./Application/User/freertos.d ./Application/User/freertos.o ./Application/User/freertos.su ./Application/User/gpio.cyclo ./Application/User/gpio.d ./Application/User/gpio.o ./Application/User/gpio.su ./Application/User/i2c.cyclo ./Application/User/i2c.d ./Application/User/i2c.o ./Application/User/i2c.su ./Application/User/ltdc.cyclo ./Application/User/ltdc.d ./Application/User/ltdc.o ./Application/User/ltdc.su ./Application/User/main.cyclo ./Application/User/main.d ./Application/User/main.o ./Application/User/main.su ./Application/User/spi.cyclo ./Application/User/spi.d ./Application/User/spi.o ./Application/User/spi.su ./Application/User/stm32f4xx_hal_msp.cyclo ./Application/User/stm32f4xx_hal_msp.d ./Application/User/stm32f4xx_hal_msp.o ./Application/User/stm32f4xx_hal_msp.su ./Application/User/stm32f4xx_hal_timebase_tim.cyclo ./Application/User/stm32f4xx_hal_timebase_tim.d ./Application/User/stm32f4xx_hal_timebase_tim.o ./Application/User/stm32f4xx_hal_timebase_tim.su ./Application/User/stm32f4xx_it.cyclo ./Application/User/stm32f4xx_it.d ./Application/User/stm32f4xx_it.o ./Application/User/stm32f4xx_it.su ./Application/User/syscalls.cyclo ./Application/User/syscalls.d ./Application/User/syscalls.o ./Application/User/syscalls.su ./Application/User/sysmem.cyclo ./Application/User/sysmem.d ./Application/User/sysmem.o ./Application/User/sysmem.su ./Application/User/temp_sens.cyclo ./Application/User/temp_sens.d ./Application/User/temp_sens.o ./Application/User/temp_sens.su ./Application/User/uart.cyclo ./Application/User/uart.d ./Application/User/uart.o ./Application/User/uart.su ./Application/User/utilities.cyclo ./Application/User/utilities.d ./Application/User/utilities.o ./Application/User/utilities.su

.PHONY: clean-Application-2f-User

