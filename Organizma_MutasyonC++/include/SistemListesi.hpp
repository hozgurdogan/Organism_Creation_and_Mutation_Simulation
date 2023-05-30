#ifndef SistemListesi_hpp
#define SistemListesi_hpp

#include<exception>
#include<iostream>


#include "SistemDugum.hpp"


class SistemListesi
{
    public:

    SistemListesi();
    ~SistemListesi();

    void SistemeOrgan_ekle(OrganListesi* eklencek_organ);


    

   

    void Sistem_yazdir();
    
    
   // friend ostream& operator<<(ostream& os, SistemListesi & organ);


   
    SistemDugum* ilk_organ;

   
    
    

   


  
   
    int sistemdeki_organSayisi;
};
#endif

