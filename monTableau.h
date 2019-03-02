/*Elyes Lamouchi*/
#ifndef MONTABLEAU_H
#define MONTABLEAU_H
#include <typeinfo>
#include <iostream>
#include <string>
using namespace std;


template <class Type> class monTableau
{
 public:			/* Pour qu on puisse y acceder a int main() */
	int taille;
	int debut;
	int fin;
	Type mTab[45]; /*45 etant la taille maximale du tableau*/
	
 public:
 	monTableau(int n)
 	{
 		int i, j, depassement;
 		Type c;
 		taille=n;
 		debut=0;
 		fin= taille;
 		if (0 <=taille && taille <45) 
 		{
 			do
 			{
 				depassement=0;
 				i=0;
  				cout << "\n\nVeuillez saisir " << taille << " elements de type " << typeid(*mTab).name() << "\n";
				while ((i<taille)&&(cin>>c))
				{	
					mTab[i]= c;	
					i++;
				}
				if(cin.get() == '\n') break;
				else
				{
					cout << "\nErreur depassement de capacite du tableau, veuillez entrer le bon nombre de " << typeid(*mTab).name() << "\n";	
					depassement= 1;
				}
				cin.ignore(INT_MAX, '\n');
 			}
			while(depassement);
		}
 	};
 	
	monTableau(int deb, int fn )
 	{
 		Type c;
 		Type* adr;
 		int i, depassement;
		
		 if (fn<=0) 
		{
			debut=-deb;
			fin=-fn;	
		}	
 		if ((deb<=0) && (fn>=0))
 		{
 			debut=-deb;
 			fin =fn +(2*debut);
		}
		
		taille= fin -debut;
 		
 		if (0 <=debut && fin <45) 
 		{
 			do
 			{
 				depassement=0;
 				i=debut;
  				cout << "\n\nVeuillez saisir " << taille << " elements de type " <<  typeid(*mTab).name() << "\n";
				while ((i<fin)&&(cin>>c))
				{	
					mTab[i]= c;	
					i++;
				}
				if(cin.get() == '\n') break;
				else
				{
					cout << "\nErreur depassement de capacite du tableau, veuillez entrer le bon nombre de " << typeid(*mTab).name() << "\n";	
					depassement= 1;
				}
				cin.ignore(INT_MAX, '\n');
 			}
			while(depassement);
		}
 	};		
 
 	
	Type &operator[] (int i) 
	{	
		if (debut <=i && i < fin) 
		{
			return mTab[i]; 
		}
		else cout << "\nErreur indice hors du tableau\n";
	};
	
	int operator == (monTableau);
	int operator != (monTableau);
	
	~monTableau(){}	;
	void affiche ();
};


#endif

