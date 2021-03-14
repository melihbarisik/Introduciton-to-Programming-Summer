/********************************************************************************
                               SAKARYA ÜNÝVERSÝTESÝ
					BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
					     BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
                           PROGRAMLAMAYA GÝRÝÞ DERSÝ

						   ÖDEV NUMARASI........:1.ÖDEV
						   ÖÐRENCÝ ADI..........:MELÝH ENSAR BARIÞIK
						   ÖÐRENCÝ NUMARASI.....:
						   DERS GRUBU...........:A

*********************************************************************************/


#include <iostream>
using namespace std;

int main()
{
	// Her seferinde bir alt satýra geçerek þeklin 7 satýr olmasýný saðlar
	for (int i = 0; i < 7; i++)
	{
		// Þekilde görülen ilk ücgeni basma islemini yapar.
		for (int j = 7; j > i; j--)
		{
			cout << "*";
		}
		
		//Ýki ucgen arasýndaki boslugu olusturur.
		for (int k = 0; k < i; k++)
		{
			cout<<"  ";
		}
		
		// Þekilde görülen ilk ücgeni basma islemini yapar.
		for (int j = 7; j > i; j--)
		{
			cout << "*";
		}
		cout << endl;
	}

	system("pause");
}