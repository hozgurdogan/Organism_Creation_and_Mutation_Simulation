#include <IkiliArama_agaci.hpp>

#include<iostream>
using namespace std;

Ikili_arama_agaci::Ikili_arama_agaci()
{
    kok=0;
   
}
Ikili_arama_agaci::~Ikili_arama_agaci()
{
    
}

void Ikili_arama_agaci:: PostOrder_DiziAtama(Dugum_ikili_agac_arama* root , int *arr, int i ){
    if(kok!=0){
        PostOrder_DiziAtama(root->sol, arr, i);
        PostOrder_DiziAtama(root->sag,arr,i);
        arr[i++] = root->veri->Dna_uzunlugu;

   
            }
}

bool Ikili_arama_agaci::varmi(SatirHucre* veri)
{
    return varmi(veri,kok);
}
bool Ikili_arama_agaci::varmi(SatirHucre* aranan,Dugum_ikili_agac_arama* aktif_d)
{
    if(aktif_d->veri< aranan)
    {
        if(aktif_d->sag)
        {
            return varmi(aranan,aktif_d->sag);
        }
        else{
            false;

        }
    }

    else if(aktif_d->veri>aranan)
    {
        if(aktif_d->sol)
        {
            return varmi(aranan,aktif_d->sol);
        }
        else
        {
            return false;

        }
    }


    else 
    {

       return true;

    }
}


void Ikili_arama_agaci::ekle(SatirHucre* veri)
{

    
    if(kok==0)
    {
        kok=new Dugum_ikili_agac_arama(veri);
        kok->veri=veri;
        
    }
      
    else
        ekle(veri,kok);

}
void Ikili_arama_agaci::ekle(SatirHucre* veri,Dugum_ikili_agac_arama* aktif_d)


{

    if(aktif_d->veri->Dna_uzunlugu >veri->Dna_uzunlugu || aktif_d->veri->Dna_uzunlugu==veri->Dna_uzunlugu) 
    {
        if(aktif_d->sol)
        {
             ekle(veri,aktif_d->sol);
        //     cout<<"sol dugume eklendi"<<endl;
        }
        else
        {
            aktif_d->sol=new Dugum_ikili_agac_arama(veri); 
            aktif_d->sol->veri=veri;
          //  cout<<"sol Dugume eklendi"<<endl;
         
        }
    }
    else if(aktif_d->veri->Dna_uzunlugu<veri->Dna_uzunlugu)
    {
        if(aktif_d->sag)
        {
             ekle(veri,aktif_d->sag);
           //  cout<<"sag dugume eklendi"<<endl;
        }
        else{
            aktif_d->sag=new Dugum_ikili_agac_arama(veri);
              aktif_d->sag->veri=veri;
       // cout<<"sag dugume eklendi"<<endl;

            
        }
    }

    else
    {
        return;
    }
}



int Ikili_arama_agaci::Yukseklik(Dugum_ikili_agac_arama* AktifHucre)
{
    if(AktifHucre)
    {
        return 1+ std::max(Yukseklik(AktifHucre->sol),Yukseklik(AktifHucre->sag));
        
    }
    return -1;
}
int Ikili_arama_agaci::Yukseklik_farki(Dugum_ikili_agac_arama* Kok)
{
    return abs(Yukseklik(kok->sol)-Yukseklik(kok->sag)); 
}
void Ikili_arama_agaci::agac_silme(Dugum_ikili_agac_arama* root)
{
    
    if (root == nullptr)
        return;

    agac_silme(root->sol);
    agac_silme(root->sag);
    
    delete root;
}
