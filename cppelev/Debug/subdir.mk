################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../Person.o \
../elevator.o \
../floor.o \
../main.o \
../queue.o \
../scheduler.o 

CPP_SRCS += \
../Person.cpp \
../elevator.cpp \
../floor.cpp \
../main.cpp \
../queue.cpp \
../scheduler.cpp 

OBJS += \
./Person.o \
./elevator.o \
./floor.o \
./main.o \
./queue.o \
./scheduler.o 

CPP_DEPS += \
./Person.d \
./elevator.d \
./floor.d \
./main.d \
./queue.d \
./scheduler.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


