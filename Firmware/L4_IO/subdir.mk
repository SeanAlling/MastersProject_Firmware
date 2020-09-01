# Adds the generic rules file.
include $(MAKEFILEHOME)/subdir_header.mk

################################################################################
#                      START USER DEFINE OPTIONS                               #
################################################################################

# Include each of the sub directories here. These can be in any order
dir := $(d)/Memory
include $(dir)/subdir.mk

dir := $(d)/RTC
include $(dir)/subdir.mk

dir := $(d)/Sensors
include $(dir)/subdir.mk

dir := $(d)/Communication
include $(dir)/subdir.mk

dir := $(d)/PowerConverters
include $(dir)/subdir.mk

dir := $(d)/Display
include $(dir)/subdir.mk

################################################################################
#                      END USER DEFINE OPTIONS                                 #
################################################################################

# Adds the generic rules file.
include $(MAKEFILEHOME)/subdir_footer.mk