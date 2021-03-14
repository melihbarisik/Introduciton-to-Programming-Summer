/********************************************************************************
							   SAKARYA �N�VERS�TES�
					B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�
						 B�LG�SAYAR M�HEND�SL��� B�L�M�
						   PROGRAMLAMAYA G�R�� DERS�

						   �DEV NUMARASI........:3.�DEV
						   ��RENC� ADI..........:MEL�H ENSAR BARI�IK
						   ��RENC� NUMARASI.....:
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
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl; // tam ekran� kapl�yor.
		cout << "                                              Matris Program�na Ho�Geldiniz                                             " << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;


		cout << "1- Matris Toplama" << endl;
		cout << "2- Matris ��karma" << endl;
		cout << "3- Matris �arpma" << endl;
		cout << "4- Matris Transpoze Alma" << endl;
		cout << "5- Matris Determinant�n� Bulma" << endl;
		cout << "6- Matris �zini Bulma" << endl;
		cout << "7- Matris K��esini Bulma" << endl;

		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "Yapmak istedi�iniz i�lemi tu�lan�y�z :"; cin >> secim;

		switch (secim)
		{
		case 1:
			system("CLS");
			cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
			cout << "Matris Toplama ��lemi" << endl;
			cout << "------------------------------------------------------------------------------------------------------------------------" << endl; cout << endl;

			cout << "A- De�erleri Siz Girmek �stiyorsan�z Tu�lan�y�n�z." << endl;
			cout << "B- Random De�erler �le Devam Etmek �Stiyorsan�z Tu�lay�n�z." << endl;
			
			cout << "Yan�t :";	cin >> RandomSecim; cout << endl;
			

			switch (RandomSecim)
			{
				//Manuel Kullan�m
			case 'A':
				Not1 = "Olu�turdu�unuz �lk Matris";
				Not2 = "Olu�turdu�unuz �kinci Matris";

				cout << "Birinci Matris Bilgileri" << endl;
				matrisOlustur(matris1);
				cout << "�kinci Matris Bilgileri" << endl;
				matrisOlustur(matris2);

				matrisYazdir(matris1, Not1);
				matrisYazdir(matris2, Not2);

				matrisToplama(matris1, matris2);
				break;

				//Otomatik Kullan�m
			case 'B':
				Not1 = "Olu�turulan �lk Matris";
				Not2 = "Olu�turulan �kinci Matris";

				
				RandomMatrisOlustur(matris1);
				
				RandomMatrisOlustur(matris2);

				matrisYazdir(matris1, Not1);
				matrisYazdir(matris2, Not2);

				matrisToplama(matris1, matris2);
				break;
			default:
				cout << "YANLI� TU�LADINIZ." << endl;
				break;
			}
			break;
		case 2:
			system("CLS");
			cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
			cout << "Matris ��karma ��lemi" << endl;
			cout << "------------------------------------------------------------------------------------------------------------------------" << endl; cout << endl;

			cout << "A-De�erleri Siz Girmek �stiyorsan�z Tu�lan�y�n�z." << endl;
			cout << "B-Random De�erler �le Devam Etmek �Stiyorsan�z Tu�lay�n�z." << endl;
			cout << "Yan�t :";	cin >> RandomSecim; cout << endl;

			switch (RandomSecim)
			{
			case 'A':
				

				Not1 = "Olu�turdu�unuz �lk Matris";
				Not2 = "Olu�turdu�unuz �kinci Matris";

				cout << "Birinci Matris Bilgileri" << endl;
				matrisOlustur(matris1);
				cout << "�kinci Matris Bilgileri" << endl;
				matrisOlustur(matris2);

				matrisYazdir(matris1, Not1);
				matrisYazdir(matris2, Not2);

				matrisCikarma(matris1, matris2);
					break;

			case 'B':
				

				Not1 = "Olu�turulan �lk Matris";
				Not2 = "Olu�turulan �kinci Matris";

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
			cout << "Matris �arpma ��lemi" << endl;
			cout << "------------------------------------------------------------------------------------------------------------------------" << endl; cout << endl;

			cout << "A-De�erleri Siz Girmek �stiyorsan�z Tu�lan�y�n�z." << endl;
			cout << "B-Random De�erler �le Devam Etmek �Stiyorsan�z Tu�lay�n�z." << endl;
			cout << "Yan�t :";	cin >> RandomSecim; cout << endl;
			switch (RandomSecim)
			{
			case 'A':
				Not1 = "Olu�turdu�unuz �lk Matris";
				Not2 = "Olu�turdu�unuz �kinci Matris";

				cout << "Birinci Matris Bilgileri" << endl;
				matrisOlustur(matris1);
				cout << "�kinci Matris Bilgileri" << endl;
				matrisOlustur(matris2);

				matrisYazdir(matris1, Not1);
				matrisYazdir(matris2, Not2);

				matrisCarpma(matris1, matris2);
				break;
			case 'B':
				Not1 = "Olu�turulan �lk Matris";
				Not2 = "Olu�turulan �kinci Matris";


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
			cout << "Matris Transpoz ��lemi" << endl;
			cout << "------------------------------------------------------------------------------------------------------------------------" << endl; cout << endl;

			cout << "A-De�erleri Siz Girmek �stiyorsan�z Tu�lan�y�n�z." << endl;
			cout << "B-Random De�erler �le Devam Etmek �Stiyorsan�z Tu�lay�n�z." << endl;
			cout << "Yan�t :";	cin >> RandomSecim; cout << endl;
			switch (RandomSecim)
			{
			case 'A':

				Not1 = "Transpozu Al�nacak Matris";


				cout << "Matris Bilgileri" << endl;
				matrisOlustur(matris1);

				matrisYazdir(matris1, Not1);

				matrisTranspozeAl(matris1);
				break;
			case 'B':
				Not1 = "Transpozu Al�nacak Matris";


				
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
			cout << "Matris Determinant ��lemi" << endl;
			cout << "------------------------------------------------------------------------------------------------------------------------" << endl; cout << endl;
			cout << "A-De�erleri Siz Girmek �stiyorsan�z Tu�lan�y�n�z." << endl;
			cout << "B-Random De�erler �le Devam Etmek �Stiyorsan�z Tu�lay�n�z." << endl;
			cout << "Yan�t :";	cin >> RandomSecim; cout << endl;
			switch (RandomSecim)
			{
			case 'A':
				Not1 = "- Kullan�lan Matris -";
				cout << "Matris Bilgileri" << endl;
				matrisOlustur(matris1);

				matrisYazdir(matris1, Not1);

				cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
				cout << setw(75) << "Matrisin Determinant� :" << matrisDeterminantAl(matris1, 3) << endl;
				cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
				break;
			case 'B':
				Not1 = "- Kullan�lan Matris -";
				
				RandomMatrisOlustur(matris1);

				matrisYazdir(matris1, Not1);

				cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
				cout << setw(75) << "Matrisin Determinant� :" << matrisDeterminantAl(matris1, 3) << endl;
				cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
				break;
			default:
				break;
			}
			
	
			break;
		case 6:
			system("CLS");
			cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
			cout << "Matris �zini Bulma ��lemi" << endl;
			cout << "------------------------------------------------------------------------------------------------------------------------" << endl; cout << endl;
			cout << "A-De�erleri Siz Girmek �stiyorsan�z Tu�lan�y�n�z." << endl;
			cout << "B-Random De�erler �le Devam Etmek �Stiyorsan�z Tu�lay�n�z." << endl;
			cout << "Yan�t :";	cin >> RandomSecim;  cout << endl;
			switch (RandomSecim)
			{
			case 'A':
				Not1 = "�zi Al�nacak Matris";


				cout << "�zi Al�nacak Matris Bilgileri" << endl;
				matrisOlustur(matris1);

				matrisYazdir(matris1, Not1);
				cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
				matrisIziniBul(matris1);
				cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
				break;
			case 'B':
				Not1 = "�zi Al�nacak Matris";

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
			cout << "Matris K��esi Bulma ��lemi" << endl;
			cout << "------------------------------------------------------------------------------------------------------------------------" << endl; cout << endl;
			cout << "A-De�erleri Siz Girmek �stiyorsan�z Tu�lan�y�n�z." << endl;
			cout << "B-Random De�erler �le Devam Etmek �Stiyorsan�z Tu�lay�n�z." << endl;
			cout << "Yan�t :";	cin >> RandomSecim; cout << endl;
			switch (RandomSecim)
			{
				
			case 'A':
				
				Not1 = "K��esi Al�nacak Matris";

				
				cout << "Matris Bilgileri" << endl;
				matrisOlustur(matris1);

				matrisYazdir(matris1, Not1);
				matrisKosesiBul(matris1);
				break;
			case 'B':
				Not1 = "K��esi Al�nacak Matris";


				
				RandomMatrisOlustur(matris1);

				matrisYazdir(matris1, Not1);
				matrisKosesiBul(matris1);
				break;
			default:
				break;
			}
		
			break;


		default:
			cout << "HATALI NUMARA TU�LADINIZ" << endl;
			break;
		}


		cout << "Ba�ka bir i�lem yapmak ister misiniz ? (E/H) "; 
		cin >> DevamMi;
		cout << endl;
		system("CLS");


	} while (DevamMi == 'e' || DevamMi == 'E');

	

	system("pause");
}

void matrisToplama(int m1[][3], int m2[][3])
{

	string Not2 = "- Matrislerin Toplam� -";

	
	

	int toplamMatrisi[3][3];
	

	//Matrislerin sat�r�n� �eviriyor
	for (int i = 0; i < 3; i++)
		//matrislerin s�tununu �eviriyor.
		for (int j = 0; j < 3; j++)
		{
			//Denk gelen matrisleri toplay�p yeni bir matris olu�turuyor.
			toplamMatrisi[i][j] = m1[i][j] + m2[i][j];
		}

	// Matrislerin Toplam� Ekrana Yazd�r�l�yor.
	matrisYazdir(toplamMatrisi,Not2);

}
void matrisCikarma(int m1[][3], int m2[][3])
{
	
	string Not2 = " - Matrislerin Fark� -";
	int cikarmaMatris[3][3];
	

	//Matrisler uygun s�rayla ��kart�l�yor.
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			cikarmaMatris[i][j] = m1[i][j] - m2[i][j];
		}

	// Matrislerin fark� ekrana yaz�l�yor.
	matrisYazdir(cikarmaMatris,Not2);

}

void matrisCarpma(int m1[][3], int m2[][3])
{

	string Not2 = "- Matrislerin �arp�m� -";
	int CarpimMatrisi[3][3];
	int Toplam;
	
	
	// matrislarin sat�r�n� d�nd�r�yor.
	for (int i = 0; i < 3; i++)
	{
		//matrislerin sutunlar�n� donduruyor.
		for (int j = 0; j < 3; j++)
		{
			Toplam = 0;

			for (int k = 0; k < 3; k++)
			{
				//Matris �arp�m�nda denk gelen k�s�mlar� topluyor.
				Toplam += m1[i][k] * m2[k][j];
			}
			 //Toplanan k�s�m matris �arp�m�n�n �yesi oluyor.
			CarpimMatrisi[i][j] = Toplam;
		}
		cout << endl;
	}
	matrisYazdir(CarpimMatrisi, Not2);

}
void matrisTranspozeAl(int m1[][3])
{
	
	string Not2;
	Not2 = "- Transpozu Al�nan Matris -";



	int TranspozMatris[3][3];

	for (int i = 0; i < 3; i++) {  // sat�r say�s�
		for (int j = 0; j < 3; j++) {// sutun say�s�
			TranspozMatris[j][i] = m1[i][j]; // sat�rlar ve s�t�nlar de�i�tiriliyor.
		}
	}
	// yeni matris ekrana yazd�r�l�yor.
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
	
	
	
	

	for (i = 0; i < 3; i++) { //sat�r
		for (j = 0; j < 3; j++) { //sutun
			if (i == j) {
				tr = tr + m1[i][j]; // sat�r ve sutunun ayn� oldugu kosegen elemanlar� toplan�yor.
			}
		}
	}
	//toplanan matris elemanlar� ekrana yazd�r�l�yor.
	cout <<setw(70)<< "Matrisin �zi :" << tr << endl;
}

void matrisKosesiBul(int m1[][3])
{
	int dizi[3];
	 int m = 3;
	 int i, j = 0;



	for (i = 0; i < m; ++i)
		for (j = 0; j < m; j++)
		{
			if (i == j)// sat�r ve sutunun ayn� oldugu kosegen elemanlar� bir diziye at�ly�or.
				dizi[i] = m1[i][j];	
		}

	cout << setw(78) << "Matrisin K��egen Elemanlar�" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << setw(60) << "{";
	//dizi yazd�r�l�yor.
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
	//sat�r d�nd�r�l�yor.
	for (int i = 0; i < 3; i++)
	{
		//s�tun d�nd�r�l�yor.
		for (int j = 0; j < 3; j++)
		{
			//eleman atamas� yap�l�yor.
			cout << i+1 << ". sat�r " << j+1 << ". sutun eleman�n� giriniz :";
			cin >> m1[i][j];
		}
		cout << endl;
	}
}

void matrisYazdir(int matris[][3], string Not)
{
	cout <<setw(74)<< Not << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	// Sat�r say�s� kadar for d�n�yor.
	for (int i = 0; i < 3; i++)
	{
		cout << setw(60);
		//Sutun say�s� kadar for d�n�yor.
		for (int k = 0; k < 3; k++)
		{
			//olu�an matris bir bo�luk ile beraber ekrana yaz�l�yor.
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
				//matrise 0-9 aras� bir de�er atan�yor.
				m[i][j] = rand() %10;
			}
			cout << endl;
		}
	}
}