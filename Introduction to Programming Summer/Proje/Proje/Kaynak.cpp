/********************************************************************************
							   SAKARYA �N�VERS�TES�
					B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
						 B�LG�SAYAR M�HEND�SL��� B�L�M�
						   PROGRAMLAMAYA G�R�� DERS�

						   �DEV NUMARASI........:Proje
						   ��RENC� ADI..........:MEL�H ENSAR BARI�IK
						   ��RENC� NUMARASI.....:
						   DERS GRUBU...........:A

*********************************************************************************/
#include <iostream>
#include <fstream>
#include<iomanip>
#include <string>
#include <cstring>
#include<locale.h>
#include<locale>
using namespace std;

struct Okuyucu
{
	string Ad;
	string Soyad;
	int Tc;
	string DogumTarihi;
	int Telefon;
	int UyeNo;
	string Gorevi;
	int AlabilecegiKitapSayisi = 10;
};
struct Kitap
{
	int ISBN;
	string KitapIsmi;
	string YazarAdi;
	string YazarSoyadi;
	string Konu;
	string Tur;
	int SayfaSayisi;
};
struct OduncKitap
{
	int ISBN;
	int TCNO;
	string oduncTarihi;
	string donusTarihi;
};

void IslemSecimi();

void OkuyucuKayitEt();
void OkuyucuKayitGuncelle();
void OkuyucuKaydiSil();

void KitapEkle();
void KitapSil();
void KitapGuncelle();

void KitapOduncAlma(); 
void OkuyucuUstundekiKitaplarListesi();
void OkuyucuKitapGeriBirak();


void KitapBilgi(Kitap Kitap1);
void OkuyucuBilgi(Okuyucu Okuyucu2);

void KayitSilindiOduncSil(int);
void OkuyucuAlabilecegiKitapSayisiAzalt(int);
void OkuyucuAlabilecegiKitapSayisiArttir(int);

int OkuyucuNumarasiVer();


int main()
{
	
	setlocale(LC_ALL, "Turkish");

	IslemSecimi();


	system("pause");
}



void IslemSecimi()
{
	
	
	char DevamMi = 'h';

	do{
		int YapilacakIslem;
		cout << "-------------------------------------" << endl;
		cout << "  K�T�PHANE S�STEM�NE HO�GELD�N�Z." << endl;
		cout << "-------------------------------------" << endl;
	cout << "1-Okuyucu Kaydi" << endl;
	cout << "2-Okuyucu Kaydi guncelleme" << endl;
	cout << "3-Okuyucu Silme" << endl;
	cout << "4-Okuyucu Uzerindeki Kitaplar Listesi" << endl;
	cout << "5-Okuyucu Kitap Odunc Alma" << endl;
	cout << "6-Okuyucu Kitap Geri Dondurme" << endl;
	cout << "7-Kitap Ekleme" << endl;
	cout << "8-Kitap Silme" << endl;
	cout << "9-Kitap Kaydi Guncelle" << endl;
	cout << endl;
	cout << "Yapilacak Islem     :"; cin >> YapilacakIslem;

	switch (YapilacakIslem)
	{
	case 1:
		system("CLS"); cout << endl;
		cout << "-------------------------------------" << endl;
		cout << "Okuycu Kay�t Men�s�" << endl;
		cout << "-------------------------------------" << endl;
		cout << endl;
		OkuyucuKayitEt();
		break;
	case 2:
		system("CLS"); cout << endl;
		cout << "-------------------------------------" << endl;
		cout << "Okuycu Kayd� G�ncelleme Men�s�" << endl;
		cout << "-------------------------------------" << endl;
		cout << endl;
		OkuyucuKayitGuncelle();
		break;
	case 3:
		system("CLS"); cout << endl;
		cout << "-------------------------------------" << endl;
		cout << "Okuycu Kayd� Silme Men�s�" << endl;
		cout << "-------------------------------------" << endl;
		cout << endl;
		OkuyucuKaydiSil();
		break;
	case 4:
		system("CLS"); cout << endl;
		cout << "-------------------------------------" << endl;
		cout << "Okuycunun �zerindeki Kitaplar�n Listesi" << endl;
		cout << "-------------------------------------" << endl;
		cout << endl;
		OkuyucuUstundekiKitaplarListesi();
		break;
	case 5:
		system("CLS"); cout << endl;
		cout << "-------------------------------------" << endl;
		cout << "Kitap �d�n� Alma Men�s�" << endl;
		cout << "-------------------------------------" << endl;
		cout << endl;
		KitapOduncAlma();
		break;
	case 6:
		system("CLS"); cout << endl;
		cout << "-------------------------------------" << endl;
		cout << "Kitap Geri Verme Men�s�" << endl;
		cout << "-------------------------------------" << endl;
		cout << endl;
		OkuyucuKitapGeriBirak();
		break;
	case 7:
		system("CLS"); cout << endl;
		cout << "-------------------------------------" << endl;
		cout << "Kitap Ekleme Men�s�" << endl;
		cout << "-------------------------------------" << endl;
		cout << endl;
		KitapEkle();
		break;
	case 8:
		system("CLS"); cout << endl;
		cout << "-------------------------------------" << endl;
		cout << "Kitap Silme Men�s�" << endl;
		cout << "-------------------------------------" << endl;
		cout << endl;
		KitapSil();
		break;
	case 9:
		system("CLS"); cout << endl;
		cout << "-------------------------------------" << endl;
		cout << "Kitap G�ncelleme Men�s�" << endl;
		cout << "-------------------------------------" << endl;
		cout << endl;
		KitapGuncelle();
		break;
	default:
		cout << "YANLIS NUMARA TUSLADINIZ." << endl;
		break;
	}


	cout << "Ba�ka bir i�lem daha yapmak ister misiniz (E/H) ?"; cin >> DevamMi;
	system("CLS");
	} while (DevamMi == 'e' || DevamMi == 'E');
}

void OkuyucuKayitEt()
{
	Okuyucu Okuyucu1;
	Okuyucu Okuyucu2;
	int OkuyucuNumarasi = 0;
	
	// Okuyucunun Numaras� Belirleniyor.
	OkuyucuNumarasi = OkuyucuNumarasiVer();
	
	ofstream DosyaYaz("Okuyucu.txt", ios::out | ios::app);

	// Gerekli Bilgiler �steniyor.
	cout << "Okuyucunun Ad�                         :" << setw(10); cin >> Okuyucu1.Ad;
	cout << "Okuyucunun Soyadi                      :" << setw(10); cin >> Okuyucu1.Soyad;
	cout << "Okuyucunun Tc Numarasi                 :" << setw(10); cin >> Okuyucu1.Tc;
	cout << "Okuyucunun Do�umTarihi (gg/aa/yy)      :" << setw(10); cin >> Okuyucu1.DogumTarihi;
	cout << "Okuyucunun Telefon Numaras�            :" << setw(10); cin >> Okuyucu1.Telefon;
	cout << "Okuyucunun �ye Numaras�                :" << OkuyucuNumarasi << endl;
	cout << "Okuyucunun G�revi                      :" << setw(10); cin >> Okuyucu1.Gorevi;
	cout << "Okuyucunun Alabilece�i Kitap Say�s�    :" << Okuyucu1.AlabilecegiKitapSayisi << endl;

	Okuyucu1.UyeNo = OkuyucuNumarasi;

	//Bilgiler Dosyaya Yaz�l�yor.
	DosyaYaz <<Okuyucu1.Ad <<" " << Okuyucu1.Soyad <<
		" " << Okuyucu1.Tc << " " << Okuyucu1.DogumTarihi << " "
		<< Okuyucu1.Telefon << " " << Okuyucu1.UyeNo <<
		" " << Okuyucu1.Gorevi << " " << Okuyucu1.AlabilecegiKitapSayisi <<"\n";

	DosyaYaz.close();
}
void OkuyucuKayitGuncelle()
{
	Okuyucu OkuyucuKontrol;
	Okuyucu Okuyucu2;
	int ArananTc;
	cout << "G�ncellemek istedi�iniz kullan�c�n�n TC numaras�    :";  cin >> ArananTc;
	ifstream DosyaOku;
	ofstream DosyaYaz;
	DosyaOku.open("Okuyucu.txt", ios::in);
	DosyaYaz.open("Gecici.tmp", ios::out);
	int UyusmaVarMi = 0;
	
	//Dosya sonuna kadar d�nen bir while dong�s� ba�lat�l�yor.
	while (!DosyaOku.eof())
	{
		//Dosya icindeki bilgiler al�n�yor.
		DosyaOku >> Okuyucu2.Ad >> Okuyucu2.Soyad >>
			Okuyucu2.Tc >> Okuyucu2.DogumTarihi >>
			Okuyucu2.Telefon >> Okuyucu2.UyeNo >>
			Okuyucu2.Gorevi >> Okuyucu2.AlabilecegiKitapSayisi;

		// Al�nana bilgi istenen tc ile kar��la�t�r�l�yor.
		if (Okuyucu2.Tc == ArananTc)
		{
			//Okuyucunun g�ncel bilgilerini veriyor.
			cout << "Dosyada var olan bilgiler." << endl;
			OkuyucuBilgi(Okuyucu2);


			// Yeni Bilgiler isteniyor.
			cout << "Yeni bilgiler" << endl;
			cout << "Okuyucunun Ad�                          :"; cin >> Okuyucu2.Ad;
			cout << "Okuyucunun Soyad�                       :"; cin >> Okuyucu2.Soyad;
			cout << "Okuyucunun Tc Numaras�                  :"; cin >> Okuyucu2.Tc;
			cout << "Okuyucunun Do�um Tarihi:                :"; cin >> Okuyucu2.DogumTarihi;
			cout << "Okuyucunun Telefon                      :"; cin >> Okuyucu2.Telefon;
			cout << "Okuyucunun �ye No                       :" << Okuyucu2.UyeNo << endl;
			cout << "Okuyucunun G�revi                       :"; cin >> Okuyucu2.Gorevi;
			cout << "Okuyucunun Alabilecegi Kitap Sayisi     :"; cout << Okuyucu2.AlabilecegiKitapSayisi << endl;

			//Guncelleme kay�t ediliyor.
			DosyaYaz << Okuyucu2.Ad << " " << Okuyucu2.Soyad <<
				" " << Okuyucu2.Tc << " " << Okuyucu2.DogumTarihi << " "
				<< Okuyucu2.Telefon << " " << Okuyucu2.UyeNo <<
				" " << Okuyucu2.Gorevi << " " << Okuyucu2.AlabilecegiKitapSayisi <<"\n";

			UyusmaVarMi=1;
		}
		//Uyu�ma olmayan diger bilgiler de dosyaya yaz�l�yor.
		else
		{
			//Son sat�rda tekrar yaz�lma olay� olmas�n� �nl�yor.
			if (OkuyucuKontrol.Ad != Okuyucu2.Ad)
			{
				
				DosyaYaz << Okuyucu2.Ad << " " << Okuyucu2.Soyad <<
					" " << Okuyucu2.Tc << " " << Okuyucu2.DogumTarihi << " "
					<< Okuyucu2.Telefon << " " << Okuyucu2.UyeNo <<
					" " << Okuyucu2.Gorevi << " " << Okuyucu2.AlabilecegiKitapSayisi << "\n";
				OkuyucuKontrol.Ad = Okuyucu2.Ad;
			}
		}
	}
	
	//Girilen Tc nin sistemde olup olmad���na bak�yor.
	if (UyusmaVarMi == 0)
	{
		cout << "Girilen TC ile uyumlu bir �ye bulunmamaktad�r." << endl;

	}

	DosyaYaz.close(); // Dosyalar kapan�yor.
	DosyaOku.close();
	remove("Okuyucu.txt");//Eski dosya uzakla�t�rl�yor.
	rename("Gecici.tmp", "Okuyucu.txt");// T�m bilgilerin kay�t oldugu yeni dosyan�n ad� degistiriliyor.
}
void OkuyucuKaydiSil()
{
	Okuyucu Okuyucu2;
	Okuyucu OkuyucuKontrol;
	ifstream DosyaOku;
	ofstream DosyaYaz;
	DosyaOku.open("Okuyucu.txt", ios::in);
	DosyaYaz.open("Gecici.txt", ios::out);
	int UyusmaVarMi = 0;

	int ArananTc;
	cout << "Silmek istedi�iniz kullan�c�n�n TC numaras�    :";  cin >> ArananTc;

	//Dosya sonuna kadar d�nen bir while dong�s� ba�lat�l�yor.
	while (!DosyaOku.eof())
	{
		//Dosya icindeki bilgiler al�n�yor.
		DosyaOku >> Okuyucu2.Ad >> Okuyucu2.Soyad >>
			Okuyucu2.Tc >> Okuyucu2.DogumTarihi >>
			Okuyucu2.Telefon >> Okuyucu2.UyeNo >>
			Okuyucu2.Gorevi >> Okuyucu2.AlabilecegiKitapSayisi;

		// Al�nana bilgi istenen tc ile kar��la�t�r�l�yor.
		if (Okuyucu2.Tc == ArananTc)
		{
			system("CLS");
		
			// Silinecek kullanici bilgileri.
			cout << "Silinecek Kullan�c� Bilgilieri " << endl;
			OkuyucuBilgi(Okuyucu2);
			KayitSilindiOduncSil(ArananTc);

			UyusmaVarMi++;
		}
		//Uyu�ma olmayan diger bilgiler de dosyaya yaz�l�yor.
		else
		{
			
			// Son Veri Tekrar�n� �nlemek ��in Kullan�l�yor.
			if (OkuyucuKontrol.Ad != Okuyucu2.Ad)
			{
				DosyaYaz << Okuyucu2.Ad << " " << Okuyucu2.Soyad <<
					" " << Okuyucu2.Tc << " " << Okuyucu2.DogumTarihi << " "
					<< Okuyucu2.Telefon << " " << Okuyucu2.UyeNo <<
					" " << Okuyucu2.Gorevi << " " << Okuyucu2.AlabilecegiKitapSayisi << "\n";

				OkuyucuKontrol.Ad = Okuyucu2.Ad;
			}
	
		}
	}
	if (UyusmaVarMi == 0)
	{
		cout << "Girilen TC ile uyumlu bir �ye bulunmamaktad�r." << endl;

	}

	DosyaOku.close();
	DosyaYaz.close(); // Dosyalar kapan�yor.
	remove("Okuyucu.txt");//Eski dosya uzakla�t�rl�yor.
	rename("Gecici.txt", "Okuyucu.txt");// T�m bilgilerin kay�t oldugu yeni dosyan�n ad� degistiriliyor.
}


void KitapEkle()
{
	Kitap kitap1;

	ofstream DosyaYaz;
	// Kitaplar�n yaz�laca�� kitaplar dosyas� a��l�yor.
	DosyaYaz.open("Kitaplar.txt", ios::out | ios::app);

	//Bilgiler Al�n�yor.
	cout << "Kitab�n ISBN Numaras�       :"<<setw(10); cin >> kitap1.ISBN;
	cout << "Kitab�n Ad�                 : "<<setw(8); cin >> kitap1.KitapIsmi;
	cout << "Kitab�n Yazar�n�n Ad�       :"<<setw(10); cin >> kitap1.YazarAdi;
	cout << "Kitab�n Yazar�n�n Soyad�    :"; cin >> kitap1.YazarSoyadi;
	cout << "Kitab�n Konusu              :"; cin >> kitap1.Konu;
	cout << "Kitab�n T�r�                :"; cin >> kitap1.Tur;
	cout << "Kitab�n Sayfa Say�s�        :"; cin >> kitap1.SayfaSayisi;

	//Dosyaya Yaz�l�yor.
	DosyaYaz << kitap1.ISBN << " " << kitap1.KitapIsmi << " " <<
		kitap1.YazarAdi << " " << kitap1.YazarSoyadi << " "<<
		kitap1.Konu << " " << kitap1.Tur << " "
		<< kitap1.SayfaSayisi <<"\n";

	DosyaYaz.close();


}
void KitapSil()
{
	Kitap kitap1;
	Kitap KitapKontrol;
	KitapKontrol.ISBN = 0;
	int arananISBN;
	int uyusmaVarMi = 0;
	ofstream DosyaYaz;
	ifstream DosyaOku;

	cout << "Silmek istedi�iniz kitab�n ISBN numaras�n� giriniz  :"; cin >> arananISBN;
	DosyaOku.open("Kitaplar.txt");
	DosyaYaz.open("GeciciKitap.txt");

	while (!DosyaOku.eof())
	{
		DosyaOku >> kitap1.ISBN >> kitap1.KitapIsmi >>
			kitap1.YazarAdi >> kitap1.YazarSoyadi >>
			kitap1.Konu >> kitap1.Tur >> kitap1.SayfaSayisi;

		if (arananISBN == kitap1.ISBN && KitapKontrol.ISBN != kitap1.ISBN)
		{
			KitapKontrol.ISBN = kitap1.ISBN;
			//Silinecek Bilgiler
			KitapBilgi(kitap1);
			uyusmaVarMi++;
		}
	
		else
		{
			// Silinecek kitap hari� kalanlar dosyaya yazilacak
			uyusmaVarMi++;
			
			if (KitapKontrol.ISBN != kitap1.ISBN)
			{
				DosyaYaz << kitap1.ISBN << " " << kitap1.KitapIsmi << " " <<
					kitap1.YazarAdi << " " << kitap1.YazarSoyadi << " " <<
					kitap1.Konu << " " << kitap1.Tur << " "
					<< kitap1.SayfaSayisi << "\n";

				KitapKontrol.ISBN = kitap1.ISBN;
			}
				
			

			
			

		}
		if (uyusmaVarMi == 1)
		{
			cout << "Arad���n�z ISBN numaras�nda bir kitap bulunamad�." << endl; cout << endl;
		}

	}

	DosyaYaz.close();
	DosyaOku.close();
	

	remove("Kitaplar.txt");
	rename("GeciciKitap.txt", "Kitaplar.txt");
}
void KitapGuncelle()
{
	Kitap Kitap1;
	int ArananISBN;
	int uyusmaVarMi = 0;
	OduncKitap OduncKontrol;
	OduncKontrol.ISBN = 0;

	ofstream DosyaYaz;
	ifstream DosyaOku;

	DosyaYaz.open("GeciciKitapGuncelle.txt", ios::out);
	DosyaOku.open("Kitaplar.txt", ios::in);

	cout << "Guncellemek istediginiz ISBN numarasini yaziniz  : "; cin >> ArananISBN;

	while (!DosyaOku.eof())
	{
		//Kitap dosyas�ndaki bilgilere bak�l�yor.
		DosyaOku >> Kitap1.ISBN >> Kitap1.KitapIsmi
			>> Kitap1.YazarAdi >> Kitap1.YazarSoyadi
			>> Kitap1.Konu >> Kitap1.Tur
			>> Kitap1.SayfaSayisi;

		//ArananISBN ile her bir bilgi kar��la�t�r�l�yor.
		if (ArananISBN == Kitap1.ISBN && OduncKontrol.ISBN!=Kitap1.ISBN)
		{
			KitapBilgi(Kitap1);


			cout << "Yeni Bilgiler" << endl;
			cout << "Kitab�n ISBN           :"; cin >> Kitap1.ISBN;
			cout << "Kitab�n Ad�            :"; cin >> Kitap1.KitapIsmi;
			cout << "Kitab�n Yazar�n�n Ad�  :"; cin >> Kitap1.YazarAdi;
			cout << "Kitab�n Soyad          :"; cin >> Kitap1.YazarSoyadi;
			cout << "Kitab�n Konusu         :"; cin >> Kitap1.Konu;
			cout << "Kitab�n T�r�           :"; cin >> Kitap1.Tur;
			cout << "Kitab�n Sayfa Say�s�   :"; cin >> Kitap1.SayfaSayisi;

			//E�itli�in oldugu kitap g�ncelleniyor.
			DosyaYaz << Kitap1.ISBN << " " << Kitap1.KitapIsmi
				<< " " << Kitap1.YazarAdi << " " << Kitap1.YazarSoyadi
				<< " " << Kitap1.Konu << " " << Kitap1.Tur << " "
				<< Kitap1.SayfaSayisi << "\n";
			uyusmaVarMi++;
			OduncKontrol.ISBN = Kitap1.ISBN;
		}
		else
		{
			//E�itlik yok ise kitaplar oldugu gibi yeni dosyaya yaz�l�yor.

				
			// Son 2 kitap ayn� ise son kitap bilgileri yaz�lm�yor ( son sat�r hatas�)
			if (OduncKontrol.ISBN != Kitap1.ISBN)
			{
				DosyaYaz << Kitap1.ISBN << " " << Kitap1.KitapIsmi
					<< " " << Kitap1.YazarAdi << " " << Kitap1.YazarSoyadi
					<< " " << Kitap1.Konu << " " << Kitap1.Tur << " "
					<< Kitap1.SayfaSayisi << "\n";
				OduncKontrol.ISBN = Kitap1.ISBN;
			}
		}
		
		
	}
	if (uyusmaVarMi == 0)
	{

		cout << "Arad���n�z ISBN numaras�nda bir kitap bulunamad�." << endl; cout << endl;
	}
	DosyaYaz.close(); // Dosyalar kapan�yor.
	DosyaOku.close();
	remove("Kitaplar.txt");//Eski dosya uzakla�t�rl�yor.
	rename("GeciciKitapGuncelle.txt", "Kitaplar.txt");// T�m bilgilerin kay�t oldugu yeni dosyan�n ad� degistiriliyor

}



void KitapOduncAlma()
{
	Okuyucu Okuyucu2;
	Kitap Kitap1;
	OduncKitap OduncKitap1;

	int arananTC;
	int arananISBN;
	int KitapBostaMi = 0;
	int kontrol = 0;
	int uyusmaVarMi = 0;

	cout << "TC kimlik numaran�z� giriniz  :"; cin >> arananTC; cout << endl; cout << endl;

	ifstream DosyaOku;
	DosyaOku.open("Okuyucu.txt", ios::in);

	//Okuyucu Dosyas�n�n i�inde geziyor.
	while (!DosyaOku.eof())
	{


		DosyaOku >> Okuyucu2.Ad >> Okuyucu2.Soyad >>
			Okuyucu2.Tc >> Okuyucu2.DogumTarihi >>
			Okuyucu2.Telefon >> Okuyucu2.UyeNo >>
			Okuyucu2.Gorevi >> Okuyucu2.AlabilecegiKitapSayisi;

		
		// Girilen Kimlik numaras� sistemde var m� diye kontrol ediyor.
		if (arananTC == Okuyucu2.Tc)
		{
			DosyaOku.close();
			uyusmaVarMi++;

			cout << "Say�n :" << Okuyucu2.Ad << " "
				<< Okuyucu2.Soyad << " " << endl;

			


			cout << "Almak istedi�iniz kitabin ISBN numaras�n� giriniz :"; cin >> arananISBN;
			cout << endl;

			DosyaOku.open("Kitaplar.txt");
			// Kitaplar Dosyas� i�inde sonuna gelene kadar d�n�yor.
			while (!DosyaOku.eof())
			{

				DosyaOku >> Kitap1.ISBN >> Kitap1.KitapIsmi
					>> Kitap1.YazarAdi >> Kitap1.YazarSoyadi
					>> Kitap1.Konu >> Kitap1.Tur
					>> Kitap1.SayfaSayisi;
	
			   // Aranan Kitab�n ISBN numaras� sistemde var m� kontrol ediliyor.
				if (Kitap1.ISBN == arananISBN && KitapBostaMi == 0)
				{
					KitapBostaMi++;

					DosyaOku.close();

					
					DosyaOku.open("Odunc.txt");
					// Odunc dosyas�nda d�n�yor.
					while (!DosyaOku.eof())
					{
						DosyaOku >> OduncKitap1.ISBN >> OduncKitap1.TCNO >> OduncKitap1.oduncTarihi >> OduncKitap1.donusTarihi;
						
						//E�er aranan ISBN Odunc dosyas�nda varsa kitap ba�ka kullan�c�da oldu�u i�in isteyene verilmiyor.
						if (arananISBN == OduncKitap1.ISBN)
						{
							
							kontrol++;
							cout << "Almak istedi�iniz " << arananISBN << " ISBN nolu kitap �u an ba�ka bir kullan�c�da" << endl;
							cout << "Kitab� " << OduncKitap1.donusTarihi << " tarihinde alabilirsiniz." << endl; cout << endl;
							break;
							
						}


					}
					if (kontrol == 0)
					{
						KitapBilgi(Kitap1);

						cout << "Kitab�n Odun� Al�nma Tarihini Giriniz. (gg/aa/yy):  "; cin >> OduncKitap1.oduncTarihi;
						cout << "Kitab�n Geri D�nme Tarihini Giriniz. (gg/aa/yy):    "; cin >> OduncKitap1.donusTarihi;


						
					
							ofstream DosyaYaz;
							DosyaYaz.open("Odunc.txt",ios::app);
							DosyaYaz << Kitap1.ISBN << " " << Okuyucu2.Tc << " " << OduncKitap1.oduncTarihi << " " << OduncKitap1.donusTarihi << "\n";
							DosyaYaz.close();

							
							Okuyucu2.AlabilecegiKitapSayisi--;
							cout << "Alabileci�iniz Kitap Say�s�  :" << Okuyucu2.AlabilecegiKitapSayisi<< endl;
							
							OkuyucuAlabilecegiKitapSayisiAzalt(Okuyucu2.Tc);
							
							
					}
				

				}
				
			}
			if (KitapBostaMi == 0)
			{
				KitapBostaMi++;
				cout << "Arad���n�z ISBN numaras� sistemde bulunmamaktad�r." << endl;
			}


		}
	}
	if (uyusmaVarMi == 0)
	{
		uyusmaVarMi++;
		cout << "Girdi�iniz Tc kimlik numarasina ait bir �ye bulunamadi." << endl; cout << endl;

	}


}
void OkuyucuUstundekiKitaplarListesi()
{
	OduncKitap OduncKontrol;
	Kitap Kitap1;
	int arananTC;
	OduncKitap Odunc1;
	OduncKontrol.ISBN = 0;
	int kontrol = 0;
	cout << "Sahip oldu�unuz kitaplar� ��renmek i�in TC numaran�z� giriniz :"; cin >> arananTC;

	ifstream DosyaOku;
	ifstream DosyaOku2;
	DosyaOku.open("Odunc.txt");
	while (!DosyaOku.eof())
	{
		DosyaOku >> Odunc1.ISBN >> Odunc1.TCNO >> Odunc1.oduncTarihi >> Odunc1.donusTarihi;

		
		//aranan TC numaras� �d�n�te var ise okuyucu kitap alm�� demektir.
		if (arananTC == Odunc1.TCNO)
		{
			

			kontrol++;
			
			DosyaOku2.open("Kitaplar.txt");
			while (!DosyaOku2.eof())
			{
				// Odunc de verilen tc kimlik numaras�na ait �sbn numaral� kitaplar bilgi yazd�rmak i�in Kitaplar dosyas�nda aran�yor.
				DosyaOku2 >> Kitap1.ISBN >> Kitap1.KitapIsmi
					>> Kitap1.YazarAdi >> Kitap1.YazarSoyadi
					>> Kitap1.Konu >> Kitap1.Tur
					>> Kitap1.SayfaSayisi;
				
				if (Odunc1.ISBN == Kitap1.ISBN && OduncKontrol.ISBN!=Odunc1.ISBN)
				{
					
					cout << arananTC << "TC numaral� kullan�c�n�n �u an sahip oldu�u kitap :" << endl; cout << endl;
					KitapBilgi(Kitap1);
					OduncKontrol.ISBN = Odunc1.ISBN;
					
				}
				
			}
			DosyaOku2.close();
		}
	}
	DosyaOku.close();
	
	//Program e�le�me bulamazsa mesaj� yazd�r�yor.
	     if(kontrol==0)
		 { 
		cout << "Girilen TC numaras� �zerine kay�tl� bir kitap bulunamad�." << endl;
		 }
 
}
void OkuyucuKitapGeriBirak()
{
	OduncKitap Odunc1;
	int KontrolISBN = 0	;
	int arananTC;
	int BirakilacakISBN;
	int KontrolTek = 0;

	cout << "L�tfen tc kimlik numaran�z� giriniz                  :"; cin>>arananTC;
	cout << "B�rakmak isted�iniz kitab�n ISBN numaras�n� giriniz  :"; cin >> BirakilacakISBN;

	ifstream DosyaOku;
	DosyaOku.open("Odunc.txt");

	ofstream DosyaYaz;
	DosyaYaz.open("GeciciOdunc.txt");

	//Odunc dosyas�nda geziniyor.
	while (!DosyaOku.eof())
	{
		DosyaOku >> Odunc1.ISBN >> Odunc1.TCNO >> Odunc1.oduncTarihi >> Odunc1.donusTarihi;

		// arananTc nin odunc dosyas�nda olup olmad���na ve ISBN numaras�n�n uyumuna bak�yor.
		if (arananTC == Odunc1.TCNO && Odunc1.ISBN==BirakilacakISBN)
		{
			KontrolTek++;
			if (KontrolISBN != Odunc1.ISBN)
			{
				cout << Odunc1.ISBN << " ISBN numaras�na sahip kitab� geri b�rakt�n�z." << endl;
				OkuyucuAlabilecegiKitapSayisiArttir(arananTC);
				KontrolISBN = Odunc1.ISBN;
			}
		}
		else
		{
			DosyaYaz << Odunc1.ISBN << " " << Odunc1.TCNO << " " << Odunc1.oduncTarihi << " " << Odunc1.donusTarihi << "\n";
		}
	
	}
	if (KontrolTek == 0)
	{
		cout << "Girilen TC numaras� veya ISBN hatal�" << endl;
	}
	DosyaOku.close();
	DosyaYaz.close();
		remove("Odunc.txt");
		rename("GeciciOdunc.txt", "Odunc.txt");
	
}





void KitapBilgi(Kitap Kitap1)
{
	cout << "Kitap Bilgileri " << endl;
	cout << "Kitap ISBN :" << Kitap1.ISBN << endl
		<< "Kitap ismi :" << Kitap1.KitapIsmi << endl
		<< "Kitap yazar adi :" << Kitap1.YazarAdi << endl
		<< "Kitap yazar soyadi" << Kitap1.YazarSoyadi << endl
		<< "Kitap konusu :" << Kitap1.Konu << endl
		<< "Kitap turu :" << Kitap1.Tur << endl
		<< "Kitap sayfa sayisi :" << Kitap1.SayfaSayisi << endl;
}
void OkuyucuBilgi(Okuyucu Okuyucu2)
{
	/*system("CLS");*/
	// Elimizde bulunan kayda ait bilgiler.
	
	cout	<< "Okuyucunun Ad�                        : " << Okuyucu2.Ad << " " << endl
		<< "Okuyucunun Soyad�                     :" << Okuyucu2.Soyad << " " << endl
		<< "Okuyucunun Tc Numaras�                :" << Okuyucu2.Tc << " " << endl
		<< "Okuyucunun Do�um Tarihi (gg/aa/yy)    :" << Okuyucu2.DogumTarihi << " " << endl
		<< "Okuyucunun Telefon Numaras�           :" << Okuyucu2.Telefon << " " << endl
		<< "Okuyucunun �ye Numaras�               :" << Okuyucu2.UyeNo << " " << endl
		<< "Okuyucunun G�revi                     :" << Okuyucu2.Gorevi << " " << endl
		<< "Okuyucunun Alabilece�i Kitap Sayisi   :" << Okuyucu2.AlabilecegiKitapSayisi << endl;
}

void KayitSilindiOduncSil(int TC)
{
	OduncKitap KontrolKitap;
	OduncKitap Odunc1;
	ifstream DosyaOku;
	DosyaOku.open("Odunc.txt");
	
	ofstream DosyazYaz;
	DosyazYaz.open("GeciciOdunc.txt");
	while (!DosyaOku.eof())
	{
		while (DosyaOku >> Odunc1.ISBN >> Odunc1.TCNO >> Odunc1.oduncTarihi >> Odunc1.donusTarihi)
		{
			
			if (TC == Odunc1.TCNO)
			{
				cout << endl;
				cout << "Sistemde Kay�tl� Olan " << Odunc1.ISBN << " nolu kitab�n�z geri b�rak�lm��t�r" << endl;
			}
			else
			{
				if (KontrolKitap.ISBN != Odunc1.ISBN)
				{
					DosyazYaz << Odunc1.ISBN << " " << Odunc1.TCNO << " " << Odunc1.oduncTarihi << " " << Odunc1.donusTarihi << "\n";
					KontrolKitap.ISBN = Odunc1.ISBN;
				}

			}

		}
	}
	DosyaOku.close();
	DosyazYaz.close();
	remove("Odunc.txt");
	rename("GeciciOdunc.txt", "Odunc.txt");
}
void OkuyucuAlabilecegiKitapSayisiAzalt(int TC)
{
	Okuyucu OkuyucuKontrol;
	Okuyucu Okuyucu1;
	ifstream DosyaOku;
	ofstream DosyaYaz;

	DosyaOku.open("Okuyucu.txt");
	DosyaYaz.open("GeciciOkuyucu.txt");

	

	while (!DosyaOku.eof())
	{
		DosyaOku >> Okuyucu1.Ad >> Okuyucu1.Soyad >>
			Okuyucu1.Tc >> Okuyucu1.DogumTarihi >>
			Okuyucu1.Telefon >> Okuyucu1.UyeNo >>
			Okuyucu1.Gorevi >> Okuyucu1.AlabilecegiKitapSayisi; 
		
		
		
		if (Okuyucu1.Tc==TC)
		{
			Okuyucu1.AlabilecegiKitapSayisi--;
		

			DosyaYaz << Okuyucu1.Ad << " " << Okuyucu1.Soyad <<
				" " << Okuyucu1.Tc << " " << Okuyucu1.DogumTarihi << " "
				<< Okuyucu1.Telefon << " " << Okuyucu1.UyeNo <<
				" " << Okuyucu1.Gorevi << " " << Okuyucu1.AlabilecegiKitapSayisi << "\n";
			
		}
		else {

			if(OkuyucuKontrol.Tc !=Okuyucu1.Tc)
			
			DosyaYaz << Okuyucu1.Ad << " " << Okuyucu1.Soyad <<
				" " << Okuyucu1.Tc << " " << Okuyucu1.DogumTarihi << " "
				<< Okuyucu1.Telefon << " " << Okuyucu1.UyeNo <<
				" " << Okuyucu1.Gorevi << " " << Okuyucu1.AlabilecegiKitapSayisi << "\n";
			OkuyucuKontrol.Tc = Okuyucu1.Tc;
		}
	}
	DosyaYaz.close();
	DosyaOku.close();
	remove("Okuyucu.txt");
	rename("GeciciOkuyucu.txt","Okuyucu.txt");
}
void OkuyucuAlabilecegiKitapSayisiArttir(int TC)
{
	Okuyucu OkuyucuKontrol;
	Okuyucu Okuyucu1;
	ifstream DosyaOku;
	ofstream DosyaYaz;

	DosyaOku.open("Okuyucu.txt");
	DosyaYaz.open("GeciciOkuyucu.txt");



	while (!DosyaOku.eof())
	{
		DosyaOku >> Okuyucu1.Ad >> Okuyucu1.Soyad >>
			Okuyucu1.Tc >> Okuyucu1.DogumTarihi >>
			Okuyucu1.Telefon >> Okuyucu1.UyeNo >>
			Okuyucu1.Gorevi >> Okuyucu1.AlabilecegiKitapSayisi;



		if (Okuyucu1.Tc == TC)
		{
			Okuyucu1.AlabilecegiKitapSayisi++;


			DosyaYaz << Okuyucu1.Ad << " " << Okuyucu1.Soyad <<
				" " << Okuyucu1.Tc << " " << Okuyucu1.DogumTarihi << " "
				<< Okuyucu1.Telefon << " " << Okuyucu1.UyeNo <<
				" " << Okuyucu1.Gorevi << " " << Okuyucu1.AlabilecegiKitapSayisi << "\n";
		}
		else {

			if (OkuyucuKontrol.Tc != Okuyucu1.Tc)

				DosyaYaz << Okuyucu1.Ad << " " << Okuyucu1.Soyad <<
				" " << Okuyucu1.Tc << " " << Okuyucu1.DogumTarihi << " "
				<< Okuyucu1.Telefon << " " << Okuyucu1.UyeNo <<
				" " << Okuyucu1.Gorevi << " " << Okuyucu1.AlabilecegiKitapSayisi << "\n";
			OkuyucuKontrol.Tc = Okuyucu1.Tc;
		}
	}
	DosyaYaz.close();
	DosyaOku.close();
	remove("Okuyucu.txt");
	rename("GeciciOkuyucu.txt", "Okuyucu.txt");
}


int OkuyucuNumarasiVer()
{
	Okuyucu Okuyucu2;
	ifstream DosyaOku("Okuyucu.txt");
	ifstream DosyaOku1("Okuyucu.txt");
	int okuyucuNumarasi = 0;
	while (!DosyaOku.eof())
	{
		DosyaOku >> Okuyucu2.Ad >> Okuyucu2.Soyad >>
			Okuyucu2.Tc >> Okuyucu2.DogumTarihi >>
			Okuyucu2.Telefon >> Okuyucu2.UyeNo >>
			Okuyucu2.Gorevi >> Okuyucu2.AlabilecegiKitapSayisi;

		okuyucuNumarasi++;
     }


	while (!DosyaOku1.eof())
	{
		
		DosyaOku1 >> Okuyucu2.Ad >> Okuyucu2.Soyad >>
			Okuyucu2.Tc >> Okuyucu2.DogumTarihi >>
			Okuyucu2.Telefon >> Okuyucu2.UyeNo >>
			Okuyucu2.Gorevi >> Okuyucu2.AlabilecegiKitapSayisi;

		

		if (okuyucuNumarasi <= Okuyucu2.UyeNo)
		{
			okuyucuNumarasi = Okuyucu2.UyeNo;
			okuyucuNumarasi++;
	     }
	}
	

	return okuyucuNumarasi;
}
