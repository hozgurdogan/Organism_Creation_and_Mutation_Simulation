#ifndef OrganizmaDugum_hpp
#define OrganizmaDugum_hpp
#include <iostream>
#include "SistemListesi.hpp"
using namespace std;

class OrganizmaDugum
{

public:
    OrganizmaDugum(SistemListesi* Sistem);
    ~OrganizmaDugum();
    
    SistemListesi* Sistem;
    
    OrganizmaDugum* sonraki;
    OrganizmaDugum* onceki;
    
};
#endif

