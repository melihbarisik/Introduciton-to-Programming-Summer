/********************************************************************************
							   SAKARYA �N�VERS�TES�
					B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
						 B�LG�SAYAR M�HEND�SL��� B�L�M�
						   PROGRAMLAMAYA G�R�� DERS�

						   �DEV NUMARASI........:4.�DEV
						   ��RENC� ADI..........:MEL�H ENSAR BARI�IK
						   ��RENC� NUMARASI.....:
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

		// Karakter Dizini Eklenecek Dizin ve S�ralar Al�n�yor.
		cout << "Karakater Dizinini Giriniz                         :"; gets_s(BirinciKarakterDizini);
		cout << "Eklemek �stedi�iniz Karkater Dizinini Giriniz      :"; gets_s(IkinciKarakterDizini);







		// Gerekli Uzunluklar Al�n�yor
		birinciUzunluk = strlen(BirinciKarakterDizini);
		ikinciUzunluk = strlen(IkinciKarakterDizini);

		//Girilen s�ra say�s�n�n do�ru bir de�er olup olmad��� kontrol ediliyor.
		cout << "Dizin Eklemeye Ba�lanacak S�ray� Giriniz           :"; cin >> kacinciSirayaEklenecek;
		while (kacinciSirayaEklenecek <0 || kacinciSirayaEklenecek >birinciUzunluk)
		{
			cout << endl;
			cout << "S�ra Say�s� S�f�rdan K���k, Karakter Dizini Uzunlu�u Olan " << birinciUzunluk << " Dan B�y�k Olamaz." << endl;
			cout << "Dizin Eklemeye Ba�lanacak S�ray� Giriniz           :"; cin >> kacinciSirayaEklenecek;
		}

		//Girilen s�ra say�s�n�n do�ru bir de�er olup olmad��� kontrol ediliyor.
		cout << "Dizin Eklemenin Bitece�i  S�ray� Giriniz           :"; cin >> kacinciSiradaBitecek;
		while (kacinciSiradaBitecek <0 || kacinciSiradaBitecek >birinciUzunluk)
		{
			cout << endl;
			cout << "S�ra Say�s� S�f�rdan K���k, Karakter Dizini Uzunlu�u Olan " << birinciUzunluk << " Dan B�y�k Olamaz." << endl;
			cout << "Dizin Eklemenin Bitece�i  S�ray� Giriniz           :"; cin >> kacinciSiradaBitecek;

		}
		gets_s(HataOnle);
		//�lk de�er ikinciden b�y�k olursa hata olamamas� i�in kod
		if (kacinciSirayaEklenecek > kacinciSiradaBitecek)
		{
			temp = kacinciSirayaEklenecek;
			kacinciSirayaEklenecek = kacinciSiradaBitecek;
			kacinciSiradaBitecek = temp;
		}

		//verilen ilk aral��a kadar olan par�a al�n�yor.
		for (int i = 0; i <= kacinciSirayaEklenecek; i++)
		{
			ParcaBir[i] = BirinciKarakterDizini[i];
		}

		//verilen ikinci aral�ktan sonraki k�s�m al�n�yor.
		int k = 0;
		for (int j = kacinciSiradaBitecek; j < birinciUzunluk; j++, k++)
		{
			ParcaIki[k] = BirinciKarakterDizini[j];
		}




		// Al�nan par�alar�n uzunluklar� hesaplan�yor.
		parcaBirUzunluk = strlen(ParcaBir);
		parcIkiUzunluk = strlen(ParcaIki);


		//Ba�lang��tan ilk aral��a kadar olan k�s�m yani ilk par�a diziye ekleniyor. 
		for (int i = 0; i < parcaBirUzunluk; i++)
		{
			TemizKarakterDizini[i] = ParcaBir[i];
		}


		int j = 0;
		// Eklenecek k�s�m bir ve ikinci aral�klar�n aras�nda kalan k�sma yaz�l�yor.
		for (int i = parcaBirUzunluk; i < parcaBirUzunluk + ikinciUzunluk; i++, j++)
		{
			TemizKarakterDizini[i] = IkinciKarakterDizini[j];


		}

		
			int l = 0;
			// ikinci aral�ktan sona kadar olan ikinci par�a dizinin sonuna ekleniyor.

			for (int i = parcaBirUzunluk + ikinciUzunluk; i < ikinciUzunluk + parcIkiUzunluk + parcaBirUzunluk; i++, l++)
			{
				TemizKarakterDizini[i] = ParcaIki[l];
			}
		




		cout << "Olu�an Karakter Dizini                             :" << TemizKarakterDizini << endl;
	}
	void SonaKarkaterDiziniEkle()
	{
		// Kullan�lacak Karakter Dizinlerini Al�yorum
		cout << "�lk Karakter Dizinini Giriniz                :"; gets_s(BirinciKarakterDizini);
		cout << "Sona Eklenecek Karakter Dizinini Giriniz     :"; gets_s(IkinciKarakterDizini);

		// Karakter dizinlerinin uzunluklar�n� al�yorum.
		birinciUzunluk = strlen(BirinciKarakterDizini);
		ikinciUzunluk = strlen(IkinciKarakterDizini);

		
		int j = 0;
		// Birinci karakter dizininin bitti�i yerden ikinciyi ekliyorum
		for (int i = birinciUzunluk; i <= birinciUzunluk + ikinciUzunluk; i++, j++)
		{
			BirinciKarakterDizini[i] = IkinciKarakterDizini[j];
			
		}
	
		cout << "Karakter Dizini Sona Eklendi                 :";
		cout << BirinciKarakterDizini << endl;
	
		
		
	}
	void KarakterDiziniBirlestir()
	{
		// Kullan�lacak Karakter Dizinlerini Al�yorum
		cout << "Birle�tirilecek �lk Karakter Dizinini Giriniz      :"; gets_s(BirinciKarakterDizini);
		cout << "Birle�tirilecek �kinci Karakter Dizinini Giriniz   :"; gets_s(IkinciKarakterDizini);
		// Karakter dizinlerinin uzunluklar�n� al�yorum.
		birinciUzunluk = strlen(BirinciKarakterDizini);
		ikinciUzunluk = strlen(IkinciKarakterDizini);

	
		int j = 0;
		// Birinci karakter dizininin bitti�i yerden ikinciyi ekliyorum
		for (int i = birinciUzunluk; i < birinciUzunluk + ikinciUzunluk; i++, j++)
		{
			BirinciKarakterDizini[i] = IkinciKarakterDizini[j];
		}

		//Ekledi�imi dizinleri temiz bir char dizisine at�yorum.
		for (int i = 0; i < birinciUzunluk + ikinciUzunluk; i++)
		{
			TemizKarakterDizini[i] = BirinciKarakterDizini[i];
		}
	

		cout << "Birle�mi� Karakter Dizisi                          :";
		cout << TemizKarakterDizini << endl;
	}
	void KarakterleriBuyut()
	{

		// Kullan�lacak Karakter Dizinlerini Al�yorum
		cout << "Harfleri B�y�yecek Karakter Dizinini Giriniz :"; gets_s(BirinciKarakterDizini);
		
		
		//Kullan�lacak dizinin uzunlu�unu al�yorum.
			birinciUzunluk = strlen(BirinciKarakterDizini);

			//Diziyi sonuna kadar �eviriyorum.
			for (int i = 0; i < birinciUzunluk; i++)
			{
				//E�er dizinin elemanlar� asc�� tablosunda 65-122 aras�nda ise yani k���k harfise 
				if (BirinciKarakterDizini[i] >= 97 && BirinciKarakterDizini[i] <= 122)
				{
					//Elemenalardan 32 ��kar�p b�y�k hallerini yaz�yorum
					BirinciKarakterDizini[i] -= 32;
				}
			}
			
			cout << "Harfleri B�y�m�� Karakter Dizini             :";
			cout << BirinciKarakterDizini << endl;

	}
	void KarakterleriKucult()
	{
		// Kullan�lacak Karakter Dizinlerini Al�yorum
		cout << "Harfleri K���lecek Karkater Dizinini Giriniz :"; gets_s(BirinciKarakterDizini);

		//Kullan�lacak dizinin uzunlu�unu al�yorum.
		birinciUzunluk = strlen(BirinciKarakterDizini);

		//Diziyi sonuna kadar �eviriyorum.
		for (int i = 0; i < birinciUzunluk; i++)
		{
			//E�er dizinin elemanlar� asc�� tablosunda 65-122 aras�nda ise yani k���k harfise 
			if (BirinciKarakterDizini[i] >= 65 && BirinciKarakterDizini[i] <= 90)
			{
				//Elemenalardan 32 ��kar�p b�y�k hallerini yaz�yorum
				BirinciKarakterDizini[i] += 32;
			}
		}
		
		cout << "Harfleri K���lm�� Karakter Dizini            :";
		cout << BirinciKarakterDizini << endl;
	}
	void KarakterDiziniAra()
	{
		// Kullan�lacak Karakter Dizinlerini Al�yorum
		cout << "Karakter Dizinini Giriniz                  :"; gets_s(BirinciKarakterDizini);
		cout << "Aranacak Karkater Dizini Par�as�n� Giriniz :"; gets_s(IkinciKarakterDizini);

		// Kullan�lacak Uzunluklar� Hesapl�yorum.
			birinciUzunluk = strlen(BirinciKarakterDizini);
			ikinciUzunluk = strlen(IkinciKarakterDizini);

			// �lk for b�y�k karakter dizini i�in d�n�yor.
			for (int i = 0; i < birinciUzunluk; i++)
			{
				if (Sayac != ikinciUzunluk) {
					//ikinci for k���k karakter dizini i�in d�n�yor.
					for (int j = 0; j < ikinciUzunluk; j++)
					{
						//B�y�k karakter dizininin aranan karakter dizini kadar uzun olan her harfleri s�rayla kontrol ediliyor.
						TemizKarakterDizini[j] = BirinciKarakterDizini[j + i];


						if (IkinciKarakterDizini[j] == TemizKarakterDizini[j])
						{//Pe� pe�e aranan dizin kadar e�le�me sa�lan�rsa kod durduruluyor.
							Sayac++;
							Baslangic = i; Bitis = i + ikinciUzunluk ;
						
						}
						// E�le�me pe� pe�e olmaz ise de�erler s�f�rlan�yor.
						else
						{
							Baslangic = 0;
							Sayac = 0;
						}
					}
				}
			}
			
			if (Sayac != ikinciUzunluk)
				cout << "Arad���n�z De�er Malesef Bulunamad�" << endl;
			else if (Sayac == ikinciUzunluk)
			{
				cout << "Arad���n�z De�er Olan "<< IkinciKarakterDizini << " Karakter Dizini " << Baslangic << ". Harfinden " << Bitis << ". Harfe Kadar Olan K�sm�nda Bulundu." << endl;
			}
			
			
		 

	

		
	}
	void ArayaKarakterDiziniEkle()
	{
		// Karakter Dizini Eklenecek Dizin ve Ka��nc� S�raya Eklenece�i Al�n�yor.
		
		cout << "Karakater Dizinini Giriniz                         :"; gets_s(BirinciKarakterDizini);
		cout << "Eklemek �stedi�iniz Karkater Dizinini Giriniz      :"; gets_s(IkinciKarakterDizini);
		cout << "Ka��nc� S�raya Dizin Eklemek �stedi�inizi Giriniz  :"; cin >> kacinciSirayaEklenecek;
		
		

		// Gerekli Uzunluklar Al�n�yor.
		birinciUzunluk = strlen(BirinciKarakterDizini);
		ikinciUzunluk = strlen(IkinciKarakterDizini);

		//Girilen s�ra say�s�n�n do�ru bir de�er olup olmad��� kontrol ediliyor.
	while (kacinciSirayaEklenecek <0 || kacinciSirayaEklenecek >birinciUzunluk)
	{
		cout << endl;
		cout << "S�ra Say�s� S�f�rdan K���k, Karakter Dizini Uzunlu�u Olan " << birinciUzunluk << " Dan B�y�k Olamaz." << endl;
		cout << "Ka��nc� S�raya Dizin Eklemek �stedi�inizi Giriniz  :"; cin >> kacinciSirayaEklenecek;

	}
	gets_s(HataOnle);

		//verilen s�raya kadar olan k�s�m birinci par�a bir diziye at�l�yor.
		for (int i = 0; i < kacinciSirayaEklenecek; i++)
		{
			
			ParcaBir[i] = BirinciKarakterDizini[i];
		}
		
		//verilen s�radan sonra gelen ikinci k�s�m parcaiki farkl� bir diziye yaz�l�yor.
		int k = 0;
		for (int j = kacinciSirayaEklenecek; j < birinciUzunluk; j++, k++)
		{
			
			ParcaIki[k] = BirinciKarakterDizini[j];
		}



		
		// Al�nan par�alar�n uzunluklar� hesaplan�yor.
		parcaBirUzunluk = strlen(ParcaBir);
		parcIkiUzunluk = strlen(ParcaIki);
		
		
			//Birinci par�a karakter dizinin ilk par�as� oluyor
			for (int i = 0; i < parcaBirUzunluk; i++)
			{
				TemizKarakterDizini[i] = ParcaBir[i];
			}
		

		int j = 0;
		// eklenecek k�s�ma girilen par�a yaz�l�yor.
		for (int i = parcaBirUzunluk; i < parcaBirUzunluk+ikinciUzunluk; i++,j++)
		{
			TemizKarakterDizini[i] = IkinciKarakterDizini[j];
			
			
		}

		
			int l = 0;
			// ikinci par�a dizinin sonuna yerle�tirilerek i�lem tamamlan�yor.

			for (int i = parcaBirUzunluk + ikinciUzunluk; i < ikinciUzunluk + parcIkiUzunluk + parcaBirUzunluk; i++, l++)
			{
				TemizKarakterDizini[i] = ParcaIki[l];
			}
		



		
		cout << "Olu�an Karakter Dizini                             :" << TemizKarakterDizini << endl;
		
	}
	


};
int main()
{

	setlocale(LC_ALL, "Turkish");

	OzelStringSinifi Ozel1;
	
	



	cout << "1-Sona Karakter Dizini Ekleme ��lemi" << endl; cout << endl;
	Ozel1.SonaKarkaterDiziniEkle();
	cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;

	cout << "2-�ki Karakter Dizini Birle�tirme ��lemi" << endl; cout << endl;
	Ozel1.KarakterDiziniBirlestir();
	cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;

	cout << "3-Karakter Dizinindeki Harfleri B�y�ltme ��lemi" << endl; cout << endl;
	Ozel1.KarakterleriBuyut();
	cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;

	cout << "4-Karakter Dizinindeki Harfleri B�y�ltme ��lemi" << endl; cout << endl;
	Ozel1.KarakterleriKucult();
	cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
	
	cout << "5-Karakter Dizini Arama ��lemi" << endl; cout << endl;
	Ozel1.KarakterDiziniAra();
	cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;

	cout << "6-�zerine Karakter Dizini Yazma ��lemi" << endl;
	Ozel1.UzerineKarakterDiziniYazma();
	cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;

	cout << "7-Araya Karakter Dizini Ekleme ��lemi" << endl;
	Ozel1.ArayaKarakterDiziniEkle();
	cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
	



	

	
	
	










	system("pause");
}