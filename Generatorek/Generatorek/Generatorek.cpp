#include "pch.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{	
	srand( time( NULL ) );
	ofstream file{ "tasks.txt" };
	int n, m, x, y;
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
	
	for (int i = 0; i < n; i++)
	{
		x = (rand() % y) + 1;
		file << x << '\n';

	}

	return 0;
}