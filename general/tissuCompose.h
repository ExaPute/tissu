#pragma once
#include "tissu.h"

//Le tissu composé marche mais est très mal optimisé car notre conception n'avait pas l'air de bien coller avec cette cette classe. Donc a chaque ajoute
//de tissu, le programme doit recréer cahcunes des masses présentes et chacun des ressort. Nous n'avons pas trouvé de moyen d'éviter cela.

class TissuCompose : public Tissu{
    public:
        TissuCompose(std::vector<Tissu*>, double epsilon, double k_,double lo_);

        //Permet d'ajouter un tissu a notre tissu coomposé. Cette méthode 
        void operator+=(Tissu&);//testé

    private:
    
        void racommode();
        void recreer_masse();
        void recreer_ressort();
        void creer_nouveau_ressort();

        bool is_in_range(Masse& masse1, Masse& m2) const;
        std::vector<Tissu*> vector_tissu;
        double epsilon;
        double k;
        double lo;

};