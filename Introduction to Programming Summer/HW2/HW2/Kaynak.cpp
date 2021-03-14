/********************************************************************************
							   SAKARYA ÜNÝVERSÝTESÝ
					BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
						 BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
						   PROGRAMLAMAYA GÝRÝÞ DERSÝ

						   ÖDEV NUMARASI........:2.ÖDEV
						   ÖÐRENCÝ ADI..........:MELÝH ENSAR BARIÞIK
						   ÖÐRENCÝ NUMARASI.....:
						   DERS GRUBU...........:A

*********************************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include<ctype.h>
#include<conio.h>
#include <sstream>
#include<locale.h>
using namespace std;

int pozitifHesapla(string, string);
int negatifHesapla(string, string);
int puanHesapla(int,int,int);
string randomSayiUret();
bool KazandiKaybetti(int,string,string,int);
string KullaniciKontrol(string);
string SayiTekrarKontrol(string);


int main()
{
	setlocale(LC_ALL, "Turkish");

	string TutulanSayi; 
	string KullanicininDenedigi;
	int hak = 1;
	int ToplamPozitif = 0;
	int ToplamNegatif = 0;
	int puan = 0;
	bool sonuc = 0;

	//4 basamklý sayýlar üretiyor.
	
	TutulanSayi = randomSayiUret();
	TutulanSayi = SayiTekrarKontrol(TutulanSayi);

	
	cout << "------------------------------------------------------------------------------------------------------------------------";
	cout << "\t \t \t \t \t Oyunumuza Hosgeldiniz." << endl;
	cout << "\t \t Bilgisayarýn tuttuðu 4 rakamlý bir sayýyý 10 hakta bilmeye çalýþacaksýnýz." << endl;
	cout << "\t \t \t \t \t      ÝYÝ ÞANSLAR" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;


	// Verilen 10 hak biter veya kullanýcý degeri bulursa while sonlanacak.
	while (hak != 11 && sonuc==0)
	{
		int pozitif;
		int negatif;

		cout << hak << ".hak :" << "Sayiyi Giriniz :"; cin >> KullanicininDenedigi; 

		// Kullanýcýnýn girdiði deðerin sayý olmasýný saðlayan fonksiyon
		KullanicininDenedigi = KullaniciKontrol(KullanicininDenedigi);

		// Puan hesaplamada kullanýlýcak olan artý(+) ve eksi(-) degerleri hesaplanýyor.
		pozitif = pozitifHesapla(TutulanSayi,KullanicininDenedigi);
		negatif = negatifHesapla(TutulanSayi,KullanicininDenedigi);

		
		cout << negatif << " " << pozitif << endl;

		ToplamPozitif += pozitif;
		ToplamNegatif += negatif;
		
		hak++;

		// Puan hesaplamasý için gerekli olan degerleri fonksiyona yolluyorum.
		puan = puanHesapla(ToplamPozitif, ToplamNegatif, hak - 1);

		// Her döngü döndüðünde hakkýn bitip bitmediðini veya sayýnýn dogru tahmin edilip edilmediðine bakýyor.
		//Bakýlan deðer bool ile (0-1) geri geliyor ve while içinde kontrol ediliyor.
	    sonuc= KazandiKaybetti(hak,TutulanSayi,KullanicininDenedigi,puan);
	}
	
	system("pause");
}


int pozitifHesapla(string TutulanSayi, string KullanicininDenedigi)
{
	int pozitif = 0;
	

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			//Eðer sistemin tuttugu ve kullanýcýnýn yazdýgý sayýlar içinde ayný ve ayný sýrada olan sayý/sayýlar var ise artý (+) 1 yazýyor.
			if (TutulanSayi[i] == KullanicininDenedigi[j] && i == j)
			{
				pozitif++;
			}
		}
	}
	return pozitif;
}
int negatifHesapla(string TutulanSayi, string KullanicininDenedigi)
{
	int negatif = 0;


	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			//Eðer sistemin tuttugu ve kullanýcýnýn yazdýgý sayýlar içinde ayný ve farklý sýrada olan sayý/sayýlar var ise eksi(-) 1 yazýyor.
			if (TutulanSayi[i] == KullanicininDenedigi[j] && i != j)
			{
				negatif--;
			}
		}
	}
	return negatif;
}
int puanHesapla(int pozitif, int negatif,int hak)
{
	//puan hesaplanýyor.
	if (pozitif + negatif == 0)
	{
		return (10 * pozitif) + (5 * negatif) + (1000 / hak);
	}
	else
	{
		return (10 * pozitif) + (5 * negatif) + (1000 / hak) - ((pozitif*negatif) / (pozitif + negatif));
	}

}
string randomSayiUret()
{
	// 4 basamklý sayýlar üretiyor.
	int IrandomSayi;
	string SrandomSayi;
	srand(time(NULL));
	IrandomSayi = rand() % 9000 + 1000;
	SrandomSayi = to_string(IrandomSayi);
	return SrandomSayi;
}
bool KazandiKaybetti(int hak,string IstenenDeger, string GirilenDeger,int puan)
{
	//Deðerler birbirine eþit ise kullanýcý buldu anlamýna geliyor.
	if (IstenenDeger == GirilenDeger)
	{
		system("CLS");
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	    cout << "\t \t \t \t \t \t TEBRIKLER BULDUNUZ " << endl << "\t \t \t \t \t \t SAYI :" << IstenenDeger << endl;
		cout << "\t \t \t \t \t \t PUANINIZ :" << puan << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		return 1;
	
	
	}
	// Hak sayýsý 10u geçti ise (11) oyun bitiyor.
	if (hak == 11)
	{
		system("CLS");
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "\t \t \t \t \t \t UZGUNUM BULAMADINIZ " << endl << "\t \t \t \t \t \t SAYININ DEGERI :" << IstenenDeger << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		return 1;
	}
	return 0;
}
string KullaniciKontrol(string GirilenDeger)
{
	int uzunluk=GirilenDeger.length();
	
	//Tum rakamlarý tek tek kontrol ediyor.
	for (int i = 0; i < uzunluk; i++)
	{
		// isdigit yardýmý ile deðerlerin rakam olup olmadýðý kontrol ediliyor.
		if (!isdigit(GirilenDeger[i]))
		{
			cout << "GIRDIGINIZ DEGER SADECE RAKAMLARDAN OLUSMALI !!!!!" << endl;
			cout << "Lutfen yeni bir deger deneyin :"; cin >> GirilenDeger;
			uzunluk = GirilenDeger.length();
		}
	}
	return GirilenDeger;
}
string SayiTekrarKontrol(string sayi)
{

	srand(time(0));
	int geciciDeger = rand() % 9 + 49;
	sayi[0] = geciciDeger;
	int sayac = 0;
	// sayýmýz 4 basamaklý oldugu icin 4 kez dönüyor.
	for (int i = 1; i < 5; i++) 
	{
		do {
			sayac = 0;

			// 0-9 arasý geçici deðer oluþturuyor.
			geciciDeger = rand() % 9 + 48; 

			//sayýnýn harflerini karþýlaþtýrýyor.
			for (int j = 0; j < i; j++)
			{
				//eþitlik varsa sayac artýyor ve while devam ediyor.
				if (geciciDeger == sayi[j])
				{
					sayac++;
				}
			}

		} while (sayac > 0); // karþýlaþtýrma yaptýðýmýz sayýlar eþit oldugu sürece devam ediyor.

		sayi[i] = geciciDeger;
	}
	return sayi;

}
