################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all:
	$(MAKE) --no-print-directory pre-build
	$(MAKE) --no-print-directory main-build

# Main-build Target
main-build: libsignal.a

# Tool invocations
libsignal.a: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GCC Archiver'
	ar -r  "libsignal.a" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(ARCHIVES)$(OBJS)$(C_DEPS) libsignal.a
	-@echo ' '

pre-build:
	-make -f fft_test.mk clean && make -f ifft_test.mk clean && make -f dft_test.mk clean && make -f idft_test.mk clean && make -f mk_src_signal.mk clean
	-@echo ' '

post-build:
	-make -f fft_test.mk && make -f ifft_test.mk && make -f dft_test.mk && make -f idft_test.mk && make -f mk_src_signal.mk
	-@echo ' '

.PHONY: all clean dependents main-build pre-build post-build

-include ../makefile.targets
