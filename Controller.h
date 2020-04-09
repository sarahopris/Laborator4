#pragma once
#include "Repo.h"
#include <vector>
#include <iostream>
struct action
{
	Medikament d;
	int act;
	/*
	1. Add
	2. Update
	3. Remove
	*/
};

class Controller
{
private:
	Repo rep;
	vector<action> history_undo; //istoric de modificari
	vector<action> history_redo; //istoric de undo-uri

public:
	//constructor
	Controller();

	//destructor
	~Controller();

	//verifies if the repo is empty
	bool isempty();

	//searches for a specified Medikament 
	bool search(Medikament d);

	//add new Medikament
	void add(Medikament d);

	// undo add
	void uadd(Medikament d);

	void remove(Medikament d);

	void uremove(Medikament d);

};
