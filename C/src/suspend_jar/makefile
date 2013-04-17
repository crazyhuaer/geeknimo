include $(PRJ_ROOT)/ruler/Makefile.mk

##############################################################
# compile target control
##############################################################
SK_BUILD_BIN	= NO
SK_BUILD_LIB	= NO

##############################################################
# output include file and include dir
##############################################################
OUT_INC_FILE = 
OUT_INC_DIR =
# OUT_INC_DIR = $(PRJ_ROOT)/inclue

##############################################################
# target name
##############################################################
MODULE_BIN := $(notdir $(CURRENT_DIR))
MODULE_LIB_STATIC := $(addprefix lib, $(addsuffix .a, $(MODULE_BIN)))
MODULE_LIB_SHARED := $(addprefix lib, $(addsuffix .so, $(MODULE_BIN)))

ifeq ($(SK_BUILD_BIN), NO)
MODULE_BIN := jar
endif

ifeq ($(SK_BUILD_LIB), NO)
MODULE_LIB_STATIC :=
MODULE_LIB_SHARED :=
endif

##############################################################
# define subdirs that should be compiled in
##############################################################
SUB_DIRS :=

##############################################################
# other module dependent source files
##############################################################
# C_SRCS = 
# CPP_SRCS =

##############################################################
# module dependent header files and libs
##############################################################
#INCLUDE += -I$(PRJ_ROOT)/common/inc/os
INCLUDE += -I$(PRJ_ROOT)/common/inc/os

CFLAGS += 
LD_FLAGS += -L$(PRJ_ROOT)/common/lib -lpthread -lrt -los
#LD_FLAGS += -L$(PRJ_ROOT)/common/lib -lpthread -lrt -los 

include $(PRJ_ROOT)/ruler/Makesource.ruler

