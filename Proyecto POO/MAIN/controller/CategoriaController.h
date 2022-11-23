#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "../model/Categoria.h"
using namespace std;

class CategoriaController
{
private:
	vector<Categoria>vectorCategoria;
public:
	CategoriaController()
	{
		cargarDatosDelArchivoAlVector();
	}

	void add(Categoria obj)
	{
		vectorCategoria.push_back(obj);
	}

	Categoria get(int pos)
	{
		return vectorCategoria[pos];
	}

	int size()
	{
		return vectorCategoria.size();
	}

	int getCorrelativo()
	{
		if (size() == 0)
		{
			return 1;
		}
		else
		{
			return 	vectorCategoria[size() - 1].getCodCategoria() + 1;
		}
	}

	Categoria buscarPorCodigo(int codigo)
	{
		Categoria objError;
		objError.setNomCat("Error");
		for (Categoria x : vectorCategoria)
		{
			if (codigo == x.getCodCategoria())
			{
				return x;
			}
		}
		return objError;
	}

	bool modificar(Categoria obj1EsElQueSeModifica, string nomCat)
	{
		for (int i = 0; i < vectorCategoria.size(); i++)
		{
			if (obj1EsElQueSeModifica.getCodCategoria() == vectorCategoria[i].getCodCategoria())
			{
				vectorCategoria[i].setNomCat(nomCat);
				return true;
			}
		}
		return false;
	}

	int getPostArray(Categoria obj)
	{
		for (int i = 0; i < vectorCategoria.size(); i++)
		{
			if (obj.getCodCategoria() == vectorCategoria[i].getCodCategoria())
			{
				return i;
			}
		}
		return -1;
	}

	void eliminar(Categoria obj)
	{
		vectorCategoria.erase(vectorCategoria.begin() + getPostArray(obj));
	}

	void grabarEnArchivo(Categoria obj)
	{
		try
		{
			fstream archivoCategoria;
			archivoCategoria.open("categoria.csv", ios::app);
			if (archivoCategoria.is_open())
			{
				archivoCategoria << obj.getCodCategoria() << ";" << obj.getNomCat() << ";" << endl;
				archivoCategoria.close();
			}
		}
		catch (exception e)
		{
			cout << "Ocurrio un error al grabar el archivo";
		}
	}

	void grabarModificarEnArchivo()
	{
		try
		{
			fstream archivoCategoria;
			archivoCategoria.open("categoria.csv", ios::out);
			if (archivoCategoria.is_open())
			{
				for (Categoria x : vectorCategoria)
				{
					archivoCategoria << x.getCodCategoria() << ";" << x.getNomCat() << ";" << endl;
				}
				archivoCategoria.close();
			}
		}
		catch (exception e)
		{
			cout << "Ocurrio un error al modificar el archivo";
		}
	}

	void cargarDatosDelArchivoAlVector()
	{
		try
		{
			int 	i;
			size_t 	posi;
			string 	linea;
			string 	temporal[2];
			fstream	archivoCategoria;
			archivoCategoria.open("categoria.csv", ios::in);
			if (archivoCategoria.is_open())
			{
				while (!archivoCategoria.eof() && getline(archivoCategoria, linea))
				{
					i = 0;
					while ((posi = linea.find(";")) != string::npos)
					{
						temporal[i] = linea.substr(0, posi);
						linea.erase(0, posi + 1);
						++i;
					}

					Categoria objCategoria(stoi(temporal[0]), temporal[1]);

					add(objCategoria);
				}
			}
		}
		catch (exception e)
		{
			cout << "Ocurrio un error al cargar el archivo";
		}
	}
};