#pragma once
#include<list>
#include "Func.h"

#include<map>

using namespace std;

class Gestor_Func
{
private:

	list<Pessoa *> lista;

	map<int, float> map_of_salarios; //exercicio 9

public:

	Gestor_Func();
	~Gestor_Func();

	void SetLista(list<Pessoa *> _lista);
	list<Pessoa *> GetLista(void);

	void SetFunc(Pessoa *, int posicao);
	Pessoa* GetFunc(string nome);

	void AddFunc(string tipo); //alinea a
	void RemoveFunc(int num); //alinea b
	void ShowFunc(void); //alinea c
	friend ostream & operator << (ostream &os, Gestor_Func &GF); //alinea d
	friend istream &operator >> (istream &is, Gestor_Func &GF); //alinea d

	void ReadFile(ifstream &is); //alinea e
	void SaveFile(ofstream &os); //alinea f


	// ******* EXERCICIO 9 *******
	
	void GenerateMap();
	void ShowMapValue(int num);



};
