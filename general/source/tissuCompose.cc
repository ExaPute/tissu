#include "../include/tissuCompose.h"


TissuCompose::TissuCompose(std::vector<Tissu*> vector_tissu_, double epsilon_,double k_, double lo_)
:vector_tissu(vector_tissu_), epsilon(epsilon_), k(k_), lo(lo_)
{
    racommode();
}

//-----------------------------------------------------------------------------------------------------------------------------

void TissuCompose::racommode(){
    recreer_masse();
    recreer_ressort();
    creer_nouveau_ressort();
}

//-----------------------------------------------------------------------------------------------------------------------------

bool TissuCompose::is_in_range(Masse& m1, Masse& m2) const{
    return (m1.get_position() - m2.get_position()).norme() <= epsilon;
}

//-----------------------------------------------------------------------------------------------------------------------------

//Recrée toute les masses des deux anciens Tissus dans le tissu compose
void TissuCompose::recreer_masse(){
    //Pour la surcharge de l'opérateur +=, je dois m'assurer que le tableau soit bien clear avant d'effectuer les opérations
    vector_masse.clear();

    for(auto const t : vector_tissu){
        for(auto const& m : t->get_masse_copy()){
            vector_masse.push_back(Masse(m.get_masse(),m.get_position(),m.get_vitesse(),m.get_coeff_frottement()));
            vector_masse[vector_masse.size()-1].set_table_index(vector_masse.size()-1);
        }
    }
}

//-----------------------------------------------------------------------------------------------------------------------------

void TissuCompose::recreer_ressort(){
    //Pour pouvoir acceder 
    int nb_masse_avant = 0;
    vector_ressort.clear();
    for(int i = 0; i < vector_tissu.size(); ++i){ 
        for(auto const ressort : vector_tissu[i]->get_ressort()){
            int k = ressort->get_masse_arrive().get_table_index();
            int l = ressort->get_masse_depart().get_table_index();
            connecte(nb_masse_avant+k,nb_masse_avant+l,ressort->get_k(), ressort->get_lo());
        }

        nb_masse_avant += vector_tissu[i]->get_masse()->size();
    }
}

//-----------------------------------------------------------------------------------------------------------------------------

void TissuCompose::creer_nouveau_ressort(){
    int nb_masse_avant = 0;

    for(auto t : vector_tissu){
        for(int i = 0; i<nb_masse_avant;++i){
            for(int j = nb_masse_avant; j<nb_masse_avant + t->get_masse_copy().size();++j){
                if(is_in_range(vector_masse[i],vector_masse[j])){
                    connecte(i,j,k,lo);
                }
            }
        }

        nb_masse_avant += t->get_masse_copy().size();
    }
}

//-----------------------------------------------------------------------------------------------------------------------------

void TissuCompose::operator+=(Tissu& autre_tissu){
    vector_tissu.push_back(&autre_tissu);
    racommode();
}

