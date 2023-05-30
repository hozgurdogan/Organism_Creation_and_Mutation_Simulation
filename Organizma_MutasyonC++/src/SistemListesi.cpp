#include <SistemListesi.hpp>
#include <iomanip>
#include <iostream>
#include <Windows.h>
using namespace std;

SistemListesi:: SistemListesi()
{
    ilk_organ=0;
    sistemdeki_organSayisi=0;

 
 
   
  

}
SistemListesi::~SistemListesi()
{
    SistemDugum* gec= ilk_organ;
    while(gec!=0)
    {
        SistemDugum* silincek=gec;
        gec=gec->sonraki;
        delete silincek;

    }
    sistemdeki_organSayisi=0;
    
}

void SistemListesi::SistemeOrgan_ekle(OrganListesi* eklenecek_organ)
{

// eklenecek_organ->DokuYazdir();cout<<"******Sisteme Eklendi";

     sistemdeki_organSayisi++;
  
   
   
    SistemDugum* yeniDugum = new SistemDugum(eklenecek_organ);
   

    if(ilk_organ==0)
    {
        ilk_organ = yeniDugum;
         sistemdeki_organSayisi++;
      //   cout<< "ilk doku eklendi";
      //   yeniDugum->Doku->DokuYazdir();
    }
    else
    {
        SistemDugum* gec = ilk_organ;

        while(gec->sonraki!=0)
        {
            gec=gec->sonraki;
        }

        gec->sonraki = yeniDugum;
        yeniDugum->onceki = gec;
       
      //s  yeniDugum->Doku->DokuYazdir();
    }
   
    

}




void SistemListesi::Sistem_yazdir()
{
     SistemDugum* gec=ilk_organ;
     
  //  cout<<"sistemdeki organ sayisi.."<<sistemdeki_organSayisi;
    if(ilk_organ==0)
    {
        cout<<"bos";
    }

    else{ 
        
    int sayac=0;


    while (gec!=0)
    {   
        Sleep(400);
        sayac++;
  
       cout<<endl<<endl<<endl;
       cout<<".Sistem icindeki  icinde ki  "<<sayac+1 <<".Organ adresi....:"<<&gec<<"  doku sayisi:  "<<gec->Organ->Organdaki_doku_sayisi<<"  ve  orgainin dokulari..";
         
        /*
         if(gec->Organ->Organ_dengeliMi==true)
         {
            cout<<" ";
         }
         else if(gec->Organ->Organ_dengeliMi==false)
         {
            cout<<"#";

         }*/
       gec->Organ->Organ_yaz();
        gec=gec->sonraki;
    }
    }
}


