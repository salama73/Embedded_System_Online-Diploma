
CC=arm-none-eabi-
CFLAGS=-mcpu=cortex-m4 -gdwarf-2 -g
INCS=-I .
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)
AS=$(wildcard *.s)
ASOBJ=$(AS:.s=.o)
project_name=unit_3_lab_3_cortex_m4

all:$(project_name).bin
	@echo "     bulding     "

%.o:%.s
	$(CC)as.exe  $(CFLAGS)  $< -o $@

%.o: %.c
	$(CC)gcc.exe -c  $(INCS) $(CFLAGS)  $< -o $@
		
$(project_name).elf: $(OBJ) $(ASOBJ)
	$(CC)ld.exe -T linker_script.ld -Map=output.map $(OBJ) $(ASOBJ) -o $@
	cp $(project_name).elf  $(project_name).axf

$(project_name).bin: $(project_name).elf
	$(CC)objcopy.exe -O binary $< $@ 

clean:
	rm -rf *.o *~

clean_all:
	rm *.o *.elf *.bin





