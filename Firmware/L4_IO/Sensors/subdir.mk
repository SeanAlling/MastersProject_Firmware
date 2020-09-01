# Adds the generic rules file.
include $(MAKEFILEHOME)/subdir_header.mk

################################################################################
#                      START USER DEFINE OPTIONS                               #
################################################################################

# Include each of the sub directories here. These can be in any order

dir := $(d)/HDC1080
include $(dir)/subdir.mk

dir := $(d)/OPT3001
include $(dir)/subdir.mk
################################################################################
#                      END USER DEFINE OPTIONS                                 #
################################################################################

# Adds the generic rules file.
include $(MAKEFILEHOME)/subdir_footer.mk