#pragma once
#include "tissu.h"
#include "integrateur.h"
#include "contrainte.h"


class Systeme : public Dessinable{
    public:
        virtual void dessine_sur(SupportADessin&) override;

        void ajoute_tissu(Tissu& t);

        void evolve(double dt,double t);

        const std::vector<Tissu*> get_tissu() const;

        void ajoute_contrainte(Contrainte& c);

        void set_integrateur(Integrateur& inte);
        friend std::ostream& operator<<(std::ostream&, Systeme const&);
    private:
        std::vector<Contrainte*> vector_contrainte;
        std::vector<Tissu*> vector_tissu;
        Integrateur*  integrateur;
};

std::ostream& operator<<(std::ostream&, Systeme const& s);