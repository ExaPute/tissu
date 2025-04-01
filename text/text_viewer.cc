#include <iostream> // pour endl
#include "text_viewer.h"
#include "../general/systeme.h"


void TextViewer::dessine(Tissu const& t){
    flot<<t;
}

void TextViewer::dessine(Masse const& m){
    flot<<m;
}

void TextViewer::dessine(Systeme const& s){
    flot<<s;
}
