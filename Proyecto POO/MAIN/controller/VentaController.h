#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "../model/Venta.h"
using namespace std;

class VentaController
{
private:
	vector<Venta> vectorVenta;

public:
	VentaController()
	{
		cargarDatosDelArchivoAlVector();
	}

	void add(Venta obj)
	{
		vectorVenta.push_back(obj);
	}

	Venta get(int pos)
	{
		return vectorVenta[pos];
	}

	int size()
	{
		return vectorVenta.size();
	}

	int getCorrelativo()
	{
		if (vectorVenta.size() == 0)
		{
			return 1;
		}
		else
		{
			return vectorVenta[vectorVenta.size() - 1].getcodigo() + 1;
		}
	}

	Venta buscarPorCodigo(int codigo)
	{
		Venta objError;
		objError.setcodigo(0);

		for (Venta x : vectorVenta)
		{
			if (codigo == x.getcodigo())
			{
				return x;
			}
		}
	}

	bool modificar(Venta obj1EsElQueSeModifica, string fecha, float igv, float total, string estado, int codCliente, int codVendedor, string tipoVenta)
	{
		for (int i = 0; i < vectorVenta.size(); i++)
		{
			if (obj1EsElQueSeModifica.getcodigo() == vectorVenta[i].getcodigo())
			{
				vectorVenta[i].setfecha(fecha);
				vectorVenta[i].setigv(igv);
				vectorVenta[i].settotal(total);
				vectorVenta[i].setestado(estado);
				vectorVenta[i].setcodCliente(codCliente);
				vectorVenta[i].setcodVendedor(codVendedor);
				vectorVenta[i].settipoVenta(tipoVenta);
				return true;
			}
		}
		return false;
	}

	int getPostArray(Venta obj)
	{
		for (int i = 0; i < vectorVenta.size(); i++)
		{
			if (obj.getcodigo() == vectorVenta[i].getcodigo())
			{
				return i;
			}
		}
		return -1;
	}

	void eliminar(Venta obj)
	{
		vectorVenta.erase(vectorVenta.begin() + getPostArray(obj));
	}

	void grabarEnArchivo(Venta obj)
	{
		try
		{
			fstream archivoVenta;
			archivoVenta.open("ventas.csv", ios::app);
			if (archivoVenta.is_open())
			{
				archivoVenta << obj.getcodigo() << ";" << obj.getfecha() << ";" << obj.getsubtotal() << ";" << obj.getigvVenta() << ";" << obj.getigv() << ";" << obj.gettotal() << ";" << obj.getestado() << ";" << obj.getcodCliente() << ";" << obj.getcodVendedor() << ";" << obj.gettipoVenta() << ";" << endl;
				archivoVenta.close();
			}
		}
		catch (exception e)
		{
			cout << "Ocurrio un error al grabar el registro!!!";
		}
	}

	void grabarModificarEnArchivo()
	{
		try {
			fstream archivoVenta;
			archivoVenta.open("ventas.csv", ios::out);
			if (archivoVenta.is_open())
			{
				for (Venta x : vectorVenta)
				{
					archivoVenta << x.getcodigo() << ";" << x.getfecha() << ";" << x.getsubtotal() << ";" << x.getigvVenta() << ";" << x.getigv() << ";" << x.gettotal() << ";" << x.getestado() << ";" << x.getcodCliente() << ";" << x.getcodVendedor() << ";" << x.gettipoVenta() << ";" << "\n";
				}
			}
		}
		catch (exception e)
		{
			cout << "Ocurrio un error al grabar en el archivo" << endl;
		}

	}

	void cargarDatosDelArchivoAlVector()
	{
		try
		{
			int i;
			size_t posi;
			string linea;
			string temporal[10];
			fstream archivoVenta;
			archivoVenta.open("ventas.csv", ios::in);
			if (archivoVenta.is_open())
			{
				while (!archivoVenta.eof() && getline(archivoVenta, linea))
				{
					i = 0;
					while ((posi = linea.find(";")) != string::npos)
					{
						temporal[i] = linea.substr(0, posi);
						linea.erase(0, posi + 1);
						++i;
					}
					
					Venta objVenta(stoi(temporal[0]), temporal[1], stof(temporal[2]), stof(temporal[3]), stof(temporal[4]), stof(temporal[5]), temporal[6], stoi(temporal[7]), stoi(temporal[8]), temporal[9]);

					add(objVenta);

				}
			}
			archivoVenta.close();
		}
		catch (exception e)
		{
			cout << "Ocurrio un error al leer el archivo";
		}
	}

	void modificarestado()
	{
		try {
			fstream archivoVenta;
			archivoVenta.open("ventas.csv", ios::trunc);
			if (archivoVenta.is_open())
			{
				for (Venta x : vectorVenta) 
				{
					archivoVenta << x.getcodigo() << ";" << x.getfecha() << ";" << x.getsubtotal() << ";" << x.getigvVenta() << ";" << x.getigv() << ";" << x.gettotal() << ";" << x.getestado() << ";" << x.getcodCliente() << ";" << x.getcodVendedor() << ";" << x.gettipoVenta() << ";" << "\n";
					archivoVenta.close();
				}
			}
		}
		catch (exception e)
		{
			cout << "Ocurrio un error al grabar en el archivo" << endl;
		}

	}

};