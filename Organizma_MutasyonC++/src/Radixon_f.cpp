#include <Radionx_F.hpp>
#include <iostream>



int Radixon_f :: max_digit(SatirDoku *& l)
{
	int a, dig = 0, i;
	SatirHucre* t = l->view_head();
	a = t->Dna_uzunlugu;
	while (t != NULL)
	{
		if (a < t->Dna_uzunlugu)
			a = t->Dna_uzunlugu;
		t = t->sonraki_hucre;
	}
	while (a > 0)
	{
		a = a / 10;
		dig++;
	}
	return dig;
}
int Radixon_f:: pow(int a, int b)
{
	int ans = 1;
	while (b--)
	{
		ans = ans * a;
	}
	return ans;
}
void  Radixon_f:: radix_sort(SatirDoku*& l, SatirDoku r[])
{
	int i = 1, j, a, b;
	int num = max_digit(l);
	while (i <= num)
	{
		while (!l->is_empty())
		{
			a = l->remove();
			b = a % pow(10, i);
			b = b / pow(10, i - 1);
			r[b].Hucre_ekle(a);
		}
		for (j = 0;j < 10;j++)
		{
			while (!r[j].is_empty())
			{
				a = r[j].remove();
				l->Hucre_ekle(a);
			}
		}
		i++;
	}
}





