#include <iostream>
using namespace std;

class TipoPersonal
{
private:
	int codTipPer;
	string nomTipPer;
public:
	TipoPersonal()
	{

	}

	TipoPersonal(int codTipPer, string nomTipPer)
	{
		this->codTipPer = codTipPer;
		this->nomTipPer = nomTipPer;
	}

	~TipoPersonal()
	{

	}

	void setCodTipPer(int codTipPer)
	{
		this->codTipPer = codTipPer;
	}

	void setNomTipPer(string nomTipPer)
	{
		this->nomTipPer = nomTipPer;
	}

	int getCodTipPer()
	{
		return codTipPer;
	}

	string getNomTipPer()
	{
		return nomTipPer;
	}
};