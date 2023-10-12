######################################################################################
#									Definitions		 								 #
#			 Please Check these every time you start a new project					 #
######################################################################################
# selection Source Code"*.c" & project Name & Target"*.c-->*.o"
PROJECT_NAME=AutonomousVehicle 

# Target AVR settings
   ##https://gcc.gnu.org/onlinedocs/gcc/AVR-Options.html
MCU   = atmega32a
F_CPU = 8000000
BAUD = 9600

# The code file containing the main() function.
MAIN = APP.c

# If you've split your program into multiple .c / .h files, 
# include the additional source (in same directory) here 
LOCAL_SOURCE = $(wildcard *.c)

# Here you can link to one more directory (and multiple .c files)
# EXTRA_SOURCE_DIR = ../../lib/
EXTRA_SOURCE_DIR =
EXTRA_SOURCE_FILES = 

##########------------------------------------------------------##########
##########                 Programmer Defaults                  ##########
##########          Set up once, then forget about it           ##########
##########        (Can override.  See bottom of file.)          ##########
##########------------------------------------------------------##########
PROGRAMMER_TYPE =usbasp


##########------------------------------------------------------##########
##########                   Makefile Magic!                    ##########
##########         Summary:                                     ##########
##########             We want a .hex file                      ##########
##########        Compile source files into .elf                ##########
##########        Convert .elf file into .hex                   ##########
##########        You shouldn't need to edit below.             ##########
##########------------------------------------------------------##########
TOOLCHAIN=avr-objcopy
optimizationlevel = -O0 
#OPTIONS=-mmcu=$(MCU) $(optimizationlevel) -DF_CPU=$(F_CPU)UL
CC =avr-gcc
++ =avr-g++
OBJCOPY =avr-objcopy
OBJDUMP =avr-objdump
AVRSIZE =avr-size
AVRDUDE =avrdude

# Compilation options, type man avr-gcc if you're curious.
CFLAGS = -mmcu=$(MCU) -DF_CPU=$(F_CPU)UL -DBAUD=$(BAUD) -Os -I. -I$(EXTRA_SOURCE_DIR)
CFLAGS += -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums 
CFLAGS += -Wall -Wstrict-prototypes
CFLAGS += -g -ggdb
CFLAGS += -ffunction-sections -fdata-sections -Wl,--gc-sections -Wl,--relax
CFLAGS += -std=gnu99
   ## CFLAGS += -Wl,-u,vfprintf -lprintf_flt -lm  ## for floating-point printf
   ## CFLAGS += -Wl,-u,vfprintf -lprintf_min      ## for smaller printf

# selection Toolchain & Options & Defined programs / locations
TARGET = $(strip $(basename $(MAIN)))
EXTRA_SOURCE = $(addprefix $(EXTRA_SOURCE_DIR), $(EXTRA_SOURCE_FILES))
SRC += $(LOCAL_SOURCE) 
SRC += $(EXTRA_SOURCE) 

# List of all header files
HEADERS = $(wildcard *.h) 

# For every .c file, compile an .o object file
OBJ = $(SRC:.c=.o)

######################################################################################
#						our Rules for building process 								 #
######################################################################################
#Generic Makefile targets.  (Only .hex file is necessary)
all: $(TARGET).hex
%.hex: %.elf
	@$(OBJCOPY) -R .eeprom -O ihex $< $@
	@echo "Succes Compiled"
    #$@ is the name of the target being generated, and $< the first prerequisite (usually a source file).
    #avr-obcopy -O output-format [-j section-to include]... [-R section-to-remove]... input-file output-file
    #avr-objcopy -O ihex -R .eeprom filename.elf filename.hex
%.elf: $(SRC)
	@$(CC) $(CFLAGS) $(SRC) --output $@ 
    #    -E                       Preprocess only; do not compile, assemble or link.
    #    -S                       Compile only; do not assemble or link.
    #    -c                       Compile and assemble, but do not link.
    #    -o <file>                Place the output into <file>.
%.eeprom: %.elf
	@$(OBJCOPY) -j .eeprom --change-section-lma .eeprom=0 -O ihex $< $@ 



debug:
	@echo
	@echo "Source files:"   $(SRC)
	@echo "MCU, F_CPU, BAUD:"  $(MCU), $(F_CPU), $(BAUD)
	@echo



# Optionally create listing file from .elf
# This creates approximate assembly-language equivalent of your code.
# Useful for debugging time-sensitive bits, 
# or making sure the compiler does what you want.
disassemble: $(TARGET).lst
disasm: disassemble
eeprom: $(TARGET).eeprom
%.lst: %.elf
	$(OBJDUMP) -S $< > $@
    ##    i need to take ".elf" ~= "$<" and process it by objdump and output transfer it to $@
    ##    The -S option will generate a ".s " GNU-assembly source file. ( ",asm " conventionally implies an
    ##    Atmel-assembly source file, which is different.) If you generated your Makefile with Mfile,
    ##    you should be able to just "make <whatever>.s ".



# Optionally show how big the resulting program is 
size:  $(TARGET).elf
	$(AVRSIZE) -C --mcu=$(MCU) $(TARGET).elf

# to clean *.elf *.hex *.obj *.o *.d *.eep *.lst *.lss *.sym *.map *~
clean:
	@rm -f $(TARGET).elf $(TARGET).hex $(TARGET).obj \
	$(TARGET).o $(TARGET).d $(TARGET).eep $(TARGET).lst \
	$(TARGET).lss $(TARGET).sym $(TARGET).map $(TARGET)~ \
	$(TARGET).eeprom
	@echo "`date` done" >> log.txt

squeaky_clean:
	@rm -f *.elf *.hex *.obj *.o *.d *.eep *.lst *.lss *.sym *.map *~ *.eeprom
	@echo "`date` done" >> log.txt

    ##*~ means all files ending in ~ . Many Unix/Linux systems programs create 
    ##backup files that end in ~ . For example, the emacs and nano editors automatically 
    ##save a backup copy of each file you edit. When it saves a file, the old version gets 
    ##saved using the file name with a tilde ( ~ ) added to the end.



##########------------------------------------------------------##########
##########              Programmer-specific details             ##########
##########           Flashing code to AVR using avrdude         ##########
##########------------------------------------------------------##########
#To compile Before flash on target mcu
flash: $(TARGET).hex
	@$(AVRDUDE) -c $(PROGRAMMER_TYPE) -p m32 -B 0.5 -U flash:w:"${TARGET}.hex":a



