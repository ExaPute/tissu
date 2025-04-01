#include "tissuDisque.h"	
#include <cmath>


TissuDisque::TissuDisque(double masse, Vecteur3D posi_c, Vecteur3D rayon, double pas_ray, double coef_ff, double k, unsigned int nbr_a)
	: masse(masse),posi_c(posi_c),ray(rayon),pas_r(pas_ray),coef_ff(coef_ff),k(k),nbr_a(nbr_a)
	{
		lg = ray.norme()/pas_r;
		creer_masse();
		connect_hor();
		connect_vert();
		
	}

//-----------------------------------------------------------------------------------------------------------------------------

void TissuDisque::creer_masse(){
	vector_masse.push_back(Masse(masse,posi_c,Vecteur3D(0),coef_ff));
	Vecteur3D u(0,-ray.getZ(),ray.getY()); //Vecteur le ong du Tissu
	u = u.unitaire();
	ray = ray.unitaire();
	long double psi((2*M_PI)/nbr_a);

	for(int i(1); i<=lg;++i){
		for(int j(0);j<nbr_a;++j){
			Vecteur3D w((cos(j*psi)*u) + ((1-cos(j*psi))*(u.prod_scal(ray))*ray) + (sin(j*psi)*(ray.prod_vect(u))));
			w = w.unitaire();
			vector_masse.push_back(Masse(masse,posi_c+lg*w*i, Vecteur3D(0),coef_ff));
			int s = vector_masse.size();
			vector_masse[s-1].set_table_index(s-1);
		}
	}
}

//-----------------------------------------------------------------------------------------------------------------------------

void TissuDisque::connect_hor(){
	for(int i(0);i<lg;++i){
			int a(1+nbr_a*i);
			int b(nbr_a*(i+1));
			double lo((vector_masse[a].get_position()-vector_masse[b].get_position()).norme());

		connecte(a,b,k,lo);
		
		for(int j(0);j<nbr_a-1;++j){
			int a(1+nbr_a*i+j);
			int b(2+nbr_a*i+j);
			double lo((vector_masse[a].get_position()-vector_masse[b].get_position()).norme());
			connecte(a,b,k,lo);
		}
	}
}

//-----------------------------------------------------------------------------------------------------------------------------

void TissuDisque::connect_vert(){
	//Connection de la masse centrale avec les masse qui l'entoure
	if(lg!=0){
		for(int i(0);i<nbr_a;++i){
			connecte(0,1+i,k,pas_r);
		}
	}
	
	
	for(int i(0);i<lg-1;++i){
		for(int j(0);j<nbr_a;++j){
			connecte(1+nbr_a*i+j,1+nbr_a*(i+1)+j,k,pas_r);	
		}
	}
}

//-----------------------------------------------------------------------------------------------------------------------------


