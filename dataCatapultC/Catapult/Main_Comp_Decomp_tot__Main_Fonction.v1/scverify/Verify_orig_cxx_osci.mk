# ----------------------------------------------------------------------------
# Original Design + Testbench
#
#    HLS version: 2011a.200 Production Release
#       HLS date: Mon Jun  2 22:10:04 PDT 2014
#  Flow Packages: HDL_Tcl 2008a.1, SCVerify 2009a.1
#
#   Generated by: xph3sle512@cimeld21
# Generated date: Wed Feb 01 12:29:53 CET 2017
#
# ----------------------------------------------------------------------------
# ===================================================
# DEFAULT GOAL is the help target
.PHONY: all
all: help

# ===================================================
# VARIABLES
# 
MGC_HOME          = /softslin/catapult2011a_200_12/Mgc_home/
PROJDIR           = $(subst /,$(PATHSEP),../..)
SOLNDIR           = $(subst /,$(PATHSEP),Catapult/Main_Comp_Decomp_tot__Main_Fonction.v1)
export MGC_HOME

# Variables that can be overridden from the make command line
ifeq "$(INCL_DIRS)" ""
INCL_DIRS                   =  . /usr/x86_64-linux-gnu
endif
export INCL_DIRS
ifeq "$(STAGE)" ""
STAGE                       = orig
endif
export STAGE
ifeq "$(SIMTOOL)" ""
SIMTOOL                     = osci
endif
export SIMTOOL
ifeq "$(NETLIST)" ""
NETLIST                     = cxx
endif
export NETLIST
ifeq "$(RTL_NETLIST_FNAME)" ""
RTL_NETLIST_FNAME           = /tp/xph3sle/xph3sle512/ProjetSLE_bis/dataCatapultC/Catapult/Main_Comp_Decomp_tot__Main_Fonction.v1/dummy_netlist_file
endif
export RTL_NETLIST_FNAME
ifeq "$(TARGET)" ""
TARGET                      = scverify/$(STAGE)_$(NETLIST)_$(SIMTOOL)
endif
export TARGET
ifeq "$(INVOKE_ARGS)" ""
INVOKE_ARGS                 = 
endif
export INVOKE_ARGS
export SCVLIBS
LINK_SYSTEMC             += true
TOP_HDL_ENTITY           += Main_Comp_Decomp_tot::Main_Fonction
TOP_DU                   += scverify_top
LINK_SYSTEMC             += true

ifeq ($(RECUR),)
ifeq ($(STAGE),mapped)
ifeq ($(RTLTOOL),)
   $(error This makefile requires specifying the RTLTOOL variable on the make command line)
endif
endif
endif
# ===================================================
# Include makefile for default commands and variables
include $(MGC_HOME)/shared/include/mkfiles/ccs_default_cmds.mk

# ===================================================
# Include environment variables set by flow options
include ./ccs_env.mk

# ===================================================
# SOURCES
# 
# Specify list of Modelsim libraries to create
HDL_LIB_NAMES = work
# Specify list of source files - MUST be ordered properly
ifeq ($(STAGE),gate)
ifeq ($(RTLTOOL),)
ifeq ($(GATE_VHDL_DEP),)
GATE_VHDL_DEP = 
endif
ifeq ($(GATE_VLOG_DEP),)
GATE_VLOG_DEP = 
endif
endif
VHDL_SRC =  $(GATE_VHDL_DEP)
VLOG_SRC =  $(GATE_VLOG_DEP)
else
VHDL_SRC = 
VLOG_SRC = 
endif
CXX_SRC  = ../../../Rendu/src/CPP_for_Catapult/comp_decomp_tot/Main_Trans_Ond.cpp/Main_Trans_Ond.cpp.cxxts ../../../Rendu/src/CPP_for_Catapult/comp_decomp_tot/Decompressor.cpp/Decompressor.cpp.cxxts ../../../Rendu/src/CPP_for_Catapult/comp_decomp_tot/Main_Comp_Decomp_tot.cpp/Main_Comp_Decomp_tot.cpp.cxxts ../../../Rendu/src/CPP_for_Catapult/comp_decomp_tot/Main_Inv_Wave.cpp/Main_Inv_Wave.cpp.cxxts ../../../Rendu/src/CPP_for_Catapult/comp_decomp_tot/Exchange.cpp/Exchange.cpp.cxxts ../../../Rendu/src/CPP_for_Catapult/comp_decomp_tot/model.cpp/model.cpp.cxxts ../../../Rendu/src/CPP_for_Catapult/comp_decomp_tot/Main_Cod_Entropique.cpp/Main_Cod_Entropique.cpp.cxxts ../../../Rendu/src/CPP_for_Catapult/comp_decomp_tot/Main_Decomp.cpp/Main_Decomp.cpp.cxxts ../../../Rendu/src/CPP_for_Catapult/comp_decomp_tot/Compressor.cpp/Compressor.cpp.cxxts
# Specify RTL synthesis scripts (if any)
RTL_SCRIPT = 

# Specify hold time file name (for verifying synthesized netlists)
HLD_CONSTRAINT_FNAME = top_gate_constraints.cpp

# ===================================================
# GLOBAL OPTIONS
# 
# CXXFLAGS - global C++ options (apply to all C++ compilations) except for include file search paths
CXXFLAGS += -DSC_INCLUDE_DYNAMIC_PROCESSES -DSC_USE_STD_STRING -DTOP_HDL_ENTITY=$(TOP_HDL_ENTITY) -DCCS_MISMATCHED_OUTPUTS_ONLY -Wall -m32
# 
# LDFLAGS - global linker options
LDFLAGS += -m32
# 
# If the make command line includes a definition of the special variable MC_DEFAULT_TRANSACTOR_LOG
# then define that value for all compilations as well
ifneq "$(MC_DEFAULT_TRANSACTOR_LOG)" ""
CXXFLAGS += -DMC_DEFAULT_TRANSACTOR_LOG=$(MC_DEFAULT_TRANSACTOR_LOG)
endif
# 
# CXX_INCLUDES - include file search paths
CXX_INCLUDES = . /usr/x86_64-linux-gnu ../..
# 
# TCL shell
TCLSH_CMD = $(MGC_HOME)/bin/tclsh8.5

# Pass along SCVerify_DEADLOCK_DETECTION option
ifneq "$(SCVerify_DEADLOCK_DETECTION)" ""
CXXFLAGS += -DDEADLOCK_DETECTION
endif
# ===================================================
# PER SOURCE FILE SPECIALIZATIONS
# 
# Specify source file paths
ifeq ($(STAGE),gate)
ifneq ($(GATE_VHDL_DEP),)
$(TARGET)/$(notdir $(GATE_VHDL_DEP)): $(dir $(GATE_VHDL_DEP))
endif
ifneq ($(GATE_VLOG_DEP),)
$(TARGET)/$(notdir $(GATE_VLOG_DEP)): $(dir $(GATE_VLOG_DEP))
endif
endif
$(TARGET)/Main_Trans_Ond.cpp.cxxts: ../../../Rendu/src/CPP_for_Catapult/comp_decomp_tot/Main_Trans_Ond.cpp
$(TARGET)/Decompressor.cpp.cxxts: ../../../Rendu/src/CPP_for_Catapult/comp_decomp_tot/Decompressor.cpp
$(TARGET)/Main_Comp_Decomp_tot.cpp.cxxts: ../../../Rendu/src/CPP_for_Catapult/comp_decomp_tot/Main_Comp_Decomp_tot.cpp
$(TARGET)/Main_Inv_Wave.cpp.cxxts: ../../../Rendu/src/CPP_for_Catapult/comp_decomp_tot/Main_Inv_Wave.cpp
$(TARGET)/Exchange.cpp.cxxts: ../../../Rendu/src/CPP_for_Catapult/comp_decomp_tot/Exchange.cpp
$(TARGET)/model.cpp.cxxts: ../../../Rendu/src/CPP_for_Catapult/comp_decomp_tot/model.cpp
$(TARGET)/Main_Cod_Entropique.cpp.cxxts: ../../../Rendu/src/CPP_for_Catapult/comp_decomp_tot/Main_Cod_Entropique.cpp
$(TARGET)/Main_Decomp.cpp.cxxts: ../../../Rendu/src/CPP_for_Catapult/comp_decomp_tot/Main_Decomp.cpp
$(TARGET)/Compressor.cpp.cxxts: ../../../Rendu/src/CPP_for_Catapult/comp_decomp_tot/Compressor.cpp
# 
# Specify additional C++ options per C++ source by setting CXX_OPTS
$(TARGET)/Compressor.cpp.cxxts: CXX_OPTS=
$(TARGET)/Main_Cod_Entropique.cpp.cxxts: CXX_OPTS=
$(TARGET)/model.cpp.cxxts: CXX_OPTS=
$(TARGET)/Exchange.cpp.cxxts: CXX_OPTS=
$(TARGET)/Main_Inv_Wave.cpp.cxxts: CXX_OPTS=
$(TARGET)/Main_Decomp.cpp.cxxts: CXX_OPTS=
$(TARGET)/Main_Comp_Decomp_tot.cpp.cxxts: CXX_OPTS=
$(TARGET)/Decompressor.cpp.cxxts: CXX_OPTS=
$(TARGET)/Main_Trans_Ond.cpp.cxxts: CXX_OPTS=
# 
# Specify dependencies
$(TARGET)/Main_Trans_Ond.cpp.cxxts: 
$(TARGET)/Decompressor.cpp.cxxts: 
$(TARGET)/Main_Comp_Decomp_tot.cpp.cxxts: 
$(TARGET)/Main_Inv_Wave.cpp.cxxts: 
$(TARGET)/Exchange.cpp.cxxts: 
$(TARGET)/model.cpp.cxxts: 
$(TARGET)/Main_Cod_Entropique.cpp.cxxts: 
$(TARGET)/Main_Decomp.cpp.cxxts: 
$(TARGET)/Compressor.cpp.cxxts: 
# 
# Specify compilation library for HDL source
ifeq ($(STAGE),gate)
ifneq ($(GATE_VHDL_DEP),)
$(TARGET)/$(notdir $(GATE_VHDL_DEP)): HDL_LIB=work
endif
ifneq ($(GATE_VLOG_DEP),)
$(TARGET)/$(notdir $(GATE_VLOG_DEP)): HDL_LIB=work
endif
endif
# 
# Specify top design unit for HDL source

# Specify top design unit

ifneq "$(RTLTOOL)" ""
# ===================================================
# Include makefile for RTL synthesis
include $(MGC_HOME)/shared/include/mkfiles/ccs_$(RTLTOOL).mk
else
# ===================================================
# Include makefile for simulator
include $(MGC_HOME)/shared/include/mkfiles/ccs_$(SIMTOOL).mk
endif

