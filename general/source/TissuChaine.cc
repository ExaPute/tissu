#include "../include/TissuChaine.h"
#include <vector>
#include "../include/masse.h"
#include "../include/ressort.h"




TissuChaine::TissuChaine(double masse, double coefficient_frottement_fluide, double k, double lo, std::vector<Vecteur3D> posi)
{
	vector_masse.push_back(Masse(masse,posi[0],Vecteur3D(0),coefficient_frottement_fluide));
	vector_masse[0].set_table_index(0);
	for (int i(1); i<=posi.size();++i){
		vector_masse.push_back(Masse(masse,posi[i],Vecteur3D(0),coefficient_frottement_fluide));
		vector_masse[i].set_table_index(i);
		connecte(i-1,i,k,lo);
		
		
		
		
	}
	
	
}



