/*Elyes Lamouchi*/
#include "ticTacToe.h"
#include <iostream>
#include <cstdlib>

using namespace std;


void ticTacToe::jouer() 
{

	int joueur;
	int j;
	bool get;
	
	e = CONTINUER;
	get=1;
	j=0;
			
	while(j<9 && get!=0)
	{
		affichTab();
		
		joueur = j % 2;
		if (joueur==0)	symbolMouv='X';					/*si j est paire alors c est X qui joue et si j est impaire c est O qui joue*/		
		else			symbolMouv='O';	

		get = getXOMouv(symbolMouv);
		system("CLS");
		j++;
	}
	affichTab();
	if (e==VICTOIRE) cout << "\nLe gagnant est le joueur numero : "<< symbolMouv << " bravo!\n";
	else if (e!=VICTOIRE) cout << "\nAucun gagnant match nul";
	recommence();
}


bool ticTacToe::getXOMouv(char symbolMouv)
{
	bool get, v;
	get=1;
	v=0;
	
	while(v==0)
	{
		cout << "\nJoueur " << symbolMouv << " veuillez entrer la ligne et la colonne de la case choisie : ";
		cin >> x >> y;
		v = mouvValid(x,y);
	}	

	tab[x-1][y-1]=symbolMouv;
	e = etatJeux();
	if (e!=CONTINUER) get = 0;
	return get;
}


void ticTacToe::affichTab ()
{
	int a, b;
	for (a=0; a<=2; a++)
	{
		cout << "\n___________\n";
		for (b=0; b<=2; b++)
		{
			cout << tab[a][b] << " | ";
		}
	}	
}


bool ticTacToe::mouvValid (int x, int y)
{
	bool valid;
	if ( tab[x-1][y-1]== ' ') valid =1;
	else
	{
		valid =0;
		cout << "\nVeuillez choisir une case vide\n";
	}
	return valid;
}


ticTacToe::etat ticTacToe::etatJeux()
{
	int c;
	
	if ((tab[0][0]=='X' && tab[1][1]=='X' && tab[2][2]=='X')||(tab[0][2]=='X' && tab[1][1]=='X' && tab[2][0]=='X'))
	{
		e= VICTOIRE;
		symbolMouv = 'X';
	}
	
	else if ((tab[0][0]=='O' && tab[1][1]=='O' && tab[2][2]=='O')||(tab[0][2]=='O' && tab[1][1]=='O' && tab[2][0]=='O'))
	{
		e= VICTOIRE;
		symbolMouv = 'O';
	}
	
	else 
	{
		for (c=0; c<=2; c++)
		{	
			if (tab[c][0]=='X' && tab[c][1]=='X' && tab[c][2]=='X') 
			{
				e= VICTOIRE;
				symbolMouv = 'X';
				break;
			}
			else if (tab[0][c]=='X' && tab[1][c]=='X' && tab[2][c]=='X')
			{
				e= VICTOIRE;
				symbolMouv = 'X';
				break;
			}
			else if (tab[c][0]=='O' && tab[c][1]=='O' && tab[c][2]=='O') 
			{
				e= VICTOIRE;
				symbolMouv = 'O';
				break;
			}
			else if (tab[0][c]=='O' && tab[1][c]=='O' && tab[2][c]=='O') 
			{
				e= VICTOIRE;
				symbolMouv = 'O';
				break;
			}
			else e = CONTINUER;
		}
	}	

	return e;
}


void ticTacToe::recommence ()
{
	int rep;
	cout << "\n\nVoudrez vous jouer une autre partie, si oui faites 1 : ";
	cin >> rep;	
	ticTacToe b;
	if (rep==1)	b.jouer();
}

int main ()
{
	ticTacToe a;
	a.jouer();
	return 0;
}

/*Exemples de resultats d execution
____________________________________________
Exemple 1 : Un seul jeu avec victoire de O:


___________
X | X | O |
___________
  | O |   |
___________
O |   | X |
Le gagnant est le joueur numero : O bravo!


Voudrez vous jouer une autre partie, si oui faites 1 : 0
_________________________________________________________
Exemple 2 : 2 jeux avec partie nulle, puis comencement d une nouvelle partie:

___________
X | X | O |
___________
O | O | X |
___________
X | O | X |
Aucun gagnant match nul

Voudrez vous jouer une autre partie, si oui faites 1 : 1

___________
  |   |   |
___________
  |   |   |
___________
  |   |   |
Joueur X veuillez entrer la ligne et la colonne de la case choisie :
______________________________________________________________________
Exemple 3 :erreur de mouvement non valide:

___________
X |   |   |
___________
  | O |   |
___________
  |   |   |
Joueur X veuillez entrer la ligne et la colonne de la case choisie : 2 2

Veuillez choisir une case vide

Joueur X veuillez entrer la ligne et la colonne de la case choisie :
*/


