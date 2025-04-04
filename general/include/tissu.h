#pragma once
#include <vector>
#include <iostream>
#include "ressort.h"
#include "masse.h"
#include "dessinable.h"
#include "integrateur.h"


class Tissu : public Dessinable{
	
	public :
		~Tissu();
		Tissu (const std::vector<Masse>& m_vect);
		Tissu () = default;
		virtual void dessine_sur(SupportADessin& support) override;


		friend std::ostream& operator<<(std::ostream&, Tissu const&);
		//Constructeurs comme proposés
		
		const std::vector<Masse>* get_masse() const;
		std::vector<Masse> get_masse_copy() const;
		const std::vector<Ressort*> get_ressort() const;
		std::vector<Masse*> get_masse_adresse();
	
		void connecte(int i, int j, double k, double lo);
	
		//void mise_a_jour_force();
		// void evolve(); pas fait a voir jeudi 07.04
		
		void check() const;

		void evolve(Integrateur& inte,double dt);

		void mise_a_jour_force();	

		
/* Fonctions a peut-etre ajouter par la suite :
 * Deconecte -> supprime un ressort, attention pointeurs impliquent destructeurs
 * Trou -> supprime une masse, attention si on supprime les deux masses d'un ressort doit-on supprimer le ressort ? Importance de la fonction check apres avoir fait un trou 
	
*/
	protected : //Pour que les sous-classes puissent y avoir accès
		std::vector<Masse> vector_masse;

		std::vector<Ressort*> vector_ressort;
		
	
};

std::ostream& operator<<(std::ostream&, Tissu const&);