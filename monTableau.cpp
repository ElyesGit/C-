/*Elyes Lamouchi*/
#include "monTableau.h"
#include <iostream>
using namespace std;



template <class Type> int monTableau<Type>::operator == (monTableau autreTab)
{
	int i, diff, aTd;
	aTd= autreTab.debut;

	if (taille==autreTab.taille)
	{
		for (i=0; i< taille; i++)
		{
			if (mTab[debut+i]!=autreTab.mTab[aTd+i]) break;
		}	
	}
	
	if (i==taille)  return 1;
	else return 0;
}

template <class Type> int monTableau<Type>::operator != (monTableau autreTab)
{
	int i, diff, aTd;
	aTd= autreTab.debut;

	if (taille==autreTab.taille)
	{
		for (i=0; i< taille; i++)
		{
			if (mTab[debut+i]!=autreTab.mTab[aTd+i]) break;
		}	
	}
	
	if (i<taille)  return 1;
	else return 0;
}

template <class Type> void monTableau<Type>::affiche()
{
	cout << "\n\n******Affichage du tableau********\n\n";
	for (int i=debut; i< fin; i++) 
		{
			cout << mTab[i] << " | ";
		}
}

int main ()
{

	monTableau<int> tabInt1(5);
	monTableau<int> tabInt2(0,5);
	monTableau<int> tabInt3(-3,2);  /*construction de tableau par des indexes negatifs*/
	monTableau<char> tabChar(-4,3);
	
	
	for (int i= tabInt1.debut; i< tabInt1.fin; i++) 
	{
		cout << tabInt1[i] << " | ";		/* Test de l operateur surdefini [] sur instance de la classe monTableau */
	}		

	tabInt2.affiche();				/* Test de la fonction affiche qui permet de verifier si la construction a ete bien faite*/
	tabInt3.affiche();
	tabChar.affiche();					
		
	if (tabInt1==tabInt2) cout << "\n\nLes deux tables tabInt1 et tabInt2 sont egales\n";			/* Test des operateurs surdefinis == et != */
	if (tabInt3!=tabInt2) cout << "\n\nLes deux tables tabInt2 et tabInt3 ne sont pas egales\n"; 
	
	return 0;	
}

/* RESULTAT D EXECUTION 
____________________________________

Veuillez saisir 5 elements de type i
1 2 3 4 5 6

Erreur depassement de capacite du tableau, veuillez entrer le bon nombre de i


Veuillez saisir 5 elements de type i
7 8 9 10 11


Veuillez saisir 5 elements de type i
7 8 9 10 11


Veuillez saisir 5 elements de type i
12 13 14 15 16


Veuillez saisir 7 elements de type c
bonjour
7 | 8 | 9 | 10 | 11 |

******Affichage du tableau********

7 | 8 | 9 | 10 | 11 |

******Affichage du tableau********

12 | 13 | 14 | 15 | 16 |

******Affichage du tableau********

b | o | n | j | o | u | r |

Les deux tables tabInt1 et tabInt2 sont egales


Les deux tables tabInt2 et tabInt3 ne sont pas egales

--------------------------------
*/






