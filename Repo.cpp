#include "Repo.h"
#include "Domain.h"
#include <iostream>
using namespace std;

Repo::Repo()
{
	cap = 100;
	len = 0;
	farm = new Medikament[cap];
}
void Repo::show()
{
	for (int i = 0; i < len; i++)
	{
		cout << farm[i].getname() << ' ' << farm[i].getkonzentration() << ' ' << farm[i].getmenge() << ' ' << farm[i].getpreis() << '\n';
	}
}