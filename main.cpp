#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>
using namespace std;
enum Color {
	Black, Blue, Green, Cyan, Red,
	Magenta, Brown, LightGray, DarkGray, LightBlue, LightGreen, LightCyan,
	LightRed, LightMagenta, Yellow, White
};
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
void SetColor(Color text, Color background)
{
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}
void main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "rus");

	/*������� ������������� ������ �� 25 ���������.
	��������� ��� ���������� ���������� � ��������� �� - 15 �� 30.
	������� ������ �� ����.*/

	/*3. ������������� ������ ����� ��������� �������� � ��������� � �� �����������.
	����� � ������ �� ���� ��������� �� ��������.*/

	const int length = 25;
	int mas[length];
	for (int i = 0; i < length; i++)
	{
		mas[i] = -15 + rand() % 46;
		cout << mas[i] << "\t";
	}
	cout << "\n";
	int min = mas[0], max = mas[0], minPos = 0, maxPos = 0;
	int minNum = 0, maxNum = 0, position = 0; //��� ��� ���������� �������
	for (int i = 0; i < length; i++)
	{
		if (mas[i] < min)
		{
			min = mas[i];
			minPos = i;
		}
		if (mas[i] > max)
		{
			max = mas[i];
			maxPos = i;
		}
	}

	if (maxPos < minPos)
	{
		swap(max, min);
	}

	cout << "\nmin: " << min << " and max: " << max << "\n";

	for (int i = 0; i < minPos - 1; i++) //���������� �� �������� ����� �� ��������
	{
		maxNum = mas[i];
		position = i;
		for (int j = i + 1; j < minPos - 1; j++)
		{
			if (mas[j] > maxNum)
			{
				maxNum = mas[j];
				position = j;
			}
		}
		swap(mas[i], mas[position]);
	}
	for (int i = maxPos + 1; i < length; i++) // ���������� �� �������� ������ �� ���������
	{
		maxNum = mas[i];
		position = i;
		for (int j = i + 1; j < length; j++)
		{
			if (mas[j] > maxNum)
			{
				maxNum = mas[j];
				position = j;
			}
		}
		swap(mas[i], mas[position]);
	}
	for (int i = minPos + 1; i < maxPos - 1; i++) // ���������� ��������� ����� ��������� � ����������
		//�� �����������
	{
		minNum = mas[i];
		position = i;
		for (int j = i + 1; j < maxPos - 1; j++)
		{
			if (mas[j] < minNum)
			{
				minNum = mas[j];
				position = j;
			}
		}
		swap(mas[i], mas[position]);
	}
	cout << "\nafter sort:\n";
	for (int i = 0; i < length; i++)
	{
		cout << mas[i] << "\t";
	}


	/*5 * .������������� ��� ����������� ������������������ ������������� ��������,
		������� ������� �����, ��� �� ��� ���������.*/

	const int length = 25;
	int mas[length];
	int count = 0; //��� ����������� ���������� ������������� ���������
	for (int i = 0; i < length; i++)
	{
		mas[i] = -15 + rand() % 31;
		cout << mas[i] << "\t";
	}
	cout << "\n";
	for (int i = 0; i < length - 1; i++)
	{
		if (mas[i] < 0)
		{
			count++;
			if (mas[i + 1] >= 0)
			{
				if (count > 2)
				{
					for (int si = i - count + 1; si < i + 1; si++)
					{
						for (int sj = si + 1; sj < i + 1; sj++)
						{
							if (mas[sj] > mas[si])
							{
								swap(mas[si], mas[sj]);
							}
						}
					}

				}
				count = 0;
			}

		}
		//���� ������������������ �������� �� ����� �������
		if (i == length - 2 && mas[i + 1] < 0 && count > 1)
		{
			for (int si = i - count + 1; si < i + 2; si++)
			{
				for (int sj = si + 1; sj < i + 2; sj++)
				{
					if (mas[sj] > mas[si])
					{
						swap(mas[si], mas[sj]);
					}
				}
			}
		}
	}
	cout << "\n\n";
	for (int i = 0; i < length; i++)
	{
		cout << mas[i] << "\t";
	}
	cout << "\n\n";

}