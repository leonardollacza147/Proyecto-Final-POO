#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "../model/RegistroProducto.h"
using namespace std;

class RegistroProductoController
{
private:
	vector<RegistroProducto>vectorRegistroProducto;
public:
	RegistroProductoController()
	{
		cargarDatosDelArchivoAlVector();
	}

	void add(RegistroProducto obj)
	{
		vectorRegistroProducto.push_back(obj);
	}

	RegistroProducto get(int pos)
	{
		return vectorRegistroProducto[pos];
	}

	int size()
	{
		return vectorRegistroProducto.size();
	}

	int getCorrelativo()
	{
		if (size() == 0)
		{
			return 1;
		}
		else
		{
			return 	vectorRegistroProducto[size() - 1].getCodProducto() + 1;
		}
	}

	RegistroProducto buscarPorCodigo(int codigo)
	{
		RegistroProducto objError;
		objError.setNomPro("Error");
		for (int i = 0; i < vectorRegistroProducto.size(); i++)
		{
			if (codigo == vectorRegistroProducto[i].getCodProducto())
			{
				return vectorRegistroProducto[i];
			}
		}
		return objError;
	}

	bool modificar(RegistroProducto obj1EsElQueSeModifica, string nomPro, float prePro, int stkPro, int codCategoria)
	{
		for (int i = 0; i < vectorRegistroProducto.size(); i++)
		{
			if (obj1EsElQueSeModifica.getCodProducto() == vectorRegistroProducto[i].getCodProducto())
			{
				vectorRegistroProducto[i].setNomPro(nomPro);
				vectorRegistroProducto[i].setPrePro(prePro);
				vectorRegistroProducto[i].setStkPro(stkPro);
				vectorRegistroProducto[i].setCodCategoria(codCategoria);
				return true;
			}
		}
		return false;
	}

	int getPostArray(RegistroProducto obj)
	{
		for (int i = 0; i < vectorRegistroProducto.size(); i++)
		{
			if (obj.getCodProducto() == vectorRegistroProducto[i].getCodProducto())
			{
				return i;
			}
		}
		return -1;
	}

	void eliminar(RegistroProducto obj)
	{
		vectorRegistroProducto.erase(vectorRegistroProducto.begin() + getPostArray(obj));
	}

	void grabarEnArchivo(RegistroProducto obj)
	{
		try
		{
			fstream archivoRegistroProducto;
			archivoRegistroProducto.open("productos.csv", ios::app);
			if (archivoRegistroProducto.is_open())
			{
				archivoRegistroProducto << obj.getCodProducto() << ";" << obj.getNomPro() << ";" << obj.getPrePro() << ";" << obj.getStkPro() << ";" << obj.getCodCategoria() << ";" << endl;
				archivoRegistroProducto.close();
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
			fstream archivoRegistroProducto;
			archivoRegistroProducto.open("productos.csv", ios::out);
			if (archivoRegistroProducto.is_open())
			{
				for (RegistroProducto x : vectorRegistroProducto)
				{
					archivoRegistroProducto << x.getCodProducto() << ";" << x.getNomPro() << ";" << x.getPrePro() << ";" << x.getStkPro() << ";" << x.getCodCategoria() << ";" << endl;
				}
				archivoRegistroProducto.close();
			}
		}
		catch (exception e)
		{
			cout << "Ocurrio un error al grabar el archivo";
		}
	}

	void cargarDatosDelArchivoAlVector()
	{
		try
		{
			int 	i;
			size_t 	posi;
			string 	linea;
			string 	temporal[5];
			fstream	archivoRegistroProducto;
			archivoRegistroProducto.open("productos.csv", ios::in);
			if (archivoRegistroProducto.is_open())
			{
				while (!archivoRegistroProducto.eof() && getline(archivoRegistroProducto, linea))
				{
					i = 0;
					while ((posi = linea.find(";")) != string::npos)
					{
						temporal[i] = linea.substr(0, posi);
						linea.erase(0, posi + 1);
						++i;
					}

					RegistroProducto objRegistroProducto(stoi(temporal[0]),
						temporal[1], stoi(temporal[2]),
						stoi(temporal[3]), stoi(temporal[4]));

					add(objRegistroProducto);
				}
			}
		}
		catch (exception e)
		{
			cout << "Ocurrio un error al grabar el archivo";
		}
	}
};