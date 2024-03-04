# Makefile to build Goldeneye 007

# defines parameters like VERSION and paths to build tools.
include include/Makefile.options

# Any preprocessing steps. This will ensure required directories exist.
include include/Makefile.prep

# Group/collect files into variables to be referenced in the build.
include include/Makefile.files

# Makefile targets, how to build steps, etc.
ifeq ($(COLOR), 1)
	include include/Makefile.color
else
	include include/Makefile.targets
endif
