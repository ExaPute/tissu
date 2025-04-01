#include "TissuChaine.h"




TissuChaine::TissuChaine(double masse, double coefficient_frottement_fluide, double k, double lo, vector position<Vecteur3D>)
: {
	vector_masse.push_back(masse,position[0],Vecteur3D(0),coeff_frottement_fluide);
	vector_masse[0].set_table_index(0);
	for (int i(1), i<=position.size(),++i){
		vector_masse.push_back(masse,position[i],Vecteur3D(0),coeff_frottement_fluide);
		vector_masse[i].set_table_index(i);
		connecte(i-1,i,k,lo);
		
		
		
		
	}
	
	
	}



