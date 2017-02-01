// ----------------------------------------------------------------------------
// SystemC Testbench Header
//
//    HLS version: 2011a.200 Production Release
//       HLS date: Mon Jun  2 22:10:04 PDT 2014
//  Flow Packages: HDL_Tcl 2008a.1, SCVerify 2009a.1
//
//   Generated by: xph3sle512@cimeld21
// Generated date: Wed Feb 01 14:05:43 CET 2017
//
// ----------------------------------------------------------------------------
#ifdef CCS_SCVERIFY

// 
// -------------------------------------
// testbench
// User supplied testbench
// -------------------------------------
// 
#ifndef INCLUDED_TESTBENCH_H
#define INCLUDED_TESTBENCH_H

extern void mc_testbench_Src_skip(bool v);
extern void mc_testbench_Comp_skip(bool v);
extern void mc_testbench_Vga_skip(bool v);
extern void mc_testbench_nblevels_skip(bool v);
extern void mc_testbench_Main_Only_Comp_Decomp__Main_Fonction_return_skip(bool v);

#ifndef SC_USE_STD_STRING
#define SC_USE_STD_STRING
#endif

#include "../../../Rendu/src/CPP_for_Catapult/comp_decomp_noW/Main_Only_Comp_Decomp.h"
#include <systemc.h>
#include <tlm.h>
#include <ac_int.h>
#include <mc_container_types.h>
#include <mc_typeconv.h>
#include <mc_transactors.h>
#include <mc_comparator.h>
#include <mc_end_of_testbench.h>
#include <vector>


class testbench : public sc_module
{
public:
   // Interface Ports
   sc_in< bool > clk;
   sc_port< tlm::tlm_fifo_put_if< mgc_sysc_ver_array1D<ac_int<8, false >,76800> > > ccs_Src;
   sc_port< tlm::tlm_fifo_put_if< mc_wait_ctrl > > ccs_wait_ctrl_Src;
   sc_port< tlm::tlm_fifo_put_if< mgc_sysc_ver_array1D<ac_int<8, false >,76800> > > ccs_Comp_IN;
   sc_port< tlm::tlm_fifo_put_if< mc_wait_ctrl > > ccs_wait_ctrl_Comp_IN;
   sc_port< tlm::tlm_fifo_get_if< mgc_sysc_ver_array1D<ac_int<8, false >,76800> > > ccs_Comp;
   sc_port< tlm::tlm_fifo_put_if< mc_wait_ctrl > > ccs_wait_ctrl_Comp;
   sc_port< tlm::tlm_fifo_get_if< mgc_sysc_ver_array1D<ac_int<8, false >,76800> > > ccs_Vga;
   sc_port< tlm::tlm_fifo_put_if< mc_wait_ctrl > > ccs_wait_ctrl_Vga;
   sc_port< tlm::tlm_fifo_put_if< ac_int<4, false > > > ccs_nblevels;
   sc_port< tlm::tlm_fifo_put_if< mc_wait_ctrl > > ccs_wait_ctrl_nblevels;
   sc_port< tlm::tlm_fifo_get_if< int > > ccs_Main_Only_Comp_Decomp__Main_Fonction_return;
   sc_port< tlm::tlm_fifo_put_if< mc_wait_ctrl > > ccs_wait_ctrl_Main_Only_Comp_Decomp__Main_Fonction_return;
   
   // Data objects
   bool testbench_ended;
   int main_exit_code;
   bool atleast_one_active_input;
   sc_time last_event_time;
   sc_time last_event_time2;
   sc_signal< bool >                          cpp_testbench_active;
   sc_event testbench_end_event;
   int argc;
   const char* const *argv;
   bool _checked_results;
   bool _failed;
   static testbench* that;
   static std::vector<mc_end_of_testbench*> _end_of_tb_objs;
   int main();
   static bool Src_ignore;
   static bool Src_skip;
   static int Src_array_comp_first;
   static int Src_array_comp_last;
   bool _capture_Src;
   static int Src_wait_cycles;
   static mc_wait_ctrl Src_wait_ctrl;
   int Src_capture_count;
   int Src_iteration_count;
   static bool Comp_ignore;
   static bool Comp_skip;
   static int Comp_array_comp_first;
   static int Comp_array_comp_last;
   bool _capture_Comp_IN;
   static int Comp_IN_wait_cycles;
   static mc_wait_ctrl Comp_IN_wait_ctrl;
   int Comp_IN_capture_count;
   int Comp_IN_iteration_count;
   static bool Comp_use_mask;
   static ac_int<8, false > Comp_output_mask;
   tlm::tlm_fifo< mc_golden_info< mgc_sysc_ver_array1D<ac_int<8, false >,76800>, ac_int<8, false > > > Comp_golden;
   bool _capture_Comp;
   static int Comp_wait_cycles;
   static mc_wait_ctrl Comp_wait_ctrl;
   int Comp_capture_count;
   int Comp_iteration_count;
   static bool Vga_ignore;
   static bool Vga_skip;
   static int Vga_array_comp_first;
   static int Vga_array_comp_last;
   static bool Vga_use_mask;
   static ac_int<8, false > Vga_output_mask;
   tlm::tlm_fifo< mc_golden_info< mgc_sysc_ver_array1D<ac_int<8, false >,76800>, ac_int<8, false > > > Vga_golden;
   bool _capture_Vga;
   static int Vga_wait_cycles;
   static mc_wait_ctrl Vga_wait_ctrl;
   int Vga_capture_count;
   int Vga_iteration_count;
   static bool nblevels_ignore;
   static bool nblevels_skip;
   static int nblevels_array_comp_first;
   static int nblevels_array_comp_last;
   bool _capture_nblevels;
   static int nblevels_wait_cycles;
   static mc_wait_ctrl nblevels_wait_ctrl;
   int nblevels_capture_count;
   int nblevels_iteration_count;
   static bool Main_Only_Comp_Decomp__Main_Fonction_return_ignore;
   static bool Main_Only_Comp_Decomp__Main_Fonction_return_skip;
   static int Main_Only_Comp_Decomp__Main_Fonction_return_array_comp_first;
   static int Main_Only_Comp_Decomp__Main_Fonction_return_array_comp_last;
   static bool Main_Only_Comp_Decomp__Main_Fonction_return_use_mask;
   static int Main_Only_Comp_Decomp__Main_Fonction_return_output_mask;
   tlm::tlm_fifo< mc_golden_info< int, int > > Main_Only_Comp_Decomp__Main_Fonction_return_golden;
   bool _capture_Main_Only_Comp_Decomp__Main_Fonction_return;
   static int Main_Only_Comp_Decomp__Main_Fonction_return_wait_cycles;
   static mc_wait_ctrl Main_Only_Comp_Decomp__Main_Fonction_return_wait_ctrl;
   int Main_Only_Comp_Decomp__Main_Fonction_return_capture_count;
   int Main_Only_Comp_Decomp__Main_Fonction_return_iteration_count;
   int wait_cnt;
   
   // Named Objects
   
   // Module instance pointers
   mc_comparator< mgc_sysc_ver_array1D<ac_int<8, false >,76800> , ac_int<8, false > > *Comp_comp;
   mc_comparator< mgc_sysc_ver_array1D<ac_int<8, false >,76800> , ac_int<8, false > > *Vga_comp;
   mc_comparator< int , int > *Main_Only_Comp_Decomp__Main_Fonction_return_comp;
   
   // Declare processes (SC_METHOD and SC_THREAD)
   void wait_for_end();
   void run();
   
   // Constructor
   SC_HAS_PROCESS(testbench);
   testbench(
      const sc_module_name& name
   )
      : clk("clk")
      , ccs_Src("ccs_Src")
      , ccs_wait_ctrl_Src("ccs_wait_ctrl_Src")
      , ccs_Comp_IN("ccs_Comp_IN")
      , ccs_wait_ctrl_Comp_IN("ccs_wait_ctrl_Comp_IN")
      , ccs_Comp("ccs_Comp")
      , ccs_wait_ctrl_Comp("ccs_wait_ctrl_Comp")
      , ccs_Vga("ccs_Vga")
      , ccs_wait_ctrl_Vga("ccs_wait_ctrl_Vga")
      , ccs_nblevels("ccs_nblevels")
      , ccs_wait_ctrl_nblevels("ccs_wait_ctrl_nblevels")
      , ccs_Main_Only_Comp_Decomp__Main_Fonction_return("ccs_Main_Only_Comp_Decomp__Main_Fonction_return")
      , ccs_wait_ctrl_Main_Only_Comp_Decomp__Main_Fonction_return("ccs_wait_ctrl_Main_Only_Comp_Decomp__Main_Fonction_return")
      , cpp_testbench_active("cpp_testbench_active")
      , Comp_golden("Comp_golden",-1)
      , Vga_golden("Vga_golden",-1)
      , Main_Only_Comp_Decomp__Main_Fonction_return_golden("Main_Only_Comp_Decomp__Main_Fonction_return_golden",-1)
   {
      // Instantiate other modules
      Comp_comp = new mc_comparator< mgc_sysc_ver_array1D<ac_int<8, false >,76800> , ac_int<8, false > > (
         "Comp_comp",
         0,
         1
      );
      Comp_comp->data_in(ccs_Comp);
      Comp_comp->data_golden(Comp_golden);
      
      Vga_comp = new mc_comparator< mgc_sysc_ver_array1D<ac_int<8, false >,76800> , ac_int<8, false > > (
         "Vga_comp",
         0,
         1
      );
      Vga_comp->data_in(ccs_Vga);
      Vga_comp->data_golden(Vga_golden);
      
      Main_Only_Comp_Decomp__Main_Fonction_return_comp = new mc_comparator< int , int > (
         "Main_Only_Comp_Decomp__Main_Fonction_return_comp",
         0,
         1
      );
      Main_Only_Comp_Decomp__Main_Fonction_return_comp->data_in(ccs_Main_Only_Comp_Decomp__Main_Fonction_return);
      Main_Only_Comp_Decomp__Main_Fonction_return_comp->data_golden(Main_Only_Comp_Decomp__Main_Fonction_return_golden);
      
      
      // Register processes
      SC_METHOD(wait_for_end);
      sensitive << clk.pos() << testbench_end_event;
      SC_THREAD(run);
      // Other constructor statements
      set_stack_size(64000000);
      argc = sc_argc();
      argv = sc_argv();
      _checked_results = false;
      that = this;
      testbench_ended = false;
      main_exit_code = 0;
      atleast_one_active_input = true;
      _capture_Src = true;
      _capture_Comp_IN = true;
      _capture_Comp = true;
      _capture_Vga = true;
      _capture_nblevels = true;
      _capture_Main_Only_Comp_Decomp__Main_Fonction_return = true;
      wait_cnt = 0;
   }
   
   ~testbench()
   {
      delete Comp_comp;
      Comp_comp = 0;
      delete Vga_comp;
      Vga_comp = 0;
      delete Main_Only_Comp_Decomp__Main_Fonction_return_comp;
      Main_Only_Comp_Decomp__Main_Fonction_return_comp = 0;
   }
   
   // C++ class functions
   public:
      void mc_testbench_process_wait_ctrl(const sc_string &var,int &var_wait_cycles,mc_wait_ctrl &var_wait_ctrl,tlm::tlm_fifo_put_if< mc_wait_ctrl > *ccs_wait_ctrl_fifo_if,const int var_capture_count,const int var_stopat) ;
   public:
      static void register_end_of_testbench_obj(mc_end_of_testbench* obj) ;
   public:
      void capture_Src( ac_int<8, false > Src[76800]) ;
   public:
      void capture_Comp_IN( ac_int<8, false > Comp[76800]) ;
   public:
      void capture_Comp( ac_int<8, false > Comp[76800]) ;
   public:
      void capture_Vga( ac_int<8, false > Vga[76800]) ;
   public:
      void capture_nblevels(ac_int<4, false > nblevels) ;
   public:
      void capture__TOP__return(int _TOP__return) ;
   protected:
      void wait_on_input_required() ;
   public:
      static void capture_IN(Main_Only_Comp_Decomp *Main_Only_Comp_Decomp__this,  ac_int<8, false > Src[76800],  ac_int<8, false > Comp[76800],  ac_int<8, false > Vga[76800], ac_int<4, false > nblevels) ;
   public:
      static void capture_OUT(int _TOP__return, Main_Only_Comp_Decomp *Main_Only_Comp_Decomp__this,  ac_int<8, false > Src[76800],  ac_int<8, false > Comp[76800],  ac_int<8, false > Vga[76800], ac_int<4, false > nblevels) ;
   public:
      static int exec_Main_Fonction(Main_Only_Comp_Decomp *Main_Only_Comp_Decomp__this,  ac_int<8, false > Src[76800],  ac_int<8, false > Comp[76800],  ac_int<8, false > Vga[76800], ac_int<4, false > nblevels) ;
   protected:
      void end_of_simulation() ;
   public:
      void check_results() ;
   public:
      bool failed() ;
};
#endif
#endif
