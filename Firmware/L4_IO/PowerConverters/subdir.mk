# Adds the generic rules file.
include $(MAKEFILEHOME)/subdir_header.mk

################################################################################
#                      START USER DEFINE OPTIONS                               #
################################################################################

# Include each of the sub directories here. These can be in any order

dir := $(d)/STLQ015MXXX
include $(dir)/subdir.mk

################################################################################
#                      END USER DEFINE OPTIONS                                 #
################################################################################

# Adds the generic rules file.
include $(MAKEFILEHOME)/subdir_footer.mk