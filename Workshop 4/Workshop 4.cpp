#include "Workshop 4.h"
#include <string>

Objet2D::Objet2D()
{
	this->tdim1 = 0;
	this->tdim2 = 0;
	this->Suivant = nullptr;
};

Objet2D::Objet2D(int tdim1, int tdim2) {
	this->tdim1 = tdim1;
	this->tdim2 = tdim2;
	this->Suivant = nullptr;
};

int Objet2D::getPerimetre()
{
	return (2 * tdim1 + 2 * tdim2);
}

int Objet2D::getAire()
{
	return (tdim1 * tdim2);
}

string Objet2D::afficheInfo()
{
	string info = "Longueur : ";
	info += to_string(tdim1);
	info += " Largueur :";
	info += to_string(tdim2);
	info += " Perimetre : ";
	info += to_string(getPerimetre());
	info += " Aire : ";
	info += to_string(getAire());
	return info;
}



Rectangle::Rectangle()
{
	this->tdim1 = 0;
	this->tdim2 = 0;
}

Rectangle::Rectangle(int tdim1, int tdim2)
{
	this->tdim1 = tdim1;
	this->tdim2 = tdim2;
}

int Rectangle::getLongueur()
{
	return tdim1;
}

int Rectangle::getLargeur()
{
	return tdim2;
}

int Rectangle::getPerimetre()
{
	return (2 * tdim1 + 2 * tdim2);
}

int Rectangle::getAire()
{
	return (tdim1 * tdim2);
}

string Rectangle::afficheInfo()
{
	string info = "Longueur : ";
	info += to_string(getLongueur());
	info += " Largueur :";
	info += to_string(getLargeur());
	info += " Perimetre : ";
	info += to_string(getPerimetre());
	info += " Aire : ";
	info += to_string(getAire());
	return info;
}



Cube::Cube()
{
	this->tcote = 0;
}

Cube::Cube(int tcote)
{
	this->tcote = tcote;
}

int Cube::getCote()
{
	return tcote;
}

int Cube::getPerimetre()
{
	return (4 * tcote);
}

int Cube::getAire()
{
	return (tcote * tcote);
}

string Cube::afficheInfo()
{
	string info = "Cote : ";
	info += to_string(tcote);
	info += " Perimetre : ";
	info += to_string(getPerimetre());
	info += " Aire : ";
	info += to_string(getAire());
	return info;
}

Stock2D::Stock2D() {
	this->tete = 0;
	this->queue = 0;
}

void Stock2D::ajouter(Objet2D *objet, int indice)
{
	Objet2D* temp = tete;
	Objet2D* p_objet = objet;
	Objet2D* suivant;
	int actuel = 0;
	while (actuel < indice)
	{
		temp = temp->getSuivant();
		actuel += 1;
	}
	suivant = temp->getSuivant();
	temp->setSuivant(p_objet);
	p_objet->setSuivant(suivant);
}

void Stock2D::supprimer(int indice) {
	Objet2D* temp = tete;
	Objet2D* precedent = NULL;
	int actuel = 0;
	while (actuel < indice+1)
	{
		precedent=temp;
		temp = temp->getSuivant();
		actuel += 1;
	}
	precedent->setSuivant(temp->getSuivant());
	temp->setSuivant(0);
}

void Stock2D::afficherInfos() {
	Objet2D* temp;
	temp = tete;
	while (temp->getSuivant() != 0)
	{
		temp->afficheInfo();
		temp = temp->getSuivant();
	}
}