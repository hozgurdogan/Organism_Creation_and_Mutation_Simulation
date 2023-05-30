#include<SatirDoku.hpp>
#include <iomanip>

SatirDoku:: SatirDoku()
{
    ilk_hucre=0;
    Dokudaki_hucre_sayisi=0;
    Ortanca_dugum=0;
    indis=0;
    

}
SatirDoku::~SatirDoku()
{
    SatirHucre* gec= ilk_hucre;
    while(gec!=0)
    {
        SatirHucre* silincek=gec;
        gec=gec->sonraki_hucre;
        delete silincek;

    }
    Dokudaki_hucre_sayisi=0;
}

void SatirDoku::Hucre_ekle(int Dna_uzunlugu)
{
    
    SatirHucre* yeniDugum = new SatirHucre(Dna_uzunlugu);
    if(ilk_hucre==0)
    {
        ilk_hucre = yeniDugum;
         Dokudaki_hucre_sayisi++;
    }
    else
    {
        SatirHucre* gec = ilk_hucre;

        while(gec->sonraki_hucre!=0)
        {
            gec=gec->sonraki_hucre;
        }

        gec->sonraki_hucre = yeniDugum;
        yeniDugum->onceki_hucre = gec;
         Dokudaki_hucre_sayisi++;
    }
   
    

}
int SatirDoku::ilk_hucre_getir()
{
    if(ilk_hucre!=0)
    {
        return ilk_hucre->Dna_uzunlugu;
    }
    throw std::out_of_range("Doku::ilkHucre(): Doku bos hataasi");
}

void SatirDoku::Hucre_cikar()
{
    if(ilk_hucre==0)
    {
        return;
    }
    if(ilk_hucre->sonraki_hucre==0)
    {

    }
    Dokudaki_hucre_sayisi--;
}

void SatirDoku::Sirali_doku_yazdir()
{
    
    SatirHucre* gec=ilk_hucre;
    while (gec!=0)
    {
        cout<<setw(4)<<gec->Dna_uzunlugu;
        gec=gec->sonraki_hucre;
       
        
    }
    
    cout<<"  Hucre sayisi---->"<<Dokudaki_hucre_sayisi<<"------> ortanca eleman :"<<Ortanca_dugum->Dna_uzunlugu;
   
}
void SatirDoku::DokuYazdir()
{
   
    SatirHucre* gec=ilk_hucre;
    cout<<"Dokudaki Hucre sayisi---->"<<Dokudaki_hucre_sayisi;
    cout<<endl;
    int sayac=0;
    cout<<endl;
   
    while (gec!=0)
    {
  
        cout<<setw(4)<<gec->Dna_uzunlugu ;
        gec=gec->sonraki_hucre;
    
        
    }

}
int SatirDoku:: remove()
	{
		SatirHucre* t = ilk_hucre;
		int a = t->Dna_uzunlugu;
		ilk_hucre = t->sonraki_hucre;
         Dokudaki_hucre_sayisi=0;
		delete t;
		return a;
        
       
	}

    int SatirDoku:: is_empty()
	{
		if (ilk_hucre == NULL)
			return 1;
		else
			return 0;
	}
    SatirHucre* SatirDoku ::view_head()
    {
        return ilk_hucre;

    }
    void SatirDoku:: print()
	{
		SatirHucre* t = ilk_hucre;
		while (t != NULL)
		{
			cout << t->Dna_uzunlugu << " ";
			t = t->sonraki_hucre;
		}
	}
  void SatirDoku:: Ortadaki_hucreyi_bulma()
    {
        SatirHucre* gec=ilk_hucre;
        indis=(Dokudaki_hucre_sayisi+1)/2;
       
     
      
        for(int i=0;i<indis;i++)
        {
            gec=gec->sonraki_hucre;
            

        }
        Ortanca_dugum=gec;
      //  cout<<endl<<Ortanca_dugum;
        //cout<<endl;
 
    }
   