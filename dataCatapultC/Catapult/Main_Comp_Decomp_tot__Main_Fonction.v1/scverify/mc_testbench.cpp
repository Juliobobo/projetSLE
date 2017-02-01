// ----------------------------------------------------------------------------
// SystemC Testbench Body
//
//    HLS version: 2011a.200 Production Release
//       HLS date: Mon Jun  2 22:10:04 PDT 2014
//  Flow Packages: HDL_Tcl 2008a.1, SCVerify 2009a.1
//
//   Generated by: xph3sle512@cimeld21
// Generated date: Wed Feb 01 12:33:13 CET 2017
//
// ----------------------------------------------------------------------------
// 
// -------------------------------------
// testbench
// User supplied testbench
// -------------------------------------
// 
#include "mc_testbench.h"
#include <mc_simulator_extensions.h>

testbench* testbench::that;
std::vector<mc_end_of_testbench*> testbench::_end_of_tb_objs;
bool testbench::Src_ignore;
bool testbench::Src_skip;
void mc_testbench_Src_skip(bool v) { testbench::Src_skip = v; }
int testbench::Src_array_comp_first;
int testbench::Src_array_comp_last;
int testbench::Src_IN_wait_cycles;
mc_wait_ctrl testbench::Src_IN_wait_ctrl;
bool testbench::Src_use_mask;
ac_int<8, false > testbench::Src_output_mask;
int testbench::Src_wait_cycles;
mc_wait_ctrl testbench::Src_wait_ctrl;
bool testbench::Comp_ignore;
bool testbench::Comp_skip;
void mc_testbench_Comp_skip(bool v) { testbench::Comp_skip = v; }
int testbench::Comp_array_comp_first;
int testbench::Comp_array_comp_last;
int testbench::Comp_IN_wait_cycles;
mc_wait_ctrl testbench::Comp_IN_wait_ctrl;
bool testbench::Comp_use_mask;
ac_int<8, false > testbench::Comp_output_mask;
int testbench::Comp_wait_cycles;
mc_wait_ctrl testbench::Comp_wait_ctrl;
bool testbench::Decomp_ignore;
bool testbench::Decomp_skip;
void mc_testbench_Decomp_skip(bool v) { testbench::Decomp_skip = v; }
int testbench::Decomp_array_comp_first;
int testbench::Decomp_array_comp_last;
int testbench::Decomp_wait_cycles;
mc_wait_ctrl testbench::Decomp_wait_ctrl;
bool testbench::Vga_ignore;
bool testbench::Vga_skip;
void mc_testbench_Vga_skip(bool v) { testbench::Vga_skip = v; }
int testbench::Vga_array_comp_first;
int testbench::Vga_array_comp_last;
int testbench::Vga_IN_wait_cycles;
mc_wait_ctrl testbench::Vga_IN_wait_ctrl;
bool testbench::Vga_use_mask;
ac_int<8, false > testbench::Vga_output_mask;
int testbench::Vga_wait_cycles;
mc_wait_ctrl testbench::Vga_wait_ctrl;
bool testbench::nblevels_ignore;
bool testbench::nblevels_skip;
void mc_testbench_nblevels_skip(bool v) { testbench::nblevels_skip = v; }
int testbench::nblevels_array_comp_first;
int testbench::nblevels_array_comp_last;
int testbench::nblevels_wait_cycles;
mc_wait_ctrl testbench::nblevels_wait_ctrl;
bool testbench::change_mode_ignore;
bool testbench::change_mode_skip;
void mc_testbench_change_mode_skip(bool v) { testbench::change_mode_skip = v; }
int testbench::change_mode_array_comp_first;
int testbench::change_mode_array_comp_last;
int testbench::change_mode_wait_cycles;
mc_wait_ctrl testbench::change_mode_wait_ctrl;
bool testbench::Main_Comp_Decomp_tot__Main_Fonction_return_ignore;
bool testbench::Main_Comp_Decomp_tot__Main_Fonction_return_skip;
void mc_testbench_Main_Comp_Decomp_tot__Main_Fonction_return_skip(bool v) { testbench::Main_Comp_Decomp_tot__Main_Fonction_return_skip = v; }
int testbench::Main_Comp_Decomp_tot__Main_Fonction_return_array_comp_first;
int testbench::Main_Comp_Decomp_tot__Main_Fonction_return_array_comp_last;
bool testbench::Main_Comp_Decomp_tot__Main_Fonction_return_use_mask;
int testbench::Main_Comp_Decomp_tot__Main_Fonction_return_output_mask;
int testbench::Main_Comp_Decomp_tot__Main_Fonction_return_wait_cycles;
mc_wait_ctrl testbench::Main_Comp_Decomp_tot__Main_Fonction_return_wait_ctrl;

// ============================================
// Function: mc_testbench_process_wait_ctrl
// --------------------------------------------

void testbench::mc_testbench_process_wait_ctrl(const sc_string &var,int &var_wait_cycles,mc_wait_ctrl &var_wait_ctrl,tlm::tlm_fifo_put_if< mc_wait_ctrl > *ccs_wait_ctrl_fifo_if,const int var_capture_count,const int var_stopat)
{
   if (var_wait_cycles) {
      // backward compatibility mode
      var_wait_ctrl.cycles = var_wait_cycles;
      var_wait_cycles = 0;
      std::ostringstream msg; msg.str("");
      msg << "Depricated use of '" << var << "_wait_cycles' variable. Use '" << var << "_wait_ctrl.cycles' instead.";
      SC_REPORT_WARNING("User testbench", msg.str().c_str());
   }
   if (var_wait_ctrl.cycles != 0) {
      var_wait_ctrl.iteration = var_capture_count;
      var_wait_ctrl.stopat = var_stopat;
      if (var_wait_ctrl.cycles < 0) {
         std::ostringstream msg; msg.str("");
         msg << "Ignoring negative value (" << var_wait_ctrl.cycles << ") for testbench control testbench::" << var << "_wait_ctrl.cycles.";
         SC_REPORT_WARNING("User testbench", msg.str().c_str());
         var_wait_ctrl.cycles = 0;
      }
      if (var_wait_ctrl.interval < 0) {
         std::ostringstream msg; msg.str("");
         msg << "Ignoring negative value (" << var_wait_ctrl.interval << ") for testbench control testbench::" << var << "_wait_ctrl.interval.";
         SC_REPORT_WARNING("User testbench", msg.str().c_str());
         var_wait_ctrl.interval = 0;
      }
      if (var_wait_ctrl.is_set()) {
         std::ostringstream msg; msg.str("");
         msg << "Captured wait_ctrl request " << var_wait_ctrl;
         SC_REPORT_INFO("User testbench", msg.str().c_str());
         ccs_wait_ctrl_fifo_if->put(var_wait_ctrl);
      }
   }
   var_wait_ctrl.clear(); // reset wait_ctrl
}
// ============================================
// Function: register_end_of_testbench_obj
// --------------------------------------------

void testbench::register_end_of_testbench_obj(mc_end_of_testbench* obj)
{
   _end_of_tb_objs.push_back(obj);
}
// ============================================
// Function: capture_Src_IN
// --------------------------------------------

void testbench::capture_Src_IN( ac_int<8, false > Src[76800])
{
   if (Src_IN_capture_count == wait_cnt)
      wait_on_input_required();
   if (_capture_Src_IN && !Src_ignore)
   {
      int cur_iter=Src_IN_iteration_count;
      ++Src_IN_iteration_count;
      mgc_sysc_ver_array1D<ac_int<8, false >,76800> Src_IN_tmp;
               int Src_linear_idx = 0;
               for (int Src_idx_0 = 0; Src_idx_0 < 76800; ++Src_idx_0)
                  Src_IN_tmp[Src_linear_idx++] = Src[Src_idx_0];
      ccs_Src_IN->put(Src_IN_tmp);
      ++Src_IN_capture_count;
      if (cur_iter < Src_IN_capture_count)
         mc_testbench_process_wait_ctrl("Src_IN",Src_IN_wait_cycles,Src_IN_wait_ctrl,ccs_wait_ctrl_Src_IN.operator->(),cur_iter,Src_IN_capture_count);
      Src_ignore = false;
   }
}
// ============================================
// Function: capture_Src
// --------------------------------------------

void testbench::capture_Src( ac_int<8, false > Src[76800])
{
   if (_capture_Src)
   {
      int cur_iter=Src_iteration_count;
      ++Src_iteration_count;
      mc_golden_info< mgc_sysc_ver_array1D<ac_int<8, false >,76800>, ac_int<8, false > > Src_tmp(Src_ignore, false, Src_iteration_count);
      Src_tmp._data.mc_testbench_process_array_bounds("Src",Src_array_comp_first,Src_array_comp_last,76799,0);
      // BEGIN: testbench output_mask control for field_name Src
      if ( Src_use_mask ) {
         Src_tmp._use_mask = true;
         Src_tmp._mask = Src_output_mask ;
      }
      // END: testbench output_mask control for field_name Src
               int Src_linear_idx = 0;
               for (int Src_idx_0 = 0; Src_idx_0 < 76800; ++Src_idx_0)
                  Src_tmp._data[Src_linear_idx++] = Src[Src_idx_0];
      if (!Src_skip) {
         Src_golden.put(Src_tmp);
         ++Src_capture_count;
      } else {
         std::ostringstream msg; msg.str("");
         msg << "Src_skip=true for iteration=" << Src_iteration_count << " @ " << sc_time_stamp();
         SC_REPORT_WARNING("User testbench", msg.str().c_str());
      }
      if (cur_iter < Src_capture_count)
         mc_testbench_process_wait_ctrl("Src",Src_wait_cycles,Src_wait_ctrl,ccs_wait_ctrl_Src.operator->(),cur_iter,Src_capture_count);
      Src_ignore = false;
      Src_use_mask = false;
   }
   Src_skip = false;
}
// ============================================
// Function: capture_Comp_IN
// --------------------------------------------

void testbench::capture_Comp_IN( ac_int<8, false > Comp[76800])
{
   if (Comp_IN_capture_count == wait_cnt)
      wait_on_input_required();
   if (_capture_Comp_IN && !Comp_ignore)
   {
      int cur_iter=Comp_IN_iteration_count;
      ++Comp_IN_iteration_count;
      mgc_sysc_ver_array1D<ac_int<8, false >,76800> Comp_IN_tmp;
               int Comp_linear_idx = 0;
               for (int Comp_idx_0 = 0; Comp_idx_0 < 76800; ++Comp_idx_0)
                  Comp_IN_tmp[Comp_linear_idx++] = Comp[Comp_idx_0];
      ccs_Comp_IN->put(Comp_IN_tmp);
      ++Comp_IN_capture_count;
      if (cur_iter < Comp_IN_capture_count)
         mc_testbench_process_wait_ctrl("Comp_IN",Comp_IN_wait_cycles,Comp_IN_wait_ctrl,ccs_wait_ctrl_Comp_IN.operator->(),cur_iter,Comp_IN_capture_count);
      Comp_ignore = false;
   }
}
// ============================================
// Function: capture_Comp
// --------------------------------------------

void testbench::capture_Comp( ac_int<8, false > Comp[76800])
{
   if (_capture_Comp)
   {
      int cur_iter=Comp_iteration_count;
      ++Comp_iteration_count;
      mc_golden_info< mgc_sysc_ver_array1D<ac_int<8, false >,76800>, ac_int<8, false > > Comp_tmp(Comp_ignore, false, Comp_iteration_count);
      Comp_tmp._data.mc_testbench_process_array_bounds("Comp",Comp_array_comp_first,Comp_array_comp_last,76799,0);
      // BEGIN: testbench output_mask control for field_name Comp
      if ( Comp_use_mask ) {
         Comp_tmp._use_mask = true;
         Comp_tmp._mask = Comp_output_mask ;
      }
      // END: testbench output_mask control for field_name Comp
               int Comp_linear_idx = 0;
               for (int Comp_idx_0 = 0; Comp_idx_0 < 76800; ++Comp_idx_0)
                  Comp_tmp._data[Comp_linear_idx++] = Comp[Comp_idx_0];
      if (!Comp_skip) {
         Comp_golden.put(Comp_tmp);
         ++Comp_capture_count;
      } else {
         std::ostringstream msg; msg.str("");
         msg << "Comp_skip=true for iteration=" << Comp_iteration_count << " @ " << sc_time_stamp();
         SC_REPORT_WARNING("User testbench", msg.str().c_str());
      }
      if (cur_iter < Comp_capture_count)
         mc_testbench_process_wait_ctrl("Comp",Comp_wait_cycles,Comp_wait_ctrl,ccs_wait_ctrl_Comp.operator->(),cur_iter,Comp_capture_count);
      Comp_ignore = false;
      Comp_use_mask = false;
   }
   Comp_skip = false;
}
// ============================================
// Function: capture_Decomp
// --------------------------------------------

void testbench::capture_Decomp( ac_int<8, false > Decomp[76800])
{
   if (Decomp_capture_count == wait_cnt)
      wait_on_input_required();
   if (_capture_Decomp && !Decomp_ignore)
   {
      int cur_iter=Decomp_iteration_count;
      ++Decomp_iteration_count;
      mgc_sysc_ver_array1D<ac_int<8, false >,76800> Decomp_tmp;
               int Decomp_linear_idx = 0;
               for (int Decomp_idx_0 = 0; Decomp_idx_0 < 76800; ++Decomp_idx_0)
                  Decomp_tmp[Decomp_linear_idx++] = Decomp[Decomp_idx_0];
      ccs_Decomp->put(Decomp_tmp);
      ++Decomp_capture_count;
      if (cur_iter < Decomp_capture_count)
         mc_testbench_process_wait_ctrl("Decomp",Decomp_wait_cycles,Decomp_wait_ctrl,ccs_wait_ctrl_Decomp.operator->(),cur_iter,Decomp_capture_count);
      Decomp_ignore = false;
   }
}
// ============================================
// Function: capture_Vga_IN
// --------------------------------------------

void testbench::capture_Vga_IN( ac_int<8, false > Vga[76800])
{
   if (Vga_IN_capture_count == wait_cnt)
      wait_on_input_required();
   if (_capture_Vga_IN && !Vga_ignore)
   {
      int cur_iter=Vga_IN_iteration_count;
      ++Vga_IN_iteration_count;
      mgc_sysc_ver_array1D<ac_int<8, false >,76800> Vga_IN_tmp;
               int Vga_linear_idx = 0;
               for (int Vga_idx_0 = 0; Vga_idx_0 < 76800; ++Vga_idx_0)
                  Vga_IN_tmp[Vga_linear_idx++] = Vga[Vga_idx_0];
      ccs_Vga_IN->put(Vga_IN_tmp);
      ++Vga_IN_capture_count;
      if (cur_iter < Vga_IN_capture_count)
         mc_testbench_process_wait_ctrl("Vga_IN",Vga_IN_wait_cycles,Vga_IN_wait_ctrl,ccs_wait_ctrl_Vga_IN.operator->(),cur_iter,Vga_IN_capture_count);
      Vga_ignore = false;
   }
}
// ============================================
// Function: capture_Vga
// --------------------------------------------

void testbench::capture_Vga( ac_int<8, false > Vga[76800])
{
   if (_capture_Vga)
   {
      int cur_iter=Vga_iteration_count;
      ++Vga_iteration_count;
      mc_golden_info< mgc_sysc_ver_array1D<ac_int<8, false >,76800>, ac_int<8, false > > Vga_tmp(Vga_ignore, false, Vga_iteration_count);
      Vga_tmp._data.mc_testbench_process_array_bounds("Vga",Vga_array_comp_first,Vga_array_comp_last,76799,0);
      // BEGIN: testbench output_mask control for field_name Vga
      if ( Vga_use_mask ) {
         Vga_tmp._use_mask = true;
         Vga_tmp._mask = Vga_output_mask ;
      }
      // END: testbench output_mask control for field_name Vga
               int Vga_linear_idx = 0;
               for (int Vga_idx_0 = 0; Vga_idx_0 < 76800; ++Vga_idx_0)
                  Vga_tmp._data[Vga_linear_idx++] = Vga[Vga_idx_0];
      if (!Vga_skip) {
         Vga_golden.put(Vga_tmp);
         ++Vga_capture_count;
      } else {
         std::ostringstream msg; msg.str("");
         msg << "Vga_skip=true for iteration=" << Vga_iteration_count << " @ " << sc_time_stamp();
         SC_REPORT_WARNING("User testbench", msg.str().c_str());
      }
      if (cur_iter < Vga_capture_count)
         mc_testbench_process_wait_ctrl("Vga",Vga_wait_cycles,Vga_wait_ctrl,ccs_wait_ctrl_Vga.operator->(),cur_iter,Vga_capture_count);
      Vga_ignore = false;
      Vga_use_mask = false;
   }
   Vga_skip = false;
}
// ============================================
// Function: capture_nblevels
// --------------------------------------------

void testbench::capture_nblevels(ac_int<4, false > nblevels)
{
   if (nblevels_capture_count == wait_cnt)
      wait_on_input_required();
   if (_capture_nblevels && !nblevels_ignore)
   {
      int cur_iter=nblevels_iteration_count;
      ++nblevels_iteration_count;
      ccs_nblevels->put(nblevels);
      ++nblevels_capture_count;
      if (cur_iter < nblevels_capture_count)
         mc_testbench_process_wait_ctrl("nblevels",nblevels_wait_cycles,nblevels_wait_ctrl,ccs_wait_ctrl_nblevels.operator->(),cur_iter,nblevels_capture_count);
      nblevels_ignore = false;
   }
}
// ============================================
// Function: capture_change_mode
// --------------------------------------------

void testbench::capture_change_mode(ac_int<4, false > change_mode)
{
   if (change_mode_capture_count == wait_cnt)
      wait_on_input_required();
   if (_capture_change_mode && !change_mode_ignore)
   {
      int cur_iter=change_mode_iteration_count;
      ++change_mode_iteration_count;
      ccs_change_mode->put(change_mode);
      ++change_mode_capture_count;
      if (cur_iter < change_mode_capture_count)
         mc_testbench_process_wait_ctrl("change_mode",change_mode_wait_cycles,change_mode_wait_ctrl,ccs_wait_ctrl_change_mode.operator->(),cur_iter,change_mode_capture_count);
      change_mode_ignore = false;
   }
}
// ============================================
// Function: capture__TOP__return
// --------------------------------------------

void testbench::capture__TOP__return(int _TOP__return)
{
   if (_capture_Main_Comp_Decomp_tot__Main_Fonction_return)
   {
      int cur_iter=Main_Comp_Decomp_tot__Main_Fonction_return_iteration_count;
      ++Main_Comp_Decomp_tot__Main_Fonction_return_iteration_count;
      mc_golden_info< int, int > Main_Comp_Decomp_tot__Main_Fonction_return_tmp(_TOP__return, Main_Comp_Decomp_tot__Main_Fonction_return_ignore, ~0, false, Main_Comp_Decomp_tot__Main_Fonction_return_iteration_count);
      // BEGIN: testbench output_mask control for field_name Main_Comp_Decomp_tot__Main_Fonction_return
      if ( Main_Comp_Decomp_tot__Main_Fonction_return_use_mask ) {
         Main_Comp_Decomp_tot__Main_Fonction_return_tmp._use_mask = true;
         Main_Comp_Decomp_tot__Main_Fonction_return_tmp._mask = Main_Comp_Decomp_tot__Main_Fonction_return_output_mask ;
      }
      // END: testbench output_mask control for field_name Main_Comp_Decomp_tot__Main_Fonction_return
      if (!Main_Comp_Decomp_tot__Main_Fonction_return_skip) {
         Main_Comp_Decomp_tot__Main_Fonction_return_golden.put(Main_Comp_Decomp_tot__Main_Fonction_return_tmp);
         ++Main_Comp_Decomp_tot__Main_Fonction_return_capture_count;
      } else {
         std::ostringstream msg; msg.str("");
         msg << "Main_Comp_Decomp_tot__Main_Fonction_return_skip=true for iteration=" << Main_Comp_Decomp_tot__Main_Fonction_return_iteration_count << " @ " << sc_time_stamp();
         SC_REPORT_WARNING("User testbench", msg.str().c_str());
      }
      if (cur_iter < Main_Comp_Decomp_tot__Main_Fonction_return_capture_count)
         mc_testbench_process_wait_ctrl("Main_Comp_Decomp_tot__Main_Fonction_return",Main_Comp_Decomp_tot__Main_Fonction_return_wait_cycles,Main_Comp_Decomp_tot__Main_Fonction_return_wait_ctrl,ccs_wait_ctrl_Main_Comp_Decomp_tot__Main_Fonction_return.operator->(),cur_iter,Main_Comp_Decomp_tot__Main_Fonction_return_capture_count);
      Main_Comp_Decomp_tot__Main_Fonction_return_ignore = false;
      Main_Comp_Decomp_tot__Main_Fonction_return_use_mask = false;
   }
   Main_Comp_Decomp_tot__Main_Fonction_return_skip = false;
}
// ============================================
// Function: wait_on_input_required
// --------------------------------------------

void testbench::wait_on_input_required()
{
   ++wait_cnt;
   wait(SC_ZERO_TIME); // get fifos a chance to update
   while (atleast_one_active_input) {
      if (_capture_Src_IN && ccs_Src_IN->used() == 0) return;
      if (_capture_Comp_IN && ccs_Comp_IN->used() == 0) return;
      if (_capture_Decomp && ccs_Decomp->used() == 0) return;
      if (_capture_Vga_IN && ccs_Vga_IN->used() == 0) return;
      if (_capture_nblevels && ccs_nblevels->used() == 0) return;
      if (_capture_change_mode && ccs_change_mode->used() == 0) return;
      that->cpp_testbench_active.write(false);
      wait(ccs_Src_IN->ok_to_put() | ccs_Comp_IN->ok_to_put() | ccs_Decomp->ok_to_put() | ccs_Vga_IN->ok_to_put() | ccs_nblevels->ok_to_put() | ccs_change_mode->ok_to_put());
      that->cpp_testbench_active.write(true);
   }
}
// ============================================
// Function: capture_IN
// --------------------------------------------

void testbench::capture_IN(Main_Comp_Decomp_tot *Main_Comp_Decomp_tot__this,  ac_int<8, false > Src[76800],  ac_int<8, false > Comp[76800],  ac_int<8, false > Decomp[76800],  ac_int<8, false > Vga[76800], ac_int<4, false > nblevels, ac_int<4, false > change_mode)
{
   that->capture_Src_IN(Src);
   that->capture_Comp_IN(Comp);
   that->capture_Decomp(Decomp);
   that->capture_Vga_IN(Vga);
   that->capture_nblevels(nblevels);
   that->capture_change_mode(change_mode);
}
// ============================================
// Function: capture_OUT
// --------------------------------------------

void testbench::capture_OUT(int _TOP__return, Main_Comp_Decomp_tot *Main_Comp_Decomp_tot__this,  ac_int<8, false > Src[76800],  ac_int<8, false > Comp[76800],  ac_int<8, false > Decomp[76800],  ac_int<8, false > Vga[76800], ac_int<4, false > nblevels, ac_int<4, false > change_mode)
{
   that->capture_Src(Src);
   that->capture_Comp(Comp);
   that->capture_Vga(Vga);
   that->capture__TOP__return(_TOP__return);
}
// ============================================
// Function: exec_Main_Fonction
// --------------------------------------------

int testbench::exec_Main_Fonction(Main_Comp_Decomp_tot *Main_Comp_Decomp_tot__this,  ac_int<8, false > Src[76800],  ac_int<8, false > Comp[76800],  ac_int<8, false > Decomp[76800],  ac_int<8, false > Vga[76800], ac_int<4, false > nblevels, ac_int<4, false > change_mode)
{
   that->cpp_testbench_active.write(true);
   capture_IN(Main_Comp_Decomp_tot__this, Src, Comp, Decomp, Vga, nblevels, change_mode);
   int _TOP__return = Main_Comp_Decomp_tot__this->Main_Comp_Decomp_tot::Main_Fonction(Src, Comp, Decomp, Vga, nblevels, change_mode);
   // throttle ac_channel based on number of calls to chan::size() or chan::empty() or chan::nb_read() (but not chan::available()) 
   if (1) {
      int cnt=0;
      if (cnt) std::cout << "mc_testbench.cpp: CONTINUES @ " << sc_time_stamp() << std::endl;
      if (cnt) that->cpp_testbench_active.write(true);
   }
   capture_OUT(_TOP__return, Main_Comp_Decomp_tot__this, Src, Comp, Decomp, Vga, nblevels, change_mode);
   return _TOP__return;
}
// ============================================
// Function: end_of_simulation
// --------------------------------------------

void testbench::end_of_simulation()
{
   if (!_checked_results) {
      SC_REPORT_INFO(name(), "Simulation ran into deadlock");
      check_results();
   }
}
// ============================================
// Function: check_results
// --------------------------------------------

void testbench::check_results()
{
   for (std::vector<mc_end_of_testbench*>::iterator i = _end_of_tb_objs.begin(); i != _end_of_tb_objs.end(); ++i)
      (*i)->end_of_testbench();
   
   _checked_results = true;
   cout<<endl;
   cout<<"Checking results"<<endl;
   _failed = false;
   if (main_exit_code) _failed = true;
   int _num_outputs_checked = 0;
   
   if (!_capture_Src) {
      cout<<"'Src' - warning, output was optimized away"<<endl;
   } else {
      _num_outputs_checked++;
      cout<<"'Src'"<<endl;
      cout<<"   capture count        = "<<Src_capture_count<<endl;
      cout<<"   comparison count     = "<<Src_comp->get_compare_count();
      if (Src_comp->get_partial_compare_count()) 
         cout <<" ("<<Src_comp->get_partial_compare_count()<<" partial)";
      if (Src_comp->get_mask_compare_count()) 
         cout <<" ("<<Src_comp->get_mask_compare_count()<<" masked)";
      cout << endl;
      cout<<"   ignore count         = "<<Src_comp->get_ignore_count()<<endl;
      cout<<"   error count          = "<<Src_comp->get_error_count()<<endl;
      cout<<"   stuck in dut fifo    = "<<ccs_Src->used()<<endl;
      cout<<"   stuck in golden fifo = "<<Src_golden.used()<<endl;
      if (Src_comp->get_error_count() > 0) cout << "   Error: output 'Src' had comparison errors"<<endl;
      if (Src_comp->get_compare_count() < Src_capture_count) cout << "   Error: output 'Src' has incomplete comparisons"<<endl;
      if (Src_capture_count == 0) cout << "   Error: output 'Src' has no golden values to compare against"<<endl;
      _failed = _failed || Src_comp->get_error_count() > 0;
      _failed = _failed || Src_comp->get_compare_count() < Src_capture_count;
      _failed = _failed || Src_capture_count == 0;
      cout<<endl;
   }
   if (!_capture_Comp) {
      cout<<"'Comp' - warning, output was optimized away"<<endl;
   } else {
      _num_outputs_checked++;
      cout<<"'Comp'"<<endl;
      cout<<"   capture count        = "<<Comp_capture_count<<endl;
      cout<<"   comparison count     = "<<Comp_comp->get_compare_count();
      if (Comp_comp->get_partial_compare_count()) 
         cout <<" ("<<Comp_comp->get_partial_compare_count()<<" partial)";
      if (Comp_comp->get_mask_compare_count()) 
         cout <<" ("<<Comp_comp->get_mask_compare_count()<<" masked)";
      cout << endl;
      cout<<"   ignore count         = "<<Comp_comp->get_ignore_count()<<endl;
      cout<<"   error count          = "<<Comp_comp->get_error_count()<<endl;
      cout<<"   stuck in dut fifo    = "<<ccs_Comp->used()<<endl;
      cout<<"   stuck in golden fifo = "<<Comp_golden.used()<<endl;
      if (Comp_comp->get_error_count() > 0) cout << "   Error: output 'Comp' had comparison errors"<<endl;
      if (Comp_comp->get_compare_count() < Comp_capture_count) cout << "   Error: output 'Comp' has incomplete comparisons"<<endl;
      if (Comp_capture_count == 0) cout << "   Error: output 'Comp' has no golden values to compare against"<<endl;
      _failed = _failed || Comp_comp->get_error_count() > 0;
      _failed = _failed || Comp_comp->get_compare_count() < Comp_capture_count;
      _failed = _failed || Comp_capture_count == 0;
      cout<<endl;
   }
   if (!_capture_Vga) {
      cout<<"'Vga' - warning, output was optimized away"<<endl;
   } else {
      _num_outputs_checked++;
      cout<<"'Vga'"<<endl;
      cout<<"   capture count        = "<<Vga_capture_count<<endl;
      cout<<"   comparison count     = "<<Vga_comp->get_compare_count();
      if (Vga_comp->get_partial_compare_count()) 
         cout <<" ("<<Vga_comp->get_partial_compare_count()<<" partial)";
      if (Vga_comp->get_mask_compare_count()) 
         cout <<" ("<<Vga_comp->get_mask_compare_count()<<" masked)";
      cout << endl;
      cout<<"   ignore count         = "<<Vga_comp->get_ignore_count()<<endl;
      cout<<"   error count          = "<<Vga_comp->get_error_count()<<endl;
      cout<<"   stuck in dut fifo    = "<<ccs_Vga->used()<<endl;
      cout<<"   stuck in golden fifo = "<<Vga_golden.used()<<endl;
      if (Vga_comp->get_error_count() > 0) cout << "   Error: output 'Vga' had comparison errors"<<endl;
      if (Vga_comp->get_compare_count() < Vga_capture_count) cout << "   Error: output 'Vga' has incomplete comparisons"<<endl;
      if (Vga_capture_count == 0) cout << "   Error: output 'Vga' has no golden values to compare against"<<endl;
      _failed = _failed || Vga_comp->get_error_count() > 0;
      _failed = _failed || Vga_comp->get_compare_count() < Vga_capture_count;
      _failed = _failed || Vga_capture_count == 0;
      cout<<endl;
   }
   if (!_capture_Main_Comp_Decomp_tot__Main_Fonction_return) {
      cout<<"'Main_Comp_Decomp_tot__Main_Fonction_return' - warning, output was optimized away"<<endl;
   } else {
      _num_outputs_checked++;
      cout<<"'Main_Comp_Decomp_tot__Main_Fonction_return'"<<endl;
      cout<<"   capture count        = "<<Main_Comp_Decomp_tot__Main_Fonction_return_capture_count<<endl;
      cout<<"   comparison count     = "<<Main_Comp_Decomp_tot__Main_Fonction_return_comp->get_compare_count();
      if (Main_Comp_Decomp_tot__Main_Fonction_return_comp->get_partial_compare_count()) 
         cout <<" ("<<Main_Comp_Decomp_tot__Main_Fonction_return_comp->get_partial_compare_count()<<" partial)";
      if (Main_Comp_Decomp_tot__Main_Fonction_return_comp->get_mask_compare_count()) 
         cout <<" ("<<Main_Comp_Decomp_tot__Main_Fonction_return_comp->get_mask_compare_count()<<" masked)";
      cout << endl;
      cout<<"   ignore count         = "<<Main_Comp_Decomp_tot__Main_Fonction_return_comp->get_ignore_count()<<endl;
      cout<<"   error count          = "<<Main_Comp_Decomp_tot__Main_Fonction_return_comp->get_error_count()<<endl;
      cout<<"   stuck in dut fifo    = "<<ccs_Main_Comp_Decomp_tot__Main_Fonction_return->used()<<endl;
      cout<<"   stuck in golden fifo = "<<Main_Comp_Decomp_tot__Main_Fonction_return_golden.used()<<endl;
      if (Main_Comp_Decomp_tot__Main_Fonction_return_comp->get_error_count() > 0) cout << "   Error: output 'Main_Comp_Decomp_tot__Main_Fonction_return' had comparison errors"<<endl;
      if (Main_Comp_Decomp_tot__Main_Fonction_return_comp->get_compare_count() < Main_Comp_Decomp_tot__Main_Fonction_return_capture_count) cout << "   Error: output 'Main_Comp_Decomp_tot__Main_Fonction_return' has incomplete comparisons"<<endl;
      if (Main_Comp_Decomp_tot__Main_Fonction_return_capture_count == 0) cout << "   Error: output 'Main_Comp_Decomp_tot__Main_Fonction_return' has no golden values to compare against"<<endl;
      _failed = _failed || Main_Comp_Decomp_tot__Main_Fonction_return_comp->get_error_count() > 0;
      _failed = _failed || Main_Comp_Decomp_tot__Main_Fonction_return_comp->get_compare_count() < Main_Comp_Decomp_tot__Main_Fonction_return_capture_count;
      _failed = _failed || Main_Comp_Decomp_tot__Main_Fonction_return_capture_count == 0;
      cout<<endl;
   }
   cout<<endl;
   if (_num_outputs_checked == 0) {
      cout<<"Error: All outputs were optimized away. No output values were compared."<<endl;
      _failed = _failed || (_num_outputs_checked == 0);
   }
   if (main_exit_code) cout << "Error: C++ Testbench 'main()' returned a non-zero exit code ("<<main_exit_code<<"). Check your testbench." <<endl;
   cout<<(_failed ? "Error: ":"Info: ")<<"Simulation "<<(_failed ? "FAILED":"PASSED")<<" @ "<<sc_time_stamp()<<endl;
}
// ============================================
// Function: failed
// --------------------------------------------

bool testbench::failed()
{
   return _failed;
}
// ---------------------------------------------------------------
// Process: SC_METHOD wait_for_end
// Static sensitivity: sensitive << clk.pos() << testbench_end_event;

void testbench::wait_for_end() {
   // If run() has not finished, we do nothing here
   if (!testbench_ended) return;
   // check for completed outputs
   if (Src_comp->get_compare_count() < Src_capture_count) {testbench_end_event.notify(1,SC_NS); return;}
   if (Comp_comp->get_compare_count() < Comp_capture_count) {testbench_end_event.notify(1,SC_NS); return;}
   if (Vga_comp->get_compare_count() < Vga_capture_count) {testbench_end_event.notify(1,SC_NS); return;}
   if (Main_Comp_Decomp_tot__Main_Fonction_return_comp->get_compare_count() < Main_Comp_Decomp_tot__Main_Fonction_return_capture_count) {testbench_end_event.notify(1,SC_NS); return;}
   // If we made it here, all outputs have flushed. Check the results
   SC_REPORT_INFO(name(), "Simulation completed");
   check_results();
   sc_stop();
}
// ---------------------------------------------------------------
// Process: SC_THREAD run
// Static sensitivity: 

void testbench::run() {
   Src_ignore = false;
   Src_skip = false;
   Src_array_comp_first = -1;
   Src_array_comp_last = -1;
   Src_IN_wait_cycles = 0;
   Src_IN_wait_ctrl.clear();
   Src_IN_capture_count = 0;
   Src_IN_iteration_count = 0;
   Src_use_mask = false;
   Src_output_mask = ~0;
   Src_wait_cycles = 0;
   Src_wait_ctrl.clear();
   Src_capture_count = 0;
   Src_iteration_count = 0;
   Comp_ignore = false;
   Comp_skip = false;
   Comp_array_comp_first = -1;
   Comp_array_comp_last = -1;
   Comp_IN_wait_cycles = 0;
   Comp_IN_wait_ctrl.clear();
   Comp_IN_capture_count = 0;
   Comp_IN_iteration_count = 0;
   Comp_use_mask = false;
   Comp_output_mask = ~0;
   Comp_wait_cycles = 0;
   Comp_wait_ctrl.clear();
   Comp_capture_count = 0;
   Comp_iteration_count = 0;
   Decomp_ignore = false;
   Decomp_skip = false;
   Decomp_array_comp_first = -1;
   Decomp_array_comp_last = -1;
   Decomp_wait_cycles = 0;
   Decomp_wait_ctrl.clear();
   Decomp_capture_count = 0;
   Decomp_iteration_count = 0;
   Vga_ignore = false;
   Vga_skip = false;
   Vga_array_comp_first = -1;
   Vga_array_comp_last = -1;
   Vga_IN_wait_cycles = 0;
   Vga_IN_wait_ctrl.clear();
   Vga_IN_capture_count = 0;
   Vga_IN_iteration_count = 0;
   Vga_use_mask = false;
   Vga_output_mask = ~0;
   Vga_wait_cycles = 0;
   Vga_wait_ctrl.clear();
   Vga_capture_count = 0;
   Vga_iteration_count = 0;
   nblevels_ignore = false;
   nblevels_skip = false;
   nblevels_array_comp_first = -1;
   nblevels_array_comp_last = -1;
   nblevels_wait_cycles = 0;
   nblevels_wait_ctrl.clear();
   nblevels_capture_count = 0;
   nblevels_iteration_count = 0;
   change_mode_ignore = false;
   change_mode_skip = false;
   change_mode_array_comp_first = -1;
   change_mode_array_comp_last = -1;
   change_mode_wait_cycles = 0;
   change_mode_wait_ctrl.clear();
   change_mode_capture_count = 0;
   change_mode_iteration_count = 0;
   Main_Comp_Decomp_tot__Main_Fonction_return_ignore = false;
   Main_Comp_Decomp_tot__Main_Fonction_return_skip = false;
   Main_Comp_Decomp_tot__Main_Fonction_return_array_comp_first = -1;
   Main_Comp_Decomp_tot__Main_Fonction_return_array_comp_last = -1;
   Main_Comp_Decomp_tot__Main_Fonction_return_use_mask = false;
   Main_Comp_Decomp_tot__Main_Fonction_return_output_mask = ~0;
   Main_Comp_Decomp_tot__Main_Fonction_return_wait_cycles = 0;
   Main_Comp_Decomp_tot__Main_Fonction_return_wait_ctrl.clear();
   Main_Comp_Decomp_tot__Main_Fonction_return_capture_count = 0;
   Main_Comp_Decomp_tot__Main_Fonction_return_iteration_count = 0;
   main_exit_code = main();
   cout<<"Info: Execution of user-supplied C++ testbench 'main()' has completed with exit code = " << main_exit_code << endl;
   cout<<endl;
   cout<<"Info: Collecting data completed"<<endl;
   cout<<"   captured "<<Src_IN_capture_count<<" values of Src_IN"<<endl;
   cout<<"   captured "<<Src_capture_count<<" values of Src"<<endl;
   cout<<"   captured "<<Comp_IN_capture_count<<" values of Comp_IN"<<endl;
   cout<<"   captured "<<Comp_capture_count<<" values of Comp"<<endl;
   cout<<"   captured "<<Decomp_capture_count<<" values of Decomp"<<endl;
   cout<<"   captured "<<Vga_IN_capture_count<<" values of Vga_IN"<<endl;
   cout<<"   captured "<<Vga_capture_count<<" values of Vga"<<endl;
   cout<<"   captured "<<nblevels_capture_count<<" values of nblevels"<<endl;
   cout<<"   captured "<<change_mode_capture_count<<" values of change_mode"<<endl;
   cout<<"   captured "<<Main_Comp_Decomp_tot__Main_Fonction_return_capture_count<<" values of Main_Comp_Decomp_tot__Main_Fonction_return"<<endl;
   testbench_ended = true;
   testbench_end_event.notify(SC_ZERO_TIME);
}