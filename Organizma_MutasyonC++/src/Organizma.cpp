#include <Organizma.hpp>
#include <iomanip>
#include <iostream>
using namespace std;

Organizma:: Organizma()
{
    ilkSistem=0;
    organizmadakiSistemSayisi=0;

 
 
   
  

}
Organizma::~Organizma()
{

}

void Organizma::OrganizmayaSistemEkle(SistemListesi* eklencekSistem)
{



     organizmadakiSistemSayisi++;
  
   
   
    OrganizmaDugum* yeniDugum = new OrganizmaDugum(eklencekSistem);
   

    if(ilkSistem==0)
    {
        ilkSistem = yeniDugum;
         organizmadakiSistemSayisi++;

    }
    else
    {
        OrganizmaDugum* gec = ilkSistem;

        while(gec->sonraki!=0)
        {
            gec=gec->sonraki;
        }

        gec->sonraki = yeniDugum;
        yeniDugum->onceki = gec;
       
    
    }
   
    

}

void Organizma::Mutasyon()
{
    OrganizmaDugum* sistemler=ilkSistem;
    
    int sayac1=0;  int sistem_sayac=0;
     int sayac=0;
    while(sistemler!=0)
    {
        SistemDugum* Orgamlar=sistemler->Sistem->ilk_organ;
       
      
        sistem_sayac++;
        while(Orgamlar!=0)
        {
            
            int Organin__Agacin_kok_verisi;
           Organin__Agacin_kok_verisi= Orgamlar->Organ->agac->kok->veri->Dna_uzunlugu;

           OrganDugum* Dokular=Orgamlar->Organ->ilkDoku;
            
           while(Dokular!=0)
           {
                SatirHucre* Hucreler=Dokular->Doku->ilk_hucre;
                if(Organin__Agacin_kok_verisi%50==0)    
                { 
                    sayac++;
                    cout<<" Mutsayona ugricak Doku ->  ";  Dokular->Doku->DokuYazdir();
                    SatirDoku* MutasyonluDoku=new SatirDoku();
                    while(Hucreler!=0)
                    {
                        if((Hucreler->Dna_uzunlugu)%2==0)
                        {
                            Hucreler->Dna_uzunlugu=(Hucreler->Dna_uzunlugu)/2;
                            MutasyonluDoku->Hucre_ekle(Hucreler->Dna_uzunlugu);
                        }
                        else{

                            MutasyonluDoku->Hucre_ekle(Hucreler->Dna_uzunlugu);

                        }

                        Hucreler=Hucreler->sonraki_hucre;
                    }

                    cout<<"Mutasyonlu hali--->";  MutasyonluDoku->DokuYazdir();

                    delete MutasyonluDoku;

          



                }

                else                                      
                {
                    Dokular->Doku->Ortadaki_hucreyi_bulma();
                    Orgamlar->Organ->agacMutasyon->ekle(Dokular->Doku->Ortanca_dugum);
                }


            Dokular=Dokular->sonraki;
           }
            
           
              
         
        
            Orgamlar->Organ->Agac_denge_kontrol();
            Orgamlar=Orgamlar->sonraki;
        }
        sistemler=sistemler->sonraki;
    }

    cout<<endl<<sayac;
    


}















void Organizma::OrganizmaPrint()
{
     OrganizmaDugum* gec=ilkSistem;
     

 
    if(ilkSistem==0)
    {
        cout<<"bos";
    }

    else{ 
        
    int sayac=0;


    while (gec!=0)
    {   
        sayac++;
        SistemDugum* gec1=gec->Sistem->ilk_organ;
        while (gec1!=0)
    {   
      
        
         if(gec1->Organ->Organ_dengeliMi==true)
         {
            cout<<" ";
         }
         else if(gec1->Organ->Organ_dengeliMi==false)
         {
            cout<<"#";

         }

          
        gec1=gec1->sonraki;
    }
  
         
        
      
        gec=gec->sonraki;
            cout<<endl;

    }
    }
}


