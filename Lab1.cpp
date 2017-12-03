#include "stdafx.h"
#include "locale.h"
#include "iostream"

using namespace std;

int main()
{
	setlocale(0, "rus");

	long float g;					//���������� ��� �, �� � �
	int kg, t;
	bool needcheck = true;			//��� �������� ���� �������� ������


	while (needcheck)				//���� ����� ����������� �� ��� ���, ���� ������������ �� ����� ������������� ����� �����
	{
		cout << "������� ����� ���� � ������� (����� ������������� �����): ";
		cin >> g;

		if (!cin)					//�������� �������� ������
		{
			cout << "\n";
			cout << "�������� ���� ������� �� �������� ������ (��� ����� ������� �������). ����������, ���������� �����\n" << endl;
			cin.clear();
			cin.ignore(65535, '\n');
		}

		else if ((g < 0) || (g > 2147483647))
		{
			cout << "\n";
			cout << "�� ����� ������������� ��� ������� ������� �����. ����������, ���������� �����\n" << endl;
			cin.clear();
			cin.ignore(65535, '\n');
		}

		else
		{
			t = g / 1000000;
			kg = (g - (t * 1000000)) / 1000;
			needcheck = false;						//������� ��������� �����
		}
	}


	cout << "��� " << t;							//������ ��� ��������� ���� � ���������� �����. ��� �����

	if ((t % 100 > 10) && (t % 100 < 20)) cout << " ���� � " << kg;
	else
	{
		switch (t % 10)
		{
		case 1:
		{cout << " ����� � " << kg;		break; }

		case 2:
		case 3:
		case 4:
		{cout << " ����� � " << kg;		break; }
		default:
			cout << " ���� � " << kg;
		}
	}

	if ((kg % 100 > 10) && (kg % 100 < 20)) cout << " ���������.";		//� ��� ����������
	else
	{
		switch (kg % 10)
		{
		case 2:
		case 3:
		case 4:
		{cout << " ����������.";	break; }
		default:
			cout << " ���������.";
		}
	}

	getchar();
	getchar();
	return 0;
}