
TARGET:=Pencil
TOOLCHAIN_PATH:=/opt/arm/gcc-arm-none-eabi-4_8-2014q1/bin
TOOLCHAIN_PREFIX:=arm-none-eabi
OPTLVL:=3 # Optimization level, can be [0, 1, 2, 3, s].

PROJECT_NAME:=$(notdir $(lastword $(CURDIR)))
TOP:=/usr/share/stm32vldiscovery/an3268/stm32vldiscovery_package
DISCOVERY:=$(TOP)/Utilities
STMLIB:=$(TOP)/Libraries
STD_PERIPH:=$(STMLIB)/STM32F10x_StdPeriph_Driver
CORE:=$(STMLIB)/CMSIS/CM3/CoreSupport
DEVICE:=$(STMLIB)/CMSIS/CM3/DeviceSupport/ST/STM32F10x
STARTUP:=$(STMLIB)/CMSIS/CM3/DeviceSupport/ST/STM32F10x/startup/gcc_ride7
LINKER_SCRIPT:="$(CURDIR)/STM32F100RB_FLASH.ld"

INCLUDE=-I"$(CURDIR)"
INCLUDE+=-I"$(CORE)"
INCLUDE+=-I"$(DEVICE)"
INCLUDE+=-I"$(STD_PERIPH)/inc"
INCLUDE+=-I"$(DISCOVERY)"

# vpath is used so object files are written to the current directory instead
# of the same directory as their source files
vpath %.c $(STD_PERIPH)/src $(DEVICE) $(CORE) $(DISCOVERY) 
vpath %.s $(STARTUP)

ASRC=startup_stm32f10x_md_vl.s

# Project Source Files
SRC=main.c
SRC+=Serial.c
SRC+=stm32f10x_it.c

#CMSIS
SRC+=system_stm32f10x.c

# Discovery Source Files
#SRC+=STM32vldiscovery.c

# Standard Peripheral Source Files
SRC+=misc.c
SRC+=stm32f10x_exti.c
SRC+=stm32f10x_gpio.c
SRC+=stm32f10x_rcc.c
SRC+=stm32f10x_tim.c
SRC+=stm32f10x_usart.c

CDEFS=-DSTM32F10X_MD_VL
CDEFS+=-DUSE_STDPERIPH_DRIVER

MCUFLAGS=-mcpu=cortex-m3 -mthumb
COMMONFLAGS=-O$(OPTLVL) -g -Wall -Werror 
CFLAGS=$(COMMONFLAGS) $(MCUFLAGS) $(INCLUDE) $(CDEFS)

LDLIBS=
LDFLAGS=$(COMMONFLAGS) -fno-exceptions -ffunction-sections -fdata-sections \
        -nostartfiles -Wl,--gc-sections,-T$(LINKER_SCRIPT)

#####
#####

OBJ = $(SRC:%.c=%.o) $(ASRC:%.s=%.o)

CC=$(TOOLCHAIN_PATH)/$(TOOLCHAIN_PREFIX)-gcc
LD=$(TOOLCHAIN_PATH)/$(TOOLCHAIN_PREFIX)-gcc
OBJCOPY=$(TOOLCHAIN_PATH)/$(TOOLCHAIN_PREFIX)-objcopy
AS=$(TOOLCHAIN_PATH)/$(TOOLCHAIN_PREFIX)-as
AR=$(TOOLCHAIN_PATH)/$(TOOLCHAIN_PREFIX)-ar
GDB=$(TOOLCHAIN_PATH)/$(TOOLCHAIN_PREFIX)-gdb


all: STM32F100RB_FLASH.ld $(OBJ)
	$(CC) -o $(TARGET).elf $(LDFLAGS) $(OBJ)	$(LDLIBS)
	$(OBJCOPY) -O ihex   $(TARGET).elf $(TARGET).hex
	$(OBJCOPY) -O binary $(TARGET).elf $(TARGET).bin

STM32F100RB_FLASH.ld:
	@echo "Please copy STM32F100RB_FLASH.ld to the current directory."
	@false

.PHONY: clean

clean:
	rm -f $(OBJ)
	rm -f $(TARGET).elf
	rm -f $(TARGET).hex
	rm -f $(TARGET).bin
