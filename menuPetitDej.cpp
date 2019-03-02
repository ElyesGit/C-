/* Elyes Lamouchi */
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>    /* pour utiliser la fonction roundf() */

using namespace std;

/* Definition des deux structures utilisees */
struct elemMenu
	{
		string elem;
		double prix;
	};
	
struct freqElem     /* J ai definit cette structure afin de faciliter la lecture de la frequence d un item commandé */
	{
		elemMenu elemprix;
		int freq;	
	};
	
/* Definition des fonctions utilisees */	
void chargerMenu(elemMenu *adtab);
void affichMenu(elemMenu *adtab);
void affichFact(elemMenu *adtab);


int main() {
		
	elemMenu menu[7];
	elemMenu *adtab;
	adtab = menu;				/*Assignation de la premiere case du tableau menu au pointeur adtab*/
	
	chargerMenu(adtab);			/*Appel des fonctions*/
	affichMenu(adtab);
	affichFact(adtab);
		
	return 0;
}

void chargerMenu(struct elemMenu *adtab)
{
	int i;
	string element;
	i = 0;
	char ch;									/* Chargement des donnees du fichier texte dans le tableau menu a l aide d un pointeur */
	ifstream inFile;
	inFile.open("MenuRestoIFT1166.txt");
	
	if (!inFile) {
		cout << "Impossible d’ouvrir le fichier. Fin du programme!" << endl;
	}
	while(!inFile.eof())
	{
		getline(inFile, element);
		inFile >> (adtab+i)->prix;
		(adtab+i)->elem = element;
		inFile.get(ch);
		i++;
	}

}

void affichMenu(struct elemMenu *adtab)
{
	int j;
	j = 0;

	cout << "\nVoici le menu du restaurant:\n\n";
	
	while(j<7)											/* Ici aussi j ai utilise un pointeur afin de lire les elements du tableau menu */
	{
		cout << "Item numero " << j+1 << " : " << (adtab+j)->elem << " au prix de: " << (adtab+j)->prix << "$\n";
		j++;
	}
															
	/*Indication sur la facon comment commander */
	cout << "\nAfin de commander un item du menu veillez ecrire son numero.\n";
	cout << "\nVeuillez entrer le numero de l item desire.\n";	
}


void affichFact(elemMenu *adtab)
{
	int i, l, m, s;
	double somme, taxes;								
	freqElem frqEl[30];				
	i = 0;
	m = 0;
	s = 1;
	somme = 0;

	while(cin>>l && l!=0)
	{
		switch (l)
		{
			case 1 :
					{
						frqEl[i].elemprix =*(adtab);
						cout << "Combien desirez vous de " << (adtab)->elem << "\n";
						cin >> frqEl[i].freq;
						break;
					}		
			case 2 :
					{
						frqEl[i].elemprix =*(adtab+1);
						cout << "Combien desirez vous de " << (adtab+1)->elem << "\n";
						cin >> frqEl[i].freq;
						break;
					}		
			case 3 :
					{
						frqEl[i].elemprix =*(adtab+2);
						cout << "Combien desirez vous de " << (adtab+2)->elem << "\n";
						cin >> frqEl[i].freq;
						break;
					}	
			case 4 :
					{
						frqEl[i].elemprix =*(adtab+3);
						cout << "Combien desirez vous de " << (adtab+3)->elem << "\n";
						cin >> frqEl[i].freq;
						break;
					}	
			case 5 :	
					{
						frqEl[i].elemprix =*(adtab+4);
						cout << "Combien desirez vous de " << (adtab+4)->elem << "\n";
						cin >> frqEl[i].freq;
						break;
					}	
			case 6 :
					{
						frqEl[i].elemprix =*(adtab+5);
						cout << "Combien desirez vous de " << (adtab+5)->elem << "\n";
						cin >> frqEl[i].freq;
						break;
					}	
			case 7 :
					{
						frqEl[i].elemprix =*(adtab+6);
						cout << "Combien desirez vous de " << (adtab+6)->elem << "\n";
						cin >> frqEl[i].freq;
						break;
					}	
		}
		cout << "Si vous desirer un autre item, veuillez entrer son numero. Sinon entrez 0\n";
		i++;
	}
	
	
	cout << "\n\nVoici la facture :\n";
	cout << "\nBienvenue au restaurant IFT116\n";
	cout << "--------------------------------\n";	
	
	while(m<i)
	{
		(frqEl+m)->elemprix.prix *= (frqEl+m)->freq;
		cout << (frqEl+m)->freq << "	" << (frqEl+m)->elemprix.elem << "	" << (frqEl+m)->elemprix.prix << "$\n";
		somme+= (frqEl+m)->elemprix.prix;
		m++;
	}
	
	taxes = somme*0.14975;				/*J ai calculer la somme+taxes avant d arrondir pour ne pas perdre de precision*/
	somme += taxes;

	/*Arrondissement à deux decimales des taxes et de la somme*/	
	taxes = roundf(taxes * 100) / 100;
	somme = roundf(somme * 100) / 100;

	cout << " 	Taxes	" << taxes << "$\n";
	cout << " 	Montant a payer	" << somme << "$";
}

/* Resultat d execution:

Voici le menu du restaurant:

Item numero 1 : Oeuf au prix de: 3.45$
Item numero 2 : Muffin au prix de: 1.99$
Item numero 3 : Pain grille au prix de: 2.99$
Item numero 4 : Fruits au prix de: 3.49$
Item numero 5 : Cereales au prix de: 1.69$
Item numero 6 : Cafe au prix de: 1.5$
Item numero 7 : The au prix de: 1.75$

Afin de commander un item du menu veillez ecrire son numero.

Veuillez entrer le numero de l item desire.
1
Combien desirez vous de Oeuf
2
Si vous desirer un autre item, veuillez entrer son numero. Sinon entrez 0
2
Combien desirez vous de Muffin
4
Si vous desirer un autre item, veuillez entrer son numero. Sinon entrez 0
6
Combien desirez vous de Cafe
2
Si vous desirer un autre item, veuillez entrer son numero. Sinon entrez 0
0


Voici la facture :

Bienvenue au restaurant IFT116
--------------------------------
2       Oeuf    6.9$
4       Muffin  7.96$
2       Cafe    3$
        Taxes   2.67$
        Montant a payer 20.53$
--------------------------------
*/


















