#include <iostream>
#include "../include/ressort.h"
#include "../include/masse.h"
#include "../include/vecteur3D.h"
#include "../include/constantes.h"
#include "../include/support_a_dessin.h"

using namespace std;


//definition classe ressort

	Ressort::Ressort(Masse& m1, Masse& m2)
	: masse_depart(&m1), masse_arrive(&m2), k(1), lo(0) { //Nous avons arbitrairement posé k = 1 et lo = 0 par défaut
		m1.add_ressort(this); 
		m2.add_ressort(this);
	}
	
	Ressort::Ressort(Masse& m1, Masse& m2, double k2)
	: masse_depart(&m1), masse_arrive(&m2), k(k2), lo(0) {
		m1.add_ressort(this);
		m2.add_ressort(this);
		if(k2<0){
			k = -k2;
		}else{
			k=k2;
		}
	}
	
	Ressort::Ressort(Masse& m1, Masse& m2, double k2, double l)
	: masse_depart(&m1), masse_arrive(&m2), k(k2), lo(l) {
		m1.add_ressort(this);
		m2.add_ressort(this);
		if(k2<0){
			k = -k2;
		}else{
			k=k2;
		}
		
		if(l<0){
			lo = -l;
		}else{
			lo=l;
		}

	}

//-----------------------------------------------------------------------------------------------------------------------------

	void Ressort::dessine_sur(SupportADessin& support){
		support.dessine(*this); 
	}

	Ressort::~Ressort(){
		masse_depart->enleverRessort(this);
		masse_arrive->enleverRessort(this);
	}


//-----------------------------------------------------------------------------------------------------------------------------

	//gets
	Masse Ressort::get_masse_depart() const{
		return *masse_depart; //utilisation du type retour const Masse& pour référence et moins de copies, faisable ?(pas sur en vrai c chlou)
	}
	
	Masse Ressort::get_masse_arrive() const{
		return *masse_arrive;
	}
	
	double Ressort::get_k() const{
		return k;
	}
	
	double Ressort::get_lo() const{
		return lo;
	}
	
	const Masse* Ressort::get_masse_dep_adresse() const{
		return masse_depart;
	}
	
	const Masse* Ressort::get_masse_arriv_adresse() const{
		return masse_arrive;
	}
	
//-----------------------------------------------------------------------------------------------------------------------------
	
	//sets
	void Ressort::set_masse_depart(Masse& m){
		masse_depart = &m;
	}
	
	void Ressort::set_masse_arrive(Masse& m){
		masse_arrive = &m;
	}
	
	void Ressort::set_k(double k2){
		k = k2;
	}
	
	void Ressort::set_lo(double l){
		lo = l;
	}

	void Ressort::set_masse_depart_adresse(Masse* m){
		masse_depart = m;
	}

	void Ressort::set_masse_arrive_adresse(Masse* m){
		masse_arrive = m;
	}
	
	
	//méthodes
	Vecteur3D Ressort::force_rappel(Masse* masse) const{
		Vecteur3D z((*masse_arrive).get_position()- (*masse_depart).get_position());
		Vecteur3D f = k*(z.norme()-lo)*z.unitaire();

		if(masse == masse_arrive){
			return -f;
		}
		return f;
	}

	Vecteur3D Ressort::force_rappel(Masse* masse, Vecteur3D position) const{
		
		
		if(masse == masse_arrive){				
			Vecteur3D z(position - (*masse_depart).get_position());
			Vecteur3D f = k*(z.norme()-lo)*z.unitaire();

			return -f;
		}
		Vecteur3D z(masse_arrive->get_position() - position);
		Vecteur3D f = k*(z.norme()-lo)*z.unitaire();

		return f;

	}
	//Bonne formulation physique + norme en interne oblige de créer un nouveau vect z ?
	
	
	
	
	

//surcharge opérateur externe <<


ostream& operator<<(ostream& autre, Ressort const& ressort){
	autre<<endl<<"------------affichage ressort début------------"<<endl
	<<"masse m_depart : "<<ressort.masse_depart<<*(ressort.masse_depart)<<endl
	<<"masse m_arrivee : "<<ressort.masse_arrive<<*(ressort.masse_arrive)<<endl
	<<"constante k = "<< ressort.get_k()<<endl
	<<"constante lo"<<ressort.get_lo()<<endl
	<<"addresse ressort : "<<&ressort<<endl
	<<"------------affichage ressort fin------------"<<endl;
	
	return autre;
}
