#pragma once
#include <iostream>
#include <vector>
#include "vecteur3D.h"
#include "constantes.h"
#include "dessinable.h"

class Ressort;

class Masse : public Dessinable{
	
	public :
		~Masse();
		Masse(const Masse&);		//Désactivation du constructeur de copie car cela causerait une inteférance avec les ressort pointés
    	Masse& operator=(Masse&) = delete;
		
		virtual void dessine_sur(SupportADessin& support) override;

//-----------------------------------------------------------------------------------------------------------------------------

		//Constructeurs dans l'ordre suivant : masse/position/vitesse/lamda/ressorts
		Masse(double m, const Vecteur3D& p, const Vecteur3D& v, double l);
		
		Masse(double m);

//-----------------------------------------------------------------------------------------------------------------------------

		//Gets
		Vecteur3D get_position() const;
		Vecteur3D get_vitesse() const;
		Vecteur3D get_force() const;

		double get_coeff_frottement() const;
		double get_masse() const;	
		unsigned int get_nombre_ressort() const;	
		int get_table_index() const;

//-----------------------------------------------------------------------------------------------------------------------------

		//sets
		void set_position(const Vecteur3D& p);
		void set_vitesse(const Vecteur3D& v);
		void set_masse(double m);
		void set_coeff_frottement(double l);
		void set_force(const Vecteur3D f);
		void add_ressort(Ressort* res);	
		void set_table_index(int i);

//-----------------------------------------------------------------------------------------------------------------------------

		//Méthodes
		void enleverRessort(Ressort* r);
		void ajoute_force(Vecteur3D const& df);
		Vecteur3D get_acce() const;
		Vecteur3D get_acce(Vecteur3D pos, Vecteur3D vit);

		void mise_a_jour_forces();	
	
	private :
	
		//Attributs
		double masse;
		
		Vecteur3D position;
		
		Vecteur3D vitesse;
		
		double coeff_frottement;
		
		Vecteur3D force_subie;
		
		std::vector<Ressort*> vector_ressort;

		double table_index;//Quand une masse se trouve dans un tissu, elle stock son indice pour faciliter le travail avec le tissuCompose
	
	
};




std::ostream& operator<<(std::ostream&, Masse const&);
