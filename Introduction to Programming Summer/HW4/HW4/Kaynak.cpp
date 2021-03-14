/********************************************************************************
							   SAKARYA ÜNÝVERSÝTESÝ
					BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
						 BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
						   PROGRAMLAMAYA GÝRÝÞ DERSÝ

						   ÖDEV NUMARASI........:4.ÖDEV
						   ÖÐRENCÝ ADI..........:MELÝH ENSAR BARIÞIK
						   ÖÐRENCÝ NUMARASI.....:
						   DERS GRUBU...........:A

*********************************************************************************/
#include <iostream>

using namespace std;

class OzelStringSinifi
{

private:
	enum 
	{
		BOYUT = 50
	};

	char BirinciKarakterDizini[BOYUT] = "a";

	char IkinciKarakterDizini[BOYUT] = "a";

	char TemizKarakterDizini[BOYUT] = "a";

	char ParcaBir[BOYUT] = "a";

	char ParcaIki[BOYUT] = "a";

	char HataOnle[2];

	int Baslangic = 1;
	int Bitis = 1;

	int Kontrol = 0;
	int Sayac = 0;

	int birinciUzunluk;
	int ikinciUzunluk;
	int parcaBirUzunluk;
	int parcIkiUzunluk;
	int kacinciSirayaEklenecek;
	int kacinciSiradaBitecek;

public:
	void UzerineKarakterDiziniYazma()
	{


		int temp;

		// Karakter Dizini Eklenecek Dizin ve Sýralar Alýnýyor.
		cout << "Karakater Dizinini Giriniz                         :"; gets_s(BirinciKarakterDizini);
		cout << "Eklemek Ýstediðiniz Karkater Dizinini Giriniz      :"; gets_s(IkinciKarakterDizini);







		// Gerekli Uzunluklar Alýnýyor
		birinciUzunluk = strlen(BirinciKarakterDizini);
		ikinciUzunluk = strlen(IkinciKarakterDizini);

		//Girilen sýra sayýsýnýn doðru bir deðer olup olmadýðý kontrol ediliyor.
		cout << "Dizin Eklemeye Baþlanacak Sýrayý Giriniz           :"; cin >> kacinciSirayaEklenecek;
		while (kacinciSirayaEklenecek <0 || kacinciSirayaEklenecek >birinciUzunluk)
		{
			cout << endl;
			cout << "Sýra Sayýsý Sýfýrdan Küçük, Karakter Dizini Uzunluðu Olan " << birinciUzunluk << " Dan Büyük Olamaz." << endl;
			cout << "Dizin Eklemeye Baþlanacak Sýrayý Giriniz           :"; cin >> kacinciSirayaEklenecek;
		}

		//Girilen sýra sayýsýnýn doðru bir deðer olup olmadýðý kontrol ediliyor.
		cout << "Dizin Eklemenin Biteceði  Sýrayý Giriniz           :"; cin >> kacinciSiradaBitecek;
		while (kacinciSiradaBitecek <0 || kacinciSiradaBitecek >birinciUzunluk)
		{
			cout << endl;
			cout << "Sýra Sayýsý Sýfýrdan Küçük, Karakter Dizini Uzunluðu Olan " << birinciUzunluk << " Dan Büyük Olamaz." << endl;
			cout << "Dizin Eklemenin Biteceði  Sýrayý Giriniz           :"; cin >> kacinciSiradaBitecek;

		}
		gets_s(HataOnle);
		//Ýlk deðer ikinciden büyük olursa hata olamamasý için kod
		if (kacinciSirayaEklenecek > kacinciSiradaBitecek)
		{
			temp = kacinciSirayaEklenecek;
			kacinciSirayaEklenecek = kacinciSiradaBitecek;
			kacinciSiradaBitecek = temp;
		}

		//verilen ilk aralýða kadar olan parça alýnýyor.
		for (int i = 0; i <= kacinciSirayaEklenecek; i++)
		{
			ParcaBir[i] = BirinciKarakterDizini[i];
		}

		//verilen ikinci aralýktan sonraki kýsým alýnýyor.
		int k = 0;
		for (int j = kacinciSiradaBitecek; j < birinciUzunluk; j++, k++)
		{
			ParcaIki[k] = BirinciKarakterDizini[j];
		}




		// Alýnan parçalarýn uzunluklarý hesaplanýyor.
		parcaBirUzunluk = strlen(ParcaBir);
		parcIkiUzunluk = strlen(ParcaIki);


		//Baþlangýçtan ilk aralýða kadar olan kýsým yani ilk parça diziye ekleniyor. 
		for (int i = 0; i < parcaBirUzunluk; i++)
		{
			TemizKarakterDizini[i] = ParcaBir[i];
		}


		int j = 0;
		// Eklenecek kýsým bir ve ikinci aralýklarýn arasýnda kalan kýsma yazýlýyor.
		for (int i = parcaBirUzunluk; i < parcaBirUzunluk + ikinciUzunluk; i++, j++)
		{
			TemizKarakterDizini[i] = IkinciKarakterDizini[j];


		}

		
			int l = 0;
			// ikinci aralýktan sona kadar olan ikinci parça dizinin sonuna ekleniyor.

			for (int i = parcaBirUzunluk + ikinciUzunluk; i < ikinciUzunluk + parcIkiUzunluk + parcaBirUzunluk; i++, l++)
			{
				TemizKarakterDizini[i] = ParcaIki[l];
			}
		




		cout << "Oluþan Karakter Dizini                             :" << TemizKarakterDizini << endl;
	}
	void SonaKarkaterDiziniEkle()
	{
		// Kullanýlacak Karakter Dizinlerini Alýyorum
		cout << "Ýlk Karakter Dizinini Giriniz                :"; gets_s(BirinciKarakterDizini);
		cout << "Sona Eklenecek Karakter Dizinini Giriniz     :"; gets_s(IkinciKarakterDizini);

		// Karakter dizinlerinin uzunluklarýný alýyorum.
		birinciUzunluk = strlen(BirinciKarakterDizini);
		ikinciUzunluk = strlen(IkinciKarakterDizini);

		
		int j = 0;
		// Birinci karakter dizininin bittiði yerden ikinciyi ekliyorum
		for (int i = birinciUzunluk; i <= birinciUzunluk + ikinciUzunluk; i++, j++)
		{
			BirinciKarakterDizini[i] = IkinciKarakterDizini[j];
			
		}
	
		cout << "Karakter Dizini Sona Eklendi                 :";
		cout << BirinciKarakterDizini << endl;
	
		
		
	}
	void KarakterDiziniBirlestir()
	{
		// Kullanýlacak Karakter Dizinlerini Alýyorum
		cout << "Birleþtirilecek Ýlk Karakter Dizinini Giriniz      :"; gets_s(BirinciKarakterDizini);
		cout << "Birleþtirilecek Ýkinci Karakter Dizinini Giriniz   :"; gets_s(IkinciKarakterDizini);
		// Karakter dizinlerinin uzunluklarýný alýyorum.
		birinciUzunluk = strlen(BirinciKarakterDizini);
		ikinciUzunluk = strlen(IkinciKarakterDizini);

	
		int j = 0;
		// Birinci karakter dizininin bittiði yerden ikinciyi ekliyorum
		for (int i = birinciUzunluk; i < birinciUzunluk + ikinciUzunluk; i++, j++)
		{
			BirinciKarakterDizini[i] = IkinciKarakterDizini[j];
		}

		//Eklediðimi dizinleri temiz bir char dizisine atýyorum.
		for (int i = 0; i < birinciUzunluk + ikinciUzunluk; i++)
		{
			TemizKarakterDizini[i] = BirinciKarakterDizini[i];
		}
	

		cout << "Birleþmiþ Karakter Dizisi                          :";
		cout << TemizKarakterDizini << endl;
	}
	void KarakterleriBuyut()
	{

		// Kullanýlacak Karakter Dizinlerini Alýyorum
		cout << "Harfleri Büyüyecek Karakter Dizinini Giriniz :"; gets_s(BirinciKarakterDizini);
		
		
		//Kullanýlacak dizinin uzunluðunu alýyorum.
			birinciUzunluk = strlen(BirinciKarakterDizini);

			//Diziyi sonuna kadar çeviriyorum.
			for (int i = 0; i < birinciUzunluk; i++)
			{
				//Eðer dizinin elemanlarý ascýý tablosunda 65-122 arasýnda ise yani küçük harfise 
				if (BirinciKarakterDizini[i] >= 97 && BirinciKarakterDizini[i] <= 122)
				{
					//Elemenalardan 32 çýkarýp büyük hallerini yazýyorum
					BirinciKarakterDizini[i] -= 32;
				}
			}
			
			cout << "Harfleri Büyümüþ Karakter Dizini             :";
			cout << BirinciKarakterDizini << endl;

	}
	void KarakterleriKucult()
	{
		// Kullanýlacak Karakter Dizinlerini Alýyorum
		cout << "Harfleri Küçülecek Karkater Dizinini Giriniz :"; gets_s(BirinciKarakterDizini);

		//Kullanýlacak dizinin uzunluðunu alýyorum.
		birinciUzunluk = strlen(BirinciKarakterDizini);

		//Diziyi sonuna kadar çeviriyorum.
		for (int i = 0; i < birinciUzunluk; i++)
		{
			//Eðer dizinin elemanlarý ascýý tablosunda 65-122 arasýnda ise yani küçük harfise 
			if (BirinciKarakterDizini[i] >= 65 && BirinciKarakterDizini[i] <= 90)
			{
				//Elemenalardan 32 çýkarýp büyük hallerini yazýyorum
				BirinciKarakterDizini[i] += 32;
			}
		}
		
		cout << "Harfleri Küçülmüþ Karakter Dizini            :";
		cout << BirinciKarakterDizini << endl;
	}
	void KarakterDiziniAra()
	{
		// Kullanýlacak Karakter Dizinlerini Alýyorum
		cout << "Karakter Dizinini Giriniz                  :"; gets_s(BirinciKarakterDizini);
		cout << "Aranacak Karkater Dizini Parçasýný Giriniz :"; gets_s(IkinciKarakterDizini);

		// Kullanýlacak Uzunluklarý Hesaplýyorum.
			birinciUzunluk = strlen(BirinciKarakterDizini);
			ikinciUzunluk = strlen(IkinciKarakterDizini);

			// Ýlk for büyük karakter dizini için dönüyor.
			for (int i = 0; i < birinciUzunluk; i++)
			{
				if (Sayac != ikinciUzunluk) {
					//ikinci for küçük karakter dizini için dönüyor.
					for (int j = 0; j < ikinciUzunluk; j++)
					{
						//Büyük karakter dizininin aranan karakter dizini kadar uzun olan her harfleri sýrayla kontrol ediliyor.
						TemizKarakterDizini[j] = BirinciKarakterDizini[j + i];


						if (IkinciKarakterDizini[j] == TemizKarakterDizini[j])
						{//Peþ peþe aranan dizin kadar eþleþme saðlanýrsa kod durduruluyor.
							Sayac++;
							Baslangic = i; Bitis = i + ikinciUzunluk ;
						
						}
						// Eþleþme peþ peþe olmaz ise deðerler sýfýrlanýyor.
						else
						{
							Baslangic = 0;
							Sayac = 0;
						}
					}
				}
			}
			
			if (Sayac != ikinciUzunluk)
				cout << "Aradýðýnýz Deðer Malesef Bulunamadý" << endl;
			else if (Sayac == ikinciUzunluk)
			{
				cout << "Aradýðýnýz Deðer Olan "<< IkinciKarakterDizini << " Karakter Dizini " << Baslangic << ". Harfinden " << Bitis << ". Harfe Kadar Olan Kýsmýnda Bulundu." << endl;
			}
			
			
		 

	

		
	}
	void ArayaKarakterDiziniEkle()
	{
		// Karakter Dizini Eklenecek Dizin ve Kaçýncý Sýraya Ekleneceði Alýnýyor.
		
		cout << "Karakater Dizinini Giriniz                         :"; gets_s(BirinciKarakterDizini);
		cout << "Eklemek Ýstediðiniz Karkater Dizinini Giriniz      :"; gets_s(IkinciKarakterDizini);
		cout << "Kaçýncý Sýraya Dizin Eklemek Ýstediðinizi Giriniz  :"; cin >> kacinciSirayaEklenecek;
		
		

		// Gerekli Uzunluklar Alýnýyor.
		birinciUzunluk = strlen(BirinciKarakterDizini);
		ikinciUzunluk = strlen(IkinciKarakterDizini);

		//Girilen sýra sayýsýnýn doðru bir deðer olup olmadýðý kontrol ediliyor.
	while (kacinciSirayaEklenecek <0 || kacinciSirayaEklenecek >birinciUzunluk)
	{
		cout << endl;
		cout << "Sýra Sayýsý Sýfýrdan Küçük, Karakter Dizini Uzunluðu Olan " << birinciUzunluk << " Dan Büyük Olamaz." << endl;
		cout << "Kaçýncý Sýraya Dizin Eklemek Ýstediðinizi Giriniz  :"; cin >> kacinciSirayaEklenecek;

	}
	gets_s(HataOnle);

		//verilen sýraya kadar olan kýsým birinci parça bir diziye atýlýyor.
		for (int i = 0; i < kacinciSirayaEklenecek; i++)
		{
			
			ParcaBir[i] = BirinciKarakterDizini[i];
		}
		
		//verilen sýradan sonra gelen ikinci kýsým parcaiki farklý bir diziye yazýlýyor.
		int k = 0;
		for (int j = kacinciSirayaEklenecek; j < birinciUzunluk; j++, k++)
		{
			
			ParcaIki[k] = BirinciKarakterDizini[j];
		}



		
		// Alýnan parçalarýn uzunluklarý hesaplanýyor.
		parcaBirUzunluk = strlen(ParcaBir);
		parcIkiUzunluk = strlen(ParcaIki);
		
		
			//Birinci parça karakter dizinin ilk parçasý oluyor
			for (int i = 0; i < parcaBirUzunluk; i++)
			{
				TemizKarakterDizini[i] = ParcaBir[i];
			}
		

		int j = 0;
		// eklenecek kýsýma girilen parça yazýlýyor.
		for (int i = parcaBirUzunluk; i < parcaBirUzunluk+ikinciUzunluk; i++,j++)
		{
			TemizKarakterDizini[i] = IkinciKarakterDizini[j];
			
			
		}

		
			int l = 0;
			// ikinci parça dizinin sonuna yerleþtirilerek iþlem tamamlanýyor.

			for (int i = parcaBirUzunluk + ikinciUzunluk; i < ikinciUzunluk + parcIkiUzunluk + parcaBirUzunluk; i++, l++)
			{
				TemizKarakterDizini[i] = ParcaIki[l];
			}
		



		
		cout << "Oluþan Karakter Dizini                             :" << TemizKarakterDizini << endl;
		
	}
	


};
int main()
{

	setlocale(LC_ALL, "Turkish");

	OzelStringSinifi Ozel1;
	
	



	cout << "1-Sona Karakter Dizini Ekleme Ýþlemi" << endl; cout << endl;
	Ozel1.SonaKarkaterDiziniEkle();
	cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;

	cout << "2-Ýki Karakter Dizini Birleþtirme Ýþlemi" << endl; cout << endl;
	Ozel1.KarakterDiziniBirlestir();
	cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;

	cout << "3-Karakter Dizinindeki Harfleri Büyültme Ýþlemi" << endl; cout << endl;
	Ozel1.KarakterleriBuyut();
	cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;

	cout << "4-Karakter Dizinindeki Harfleri Büyültme Ýþlemi" << endl; cout << endl;
	Ozel1.KarakterleriKucult();
	cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
	
	cout << "5-Karakter Dizini Arama Ýþlemi" << endl; cout << endl;
	Ozel1.KarakterDiziniAra();
	cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;

	cout << "6-Üzerine Karakter Dizini Yazma Ýþlemi" << endl;
	Ozel1.UzerineKarakterDiziniYazma();
	cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;

	cout << "7-Araya Karakter Dizini Ekleme Ýþlemi" << endl;
	Ozel1.ArayaKarakterDiziniEkle();
	cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
	



	

	
	
	










	system("pause");
}