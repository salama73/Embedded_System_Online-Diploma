
CC=arm-none-eabi-
CFLAGS=-mcpu=cortex-m3 -gdwarf-2
INCS=-I .
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)
AS=$(wildcard *.s)
ASOBJ=$(AS:.s=.o)
project_name=learn_in_depth_cortex_m3

all:$(project_name).bin
	@echo "     bulding     "

%.o:%.s
	$(CC)as.exe  $(CFLAGS)  $< -o $@

%.o: %.c
	$(CC)gcc.exe -c  $(INCS) $(CFLAGS)  $< -o $@
		
$(project_name).elf: $(OBJ) $(ASOBJ)
	$(CC)ld.exe -T linker_script.ld -Map=output.map $(OBJ) $(ASOBJ) -o $@

$(project_name).bin: $(project_name).elf
	$(CC)objcopy.exe -O binary $< $@

clean:
	rm -rf *.o *~




