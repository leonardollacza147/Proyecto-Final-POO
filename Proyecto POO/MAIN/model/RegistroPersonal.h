#include <iostream>
using namespace std;

class RegistroPersonal
{
private:
	int codPersonal;
	string nomApePer;
	string usuPer;
	string passPer;
	int codTipPer;
public:
	RegistroPersonal()
	{

	}

	RegistroPersonal(int codPersonal, string nomApePer, string usuPer, string passPer, int codTipPer)
	{
		this->codPersonal = codPersonal;
		this->nomApePer = nomApePer;
		this->usuPer = usuPer;
		this->passPer = passPer;
		this->codTipPer = codTipPer;
	}

	~RegistroPersonal()
	{

	}

	void setCodPersonal(int codPersonal)
	{
		this->codPersonal = codPersonal;
	}

	void setNomApePer(string nomApePer)
	{
		this->nomApePer = nomApePer;
	}

	void setUsuPer(string usuPer)
	{
		this->usuPer = usuPer;
	}

	void setPassPer(string passPer)
	{
		this->passPer = passPer;
	}

	void setCodTipPer(int codTipPer)
	{
		this->codTipPer = codTipPer;
	}

	int getCodPersonal()
	{
		return codPersonal;
	}

	string getNomApePer()
	{
		return nomApePer;
	}

	string getUsuPer()
	{
		return usuPer;
	}

	string getPassPer()
	{
		return passPer;
	}

	int getCodTipPer()
	{
		return codTipPer;
	}
};