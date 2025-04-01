#pragma once
#include "masse.h"

class Integrateur{
    public :
        virtual void integre(Masse& m1,double dt) const = 0;
};

//#############################################################################################################################
//                                                 EulerCromer
//#############################################################################################################################

class IntegrateurEulerCromer : public Integrateur{
    public:
        void integre(Masse& m,double dt) const override;
};

//#############################################################################################################################
//                                                 RungaKuuta4
//#############################################################################################################################

class IntegrateurRungeKutta4 : public Integrateur {
    public:
        virtual void integre(Masse& m1, double dt) const override;
};

//#############################################################################################################################
//                                                 Newmark
//#############################################################################################################################

class IntegrateurNewmark : public Integrateur {
    public : 
        void integre(Masse& m, double dt) const override;
};