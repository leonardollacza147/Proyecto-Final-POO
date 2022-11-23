#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "../model/Factura.h"
using namespace std;

class FacturaController
{
private:
	vector<Factura>vectorFactura;

public:
	FacturaController()
	{
		cargarDatosDelArchivoAlVector();
	}

	void add(Factura obj)
	{
		vectorFactura.push_back(obj);
	}

	Factura get(int pos)
	{
		return vectorFactura[pos];
	}

	int size()
	{
		return vectorFactura.size();
	}

	int getCorrelativo()
	{
		if (vectorFactura.size() == 0)
		{
			return 1;
		}
		else
		{
			return vectorFactura[vectorFactura.size() - 1].getCodFactura() + 1;
		}
	}

	Factura buscarPorCodigo(int codigo)
	{
		Factura objError;
		objError.setCodFactura(0);

		for (Factura x : vectorFactura)
		{
			if (codigo == x.getCodFactura())
			{
				return x;
			}
		}
	}

	bool modificar(Factura obj1EsElQueSeModifica, int codProducto, int cantidad)
	{
		for (int i = 0; i < vectorFactura.size(); i++)
		{
			if (obj1EsElQueSeModifica.getCodFactura() == vectorFactura[i].getCodFactura())
			{
				vectorFactura[i].setCodProducto(codProducto);
				vectorFactura[i].setCantidad(cantidad);
				return true;
			}
		}
		return false;
	}

	int getPostArray(Factura obj)
	{
		for (int i = 0; i < vectorFactura.size(); i++)
		{
			if (obj.getCodFactura() == vectorFactura[i].getCodFactura())
			{
				return i;
			}
		}
		return -1;
	}

	void eliminar(Factura obj)
	{
		vectorFactura.erase(vectorFactura.begin() + getPostArray(obj));
	}

	void grabarEnArchivo(Factura obj)
	{
		try
		{
			fstream archivoFactura;
			archivoFactura.open("facturas.csv", ios::app);
			if (archivoFactura.is_open())
			{
				archivoFactura << obj.getCodFactura() << ";" << obj.getCodProducto() << ";" << obj.getCantidad() << ";" << obj.getPrecioVenta() << ";" << obj.getImporte() << ";" << endl;
				archivoFactura.close();
			}
		}
		catch (exception e)
		{
			cout << "Ocurrio un error al grabar el registro!!!";
		}
	}

	void grabarModificarEnArchivo()
	{
		try
		{
			fstream archivoFactura;
			archivoFactura.open("facturas.csv", ios::out);
			if (archivoFactura.is_open())
			{
				for (Factura x : vectorFactura)
				{
					archivoFactura << x.getCodFactura() << ";" << x.getCodProducto() << ";" << x.getCantidad() << ";" << x.getPrecioVenta() << ";" << x.getImporte() << ";" << endl;
				}
				archivoFactura.close();
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
			int i;
			size_t posi;
			string linea;
			string temporal[6];
			fstream archivoFactura;
			archivoFactura.open("facturas.csv", ios::in);
			if (archivoFactura.is_open())
			{
				while (!archivoFactura.eof() && getline(archivoFactura, linea))
				{
					i = 0;
					while ((posi = linea.find(";")) != string::npos)
					{
						temporal[i] = linea.substr(0, posi);
						linea.erase(0, posi + 1);
						++i;
					}
					
					Factura objFactura(stoi(temporal[0]), stoi(temporal[1]), stoi(temporal[2]), stof(temporal[3]), stof(temporal[4]));
					
					add(objFactura);
					
				}
			}
			archivoFactura.close();
		}
		catch (exception e)
		{
			cout << "Ocurrio un error al leer el archivo";
		}
	}

};