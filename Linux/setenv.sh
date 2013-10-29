#############################################################
#
#	Copyright (c) 2009-2011, ShenzhenSkyworth Digital Technology Co., Ltd
#	All rights reserved.
#
#	File name: setenv.sh for android Project
#	Description: set environment variables for android4.0
#	Version: 1.0
#	Author: 
#	Date: 2012-4-10
#
##############################################################

export PRJ_ROOT=$(pwd)
#export ROOT=
export PLATFORM_PATH=/home/geeknimo/disk/study/openwrt_source/trunk/staging_dir/toolchain-mips_34kc_gcc-4.6-linaro_uClibc-0.9.33.2
export PATH=$PATH:$PLATFORM_PATH/bin
export LIBS_DIR=$PLATFORM_PATH/lib
export PKG_CONFIG_PATH=
export PLATFORM_NAME=mips-openwrt
export CROSS_COMPILE=mips-openwrt-linux-
export COMPILE_FLAG=Debug

export LD_LIBRARY_PATH=$(pwd)/common/lib

cd $PRJ_ROOT
