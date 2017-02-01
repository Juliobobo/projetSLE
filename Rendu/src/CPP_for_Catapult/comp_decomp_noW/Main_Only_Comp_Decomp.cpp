//
// Created by florentin on 01/02/17.
//

#include "Main_Only_Comp_Decomp.h"

Main_Only_Comp_Decomp::Main_Only_Comp_Decomp() {}

int Main_Only_Comp_Decomp::Main_Fonction(ac_int<8, false> Src[WIDTH_IMAGE*HEIGHT_IMAGE],
										  ac_int<8, false> Comp[WIDTH_IMAGE*HEIGHT_IMAGE],
										  ac_int<8, false> Vga[WIDTH_IMAGE*HEIGHT_IMAGE],
										  uint4 nblevels) {
  int comp_size;
  Main_Cod_Entropique cod_entropique;
  Main_Decomp main_decomp;
  comp_size = cod_entropique.Mn_Fonction(WIDTH_IMAGE,HEIGHT_IMAGE,Src,Comp);
  main_decomp.Mn_Fonction(Comp,Vga,comp_size);
  return comp_size;


}


