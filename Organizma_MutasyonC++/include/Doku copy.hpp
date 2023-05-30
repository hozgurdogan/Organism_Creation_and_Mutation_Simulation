#ifndef SatirDoku_hpp
#define SatirDoku_hpp
#include<exception>
#include<iostream>
#include "SatirHucre.hpp"

class SatirDoku
{
    public:

    SatirDoku();
    ~SatirDoku();
    void Hucre_ekle(int Dna_uzunlugu);
    void Hucre_cikar();
    int ilk_hucre_getir();
    void Sirali_doku_yazdir();
    void DokuYazdir();
    friend ostream& operator<<(ostream& os, SatirDoku & doku);
    SatirHucre* Hucre_getir(int sira);
   
    SatirHucre* ilk_hucre;

    void Ortadaki_hucreyi_bulma();
    int indis;
    

    SatirHucre* Ortanca_dugum;


    int remove();
    int is_empty();
    SatirHucre* view_head();
    void print();
    int Dokudaki_hucre_sayisi;
};

#endif