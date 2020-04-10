#include <iostream>
#include "ui.h"
#include <string>

ui::ui()
{
}

ui::~ui()
{
}

void ui::Menu()
{
	cout << "Possible commands: " << endl;
	cout << "\t 1 - Add Medicine." << endl;
	cout << "\t 2 - Delete Medicine" << endl;
	cout << "\t 3 - Update." << endl;
	cout << "\t 4 - Display by name" << endl;
	cout << "\t 5 - Display by quantity" << endl;
	cout << "\t 6 - Display by price" << endl;
	cout << "\t 7 - Undo" << endl;
	cout << "\t 8 - Redo" << endl;
	cout << "\t 0 - Exit." << endl;
}

void ui::run()
{
	Controller con = Controller();
	while (true)
	{
		ui::Menu();

		int com;
		cout << " Input the command: ";
		cin >> com;
		switch (com)
		{
		case 1:
		{
			string name;
			int m;
			float k, p;

			cout << "Fuge ein neues Medikament ein \n" << "Name:";
			cin >> name;
			cout << "Menge: ";
			cin >> m;
			cout << "Konzentration: ";
			cin >> k;
			cout << "Preis: ";
			cin >> p;
			Medikament d = Medikament(name, k, m, p);
			con.add(d);
			break;
		}
		case 2:
		{
			string name;
			int m = 0;
			float k, p = 0;
			cout << "Medikament zum loschen\n" << " Name: ";
			cin >> name;
			cout << "Konzentration: ";
			cin >> k;
			Medikament d = Medikament(name, k, m, p);
			con.remove(d);
			break;
		}
		case 3:
		{	string name;
			int m = 0;
			float k, p = 0;
			cout<< "Add new drug\n" << "Name: ";
			cin >> name;
			cout << "Konzentation: ";
			cin >> k;
			Medikament d = Medikament(name, k, m, p);
			con.update(d);
			break;

		}
		case 4:
		{
			string s;
			cout << "What are you searching for?" << endl;
			cout << "Type the first letters of the drug: ";
			getline(cin, s);
			getline(cin, s);
			if (s == "")
			{
				cout << "The string is empty!" << endl;;
				con.name_sort();
				break;
			}
			else
			{
				con.show(s);
				break;
			}
		}
		case 5:
		{
			cout << "Enter quantity: ";
			int quantity;
			cin >> quantity;
			con.menge_sort(quantity);
			break;
		}
		case 6:
		{
			con.preis_sort();
			break;
		}
		case 7:
		{
			con.undo();
			cout << "Undo succeeded" << endl;
			break;
		}
		case 8:
		{
			con.redo();
			cout << "Redo succeeded" << endl;
			break;
		}

		default:
			return;

		}

		

	}
}