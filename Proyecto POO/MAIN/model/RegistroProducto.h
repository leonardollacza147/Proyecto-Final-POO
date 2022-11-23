#include <iostream>
using namespace std;

class RegistroProducto
{
private:
	int codProducto;
	string nomPro;
	float prePro;
	int stkPro;
	int codCategoria;
public:

	RegistroProducto()
	{

	}

	RegistroProducto(int codProducto, string nomPro, float prePro, int stkPro, int codCategoria)
	{
		this->codProducto = codProducto;
		this->nomPro = nomPro;
		this->prePro = prePro;
		this->stkPro = stkPro;
		this->codCategoria = codCategoria;
	}

	~RegistroProducto()
	{

	}

	//set

	void setCodProducto(int codProducto)
	{
		this->codProducto = codProducto;
	}

	void setNomPro(string nomPro)
	{
		this->nomPro = nomPro;
	}

	void setPrePro(float prePro)
	{
		this->prePro = prePro;
	}

	void setStkPro(int stkPro)
	{
		this->stkPro;
	}

	void setCodCategoria(int codCategoria)
	{
		this->codCategoria = codCategoria;
	}

	//get

	int getCodProducto()
	{
		return codProducto;
	}

	string getNomPro()
	{
		return nomPro;
	}

	float getPrePro()
	{
		return prePro;
	}

	int getStkPro()
	{
		return stkPro;
	}

	int getCodCategoria()
	{
		return codCategoria;
	}
};