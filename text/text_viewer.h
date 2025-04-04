#pragma once

#include <iostream>
#include "../general/include/support_a_dessin.h"

class TextViewer : public SupportADessin {
public:
 TextViewer(std::ostream& flot)
    : flot(flot)
  {}
  virtual ~TextViewer() = default;
  // on ne copie pas les TextViewer
  TextViewer(TextViewer const&)            = delete; 
  TextViewer& operator=(TextViewer const&) = delete;
   // mais on peut les déplacer
  TextViewer(TextViewer&&)            = default; 
  TextViewer& operator=(TextViewer&&) = default;

  void dessine(Tissu const&);
  void dessine(Masse const&);
  void dessine(Systeme const&);
  void dessine(Ressort const&){}
private:
  std::ostream& flot;
};
