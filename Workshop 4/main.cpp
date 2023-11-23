#include "Workshop 4.h"
#include <iostream>

int main()
{
    Objet2D ob1 = Rectangle(10,10);
    Objet2D ob2 = Rectangle(62, 79);
    Objet2D ob3 = Rectangle(42, 42);

    Stock2D new_objet = Stock2D();
    new_objet.ajouter(&ob1, 0);
    new_objet.ajouter(&ob2, 1);
    new_objet.ajouter(&ob3, 2);
    new_objet.afficherInfos();
    return 0;
}