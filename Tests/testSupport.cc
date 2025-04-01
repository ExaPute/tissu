#include "../general/support_a_dessin.h"
#include "../general/masse.h"
#include "../text/text_viewer.h"

int main(){
    Masse m1(23);

    TextViewer supp(std::cout);

    m1.dessine_sur(supp);
    return 0;
}