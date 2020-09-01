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
# This file is part of the non-recursive make build framework. This file contains the rules needed
# to create an executable/binary output file. For normal use this file should never have to be 
# modified. 
#
####################################################################################################

####################################################################################################
#                                     START PROJECT SETTINGS
####################################################################################################

include ./project_config.mk

####################################################################################################
#                                      END PROJECT SETTINGS
####################################################################################################


####################################################################################################
#                                      START MAKE FILE LOGIC
#                                           DO NOT MODIFY
####################################################################################################

# DO NOT MODIFY RULE. This is placed here so that it becomes the default rule
include $(MAKEFILEHOME)/header_exeTarget.mk

# Include utility functions in make file, like print-% or help. 
# utility.mk defines the default make target help
include $(MAKEFILEHOME)/utility.mk

#> Build all targets (*.axf & *.srec)
build:  $(ROOT_BUILD_DIR)/$(BIN_DIR)/$(TARGET).srec

#> Build all targets (*.axf & *.srec) with DEBUG defined
debug: EN_DEBUG := -DDEBUG2
debug: $(ROOT_BUILD_DIR)/$(BIN_DIR)/$(TARGET).srec

#> Build all targets (*.axf & *.srec)
all:  $(ROOT_BUILD_DIR)/$(BIN_DIR)/$(TARGET).srec


# Include each of the sub directory makefiles here
dir := Firmware
-include $(dir)/subdir.mk


.PHONY: flash
# SEGGER recommends that the device flag be passed at the command line and 
# not in the script. JLink Manual, section 3.2.3: Using command files, page 57
#> Flash the program onto the target
flash: $(ROOT_BUILD_DIR)/$(BIN_DIR)/$(TARGET).srec
	jlink -device MSP432P401R -CommanderScript .\Support\Flashscript\FlashScript.jlink

print-%  : ; @echo $* = $($*)

include $(MAKEFILEHOME)/footer_exeTarget.mk

# Include this here for now. This makes it so that every single header directory 
# will be stored in the variable. Since make assigned variables as it goes with this 
# as the last one it will be set at the very end after all of the headers have been found. 
# TODO: Change this so that each "Layer" does not include header files that are 2 or more away. 
INC_DIR := $(patsubst %,-I"%",$(INC))
####################################################################################################
#                                           END MAKEFILE
####################################################################################################
