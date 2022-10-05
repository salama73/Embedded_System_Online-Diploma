################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/Keypad.c \
../HAL/LCD.c 

OBJS += \
./HAL/Keypad.o \
./HAL/LCD.o 

C_DEPS += \
./HAL/Keypad.d \
./HAL/LCD.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/Keypad.o: ../HAL/Keypad.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/Deploma Assignment/Deploma Assignment_Code/Second_term/unit_8/lesson_3/usart_stm32/HAL/inc" -I"D:/Deploma Assignment/Deploma Assignment_Code/Second_term/unit_8/lesson_3/usart_stm32/stm32_f103c6_Drivers/inc" -I"D:/Deploma Assignment/Deploma Assignment_Code/Second_term/unit_8/lesson_3/usart_stm32/stm32_f103c6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/Keypad.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
HAL/LCD.o: ../HAL/LCD.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/Deploma Assignment/Deploma Assignment_Code/Second_term/unit_8/lesson_3/usart_stm32/HAL/inc" -I"D:/Deploma Assignment/Deploma Assignment_Code/Second_term/unit_8/lesson_3/usart_stm32/stm32_f103c6_Drivers/inc" -I"D:/Deploma Assignment/Deploma Assignment_Code/Second_term/unit_8/lesson_3/usart_stm32/stm32_f103c6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/LCD.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

