#pragma once
#include "Func.h"
class Opera :
	public Func
{
private:
	bool f_turno;

public:
	Opera();
	Opera(bool _f_turno, int _h_extra, int _ord_b, int _num, string _setor, string _nome, string _morada, Data _data);
	Opera(bool _f_turno, int _h_extra, int _ord_b, int _num, string _setor, string _nome, string _morada, int _d, int _m, int _a);
	virtual ~Opera();

	void SetFTurno(bool _f_turno) { f_turno = _f_turno; }

	bool GetFTurno(void) { return f_turno; }

	void Show(void);
	void ReadK(void);

	friend ostream & operator << (ostream &os, const Opera O);
	friend istream & operator >> (istream &is, Opera &O);

	void SaveFile(ofstream &os);
	void ReadFile(ifstream &is);

	float Calc_Ordenado(void);

};

