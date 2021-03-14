/********************************************************************************
							   SAKARYA �N�VERS�TES�
					B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
						 B�LG�SAYAR M�HEND�SL��� B�L�M�
						   PROGRAMLAMAYA G�R�� DERS�

						   �DEV NUMARASI........:2.�DEV
						   ��RENC� ADI..........:MEL�H ENSAR BARI�IK
						   ��RENC� NUMARASI.....:
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

	//4 basamkl� say�lar �retiyor.
	
	TutulanSayi = randomSayiUret();
	TutulanSayi = SayiTekrarKontrol(TutulanSayi);

	
	cout << "------------------------------------------------------------------------------------------------------------------------";
	cout << "\t \t \t \t \t Oyunumuza Hosgeldiniz." << endl;
	cout << "\t \t Bilgisayar�n tuttu�u 4 rakaml� bir say�y� 10 hakta bilmeye �al��acaks�n�z." << endl;
	cout << "\t \t \t \t \t      �Y� �ANSLAR" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;


	// Verilen 10 hak biter veya kullan�c� degeri bulursa while sonlanacak.
	while (hak != 11 && sonuc==0)
	{
		int pozitif;
		int negatif;

		cout << hak << ".hak :" << "Sayiyi Giriniz :"; cin >> KullanicininDenedigi; 

		// Kullan�c�n�n girdi�i de�erin say� olmas�n� sa�layan fonksiyon
		KullanicininDenedigi = KullaniciKontrol(KullanicininDenedigi);

		// Puan hesaplamada kullan�l�cak olan art�(+) ve eksi(-) degerleri hesaplan�yor.
		pozitif = pozitifHesapla(TutulanSayi,KullanicininDenedigi);
		negatif = negatifHesapla(TutulanSayi,KullanicininDenedigi);

		
		cout << negatif << " " << pozitif << endl;

		ToplamPozitif += pozitif;
		ToplamNegatif += negatif;
		
		hak++;

		// Puan hesaplamas� i�in gerekli olan degerleri fonksiyona yolluyorum.
		puan = puanHesapla(ToplamPozitif, ToplamNegatif, hak - 1);

		// Her d�ng� d�nd���nde hakk�n bitip bitmedi�ini veya say�n�n dogru tahmin edilip edilmedi�ine bak�yor.
		//Bak�lan de�er bool ile (0-1) geri geliyor ve while i�inde kontrol ediliyor.
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
			//E�er sistemin tuttugu ve kullan�c�n�n yazd�g� say�lar i�inde ayn� ve ayn� s�rada olan say�/say�lar var ise art� (+) 1 yaz�yor.
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
			//E�er sistemin tuttugu ve kullan�c�n�n yazd�g� say�lar i�inde ayn� ve farkl� s�rada olan say�/say�lar var ise eksi(-) 1 yaz�yor.
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
	//puan hesaplan�yor.
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
	// 4 basamkl� say�lar �retiyor.
	int IrandomSayi;
	string SrandomSayi;
	srand(time(NULL));
	IrandomSayi = rand() % 9000 + 1000;
	SrandomSayi = to_string(IrandomSayi);
	return SrandomSayi;
}
bool KazandiKaybetti(int hak,string IstenenDeger, string GirilenDeger,int puan)
{
	//De�erler birbirine e�it ise kullan�c� buldu anlam�na geliyor.
	if (IstenenDeger == GirilenDeger)
	{
		system("CLS");
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	    cout << "\t \t \t \t \t \t TEBRIKLER BULDUNUZ " << endl << "\t \t \t \t \t \t SAYI :" << IstenenDeger << endl;
		cout << "\t \t \t \t \t \t PUANINIZ :" << puan << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		return 1;
	
	
	}
	// Hak say�s� 10u ge�ti ise (11) oyun bitiyor.
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
	
	//Tum rakamlar� tek tek kontrol ediyor.
	for (int i = 0; i < uzunluk; i++)
	{
		// isdigit yard�m� ile de�erlerin rakam olup olmad��� kontrol ediliyor.
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
	// say�m�z 4 basamakl� oldugu icin 4 kez d�n�yor.
	for (int i = 1; i < 5; i++) 
	{
		do {
			sayac = 0;

			// 0-9 aras� ge�ici de�er olu�turuyor.
			geciciDeger = rand() % 9 + 48; 

			//say�n�n harflerini kar��la�t�r�yor.
			for (int j = 0; j < i; j++)
			{
				//e�itlik varsa sayac art�yor ve while devam ediyor.
				if (geciciDeger == sayi[j])
				{
					sayac++;
				}
			}

		} while (sayac > 0); // kar��la�t�rma yapt���m�z say�lar e�it oldugu s�rece devam ediyor.

		sayi[i] = geciciDeger;
	}
	return sayi;

}
