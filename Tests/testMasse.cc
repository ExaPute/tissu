#include <iostream>
#include <fstream>
#include "../general/masse.h"
#include "../general/vecteur3D.h"
#include "../general/constantes.h"
#include "../general/ressort.h"



using namespace std;



int main(){
	cout<<"------------Test masse avec les deux constructeurs puis affichage-------------------"<<endl;
	Masse m1(1,Vecteur3D(0,0,0), Vecteur3D(3,0,0), 1);
	Masse m2(3, Vecteur3D(3,0,0), Vecteur3D(0,0,0), 0);

	cout<<m1;
	cout<<m2;
	
	return 0;
	}
