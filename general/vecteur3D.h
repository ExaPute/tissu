#include <array>
#include <iostream>
#pragma once

class Vecteur3D{
	public:		
		
		////// Fonction utilitaires//////
		//Afficher les cordonnée "x y z"
		void afficher() const; //OK
		
		//Retourne True si les deux vecteur sont égaux et false sinon.
		bool comparer(Vecteur3D vec) const; //OK
		
		//Set la coordonnée coo à valeur (coo : 0-> x 1->y 2->z)
		void set_coord(int coo, double valeur); //OK
		
		//retourne la valeur de la coornée coo.
		double get_coord(int i) const; //OK

		double getX();
		double getY();
		double getZ();
		
		/////Fonction opération////////
		Vecteur3D addition(Vecteur3D autre) const; //OK
		
		Vecteur3D oppose() const; //OK
		
		//Reéalise l'opération ceVecteur- autre
		Vecteur3D soustraction(Vecteur3D autre) const;// OK
		
		//retourne le vecteur const_multp*ceVecteur
		Vecteur3D mult(double const_mult) const; //OK
		
		//Retroune le produit scalaire de ceVecteur avc autre.
		double prod_scal(Vecteur3D autre) const; //OK
		
		//Retourne le vecteur ceVecteur ^ autre.
		Vecteur3D prod_vect(Vecteur3D autre) const; //OK
		
		//retourne la norme du vecteur
		double norme() const;
		
		//retourne la norme au carré du vecteur.
		double norme2() const;
		
		//Retuorne le vecteur unitaire associé à ceVecteur
		Vecteur3D unitaire() const;		
		
		/////Constructeurs/////
		//constructeur par défaut, initialise tout à 0.
		Vecteur3D();
		
		//constructeur qui pose toutes les valeur à c.
		Vecteur3D(double c);
		
		//constructeur qui pose x à x, y à y et zà z.
		Vecteur3D(long double x, long double y, long double z);
		
		//////SURCHARGE OPERATEURS///////
		Vecteur3D& operator+=(Vecteur3D const&);//testé
		Vecteur3D& operator^=(Vecteur3D const&);//testé
		Vecteur3D& operator *=(double);//testé
		//Vecteur unitaire
		Vecteur3D operator~();//testé
		Vecteur3D& operator-=(Vecteur3D const&);//testé
		Vecteur3D operator-();//testé

		
		
		
	private:
		std::array<long double,3> vecteur;
		
};


bool operator == (Vecteur3D const&, Vecteur3D const&);//testé
Vecteur3D operator +(Vecteur3D a, Vecteur3D const& b);//testé
Vecteur3D operator -(Vecteur3D a, Vecteur3D const& b);//testé
Vecteur3D operator^(Vecteur3D a, Vecteur3D const& b);//testé
double operator *(Vecteur3D const& a, Vecteur3D const& b);//testé

Vecteur3D operator *(Vecteur3D vec, double const_mult);//testé
Vecteur3D operator *(double const_mult,Vecteur3D vec);//testé

std::ostream& operator<<(std::ostream& sortie,Vecteur3D const& vec);//testé
