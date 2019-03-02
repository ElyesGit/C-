/*Elyes Lamouchi*/
#include "rectangle.h"
#include <iostream>
#include <cstdlib>
using namespace std;

void rectangle::setDimension(double longu, double larg)
{
	longueur= longu;
	largeur=larg;
}

double rectangle::getLong() const
{
	double longu;
	longu = longueur;
	return longu;
}

double rectangle::getLarg() const
{
	double larg;
	larg = largeur;
	return larg;
}

double rectangle::surface() const
{
	double surface;
	surface = largeur* longueur;
	return surface;
}

double rectangle::perimeter() const
{
	double perimeter;
	perimeter = (largeur+ longueur)*2;
	return perimeter;
}

rectangle rectangle::operator + (rectangle rect) const
{
	rectangle r;
	r.longueur = longueur + rect.longueur;
	r.largeur = largeur + rect.largeur;
	return r;
}

rectangle rectangle::operator * (rectangle rect) const
{
	rectangle r;
	r.longueur = longueur * rect.longueur;
	r.largeur = largeur * rect.largeur;
	return r;
}

int rectangle::operator == (rectangle rect)
{
	if((rect.longueur== longueur) && (rect.largeur== largeur)) return 1;
	else return 0;
}

int rectangle::operator != (rectangle rect)
{
	if((rect.longueur!= longueur) && (rect.largeur!= largeur)) return 1;
	else return 0;
}


std::ostream& operator << (std::ostream & sortie, const rectangle &rect)
{
	sortie << "\nRectangle de longueur " << rect.longueur << " et de largeur " << rect.largeur;
	return sortie;
}

std::istream& operator >> (std::istream & entree, rectangle &rect)
{
	entree >> rect.longueur >> rect.largeur;
	return entree;
}

int main()
{
	rectangle rect1, rect2, rectTemp, rectSomme, rectMultiple;
	double longg, largg, perimm, surff;
	int egalite, inegalite;
	
	rect1.setDimension(2,3);
	longg= rect1.getLong();
	largg= rect1.getLarg();
	perimm= rect1.perimeter();
	surff= rect1.surface();
	
	cout << "\nOn a la longueur, la largeur, le perimetre, et la surface (dans cet ordre): " << longg << " " << largg << " " << perimm << " " << surff;

	cout << "\n\n_____________test des operateurs +, *, >> et <<_______________\n";	
	cout << "\nVeuillez ecrire la longueur et largeur de rect2 ";
	cin >> rect2;
	cout << "\nVOICI CE QUE FAIT (4 5 >>rect2):\n";
	cout << rect2;
	rectSomme = rect1+rect2;
	rectMultiple = rect1*rect2;
	cout << "\nOn a la somme de rect1 et rect2 et leur produit: " << rectSomme << " " << rectMultiple;
	
	cout << "\n\n_____________test de la pre et post incrementation________________\n";
	cout << "\nIci on test l operateur surdefini << en affichant rect1 pre_incrementee dans la premiere ligne";
	cout << "\nPuis on le post_incremente en l affichant dans la deuxieme ligne";
	cout << "\nEt enfin on affiche le resultat de la post_incrementation"; 
	

	cout << ++rect1;
	cout << rect1++;
	cout << rect1;
	
	egalite = (rect1==rect2);
	
	rect1= rect2;
	inegalite = (rect1!=rect2); 	/*on devrait avoir l egalite = 1 et l inegalite = 0*/
	
	cout << "\n\n_____________test de == et !=________________\n";
	if (egalite==1) cout << "\nIl ya egalite de rect1 et rect2";
	else cout << "\nIl n ya  pas egalite de rect1 et rect2";
	
	if (inegalite==1) cout << "\nIl ya inegalite de rect1 et rect2";
	else cout << "\nIl n ya pas egalite de rect1 et rect2";
		
	return 0;
}

/*Resultat d execution 
__________________________________________
On a la longueur, la largeur, le perimetre, et la surface (dans cet ordre): 2 3 10 6

_____________test des operateurs +, *, >> et <<_______________

Veuillez ecrire la longueur et largeur de rect2 4 5

VOICI CE QUE FAIT (4 5 >>rect2):

Rectangle de longueur 4 et de largeur 5
On a la somme de rect1 et rect2 et leur produit:
Rectangle de longueur 6 et de largeur 8
Rectangle de longueur 8 et de largeur 15

_____________test de la pre et post incrementation________________

Ici on test l operateur surdefini << en affichant rect1 pre_incrementee dans la premiere ligne
Puis on le post_incremente en l affichant dans la deuxieme ligne
Et enfin on affiche le resultat de la post_incrementation
Rectangle de longueur 3 et de largeur 4
Rectangle de longueur 3 et de largeur 4
Rectangle de longueur 4 et de largeur 5

_____________test de == et !=________________

Il ya egalite de rect1 et rect2
Il n ya pas egalite de rect1 et rect2
--------------------------------
*/












