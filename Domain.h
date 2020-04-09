#pragma once
using namespace std;
#include <iostream>
#include <string>

class Medikament
{
private:
	string name;
	float konzentration, preis;
	int menge;

public:
	//constructor
	Medikament();
	Medikament(string name, float k, int m, float p);

	//destructor
	~Medikament();

	//name getter 
	string getname();

	//konzentration getter
	float getkonzentration();
	
	//preis getter
	float getpreis();

	//menge getter
	int getmenge();
    
	//name setter
	void setname(string name);

	//konzentration setter
	void setkonzentration(float k);

	//preis setter
	void setpreis(float p);

	//menge setter
	void setmenge(int m);

	void zeigen();
};