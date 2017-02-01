//
// Created by florentin on 25/01/17.
//

#include "Main_Comp_Decomp_tot.h"

Main_Comp_Decomp_tot::Main_Comp_Decomp_tot(){}

int Main_Comp_Decomp_tot::Main_Fonction(ac_int<8, false> Src[WIDTH_IMAGE*HEIGHT_IMAGE],
		ac_int<8, false> Comp[WIDTH_IMAGE*HEIGHT_IMAGE],
		ac_int<8, false> Decomp[WIDTH_IMAGE*HEIGHT_IMAGE],
		ac_int<8, false> Vga[WIDTH_IMAGE*HEIGHT_IMAGE],
		uint4 nblevels, uint4 change_mode) {
	
	Main_Trans_Ond trans_ond;
  	int comp_size;
	Main_Cod_Entropique cod_entropique;
  	Main_Decomp main_decomp;
  	Main_Inv_Wave inv_wave;
	trans_ond.Mn_Trans_Ond(Src,Vga,nblevels);
	comp_size = cod_entropique.Mn_Fonction(WIDTH_IMAGE,HEIGHT_IMAGE,Vga,Comp);
  	if(change_mode == 1){
	  main_decomp.Mn_Fonction(Comp,Vga,comp_size);
	  inv_wave.Mn_Inv_Wave_Fct(Vga,Comp,nblevels,0);
	}

}

