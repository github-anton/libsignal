################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../conv.c \
../dft.c \
../fft.c \
../trig.c \
../vector.c 

OBJS += \
./conv.o \
./dft.o \
./fft.o \
./trig.o \
./vector.o 

C_DEPS += \
./conv.d \
./dft.d \
./fft.d \
./trig.d \
./vector.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"/home/anton/workspace/RKS/libsignal/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


