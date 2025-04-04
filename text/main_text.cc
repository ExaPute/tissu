#include <iostream>
#include "text_viewer.h"
#include "../general/include/systeme.h"
#include "../general/include/tissuRectangle.h"
using namespace std;

int main()
{
  TextViewer ecran(cout);
  Systeme s;
  Masse m(1,Vecteur3D(0),Vecteur3D(0),0);
  vector<Tissu*> vec;
  vector<Masse> ma;
  ma.push_back(m);

  Tissu t(ma);
  vec.push_back(&t);

  Impulsion i2(Vecteur3D(0),0.1,Vecteur3D(1000,0,0),vec,0,1000);

  s.ajoute_contrainte(i2);

  s.ajoute_tissu(t);
  double dt = 0.01;
  cout<<"toto";
  int i = 0;
  IntegrateurEulerCromer inte;

  s.set_integrateur(inte);
  while (i<50)
  {
    cout<< " Temps = "<<dt*i<<endl;
    s.dessine_sur(ecran);
    s.evolve(dt,dt*i);
    cout<<i;
    ++i;
  }
  
  

  return 0;
}