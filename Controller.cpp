#include <iostream>
#include "Controller.h"
#include <algorithm>
#include <vector>

using namespace std;

Controller::Controller()
{
	rep = Repo();
}

Controller::~Controller()
{

}

bool Controller::isempty()
{
	if (rep.len != 0) return false;
	return true;
}

bool Controller::search(Medikament d)
{
	if (isempty() == true)
	{
		return false; //there are no elements in it
	}
	for (int i = 0; i < rep.len; i++)
	{
		if ((d.getkonzentration() == rep.farm[i].getkonzentration()) and (d.getname() == rep.farm[i].getname()));
		{
			return true;

		}
	} return false;
}

void Controller::add(Medikament d)
{
		if (search(d) == false)
		{
			rep.farm[rep.len] = d;
			rep.len++;
			if (rep.len == rep.cap) //the container is full
			{
				rep.cap *= 2;
				Medikament* v = new Medikament[rep.cap];
				for (int i = 0; i < rep.len; i++)
				{
					v[i] = rep.farm[i];
				}

			delete rep.farm;
			rep.farm = v;

		}
		}
		else
		{
			for (int i = 0; i < rep.len; i++)
			{
				if ((d.getkonzentration() == rep.farm[i].getkonzentration()) and (d.getname() == rep.farm[i].getname()))
				{
					rep.farm[i].setmenge(rep.farm[i].getmenge() + d.getmenge());
				}
			}
		}
		cout << rep.len << endl;
		action a;
		a.act = 1;
		a.d = d;
		history_undo.push_back(a);
}

void Controller::remove(Medikament d)
{
	if (isempty() == true)
	{
		cout << "Container empty" << '\n';
		return;
	}
	if (search(d) == false)
	{
		cout << " The searched drug is not listed" << '\n';
		return;
	}

	Medikament m;
	for (int i = 0; i < rep.len; i++)
	{
		if ((d.getkonzentration() == rep.farm[i].getkonzentration()) and (d.getname() == rep.farm[i].getname()))
		{
			m = rep.farm[i];
			for (int k = i + 1; k < rep.len; k++)
			{
				rep.farm[k - 1] = rep.farm[k];
			}
			rep.len--;
		}
	}
	action a;
	a.act = 3;
	a, d = m;
	history_undo.push_back(a);
}

void Controller::uadd(Medikament d)
{
	if (search(d) == false)
	{
		rep.farm[rep.len] = d;
		rep.len++;
		if (rep.len == rep.cap) //the container is full
		{
			rep.cap *= 2;
			Medikament* v = new Medikament[rep.cap];
			for (int i = 0; i < rep.len; i++)
			{
				v[i] = rep.farm[i];
			}

			delete rep.farm;
			rep.farm = v;

		}
	}
	else
	{
		for (int i = 0; i < rep.len; i++)
		{
			if ((d.getkonzentration() == rep.farm[i].getkonzentration()) and (d.getname() == rep.farm[i].getname()))
			{
				rep.farm[i].setmenge(rep.farm[i].getmenge() + d.getmenge());
			}
		}
	}

	action a;
	a.act = 1;
	a.d = d;
	history_redo.push_back(a);

}

void Controller::uremove(Medikament d)
{
	if (isempty() == true)
	{
		std::cout << "Container empty\n";
		return;
	}
	if (search(d) == false)
	{
		std::cout << "The searched drug is not listed\n";
		return;
	}
	for (int i = 0; i < rep.len; ++i)
	{
		if ((d.getkonzentration() == rep.farm[i].getkonzentration()) and (d.getname() == rep.farm[i].getname()))
		{
			for (int k = i + 1; k < rep.len; ++k)
			{
				rep.farm[k - 1] = rep.farm[k];
			}
			rep.len--;
		}
	}
	action a;
	a.act = 3;
	a.d = d;
	history_redo.push_back(a);
}