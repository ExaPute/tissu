#include <iostream>
#include "../general/vecteur3D.h"


using namespace std;

int main(){
	Vecteur3D vect4(10,2,4);
	Vecteur3D vect5(34,20,3);
	Vecteur3D vectnorme(3,4,0);
	cout<<"---------------------------------------------------------------"<<endl;
	cout<<"------------------Test des opérateur--------------------------"<<endl;
	cout<<"---------------------------------------------------------------"<<endl;
	
	if((-vect4) == Vecteur3D(-10,-2,-4)){
		cout<<"Opposé : OK"<<endl;
	}else{
		cout<< "Opposé : PAS OK"<<endl;
	}

	if(~vectnorme == Vecteur3D(3.0/5, 4.0/5,0)){
		cout<<"Unitaire: OK"<<endl;
	}else{
		cout<<"Unitaire: PAS OK"<<endl;
	}

	if(Vecteur3D(10e-12) == Vecteur3D(0)){
		cout << "==   : OK"<<endl;
	}else{
		cout<<"==   : PAS OK"<<endl;
	}

	if((vect4 - vect5) == Vecteur3D(-24,-18,1)){
		cout<< "-    : OK"<<endl;
	}else{
		cout<< "-    : PAS OK"<<endl;
	}
	if((vect4 + vect5) == Vecteur3D(44,22,7) and vect4+vect5 == vect5+vect4){
		cout<< "+    : OK(DEUX SENS)"<<endl;
	}else{
		cout<< "+    : PAS OK"<<endl;
	}

	if(vect4*2 == 2*vect4 and vect4*2 == Vecteur3D(20,4,8)){
		cout<<"*    : OK (DANS LES DEUX SENS)"<<endl;
	}else{
		cout<<"*   : PAS OK"<<endl;
	}

	if(vect4*vect5 == vect5*vect4 and vect4*vect5 == 392.0){
		cout<<"*    : OK(DEUX SENS)"<<endl;
	}else{
		cout<<"*    : PAS OK"<<endl;
	}

	if((vect4^vect5) == -(vect5^vect4) and (vect4^vect5)==Vecteur3D(-74,106,132)){
		cout<<"^    : OK(DEUX SENS)"<<endl;
	}else{
		cout<<"^    : PAS OK"<<endl;
	}



	cout<<endl<<endl<<"---------------------------------------------------------------"<<endl;
	cout<<"------Test des égalité entre operation= et operation---------"<<endl;
	cout<<"---------------------------------------------------------------"<<endl;

	Vecteur3D a(vect4);
	a+=vect5;
	if((vect4+vect5) == (a)){
		cout<<"+= et +  :OK"<<endl;
	}else{
		cout<<"+= et +  :PAS OK"<<endl;
	}
	
	a=vect4;
	a^= vect5;
	if((vect4^vect5 )== (a)){
		cout<<"^= et ^  :OK"<<endl;
	}else{
		cout<<"+= et +  :PAS OK"<<endl;
	}

	a=vect4;
	a-=vect5;
	if((vect4-vect5 ) == (a)){
		cout<<"-= et -  :OK"<<endl;
	}else{
		cout<<"-= et -  :PAS OK"<<endl;
	}

	a=vect4;
	double mult = 14;
	a*=mult;
	if((vect4*mult) == (a) and a==(mult*vect4)){
		cout<<"*= et *  :OK"<<endl;
	}else{
		cout<<"*= et *  :PAS OK"<<endl;
	}

	return 0;
}
