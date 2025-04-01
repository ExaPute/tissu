#include <iostream>
#include "../general/tissu.h"
#include "../general/masse.h"
#include "../general/ressort.h"
#include "../general/integrateur.h"
#include <vector>
using namespace std;


int main(){

	cout<<"a";	

	vector<Masse> vect;
	cout<<"b";

	IntegrateurEulerCromer integrateur;

	double dt(0.1);

    Masse m1(1,Vecteur3D(0,0,0), Vecteur3D(0,0,0), 0.3);
    Masse m2(1,Vecteur3D(2,0,0), Vecteur3D(0,0,0),0.3);
    Masse m3(1, Vecteur3D(0,2,0), Vecteur3D(0,0,0), 0.3);
	cout<<"c";

	vect.push_back(m1);
	vect.push_back(m2);
	vect.push_back(m3);

	cout<<"d";
	Tissu tissu(vect);

	cout<<"a";

	tissu.connecte(0,1,9,1.5);
	tissu.connecte(0,2,1.9,1.75);
	tissu.connecte(1,2,5.5,1.25);
	
	tissu.evolve(integrateur, dt);
	cout<<tissu;
	tissu.evolve(integrateur,dt);
	cout<<tissu;
	
	return 0;
}
