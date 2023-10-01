######################################################################################
#									Definitions		 								 #
######################################################################################
#selection Source Code"*.c" & project Name & Target"*.c-->*.o"
PROJECT_NAME=AutonomousVehicle
SRC=$(wildcard *.c)
TARGET=$(wildcard *.o)  
  ## For every .c file, compile an .o object file
OBJ = $(SRC:.c=.o) 

## Target AVR settings
   ##https://gcc.gnu.org/onlinedocs/gcc/AVR-Options.html
MCU   = atmega32a
F_CPU = 8000000
BAUD = 9600

#selection Toolchain & Options & Defined programs / locations
TOOLCHAIN=avr-objcopy
OPTIONS=-mmcu=$(MCU) -DF_CPU=$(F_CPU)UL
optimizationlevel = -O0
CC = avr-gcc
++ = avr-g++
OBJCOPY = avr-objcopy
OBJDUMP = avr-objdump
AVRSIZE = avr-size
AVRDUDE = avrdude
PROGRAMMER_TYPE = usbasp

######################################################################################
#						our Rules for building process 								 #
######################################################################################
#to clean .hex && .o && .elf
clean:
	@rm  $(PROJECT_NAME).hex $(TARGET).o $(PROJECT_NAME).elf $(TARGET).eeprom $(PROJECT_NAME).lst
	@echo "`date` done" >> log.txt
squeaky_clean:
	@rm -f *.elf *.hex *.obj *.o *.d *.eep *.lst *.lss *.sym *.map *~
	@echo "`date` done" >> log.txt
    ##*~ means all files ending in ~ . Many Unix/Linux systems programs create 
    ##backup files that end in ~ . For example, the emacs and nano editors automatically 
    ##save a backup copy of each file you edit. When it saves a file, the old version gets 
    ##saved using the file name with a tilde ( ~ ) added to the end.



#To compile *.c ---> *.o then generate hex file from group of (*.o)
compile: $(SRC)
	@$(++) $(OPTIONS) $(optimizationlevel) $(TARGET).o $(SRC)
	@$(TOOLCHAIN) -j .text -j .data $(optimizationlevel) ihex $(TARGET).o  $(PROJECT_NAME).hex
	@echo "Succes Compiled"



#Generic Makefile targets.  (Only .hex file is necessary)
all: $(PROJECT_NAME).hex
%.elf: $(SRC)
	$(++) $(SRC) $(optimizationlevel) $(PROJECT_NAME).elf
##    -E                       Preprocess only; do not compile, assemble or link.
##    -S                       Compile only; do not assemble or link.
##    -c                       Compile and assemble, but do not link.
##    -o <file>                Place the output into <file>.
%.hex: %.elf
	$(OBJCOPY) -R .eeprom $(optimizationlevel) ihex $< $@
##$@ is the name of the target being generated, and $< the first prerequisite (usually a source file).
##avr-obcopy -O output-format [-j section-to include]... [-R section-to-remove]... input-file output-file
##avr-objcopy -O ihex -R .eeprom filename.elf filename.hex
%.eeprom: %.elf
	$(OBJCOPY) -j .eeprom -j .text -j .data --change-section-lma .eeprom=0 $(optimizationlevel) ihex $< $@ 



debug:
	@echo
	@echo "Source files:"   $(SRC)
	@echo "MCU, F_CPU, BAUD:"  $(MCU), $(F_CPU), $(BAUD)
	@echo



disasm: disassemble
disassemble: $(TARGET).lst
%.lst: %.elf
	$(OBJDUMP) -S $< > $@
##    i need to take ".elf" ~= "$<" and process it by objdump and output transfer it to $@
##    The -S option will generate a ".s " GNU-assembly source file. ( ",asm " conventionally implies an
##    Atmel-assembly source file, which is different.) If you generated your Makefile with Mfile,
##    you should be able to just "make <whatever>.s ".



# Optionally show how big the resulting program is 
size:  $(PROJECT_NAME).elf
	$(AVRSIZE) -C --mcu=$(MCU) $(PROJECT_NAME).elf



#To compile Before flash on target mcu
flash: compile
	@avrdude -c $(PROGRAMMER_TYPE) -p m32 -B 0.5 -U flash:w:"${PROJECT_NAME}.hex":a



