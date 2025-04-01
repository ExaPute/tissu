#include <QApplication>
#include "glwidget.h"
#include <vector>
#include "../general/systeme.h"
#include "../general/tissuRectangle.h"
#include "../general/tissuDisque.h"
#include "../general/tissuCompose.h"
#include "../general/contrainte.h"
int main(int argc, char* argv[])
{
  QApplication a(argc, argv);
  GLWidget w;
  std::vector<Tissu*> vect;




  TissuRectangle t(Vecteur3D(0,3,0),Vecteur3D(3,0,0),Vecteur3D(0,0,0),0.1,10,1,1,0.3);


  Crochet c1(Vecteur3D(0,0,0),0.1);
  Crochet c2(Vecteur3D(0,3,0),0.1);
  Crochet c3(Vecteur3D(3,3,0),0.1);
  Crochet c4(Vecteur3D(3,0,0),0.1);

    w.getSysteme()->ajoute_contrainte(c1);
    w.getSysteme()->ajoute_contrainte(c2);
    w.getSysteme()->ajoute_contrainte(c3);
    w.getSysteme()->ajoute_contrainte(c4);


  IntegrateurEulerCromer inte;
  w.getSysteme()->ajoute_tissu(t);
  w.getSysteme()->set_integrateur(inte);
  w.show();

  return a.exec();
}
