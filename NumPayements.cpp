/* Elyes Lamouchi */

#include<iostream>
#include<iomanip>
using namespace std;

int main ()
{
	float pret_tot, tx_annuel, tx_mensuel, paie_mensuelle;
	int n;
	n=0;
		
	cout << "Veuillez entrer le montant du pret, le taux d'interet annuel ainsi que le paiement mensuel (dans cet ordre) \n";
	cin >> pret_tot >> tx_annuel >> paie_mensuelle;
	tx_annuel /= 100;
	tx_mensuel = tx_annuel / 12;
	
	/* Pour s assurer que le pret soit techniquement payable avec le paiement mensuel saisi*/	
	while (paie_mensuelle <= tx_mensuel*pret_tot)
	{
		cout << "\nLe paiement mensuel est beaucoup trop petit, veuillez entrer un paiement mensuel plus grand ";
		cin >> paie_mensuelle;
	}
	
	/* Le n initialisé a 0 enregistre le nombre de mois necessaires pour payer le pret */	
	do
	{
		pret_tot -= (paie_mensuelle - tx_mensuel*pret_tot);
		n++;			
	}
	while (pret_tot>0);
	
		
	cout << "Le nombre de mois necessaires est " << n; 
	
	
	return 0;
}

/* Veuillez entrer le montant du pret, le taux d'interet annuel ainsi que le paiement mensuel (dans cet ordre) */
/* 1000 7.2 25 */
/* Le nombre de mois necessaires est 46 */

