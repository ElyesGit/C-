/* Elyes Lamouchi */

#include<iostream>
#include<iomanip>
using namespace std;

int main ()
{
	float pret_tot, interet_tot, tx_annuel, tx_mensuel, paie_mensuelle;
	interet_tot=0;
		
	cout << "Veuillez entrer le montant du pret et le taux d'interet annuel (dans cet ordre) \n";
	cin >> pret_tot >> tx_annuel;
	tx_annuel /= 100;
	tx_mensuel = tx_annuel / 12;
	
	cout << "\nAinsi q'un paiement mensuel d'un minimum de " << tx_mensuel*pret_tot << "\n"; 
	cin >> paie_mensuelle;
	
			
	while (paie_mensuelle <= tx_mensuel*pret_tot)
	{
		cout << "\nLe paiement mensuel est beaucoup trop petit, veuillez entrer un paiement mensuel plus grand \n";
		cin >> paie_mensuelle;
	}
	
	/* interet_tot intialisé à 0 va sommer l interet payé chaque mois */	
	do
	{
		pret_tot = pret_tot - (paie_mensuelle - tx_mensuel*pret_tot);
		interet_tot += (tx_mensuel*pret_tot);			
	}
	while (pret_tot>0);
	
	/* À la derniere itération de la boucle pret_tot est negatif n est pas à payer */
	/* D ou ce montant negatif doit etre soustrait du paiement mensuel fixe */	
	cout << "\nLe montant du dernier paiement mensuel est :\n" << paie_mensuelle+ pret_tot ;
	cout << "\nEt l'interet total paye apres remboursement du pret est :\n" << interet_tot;

	
	return 0;
}

/* Veuillez entrer le montant du pret et le taux d'interet annuel (dans cet ordre) */
/* 1000 7.2 */

/* Ainsi q'un paiement mensuel d'un minimum de 6 */
/* 25 */

/* Le montant du dernier paiement mensuel est : */
/* 21.9219 */
/* Et l'interet total paye apres remboursement du pret est : */
/* 140.904 */
