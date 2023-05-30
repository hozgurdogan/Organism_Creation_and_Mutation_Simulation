#include "Dugum_ikili_agac_arama.hpp"
#include<algorithm>
#include "SatirDoku.hpp"

#ifndef Ikili_arama_Agaci_hpp
#define Ikili_arama_Agaci_hpp

class Ikili_arama_agaci
{

public:
    Ikili_arama_agaci();
    ~Ikili_arama_agaci();
    bool  varmi(SatirHucre* veri);
    bool  varmi(SatirHucre* aranan,Dugum_ikili_agac_arama* aktif_d);
    void ekle(SatirHucre* veri,Dugum_ikili_agac_arama* aktif_d);
    void ekle(SatirHucre* veri);
    int Yukseklik(Dugum_ikili_agac_arama* aktifDugum);
    int Yukseklik_farki(Dugum_ikili_agac_arama* kok);
    void PostOrder_DiziAtama(Dugum_ikili_agac_arama* root, int arr[], int index);
   
    void agac_silme(Dugum_ikili_agac_arama* root);

       SatirDoku* Post_ordeOkunmus=new SatirDoku();
        SatirDoku* mutasyonagac=new SatirDoku();
    Dugum_ikili_agac_arama* kok;


};




#endif