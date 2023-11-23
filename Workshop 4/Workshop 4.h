#pragma once

#include <string>

using namespace std;

class Objet2D {
private :
	Objet2D *Suivant;
protected:
	int tdim1;
	int tdim2;

public:
	Objet2D();
	Objet2D(int tdim1, int tdim2);
	virtual int getPerimetre();
	virtual int getAire();
	virtual string afficheInfo();

	void setSuivant(Objet2D* suivant) { this->Suivant = suivant; }
	Objet2D* getSuivant() { return Suivant; }
};

class Rectangle : public Objet2D {

public:
	Rectangle();
	Rectangle(int tdim1, int tdim2);
	int getLongueur();
	int getLargeur();
	virtual int getPerimetre();
	virtual int getAire();
	virtual string afficheInfo();
};

class Cube : public Rectangle {

private:
	int tcote;
public:
	Cube();
	Cube(int tcote);
	int getCote();
	int getPerimetre();
	int getAire();
	string afficheInfo();
};

class Stock2D {
private:
	Objet2D *tete;
	Objet2D *queue;
public:
	Stock2D();
	void ajouter(Objet2D *objet, int indice);
	void supprimer(int indice);
	void afficherInfos();
};