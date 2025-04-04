#include "../include/systeme.h"
#include "../include/dessinable.h"
#include "../include/support_a_dessin.h"

void Systeme::dessine_sur(SupportADessin& support){
    support.dessine(*this);
}

//-----------------------------------------------------------------------------------------------------------------------------

std::ostream& operator<<(std::ostream& out, Systeme const& s){
    for(auto& t : s.vector_tissu){
        out<<*t;
    }

    return out;
    
}

//-----------------------------------------------------------------------------------------------------------------------------

void Systeme::ajoute_tissu(Tissu& t){
    vector_tissu.push_back((&t));
}

//-----------------------------------------------------------------------------------------------------------------------------

void Systeme::set_integrateur(Integrateur& inte){
    integrateur = &inte;
}

//-----------------------------------------------------------------------------------------------------------------------------

void Systeme::evolve(double dt,double temps){
    for(auto& t : vector_tissu){
        t->mise_a_jour_force();
        for(auto& c : vector_contrainte){
            c->appliquer(*t,temps);
        }
        t->evolve(*integrateur,dt);
    }
}

//-----------------------------------------------------------------------------------------------------------------------------

const std::vector<Tissu*> Systeme::get_tissu() const{
    return vector_tissu;
}

//-----------------------------------------------------------------------------------------------------------------------------

void Systeme::ajoute_contrainte(Contrainte& c){
    vector_contrainte.push_back(&c);
}
