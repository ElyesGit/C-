/*Elyes Lamouchi*/
#ifndef TICTACTOE_H
#define TICTACTOE_H

class ticTacToe
{	
	char tab[3][3];
	int x, y;
	char symbolMouv;
	enum etat {VICTOIRE, NULLE, CONTINUER} e;

 public:
		ticTacToe()
		{
			int i, j;
	
			for (i=0; i<=2; i++)
			{
				for (j=0; j<=2; j++)
				{
					tab[i][j]= ' ';
				}
			}	
		};
		void jouer(); 
		void affichTab();
		bool mouvValid (int, int) ;
		bool getXOMouv(char);
		etat etatJeux(); 
		~ticTacToe(){};	
		void recommence();
};

#endif
