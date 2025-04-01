#pragma once
#include "tissu.h"
class Contrainte{
    public:
        Contrainte(Vecteur3D position_, double rayon_) : position(position_), rayon(rayon_){}
        virtual void appliquer(Tissu& tissu, double temps) = 0;
    protected:
        Vecteur3D position;
        double rayon;
        bool is_in_range(Masse* m) const;
};

//#############################################################################################################################
//                                                 Crochet
//#############################################################################################################################

class Crochet : public Contrainte{
    public:
        Crochet(Vecteur3D position_, double rayon_) : Contrainte(position_, rayon_){}
        void appliquer(Tissu& tissu, double temps);
    
};

//#############################################################################################################################
//                                                 Impulsion
//#############################################################################################################################

class Impulsion : public Contrainte{
    public:
        Impulsion(Vecteur3D position_, double rayon_,Vecteur3D force_, std::vector<Tissu*> t, double ti_, double tf_);
        virtual void appliquer(Tissu& tissu, double temps);

    protected:
        std::vector<Tissu*> vector_tissu;
        void determiner_masse(); //Mémorise les masse applicable
        std::vector<Masse*> vector_masse;
        double ti;
        double tf;
        Vecteur3D force;
    
};

//#############################################################################################################################
//                                                 ImpulsionSinusoidale
//#############################################################################################################################

class ImpulsionSinusoidale : public Impulsion{
    public : 
        ImpulsionSinusoidale(Vecteur3D position_, double rayon_,Vecteur3D force_, std::vector<Tissu*> t, double ti_, double tf_,double frequence_) 
        : Impulsion(position_, rayon_,force_,t, ti_, tf_), frequence(frequence_){}

        void appliquer(Tissu& tissu, double temps);
    private:
        double frequence;
};