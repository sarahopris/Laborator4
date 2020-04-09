#include <iostream>
#include "Domain.h"

Medikament::Medikament()
{

}


Medikament::Medikament(std::string name, float k, int m, float p)
{
	this->name = name;
	this->menge = m;
	this->preis = p;
	this->konzentration = k;
}

Medikament::~Medikament()
{

}

std::string Medikament::getname() {
	return this->name;
}

float Medikament::getkonzentration() {
	return this->konzentration;
}

int Medikament::getmenge() {
	return this->menge;
}

float Medikament::getpreis() {
	return this->preis;
}

void Medikament::setname(std::string n) {
	this->name = n;
}

void Medikament::setkonzentration(float k) {
	this->konzentration = k;
}

void Medikament::setpreis(float p) {
	this->preis = p;
}

void Medikament::setmenge(int m) {
	this->menge = m;
}

void Medikament::zeigen()
{
	cout << "Name: " << name << "Konzentration: " << konzentration << "Menge: " << menge << "Preis: " << preis << endl;
}

