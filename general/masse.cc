#include <iostream>
#include <vector>
#include "masse.h"
#include "ressort.h"
#include "vecteur3D.h"
#include "constantes.h"
#include "support_a_dessin.h"
#include <algorithm>
#include <cmath>

using namespace std;


//définition de la classe Masse
//doit-on def comme g un double = 9.81... ou/et g_vect = Vecteur(0,0,+-9.81...) -->dessous
//je pense que les deux seraient bien car si on a un repère fixe déjà ici j'utilise g_vect, à voir si le ref est fixe et perp a la planete
//j'ai mis tous les get/set, pas forcément besoin de tout le monde.

//-----------------------------------------------------------------------------------------------------------------------------

	Masse::Masse(double m, const Vecteur3D& p, const Vecteur3D& v, double l)
	: masse(m), position(p), vitesse(v), coeff_frottement(l), force_subie(m*g_vect) {
		if(m<0){
			masse = -m;
		}else{
			masse = m;
		}

	}

//-----------------------------------------------------------------------------------------------------------------------------

	Masse::Masse(double m)
	: masse(m), position(Vecteur3D()), vitesse(Vecteur3D()), coeff_frottement(0), force_subie(m*g_vect) {
		if(m<0){
			masse = -m;
		}else{
			masse = m;
		}

	}

//-----------------------------------------------------------------------------------------------------------------------------
	//Destructeur obligatoire car les ressort pourraient se retrouver à pointer sur un objet qui n'existe plus.
	Masse::~Masse(){
		for(auto r : vector_ressort){
			if(r->get_masse_arriv_adresse() == this){
				r->set_masse_arrive_adresse(nullptr);
			}else{
				r->set_masse_depart_adresse(nullptr);
			}
		}
	}

Masse::Masse(const Masse& autre){
	masse = autre.masse;
	coeff_frottement = autre.coeff_frottement;
	position = autre.position;
	vitesse = autre.vitesse;
	force_subie = autre.force_subie;
	table_index = autre.table_index;
}
//-----------------------------------------------------------------------------------------------------------------------------

	void Masse::dessine_sur(SupportADessin& support){
		support.dessine(*this); 
	}

//-----------------------------------------------------------------------------------------------------------------------------

	//Nous avons besoin de cette méthode pour gérer la détruction des ressort.
	void Masse::enleverRessort(Ressort* r){
		vector_ressort.erase(remove(vector_ressort.begin(),vector_ressort.end(),r));
	}

//-----------------------------------------------------------------------------------------------------------------------------

// Get
	Vecteur3D Masse::get_position() const{
		return position;
	}
	
	Vecteur3D Masse::get_vitesse() const{
		return vitesse;
	}

	int Masse::get_table_index() const{
		return table_index;
	}
	
	Vecteur3D Masse::get_force() const{
		return force_subie;
	}
	
	double Masse::get_coeff_frottement() const{
		return coeff_frottement;
	}
	
	double Masse::get_masse() const{
		return masse;
	}
	
	unsigned int Masse::get_nombre_ressort() const{
		return vector_ressort.size();
	}
	
//-----------------------------------------------------------------------------------------------------------------------------
	
	
	//sets
	void Masse::set_position(const Vecteur3D& p){
		position = p;
	}
	
	void Masse::set_table_index(int i){
		table_index = i;
	}
	
	void Masse::set_vitesse(const Vecteur3D& v){
		vitesse = v;
	}
	
	void Masse::set_masse(double m){
		masse = m;
	}
	
	void Masse::set_coeff_frottement(double l){
		coeff_frottement = l;
	}
	
	void Masse::set_force(const Vecteur3D f){
		force_subie = f;
	}
	
	void Masse::add_ressort(Ressort* res){
		vector_ressort.push_back(res);
	}
	
//-----------------------------------------------------------------------------------------------------------------------------
	
	//Méthodes
	void Masse::ajoute_force(Vecteur3D const& df){
		force_subie += df; //ICI BESOIN += CAC
	}
	
	Vecteur3D Masse::get_acce() const{
		return (force_subie*(1/masse)); //( <=> force_subie/massse mais la division n'est pas définie por les vecteur3D)
	}
	
	//A chaque appel, nous remettons les force a zéro avant donc attention si utilisation de ajoute_force() dele faire après l'appel de mise
	//à jour force.
	void Masse::mise_a_jour_forces(){
		force_subie = masse*g_vect;
		force_subie -= coeff_frottement*vitesse;
		for (auto res : vector_ressort){
			force_subie += res->force_rappel(this);
		}

	}



//Surcharge opérateur externe prototype-->fct


ostream& operator<<(ostream& sortie,Masse const& masse){
	sortie<<endl<<"------------affichage masse----------------"<<endl
	<<"masse =  "<<masse.get_masse()<<endl
	<<"position = "<<masse.get_position()<<endl
	<<"vitesse = "<<masse.get_vitesse()<<endl
	<<"forces subies = "<<masse.get_force()<<endl
	<<"coefficient de frottement fluide = "<<masse.get_coeff_frottement()<<endl
	<<"nombre ressorts = "<<masse.get_nombre_ressort()<<endl
	<<"adresse : "<<&masse<<endl
	<<"--------------------------------"<<endl;
	return sortie;
}

Vecteur3D Masse::get_acce(Vecteur3D pos, Vecteur3D vit){
	
	Vecteur3D force = force_subie;
	
	for(auto r : vector_ressort){
		force -= r->force_rappel(this);
		force += r->force_rappel(this, pos);
	}

	force += (vitesse*coeff_frottement);
	force -= (vitesse*coeff_frottement);

	return (1/masse)*force;


}