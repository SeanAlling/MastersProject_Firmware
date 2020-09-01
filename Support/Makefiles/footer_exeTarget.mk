####################################################################################################
# Filename        : footer_exeTarget.mk
# Author          : Sean Alling
# Version         : 1.1
# Copyright       : 
# Creation Date   : 01/07/2017
####################################################################################################

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

###################################       Revision History       ###################################
# 
#          DATE              BY                     DESCRIPTION
#   ----------------  ----------------  -----------------------------------------------------
#       01/07/2017     Sean Alling        Creation
#       01/07/2017     Sean Alling        Multiple changes
#                                           1) Added Header block
#                                           2) Added Description
#                                           3) Documented all rules
#       11/10/2018     Sean Alling        Multiple Changes
#                                           1) All generated build files now under one directory
#                                           2) SizeReport.txt now has its entries sorted.
#                                           3) Removed compile time flags from linker.
#       06//27/2019   Sean Alling         Removed - from linker and objcopy commands so that a 
#                                         Error causes the build to stop immediately. 
#       06//30/2019   Sean Alling         Added dependency to linker on linker script. Causes a 
#                                         relink when the linker script changes.
#  
#  
####################################################################################################

# Include all the generated dependency rules from GCC. With these rules the build system is able 
# to resolve what needs to be rebuild when any source file changes. 
-include $(DEPS)


# Rule creating the directory where the generated objects will be located
# $@ evaluates to the name of the target
./$(ROOT_BUILD_DIR)/$(OBJ_DIR):
	@$(MKDIR) -p $@


# Rule creating the directory where the output files will be located
# $@ evaluates to the name of the target
./$(ROOT_BUILD_DIR)/$(BIN_DIR):
	@$(MKDIR) -p $@


# Generates the main binary output. A perquisite rule is used to make sure that the build and 
# output directories are created. Each command in the rule is not echoed back to the shell. 
# This is accomplished by using @. All commands except for $(CC) use -@ lets make know to ignore 
# the errors that these commands could issue.
# NOTE: This rule is using order only Prerequisites. See make manual section 4.3 
#       https://www.gnu.org/software/make/manual/html_node/Prerequisite-Types.html
./$(ROOT_BUILD_DIR)/$(BIN_DIR)/$(TARGET).axf: $(OBJS) $(LINK_SCRIPT) | ./$(ROOT_BUILD_DIR)/$(OBJ_DIR) ./$(ROOT_BUILD_DIR)/$(BIN_DIR)
	-@$(ECHO) "Invoking: MCU Linker"
	@$(CC) $(MCU_FLAGS) $(LD_FLAGS) -Wl,-T$(patsubst %,"%",$(LINK_SCRIPT))  -Wl,-Map=$(@:%.axf=%.map) -o $@ $(OBJS) $(LIBS) -Wl,--start-group  -lnosys -lc -Wl,--end-group 
	-@$(ECHO) "Finished building target: $@"
	-@$(ECHO) " "


# Convert the main binary to an srecord file. The srecord file is used for flashing the target with 
# Segger JLink.A perquisite rule is used to make sure that the build and output directories are 
# created. Each command in the rule is not echoed back to the shell. 
# This is accomplished by using @. All commands except for $(CC) use -@ lets make know to ignore 
# the errors that these commands could issue.
# NOTE: This rule is using order only Prerequisites. See make manual section 4.3 
#       https://www.gnu.org/software/make/manual/html_node/Prerequisite-Types.html
./$(ROOT_BUILD_DIR)/$(BIN_DIR)/$(TARGET).srec: ./$(ROOT_BUILD_DIR)/$(BIN_DIR)/$(TARGET).axf | ./$(ROOT_BUILD_DIR)/$(OBJ_DIR) ./$(ROOT_BUILD_DIR)/$(BIN_DIR)
	-@$(ECHO) "Generating SRecord"
	@$(OBJCOPY) -v --srec-len=16 -O srec $< $@
	-@$(ECHO) " "


# Generate a report listing the size of each object file used in the output binary and the 
# size information for the final output binary. 
./$(ROOT_BUILD_DIR)/$(BIN_DIR)/SizeReport.txt: ./$(ROOT_BUILD_DIR)/$(BIN_DIR)/$(TARGET).axf
	-@$(ECHO) "Generatng size report for: $<"
	-@$(ECHO) "Object File Size Information" > $@
	-@$(SIZE) $(sort $(OBJS)) >> $@
	-@$(ECHO) " " >> $@
	-@$(ECHO) "Output Binary Size Information" >> $@
	-@$(SIZE) --format=berkeley $< >> $@
	-@$(ECHO) "Report file generated"
	-@$(ECHO) " "

# Gets rid of implicit rules and force them to be explicit. 
.SUFFIXES: