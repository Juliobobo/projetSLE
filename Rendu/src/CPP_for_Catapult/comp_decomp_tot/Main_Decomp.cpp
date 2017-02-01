//
// Created by florentin on 26/01/17.
//

#include "Main_Decomp.h"
Main_Decomp::Main_Decomp(){}

void Main_Decomp::Mn_Fonction(ac_int<8, false>  *Src,
									  ac_int<8, false>
									  *Dst,
int comp_size)
{

  ModelA cmodel;
  cmodel.reset();
  Decompressor dec(cmodel, Src, comp_size,Dst);
  dec.decompress();
	for (int i = 0 ; i< WIDTH_IMAGE * HEIGHT_IMAGE; i++){
		Src[i] = 0 ;
  	}
}
