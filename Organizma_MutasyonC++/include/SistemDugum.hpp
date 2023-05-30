#ifndef SistemDugum_hpp
#define SistemDugum_hpp
#include <iostream>
#include "OrganListesi.hpp"
using namespace std;

class SistemDugum
{

public:
    SistemDugum(OrganListesi* ORgan);
    ~SistemDugum();
    
    OrganListesi* Organ;
    
    SistemDugum* sonraki;
    SistemDugum* onceki;
    
};
#endif

