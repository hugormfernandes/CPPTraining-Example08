#pragma once
#include "Pessoa.h"
class Func : public Pessoa
{
private:
	string setor;
	int num, ord_b, h_extra;

public:
	Func();
	Func(int _h_extra, int _ord_b, int _num, string _setor, string _nome, string _morada, Data _data);
	Func(int _h_extra, int _ord_b, int _num, string _setor, string _nome, string _morada, int _d, int _m, int _a);
	virtual ~Func();

	void SetNum(int _num) { num = _num; }
	void SetSetor(string _setor) { setor = _setor; }
	void SetOrd(int _ord_b) { ord_b = _ord_b; }
	void SetExtra(int _h_extra) { h_extra = _h_extra; }

	int GetNum(void) { return num; }
	string GetSetor(void) { return setor; }
	int GetOrd(void) { return ord_b; }
	int GetExtra(void) { return h_extra; }

	virtual void Show(void);
	virtual void ReadK(void);

	//friend ostream & operator << (ostream &os, const Func F);
	//friend istream & operator >> (istream &is, Func &F);

	virtual void SaveFile(ofstream &os);
	virtual void ReadFile(ifstream &is);

	virtual float Calc_Ordenado(void) = 0;
};

