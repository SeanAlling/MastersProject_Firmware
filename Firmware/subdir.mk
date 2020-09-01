# Adds the generic rules file.
include $(MAKEFILEHOME)/subdir_header.mk

################################################################################
#                      START USER DEFINE OPTIONS                               #
################################################################################

# Include each of the sub directories here. These can be in any order
dir := $(d)/L0_Chip
include $(dir)/subdir.mk

dir := $(d)/L1_RTOS
include $(dir)/subdir.mk

dir := $(d)/L2_BSP
include $(dir)/subdir.mk

dir := $(d)/L3_Utils
include $(dir)/subdir.mk

dir := $(d)/L4_IO
include $(dir)/subdir.mk

dir := $(d)/L5_Application
include $(dir)/subdir.mk
################################################################################
#                      END USER DEFINE OPTIONS                                 #
################################################################################

# Adds the generic rules file.
include $(MAKEFILEHOME)/subdir_footer.mk