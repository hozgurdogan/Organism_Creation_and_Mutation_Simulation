#ifndef SatirHucre_hpp
#define SatirHucre_hpp
#include <iostream>
using namespace std;

class  SatirHucre
{

public:
     SatirHucre(int Dna_uzunlugu);

     ~ SatirHucre();

    int Dna_uzunlugu;


     SatirHucre* sonraki_hucre;
     SatirHucre* onceki_hucre;
    
};
#endif

