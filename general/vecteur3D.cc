#include <array>
#include <iostream>
#include <cmath>
#include "vecteur3D.h"

using namespace std;

//---------------------------------------------------------
//------------------CONSTRUCTEURS--------------------------
//---------------------------------------------------------
Vecteur3D::Vecteur3D(){
	vecteur[0] = 0.0;
	vecteur[1] = 0.0;
	vecteur[2] = 0.0;
}

Vecteur3D::Vecteur3D(double c){
	vecteur[0] = c;
	vecteur[1] = c;
	vecteur[2] = c;
}

Vecteur3D::Vecteur3D(long double x, long double y, long double z){
	vecteur[0] = x;
	vecteur[1] = y;
	vecteur[2] = z;
}

//---------------------------------------------------------
//--------------------METHODES-----------------------------
//---------------------------------------------------------
void Vecteur3D::afficher() const{
	cout << vecteur[0]<<" "<< vecteur[1]<<" "<<vecteur[2]<<endl;
}

bool Vecteur3D::comparer(Vecteur3D vec) const{
	double epsilon = 1e-10;
	return (abs(vec.vecteur[0] - vecteur[0]) < epsilon) and 
			(abs(vec.vecteur[1] - vecteur[1]) < epsilon) and 
			(abs(vec.vecteur[2] - vecteur[2]) < epsilon);
	
}

Vecteur3D Vecteur3D::oppose() const{
	Vecteur3D retour;
	for(int i = 0; i<=2; i++){
		retour.set_coord(i, - Vecteur3D::get_coord(i));
	}
	
	return retour;
}

double Vecteur3D::get_coord(int i) const{
	return vecteur[i];
}

double Vecteur3D::getX(){
	return vecteur[0];
}
double Vecteur3D::getY(){
	return vecteur[1];
}
double Vecteur3D::getZ(){
	return vecteur[2];
}
void Vecteur3D::set_coord(int coo, double valeur){
	
	if(coo < 0 or coo>3){
		cout<<"coo non valide, veuillez entrer une valeur entre 0 et 2 compris."<<endl;
	}else{
		Vecteur3D::vecteur[coo] = valeur;
	}
}

Vecteur3D Vecteur3D::addition(Vecteur3D autre) const{
	Vecteur3D retour;
	for(int i = 0; i<=2; i++){
		retour.set_coord(i, get_coord(i) + autre.get_coord(i));
	}
	
	return retour;
}

Vecteur3D Vecteur3D::soustraction(Vecteur3D autre) const{
	return Vecteur3D::addition(autre.oppose());
}

Vecteur3D Vecteur3D::mult(double const_mult) const{
	Vecteur3D retour;
	
	for(int i=0;i<=2;i++){
		retour.set_coord(i, Vecteur3D::get_coord(i) * const_mult);
	}
	return retour;
}

double Vecteur3D::prod_scal(Vecteur3D autre) const{
	return get_coord(0) * autre.get_coord(0) + get_coord(1) * autre.get_coord(1) + get_coord(2) * autre.get_coord(2);
}

Vecteur3D Vecteur3D::prod_vect(Vecteur3D autre) const{
	Vecteur3D retour;
	retour.set_coord(0, get_coord(1)*autre.get_coord(2) - get_coord(2)*autre.get_coord(1));
	retour.set_coord(1, get_coord(2)*autre.get_coord(0) - get_coord(0)*autre.get_coord(2));
	retour.set_coord(2, get_coord(0)*autre.get_coord(1) - get_coord(1)*autre.get_coord(0));
	
	return retour;	
}

double Vecteur3D::norme2() const{	
	return prod_scal(*this);
}

double Vecteur3D::norme() const{
	return sqrt(norme2());
}

Vecteur3D Vecteur3D::unitaire() const{
	Vecteur3D retour;
	
	
	for(int i=0;i <=2; i++){
		retour.set_coord(i, get_coord(i)/norme());
	}
	
	return retour;
}

//---------------------------------------------------------
//------------------OPERATEURS-----------------------------
//---------------------------------------------------------
Vecteur3D& Vecteur3D::operator +=(Vecteur3D const& a){
	set_coord(0, get_coord(0) + a.get_coord(0));
	set_coord(1, get_coord(1) + a.get_coord(1));
	set_coord(2, get_coord(2) + a.get_coord(2));
	
	return *this;
}

bool operator ==(Vecteur3D const& a, Vecteur3D const& b){
	return a.comparer(b);
}

Vecteur3D& Vecteur3D::operator ^=(Vecteur3D const& autre){
	Vecteur3D temp = *this;
	set_coord(0, temp.get_coord(1)*autre.get_coord(2) - temp.get_coord(2)*autre.get_coord(1));
	set_coord(1, temp.get_coord(2)*autre.get_coord(0) - temp.get_coord(0)*autre.get_coord(2));
	set_coord(2, temp.get_coord(0)*autre.get_coord(1) - temp.get_coord(1)*autre.get_coord(0));
	
	return *this;
}

Vecteur3D& Vecteur3D::operator -=(Vecteur3D const& a){
	set_coord(0, get_coord(0) - a.get_coord(0));
	set_coord(1, get_coord(1) - a.get_coord(1));
	set_coord(2, get_coord(2) - a.get_coord(2));
	
	return *this;
}

Vecteur3D& Vecteur3D::operator *=(double const_mult){
	set_coord(0, const_mult*get_coord(0));
	set_coord(1, const_mult*get_coord(1));
	set_coord(2, const_mult*get_coord(2));
	
	return *this;
}

Vecteur3D Vecteur3D::operator ~(){
	return unitaire();
}

Vecteur3D Vecteur3D::operator -(){
	return oppose();
}
Vecteur3D operator +(Vecteur3D a, Vecteur3D const& b){
	return (a+=b);
}

Vecteur3D operator -(Vecteur3D a, Vecteur3D const& b){
	return (a-=b);
}
Vecteur3D operator^(Vecteur3D a, Vecteur3D const& b){
	return (a^=b);
}

double operator *(Vecteur3D const& a, Vecteur3D const& b){
	return a.prod_scal(b);
}


Vecteur3D operator *(Vecteur3D vec, double const_mult){
	return vec*=const_mult;
}
Vecteur3D operator *(double const_mult,Vecteur3D vec){
	return vec*=const_mult;
}

ostream& operator<<(ostream& sortie, Vecteur3D const& vec){
	sortie << '(' << vec.get_coord(0) << ',' << vec.get_coord(1) << ',' << vec.get_coord(2) <<')';
	return sortie;
}
