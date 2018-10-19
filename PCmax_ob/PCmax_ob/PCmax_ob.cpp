

#include "pch.h"
#include <iostream>
#include<vector>
#include <fstream>

using namespace std;

class processor
{	
	vector<int> tasks;
public:
	int sum;
	processor();
	void add(int);
	void show();
};

void greedy(processor *, int);

int main()
{
	int m, x;
	ifstream file;
	file.open("C:\\Users\\barte\\Documents\\Studia\\Semestr 3\\Optymalizacja kombinatoryczna\\PCmax_ob\\Debug\\tasks.txt");
	if (file.good())
	{
		cout << "Ile procesorow: ";
		cin >> m;
		cout << endl;

		processor *tab = new processor[m];

		while (!file.fail())
		{
			file >> x;
			greedy(tab, x);
		}

		for (int i = 0; i < m; i++)
		{
			tab[i].show();
		}

		file.close();
		delete[] tab;
	
	}
	else
		cout << "Blad programu!";
	return 0;


}

processor::processor()
{
	sum = 0;
}

void processor::add(int a)
{
	sum += a;
	tasks.push_back(a);
}

void processor::show()
{	
	cout << "Suma: " << sum << endl;
	cout << "Zadania:\t";
	for(int i = 0; i < tasks.size(); i++)
		cout << tasks[i] << "\t";
	cout << endl;	
}

void greedy(processor * tab, int a)
{
	int y = tab[0].sum, index;
	for (int i = 0; i < sizeof(tab); i++)
	{
		if (tab[i].sum <= y)
		{
			y = tab[i].sum;
			index = i;
		}
	}
	tab[index].add(a);

}
