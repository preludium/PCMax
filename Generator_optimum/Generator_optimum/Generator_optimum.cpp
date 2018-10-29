#include "pch.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

int max(int[]);

int main()
{
	srand(time(NULL));
	ofstream file{ "tasks.txt" };
	int n, m, x, y, *z, a;
	cout << "Podaj liczbe procesorow: ";
	cin >> m;
	file << m << '\n';
	cout << endl;
	cout << "Podaj liczbe zadan: ";
	cin >> n;
	file << n << '\n';
	cout << endl;
	cout << "Podaj najdluzszy czas zadania: ";
	cin >> y;

	z = new int[m];
	for (int i = 0; i < m; i++)
		z[i] = 0;

	for (int i = 0; i < (n - m); i++)
	{
		x = (rand() % y) + 1;
		file << x << "\t" << i%m << '\n';
		z[i%m] += x;

	}
	a = max(z);
	x = (rand() % y) + 1;
	file << x <<"\t" << a << '\n';
	z[a] += x;

	for (int i = 0; i < m; i++)
	{
		if (z[i] < z[a])
		{
			x = z[a] - z[i];
			file << x << '\n';
		}
	}
	return 0;
}

int max(int tab[])
{
	int j = 0, k = 0;
	for (int i = 0; i < sizeof(tab) / sizeof(tab[0]); i++)
	{
		if (j < tab[i])
		{
			j = tab[i];
			k = i;
		}
	}
	return k;
}
