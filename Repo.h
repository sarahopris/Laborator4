#pragma once
#include "Domain.h"
#include <iostream>

using namespace std;

class Repo
{
	friend class Controller;
private:
	Medikament* farm;
	int cap, len;
public:
	//constructor
	Repo();

	//alle Medikamente zeigen
	void show();

};