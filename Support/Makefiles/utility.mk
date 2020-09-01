####################################################################################################
# Filename        : utility.mk
# Author          : Sean Alling
# Version         : 1.0
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
# This file contains functions to aid in the building, or debugging of makefiles.
#
####################################################################################################

###################################       Revision History       ###################################
# 
#          DATE              BY                     DESCRIPTION
#   ----------------  ----------------  -----------------------------------------------------
#       11/10/2018     Sean Alling        Creation
#       01/07/2017     Sean Alling        Multiple changes
#                                           1) Added help rule & made it the default target
#                                           2) Moved clean rule to this file. 
#                                           3) Clean now deletes the main build directory,
#                                              ROOT_BUILD_DIR
#                                           4) Moved print-% rule to this file. 
#  
#  
#  
#  
#  
#  
####################################################################################################
.PHONY: help
.DEFAULT_GOAL: help
#> Display this help text
help: 
	$(info Available targets)
	@awk '/^[a-zA-Z\-\_0-9]+:/ {                    \
	  nb = sub( /^#> /, "", helpMsg );              \
	  if(nb == 0) {                                 \
	    helpMsg = $$0;                              \
	    nb = sub( /^[^:]*:.* ## /, "", helpMsg );   \
	  }                                             \
	  if (nb)                                       \
	    print  $$1 helpMsg;                         \
	}                                               \
	{ helpMsg = $$0 }'                              \
	$(MAKEFILE_LIST) | column -ts:

.PHONY: print-%
# Should put this rule in a different make file. One with all extra utility functions
print-%  : ; @echo $* = $($*)

.PHONY: clean
# Clean up the projects. Since all of the build files and the output files are stored under either 
# $(OBJ_DIR) or $(BIN_DIR), deleting these directories cleans up the entire project.
#> Delete all build files
clean:
	-@$(ECHO) "Deleting build files"
	@$(RM) $(ROOT_BUILD_DIR)