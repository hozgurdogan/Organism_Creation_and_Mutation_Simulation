

#include <iostream>
#include<iomanip>
#include<fstream>
#include <string>
#include<sstream>


#include <Organizma.hpp>

 

#include <Radionx_F.hpp>
using namespace std;


int main()
{


    Ikili_arama_agaci* agac=new Ikili_arama_agaci();

    
   
   string dosyaAdi="GulerYuz.txt";      // ilk başta dosya okunarak kaçar aded değişken oluştrucağımız hesaplanıyor bi nevi satır boyutları hesaplanıyor....

ifstream dosyaoku1(dosyaAdi);

     int sistem_sayaci1=0;
    int Sistem_adedi=0;
    int Organ_adedi=0;
     int satrirSayisi=0;
    if(dosyaoku1.is_open())
    {
        string doku;
       
        while(std::getline(dosyaoku1,doku))
        {
            satrirSayisi++;
          sistem_sayaci1++;
            int siradaki_hucre;

            stringstream doku_okuycu(doku);
        
           while( doku_okuycu>>siradaki_hucre)
           {
        
           
           }       

     

          
             if(sistem_sayaci1%2000==0 && sistem_sayaci1!=0 &&sistem_sayaci1!=58000)
            {
             
                
                Sistem_adedi++;

            }
        
         
            if(satrirSayisi%20==0)
             {
               
               
                Organ_adedi++;
             }

        

        }
    }









dosyaoku1.close();                                      //dosya tekrar okunmak Ã¼zere kapanÄ±yor







 SistemListesi* sistem=new SistemListesi[Sistem_adedi+1];
 OrganListesi* org2=new OrganListesi[Organ_adedi];










  // bu sefer dosya yeniden okunuyor ve bellekte veriler tutuluyor....

   
    ifstream dosya_oku(dosyaAdi);

    Radixon_f* r1=new Radixon_f();
    SatirDoku r[10];

  

        
    int i=0;
    int sistem_sayaci=0;
    int yenisistem=0;
    if(dosya_oku.is_open())
    {
        string doku;
        int satrirSayisi=0;
        while(std::getline(dosya_oku,doku))
        {
            satrirSayisi++;
          sistem_sayaci++;
            int siradaki_hucre;

            stringstream doku_okuycu(doku);
            SatirDoku* siradaki_doku=new SatirDoku();
            SatirDoku* radix_list=new SatirDoku();
           while( doku_okuycu>>siradaki_hucre)
           {
        
              siradaki_doku->Hucre_ekle(siradaki_hucre);
              radix_list->Hucre_ekle(siradaki_hucre);
           
           }       

          
          
      
      
             
             r1->radix_sort(radix_list,r);                        //radixon için gerekli nesneler oluşturuluyor
             radix_list->Ortadaki_hucreyi_bulma();  
         
    
            siradaki_doku->Ortanca_dugum=radix_list->Ortanca_dugum;
            siradaki_doku->Ortanca_dugum->Dna_uzunlugu=radix_list->Ortanca_dugum->Dna_uzunlugu;
        
        
             if(sistem_sayaci%2000==0 && sistem_sayaci!=0 &&sistem_sayaci!=58000)
            {
             
                yenisistem++;

            }
           
     
             org2[i].agac->ekle(siradaki_doku->Ortanca_dugum);
             
            org2[i].Organa_doku_ekle(siradaki_doku);
                // cout<<org2[i].agac->kok->veri->Dna_uzunlugu;
            if(satrirSayisi%20==0)
             {
                org2[i].Agac_denge_kontrol();
                sistem[yenisistem].SistemeOrgan_ekle(&org2[i]);
               
                i++;
             }

        }
      
    }




   for(int i=0;i<Organ_adedi;i++)
{
 
   
    delete &org2[i];
}





Organizma* organizma=new Organizma() ;                     //organizma oluÅŸturludu

cout<<Sistem_adedi;
for(int i=0;i<Sistem_adedi;i++)
{

   

    organizma->OrganizmayaSistemEkle(&sistem[i]); 
    delete &sistem[i];
    

}




    



  
    


    


  //  organizma->Mutasyon();
 











SistemListesi* sistem_yeni_m=new SistemListesi[Sistem_adedi+1];
 OrganListesi* org2_yeni_m=new OrganListesi[Organ_adedi];



    Radixon_f* r1_yeni=new Radixon_f();
    SatirDoku r12[10];
    
    
    
    
    
     i=0;
     sistem_sayaci=0;
     yenisistem=0;
    Organizma* organizm2=new Organizma();
    int mutasyon_organ_kontrol=2;



        OrganizmaDugum* sistemler=organizma->ilkSistem;
    
    int sayac1=0;  int sistem_sayac=0;
     int sayac=0;
     int m_sistem_sayaci=0;
    while(sistemler!=0)
    { m_sistem_sayaci++;
        SistemDugum* Orgamlar=sistemler->Sistem->ilk_organ;
       
      
        sistem_sayac++;
        while(Orgamlar!=0)
        {

            
            int Organin__Agacin_kok_verisi;
        //    cout<<Orgamlar->Organ->agac->kok->veri->Dna_uzunlugu<<endl;
           Organin__Agacin_kok_verisi= Orgamlar->Organ->agac->kok->veri->Dna_uzunlugu;

           OrganDugum* Dokular=Orgamlar->Organ->ilkDoku;
            
           while(Dokular!=0)
           {
                 satrirSayisi++;
                  sistem_sayaci++;
            int siradaki_hucre;
             SatirDoku* siradaki_doku_mutasyon=new SatirDoku();
              SatirDoku* radix_list_yeni=new SatirDoku();
                SatirHucre* Hucreler=Dokular->Doku->ilk_hucre;
                if(Organin__Agacin_kok_verisi%50==0)    //MUtasyon ilk kural;
                { 
                    mutasyon_organ_kontrol=1;
                    
                    sayac++;
                  
                
                    while(Hucreler!=0)
                    {
                 

                        if((Hucreler->Dna_uzunlugu)%2==0)
                        {
                         
                            Hucreler->Dna_uzunlugu=(Hucreler->Dna_uzunlugu)/2;
                           
                            siradaki_doku_mutasyon->Hucre_ekle(Hucreler->Dna_uzunlugu);
                             radix_list_yeni->Hucre_ekle(Hucreler->Dna_uzunlugu);
           
                        }
                        else{

                       
                            siradaki_doku_mutasyon->Hucre_ekle(Hucreler->Dna_uzunlugu);
                             radix_list_yeni->Hucre_ekle(Hucreler->Dna_uzunlugu);

                        }

                        Hucreler=Hucreler->sonraki_hucre;



                    }


                } // Mutasyon organ Doku

                else                                       //normal doku
                {
                    mutasyon_organ_kontrol=0;
                    
                    while(Hucreler!=0)
                    {
                      
                        siradaki_doku_mutasyon->Hucre_ekle(Hucreler->Dna_uzunlugu);
                         radix_list_yeni->Hucre_ekle(Hucreler->Dna_uzunlugu);
                        Hucreler=Hucreler->sonraki_hucre;
                    }
                    

                }





    r1_yeni->radix_sort(radix_list_yeni,r12);   
    radix_list_yeni->Ortadaki_hucreyi_bulma();   
    siradaki_doku_mutasyon->Ortanca_dugum=radix_list_yeni->Ortanca_dugum;
    siradaki_doku_mutasyon->Ortanca_dugum->Dna_uzunlugu=radix_list_yeni->Ortanca_dugum->Dna_uzunlugu; 
             
        org2_yeni_m[i].agac->ekle(siradaki_doku_mutasyon->Ortanca_dugum);
        org2_yeni_m[i].Organa_doku_ekle(siradaki_doku_mutasyon);
        if(sistem_sayaci%2000==0 && sistem_sayaci!=0 &&sistem_sayaci!=52000)
            {
             
                yenisistem++;

            }


                if(mutasyon_organ_kontrol==1)
         {
                








/*


                org2_yeni_m->agac->PostOrder(Orgamlar->Organ->agac->kok);

                 r1_yeni->radix_sort(org2_yeni_m->agac->postOrderDizi,r12);   

                    SatirHucre* gec8=org2->agac->postOrderDizi->ilk_hucre;
                    while(gec8!=0)
                    {
                        cout<<"Burasi";
                        org2_yeni_m->agac->ekle(gec8);
                        
                        gec8=gec8->sonraki_hucre;
                    }

                    */
                   org2_yeni_m->agac=Orgamlar->Organ->agac;

                org2_yeni_m[i].Organa_doku_ekle(siradaki_doku_mutasyon);




         }
         else if(mutasyon_organ_kontrol==0)
         {
           org2_yeni_m[i].agac->ekle(siradaki_doku_mutasyon->Ortanca_dugum);
           org2_yeni_m[i].Organa_doku_ekle(siradaki_doku_mutasyon);

            
         }

           if(satrirSayisi%20==0  && satrirSayisi!=0)
             {
                org2_yeni_m[i].Agac_denge_kontrol();
                sistem_yeni_m[yenisistem].SistemeOrgan_ekle(&org2_yeni_m[i]);
               
                i++;
             }

        


             

            delete siradaki_doku_mutasyon;
            Dokular=Dokular->sonraki;
           }
            
           
              
     
            Orgamlar->Organ->Agac_denge_kontrol();
            Orgamlar=Orgamlar->sonraki;
        }
        sistemler=sistemler->sonraki;
        cout<<m_sistem_sayaci
        <<endl;
     //   Sleep(800);
    }


      for(int i=0;i<Organ_adedi;i++)
{
  
   
    delete &org2_yeni_m[i];
}

for(int i=0;i<Sistem_adedi;i++)
{

   

    organizm2->OrganizmayaSistemEkle(&sistem_yeni_m[i]); 

    

}


    system("CLS");

    cout<<"              ORGANIZMA "<<endl;

        organizma->OrganizmaPrint();






  
    
    
    std::string input;
    std::getline(std::cin, input);

    if (input.empty())
    {
        system("CLS");
            cout<<"              ORGANIZMA(MUTASYON) "<<endl;
                    organizm2->OrganizmaPrint();
    }

    


}


        

    
    

    




   