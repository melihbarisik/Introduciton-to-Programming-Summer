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
	// Her seferinde bir alt sat�ra ge�erek �eklin 7 sat�r olmas�n� sa�lar
	for (int i = 0; i < 7; i++)
	{
		// �ekilde g�r�len ilk �cgeni basma islemini yapar.
		for (int j = 7; j > i; j--)
		{
			cout << "*";
		}
		
		//�ki ucgen aras�ndaki boslugu olusturur.
		for (int k = 0; k < i; k++)
		{
			cout<<"  ";
		}
		
		// �ekilde g�r�len ilk �cgeni basma islemini yapar.
		for (int j = 7; j > i; j--)
		{
			cout << "*";
		}
		cout << endl;
	}

	system("pause");
}