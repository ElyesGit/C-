/*Elyes Lamouchi*/
#ifndef COMPTBANQ_H
#define COMPTBANQ_H

class comptBanq
{	
public:		/*public pour que les fonctions membres des classes derivees puissent y avoir acces */
	int nCompte;
	double sCompte;	
 public:
 	comptBanq(int);
 	int retourNum();
 	double retourSolde();
 	void depot();
 	void retrait();
 	void affich();
	~comptBanq() {};
};

class comptCheq : public comptBanq
{
	double soldeMin;
	double fraisMensuel;
 public:
	comptCheq(int num);
	double determinFraisMois();
	void depot();
	void retrait();
	~comptCheq() {};
};

class comptEpargn : public comptBanq
{
	double tauxInteret;
 public:
	comptEpargn(int num);
	void determinInteret();
	~comptEpargn() {};
};

#endif
