#ifndef OrganDugum_hpp
#define OrganDugum_hpp
#include <iostream>
#include "SatirDoku.hpp"
using namespace std;

class OrganDugum
{

public:
    OrganDugum(SatirDoku* Satir);
    ~OrganDugum();
    
    SatirDoku* Doku;
    OrganDugum* sonraki;
    OrganDugum* onceki;
    
};
#endif

