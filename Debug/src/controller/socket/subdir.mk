################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/controller/socket/SocketSchnittstelle.cpp 

OBJS += \
./src/controller/socket/SocketSchnittstelle.o 

CPP_DEPS += \
./src/controller/socket/SocketSchnittstelle.d 


# Each subdirectory must supply rules for building sources it contributes
src/controller/socket/%.o: ../src/controller/socket/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/include/mysql++ -I/usr/include/mysql -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


