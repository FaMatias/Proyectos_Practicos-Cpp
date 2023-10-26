#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int fact(int n);
int coef_binomial(int n, int m);
int contar_cifras(int n);

/*
 Calcula el factorial de un numero entero n.
 Notar que no se realiza ningun control de overflow.
 13! no es representable en 32 bits.
*/
int fact(int n)
{
	int res = 1;
	for(int i=2; i<=abs(n); i++)
			res *= i;

	return res;
}

/*
Calcula el coeficiente binomial de n elementos tomados en conjuntos de k elementos.
*/
int coef_binomial(int n, int k)
{
	return fact(n) / (fact(k)  * fact(n-k));
}

/*
Cuenta la cantidad de cifras decimales que tiene
el numero n.
Ejemplo: 
	contar_cifras(100) = 3
*/
int contar_cifras(int n)
{
	int cifras = 1;

	while(n/10 > 0)
	{	
		cifras += 1;		
		n/=10;
	}

	return cifras;
}

//Programa principal
int main()
{
	//h almacenara la cantidad de niveles del triangulo.
	int h;
	cout<<"Ingrese la altura del triangulo: ";
	cin>>h;
	cout<<endl;

	/* 
	 Calculo el maximo valor que aparecera en el triangulo
	 para definir la cantidad de lugares que ocupara cada numero
	 de esta manera lograre la alineacion de los valores.
	*/
	int max_valor_binomial = coef_binomial(h-1, (h-1)/2 + (h-1)%2);
	
	/*
		La cantidad de lugares que ocupara un numero en el triangulo sera
		La cantidad de posiciones que ocupe el numero mas grande.
	*/	 
	int cifras = contar_cifras(max_valor_binomial);
	
	cout<<"El numero maximo que aparecera en el triangulo es: "<< max_valor_binomial <<endl;
	cout<<"Tiene "<< cifras <<" cifras."<<endl;
	cout<<"El triangulo de Pascal de "<< h << " niveles es: "<<endl<<endl;


	/*
		Imprimo triangulo de Pascal. Cada numero ocupa (posiblemente con espacios en blanco)
		tantas posiciones como es el valor de cifras.
	*/	
	for(int nivel=0; nivel<h; nivel++)
	{
		// imprimo el nivel "nivel"
		// comienzo con cifras*(h-1-nivel) espacios en blanco
		// para alinear este nivel con los sucesivos
		for(int i=0; i<cifras*(h-nivel); i++)
			cout<<" ";
		//imprimo los valores de los coeficientes binomiales del nivel "nivel"
		for(int j=0; j<nivel+1; j++)
		{
 			cout<< setw(cifras)<<right << coef_binomial(nivel, j);
			// Dejo cifras lugares en blanco para lograr la alineacion requerida
			for(int i=0; i<cifras; i++)
				cout<<" ";
		}
		cout<<endl; 
	}
	cout<<endl; 
	
	return 0;
}
