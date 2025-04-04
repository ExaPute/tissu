#include <iostream>
#include "../include/tissu.h"
#include "../include/ressort.h"
#include "../include/masse.h"
#include "../include/support_a_dessin.h"
using namespace std;



Tissu::Tissu(const vector<Masse>& m_vect)
: vector_masse(m_vect) {
	//On pose les index de chaque masse dans leur propriété.
	for(int i = 0; i<m_vect.size(); ++i){
		vector_masse[i].set_table_index(i);
	}
}

//-----------------------------------------------------------------------------------------------------------------------------

Tissu::~Tissu(){
	for(auto& r : vector_ressort){
		delete r;
	}
}

//-----------------------------------------------------------------------------------------------------------------------------

const std::vector<Ressort*> Tissu::get_ressort() const{
	return vector_ressort;
}

//-----------------------------------------------------------------------------------------------------------------------------

const std::vector<Masse>* Tissu::get_masse() const{
	return &vector_masse;
}

//-----------------------------------------------------------------------------------------------------------------------------

void Tissu::dessine_sur(SupportADessin& support){
		support.dessine(*this); 
}

// méthodes 

//-----------------------------------------------------------------------------------------------------------------------------

std::vector<Masse*> Tissu::get_masse_adresse(){
	std::vector<Masse*> vec;
	for(auto& m : vector_masse){
		vec.push_back(&m);
	}

	return vec;
}



//-----------------------------------------------------------------------------------------------------------------------------

void Tissu::connecte(int i, int j, double k, double lo){
	bool c1(i>=0 and i<int(vector_masse.size()));
	bool c2(j>=0 and j<int(vector_masse.size()));
	if (i != j and c1 and c2){
	vector_ressort.push_back(new Ressort(vector_masse[i], vector_masse[j],k,lo));}
	else cout<<"Problème dans les donnée d'entrées on ne fait rien !"<<endl;
}

//-----------------------------------------------------------------------------------------------------------------------------

void Tissu::mise_a_jour_force(){
	for (auto &m : vector_masse){
		m.mise_a_jour_forces();
	}
}

//-----------------------------------------------------------------------------------------------------------------------------

/*void Tissu::check() const{
	cout<<"----------------Debut check-------------------"<<endl;
	for (auto const &ptr : vector_ressort){
		if (ptr->get_masse_dep_adresse() == nullptr and ptr->get_masse_arriv_adresse() == nullptr) cout<<"Ressort lié à aucune masse, ressort d'adresse : "<<ptr<<endl; 
		else{ 
			if (ptr->get_masse_dep_adresse() == nullptr or ptr->get_masse_arriv_adresse() == nullptr) cout<<"Ressort lié à une seule masse, ressort d'adresse : "<<ptr<<endl;
			if (ptr->get_masse_dep_adresse() == ptr->get_masse_arriv_adresse()) cout<<"Ressort lié à la même masse, ressort d'addresse : "<<ptr<<endl;
			
			}
		}
		cout<<"-------------------Fin check------------------------"<<endl;
	}
*/
//-----------------------------------------------------------------------------------------------------------------------------

void Tissu::evolve(Integrateur& inte,double dt){
	for(auto& masse : vector_masse){
		inte.integre(masse,dt);
	}
}

//-----------------------------------------------------------------------------------------------------------------------------

std::ostream& operator<<(std::ostream& sortie, Tissu const& tissu){
	for(auto const& masse: tissu.vector_masse){
		sortie<<masse.get_force()<<endl;
	}

	return sortie;
}

//-----------------------------------------------------------------------------------------------------------------------------
 std::vector<Masse> Tissu::get_masse_copy() const{
	return vector_masse;
 }