#pragma once
#include "tissu.h"

class TissuRectangle : public Tissu{
    public:
        TissuRectangle(Vecteur3D direction1, Vecteur3D direction2, Vecteur3D position_, double masse_, double k_, double lo_, double densite_, double mu);
    private:
        void connect_horizontal();
        void connect_vertical();
        void creer_masse();
        Vecteur3D a;
        Vecteur3D b;
        Vecteur3D position;
        double masse;
        double k;
        double mu;
        double lo;
        double densite;
        double nb_h;
        double nb_l;
};