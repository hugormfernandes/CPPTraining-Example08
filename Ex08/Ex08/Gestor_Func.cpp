#pragma once
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "Gestor_Func.h"
#include "Opera.h"
#include "Func.h"
#include "Admin.h"

#include<list>

using namespace std;

Gestor_Func::Gestor_Func()
{
	if (!lista.empty())
	{
		lista.clear();
	};

}

Gestor_Func::~Gestor_Func()
{
	if (!lista.empty())
	{
		lista.clear();
	};
}

void Gestor_Func::SetLista(list<Pessoa *> _lista)
{
	if (!lista.empty())
	{
		lista.clear();
	}
	lista = _lista;
}

list<Pessoa *> Gestor_Func::GetLista()
{
	return lista;
}

void Gestor_Func::SetFunc(Pessoa *mp, int posicao)
{
	list<Pessoa*>::iterator p = lista.begin();
	if (posicao >= 0 && posicao<lista.size())
	{
		for (int i = 0; i < posicao; i++)
		{
			p++; //colocar iterador a apontar p/posicao correta e inserir
		}
		lista.insert(p, mp);
	}
	else
	{
		lista.push_back(mp);//adicionar pessoa na ultima posicao da lista, caso a posicao seja inadequada
	}
}

Pessoa* Gestor_Func::GetFunc(string nome)
{
	list<Pessoa*>::iterator p = lista.begin();
	while (p != lista.end())
	{
		if (nome == (*p)->GetNome())
		{
			return (*p);
		}
		p++;
	}
	return NULL;
}

//alinea a

///Adiciona uma nova pessoa à lista. O tipo define se é Admin ou Opera.
///tipo: Admin = "A" e Opera = "O"
void Gestor_Func::AddFunc(string tipo)
{
	list<Pessoa*>::iterator p = lista.begin();

	if (tipo=="O") //cria operario por defeito (turno=false)
	{
		p = lista.insert(p, (Opera*) new Opera);
		dynamic_cast<Opera*>(*p)->SetFTurno(false);
		dynamic_cast<Func*>(*p)->ReadK();
	}
	else if (tipo == "A") //cria administrativo por defeito
	{
		p = lista.insert(p, (Admin*) new Admin);
		dynamic_cast<Func*>(*p)->ReadK();
	}
	else
	{
		return;
	}
}

//alinea b

void Gestor_Func::RemoveFunc(int num) //remover pessoa pelo seu número de funcionário
{
	list<Pessoa*>::iterator p = lista.begin();
	while (p != lista.end())
	{
		if (dynamic_cast<Func*>(*p)->GetNum()==num)
		{
			lista.erase(p);
			return;
		}
		p++;
	}
}

//alinea c

void Gestor_Func::ShowFunc()
{
	list<Pessoa*>::iterator p = lista.begin();
	while (p != lista.end())
	{
		dynamic_cast<Func*>(*p)->Show();
		p++;
	}

}

//alinea d

ostream & operator << (ostream &os, Gestor_Func &GF)
{
	list<Pessoa*>::iterator p = GF.lista.begin();
	while (p != GF.lista.end())
	{
		dynamic_cast<Func*>(*p)->Show();
		p++;
	}
	return os;
}

istream &operator >> (istream &is, Gestor_Func &GF)
{
	int op;
	list<Pessoa*>::iterator p = GF.lista.begin();
	cout << "\n1-Operario | 2-Operario(turnos) | 3-Administrativo\n";
	cin >> op;
	if (op == 1)
	{
		p = GF.lista.insert(p, (Opera*) new Opera);
		dynamic_cast<Opera*>(*p)->SetFTurno(false);
		dynamic_cast<Func*>(*p)->ReadK();

	}
	if (op == 2)
	{
		p = GF.lista.insert(p, (Opera*) new Opera);
		dynamic_cast<Opera*>(*p)->SetFTurno(true);
		dynamic_cast<Func*>(*p)->ReadK();
	}
	if (op == 3)
	{
		p = GF.lista.insert(p, (Admin*) new Admin);
		dynamic_cast<Func*>(*p)->ReadK();
	}
	return is;
}

//alinea e

void Gestor_Func::ReadFile(ifstream &is)
{
	char aux[10]; //ler "O" ou "A"
	char aux2; //consumir caracteres indesejados (exemplo : "\n")
	list<Pessoa*>::iterator p = lista.end();

	while (is.peek() != EOF)
	{
		is.getline(aux, sizeof(aux), ':'); //ler do inicio da onva linha até ao ":"
		if (strcmp(aux, "O")==0)
		{
			p = lista.insert(p, (Opera*) new Opera); //insere na posicao da lista imediatamente anterior à apontada por p
			dynamic_cast<Opera*>(*p)->ReadFile(is);
			p++; // como o insert coloca o novo nó na posicao imediatamente anterior à apontada por p, no final da insercao avançamos uma posicao na lista
			is.get(aux2); //consumir o "\n" do fim de linha
		}
		if (strcmp(aux, "A") == 0)
		{
			p = lista.insert(p, (Admin*) new Admin);
			dynamic_cast<Admin*>(*p)->ReadFile(is);
			p++; // como o insert coloca o novo nó na posicao imediatamente anterior à apontada por p, no final da insercao avançamos uma posicao na lista
			is.get(aux2); //consumir o "\n" do fim de linha
		}
	}
}

//alinea f

void Gestor_Func::SaveFile(ofstream &os)
{
	list<Pessoa*>::iterator p = lista.begin();
	Opera *O = new Opera; Admin *A = new Admin;
	while (p != lista.end())
	{
		if (dynamic_cast<Admin*>(*p)!=NULL) //é admin
		{
			os << "A:";
			dynamic_cast<Admin*>(*p)->SaveFile(os);
		}
		if (dynamic_cast<Opera*>(*p)!=NULL) //verifica se é Operario
		{
			os << "O:";
			dynamic_cast<Opera*>(*p)->SaveFile(os);
		}
		os << "\n";
		p++;
	}

}


//EXERCICIO 9


void Gestor_Func::GenerateMap()
{
	list<Pessoa*>::iterator p = lista.begin();
	while (p != lista.end())
	{
		if (map_of_salarios.insert(make_pair(dynamic_cast<Func*>(*p)->GetNum(), dynamic_cast<Func*>(*p)->Calc_Ordenado())).second == false)
		{
			cout << "\nFuncionario com o numero " << dynamic_cast<Func*>(*p)->GetNum() << " nao foi inserido na tabela de vencimentos porque ja existe!";
		}
		p++;
	}
		
	return;
}

void Gestor_Func::ShowMapValue(int num)
{
	if (map_of_salarios.find(num) != map_of_salarios.end())
	{
		cout << "\nVencimento do funcionario = " << map_of_salarios[num] << "Euros.\n";
	}
	return;
}