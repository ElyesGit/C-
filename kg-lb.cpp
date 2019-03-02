/* Elyes Lamouchi */

#include<iostream>
#include<iomanip>
using namespace std;

int main ()
{
	float poidsKg, poidsLb;
	int kg, lb;
	
	cout << "Veuillez entrer votre poids en kilogrammes ";
	cin >> poidsKg;
	poidsLb= poidsKg*2.2;
	
	/* Multiplication par cent conversion en int pour se débarasser de la partie décimale */	
	poidsLb*=100;
	poidsKg*=100;
	kg= (int)(poidsKg);
	lb= (int)(poidsLb);
	
	
	poidsLb =(float)(lb)/100;
	poidsKg =(float)(kg)/100;
	cout << "Votre poids de " << poidsKg << " en kilogrammes equivaut a " << poidsLb << " en livres ";
	
	return 0;
}

/* Veuillez entrer votre poids en kilogrammes 60.123456 */
/* Votre poids de 60.12 en kilogrammes equivaut a 132.27 en livres */


