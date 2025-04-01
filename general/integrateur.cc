#include "vecteur3D.h"
#include "masse.h"
#include "integrateur.h"



//#############################################################################################################################
//                                                 EulerCromer
//#############################################################################################################################

void IntegrateurEulerCromer::integre(Masse& m,double dt) const {
    Vecteur3D v(m.get_vitesse());
    Vecteur3D p(m.get_position());
    Vecteur3D a(m.get_acce());
    v += (dt*a);
    m.set_vitesse(v);
    m.set_position(p + dt*v);
};

//#############################################################################################################################
//                                                 RungaKuuta4
//#############################################################################################################################

void IntegrateurRungeKutta4::integre(Masse& m,double dt) const{
    // Les primes des non de coeff sont rem placeés apre les "_" ici
    Vecteur3D vi(m.get_vitesse());
    Vecteur3D pi(m.get_position());
    Vecteur3D ai(m.get_acce());

    Vecteur3D k1 = vi;
    Vecteur3D k1_ = ai;

    Vecteur3D k2 = vi + ((dt/2.0)*k1_);
    Vecteur3D k2_ = m.get_acce(pi + ((dt/2.0)*k1),vi + ((dt/2.0)* k1_));

    Vecteur3D k3 = vi + ((dt/2.0)*k2_);
    Vecteur3D k3_ = m.get_acce(pi + ((dt/2.0)*k2),vi + ((dt/2.0)* k2_));

    Vecteur3D k4 = vi + (dt * k3_);
    Vecteur3D k4_ = m.get_acce(pi + (dt*k3),vi + (dt* k3_));

    m.set_position(pi + ((dt/6.0)* ( k1 + (2.0*k2) + (2.0*k3) + k4)));
    m.set_vitesse((vi + ((dt/6.0)* ( k1_ + (2.0*k2_) + (2.0*k3_) + k4_))));
}

//#############################################################################################################################
//                                                 Newmark
//#############################################################################################################################

void IntegrateurNewmark::integre(Masse& m, double dt) const{

    int nb_max = 10000;

    double epsilon = 10e-2;
    Vecteur3D xn = m.get_position();
    Vecteur3D xnp = m.get_vitesse();

    Vecteur3D xn_1 = m.get_position();
    Vecteur3D xnp_1 = m.get_vitesse();

    Vecteur3D s = m.get_acce();

    Vecteur3D q;
    Vecteur3D r;
    int i = 0;

    do
    {   
        q = xn;

        r = m.get_acce(xn,xnp);
        xnp =  xnp_1 + ((dt/2)*(r + s));
        xn = xn_1 + (dt*xnp_1) + ((dt*dt/3)*(0.5*r+s));

        ++i;

        if(i == nb_max){
            std::cout<<"Nombre d'itérations max atteint"<<std::endl;
        }
        
    }while ((xn-q).norme()>=epsilon and i< nb_max + 1);

    m.set_position(xn);
    m.set_vitesse(xnp);

}