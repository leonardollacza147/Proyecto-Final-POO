#include <iostream>
using namespace std;

class Categoria
{
private:
	int codCategoria;
	string nomCat;
public:
	Categoria()
	{

	}

	Categoria(int codCategoria, string nomCat)
	{
		this->codCategoria = codCategoria;
		this->nomCat = nomCat;
	}

	~Categoria()
	{

	}

	void setCodCategoria(int codCategoria)
	{
		this->codCategoria = codCategoria;
	}

	void setNomCat(string nomCat)
	{
		this->nomCat = nomCat;
	}

	int getCodCategoria()
	{
		return codCategoria;
	}

	string getNomCat()
	{
		return nomCat;
	}
};