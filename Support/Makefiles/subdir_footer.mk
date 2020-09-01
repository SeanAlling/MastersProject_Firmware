####################################################################################################
# Filename        : subdir_footer.mk
# Author          : Sean Alling
# Version         : 1.1
# Copyright       :  
# Creation Date   :
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
# This file is part of the non-recursive make build framework. This file generates the rules needed 
# for each the source files on a per directory basis. In order to have a build directory that the
# that matches the actual directory structure, a explicit stack is used within make. 
#
####################################################################################################

###################################       Revision History       ###################################
# 
#          DATE              BY                     DESCRIPTION
#   ----------------  ----------------  -----------------------------------------------------
#                      Sean Alling        Creation
#       01/07/2017     Sean Alling        Multiple changes
#                                           1) Added Header block
#                                           2) Added Description
#                                           3) Documented all rules
#       11/10/2018     Sean Alling        Multiple Changes
#                                           1) Added support for c++ source files
#                                           2) All generated build files now under one directory,
#                                              ROOT_BUILD_DIR.
#                                           
#      03/01/2020    Sean Alling          Added rule EN_DEBUG so so that target can be compiled 
#                                         with or without debug support.
#  
#  
#  
#  
#  
####################################################################################################

# $(d) is the current directory path. This forms part of the explicit stack that is used by make. 
# The explicit stack is needed in order to have multiple sub directories in this non recursive
# makefile. 

# The four rules are local to this directory. 
# Source files in the current directory
# object files that derived from the source files in this directory
# Dependency files derived from the source files in the current directory. 

SRCS_C_$(d)   := $(wildcard $(d)/*.c)
OBJS_C_$(d)   := $(SRCS_C_$(d):%.c=$(ROOT_BUILD_DIR)/$(OBJ_DIR)/%.c_o)
DEPS_C_$(d)   := $(OBJS_C_$(d):%.c_o=%.c_d)

SRCS_CPP_$(d) := $(wildcard $(d)/*.cpp)
OBJS_CPP_$(d) := $(SRCS_CPP_$(d):%.cpp=$(ROOT_BUILD_DIR)/$(OBJ_DIR)/%.cpp_o)
DEPS_CPP_$(d) := $(OBJS_CPP_$(d):%.cpp_o=%.cpp_d)

# Directory path for the build files will be placed. 
DIR_$(d) := ./$(ROOT_BUILD_DIR)/$(OBJ_DIR)/$(d)

# Each subdirectory must supply rules for building sources it contributes
# NOTE: This rule is using order only Prerequisites. See make manual section 4.3 
#       https://www.gnu.org/software/make/manual/html_node/Prerequisite-Types.html
./$(ROOT_BUILD_DIR)/$(OBJ_DIR)/$(d)%.c_o: $(d)%.c | ./$(ROOT_BUILD_DIR)/$(OBJ_DIR) ./$(ROOT_BUILD_DIR)/$(BIN_DIR) ./$(ROOT_BUILD_DIR)/$(OBJ_DIR)/$(d)
	@$(ECHO) "Building file: $<"
	@$(ECHO) "Invoking: MCU C Compiler"
	@$(CC) -c $(INC_DIR) $(CC_FLAGS) $(EN_DEBUG) $(MCU_FLAGS) -MMD -MP -MF"$(@:%.c_o=%.c_d)" -MT"$(@:%.c_o=%.c_o)" -MT"$(@:%.c_o=%.c_d)" -o "$@" "$<"
	@$(ECHO) "Finished building: $<"
	@$(ECHO) " "

# Each subdirectory must supply rules for building sources it contributes
# NOTE: This rule is using order only Prerequisites. See make manual section 4.3 
#       https://www.gnu.org/software/make/manual/html_node/Prerequisite-Types.html
./$(ROOT_BUILD_DIR)/$(OBJ_DIR)/$(d)%.cpp_o: $(d)%.cpp | ./$(ROOT_BUILD_DIR)/$(OBJ_DIR) ./$(ROOT_BUILD_DIR)/$(BIN_DIR) ./$(ROOT_BUILD_DIR)/$(OBJ_DIR)/$(d)
	@$(ECHO) "Building file: $<"
	@$(ECHO) "Invoking: MCU C++ Compiler"
	@$(CXX) -c $(INC_DIR) $(CXX_FLAGS) $(EN_DEBUG) $(MCU_FLAGS) -MMD -MP -MF"$(@:%.cpp_o=%.cpp_d)" -MT"$(@:%.cpp_o=%.cpp_o)" -MT"$(@:%.cpp_o=%.cpp_d)" -o "$@" "$<"
	@$(ECHO) "Finished building: $<"
	@$(ECHO) " "

# Generate the directory where the build files will be placed
./$(ROOT_BUILD_DIR)/$(OBJ_DIR)/$(d): 
	@$(MKDIR) -p $@

# The following rules add the local source, object, and dependency files to the global 
# project variables. 
SRCS += $(SRCS_C_$(d)) $(SRCS_CPP_$(d))
OBJS += $(OBJS_C_$(d)) $(OBJS_CPP_$(d))
DEPS += $(DEPS_C_$(d)) $(DEPS_CPP_$(d))

# Finished generating rules for the current directory. Pop from the explicit make stack.
d  := $(dirstack_$(sp))
sp := $(basename $(sp))