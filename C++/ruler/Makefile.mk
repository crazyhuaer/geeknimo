#############################################################
#
#
#	File name: Makefile.mk
#	Description: define makefile rulers for DM365
#	Version: 1.0
#
##############################################################




##############################################################
# define compile commands
##############################################################


CC			= $(CROSS_COMPILE)gcc
CXX			= $(CROSS_COMPILE)g++
LD			= $(CROSS_COMPILE)ld
AS			= $(CROSS_COMPILE)as
AR			= $(CROSS_COMPILE)ar
NM			= $(CROSS_COMPILE)nm
STRIP		= $(CROSS_COMPILE)strip
OBJCOPY		= $(CROSS_COMPILE)objcopy
OBJDUMP		= $(CROSS_COMPILE)objdump
RANLIB		= $(CROSS_COMPILE)ranlib

##############################################################
# define shell commands
##############################################################
MAKE		= make 
CP			= cp -f
RM			= rm -f
SORT		= sort
SED			= sed
TOUCH		= touch
MKDIR		= mkdir -p
LN		    = ln -s

##############################################################
# define output files path
##############################################################
OUT_BIN_FOLDER		= $(PRJ_ROOT)/bin
OUT_LIB_FOLDER		= $(PRJ_ROOT)/lib
OUT_PLATFORM_LIB_FOLDER = $(PRJ_ROOT)/lib/$(PLATFORM_NAME)
OUT_THIRD_LIBS_IDR	= $(PRJ_ROOT)/third_libs
OBJ_FOLDER          = $(PRJ_ROOT)/obj/
##############################################################
# define compile variables
##############################################################
INCLUDE_PATH = $(PRJ_ROOT)/inc $(PRJ_ROOT)/$(PLATFORM_NAME)/include $(PLATFORM_PATH)/include  
LIB_PATH = $(OUT_LIB_FOLDER) $(PLATFORM_PATH)/lib
DEBUG_FLAG = -g -Wall -I. -shared -fPIC -DDEBUG -c
RELEASE_FLAG = -O3 -Wall -I. -shared -fPIC -DNDEBUG -c

ifeq ($(COMPILE_FLAG), Debug)
CFLAGS := $(DEBUG_FLAG)
else
CFLAGS := $(RELEASE_FLAG)
endif

INCLUDE = $(addprefix -I$(ROOT), $(INCLUDE_PATH))
LD_FLAGS = $(addprefix -L, $(LIB_PATH))
#LD_OPT = -nostdlib -Bdynamic -Wl,-T,$(ROOT)/build/core/armelf.x -Wl,-dynamic-linker,/system/bin/linker -Wl,--gc-sections -Wl,-z,nocopyreloc -Wl,-z,noexecstack -Wl,--fix-cortex-a8 -Wl,--no-undefined  -Wl,-rpath-link=$(LIBS_DIR)
#DYN_BEGIN_OBJ = $(LIBS_DIR)/crtbegin_dynamic.o 
#END_OBJ = $(PLATFORM_PATH)/lib/gcc/arm-eabi/4.4.3/libgcc.a $(LIBS_DIR)/crtend_android.o 

CURRENT_DIR			:=  $(shell cd ./; pwd)
#C_SRCS				=  $(wildcard $(CURRENT_DIR)/*.c)
#CPP_SRCS			=  $(wildcard $(CURRENT_DIR)/*.cpp)
C_SRCS				=  $(notdir $(wildcard $(CURRENT_DIR)/*.c))
CPP_SRCS			= $(notdir $(wildcard $(CURRENT_DIR)/*.cpp))
AS_SRCS       = $(notdir $(wildcard $(CURRENT_DIR)/*.S))
C_OBJS				=  $(C_SRCS:.c=.o) 
CPP_OBJS			=  $(CPP_SRCS:.cpp=.o)
AS_OBJS				=  $(AS_SRCS:.S=.o)

OBJS				=  $(C_OBJS) $(CPP_OBJS) $(AS_OBJS)
DEPS				=  $(OBJS:.o=.d)
#MISSING_DEPS		:= $(filter-out $(wildcard $(DEPS)),$(DEPS))
#MISSING_DEPS_SOURCES := $(wildcard $(patsubst %.d,%.c,$(MISSING_DEPS)) \
#					    $(patsubst %.d,%.cc,$(MISSING_DEPS)))
