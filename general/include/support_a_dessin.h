#pragma once

class Masse;
class Tissu;
class Systeme;
class Ressort;


class SupportADessin
{
 public:
  virtual ~SupportADessin() = default;
  // on ne copie pas les Supports
  SupportADessin(SupportADessin const&)            = delete; 
  SupportADessin& operator=(SupportADessin const&) = delete;
   // mais on peut les déplacer
  SupportADessin(SupportADessin&&)            = default; 
  SupportADessin& operator=(SupportADessin&&) = default;
  
  SupportADessin() = default; 

   virtual void dessine(Tissu const&) = 0;
   virtual void dessine(Masse const&) = 0;
   virtual void dessine(Systeme const&) = 0;
   virtual void dessine(Ressort const&) = 0;
  /* Mettre ici toutes les méthodes nécessaires pour dessiner tous les
   * objets que l'on veut dessiner. Par exemple :
   *    virtual void dessine(Nounours const& a_dessiner) = 0;
   *    virtual void dessine(Voiture  const& a_dessiner) = 0;
   */
};
