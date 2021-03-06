// Efraín Girón Romero 15300102 5G1
#include "stdafx.h"
#include <iostream>
#include <string>
#include <time.h>
#include <iomanip>
#include <cstdlib>


using namespace std;

string nombres[21] = { "Efrain", "Andres", "Tono", "Saul", "Diego", "Vaneza", "Daniela", "Dante", "Luis", "Cornejo", "Fernando", "Bruno", "Emilio", "Esau", "Ivan", "Napoleon", "Santiago", "Luis Fer", "Obeth", "Hernesto", "Herbert" };

struct Nodo
{
	int dato;
	Nodo *sig;
}*inicio, *aux, *aux2, *nodo;

void NumeroAleatorio(int N, int arr[]);
void inicializar();
void imprime();
void limpia();
bool vacia();
void CrearCirculo(int AN[], int N);
void eliminar(int dato);
void ElegirSoldado();

int main()
{
	srand(time(NULL));
	int R = 0;
	inicializar();
	do
	{
		int NS;
		system("cls");
		cout << "                 S.0.S                      " << endl;
		cout << "Un general necesita refuersos y tiene que decidir a que soldado va a mandar por ayuda," << endl;
		cout << "para esto crea un circulo con los soldados a su disposicion y empieza a contar," << endl;
		cout << "desde cualquier soldado no tiene importancia, al soldado que sea el numero del conteo," << endl;
		cout << "el conteo es hasta un numero al asar sin importancia, ira saliendo del circulo," << endl;
		cout << "el ultimo en salir del circulo sera el que vaya por ayuda\n" << endl;
		cout << "Jugemos:\n        Concuantos soldados dispone usted general!!!\n(Max 20 - Min 2)" << endl;
		cin >> NS;
		system("cls");
		if (NS <= 1 || NS >= 21)
		{
			if (NS <= 1)
			{
				cout << "                General!!!!!!\n        Tenemos muy pocos soldados,\n        no es posible pedir refuerzos,\n        la batalla esta perdida." << endl;
			}
			else
			{
				cout << "                General!!!!!!\n        Tenemos suficientes soldados,\n        no es necesario pedir refuerzos,\n        la victoria sera nuestra." << endl;
			}
		}
		else
		{
			int NombresN[20];
			NumeroAleatorio(NS, NombresN);
			CrearCirculo(NombresN, NS);
			imprime();
			cout << "------------------------------------------------------------------------------" << endl;
			ElegirSoldado();
			cout << "------------------------------------------------------------------------------" << endl;
			imprime();
		}
		system("Pause");
		system("cls");
		limpia();
		cout << "Deceas volver a jugar\n1: Si\n2: No" << endl;
		cin >> R;
	} while (R != 2);
	return 0;
}

void NumeroAleatorio(int N, int arr[])
{
	for (int x = 0; x < N; x++)
	{
		int b = rand() % 21;
		for (int a = 0; a < x; a++)
		{
			if (arr[a] == b)
			{
				b = rand() % 21;
				a = 0;
			}
		}
		arr[x] = b;
	}
}

void inicializar()
{
	inicio = NULL;
}

bool vacia()
{
	if (inicio == NULL)
	{
		return(true);
	}
	else
	{
		return(false);
	}
}

void CrearCirculo(int AN[], int N)
{
	for (int e = 0; e < N; e++)
	{
		nodo = new Nodo;
		nodo->dato = AN[e];
		nodo->sig = NULL;
		if (vacia())
		{
			inicio = nodo;
			inicio->sig = inicio;
		}
		else
		{
			bool exit = false;
			aux = inicio;
			while (!exit)
			{
				if (aux->sig == inicio)
				{
					aux->sig = nodo;
					exit = true;
				}
				else
				{
					aux = aux->sig;
				}
			}
			nodo->sig = inicio;
		}
	}
}

void eliminar(int dato)
{
	if (dato == inicio->dato)
	{
		if (inicio->sig == inicio)
		{
			inicializar();
		}
		else
		{
			aux = inicio;
			bool exit = true;
			while (exit == true)
			{
				if (aux->sig == inicio)
				{
					aux->sig = inicio->sig;
					delete inicio;
					inicio = aux->sig;
					exit = false;
				}
				else
				{
					aux = aux->sig;
				}
			}
		}
	}
	else
	{
		bool exit = true;
		aux = inicio;
		while (exit == true)
		{
			if (aux->sig->dato == dato)
			{
				aux2 = aux->sig;
				aux->sig = aux2->sig;
				delete aux2;
				exit = false;
			}
			else
			{
				aux = aux->sig;
			}
		}
	}
}

void imprime()
{
	aux = inicio;
	do
	{
		cout << nombres[aux->dato] << " - ";
		aux = aux->sig;
	} while (aux != inicio);
	cout << endl;
}

void limpia()
{
	bool exit = true;
	aux = inicio;
	while (exit)
	{
		if (aux->sig == inicio)
		{
			aux->sig = NULL;
			exit = false;
		}
		else
		{
			aux = aux->sig;
		}
	}
	aux = inicio;
	while (inicio != NULL)
	{
		if (inicio->sig == inicio)
		{
			inicializar();
		}
		else
		{
			inicio = inicio->sig;
			delete aux;
			aux = inicio;
		}

	}
}

void ElegirSoldado()
{
	aux = inicio;
	for (int a = 0; a < (rand() % 21); a++)
	{
		aux = aux->sig;
	}
	/*inicio = aux;  Para cambiar el lugar en el que se comienza a contar
	for (int a = 0; a < (rand() % 21); a++)
	{
		aux = aux->sig;
	}*/
	cout << "El soldado que ira por refuersos es:\n" << "                              " << nombres[aux->dato] << endl;
	eliminar(aux->dato);
}