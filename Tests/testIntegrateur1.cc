#include "../general/integrateur.h"
#include "../general/masse.h"
#include <iostream>

using namespace std;


int main(){
    Masse m(0.127, Vecteur3D(0,0,1), Vecteur3D(1,0,2),0);
    double dt(0.01);

    IntegrateurEulerCromer integrateur;
    cout<<"Postition de départ :"<<endl;
    cout<<m;

    cout<<"t = 0.01 s";
    integrateur.integre(m,dt);
    cout<<m;

    cout<<"t = 0.02 s";
    integrateur.integre(m,dt);
    cout<<m;
    return 0;
}