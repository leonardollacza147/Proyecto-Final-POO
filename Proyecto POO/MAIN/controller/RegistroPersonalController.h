#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "../model/RegistroPersonal.h"
using namespace std;

class RegistroPersonalController
{
private:
	vector<RegistroPersonal>vectorRegistroPersonal;
public:
	RegistroPersonalController()
	{
		cargarDatosDelArchivoAlVector();
	}

	void add(RegistroPersonal obj)
	{
		vectorRegistroPersonal.push_back(obj);
	}

	RegistroPersonal get(int pos)
	{
		return vectorRegistroPersonal[pos];
	}

	int size()
	{
		return vectorRegistroPersonal.size();
	}

	int getCorrelativo()
	{
		if (size() == 0)
		{
			return 1;
		}
		else
		{
			return 	vectorRegistroPersonal[size() - 1].getCodPersonal() + 1;
		}
	}

	RegistroPersonal buscarPorCodigo(int codigo)
	{
		RegistroPersonal objError;
		objError.setNomApePer("Error");
		for (int i = 0; i < vectorRegistroPersonal.size(); i++)
		{
			if (codigo == vectorRegistroPersonal[i].getCodPersonal())
			{
				return vectorRegistroPersonal[i];
			}
		}
		return objError;
	}

	bool modificar(RegistroPersonal obj1EsElQueSeModifica, string nomApePer, string usuPer, string passPer, int codTipPer)
	{
		for (int i = 0; i < vectorRegistroPersonal.size(); i++)
		{
			if (obj1EsElQueSeModifica.getCodPersonal() == vectorRegistroPersonal[i].getCodPersonal())
			{
				vectorRegistroPersonal[i].setNomApePer(nomApePer);
				vectorRegistroPersonal[i].setUsuPer(usuPer);
				vectorRegistroPersonal[i].setPassPer(passPer);
				vectorRegistroPersonal[i].setCodTipPer(codTipPer);
				return true;
			}
		}
		return false;
	}

	int getPostArray(RegistroPersonal obj)
	{
		for (int i = 0; i < vectorRegistroPersonal.size(); i++)
		{
			if (obj.getCodPersonal() == vectorRegistroPersonal[i].getCodPersonal())
			{
				return i;
			}
		}
		return -1;
	}

	void eliminar(RegistroPersonal obj)
	{
		vectorRegistroPersonal.erase(vectorRegistroPersonal.begin() + getPostArray(obj));
	}

	void grabarEnArchivo(RegistroPersonal obj)
	{
		try
		{
			fstream archivoRegistroPersonal;
			archivoRegistroPersonal.open("personal.csv", ios::app);
			if (archivoRegistroPersonal.is_open())
			{
				archivoRegistroPersonal << obj.getCodPersonal() <<";" << obj.getNomApePer() << ";" << obj.getUsuPer() << obj.getPassPer() << ";" << obj.getCodTipPer() << endl;
				archivoRegistroPersonal.close();
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
			fstream archivoRegistroPersonal;
			archivoRegistroPersonal.open("personal.csv", ios::out);
			if (archivoRegistroPersonal.is_open())
			{
				for (RegistroPersonal x : vectorRegistroPersonal)
				{
					archivoRegistroPersonal <<x.getCodPersonal()<< ";" << x.getNomApePer() << ";" << x.getUsuPer() << ";" << x.getPassPer() << ";" << x.getCodTipPer() << ";" << endl;
				}
				archivoRegistroPersonal.close();
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
			fstream	archivoPersonal;
			archivoPersonal.open("personal.csv", ios::in);
			if (archivoPersonal.is_open())
			{
				while (!archivoPersonal.eof() && getline(archivoPersonal, linea))
				{
					i = 0;
					while ((posi = linea.find(";")) != string::npos)
					{
						temporal[i] = linea.substr(0, posi);
						linea.erase(0, posi + 1);
						++i;
					}

					RegistroPersonal objPersonal(stoi(temporal[0]), temporal[1],temporal[2],temporal[3],stoi(temporal[4]));

					add(objPersonal);
				}
			}
		}
		catch (exception e)
		{
			cout << "Ocurrio un error al grabar el archivo";
		}
	}
};