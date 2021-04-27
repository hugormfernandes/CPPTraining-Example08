#pragma once
#include "Func.h"



Func::Func()
{
}


Func::~Func()
{
}

Func::Func(int _h_extra, int _ord_b, int _num, string _setor, string _nome, string _morada, Data _data) :Pessoa(_nome, _morada, _data)
{
	setor = _setor;
	num = _num;
	ord_b = _ord_b;
	h_extra = _h_extra;
}

Func::Func(int _h_extra, int _ord_b, int _num, string _setor, string _nome, string _morada, int _d, int _m, int _a) :Pessoa(_nome, _morada, _d, _m, _a)
{
	setor = _setor;
	num = _num;
	ord_b = _ord_b;
	h_extra = _h_extra;
}

void Func::Show(void)
{
	Pessoa::Show();
	cout << "Horas extra:" << h_extra << " Ord. Base:" << ord_b << " Num:" << num << " Setor:" << setor << "\n";
}

void Func::ReadK(void)
{
	Pessoa::ReadK();
	cout << "Horas extra:";
	cin >> h_extra;
	cout << "Ord. Base:";
	cin >> ord_b;
	cout << "Num:";
	cin >> num;
	cout << "Setor:";
	cin >> setor;
}

/*
ostream & operator << (ostream &os, const Func F)
{
os << (Pessoa &)F;
os << "Num: " << F.num;
os << "; Setor: " << F.setor;

return os;
}

istream & operator >> (istream &is, Func &F)
{
char aux[100];

is >> (Pessoa &)F;
cout << "Num:";
is >> F.num;
cout << "Setor:";
is >> aux;
F.setor = aux;

return is;
}
*/

void Func::SaveFile(ofstream &os)
{
	Pessoa::SaveFile(os);
	os << h_extra << ";" << ord_b << ";" << num << ";" << setor << ";";
}

void Func::ReadFile(ifstream &is)
{
	char aux[100];

	Pessoa::ReadFile(is);
	is.getline(aux, 100, ';');
	num = atoi(aux);
	is.getline(aux, 100, ';');
	setor = aux;
	is.getline(aux, 100, ';');
	ord_b = atoi(aux);
	is.getline(aux, 100, ';');
	h_extra = atoi(aux);
}
