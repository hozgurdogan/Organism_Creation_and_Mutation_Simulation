#ifndef OrganListesi_hpp
#define OrganListesi_hpp

#include<exception>
#include<iostream>
#include "OrganDugum.hpp"
#include "IkiliArama_agaci.hpp"

class OrganListesi
{
    public:

    OrganListesi();
    ~OrganListesi();

    void Organa_doku_ekle(SatirDoku* eklencek_doku);


    Ikili_arama_agaci* agac=new Ikili_arama_agaci();
    Ikili_arama_agaci* agacMutasyon=new Ikili_arama_agaci();

    SatirDoku* Post_ordeOkunmus=new SatirDoku();

    void Agac_denge_kontrol ();
    
    int ilk_hucre_getir();
   

    void Organ_yaz();
    bool Organ_dengeliMi;
    
    
   // friend ostream& operator<<(ostream& os, OrganListesi & doku);


   
    OrganDugum* ilkDoku;

   
    
    

    OrganDugum* Ortanca_dugum;


  
   
    OrganDugum* view_head();
   
    int Organdaki_doku_sayisi;
};
#endif

