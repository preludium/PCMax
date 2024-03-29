#include "pch.h"
#include <iostream>
using namespace std;

void wypis(int m, int* t, int cykl)
{
	cout << "\n\t\t Cykl nr " << cykl << " : \n";
	for (int i = 0; i < m; i++)
	{
		cout << "Proces " << i + 1 << "\t | \t ";
		for (int j = 0; j < t[i]; j++)
		{
			cout << "*";
		}
		cout << "\n";
	}
}

void zachlanny(int n, int m, int* t)
{			
	int cur = m, cykl = 1, sum, temp, ctrl;
	
	while (true)
	{
		ctrl = 0;
		sum = 0;						//sprawdzanie czy wszystkie programy sie zakonczyly
		for (int i = 0; i < m; i++)
		{
			if (t[i] == 0 && cur < n)
			{
				ctrl++;
			}
			sum+=t[i];
		}
		if (sum == 0)
		{
			wypis(m, t, cykl);
			break;
		}

		wypis(m, t, cykl);

		for (int i = 0; i < m; i++)
		{
			if (t[i] > 0 && ctrl == 0)					// zmniejszenie czasu wykonywania programow o jednostke czasu
			{
				t[i] = t[i] - 1;
			}
			else if (t[i] == 0 && cur < n)
			{
				temp = t[i];
				t[i] = t[cur];
				t[cur] = temp;
				cur++;
			}
		}
		cykl++;
	}
}

int main()
{
	int n, m;
	cout << "Ilosc programow : ";
	cin >> n;

	cout << "Ilosc procesorow : ";
	cin >> m;

	int* t = new int[n];			// tablica czasów programów
	
	for (int i = 0; i < n; i++)
	{
		cout << "Czas programu " << i + 1 << " : ";
		cin >> t[i];
	}

	zachlanny(n, m, t);

	delete[] t;
	return 0;
}