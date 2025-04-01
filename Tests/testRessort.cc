#include <iostream>
#include "../general/vecteur3D.h"
#include "../general/masse.h"
#include "../general/ressort.h"

using namespace std;

int main(){
    Masse m1(3, Vecteur3D(0,0,0), Vecteur3D(0,0,0), 0.4);
    Masse m2(2, Vecteur3D(10,0,0), Vecteur3D(0,0,0), 0.4);

    Ressort ressort1(m1,m2, 1, 0);
    cout<<ressort1;

    ressort1.get_masse_arrive().set_masse(10);
    m1.mise_a_jour_forces();
    m2.mise_a_jour_forces();


    cout<<ressort1;



    return 0;
}