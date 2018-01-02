// Efraín Girón Romero 15300102 5G1
#include "stdafx.h"
#include <iostream>
#include <string>
#include <time.h>
#include <iomanip>
#include <cstdlib>


using namespace std;

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
bool buscar(int dato);
void insertar(int dato);
void eliminar(int dato);

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
			//crearCirculo(NS);
			//imprime();
			//SelctMensajero(NS);
			NumeroAleatorio(NS, NombresN);
			for (int x = 0; x < NS; x++)
			{
				cout << NombresN[x] << endl;
			}
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

void insertar(int dato)
{
	nodo = new Nodo;
	nodo->dato = dato;
	nodo->sig = NULL;
	if (vacia())
	{
		inicio = nodo;
		inicio->sig = inicio;
	}
	else
	{
		if (buscar(dato))
		{
			cout << "El dato ya existe en la lista\nNo se pueden repetir los datos" << endl;
		}
		else
		{
			if (dato < inicio->dato)
			{
				bool exit = true;
				aux = inicio;
				while (exit == true)
				{
					if (aux->sig == inicio)
					{
						aux->sig = nodo;
						exit = false;
					}
					else
					{
						aux = aux->sig;
					}
				}
				nodo->sig = inicio;
				inicio = nodo;
			}
			else
			{
				bool exit = true;
				aux = inicio;
				while (exit == true)
				{
					if (nodo->dato < aux->sig->dato || aux->sig == inicio)
					{
						nodo->sig = aux->sig;
						aux->sig = nodo;
						exit = false;
					}
					else
					{
						aux = aux->sig;
					}
				}
			}
		}
	}
	system("Pause");
}

void eliminar(int dato)
{
	if (vacia())
	{
		cout << "La lista ya esta vacia" << endl;
	}
	else
	{
		if (!buscar(dato))
		{
			cout << "El elemento que decea eliminar no esta en la fila" << endl;
		}
		else
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
	}
	system("Pause");
}

void imprime()
{
	if (vacia())
	{
		cout << "La lista esta vacia" << endl;
	}
	else
	{
		aux = inicio;
		do
		{
			cout << aux->dato << " - ";
			aux = aux->sig;
		} while (aux != inicio);
		cout << endl;
	}
	system("Pause");
}

void limpia()
{
	if (vacia())
	{
		cout << "La lista ya se encuentra vacia" << endl;
	}
	else
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
}

bool buscar(int dato)
{
	if (vacia())
	{
		return(false);
	}
	else
	{
		aux = inicio;
		do
		{
			if (aux->dato == dato)
			{
				return(true);
			}
			else
			{
				aux = aux->sig;
			}
		} while (aux != inicio);
		if (aux == inicio)
		{
			return(false);
		}
	}
}
