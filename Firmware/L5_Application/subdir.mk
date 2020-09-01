# Adds the generic rules file.
include $(MAKEFILEHOME)/subdir_header.mk

################################################################################
#                      START USER DEFINE OPTIONS                               #
################################################################################

# Include each of the sub directories here. These can be in any order
dir := $(d)/Experiments
include $(dir)/subdir.mk

INC += $(d)
################################################################################
#                      END USER DEFINE OPTIONS                                 #
################################################################################

# Adds the generic rules file.
include $(MAKEFILEHOME)/subdir_footer.mk