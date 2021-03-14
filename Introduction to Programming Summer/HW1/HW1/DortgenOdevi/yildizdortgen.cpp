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
	int yukselik;
	int genislik;

	cout << "Lutfen yuksekligi giriniz....:"; cin >> yukselik;
	cout << "Lutfen genisligi  giriniz.....:"; cin >> genislik;

	//Genislik sýfýr veya negartif olamaz
	while (genislik == 0 || genislik < 0)
	{
		cout << "Genislik sifir veya negatif olamaz baska bir deger giriniz."; cin >> genislik;
	}
	//Yukseklik sýfýr olamaz
	while (yukselik == 0 || yukselik < 0)
	{
		cout << "Yukseklik sifir veya negatif olamaz baska bir deger giriniz."; cin >> yukselik;
	}

	// Girilen yukseklik kadar satýr dolaþýr
	for (int i = 0; i < yukselik ; i++)
	{
		// Ýlk ve son satýra genislik kadar yýldýz yapar
		if (i == 0 || i == yukselik-1 )
		{
		
				for (int i = 0; i < genislik; i++)
				{
					cout << "*";
				}

		}

		//Ýlk ve son satýr haricinde baþý ve sonunda 1 yýldýz olan ici bos bir sýra yapar
		else
		{
			cout << "*";

			for (int j = 0; j < genislik-2; j++)
			{

				cout << " ";

			}

			cout << "*";
		}

		cout << endl;
	}
	system("pause");
}