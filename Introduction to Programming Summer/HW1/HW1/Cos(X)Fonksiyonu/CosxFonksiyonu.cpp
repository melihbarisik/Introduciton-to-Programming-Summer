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

float radyanCevir(float, float);
void ciz(float);



int  main()
{
	int deger;
	cout << "1-9 Arasinda bir deger giriniz     :"; cin >> deger;

	//Girlen degerin 1 ile 9 arasýnda olmasý için kontrol ediyor.
	while (deger != 1 && deger != 2 && deger != 3 && deger != 4 && deger != 5 && deger != 6 && deger != 7 && deger != 8 && deger != 9)
	{
		cout << "Sayi 1 ile 9 arasinda bir deger olmalidir." << endl;
		cout << " Yeni bir deger giriniz  :";
		cin >> deger;
	}
	float radyan = 0.0;

	// 360 derece üzerinden açýyý 18 li parçalar halinde bölüp fonksyonlara gönderiyor
	for (int i = 0; i <= 360; i = i + 18)
	{
		radyan = radyanCevir(deger, i);
		ciz(radyan);
	}

	system("pause");
}




float radyanCevir(float deger, float aci)
{
	float radyan;
	aci = aci * 3.141618 / 180;
	radyan = deger * cos(aci);
	return radyan;
}


void ciz(float radyan)
{
	int basilacakSayi;

	//Deger negatif ise 
	if (radyan < 0.0)
	{
		// sayý negatif ve çok küsürlü olabileceði için mutlak deðerini alýp int deger yapýyoruz.
		basilacakSayi = (int)fabs(radyan);

		basilacakSayi = 10 - basilacakSayi;

		//Fonksiyon grafiginin solunda kalan boþluklu alaný oluþturuyor
		for (int j = 1; j < basilacakSayi; j++)
			cout << " ";

		//Boþluklu alandan sonra gelecek yýldýzlarý bastýrýyýor.
		for (int j = basilacakSayi; j <= 10; j++)
			cout << "*";
	}

	//Deger pozitif ise 
	else
	{
		// Sayý küsürlü olabileceði için int deger yapýyoruz.
		basilacakSayi = (int)radyan;

		//Negatif ve pozitif degerlerin net ayrýmý olmasý için 10 sýra boþluk býrakýyoruz
		for (int j = 1; j < 11; j++)
			cout << " ";

		//Boþluklu alandan sonra gelecek yýldýzlarý bastýrýyýor.
		for (int j = 11; j <= basilacakSayi + 11; j++)
			cout << "*";
	}
	cout << endl;
}