#ifndef Organizma_hpp
#define Organizma_hpp

#include<exception>
#include<iostream>
#include <Organizma.hpp>

#include "OrganizmaDugum.hpp"


class Organizma
{
    public:

    Organizma();
    ~Organizma();

    void OrganizmayaSistemEkle(SistemListesi* eklencekSistem);






    void Mutasyon();

   

    void OrganizmaPrint();
    
    
   // friend ostream& operator<<(ostream& os, SistemListesi & organ);


   
    OrganizmaDugum* ilkSistem;

   
    
    

   


  
   
    int organizmadakiSistemSayisi;
};
#endif

