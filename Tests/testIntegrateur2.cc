#include "../general/masse.h"
#include "../general/ressort.h"
#include "../general/integrateur.h"
#include <iostream>

using namespace std;

int main(){

    double dt(0.1);

    Masse m1(1,Vecteur3D(0,0,0), Vecteur3D(0,0,0), 0.3);
    Masse m2(1,Vecteur3D(2,0,0), Vecteur3D(0,0,0),0.3);
    Masse m3(1, Vecteur3D(0,2,0), Vecteur3D(0,0,0), 0.3);

    Ressort r1(m1,m2, 9, 1.5);
    Ressort r2(m1,m3,1.9,1.75);
    Ressort r3(m2,m3,5.5,1.25);

    IntegrateurEulerCromer inte;
    cout<<"situation initiale :";
    cout<<m1<<m2<<m3;

    cout<<"======================="<<endl<<"t = 0.1s";
    m1.mise_a_jour_forces();
    m1.ajoute_force(-(m1.get_masse()*g_vect));

    m2.mise_a_jour_forces();
    m2.ajoute_force(-(m2.get_masse()*g_vect));
    
    m3.mise_a_jour_forces();
    m3.ajoute_force(-(m3.get_masse()*g_vect));

    inte.integre(m1, dt);
    inte.integre(m2, dt);
    inte.integre(m3, dt);

    cout<<m1<<m2<<m3;

    cout<<"==============================";
    m1.mise_a_jour_forces();
    m2.mise_a_jour_forces();
    m3.mise_a_jour_forces();

    
    cout<<m1<<m2<<m3;

    cout<<"======================="<<endl<<"t =0.2s";
    m1.mise_a_jour_forces();
    m1.ajoute_force(-(m1.get_masse()*g_vect));

    m2.mise_a_jour_forces();
    m2.ajoute_force(-(m2.get_masse()*g_vect));
    
    m3.mise_a_jour_forces();
    m3.ajoute_force(-(m3.get_masse()*g_vect));

    inte.integre(m1, dt);
    inte.integre(m2, dt);
    inte.integre(m3, dt);

    cout<<m1<<m2<<m3;




    return 0;
}