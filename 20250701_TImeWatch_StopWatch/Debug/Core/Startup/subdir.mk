################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Core/Startup/startup_stm32f411retx.s 

OBJS += \
./Core/Startup/startup_stm32f411retx.o 

S_DEPS += \
./Core/Startup/startup_stm32f411retx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Startup/%.o: ../Core/Startup/%.s Core/Startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -I"C:/harman/RTOS/20250701_TImeWatch_StopWatch/Core/ap" -I"C:/harman/RTOS/20250701_TImeWatch_StopWatch/Core/driver/Button" -I"C:/harman/RTOS/20250701_TImeWatch_StopWatch/Core/driver/FND" -I"C:/harman/RTOS/20250701_TImeWatch_StopWatch/Core/driver/LedBar" -I"C:/harman/RTOS/20250701_TImeWatch_StopWatch/Core/ap/src" -I"C:/harman/RTOS/20250701_TImeWatch_StopWatch/Core/driver/LCD" -I"C:/harman/RTOS/20250701_TImeWatch_StopWatch/Core/ap/inc" -I"C:/harman/RTOS/20250701_TImeWatch_StopWatch/Core/driver/buzzer" -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-Core-2f-Startup

clean-Core-2f-Startup:
	-$(RM) ./Core/Startup/startup_stm32f411retx.d ./Core/Startup/startup_stm32f411retx.o

.PHONY: clean-Core-2f-Startup

