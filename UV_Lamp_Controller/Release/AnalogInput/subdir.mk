################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
..\AnalogInput\AnalogInput.cpp \
..\AnalogInput\ToggleAnalogInput.cpp 

LINK_OBJ += \
.\AnalogInput\AnalogInput.cpp.o \
.\AnalogInput\ToggleAnalogInput.cpp.o 

CPP_DEPS += \
.\AnalogInput\AnalogInput.cpp.d \
.\AnalogInput\ToggleAnalogInput.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
AnalogInput\AnalogInput.cpp.o: ..\AnalogInput\AnalogInput.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Eclipse-neon\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"C:\Eclipse-neon\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\cores\arduino" -I"C:\Eclipse-neon\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\variants\standard" -I"C:\Eclipse-neon\arduinoPlugin\libraries\LiquidCrystal\1.0.7" -I"C:\Eclipse-neon\arduinoPlugin\libraries\LiquidCrystal\1.0.7\src" -I"C:\Eclipse-neon\arduinoPlugin\libraries\ArduinoSTL\1.0.4" -I"C:\Eclipse-neon\arduinoPlugin\libraries\ArduinoSTL\1.0.4\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '

AnalogInput\ToggleAnalogInput.cpp.o: ..\AnalogInput\ToggleAnalogInput.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Eclipse-neon\/arduinoPlugin/packages/arduino/tools/avr-gcc/4.9.2-atmel3.5.4-arduino2/bin/avr-g++" -c -g -Os -Wall -Wextra -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10802 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR   -I"C:\Eclipse-neon\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\cores\arduino" -I"C:\Eclipse-neon\arduinoPlugin\packages\arduino\hardware\avr\1.6.20\variants\standard" -I"C:\Eclipse-neon\arduinoPlugin\libraries\LiquidCrystal\1.0.7" -I"C:\Eclipse-neon\arduinoPlugin\libraries\LiquidCrystal\1.0.7\src" -I"C:\Eclipse-neon\arduinoPlugin\libraries\ArduinoSTL\1.0.4" -I"C:\Eclipse-neon\arduinoPlugin\libraries\ArduinoSTL\1.0.4\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '


