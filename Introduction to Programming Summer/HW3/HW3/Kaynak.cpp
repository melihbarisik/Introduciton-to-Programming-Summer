/********************************************************************************
							   SAKARYA ÜNÝVERSÝTESÝ
					BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
						 BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
						   PROGRAMLAMAYA GÝRÝÞ DERSÝ

						   ÖDEV NUMARASI........:3.ÖDEV
						   ÖÐRENCÝ ADI..........:MELÝH ENSAR BARIÞIK
						   ÖÐRENCÝ NUMARASI.....:
						   DERS GRUBU...........:A

*********************************************************************************/
#include <iostream>
#include<locale.h>
#include<iomanip>
#include<string>
#include<math.h>
using namespace std;


void matrisToplama(int[][3], int[][3]);
void matrisCikarma(int[][3], int[][3]);

void matrisCarpma(int[][3], int[][3]);
void matrisTranspozeAl(int[][3]);

int matrisDeterminantAl(int[][3],int);
void matrisIziniBul(int[][3]);

void matrisKosesiBul(int m[][3]);

void matrisOlustur(int m[][3]);
void RandomMatrisOlustur(int m[][3]);

void matrisYazdir(int[][3],string);

int main()
{
	setlocale(LC_ALL, "Turkish");
	srand(time(NULL));

	int secim;
	string Not1;
	string Not2;
	int matris1[3][3];
	int matris2[3][3];
	char DevamMi;

	char RandomSecim;


	


	do
	{
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl; // tam ekraný kaplýyor.
		cout << "                                              Matris Programýna HoþGeldiniz                                             " << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;


		cout << "1- Matris Toplama" << endl;
		cout << "2- Matris Çýkarma" << endl;
		cout << "3- Matris Çarpma" << endl;
		cout << "4- Matris Transpoze Alma" << endl;
		cout << "5- Matris Determinantýný Bulma" << endl;
		cout << "6- Matris Ýzini Bulma" << endl;
		cout << "7- Matris Köþesini Bulma" << endl;

		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "Yapmak istediðiniz iþlemi tuþlanýyýz :"; cin >> secim;

		switch (secim)
		{
		case 1:
			system("CLS");
			cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
			cout << "Matris Toplama Ýþlemi" << endl;
			cout << "------------------------------------------------------------------------------------------------------------------------" << endl; cout << endl;

			cout << "A- Deðerleri Siz Girmek Ýstiyorsanýz Tuþlanýyýnýz." << endl;
			cout << "B- Random Deðerler Ýle Devam Etmek ÝStiyorsanýz Tuþlayýnýz." << endl;
			
			cout << "Yanýt :";	cin >> RandomSecim; cout << endl;
			

			switch (RandomSecim)
			{
				//Manuel Kullaným
			case 'A':
				Not1 = "Oluþturduðunuz Ýlk Matris";
				Not2 = "Oluþturduðunuz Ýkinci Matris";

				cout << "Birinci Matris Bilgileri" << endl;
				matrisOlustur(matris1);
				cout << "Ýkinci Matris Bilgileri" << endl;
				matrisOlustur(matris2);

				matrisYazdir(matris1, Not1);
				matrisYazdir(matris2, Not2);

				matrisToplama(matris1, matris2);
				break;

				//Otomatik Kullaným
			case 'B':
				Not1 = "Oluþturulan Ýlk Matris";
				Not2 = "Oluþturulan Ýkinci Matris";

				
				RandomMatrisOlustur(matris1);
				
				RandomMatrisOlustur(matris2);

				matrisYazdir(matris1, Not1);
				matrisYazdir(matris2, Not2);

				matrisToplama(matris1, matris2);
				break;
			default:
				cout << "YANLIÞ TUÞLADINIZ." << endl;
				break;
			}
			break;
		case 2:
			system("CLS");
			cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
			cout << "Matris Çýkarma Ýþlemi" << endl;
			cout << "------------------------------------------------------------------------------------------------------------------------" << endl; cout << endl;

			cout << "A-Deðerleri Siz Girmek Ýstiyorsanýz Tuþlanýyýnýz." << endl;
			cout << "B-Random Deðerler Ýle Devam Etmek ÝStiyorsanýz Tuþlayýnýz." << endl;
			cout << "Yanýt :";	cin >> RandomSecim; cout << endl;

			switch (RandomSecim)
			{
			case 'A':
				

				Not1 = "Oluþturduðunuz Ýlk Matris";
				Not2 = "Oluþturduðunuz Ýkinci Matris";

				cout << "Birinci Matris Bilgileri" << endl;
				matrisOlustur(matris1);
				cout << "Ýkinci Matris Bilgileri" << endl;
				matrisOlustur(matris2);

				matrisYazdir(matris1, Not1);
				matrisYazdir(matris2, Not2);

				matrisCikarma(matris1, matris2);
					break;

			case 'B':
				

				Not1 = "Oluþturulan Ýlk Matris";
				Not2 = "Oluþturulan Ýkinci Matris";

				RandomMatrisOlustur(matris1);
				RandomMatrisOlustur(matris2);
				
				

				matrisYazdir(matris1, Not1);
				matrisYazdir(matris2, Not2);

				matrisCikarma(matris1, matris2);
					break;
			default:
				break;
			}
		
			break;
		case 3:
			system("CLS");
			cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
			cout << "Matris Çarpma Ýþlemi" << endl;
			cout << "------------------------------------------------------------------------------------------------------------------------" << endl; cout << endl;

			cout << "A-Deðerleri Siz Girmek Ýstiyorsanýz Tuþlanýyýnýz." << endl;
			cout << "B-Random Deðerler Ýle Devam Etmek ÝStiyorsanýz Tuþlayýnýz." << endl;
			cout << "Yanýt :";	cin >> RandomSecim; cout << endl;
			switch (RandomSecim)
			{
			case 'A':
				Not1 = "Oluþturduðunuz Ýlk Matris";
				Not2 = "Oluþturduðunuz Ýkinci Matris";

				cout << "Birinci Matris Bilgileri" << endl;
				matrisOlustur(matris1);
				cout << "Ýkinci Matris Bilgileri" << endl;
				matrisOlustur(matris2);

				matrisYazdir(matris1, Not1);
				matrisYazdir(matris2, Not2);

				matrisCarpma(matris1, matris2);
				break;
			case 'B':
				Not1 = "Oluþturulan Ýlk Matris";
				Not2 = "Oluþturulan Ýkinci Matris";


				RandomMatrisOlustur(matris1);

				RandomMatrisOlustur(matris2);

				matrisYazdir(matris1, Not1);
				matrisYazdir(matris2, Not2);

				matrisCarpma(matris1, matris2);
				break;
			default:
				break;
			}
			

		
			break;
		case 4:
			system("CLS");
			cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
			cout << "Matris Transpoz Ýþlemi" << endl;
			cout << "------------------------------------------------------------------------------------------------------------------------" << endl; cout << endl;

			cout << "A-Deðerleri Siz Girmek Ýstiyorsanýz Tuþlanýyýnýz." << endl;
			cout << "B-Random Deðerler Ýle Devam Etmek ÝStiyorsanýz Tuþlayýnýz." << endl;
			cout << "Yanýt :";	cin >> RandomSecim; cout << endl;
			switch (RandomSecim)
			{
			case 'A':

				Not1 = "Transpozu Alýnacak Matris";


				cout << "Matris Bilgileri" << endl;
				matrisOlustur(matris1);

				matrisYazdir(matris1, Not1);

				matrisTranspozeAl(matris1);
				break;
			case 'B':
				Not1 = "Transpozu Alýnacak Matris";


				
				RandomMatrisOlustur(matris1);

				matrisYazdir(matris1, Not1);

				matrisTranspozeAl(matris1);

					break;
			default:
				break;
			}
		

			break;
		case 5:
			system("CLS");
			
			cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
			cout << "Matris Determinant Ýþlemi" << endl;
			cout << "------------------------------------------------------------------------------------------------------------------------" << endl; cout << endl;
			cout << "A-Deðerleri Siz Girmek Ýstiyorsanýz Tuþlanýyýnýz." << endl;
			cout << "B-Random Deðerler Ýle Devam Etmek ÝStiyorsanýz Tuþlayýnýz." << endl;
			cout << "Yanýt :";	cin >> RandomSecim; cout << endl;
			switch (RandomSecim)
			{
			case 'A':
				Not1 = "- Kullanýlan Matris -";
				cout << "Matris Bilgileri" << endl;
				matrisOlustur(matris1);

				matrisYazdir(matris1, Not1);

				cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
				cout << setw(75) << "Matrisin Determinantý :" << matrisDeterminantAl(matris1, 3) << endl;
				cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
				break;
			case 'B':
				Not1 = "- Kullanýlan Matris -";
				
				RandomMatrisOlustur(matris1);

				matrisYazdir(matris1, Not1);

				cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
				cout << setw(75) << "Matrisin Determinantý :" << matrisDeterminantAl(matris1, 3) << endl;
				cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
				break;
			default:
				break;
			}
			
	
			break;
		case 6:
			system("CLS");
			cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
			cout << "Matris Ýzini Bulma Ýþlemi" << endl;
			cout << "------------------------------------------------------------------------------------------------------------------------" << endl; cout << endl;
			cout << "A-Deðerleri Siz Girmek Ýstiyorsanýz Tuþlanýyýnýz." << endl;
			cout << "B-Random Deðerler Ýle Devam Etmek ÝStiyorsanýz Tuþlayýnýz." << endl;
			cout << "Yanýt :";	cin >> RandomSecim;  cout << endl;
			switch (RandomSecim)
			{
			case 'A':
				Not1 = "Ýzi Alýnacak Matris";


				cout << "Ýzi Alýnacak Matris Bilgileri" << endl;
				matrisOlustur(matris1);

				matrisYazdir(matris1, Not1);
				cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
				matrisIziniBul(matris1);
				cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
				break;
			case 'B':
				Not1 = "Ýzi Alýnacak Matris";

				RandomMatrisOlustur(matris1);

				matrisYazdir(matris1, Not1);
				cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
				matrisIziniBul(matris1);
				cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
				break;
			default:
				break;
			}

			

			break;
		case 7:
			system("CLS");
			cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
			cout << "Matris Köþesi Bulma Ýþlemi" << endl;
			cout << "------------------------------------------------------------------------------------------------------------------------" << endl; cout << endl;
			cout << "A-Deðerleri Siz Girmek Ýstiyorsanýz Tuþlanýyýnýz." << endl;
			cout << "B-Random Deðerler Ýle Devam Etmek ÝStiyorsanýz Tuþlayýnýz." << endl;
			cout << "Yanýt :";	cin >> RandomSecim; cout << endl;
			switch (RandomSecim)
			{
				
			case 'A':
				
				Not1 = "Köþesi Alýnacak Matris";

				
				cout << "Matris Bilgileri" << endl;
				matrisOlustur(matris1);

				matrisYazdir(matris1, Not1);
				matrisKosesiBul(matris1);
				break;
			case 'B':
				Not1 = "Köþesi Alýnacak Matris";


				
				RandomMatrisOlustur(matris1);

				matrisYazdir(matris1, Not1);
				matrisKosesiBul(matris1);
				break;
			default:
				break;
			}
		
			break;


		default:
			cout << "HATALI NUMARA TUÞLADINIZ" << endl;
			break;
		}


		cout << "Baþka bir iþlem yapmak ister misiniz ? (E/H) "; 
		cin >> DevamMi;
		cout << endl;
		system("CLS");


	} while (DevamMi == 'e' || DevamMi == 'E');

	

	system("pause");
}

void matrisToplama(int m1[][3], int m2[][3])
{

	string Not2 = "- Matrislerin Toplamý -";

	
	

	int toplamMatrisi[3][3];
	

	//Matrislerin satýrýný çeviriyor
	for (int i = 0; i < 3; i++)
		//matrislerin sütununu çeviriyor.
		for (int j = 0; j < 3; j++)
		{
			//Denk gelen matrisleri toplayýp yeni bir matris oluþturuyor.
			toplamMatrisi[i][j] = m1[i][j] + m2[i][j];
		}

	// Matrislerin Toplamý Ekrana Yazdýrýlýyor.
	matrisYazdir(toplamMatrisi,Not2);

}
void matrisCikarma(int m1[][3], int m2[][3])
{
	
	string Not2 = " - Matrislerin Farký -";
	int cikarmaMatris[3][3];
	

	//Matrisler uygun sýrayla çýkartýlýyor.
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			cikarmaMatris[i][j] = m1[i][j] - m2[i][j];
		}

	// Matrislerin farký ekrana yazýlýyor.
	matrisYazdir(cikarmaMatris,Not2);

}

void matrisCarpma(int m1[][3], int m2[][3])
{

	string Not2 = "- Matrislerin Çarpýmý -";
	int CarpimMatrisi[3][3];
	int Toplam;
	
	
	// matrislarin satýrýný döndürüyor.
	for (int i = 0; i < 3; i++)
	{
		//matrislerin sutunlarýný donduruyor.
		for (int j = 0; j < 3; j++)
		{
			Toplam = 0;

			for (int k = 0; k < 3; k++)
			{
				//Matris çarpýmýnda denk gelen kýsýmlarý topluyor.
				Toplam += m1[i][k] * m2[k][j];
			}
			 //Toplanan kýsým matris çarpýmýnýn üyesi oluyor.
			CarpimMatrisi[i][j] = Toplam;
		}
		cout << endl;
	}
	matrisYazdir(CarpimMatrisi, Not2);

}
void matrisTranspozeAl(int m1[][3])
{
	
	string Not2;
	Not2 = "- Transpozu Alýnan Matris -";



	int TranspozMatris[3][3];

	for (int i = 0; i < 3; i++) {  // satýr sayýsý
		for (int j = 0; j < 3; j++) {// sutun sayýsý
			TranspozMatris[j][i] = m1[i][j]; // satýrlar ve sütünlar deðiþtiriliyor.
		}
	}
	// yeni matris ekrana yazdýrýlýyor.
	matrisYazdir(TranspozMatris, Not2);
}



int matrisDeterminantAl(int m1[][3],int n)
{
	
	int det = 0;
	int p, h, j, k, i;
	int temp[3][3];

	if (n == 1) {
		return m1[0][0];
	}
	else if (n == 2) {
		det = (m1[0][0] * m1[1][1] - m1[0][1] * m1[1][0]);
		return det;
	}
	else {
		for (p = 0; p < n; p++) {
			h = 0;
			k = 0;
			for (i = 1; i < n; i++) {
				for (j = 0; j < n; j++) {
					if (j == p) {
						continue;
					}
					temp[h][k] = m1[i][j];
					k++;
					if (k == n - 1) {
						h++;
						k = 0;
					}
				}
			}
			det = det + m1[0][p] * pow(-1, p)*matrisDeterminantAl(temp, n - 1);
		}
		return det;
	}
}
void matrisIziniBul(int m1[][3])
{
	int tr = 0;
	int i, j;
	
	
	
	

	for (i = 0; i < 3; i++) { //satýr
		for (j = 0; j < 3; j++) { //sutun
			if (i == j) {
				tr = tr + m1[i][j]; // satýr ve sutunun ayný oldugu kosegen elemanlarý toplanýyor.
			}
		}
	}
	//toplanan matris elemanlarý ekrana yazdýrýlýyor.
	cout <<setw(70)<< "Matrisin Ýzi :" << tr << endl;
}

void matrisKosesiBul(int m1[][3])
{
	int dizi[3];
	 int m = 3;
	 int i, j = 0;



	for (i = 0; i < m; ++i)
		for (j = 0; j < m; j++)
		{
			if (i == j)// satýr ve sutunun ayný oldugu kosegen elemanlarý bir diziye atýlyýor.
				dizi[i] = m1[i][j];	
		}

	cout << setw(78) << "Matrisin Köþegen Elemanlarý" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << setw(60) << "{";
	//dizi yazdýrýlýyor.
	for (int i = 0; i < 3; i++)
	{
		cout << dizi[i];
		if (i <2)
		{
			cout << "/";
		}
	}
	cout << "}" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
}


void matrisOlustur(int m1[][3])
{
	//satýr döndürülüyor.
	for (int i = 0; i < 3; i++)
	{
		//sütun döndürülüyor.
		for (int j = 0; j < 3; j++)
		{
			//eleman atamasý yapýlýyor.
			cout << i+1 << ". satýr " << j+1 << ". sutun elemanýný giriniz :";
			cin >> m1[i][j];
		}
		cout << endl;
	}
}

void matrisYazdir(int matris[][3], string Not)
{
	cout <<setw(74)<< Not << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	// Satýr sayýsý kadar for dönüyor.
	for (int i = 0; i < 3; i++)
	{
		cout << setw(60);
		//Sutun sayýsý kadar for dönüyor.
		for (int k = 0; k < 3; k++)
		{
			//oluþan matris bir boþluk ile beraber ekrana yazýlýyor.
			cout << matris[i][k] << "  ";
		}
		cout<<endl;
	}
	cout << endl;
}

void RandomMatrisOlustur(int m[][3])
{
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				//matrise 0-9 arasý bir deðer atanýyor.
				m[i][j] = rand() %10;
			}
			cout << endl;
		}
	}
}