/********************************************************************************
							   SAKARYA �N�VERS�TES�
					B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
						 B�LG�SAYAR M�HEND�SL��� B�L�M�
						   PROGRAMLAMAYA G�R�� DERS�

						   �DEV NUMARASI........:1.�DEV
						   ��RENC� ADI..........:MEL�H ENSAR BARI�IK
						   ��RENC� NUMARASI.....:
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

	//Girlen degerin 1 ile 9 aras�nda olmas� i�in kontrol ediyor.
	while (deger != 1 && deger != 2 && deger != 3 && deger != 4 && deger != 5 && deger != 6 && deger != 7 && deger != 8 && deger != 9)
	{
		cout << "Sayi 1 ile 9 arasinda bir deger olmalidir." << endl;
		cout << " Yeni bir deger giriniz  :";
		cin >> deger;
	}
	float radyan = 0.0;

	// 360 derece �zerinden a��y� 18 li par�alar halinde b�l�p fonksyonlara g�nderiyor
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
		// say� negatif ve �ok k�s�rl� olabilece�i i�in mutlak de�erini al�p int deger yap�yoruz.
		basilacakSayi = (int)fabs(radyan);

		basilacakSayi = 10 - basilacakSayi;

		//Fonksiyon grafiginin solunda kalan bo�luklu alan� olu�turuyor
		for (int j = 1; j < basilacakSayi; j++)
			cout << " ";

		//Bo�luklu alandan sonra gelecek y�ld�zlar� bast�r�y�or.
		for (int j = basilacakSayi; j <= 10; j++)
			cout << "*";
	}

	//Deger pozitif ise 
	else
	{
		// Say� k�s�rl� olabilece�i i�in int deger yap�yoruz.
		basilacakSayi = (int)radyan;

		//Negatif ve pozitif degerlerin net ayr�m� olmas� i�in 10 s�ra bo�luk b�rak�yoruz
		for (int j = 1; j < 11; j++)
			cout << " ";

		//Bo�luklu alandan sonra gelecek y�ld�zlar� bast�r�y�or.
		for (int j = 11; j <= basilacakSayi + 11; j++)
			cout << "*";
	}
	cout << endl;
}