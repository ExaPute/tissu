#include "../include/contrainte.h"
#include <cmath>

//#############################################################################################################################
//                                                 Contrainte
//#############################################################################################################################

bool Contrainte::is_in_range(Masse* m) const{
    return ((m->get_position()-position).norme() <= rayon);
}

//#############################################################################################################################
//                                                 Crochet
//#############################################################################################################################

void Crochet::appliquer(Tissu& tissu, double temps){
    for(auto m : tissu.get_masse_adresse()){
        if(is_in_range(m)){
            m->set_force(Vecteur3D(0));
            m->set_vitesse(Vecteur3D(0));
        }
    }

}

//#############################################################################################################################
//                                                 Impulsion
//#############################################################################################################################

Impulsion::Impulsion(Vecteur3D position_, double rayon_,Vecteur3D force_, std::vector<Tissu*> t, double ti_, double tf_):
Contrainte(position_,rayon_),force(force_), vector_tissu(t){
    if(ti_>=tf_){
        ti = tf_;
        tf = ti_;
    }else{
        ti = ti_;
        tf = tf_;
    }

    determiner_masse();
}

//-----------------------------------------------------------------------------------------------------------------------------

void Impulsion::appliquer(Tissu& Tissu, double temps){
    if(temps>=ti and temps <= tf){
        for(auto m : vector_masse){
            m->ajoute_force(-(m->get_masse())*g_vect);
            m->ajoute_force(force);
        }
    }

}

//-----------------------------------------------------------------------------------------------------------------------------

void Impulsion::determiner_masse(){
    for(auto t : vector_tissu){
        for(auto m : t->get_masse_adresse()){
            if(is_in_range(m)){
                vector_masse.push_back(m);
            }
        }
    }
}

//#############################################################################################################################
//                                                 ImpulsionSinusoidale
//#############################################################################################################################

void ImpulsionSinusoidale::appliquer(Tissu&, double temps){
    if(temps>=ti and temps <= tf){
        for(auto m : vector_masse){
            m->ajoute_force(-(m->get_masse())*g_vect);
            m->ajoute_force(force*sin(2*M_PI*frequence*(temps-ti)));
            
        }
    }
}