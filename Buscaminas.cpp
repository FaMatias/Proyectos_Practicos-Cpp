#include <stdlib.h>
#include <iostream>
using namespace std;

const int FIL = 3;
const int COL = 3;

int contarPosVacias(int tablero[FIL][COL]){
	int vacias=0;

	for(int i=0; i<FIL; i++)
		for(int j=0; j<COL; j++)
			if(tablero[i][j] == 0)
				vacias++;

	return vacias;
}

void mostrarTablero(char mascara[FIL][COL]){	
	for(int i=0; i<FIL; i++){
		for(int j=0; j<COL; j++)
				cout<< mascara[i][j] << "  ";
		cout << endl;
	}
}

void minarTablero(int tablero[FIL][COL], int bombas)
{
			for(int b=0; b<bombas; b++){
					int i,j;
					i = rand() % FIL;
					j = rand() % COL;
					tablero[i][j] = 1;
		}
}

void realizarJugada(int tablero[FIL][COL], char mascara[FIL][COL], int i, int j){
	switch(tablero[i][j]){
		case 0: mascara[i][j] = '_';break;
		case 1: mascara[i][j] = '*';break;
	}
}



bool jugadorPerdio(char mascara[FIL][COL]){
	for(int i=0; i<FIL; i++)
		for(int j=0; j<COL; j++)
			if( mascara[i][j] == '*' )
				return true;

	return false;
}

bool jugadorGano(char mascara[FIL][COL], int aDescubir){
	int posVacias = 0;
	for(int i=0; i<FIL; i++)
		for(int j=0; j<COL; j++)
			if( mascara[i][j] == '_' )
				posVacias += 1;

	return posVacias == aDescubir;
}

int main()
{
	int tab[FIL][COL];
	char masc[FIL][COL];

	for(int i=0; i<FIL; i++)
		for(int j=0; j<COL; j++){
			tab[i][j] = 0;
			masc[i][j] = '#';
		}

		int nBombas;
		cout<<"Ingrese la cantidad de bombas: "<<endl;
		cin>> nBombas;

	if(nBombas>0 && nBombas < FIL*COL){
	 	minarTablero(tab, nBombas);	
		int posADescubir = contarPosVacias(tab);
		mostrarTablero(masc);

		while(!jugadorPerdio(masc) && !jugadorGano(masc,posADescubir)){
			int i,j;
			cout<<"Ingrese dos numeros del 0 al 2 que seran de Fila y Columna: ";
			cin>> i >> j;
			cout<<endl;
			while(i<0 || i>=FIL || j<0 || j>=COL){
				cout<<"Jugada no permitida. Vuelva a ingresar!"<<endl;
				cout<<"Ingrese Fila y Columna: ";
				cin>> i >> j;
			}
			realizarJugada(tab,masc,i,j);
			mostrarTablero(masc);
		}

		cout<<"Juego Terminado!"<<endl;
		if(jugadorPerdio(masc))
				cout<<"Usted ha perdido la partida."<<endl;
		else
				cout<<"Usted gano la partida."<<endl;

	}else
		cout<<"El número de bombas debe ser mayor a 0 y menor que "<<FIL*COL<<endl;
}

