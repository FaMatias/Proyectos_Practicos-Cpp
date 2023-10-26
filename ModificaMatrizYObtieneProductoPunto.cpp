#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

#define N 3
#define M 4

void extrae_col(double mat[N][M], double col[N], int c)
{
    for(int i=0; i<N; i++)
        col[i] = mat[i][c];
}

bool lineal_dependientes(double v1[N], double v2[N])
{
    for(int i=1; i<N; i++)
        if(abs(v1[i]/v2[i] - v1[i-1]/v2[i-1])> 0.00001)
            return false;
    return true;
}

void modifica_matriz(double mat[N][M])
{
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            mat[i][j] = abs(mat[i][j]);
}

void rellena_matriz(double mat[N][M])
{
        for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            do{
                cout << "Ingrese el valor " << i << "," << j <<": "<<endl;
                cin >> mat[i][j];
            }while((mat[i][j] < -100) || (mat[i][j] > 100) || (mat[i][j]==0.0));
        }
    }
}


double prod_punto(double v1[N], double v2[N])
{
     double suma = 0.0;
    for(int i=0; i<N; i++)
        suma += v1[i] * v2[i];
    return suma;
   
}

int main(){
	double mat[N][M], fil1[M], fil2[M], col1[N], col2[N];
	rellena_matriz(mat);
	cout << endl;
	cout << "Matriz ingresada:"<<endl;
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<M; j++)
		{
			cout << setw(7) << mat[i][j];
		}
		cout << endl;
	}
    modifica_matriz(mat);
    cout << endl;
    cout << "Matriz modificada:"<<endl;
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<M; j++)
		{
			cout << setw(7) << mat[i][j];
		}
		cout << endl;
	}

    for(int i=0; i<M; i++)
    {
		fil1[i] = mat[0][i];
		fil2[i] = mat[N-1][i];
		}

    cout << "El producto punto de la primer y ultima fila es: ";  
    cout << prod_punto(fil1, fil2) << endl;
    cout << endl;

    for(int j=0; j<M; j++)
    {
		extrae_col(mat, col1, j);
		for(int k=j+1; k<M; k++)
		{
			extrae_col(mat, col2, k);
			if(lineal_dependientes(col1, col2))
			{
				cout << "La columna "<< j << " es linealmente dependiente con la columna " << k << endl;
				}
			}
		}
	return 0;
}
