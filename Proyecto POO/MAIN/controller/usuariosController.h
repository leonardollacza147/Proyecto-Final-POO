#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "../model/usuarios.h"
using namespace std;

class UsuariosController
{
private:

	vector<Usuarios>vectorUsuarios;

public:

	UsuariosController()
	{
		cargarDatosDelArchivoAlVector();
	}

	void add(Usuarios obj)
	{
		vectorUsuarios.push_back(obj);
	}

	Usuarios get(int pos)
	{
		return vectorUsuarios[pos];
	}

	int size()
	{
		return vectorUsuarios.size();
	}

	void grabadoEnArchivo(Usuarios obj)
	{
		try
		{
			fstream archivoUsuarios;
			archivoUsuarios.open("usuarios.csv", ios::app);
			if (archivoUsuarios.is_open())
			{
				archivoUsuarios << obj.getUsuario() << ";" << obj.getContrasenia() << endl;
				archivoUsuarios.close();
			}
		}
		catch (exception e)
		{
			cout << "Ocurrio un error en el archivo" << endl;
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
			fstream	archivoUsuarios;
			archivoUsuarios.open("usuarios.csv", ios::in);
			if (archivoUsuarios.is_open())
			{
				while (!archivoUsuarios.eof() && getline(archivoUsuarios, linea))
				{
					i = 0;
					while ((posi = linea.find(";")) != string::npos)
					{
						temporal[i] = linea.substr(0, posi);
						linea.erase(0, posi + 1);
						++i;
					}

					Usuarios objUsuarios(temporal[0], temporal[1]);

					add(objUsuarios);
				}
			}
		}
		catch (exception e)
		{
			cout << "Ocurrio un error al grabar el archivo";
		}
	}
};