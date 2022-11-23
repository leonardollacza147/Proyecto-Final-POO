#include <iostream>
using namespace std;

class RegistroClientes
{
private:
	int codCliente;
	string nomApeCliente;
	string dirCliente;
	string rucCliente;
public:
	RegistroClientes()
	{

	}

	RegistroClientes(int codCliente, string nomApeCliente, string dirCliente, string rucCliente)
	{
		this->codCliente = codCliente;
		this->nomApeCliente = nomApeCliente,
		this->dirCliente = dirCliente;
		this->rucCliente = rucCliente;
	}

	~RegistroClientes()
	{

	}

	void setCodCliente(int codCliente)
	{
		this->codCliente = codCliente;
	}

	void setNomApeCliente(string nomApeCliente)
	{
		this->nomApeCliente = nomApeCliente;
	}

	void setDirCliente(string dirCliente)
	{
		this->dirCliente = dirCliente;
	}

	void setRucCliente(string rucCliente)
	{
		this->rucCliente = rucCliente;
	}

	int getCodCliente()
	{
		return codCliente;
	}

	string getNomApeCliente()
	{
		return nomApeCliente;
	}

	string getDirCliente()
	{
		return dirCliente;
	}

	string getRucCliente()
	{
		return rucCliente;
	}
};