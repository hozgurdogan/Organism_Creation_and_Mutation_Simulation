#ifndef Dugum_ikili_agac_arama_hpp

#define Dugum_ikili_agac_arama_hpp
#include "SatirHucre.hpp"
class Dugum_ikili_agac_arama
{
    public:
    Dugum_ikili_agac_arama(SatirHucre* orta_eleman);
    ~Dugum_ikili_agac_arama();
    
    
    SatirHucre* veri;

    Dugum_ikili_agac_arama *sol;
    Dugum_ikili_agac_arama *sag;
    
};




#endif