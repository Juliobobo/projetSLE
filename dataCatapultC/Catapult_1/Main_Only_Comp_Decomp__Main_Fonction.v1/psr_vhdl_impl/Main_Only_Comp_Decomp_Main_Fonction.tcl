#
# Generated by Precision RTL Synthesis 2014a.1_64-bit (Release Production Release, compiled Mon Feb 24 02:39:08 PST 2014)
#

## Setup project
file delete -force {vivado_impl_1/vivado_impl_1.ppr}
create_project vivado_impl_1 {vivado_impl_1} -part 7A100TCSG324-1
set_property design_mode GateLvl [current_fileset]
add_file -scan_for_includes {vivado_impl_1}
set_property top Main_Only_Comp_Decomp_Main_Fonction [current_fileset]
read_verilog {Main_Only_Comp_Decomp_Main_Fonction.v}
link_design
read_xdc {Main_Only_Comp_Decomp_Main_Fonction.xdc}

## Report project
report_property [current_project]
report_property [current_fileset]
report_property [current_fileset -constrset]

## P&R

if { [catch {opt_design -sweep -propconst -quiet} result] } {
  return -code error -errorinfo "can not run opt_design exiting ... $result"
}
if { [catch {place_design} result] } {
  return -code error -errorinfo "can not run place_design exiting ... $result"
}
if { [catch {route_design} result] } {
  return -code error -errorinfo "can not run route_design exiting ... $result"
}
## Output files and reports
write_checkpoint {vivado_impl_1/Main_Only_Comp_Decomp_Main_Fonction_routed.dcp}
write_xdef {vivado_impl_1/routed_Main_Only_Comp_Decomp_Main_Fonction.xdef}
report_timing -path_type full_clock_expanded -sort_by group -nworst 30 -file {vivado_impl_1/Main_Only_Comp_Decomp_Main_Fonction_timing.twr}
report_timing -path_type full_clock_expanded -sort_by group -rise_from * -rise_to * -file {vivado_impl_1/Main_Only_Comp_Decomp_Main_Fonction_short_timing.twr}
report_timing -path_type full_clock_expanded -sort_by group -fall_from * -fall_to * -file {vivado_impl_1/Main_Only_Comp_Decomp_Main_Fonction_short_timing.twr} -append
report_timing -path_type full_clock_expanded -sort_by group -rise_from * -fall_to * -file {vivado_impl_1/Main_Only_Comp_Decomp_Main_Fonction_short_timing.twr} -append
report_timing -path_type full_clock_expanded -sort_by group -fall_from * -rise_to * -file {vivado_impl_1/Main_Only_Comp_Decomp_Main_Fonction_short_timing.twr} -append
report_timing_summary -file {vivado_impl_1/Main_Only_Comp_Decomp_Main_Fonction_sum_timing.twr}
report_utilization -file {vivado_impl_1/Main_Only_Comp_Decomp_Main_Fonction_utilization.rpt}
report_clock_utilization -file {vivado_impl_1/Main_Only_Comp_Decomp_Main_Fonction_clock_utilization.rpt}
report_io -file {vivado_impl_1/Main_Only_Comp_Decomp_Main_Fonction_io.rpt}
exit
