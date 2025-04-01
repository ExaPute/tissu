#include "tissuRectangle.h"

TissuRectangle::TissuRectangle(Vecteur3D direction1, Vecteur3D direction2, Vecteur3D position_, double masse_, double k_, double lo_, double densite_, double mu_):
a(direction1), b(direction2), position(position_), masse(masse_),k(k_),lo(lo_), densite(densite_), mu(mu_){
    if(a*b > 10e-5){
        a = a - ((a*b)/b.norme2())*b;
    }
    creer_masse();
    connect_horizontal();
    connect_vertical();
}

//-----------------------------------------------------------------------------------------------------------------------------


void TissuRectangle::creer_masse(){
    
    Vecteur3D eh = a.unitaire()*(1/densite);
    Vecteur3D el = b.unitaire()*(1/densite);

    for(int i = 0; i*densite<=a.norme(); ++i){
        for(int j = 0; j*densite<=b.norme(); ++j){
            vector_masse.push_back(Masse(masse,position+(j*el)+(i*eh),Vecteur3D(0),mu));
            int s = vector_masse.size();
            vector_masse[s-1].set_table_index(s-1);
            nb_l = j + 1;
        }
        nb_h = i + 1;
    }
}

//-----------------------------------------------------------------------------------------------------------------------------


void TissuRectangle::connect_horizontal(){
    for(int i = 0; i<nb_h ;++i){
        for(int j = 0; j<nb_l-1 ; ++j){
            connecte(i*nb_l + j, i*nb_l + j+ 1, k, lo);
        }
    }
}

//-----------------------------------------------------------------------------------------------------------------------------

void TissuRectangle::connect_vertical(){
    for(int i = 0; i<nb_l ;++i){
        for(int j = 0; j<nb_h-1 ; ++j){
            connecte(i + j*nb_l, (j+1)*nb_l + i, k, lo);
        }
    }
}