###################################          Description         ###################################
#                               _____  ____   ___          ______ ______
#                              / ___/ / __ \ /   |   _    / ____// ____/
#                              \__ \ / / / // /| |  (_)  / __/  / __/   
#                             ___/ // /_/ // ___ | _    / /___ / /___   
#                            /____//_____//_/  |_|(_)  /_____//_____/   
#                                       ___     _   __ ____             
#                                      /   |   / | / // __ \            
#                                     / /| |  /  |/ // / / /            
#                                    / ___ | / /|  // /_/ /             
#                                   /_/  |_|/_/ |_//_____/              
#                               __  __ ______ ____     ______ ______    
#                              / / / // ____// __ \   / ____// ____/    
#                             / / / // /    / / / /  / __/  / __/       
#                            / /_/ // /___ / /_/ /  / /___ / /___       
#                            \____/ \____//_____/  /_____//_____/ 
#
#
# This file declares all of the make variables that that a user can specify. Each variable controls
# an aspect of the build system.
####################################################################################################

####################################################################################################
#                                    Project Build Configurations
####################################################################################################


# Define the output binary file name
TARGET  := MastersProject

# Define the directory name used for storing all build generated files
# Default is Build
ROOT_BUILD_DIR := Build

# Define the directory name used for storing build files
# Default is Objects
OBJ_DIR := Objects


# Define the directory name where to store the output files
# Default is Debug
BIN_DIR := Debug


# Path to where the *.mk files are stored. 
# Default is ./Makefiles
MAKEFILEHOME := ./Support/Makefiles

# Full path to the target linker script file. 
# MUST be provided or the linker will fail
LINK_SCRIPT := ./Support/Linkscript/msp432p401r.lds

# Full path to the target flash script
# MUST be provided or flashing will fail
FLASH_SCRIPT := ./Support/Flashscript/FlashScript.jlink


# Define the compiler flags for the target. 
# Simple way is to take these from an eclipse build. 
# Note: Must be specified
MCU_FLAGS := -D__MSP432P401R__ -DDeviceFamily_MSP432P401x 
MCU_FLAGS += -march=armv7e-m -mthumb  -mfloat-abi=hard  -mfpu=fpv4-sp-d16
MCU_FLAGS += -D$(CMD_LINE_DEFINED_FREQUENCY) -D$(CMD_LINE_DEFINED_EXPERIMENT)

# Define linker flags
# Simple way is to take these from an eclipse build. 
# NOTE: This could be left empty
LD_FLAGS := -static --specs=nosys.specs -Wl,--gc-sections 
LD_FLAGS += -Wl,--print-memory-usage
LD_FLAGS += -Wl,--check-sections
LD_FLAGS += -ffunction-sections
LD_FLAGS += -fdata-sections


# Define c compiler flags
# Simple way is to take these from an eclipse build. 
# NOTE: This could be left empty
CC_FLAGS := -ffunction-sections -fdata-sections -g -gdwarf-3  -gstrict-dwarf  -Wall -std=c11 
CC_FLAGS += -DDEBUG2 -funsigned-char

# Define c++ compiler flags
# Simple way is to take these from an eclipse build. 
# NOTE: This could be left empty
CXX_FLAGS := -ffunction-sections -fdata-sections -g -gdwarf-3  -gstrict-dwarf  -Wall 
CXX_FLAGS += -std=c++17 -fno-exceptions -fno-rtti


# Define these commands with respect to your system
RM      := rm -rf
ECHO    := echo
MKDIR   := mkdir
MAKE    := make


# Define the compiler, linker, archiver, ... that the build will use
# NOTE: Current build requires all of these to be defined. 
AR      := arm-none-eabi-ar
CC      := arm-none-eabi-gcc
CXX     := arm-none-eabi-g++
LD      := arm-none-eabi-ld
SIZE    := arm-none-eabi-size
OBJCOPY := arm-none-eabi-objcopy


####################################################################################################
#                                            End OF File
####################################################################################################