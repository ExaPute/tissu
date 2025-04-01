#pragma once
#include <iostream>
#include "vecteur3D.h"
#include "masse.h"
#include "constantes.h"
#include "dessinable.h"


class Ressort : public Dessinable{
	
	public :
		virtual void dessine_sur(SupportADessin& support) override;
		
		~Ressort();
		Ressort(const Ressort&) = delete; //Comme pour les masse, on ne veut pas cpier des ressort car cela engendrerait des problèmes d'adresses.
		Ressort& operator=(Masse&) = delete;
		//constructeurs, pas de par défaut car on a un type masse qui n'a pas par défault, on peut tjrs ajouter
		Ressort(Masse& m1, Masse& m2);

		
		Ressort(Masse& m1, Masse& m2, double k2);
		
		Ressort(Masse& m1, Masse& m2, double k2, double l);
		//constructeur de copie par défault suffisant car meme si copie superficielle les masses ici sont des références, enfin je crois

//-----------------------------------------------------------------------------------------------------------------------------
	
		//gets
		Masse get_masse_depart() const;
		Masse get_masse_arrive() const;
		
		const Masse* get_masse_dep_adresse() const; // const
		const Masse* get_masse_arriv_adresse() const;
		
		double get_k() const;
		double get_lo() const;

		friend std::ostream& operator<<(std::ostream&, Ressort const&);
	
//-----------------------------------------------------------------------------------------------------------------------------

		//sets
		void set_masse_depart(Masse& m);
		void set_masse_arrive(Masse& m);
		void set_masse_depart_adresse(Masse* m);
		void set_masse_arrive_adresse(Masse* m);
		
		void set_k(double k2);
		void set_lo(double l);
		
//-----------------------------------------------------------------------------------------------------------------------------
	
		//méthodes
		Vecteur3D force_rappel(Masse* masse) const;
		Vecteur3D force_rappel(Masse* masse, Vecteur3D position) const;
		//Bonne formulation physique + norme en interne oblige de créer un nouveau vect z ?
	
	private :
	
		//attributs
		Masse* masse_depart;
		Masse* masse_arrive;
		double k;
		double lo;//petit o pas zéro
};


std::ostream& operator<<(std::ostream&, Ressort const&);
