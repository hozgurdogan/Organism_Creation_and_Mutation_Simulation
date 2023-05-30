#include<OrganListesi.hpp>
#include <iomanip>
#include <iostream>

using namespace std;

OrganListesi:: OrganListesi()
{
    ilkDoku=0;
    Organdaki_doku_sayisi=0;

 
 
   
  

}
OrganListesi::~OrganListesi()
{
    OrganDugum* gec= ilkDoku;
    while(gec!=0)
    {
        OrganDugum* silincek=gec;
        gec=gec->sonraki;
        delete silincek;

    }
  
    
}
void OrganListesi:: Agac_denge_kontrol()
{
   

   if(agac->Yukseklik_farki(agac->kok)>1)
   {
    Organ_dengeliMi=false;
   }
   else 
   {
    Organ_dengeliMi=true;
   }
    
   

    
}

void OrganListesi::Organa_doku_ekle(SatirDoku* eklencekDoku)
{
    cout<<endl;
    Organdaki_doku_sayisi++;
     //   cout<<Organdaki_doku_sayisi<<endl;

   
    OrganDugum* yeniDugum = new OrganDugum(eklencekDoku);
   

    if(ilkDoku==0)
    {
        ilkDoku = yeniDugum;
        
       //  cout<< "ilk doku eklendi";
      //   yeniDugum->Doku->DokuYazdir();
    }
    else
    {
        OrganDugum* gec = ilkDoku;

        while(gec->sonraki!=0)
        {
            gec=gec->sonraki;
        }

        gec->sonraki = yeniDugum;
        yeniDugum->onceki = gec;
        
      //s  yeniDugum->Doku->DokuYazdir();
    }
   
    

}
int OrganListesi::ilk_hucre_getir()
{
    if(ilkDoku!=0)
    {
        ilkDoku->Doku->DokuYazdir();
    }
    throw std::out_of_range("Doku::ilkHucre(): Doku bos hataasi");
}

/*
ostream& operator<<(ostream& os , OrganListesi & liste)
{
    using namespace std;

    OrganDugum* gec=liste.ilkDoku;

    if(liste.ilkDoku==0)
    {
        cout<<"bos";
    }

    else{
    int sayac=0;
    cout<<"Organdaki doku adedi... "<<liste.Organdaki_doku_sayisi<<endl;
    cout<<"organin koku.........."<<liste.agac->kok->veri->Dna_uzunlugu<<"         ";
    while (gec!=0)
    {   sayac++;
  
       
        cout<<"organ icinde ki doku adresi....:"<<gec->Doku<<"    ";
        cout<<sayac<<"."<<"dokunun hucreleri...." ; gec->Doku->DokuYazdir(); cout<<endl;
        gec=gec->sonraki;
    }
    }
}

*/
void OrganListesi::Organ_yaz()
{
    
    OrganDugum* gec=ilkDoku;
    int sayac=0;  
    cout<<"  kok degeri----->"<<    gec->Doku->Ortanca_dugum->Dna_uzunlugu;


    while (gec!=0)
    {
        cout<<endl;
        cout<<sayac+1<<".doku hucreleri...." ; gec->Doku->DokuYazdir(); cout<<endl;
        gec=gec->sonraki;
        
        sayac++;
        
    }
}
