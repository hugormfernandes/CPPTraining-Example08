#pragma once
#include "Opera.h"



Opera::Opera()
{
}


Opera::~Opera()
{
}

Opera::Opera(bool _f_turno, int _h_extra, int _ord_b, int _num, string _setor, string _nome, string _morada, Data _data) :Func(_h_extra, _ord_b, _num, _setor, _nome, _morada, _data)
{
	f_turno = _f_turno;
}

Opera::Opera(bool _f_turno, int _h_extra, int _ord_b, int _num, string _setor, string _nome, string _morada, int _d, int _m, int _a) : Func(_h_extra, _ord_b, _num, _setor, _nome, _morada, _d, _m, _a)
{
	f_turno = _f_turno;
}

void Opera::Show(void)
{
	Func::Show();
	if (f_turno)
		cout << "Turnos:" << "sim" << endl;
	else
		cout << "Turnos:" << "nao" << endl;
}

void Opera::ReadK(void)
{
	char op;
	Func::ReadK();
	cout << "Turnos (s/n):";
	cin >> op;
	if (op == 's')
		f_turno = true;
	else
		f_turno = false;
}


ostream & operator << (ostream &os, const Opera O)
{
	os << (Pessoa &)O;
	os << "Num: " << ((Func &)O).GetNum();
	os << "; Setor: " << ((Func &)O).GetSetor();
	os << "; Ord. base: " << ((Func &)O).GetOrd();
	os << "; Horas extra: " << ((Func &)O).GetExtra();
	if (O.f_turno)
		os << "Turnos:" << "sim" << endl;
	else
		os << "Turnos:" << "nao" << endl;

	return os;
}

istream & operator >> (istream &is, Opera &O)
{
	char aux[100], op;
	int x;

	is >> (Pessoa &)O;
	cout << "Num:";
	is >> x;
	O.SetNum(x);
	cout << "Setor:";
	is >> aux;
	O.SetSetor(aux);
	cout << "Ordenado base:";
	is >> x;
	O.SetOrd(x);
	cout << "Horas extra:";
	is >> x;
	O.SetExtra(x);
	cout << "Turnos (s/n):";
	cin >> op;
	if (op == 's')
		O.f_turno = true;
	else
		O.f_turno = false;

	return is;
}

void Opera::SaveFile(ofstream &os)
{
	Func::SaveFile(os);
	if (f_turno)
		os << "sim;";
	else
		os << "nao;";
}

void Opera::ReadFile(ifstream &is)
{
	char aux[100];

	Func::ReadFile(is);
	is.getline(aux, 100, ';');
	if (!strcmp(aux, "sim"))
		f_turno = true;
	else
		f_turno = false;
}

float Opera::Calc_Ordenado(void)
{
	if (f_turno) //flag
		return GetOrd()*1.25 + 8 * GetExtra();
	return GetOrd() + 8 * GetExtra();
}
