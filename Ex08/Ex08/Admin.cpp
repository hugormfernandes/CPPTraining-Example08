#pragma once
#include "Admin.h"



Admin::Admin()
{
}


Admin::~Admin()
{
}

Admin::Admin(int _h_extra, int _ord_b, int _num, string _setor, string _nome, string _morada, Data _data) :Func(_h_extra, _ord_b, _num, _setor, _nome, _morada, _data)
{
}

Admin::Admin(int _h_extra, int _ord_b, int _num, string _setor, string _nome, string _morada, int _d, int _m, int _a) : Func(_h_extra, _ord_b, _num, _setor, _nome, _morada, _d, _m, _a)
{
}

void Admin::Show(void)
{
	Func::Show();
}

void Admin::ReadK(void)
{
	Func::ReadK();
}


ostream & operator << (ostream &os, const Admin A)
{
	os << (Pessoa &)A;
	os << "Num: " << ((Func &)A).GetNum();
	os << "; Setor: " << ((Func &)A).GetSetor();
	os << "; Ord. base: " << ((Func &)A).GetOrd();
	os << "; Horas extra: " << ((Func &)A).GetExtra() << endl;

	return os;
}

istream & operator >> (istream &is, Admin &A)
{
	char aux[100], op;
	int x;

	is >> (Pessoa &)A;
	cout << "Num:";
	is >> x;
	A.SetNum(x);
	cout << "Setor:";
	is >> aux;
	A.SetSetor(aux);
	cout << "Ordenado base:";
	is >> x;
	A.SetOrd(x);
	cout << "Horas extra:";
	is >> x;
	A.SetExtra(x);

	return is;
}

void Admin::SaveFile(ofstream &os)
{
	Func::SaveFile(os);
}

void Admin::ReadFile(ifstream &is)
{
	char aux[100];

	Func::ReadFile(is);
}

float Admin::Calc_Ordenado(void)
{
	return GetOrd() + 10 * GetExtra();
}
