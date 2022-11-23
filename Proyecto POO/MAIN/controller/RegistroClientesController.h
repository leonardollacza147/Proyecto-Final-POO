#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "../model/RegistroClientes.h"
using namespace std;

class RegistroClientesController
{
private:

	vector<RegistroClientes>vectorRegistroClientes;

public:

	RegistroClientesController()
	{
		cargarDatosDelArchivoAlVector();
	}

	void add(RegistroClientes obj)
	{
		vectorRegistroClientes.push_back(obj);
	}

	RegistroClientes get(int pos)
	{
		return vectorRegistroClientes[pos];
	}

	int size()
	{
		return vectorRegistroClientes.size();
	}

	int getCorrelativo()
	{
		if (size() == 0)
		{
			return 1;
		}
		else
		{
			return 	vectorRegistroClientes[size() - 1].getCodCliente() + 1;
		}
	}

	RegistroClientes buscarPorCodigo(int codigo)
	{
		RegistroClientes objError;
		objError.setNomApeCliente("Error");
		for (int i = 0; i < vectorRegistroClientes.size(); i++)
		{
			if (codigo == vectorRegistroClientes[i].getCodCliente())
			{
				return vectorRegistroClientes[i];
			}
		}
		return objError;
	}

	bool modificar(RegistroClientes obj1EsElQueSeModifica, string nomApeCliente, string dirCliente, string rucCliente)
	{
		for (int i = 0; i < vectorRegistroClientes.size(); i++)
		{
			if (obj1EsElQueSeModifica.getCodCliente() == vectorRegistroClientes[i].getCodCliente())
			{
				vectorRegistroClientes[i].setNomApeCliente(nomApeCliente);
				vectorRegistroClientes[i].setDirCliente(dirCliente);
				vectorRegistroClientes[i].setRucCliente(rucCliente);
				return true;
			}
		}
		return false;
	}

	int getPostArray(RegistroClientes obj)
	{
		for (int i = 0; i < vectorRegistroClientes.size(); i++)
		{
			if (obj.getCodCliente() == vectorRegistroClientes[i].getCodCliente())
			{
				return i;
			}
		}
		return -1;
	}

	void eliminar(RegistroClientes obj)
	{
		vectorRegistroClientes.erase(vectorRegistroClientes.begin() + getPostArray(obj));
	}

	void grabarEnArchivo(RegistroClientes obj)
	{
		try
		{
			fstream archivoRegistroClientes;
			archivoRegistroClientes.open("clientes.csv", ios::app);
			if (archivoRegistroClientes.is_open())
			{
				archivoRegistroClientes << obj.getCodCliente() << ";" << obj.getNomApeCliente() << ";" << obj.getDirCliente() << ";" << obj.getRucCliente() << endl;
				archivoRegistroClientes.close();
			}
		}
		catch (exception e)
		{
			cout << "Ocurrio un error en el archivo" << endl;
		}
	}

	void grabarModificarEnArchivo()
	{
		try
		{
			fstream archivoRegistroClientes;
			archivoRegistroClientes.open("clientes.csv", ios::out);
			if (archivoRegistroClientes.is_open())
			{
				for (RegistroClientes x : vectorRegistroClientes)
				{
					archivoRegistroClientes << x.getCodCliente() << ";" << x.getNomApeCliente() << ";" << x.getDirCliente() << ";" << x.getRucCliente() << ";" << endl;
				}
				archivoRegistroClientes.close();
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
			int i;
			size_t posi;//size_t para la cantidad de positivos que genere el computador
			string linea;
			string temporal[4];
			fstream archivoRegistroClientes;//fstream sirve para crear el flujo
			archivoRegistroClientes.open("clientes.csv", ios::in);
			if (archivoRegistroClientes.is_open())
			{
				while (!archivoRegistroClientes.eof() && getline(archivoRegistroClientes, linea))//el eof muestra los datos que existan
				{
					i = 0;
					while ((posi = linea.find(";")) != string::npos)
					{
						temporal[i] = linea.substr(0, posi);
						linea.erase(0, posi + 1);
						++i;
					}
					//stoi es para convertir un string a int
					RegistroClientes objRegistroClientes(stoi(temporal[0]), temporal[1], temporal[2], temporal[3]);
					add(objRegistroClientes);//agregando el objeto al vector
				}
			}
		}
		catch (exception e)//sirve para capturar los errores
		{
			cout << "Ocurrio un error al grabar el archivo" << endl;
		}
	}
};