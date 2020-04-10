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

void Controller::update(Medikament d)
{
	Medikament mm;
	if (search(d) == false)
	{
		add(d);
	}

	else
	{
		for (int i = 0; i < rep.len; i++)
		{
			if ((d.getkonzentration() == rep.farm[i].getkonzentration()) and (d.getname() == rep.farm[i].getname()))
			{
				mm = rep.farm[i];

				std::string w;

				//update the price
				cout << "Current price of the drug is: " << d.getpreis() << "\n Do you want to update it? (y/n)";
				cin >> w;
				if (w == "y")
				{
					float x;
					cout << "The new price is: ";
					cin >> x;
					rep.farm[i].setpreis(x);
				}

				//update menge
				cout << "Current amount of the drug is: " << d.getmenge() << "\n Do you want to update it? (y/n)";
				cin >> w;
				if (w == "y")
				{
					int x;
					cout << "The new amount should be: ";
					cin >> x;
					rep.farm[i].setmenge(x);
				}

			}
		}
	}
	action a;
	a.act = 2;
	a.d = mm;
	history_undo.push_back(a);
}

void Controller::u_update(Medikament d)
{
	for (int i = 0; i < rep.len; i++)
	{
		if ((d.getkonzentration() == rep.farm[i].getkonzentration()) and (d.getname() == rep.farm[i].getname()))
		{
			rep.farm[i].setpreis(d.getpreis());
			rep.farm[i].setmenge(d.getmenge());
		}
}
	action a;
	a.act = 3;
	a.d = d;
	history_redo.push_back(a);

}

void Controller::show(std::string s)
{
	if (s.length() == 0)
	{
		rep.show();
	}
	else
	{	//Repo r;
		for (int i = 0; i < rep.len; i++)
		{
			if (rep.farm[i].getname().find(s) == 0)
			{
				rep.farm[i].zeigen();
			}
		}
		//r.show()
	}
}

void Controller::name_sort()
{
	auto relation = [](Medikament a, Medikament b) {return a.getname() < b.getname();  };
	sort(rep.farm, rep.farm + rep.len, relation);

	for (int i = 0; i < rep.len; i++)
		rep.farm[i].zeigen();
}
void Controller::menge_sort(int menge)
{
	if (isempty()== true)
	{
		std::cout << "No products!\n";
	}
	else
	{
		for (int i = 0; i < rep.len; i++)
		{
			if (rep.farm[i].getmenge() < menge)
				rep.farm[i].zeigen();
		}
	}
}


void Controller::preis_sort()
{
	auto relation = [](Medikament a, Medikament b) {return a.getpreis() < b.getpreis(); };
	sort(rep.farm, rep.farm + rep.len, relation);

	for (int i = 0; i < rep.len; i++)
		rep.farm[i].zeigen();
}

void Controller::undo()
{
	if (history_undo.size() != 0)
	{
		action med = history_undo.at(history_undo.size() - 1);
		if (med.act == 1)
		{
			uremove(med.d);
		}
		else if (med.act == 2)
		{
			u_update(med.d);
		}
		else {
			uadd(med.d);
		}
		history_undo.pop_back();
		return;
	}
	cout << "Nicht moglich!" << endl;
}

//redo die letzte Operation
void Controller::redo()
{
	if (history_redo.size() != 0)
	{
		action med = history_redo.at(history_redo.size() - 1);
		if (med.act == 1)
		{
			remove(med.d);
		}
		else if (med.act == 2)
		{
			update(med.d);
		}

		else {
			add(med.d);
		}

		history_undo.pop_back();
		return;
	}
	cout << "Nicht moglich!" << endl;
}