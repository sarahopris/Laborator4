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
	friend class ui;
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

	void update(Medikament d);

	void u_update(Medikament d);

	//shows the listed drugs
	void show(std::string s);

	void name_sort(); //sort by name

	//zeigt die Medikamente mit einer kleineren Menge als eine gegebene
	void menge_sort(int menge);

	//sortiert nach Preis
	void preis_sort();

	//undo die letzte Operation
	void undo();

	//redo die letzte Operation
	void redo();
};
