CXX = g++
CC = $(CXX)
CXXFLAGS = -std=c++11 -Wall
LDLIBS = -lm
all: testVecteur testRessort testIntegrateur1 testIntegrateur2 testTissu testSupport

testTissu: testTissu.o ../general/tissu.o ../general/masse.o ../general/ressort.o ../general/vecteur3D.o ../general/constantes.o ../general/integrateur.o
testSupport: testSupport.o ../general/support_a_dessin.o ../general/tissu.o ../general/masse.o ../general/ressort.o ../general/vecteur3D.o ../general/constantes.o

testMasse: testMasse.o ../general/masse.o ../general/vecteur3D.o ../general/constantes.o
testVecteur: testVecteur.o ../general/vecteur3D.o
testRessort: ../general/masse.o ../general/ressort.o ../general/vecteur3D.o ../general/constantes.o
testIntegrateur1 : testIntegrateur1.o ../general/constantes.o ../general/ressort.o ../general/masse.o ../general/vecteur3D.o ../general/integrateur.o
testIntegrateur2: testIntegrateur2.o ../general/constantes.o ../general/ressort.o ../general/masse.o ../general/vecteur3D.o ../general/integrateur.o

testIntegrateur1.o: testIntegrateur1.cc ../general/integrateur.h \
 ../general/masse.h ../general/vecteur3D.h ../general/constantes.h \
 ../general/dessinable.h
testIntegrateur2.o: testIntegrateur2.cc ../general/masse.h \
 ../general/vecteur3D.h ../general/constantes.h ../general/dessinable.h \
 ../general/ressort.h ../general/integrateur.h
testMasse.o: testMasse.cc ../general/masse.h ../general/vecteur3D.h \
 ../general/constantes.h ../general/dessinable.h ../general/ressort.h
testRessort.o: testRessort.cc ../general/vecteur3D.h ../general/masse.h \
 ../general/constantes.h ../general/dessinable.h ../general/ressort.h
testSupport.o: testSupport.cc ../general/support_a_dessin.h \
 ../general/masse.h ../general/vecteur3D.h ../general/constantes.h \
 ../general/dessinable.h
testTissu.o: testTissu.cc ../general/tissu.h ../general/ressort.h \
 ../general/vecteur3D.h ../general/masse.h ../general/constantes.h \
 ../general/dessinable.h ../general/integrateur.h
testVecteur.o: testVecteur.cc ../general/vecteur3D.h

cleanLinux:
	rm ../general/*.o
	rm *.o
	rm ../Qt_GL/*.o
	rm ../text/*.o
	rm *.exe
	rm ../Qt_GL/*.exe
	rm ../text/*.exe

cleanWindows:
	del *.o
	del *.exe

	
