/* Elyes Lamouchi */
#include<iostream>
#include<iomanip> 
using namespace std;

/*Definition des fonctions*/
bool estBissextile (int);
int joursDansMois (int , int);
int nombreJours (int, int, int);


int main ()
{
	char date[11];			 /* 10 cases pour la date +1 pour le caractere nul */
	int jour, mois, annee, nbj;
	char *i;
	i=date;					/*Assignation de l adresse du premier character de la date entrée au pointeur i*/

	
	
	cout << "Veuillez entrer une date quelconque :\n";
	cin >> date;
														/*cherche le jour, le mois et l annee entre les "/" */
	jour = (*(i)-48)*10+ (*(i+1)-48);
	mois = (*(i+3)-48)*10+ (*(i+4)-48);
	annee = (*(i+6)-48)*1000+ (*(i+7)-48)*100 + (*(i+8)-48)*10 + (*(i+9)-48);
	
	
	nbj = nombreJours (jour, mois, annee);
	
	cout << "\nLe nombre de jours ecoules dans cette annee est : " << nbj << " jours.";
	

}

/* Declaration des fontions */

bool estBissextile (int annee)
{
	int s;
	if ( ((annee % 4 == 0) && (annee % 100 !=0)) || (annee % 400 ==0) )	
	{
		s=1;
		cout << "\nCette annee est bissextile.";		
	}
	else
	{
		s=0;
		cout << "\nCette annee n est pas bissextile.";	
	} 	 
	return s;
}

int joursDansMois (int mois, int annee)
{
	bool s;
	int nbjours;			
	s = estBissextile(annee);
	
	switch (--mois)
	{
		case 12 :	nbjours += 31;
		case 11 :	nbjours += 30;
		case 10 :	nbjours += 31;
		case 9 :	nbjours += 30;
		case 8 :	nbjours += 31;
		case 7 :	nbjours += 31;
		case 6 :	nbjours += 30;
		case 5 :	nbjours += 31;
		case 4 :	nbjours += 30;
		case 3 :	nbjours += 31;
		case 2 : 	if (s==1)	nbjours +=29;
					else 		nbjours +=28;
		case 1 :	nbjours += 31;			
	}
	
	return nbjours;
}

int nombreJours (int jour, int mois, int annee)
{
	int jDm, nbj;
	
	jDm = joursDansMois (mois, annee);
	nbj = jDm + jour;	
	
	return nbj;
}

/* Resultat d execution:
Veuillez entrer une date quelconque :
25/12/0400

Cette annee est bissextile.
Le nombre de jours ecoules dans cette annee est : 360 jours.
--------------------------------
*/


