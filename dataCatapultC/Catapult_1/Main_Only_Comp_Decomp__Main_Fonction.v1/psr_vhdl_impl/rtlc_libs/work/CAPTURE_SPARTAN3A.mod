080189071292.3-3-00-000501041b-1485954413.326547                  %              
�                           �           Q                              q                                @g          � | �	         �           ` @          �               �      #�                       "�            J          !I      "I               V             J                                         "�                                                                                              !�                                                                                                                                                                         <          y                             A         g             | |         �                  i                                                                                                                                     �                              i                V          �   �                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     $          �                         g          � | |         o                         �                         g          1 x x          �                ^                                                                                                                                                                                     V          !   �                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     o          a              �                         g          1 | |          o          �              �                         g          1 � �          o                        �                         g          1 � �          o          i              B                         g          1 � �          o          �              U                         g          1 � �          o                        h                         g          1 � �          o          q              �                         g          1 � �          o          �              �                         g          1 � �          o          !                                       g          1 � �          o          y              Q                         g          1 � �          o          �              z                         g          1 � �          o          )              �                         g          1 � �          o          �              �                         g          1 � �          o          �              �                         g          1 � �          o          1              �                         g          1 � �          o          �                                       g          1 � �          o          �                                       g          1 � �          o          9                                       g          1 � �          o          �              8                         g          1 � �          o          �              <                         g          1 � �          o          A              o                         g          1 � �          o          �              s                         g          1 � �          o          �              w                         g          1 � �          o          I              {                         g          1 � �          o          �              �                         g          1 � �          o          �              �                         g          1 � �          o          Q              !                         g          1 � �          o          �              Z                         g          1 � �          o                        ^                         g          1 � �          o          Y              b                         g          1 � �          o          �              y                         g          1 � �          o          	              �                         g          1 � �          o          a              �                         g          1 � �          o          �              �                         g          1              o                        �                         g          1            o          i              �                         g          1            o          �              �                         g          1            o                        �                         g          1            o          q              )                         g          1            o          �              6                         g          1            o          !              A                         g          1            o          y              E                         g          1              o          �              I                         g          1 $ $          o          )              M                         g          1 ( (          o          �              d                         g          1 0 0          o          �              �                         g          1 4 4          o          1              ,                         g          1 8 8          o          �              U                         g          1 < <          o          �              m                         g          1 @ @          o          9              �                         g          1 D D          o          �              �                         g          1 H H          o          �              �                         g          1 L L          o          A              	                         g          1 P P          o          �              	%                         g          1 T T          o          �              	u                         g          1 X X          o          I              	�                         g          1 \ \          o          �              
                         g          1 ` `          o          �              
P                         g          1 d d          o          Q              
a                         g          1 h h          o          �              
e                         g          1 l l          o                         
s                         g          1 p p          o           Y              
�                         g          1 t t          U                                            0                            0                            +          !)                             �      $�         g          � �* |         �          !�             
�               �            "I                 g          � | |         U          !I                                 +          ")                            !�      $�         g          � �5 |"         �          "�             
�              !�                               g          � |" |"         U          "I                                           #)                            "�      
�         g          � � �         �          #�             
�      $                     "�                                                                        @g          � � �        J          #I      #I                +          $Y               �            $      #I         g          � � �         U          $�                                 �      &8      !              �      *      "              �      .H      $�    CAPTURE_SPARTAN3A work /softslin/precision2014a_64b/Mgc_home/pkgs/rtlc_psr/rtlc/lib/xcv7_retarget_lib.v /softslin/precision2014a_64b/Mgc_home/pkgs/rtlc_psr/rtlc/lib/xcv7_retarget_lib.v /////////////////////////////////////////////////////////////////////////////////
 /softslin/precision2014a_64b/Mgc_home/pkgs/rtlc_psr/rtlc/lib/xcv7_retarget_lib.v /softslin/precision2014a_64b/Mgc_home/pkgs/rtlc_psr/rtlc/lib/xcv7_retarget_lib.v //// Copyright (c) 2011 Xilinx, Inc.
 //// All Right Reserved.
 /////////////////////////////////////////////////////////////////////////////////
 ////   ____  ____
 ////  /   /\/   /
 //// /___/  \  /    Vendor : Xilinx
 //// \   \   \/     Version : 10.1
 ////  \   \         Description : Xilinx Functional Simulation Library Component
 ////  /   /                  I/O Clock Buffer/Divider for the Spartan Series
 //// /___/   /\     Filename : BUFIO2.v
 //// \   \  /  \    Timestamp : Tue Aug 16 13:49:22 PDT 2011
 ////  \___\/\___\
 ////
 //// Revision:
 ////    08/16/11 - Initial version.
 //// End Revision
 //
 //`timescale  1 ps / 1 ps
 //
 //module BUFIO2 (DIVCLK, IOCLK, SERDESSTROBE, I);
 //
 //
 //
 //  parameter DIVIDE_BYPASS = "TRUE";    // TRUE, FALSE
 //  parameter integer DIVIDE = 1;        // {1..8}
 //  parameter I_INVERT = "FALSE";        // TRUE, FALSE
 //  parameter USE_DOUBLER = "FALSE";     // TRUE, FALSE
 //
 //
 //    output DIVCLK; 
 //    output IOCLK; 
 //    output SERDESSTROBE; 
 //
 //    input I; 
 //
 //
 //    initial begin
 //	$display ("ERROR : The following component BUFIO2 at instance %m is not supported for retargeting in this architecture.  Please modify your source code to use supported primitives.  The complete list of supported primitives for this architectures is provided in the 7 Series HDL Libraries Guide available on www.xilinx.com.");
 //	$finish;
 //    end
 //
 //
 //
 //endmodule // BUFIO2
 // $Header: /home/rtlc/RTLCROOT/rtlc/lib/Attic/xcv7_retarget_lib.v,v 1.1.4.12.24.1 2014/01/15 12:21:18 bsrivast Exp $
 ///////////////////////////////////////////////////////////////////////////////
 // Copyright (c) 1995/2005 Xilinx, Inc.
 // All Right Reserved.
 ///////////////////////////////////////////////////////////////////////////////
 //   ____  ____
 //  /   /\/   /
 // /___/  \  /    Vendor : Xilinx
 // \   \   \/     Version : 12.1
 //  \   \         Description : Xilinx Functional Simulation Library Component
 //  /   /                 Register State Capture for Bitstream Readback for SPARTAN3A (Discontinue in 13.1)
 // /___/   /\     Filename : CAPTURE_SPARTAN3A.v
 // \   \  /  \    Timestamp : Tue Jul 27 03:47:29 PST 2010
 //  \___\/\___\
 //
 // Revision:
 //    07/27/10 - Initial version.
 // End Revision
 CAP CLK "TRUE" ONESHOT 