create_clock {clk} -name clk -domain clk -period 41.6667 -waveform {0 20.83}
set_clock_uncertainty [get_clocks clk]
set_multicycle_path 6 -through [ {div_mgc_div/z(66) div_mgc_div/z(65) div_mgc_div/z(64) div_mgc_div/z(63) div_mgc_div/z(62) div_mgc_div/z(61) div_mgc_div/z(60) div_mgc_div/z(59) div_mgc_div/z(58) div_mgc_div/z(57) div_mgc_div/z(56) div_mgc_div/z(55) div_mgc_div/z(54) div_mgc_div/z(53) div_mgc_div/z(52) div_mgc_div/z(51) div_mgc_div/z(50) div_mgc_div/z(49) div_mgc_div/z(48) div_mgc_div/z(47) div_mgc_div/z(46) div_mgc_div/z(45) div_mgc_div/z(44) div_mgc_div/z(43) div_mgc_div/z(42) div_mgc_div/z(41) div_mgc_div/z(40) div_mgc_div/z(39) div_mgc_div/z(38) div_mgc_div/z(37) div_mgc_div/z(36) div_mgc_div/z(35) div_mgc_div/z(34) div_mgc_div/z(33) div_mgc_div/z(32) div_mgc_div/z(31) div_mgc_div/z(30) div_mgc_div/z(29) div_mgc_div/z(28) div_mgc_div/z(27) div_mgc_div/z(26) div_mgc_div/z(25) div_mgc_div/z(24) div_mgc_div/z(23) div_mgc_div/z(22) div_mgc_div/z(21) div_mgc_div/z(20) div_mgc_div/z(19) div_mgc_div/z(18) div_mgc_div/z(17) div_mgc_div/z(16) div_mgc_div/z(15) div_mgc_div/z(14) div_mgc_div/z(13) div_mgc_div/z(12) div_mgc_div/z(11) div_mgc_div/z(10) div_mgc_div/z(9) div_mgc_div/z(8) div_mgc_div/z(7) div_mgc_div/z(6) div_mgc_div/z(5) div_mgc_div/z(4)}]
set_multicycle_path 5 -through [ {div_mgc_div_1/z(63) div_mgc_div_1/z(62) div_mgc_div_1/z(61) div_mgc_div_1/z(60) div_mgc_div_1/z(59) div_mgc_div_1/z(58) div_mgc_div_1/z(57) div_mgc_div_1/z(56) div_mgc_div_1/z(55) div_mgc_div_1/z(54) div_mgc_div_1/z(53) div_mgc_div_1/z(52) div_mgc_div_1/z(51) div_mgc_div_1/z(50) div_mgc_div_1/z(49) div_mgc_div_1/z(48) div_mgc_div_1/z(47) div_mgc_div_1/z(46) div_mgc_div_1/z(45) div_mgc_div_1/z(44) div_mgc_div_1/z(43) div_mgc_div_1/z(42) div_mgc_div_1/z(41) div_mgc_div_1/z(40) div_mgc_div_1/z(39) div_mgc_div_1/z(38) div_mgc_div_1/z(37) div_mgc_div_1/z(36) div_mgc_div_1/z(35) div_mgc_div_1/z(34) div_mgc_div_1/z(33) div_mgc_div_1/z(32) div_mgc_div_1/z(31) div_mgc_div_1/z(30) div_mgc_div_1/z(29) div_mgc_div_1/z(28) div_mgc_div_1/z(27) div_mgc_div_1/z(26) div_mgc_div_1/z(25) div_mgc_div_1/z(24) div_mgc_div_1/z(23) div_mgc_div_1/z(22) div_mgc_div_1/z(21) div_mgc_div_1/z(20) div_mgc_div_1/z(19) div_mgc_div_1/z(18) div_mgc_div_1/z(17) div_mgc_div_1/z(16) div_mgc_div_1/z(15) div_mgc_div_1/z(14) div_mgc_div_1/z(13) div_mgc_div_1/z(12) div_mgc_div_1/z(11) div_mgc_div_1/z(10) div_mgc_div_1/z(9) div_mgc_div_1/z(8) div_mgc_div_1/z(7) div_mgc_div_1/z(6) div_mgc_div_1/z(5) div_mgc_div_1/z(4) div_mgc_div_1/z(3) div_mgc_div_1/z(2) div_mgc_div_1/z(1)}]
set_attribute -name HIERARCHY -value preserve -type default [get_cells div_mgc_div]
set_attribute -name HIERARCHY -value preserve -type default [get_cells div_mgc_div_1]