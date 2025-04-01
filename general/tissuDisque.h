#pragma once
#include "tissu.h"



class TissuDisque : public Tissu{
	public :
		TissuDisque(double masse, Vecteur3D posi_c, Vecteur3D rayon, double pas_ray, double coef_ff, double k, unsigned int nbr_a);
		
	private :

		void creer_masse();
		void connect_hor();
		void connect_vert();
		double masse;
		Vecteur3D posi_c;
		Vecteur3D ray;
		double pas_r;
		double coef_ff;
		double k;
		unsigned int nbr_a;
		int lg;
	
};
