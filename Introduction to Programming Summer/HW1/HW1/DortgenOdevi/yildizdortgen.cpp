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

int main()
{
	int yukselik;
	int genislik;

	cout << "Lutfen yuksekligi giriniz....:"; cin >> yukselik;
	cout << "Lutfen genisligi  giriniz.....:"; cin >> genislik;

	//Genislik s�f�r veya negartif olamaz
	while (genislik == 0 || genislik < 0)
	{
		cout << "Genislik sifir veya negatif olamaz baska bir deger giriniz."; cin >> genislik;
	}
	//Yukseklik s�f�r olamaz
	while (yukselik == 0 || yukselik < 0)
	{
		cout << "Yukseklik sifir veya negatif olamaz baska bir deger giriniz."; cin >> yukselik;
	}

	// Girilen yukseklik kadar sat�r dola��r
	for (int i = 0; i < yukselik ; i++)
	{
		// �lk ve son sat�ra genislik kadar y�ld�z yapar
		if (i == 0 || i == yukselik-1 )
		{
		
				for (int i = 0; i < genislik; i++)
				{
					cout << "*";
				}

		}

		//�lk ve son sat�r haricinde ba�� ve sonunda 1 y�ld�z olan ici bos bir s�ra yapar
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