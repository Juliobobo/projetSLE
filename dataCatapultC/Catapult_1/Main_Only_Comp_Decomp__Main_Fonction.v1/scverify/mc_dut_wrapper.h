// ----------------------------------------------------------------------------
// SystemC Wrapper for Catapult Design HDL Netlist
//
//    HLS version: 2011a.200 Production Release
//       HLS date: Mon Jun  2 22:10:04 PDT 2014
//  Flow Packages: HDL_Tcl 2008a.1, SCVerify 2009a.1
//
//   Generated by: xph3sle512@cimeld21
// Generated date: Wed Feb 01 14:05:49 CET 2017
//
// ----------------------------------------------------------------------------
#ifndef INCLUDED_CCS_DUT_WRAPPER_H
#define INCLUDED_CCS_DUT_WRAPPER_H

#ifndef SC_USE_STD_STRING
#define SC_USE_STD_STRING
#endif

#include <systemc.h>
#include <mc_simulator_extensions.h>

#if defined(CCS_DUT_SYSC)

// alias ccs_DUT_wrapper to namespace enclosure of either cycle or RTL SystemC netlist
namespace ccs_design {
#if defined(CCS_DUT_CYCLE)
//#include "cycle.cxx"
#include "cycle.cxx"
#else
#if defined(CCS_DUT_RTL)
//#include "rtl.cxx"
#include "rtl.cxx"
#endif
#endif
}
typedef ccs_design::HDL::Main_Only_Comp_Decomp_Main_Fonction ccs_DUT_wrapper;

#else

// Create a foreign module wrapper around the HDL
class ccs_DUT_wrapper : public mc_foreign_module
{
public:
   #ifndef VCS_SYSTEMC
   // Interface Ports
   sc_in< sc_logic > start;
   sc_out< sc_logic > done;
   sc_in<bool> clk;
   sc_in< sc_logic > rst;
   sc_out< sc_lv<8> > Src_rsc_singleport_data_in;
   sc_out< sc_lv<17> > Src_rsc_singleport_addr;
   sc_out< sc_lv<1> > Src_rsc_singleport_re;
   sc_out< sc_lv<1> > Src_rsc_singleport_we;
   sc_in< sc_lv<8> > Src_rsc_singleport_data_out;
   sc_out< sc_lv<8> > Comp_rsc_singleport_data_in;
   sc_out< sc_lv<17> > Comp_rsc_singleport_addr;
   sc_out< sc_lv<1> > Comp_rsc_singleport_re;
   sc_out< sc_lv<1> > Comp_rsc_singleport_we;
   sc_in< sc_lv<8> > Comp_rsc_singleport_data_out;
   sc_out< sc_lv<8> > Vga_rsc_singleport_data_in;
   sc_out< sc_lv<17> > Vga_rsc_singleport_addr;
   sc_out< sc_lv<1> > Vga_rsc_singleport_re;
   sc_out< sc_lv<1> > Vga_rsc_singleport_we;
   sc_in< sc_lv<8> > Vga_rsc_singleport_data_out;
   sc_out< sc_lv<32> > Main_Only_Comp_Decomp_Main_Fonction_return_rsc_z;
   sc_out< sc_logic > Src_triosy_lz;
   sc_out< sc_logic > Comp_triosy_lz;
   sc_out< sc_logic > Vga_triosy_lz;
   sc_out< sc_logic > nblevels_triosy_lz;
   sc_out< sc_logic > Main_Only_Comp_Decomp_Main_Fonction_return_triosy_lz;
   #endif
   
public:
   ccs_DUT_wrapper(const sc_module_name& nm, const char *hdl_name)
      : mc_foreign_module(nm,hdl_name)
      #ifndef VCS_SYSTEMC
      ,start("start")
      ,done("done")
      ,clk("clk")
      ,rst("rst")
      ,Src_rsc_singleport_data_in("Src_rsc_singleport_data_in")
      ,Src_rsc_singleport_addr("Src_rsc_singleport_addr")
      ,Src_rsc_singleport_re("Src_rsc_singleport_re")
      ,Src_rsc_singleport_we("Src_rsc_singleport_we")
      ,Src_rsc_singleport_data_out("Src_rsc_singleport_data_out")
      ,Comp_rsc_singleport_data_in("Comp_rsc_singleport_data_in")
      ,Comp_rsc_singleport_addr("Comp_rsc_singleport_addr")
      ,Comp_rsc_singleport_re("Comp_rsc_singleport_re")
      ,Comp_rsc_singleport_we("Comp_rsc_singleport_we")
      ,Comp_rsc_singleport_data_out("Comp_rsc_singleport_data_out")
      ,Vga_rsc_singleport_data_in("Vga_rsc_singleport_data_in")
      ,Vga_rsc_singleport_addr("Vga_rsc_singleport_addr")
      ,Vga_rsc_singleport_re("Vga_rsc_singleport_re")
      ,Vga_rsc_singleport_we("Vga_rsc_singleport_we")
      ,Vga_rsc_singleport_data_out("Vga_rsc_singleport_data_out")
      ,Main_Only_Comp_Decomp_Main_Fonction_return_rsc_z("Main_Only_Comp_Decomp_Main_Fonction_return_rsc_z")
      ,Src_triosy_lz("Src_triosy_lz")
      ,Comp_triosy_lz("Comp_triosy_lz")
      ,Vga_triosy_lz("Vga_triosy_lz")
      ,nblevels_triosy_lz("nblevels_triosy_lz")
      ,Main_Only_Comp_Decomp_Main_Fonction_return_triosy_lz("Main_Only_Comp_Decomp_Main_Fonction_return_triosy_lz")
      #endif
      {
          // elaborate_foreign_module(hdl_name);
      }
      
      ~ccs_DUT_wrapper() {}
   };
   
   #endif

#endif

