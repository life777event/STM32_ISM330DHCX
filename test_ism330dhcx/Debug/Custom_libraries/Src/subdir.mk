################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Custom_libraries/Src/ism330dhcx_hal.c \
../Custom_libraries/Src/ism330dhcx_ll.c 

OBJS += \
./Custom_libraries/Src/ism330dhcx_hal.o \
./Custom_libraries/Src/ism330dhcx_ll.o 

C_DEPS += \
./Custom_libraries/Src/ism330dhcx_hal.d \
./Custom_libraries/Src/ism330dhcx_ll.d 


# Each subdirectory must supply rules for building sources it contributes
Custom_libraries/Src/ism330dhcx_hal.o: ../Custom_libraries/Src/ism330dhcx_hal.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32G431xx -DUSE_HAL_DRIVER -DDEBUG -c -I../Core/Inc -I../Custom_libraries/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Custom_libraries/Src/ism330dhcx_hal.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Custom_libraries/Src/ism330dhcx_ll.o: ../Custom_libraries/Src/ism330dhcx_ll.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32G431xx -DUSE_HAL_DRIVER -DDEBUG -c -I../Core/Inc -I../Custom_libraries/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Custom_libraries/Src/ism330dhcx_ll.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

