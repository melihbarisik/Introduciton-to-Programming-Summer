/********************************************************************************
							   SAKARYA ÜNÝVERSÝTESÝ
					BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
						 BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
						   PROGRAMLAMAYA GÝRÝÞ DERSÝ

						   ÖDEV NUMARASI........:Proje
						   ÖÐRENCÝ ADI..........:MELÝH ENSAR BARIÞIK
						   ÖÐRENCÝ NUMARASI.....:
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
		cout << "  KÜTÜPHANE SÝSTEMÝNE HOÞGELDÝNÝZ." << endl;
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
		cout << "Okuycu Kayýt Menüsü" << endl;
		cout << "-------------------------------------" << endl;
		cout << endl;
		OkuyucuKayitEt();
		break;
	case 2:
		system("CLS"); cout << endl;
		cout << "-------------------------------------" << endl;
		cout << "Okuycu Kaydý Güncelleme Menüsü" << endl;
		cout << "-------------------------------------" << endl;
		cout << endl;
		OkuyucuKayitGuncelle();
		break;
	case 3:
		system("CLS"); cout << endl;
		cout << "-------------------------------------" << endl;
		cout << "Okuycu Kaydý Silme Menüsü" << endl;
		cout << "-------------------------------------" << endl;
		cout << endl;
		OkuyucuKaydiSil();
		break;
	case 4:
		system("CLS"); cout << endl;
		cout << "-------------------------------------" << endl;
		cout << "Okuycunun Üzerindeki Kitaplarýn Listesi" << endl;
		cout << "-------------------------------------" << endl;
		cout << endl;
		OkuyucuUstundekiKitaplarListesi();
		break;
	case 5:
		system("CLS"); cout << endl;
		cout << "-------------------------------------" << endl;
		cout << "Kitap Ödünç Alma Menüsü" << endl;
		cout << "-------------------------------------" << endl;
		cout << endl;
		KitapOduncAlma();
		break;
	case 6:
		system("CLS"); cout << endl;
		cout << "-------------------------------------" << endl;
		cout << "Kitap Geri Verme Menüsü" << endl;
		cout << "-------------------------------------" << endl;
		cout << endl;
		OkuyucuKitapGeriBirak();
		break;
	case 7:
		system("CLS"); cout << endl;
		cout << "-------------------------------------" << endl;
		cout << "Kitap Ekleme Menüsü" << endl;
		cout << "-------------------------------------" << endl;
		cout << endl;
		KitapEkle();
		break;
	case 8:
		system("CLS"); cout << endl;
		cout << "-------------------------------------" << endl;
		cout << "Kitap Silme Menüsü" << endl;
		cout << "-------------------------------------" << endl;
		cout << endl;
		KitapSil();
		break;
	case 9:
		system("CLS"); cout << endl;
		cout << "-------------------------------------" << endl;
		cout << "Kitap Güncelleme Menüsü" << endl;
		cout << "-------------------------------------" << endl;
		cout << endl;
		KitapGuncelle();
		break;
	default:
		cout << "YANLIS NUMARA TUSLADINIZ." << endl;
		break;
	}


	cout << "Baþka bir iþlem daha yapmak ister misiniz (E/H) ?"; cin >> DevamMi;
	system("CLS");
	} while (DevamMi == 'e' || DevamMi == 'E');
}

void OkuyucuKayitEt()
{
	Okuyucu Okuyucu1;
	Okuyucu Okuyucu2;
	int OkuyucuNumarasi = 0;
	
	// Okuyucunun Numarasý Belirleniyor.
	OkuyucuNumarasi = OkuyucuNumarasiVer();
	
	ofstream DosyaYaz("Okuyucu.txt", ios::out | ios::app);

	// Gerekli Bilgiler Ýsteniyor.
	cout << "Okuyucunun Adý                         :" << setw(10); cin >> Okuyucu1.Ad;
	cout << "Okuyucunun Soyadi                      :" << setw(10); cin >> Okuyucu1.Soyad;
	cout << "Okuyucunun Tc Numarasi                 :" << setw(10); cin >> Okuyucu1.Tc;
	cout << "Okuyucunun DoðumTarihi (gg/aa/yy)      :" << setw(10); cin >> Okuyucu1.DogumTarihi;
	cout << "Okuyucunun Telefon Numarasý            :" << setw(10); cin >> Okuyucu1.Telefon;
	cout << "Okuyucunun Üye Numarasý                :" << OkuyucuNumarasi << endl;
	cout << "Okuyucunun Görevi                      :" << setw(10); cin >> Okuyucu1.Gorevi;
	cout << "Okuyucunun Alabileceði Kitap Sayýsý    :" << Okuyucu1.AlabilecegiKitapSayisi << endl;

	Okuyucu1.UyeNo = OkuyucuNumarasi;

	//Bilgiler Dosyaya Yazýlýyor.
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
	cout << "Güncellemek istediðiniz kullanýcýnýn TC numarasý    :";  cin >> ArananTc;
	ifstream DosyaOku;
	ofstream DosyaYaz;
	DosyaOku.open("Okuyucu.txt", ios::in);
	DosyaYaz.open("Gecici.tmp", ios::out);
	int UyusmaVarMi = 0;
	
	//Dosya sonuna kadar dönen bir while dongüsü baþlatýlýyor.
	while (!DosyaOku.eof())
	{
		//Dosya icindeki bilgiler alýnýyor.
		DosyaOku >> Okuyucu2.Ad >> Okuyucu2.Soyad >>
			Okuyucu2.Tc >> Okuyucu2.DogumTarihi >>
			Okuyucu2.Telefon >> Okuyucu2.UyeNo >>
			Okuyucu2.Gorevi >> Okuyucu2.AlabilecegiKitapSayisi;

		// Alýnana bilgi istenen tc ile karþýlaþtýrýlýyor.
		if (Okuyucu2.Tc == ArananTc)
		{
			//Okuyucunun güncel bilgilerini veriyor.
			cout << "Dosyada var olan bilgiler." << endl;
			OkuyucuBilgi(Okuyucu2);


			// Yeni Bilgiler isteniyor.
			cout << "Yeni bilgiler" << endl;
			cout << "Okuyucunun Adý                          :"; cin >> Okuyucu2.Ad;
			cout << "Okuyucunun Soyadý                       :"; cin >> Okuyucu2.Soyad;
			cout << "Okuyucunun Tc Numarasý                  :"; cin >> Okuyucu2.Tc;
			cout << "Okuyucunun Doðum Tarihi:                :"; cin >> Okuyucu2.DogumTarihi;
			cout << "Okuyucunun Telefon                      :"; cin >> Okuyucu2.Telefon;
			cout << "Okuyucunun Üye No                       :" << Okuyucu2.UyeNo << endl;
			cout << "Okuyucunun Görevi                       :"; cin >> Okuyucu2.Gorevi;
			cout << "Okuyucunun Alabilecegi Kitap Sayisi     :"; cout << Okuyucu2.AlabilecegiKitapSayisi << endl;

			//Guncelleme kayýt ediliyor.
			DosyaYaz << Okuyucu2.Ad << " " << Okuyucu2.Soyad <<
				" " << Okuyucu2.Tc << " " << Okuyucu2.DogumTarihi << " "
				<< Okuyucu2.Telefon << " " << Okuyucu2.UyeNo <<
				" " << Okuyucu2.Gorevi << " " << Okuyucu2.AlabilecegiKitapSayisi <<"\n";

			UyusmaVarMi=1;
		}
		//Uyuþma olmayan diger bilgiler de dosyaya yazýlýyor.
		else
		{
			//Son satýrda tekrar yazýlma olayý olmasýný önlüyor.
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
	
	//Girilen Tc nin sistemde olup olmadýðýna bakýyor.
	if (UyusmaVarMi == 0)
	{
		cout << "Girilen TC ile uyumlu bir üye bulunmamaktadýr." << endl;

	}

	DosyaYaz.close(); // Dosyalar kapanýyor.
	DosyaOku.close();
	remove("Okuyucu.txt");//Eski dosya uzaklaþtýrlýyor.
	rename("Gecici.tmp", "Okuyucu.txt");// Tüm bilgilerin kayýt oldugu yeni dosyanýn adý degistiriliyor.
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
	cout << "Silmek istediðiniz kullanýcýnýn TC numarasý    :";  cin >> ArananTc;

	//Dosya sonuna kadar dönen bir while dongüsü baþlatýlýyor.
	while (!DosyaOku.eof())
	{
		//Dosya icindeki bilgiler alýnýyor.
		DosyaOku >> Okuyucu2.Ad >> Okuyucu2.Soyad >>
			Okuyucu2.Tc >> Okuyucu2.DogumTarihi >>
			Okuyucu2.Telefon >> Okuyucu2.UyeNo >>
			Okuyucu2.Gorevi >> Okuyucu2.AlabilecegiKitapSayisi;

		// Alýnana bilgi istenen tc ile karþýlaþtýrýlýyor.
		if (Okuyucu2.Tc == ArananTc)
		{
			system("CLS");
		
			// Silinecek kullanici bilgileri.
			cout << "Silinecek Kullanýcý Bilgilieri " << endl;
			OkuyucuBilgi(Okuyucu2);
			KayitSilindiOduncSil(ArananTc);

			UyusmaVarMi++;
		}
		//Uyuþma olmayan diger bilgiler de dosyaya yazýlýyor.
		else
		{
			
			// Son Veri Tekrarýný Önlemek Ýçin Kullanýlýyor.
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
		cout << "Girilen TC ile uyumlu bir üye bulunmamaktadýr." << endl;

	}

	DosyaOku.close();
	DosyaYaz.close(); // Dosyalar kapanýyor.
	remove("Okuyucu.txt");//Eski dosya uzaklaþtýrlýyor.
	rename("Gecici.txt", "Okuyucu.txt");// Tüm bilgilerin kayýt oldugu yeni dosyanýn adý degistiriliyor.
}


void KitapEkle()
{
	Kitap kitap1;

	ofstream DosyaYaz;
	// Kitaplarýn yazýlacaðý kitaplar dosyasý açýlýyor.
	DosyaYaz.open("Kitaplar.txt", ios::out | ios::app);

	//Bilgiler Alýnýyor.
	cout << "Kitabýn ISBN Numarasý       :"<<setw(10); cin >> kitap1.ISBN;
	cout << "Kitabýn Adý                 : "<<setw(8); cin >> kitap1.KitapIsmi;
	cout << "Kitabýn Yazarýnýn Adý       :"<<setw(10); cin >> kitap1.YazarAdi;
	cout << "Kitabýn Yazarýnýn Soyadý    :"; cin >> kitap1.YazarSoyadi;
	cout << "Kitabýn Konusu              :"; cin >> kitap1.Konu;
	cout << "Kitabýn Türü                :"; cin >> kitap1.Tur;
	cout << "Kitabýn Sayfa Sayýsý        :"; cin >> kitap1.SayfaSayisi;

	//Dosyaya Yazýlýyor.
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

	cout << "Silmek istediðiniz kitabýn ISBN numarasýný giriniz  :"; cin >> arananISBN;
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
			// Silinecek kitap hariç kalanlar dosyaya yazilacak
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
			cout << "Aradýðýnýz ISBN numarasýnda bir kitap bulunamadý." << endl; cout << endl;
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
		//Kitap dosyasýndaki bilgilere bakýlýyor.
		DosyaOku >> Kitap1.ISBN >> Kitap1.KitapIsmi
			>> Kitap1.YazarAdi >> Kitap1.YazarSoyadi
			>> Kitap1.Konu >> Kitap1.Tur
			>> Kitap1.SayfaSayisi;

		//ArananISBN ile her bir bilgi karþýlaþtýrýlýyor.
		if (ArananISBN == Kitap1.ISBN && OduncKontrol.ISBN!=Kitap1.ISBN)
		{
			KitapBilgi(Kitap1);


			cout << "Yeni Bilgiler" << endl;
			cout << "Kitabýn ISBN           :"; cin >> Kitap1.ISBN;
			cout << "Kitabýn Adý            :"; cin >> Kitap1.KitapIsmi;
			cout << "Kitabýn Yazarýnýn Adý  :"; cin >> Kitap1.YazarAdi;
			cout << "Kitabýn Soyad          :"; cin >> Kitap1.YazarSoyadi;
			cout << "Kitabýn Konusu         :"; cin >> Kitap1.Konu;
			cout << "Kitabýn Türü           :"; cin >> Kitap1.Tur;
			cout << "Kitabýn Sayfa Sayýsý   :"; cin >> Kitap1.SayfaSayisi;

			//Eþitliðin oldugu kitap güncelleniyor.
			DosyaYaz << Kitap1.ISBN << " " << Kitap1.KitapIsmi
				<< " " << Kitap1.YazarAdi << " " << Kitap1.YazarSoyadi
				<< " " << Kitap1.Konu << " " << Kitap1.Tur << " "
				<< Kitap1.SayfaSayisi << "\n";
			uyusmaVarMi++;
			OduncKontrol.ISBN = Kitap1.ISBN;
		}
		else
		{
			//Eþitlik yok ise kitaplar oldugu gibi yeni dosyaya yazýlýyor.

				
			// Son 2 kitap ayný ise son kitap bilgileri yazýlmýyor ( son satýr hatasý)
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

		cout << "Aradýðýnýz ISBN numarasýnda bir kitap bulunamadý." << endl; cout << endl;
	}
	DosyaYaz.close(); // Dosyalar kapanýyor.
	DosyaOku.close();
	remove("Kitaplar.txt");//Eski dosya uzaklaþtýrlýyor.
	rename("GeciciKitapGuncelle.txt", "Kitaplar.txt");// Tüm bilgilerin kayýt oldugu yeni dosyanýn adý degistiriliyor

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

	cout << "TC kimlik numaranýzý giriniz  :"; cin >> arananTC; cout << endl; cout << endl;

	ifstream DosyaOku;
	DosyaOku.open("Okuyucu.txt", ios::in);

	//Okuyucu Dosyasýnýn içinde geziyor.
	while (!DosyaOku.eof())
	{


		DosyaOku >> Okuyucu2.Ad >> Okuyucu2.Soyad >>
			Okuyucu2.Tc >> Okuyucu2.DogumTarihi >>
			Okuyucu2.Telefon >> Okuyucu2.UyeNo >>
			Okuyucu2.Gorevi >> Okuyucu2.AlabilecegiKitapSayisi;

		
		// Girilen Kimlik numarasý sistemde var mý diye kontrol ediyor.
		if (arananTC == Okuyucu2.Tc)
		{
			DosyaOku.close();
			uyusmaVarMi++;

			cout << "Sayýn :" << Okuyucu2.Ad << " "
				<< Okuyucu2.Soyad << " " << endl;

			


			cout << "Almak istediðiniz kitabin ISBN numarasýný giriniz :"; cin >> arananISBN;
			cout << endl;

			DosyaOku.open("Kitaplar.txt");
			// Kitaplar Dosyasý içinde sonuna gelene kadar dönüyor.
			while (!DosyaOku.eof())
			{

				DosyaOku >> Kitap1.ISBN >> Kitap1.KitapIsmi
					>> Kitap1.YazarAdi >> Kitap1.YazarSoyadi
					>> Kitap1.Konu >> Kitap1.Tur
					>> Kitap1.SayfaSayisi;
	
			   // Aranan Kitabýn ISBN numarasý sistemde var mý kontrol ediliyor.
				if (Kitap1.ISBN == arananISBN && KitapBostaMi == 0)
				{
					KitapBostaMi++;

					DosyaOku.close();

					
					DosyaOku.open("Odunc.txt");
					// Odunc dosyasýnda dönüyor.
					while (!DosyaOku.eof())
					{
						DosyaOku >> OduncKitap1.ISBN >> OduncKitap1.TCNO >> OduncKitap1.oduncTarihi >> OduncKitap1.donusTarihi;
						
						//Eðer aranan ISBN Odunc dosyasýnda varsa kitap baþka kullanýcýda olduðu için isteyene verilmiyor.
						if (arananISBN == OduncKitap1.ISBN)
						{
							
							kontrol++;
							cout << "Almak istediðiniz " << arananISBN << " ISBN nolu kitap þu an baþka bir kullanýcýda" << endl;
							cout << "Kitabý " << OduncKitap1.donusTarihi << " tarihinde alabilirsiniz." << endl; cout << endl;
							break;
							
						}


					}
					if (kontrol == 0)
					{
						KitapBilgi(Kitap1);

						cout << "Kitabýn Odunç Alýnma Tarihini Giriniz. (gg/aa/yy):  "; cin >> OduncKitap1.oduncTarihi;
						cout << "Kitabýn Geri Dönme Tarihini Giriniz. (gg/aa/yy):    "; cin >> OduncKitap1.donusTarihi;


						
					
							ofstream DosyaYaz;
							DosyaYaz.open("Odunc.txt",ios::app);
							DosyaYaz << Kitap1.ISBN << " " << Okuyucu2.Tc << " " << OduncKitap1.oduncTarihi << " " << OduncKitap1.donusTarihi << "\n";
							DosyaYaz.close();

							
							Okuyucu2.AlabilecegiKitapSayisi--;
							cout << "Alabileciðiniz Kitap Sayýsý  :" << Okuyucu2.AlabilecegiKitapSayisi<< endl;
							
							OkuyucuAlabilecegiKitapSayisiAzalt(Okuyucu2.Tc);
							
							
					}
				

				}
				
			}
			if (KitapBostaMi == 0)
			{
				KitapBostaMi++;
				cout << "Aradýðýnýz ISBN numarasý sistemde bulunmamaktadýr." << endl;
			}


		}
	}
	if (uyusmaVarMi == 0)
	{
		uyusmaVarMi++;
		cout << "Girdiðiniz Tc kimlik numarasina ait bir üye bulunamadi." << endl; cout << endl;

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
	cout << "Sahip olduðunuz kitaplarý öðrenmek için TC numaranýzý giriniz :"; cin >> arananTC;

	ifstream DosyaOku;
	ifstream DosyaOku2;
	DosyaOku.open("Odunc.txt");
	while (!DosyaOku.eof())
	{
		DosyaOku >> Odunc1.ISBN >> Odunc1.TCNO >> Odunc1.oduncTarihi >> Odunc1.donusTarihi;

		
		//aranan TC numarasý ödünçte var ise okuyucu kitap almýþ demektir.
		if (arananTC == Odunc1.TCNO)
		{
			

			kontrol++;
			
			DosyaOku2.open("Kitaplar.txt");
			while (!DosyaOku2.eof())
			{
				// Odunc de verilen tc kimlik numarasýna ait ýsbn numaralý kitaplar bilgi yazdýrmak için Kitaplar dosyasýnda aranýyor.
				DosyaOku2 >> Kitap1.ISBN >> Kitap1.KitapIsmi
					>> Kitap1.YazarAdi >> Kitap1.YazarSoyadi
					>> Kitap1.Konu >> Kitap1.Tur
					>> Kitap1.SayfaSayisi;
				
				if (Odunc1.ISBN == Kitap1.ISBN && OduncKontrol.ISBN!=Odunc1.ISBN)
				{
					
					cout << arananTC << "TC numaralý kullanýcýnýn þu an sahip olduðu kitap :" << endl; cout << endl;
					KitapBilgi(Kitap1);
					OduncKontrol.ISBN = Odunc1.ISBN;
					
				}
				
			}
			DosyaOku2.close();
		}
	}
	DosyaOku.close();
	
	//Program eþleþme bulamazsa mesajý yazdýrýyor.
	     if(kontrol==0)
		 { 
		cout << "Girilen TC numarasý üzerine kayýtlý bir kitap bulunamadý." << endl;
		 }
 
}
void OkuyucuKitapGeriBirak()
{
	OduncKitap Odunc1;
	int KontrolISBN = 0	;
	int arananTC;
	int BirakilacakISBN;
	int KontrolTek = 0;

	cout << "Lütfen tc kimlik numaranýzý giriniz                  :"; cin>>arananTC;
	cout << "Býrakmak istedðiniz kitabýn ISBN numarasýný giriniz  :"; cin >> BirakilacakISBN;

	ifstream DosyaOku;
	DosyaOku.open("Odunc.txt");

	ofstream DosyaYaz;
	DosyaYaz.open("GeciciOdunc.txt");

	//Odunc dosyasýnda geziniyor.
	while (!DosyaOku.eof())
	{
		DosyaOku >> Odunc1.ISBN >> Odunc1.TCNO >> Odunc1.oduncTarihi >> Odunc1.donusTarihi;

		// arananTc nin odunc dosyasýnda olup olmadýðýna ve ISBN numarasýnýn uyumuna bakýyor.
		if (arananTC == Odunc1.TCNO && Odunc1.ISBN==BirakilacakISBN)
		{
			KontrolTek++;
			if (KontrolISBN != Odunc1.ISBN)
			{
				cout << Odunc1.ISBN << " ISBN numarasýna sahip kitabý geri býraktýnýz." << endl;
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
		cout << "Girilen TC numarasý veya ISBN hatalý" << endl;
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
	
	cout	<< "Okuyucunun Adý                        : " << Okuyucu2.Ad << " " << endl
		<< "Okuyucunun Soyadý                     :" << Okuyucu2.Soyad << " " << endl
		<< "Okuyucunun Tc Numarasý                :" << Okuyucu2.Tc << " " << endl
		<< "Okuyucunun Doðum Tarihi (gg/aa/yy)    :" << Okuyucu2.DogumTarihi << " " << endl
		<< "Okuyucunun Telefon Numarasý           :" << Okuyucu2.Telefon << " " << endl
		<< "Okuyucunun Üye Numarasý               :" << Okuyucu2.UyeNo << " " << endl
		<< "Okuyucunun Görevi                     :" << Okuyucu2.Gorevi << " " << endl
		<< "Okuyucunun Alabileceði Kitap Sayisi   :" << Okuyucu2.AlabilecegiKitapSayisi << endl;
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
				cout << "Sistemde Kayýtlý Olan " << Odunc1.ISBN << " nolu kitabýnýz geri býrakýlmýþtýr" << endl;
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
