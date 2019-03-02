/*Elyes Lamouchi*/
#include "comptBanq.h"
#include <iostream>

using namespace std;

/*definition des fonction membres de la classe comtBanq*/
comptBanq::comptBanq(int num)
	{
		nCompte = num;
		sCompte = 0;
	}

int comptBanq::retourNum()
{
	int num;	
	num = nCompte;
	return num;	
}

double comptBanq::retourSolde()
{
	double solde;	
	solde = sCompte;
	return solde;	
}

void comptBanq::depot()
{
	double depot;
	cout << "\nVeuillez entrer la somme du depot : ";
	cin >> depot;
	sCompte += depot;
}

void comptBanq::retrait()
{
	double retrait;
	
	do
	{
		cout << "\nVeuillez entrer la somme du retrait : ";
		cin >> retrait;
	} while(retrait>sCompte);
	
	sCompte -= retrait;
}

void comptBanq::affich()
{
	int num;
	double solde;
	
	num = retourNum();
	solde = retourSolde();
	
	cout << "\n\nLe numero du compte bancaire est : " << num << " et le solde est : " << solde;	
}

/*definition des fonction membres de la classe comptCheq*/

comptCheq::comptCheq(int num) : comptBanq(num)
{
	cout << "\nSolde minimum compte cheque : ";
	cin >> soldeMin;
	
	cout << "\nFrais mensuel : ";
	cin >> fraisMensuel;
}

void comptCheq::depot()
{
	double depot;
	
	cout << "\nVeuillez entrer la somme du depot : ";
	cin >> depot;
	sCompte += depot;		
		
	if (sCompte < soldeMin) 
	{
		cout << "\nSolde en dessous du minimum on vous soustrait : " << fraisMensuel;
		sCompte -=fraisMensuel;
		cout << "\n\nVotre solde est a present : " << sCompte;
	}
}

void comptCheq::retrait()
{
	double retrait;

	do
	{
		cout << "\nVeuillez entrer la somme du retrait : ";
		cin >> retrait;
		if (retrait>sCompte) cout << "\nVous n avez pas assez de solde pour un tel retrait";
	} while(retrait>sCompte);
	
 	sCompte -= retrait;	
		
	if (sCompte < soldeMin) 
	{
		cout << "\nSolde en dessous du minimum on vous soustrait : " << fraisMensuel;
		sCompte -=fraisMensuel;
		cout << "\n\nVotre solde est a present : " << sCompte;
	}
}

/*definition des fonction membres de la classe comptEpargn*/
	
comptEpargn::comptEpargn(int num) : comptBanq(num)
{
	cout << "\n\nTaux interet : ";
	cin >> tauxInteret;
}

void comptEpargn::determinInteret()
{
	cout << "\n\nVous avez accumule un interet de : " << tauxInteret*sCompte;
	sCompte += (tauxInteret*sCompte);
}


/*PROGRAMME POUR TESTER LES OPERATIONS SUPPORTEES PAR LES OBJETS*/
int main ()
{	
	/*tester toutes les operations supportees par comptCheq*/
	int aNum;
	double aSolde;
	comptCheq a(2016);
	
	a.depot();		
	a.retrait();
	aNum=a.retourNum();
	aSolde=a.retourSolde();	
	cout << "\n\nVoici le resutat des fonctions retourNum : " << aNum << " et le resultat de retourSolde : " << aSolde;
	cout << "\n\nEt ceci le resutat de la fonction affich : \n";
	a.affich();
	
	cout << "\n________________________\n";	
	/*tester toutes les operations supportees par comptEpargn*/
	comptEpargn b(2017);
	b.depot();
	b.determinInteret();
	b.affich();
	return 0;
}

/*Resultat d execution:
 

Solde minimum compte cheque : 30

Frais mensuel : 10

Veuillez entrer la somme du depot : 200

Veuillez entrer la somme du retrait : 180

Solde en dessous du minimum on vous soustrait : 10

Votre solde est a present : 10

Voici le resutat des fonctions retourNum : 2016 et le resultat de retourSolde : 10

Et ceci le resutat de la fonction affich :


Le numero du compte bancaire est : 2016 et le solde est : 10
________________________


Taux interet : 0.12

Veuillez entrer la somme du depot : 100


Vous avez accumule un interet de : 12

Le numero du compte bancaire est : 2017 et le solde est : 112
*/











