/*Elyes Lamouchi*/
#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <iostream>
using namespace std;

class rectangle
{
	double longueur, largeur;

 public:
 	void setDimension(double longu, double larg); /* J ai ecrit longu a la place de long pour ne pas confondre avec le type long*/
 	double getLong() const;
 	double getLarg() const;
 	double surface() const;
 	double perimeter() const;
 	/*Surdefinition des operateurs */
 	rectangle operator + (rectangle) const;
 	rectangle operator * (rectangle) const;
	int operator == (rectangle);
	int operator != (rectangle);
	friend ostream & operator << (ostream &, const rectangle &);
	friend istream & operator >> (istream &, rectangle &);
	
	rectangle operator ++ ()	/*Pre-incrementation*/
	{
		longueur++;
		largeur++;
		return *this;	
	}
	rectangle operator ++ (int)	/*Post*/
	{
		rectangle r=*this;
		longueur++;
		largeur++;
		return r;	
	}
};

#endif
