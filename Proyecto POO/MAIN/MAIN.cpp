#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <conio.h>
#include <Windows.h>
#include "controller/usuariosController.h"
#include "controller/RegistroClientesController.h"
#include "controller/RegistroProductoController.h"
#include "controller/RegistroPersonalController.h"
#include "controller/CategoriaController.h"
#include "controller/VentaController.h"
#include "controller/FacturaController.h"

using namespace std;
//Variables Globales
int opt;
int go = 10;//gotoxy para listar
//usuario
UsuariosController* usuController = new UsuariosController();
//producto
RegistroProductoController* regisProController = new RegistroProductoController;
//personal
RegistroPersonalController* regisPerController = new RegistroPersonalController;
//cliente
RegistroClientesController* regisCliController = new RegistroClientesController;
//categoria
CategoriaController* regisCatController = new CategoriaController;
//venta
VentaController* vntController = new VentaController;
//factura
FacturaController* factController = new FacturaController;
//INTERFAZ PADRE
void interfazprincipal();

//Prototipos para el usuario
int validar(string usua, string contrasenia);
void menuDeOpciones();
void menuOpcionesUsuarioAdmin();
void iniciarSesion();
void addItems();
void listOfItems();
//Prototipos para el producto
void menuDeOpcionesProducto();
void addItemsProducto();
void listOfItemsProducto();
void listOfItemsProducto2();
void buscarProducto();
void modificarProducto();
void eliminarProducto();
//Prototipos para el personal
void menuDeOpcionesPersonal();
void addItemsPersonal();
void listOfItemsPersonal();
void buscarPersonal();
void modificarPersonal();
void eliminarPersonal();
//Prototipos para cliente
void menuDeOpcionesCliente();
void addItemsCliente();
void listOfItemsCliente();
void buscarCliente();
void modificarCliente();
void eliminarCliente();
//Prototipos para la categoria
void menuDeOpcionesCategoria();
void addItemsCategoria();
void listOfItemsCategoria();
void modificarCategoria();
void eliminarCategoria();
//Prototipos para venta_factura
void menuOpcionesUsuarioPersonal();
void addItemsVenta();
void listOfItemsFactura();
void buscarFactura();
//void modificarFactura();
void eliminarFactura();
//gotoxy para la interfaz grafica
void gotoxy(int x, int y);
void cuadro(int x1, int y1, int x2, int y2);


int main()
{
	system("Title Proyecto POO: CASO 2");
	system("color 8e");
	cuadro(0, 0, 117, 28);
	gotoxy(40, 4);
	interfazprincipal();
	return 0;
}
void cuadro(int x1, int y1, int x2, int y2) 
{
	int i;

	for (i = x1;i < x2;i++) {
		gotoxy(i, y1); printf("\304"); //linea horizontal superior
		gotoxy(i, y2); printf("\304"); //linea horizontal inferior
	}

	for (i = y1;i < y2;i++) {
		gotoxy(x1, i); printf("\263"); //linea vertical izquierda
		gotoxy(x2, i); printf("\263"); //linea vertical derecha
	}

	gotoxy(x1, y1); printf("\332");
	gotoxy(x1, y2); printf("\300");
	gotoxy(x2, y1); printf("\277");
	gotoxy(x2, y2); printf("\331");
}

void gotoxy(int x, int y)
{
	HANDLE Manipulator;
	COORD Coordenadas;
	Manipulator = GetStdHandle(STD_OUTPUT_HANDLE);
	Coordenadas.X = x;
	Coordenadas.Y = y;
	SetConsoleCursorPosition(Manipulator, Coordenadas);
}
//INTERFAZ PADRE
void interfazprincipal()
{
	int opc;
	cuadro(0, 0, 117, 28);
	gotoxy(40, 4);
	cout << " BIENVENIDO A NUESTRO SISTEMA DE VENTAS" << endl;
	gotoxy(20, 5);
	cout << "      _____________________________________________________________________" << endl;
	gotoxy(20, 6);
	cout << "      |                                   ____________________            |" << endl;
	gotoxy(20, 7);
	cout << "      |                                   | ERICK.J   " << "       |___________ |" << endl;
	gotoxy(20, 8);
	cout << "      |        ******************         | VERO.R           |  EMPRESA  ||" << endl;
	gotoxy(20, 9);
	cout << "      |         SISTEMA DE VENTAS         | LEO.L            |           ||" << endl;
	gotoxy(20, 10);
	cout << "      |        ******************         | DIEGO.C          | VENTAMAS..||" << endl;
	gotoxy(20, 11);
	cout << "      |  _________________________________|                  |           ||" << endl;
	gotoxy(20, 12);
	cout << "      |  |  _    _           _    _    _  |   _ _  _ _  _ _  |   ______  ||" << endl;
	gotoxy(20, 13);
	cout << "      |  | | |  | |  _____  | |  | |  | | |       ______     |   |  _ |  ||" << endl;
	gotoxy(20, 14);
	cout << "      |  | |_|  |_|  | | |  |_|  |_|  |_| |       |  | |     |   |  | |  ||" << endl;
	gotoxy(20, 15);
	cout << "      ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
	gotoxy(20, 16);
	cout << " [1] VENDEDOR" << endl;
	gotoxy(20, 17);
	cout << " [2] CLIENTE" << endl;
	gotoxy(20, 18);
	cout << " [3] SALIR" << endl;
	gotoxy(20, 19);
	cout << " Ingrese opcion deseada ";
	cin >> opc;
	switch (opc)
	{
	case 1:system("cls");gotoxy(40, 10);menuDeOpciones();break;
	case 2:system("cls");gotoxy(40, 10);menuDeOpcionesCliente(); break;
	case 3:gotoxy(40, 20);cout << "Gracias por usar nuestro programa";
	}
}

//USUARIO
void menuDeOpciones()
{
	do
	{
		cuadro(35, 3, 80, 25);
		gotoxy(40, 6);
		cout << "\tMENU DE INICIO         \n";
		gotoxy(40, 8);
		cout << " [1] Iniciar sesion           \n";
		gotoxy(40, 10);
		cout << " [2] Registrar nuevo usuario  \n";
		gotoxy(40, 12);
		cout << " [3] Listar Usuarios          \n";
		gotoxy(40, 14);
		cout << " [4] Salir del menu           \n";
		gotoxy(40, 16);
		cout << " Ingresar una opcion:";
		cin >> opt;
		switch (opt)
		{
		case 1:system("cls"); iniciarSesion(); break;
		case 2:system("cls"); addItems(); break;
		case 3:system("cls"); listOfItems(); break;
		case 4:system("cls"); interfazprincipal(); break;
		default:cout << "Ingrese una opcion correcta[1-4]";
		}

	} while (opt != 4);
}

void addItems()
{
	string usu;
	string contra;
	cin.ignore();
	cuadro(35, 3, 80, 25);
	gotoxy(40, 6);
	cout << "Usuario: ";
	getline(cin, usu);
	gotoxy(40, 8);
	cout << "Password: ";
	cin >> contra;
	/*Crear el objeto de tipo alumno*/
	Usuarios objUsu(usu, contra);
	/*Agregar el objeto alarreglo*/
	usuController->add(objUsu);
	//grabar en archivo
	usuController->grabadoEnArchivo(objUsu);
	system("cls");
	menuDeOpciones();

}

void iniciarSesion()
{
	string usua, contrasenia;
	char caracter;
	int pase = 0;
	int counter = 0;
	int flag;

	system("cls");
	cuadro(35, 3, 80, 25);
	gotoxy(40, 6);
	cout << "ELIJA EL ROL AL QUE DESEA ACCEDER: " << endl;
	gotoxy(40, 10);
    cout << "Administrador*******[1]\n";
	gotoxy(40, 12);
    cout << "Personal************[2]\n";
	gotoxy(40, 14);
    cout << "Salir del menu******[3]\n";
	gotoxy(40, 16);
	cout << "Escoja una opcion: ";
    cin >> flag;

	if (flag == 1)
	{
		do
		{
			system("cls");
			cuadro(35, 3, 80, 25);
			gotoxy(40, 6);
			cout << "LOGIN DE USUARIO" << endl;
			gotoxy(40, 7);
			cout << "----------------" << endl;
			gotoxy(40, 8);
			cout << "User: ";
			cin >> usua;
			gotoxy(40, 10);
			cout << "Password: ";
			caracter = _getch();

			while (caracter != 13) // Enter en ASCII
			{
				if (caracter != 8)
				{
					contrasenia.push_back(caracter);
					cout << "*";
				}
				else
				{
					if (contrasenia.length() > 0)
					{
						cout << "\b \b";
						contrasenia = contrasenia.substr(0, contrasenia.length() - 1);
					}
				}
				caracter = _getch();
			}
			getline(cin, contrasenia);

			pase = validar(usua, contrasenia);

			if (!pase)
			{
				system("cls");
				gotoxy(40, 10);
				cout << "EL USUARIO Y/O PASSWORD SON INCORRECTOS" << endl;
				cin.get();
				counter++;
			}


		} while (counter < 3 && pase == 0);
		if (pase == 0)
		{
			system("cls");
			gotoxy(40, 10);
			cout << "\nLIMITE DE ERRORES ALCANZADO!!!" << endl;
			menuDeOpciones();
		}
		else
		{
			system("cls");
			gotoxy(40, 10);
			cout << "BIENVENIDO";
			gotoxy(40, 11);
			system("pause");
			system("cls");
			menuOpcionesUsuarioAdmin();
		}
	}
	else if (flag == 2)
	{
		do
		{
			system("cls");
			cuadro(35, 3, 80, 25);
			gotoxy(40, 6);
			cout << "LOGIN DE USUARIO" << endl;
			gotoxy(40, 8);
			cout << "----------------" << endl;
			gotoxy(40, 10);
			cout << "User: ";
			cin >> usua;
			gotoxy(40, 12);
			cout << "Password: ";
			caracter = _getch();

			while (caracter != 13) // Enter en ASCII
			{
				if (caracter != 8)
				{
					contrasenia.push_back(caracter);
					cout << "*";
				}
				else
				{
					if (contrasenia.length() > 0)
					{
						cout << "\b \b";
						contrasenia = contrasenia.substr(0, contrasenia.length() - 1);
					}
				}
				caracter = _getch();
			}
			getline(cin, contrasenia);

			pase = validar(usua, contrasenia);

			if (!pase)
			{
				system("cls");
				gotoxy(40, 10);
				cout << "El usuario y/o password son incorrectos" << endl;
				cin.get();
				counter++;
			}


		} while (counter < 3 && pase == 0);
		if (pase == 0)
		{
			system("cls");
			gotoxy(40, 10);
			cout << "\nLIMITE DE ERRORES ALCANZADO!!!" << endl;
			menuDeOpciones();
		}
		else
		{
			system("cls");
			gotoxy(40, 10);
			cout << "BIENVENIDO";
			gotoxy(40, 11);
			system("pause");
			system("cls");
			menuOpcionesUsuarioPersonal();
		}
	}
	else if (flag == 3)
	{
		system("cls");
		menuDeOpciones();
	}
	else
	{
		system("cls");
		cout << "Ingrese una opcion correcta[1-4]";
	}
	

}

void listOfItems()
{
	cuadro(35, 3, 80, 25);
	gotoxy(43, 6);
	cout << "LOS USUARIOS SON LOS SIGUIENTES" << endl;
	for (int i = 0; i < usuController->size(); i++ && go++)
	{
		gotoxy(40, go);
		cout << usuController->get(i).getUsuario() << "\t" << usuController->get(i).getContrasenia() << "\n";
	}
	gotoxy(40, 20);
	system("pause");
	system("cls");
}

int validar(string usua, string contrasenia)
{
	int z = 0;
	for (int i = 0; i < usuController->size(); i++)
	{
		if (contrasenia == usuController->get(i).getContrasenia() && usua == usuController->get(i).getUsuario())
		{
			z = 1;
		}
	}
	return z;
}

void menuOpcionesUsuarioAdmin()
{
	int optUsu;
	do
	{
		system("cls");
		cuadro(35, 3, 80, 25);
		gotoxy(40, 6);
		cout << "**********MENU DE USUARIO**********\n";
		gotoxy(40, 9);
		cout << "Categorias*******[1]\n";
		gotoxy(40, 11);
		cout << "Productos********[2]\n";
		gotoxy(40, 13);
		cout << "Personal*********[3]\n";
		gotoxy(40, 15);
		cout << "Salir************[4]\n";
		gotoxy(40, 17);
		cout << "Ingresar una opcion: ";
		cin >> optUsu;
		switch (optUsu)
		{
		case 1:system("cls"); menuDeOpcionesCategoria(); break;
		case 2:system("cls"); menuDeOpcionesProducto(); break;
		case 3:system("csl"); menuDeOpcionesPersonal(); break;
		case 4:system("cls"); menuDeOpciones(); break;
		default:cout << "Ingrese una opcion correcta[1-4]";
		}

	} while (optUsu != 4);
}
//USUARIO

//VENTA_FACTURA
void menuOpcionesUsuarioPersonal()
{
	int optUsu;
	do
	{
		system("cls");
		cuadro(35, 3, 80, 25);
		gotoxy(40, 6);
		cout << "**********MENU DE USUARIO**********\n";
		gotoxy(40, 9);
		cout << "Realizar una venta**********[1]\n";
		gotoxy(40, 11);
		cout << "Buscar facturas*************[2]\n";
		gotoxy(40, 13);
		cout << "Eliminar facturas***********[3]\n";
		gotoxy(40, 15);
		cout << "Listar facturas*************[4]\n";
		gotoxy(40, 17);
		cout << "Salir***********************[5]\n";
		gotoxy(40, 19);
		cout << "Ingresar una opcion: ";
		cin >> optUsu;
		switch (optUsu)
		{
		case 1:system("cls"); addItemsVenta(); break;
		case 2:system("cls"); buscarFactura(); break;
		case 3:system("cls"); eliminarFactura(); break;
		case 4:system("cls"); listOfItemsFactura(); break;
		case 5:system("cls"); menuDeOpciones(); break;
		default:cout << "Ingrese una opcion correcta[1-5]";
		}

	} while (optUsu != 5);
}
void addItemsVenta()
{
	string flag;
	int cod;
	int codpro;
	int cant;
	string fecha;
	float subtotal;
	float igvVenta;
	float igv = 0;
	float total;
	float precio;
	float acumulador = 0;
	string estado = "completado";
	int codClnt;
	int codVndr;
	string tipVnt;
	string per;

	cod = factController->getCorrelativo();
	cuadro(35, 3, 80, 25);
	gotoxy(45, 6);
	cout << "***Venta n° " << cod << " ****\n";
	cin.ignore();
	gotoxy(40, 9);
	cout << "Ingrese la fecha: ";
	getline(cin, fecha);
	gotoxy(40, 10);
	cout << "Ingrese el codigo del Personal: ";
	cin >> codVndr; cout << endl;
	gotoxy(40, 11);
	RegistroPersonal obj0 = regisPerController->buscarPorCodigo(codVndr);
	if (obj0.getNomApePer() != "Error")
	{
		per = obj0.getNomApePer();
	}
	else
	{
		gotoxy(40, 12);
		cout << "No se encontro al personal buscado, vuelva a intentarlo\n" << endl;
		gotoxy(40, 13);
		system("pause");
		system("cls");
		menuOpcionesUsuarioPersonal();
	}
	gotoxy(40, 12);
	cout << "Ingrese el codigo del cliente: ";
	cin >> codClnt; cout << endl;

	RegistroClientes obj = regisCliController->buscarPorCodigo(codClnt);

	if (obj.getNomApeCliente() != "Error")
	{
		tipVnt = "factura";
	}
	else
	{
		gotoxy(40, 13);
		cout << "No existe algun cliente con el codigo ingresado. Crear cliente o vuelva a intentarlo" << endl << endl;
		system("pause");
		system("cls");
		menuOpcionesUsuarioPersonal();
	}
	do
	{
		gotoxy(40, 13);
		cout << "Ingrese el %IGV que tendra el producto: ";
		cin >> igvVenta; cout << endl;
		gotoxy(40, 14);
		cout << "Codigo_Producto: ";
		cin >> codpro; cout << endl;

		RegistroProducto obj2 = regisProController->buscarPorCodigo(codpro);

		if (obj2.getCodProducto() == codpro)
		{
			precio = obj2.getPrePro();
			gotoxy(0, 16);
			cout << "CODIGO PRODUCTO" << "\t\t" << "NOMBRE PRODUCTO" << "\t\t" << "PRECIO PRODUCTO" << "\t\t" << "STOCK PRODUCTO" << "\t\t" << "CODIGO CATEGORIA" << endl;
			cout << obj2.getCodProducto() << "\t\t\t" << obj2.getNomPro()
				<< "\t\t\t" << obj2.getPrePro() << "\t\t\t" << obj2.getStkPro()
				<< "\t\t\t" << obj2.getCodCategoria() << endl;

			gotoxy(40, 20);
			cout << "Cantidad a comprar: ";
			cin >> cant; cout << endl;
			gotoxy(40, 21);
			cout << "SubTotal:" << precio * cant << endl << endl;

			acumulador += precio * cant;

			igv += (igvVenta / 100) * acumulador;

			Factura obj3(cod, codpro, cant, precio, (precio * cant));

			factController->add(obj3);
			factController->grabarEnArchivo(obj3);
			gotoxy(40, 22);
			cout << "Seguir comprando(S/s): ";
			cin >> flag; cout << endl;
		}
		else {
			gotoxy(40, 15);
			cout << "No se encontro el producto seleccionado" << endl;
			gotoxy(40, 16);
			cout << "Seguir comprando(S/s): ";
			cin >> flag; cout << endl;
		}

	} while (flag == "S" || flag == "s");

	subtotal = acumulador - igv;
	total = acumulador;

	Venta obj4(cod, fecha, subtotal, igvVenta, igv, total, estado, codClnt, codVndr, tipVnt);

	vntController->add(obj4);
	vntController->grabarEnArchivo(obj4);
	gotoxy(40, 23);
	system("pause");
	system("cls");

	cout << "    DETALLES    " << endl << endl;

	cout << "Personal a cargo de la operacion: " << per << endl;
	cout << "Carrito de compra: " << endl;

	for (int i = 0; i < factController->size(); i++)
	{

		if (factController->get(i).getCodFactura() == cod)
		{
			int codpr = factController->get(i).getCodProducto();

			RegistroProducto prodt = regisProController->buscarPorCodigo(codpr);

			cout << "El producto es: " << prodt.getNomPro() << endl;
			cout << "La cantidad adquirida es:" << factController->get(i).getCantidad() << endl;
			cout << "El precio unitario del producto es: " << factController->get(i).getPrecioVenta() << endl;
			cout << "El subtotal por este producto es: " << factController->get(i).getImporte() << endl;
			cout << endl;
		}
		else
		{

		}

	}

	cout << "SubTotal: " << obj4.getsubtotal() << endl;
	cout << "IGV: " << obj4.getigv() << endl;
	cout << "Total_Pagar: " << obj4.gettotal() << endl;

	system("pause");
	system("cls");
	menuOpcionesUsuarioPersonal();
}

void listOfItemsFactura()
{
	
	cout << "*****************Facturas realizadas*****************" << endl;

	for (int i = 0; i < vntController->size(); i++)
	{

		cout << "Codigo de la factura:	" << vntController->get(i).getcodigo() << endl;
		cout << "Codigo del vendedor:		" << vntController->get(i).getcodVendedor() << endl;
		cout << "Codigo del cliente:		" << vntController->get(i).getcodCliente() << endl;
		cout << "Fecha de la venta:		" << vntController->get(i).getfecha() << endl;
		cout << "Tipo de venta:			" << vntController->get(i).gettipoVenta() << endl;
		cout << "Estado de la venta:	        " << vntController->get(i).getestado() << endl;
		cout << "Igv(%) cobrado en esta venta:   " << vntController->get(i).getigvVenta() << endl << endl;
		cout << "Subtotal de la venta:	        " << vntController->get(i).getsubtotal() << endl;
		cout << "Igv de la venta:		" << vntController->get(i).getigv() << endl;
		cout << "Total de la venta:		" << vntController->get(i).gettotal() << endl << endl;

		cout << "**************************************************" << endl << endl;
	}

	system("pause");
	system("cls");
	menuOpcionesUsuarioPersonal();
}

void buscarFactura()
{
	int cod;
	int c = 9;
	cuadro(35, 3, 88, 25);
	gotoxy(45, 6);
	cout << "Ingrese el codigo de la factura a buscar: ";
	cin >> cod;

	Venta obj = vntController->buscarPorCodigo(cod);

	if (obj.getcodigo() == cod)
	{
		gotoxy(45, 7);
		cout << "******Venta n° " << obj.getcodigo() << " *******\n";
		gotoxy(40, 8);
		cout << "Fueron adquiridos los siguientes productos: " << endl;
		for (int i = 0; i < factController->size(); i++ && c++)
		{
            if (factController->get(i).getCodFactura() == cod)
			{

				int codpr = factController->get(i).getCodProducto();

				RegistroProducto prodt = regisProController->buscarPorCodigo(codpr);
				gotoxy(40, 9);
				cout << "El producto es: " << prodt.getNomPro() << endl;
				gotoxy(40, 10);
				cout << "La cantidad adquirida es:" << factController->get(i).getCantidad() << endl;
				gotoxy(40, 11);
				cout << "El precio unitario del producto es: " << factController->get(i).getPrecioVenta() << endl;
				gotoxy(40, 12);
				cout << "El subtotal por este producto es: " << factController->get(i).getImporte() << endl;
				cout << endl;
			}
			else
			{

			}
        }
		gotoxy(40, 13);
		cout << "Codigo_Vendedor:              " << obj.getcodVendedor() << endl;
		gotoxy(40, 14);
		cout << "Codigo_Cliente:               " << obj.getcodCliente() << endl;
		gotoxy(40, 15);
		cout << "Fecha_Venta:                  " << obj.getfecha() << endl;
		gotoxy(40, 16);
		cout << "Tipo de venta:                " << obj.gettipoVenta() << endl;
		gotoxy(40, 17);
		cout << "Estado de venta:              " << obj.getestado() << endl;
		gotoxy(40, 18);
		cout << "IGV Factura(porcentaje):      " << obj.getigvVenta() << endl << endl;
		gotoxy(40, 19);
		cout << "Subtotal:                     " << obj.getsubtotal() << endl;
		gotoxy(40, 20);
		cout << "IGV Venta:                    " << obj.getigv() << endl;
		gotoxy(40, 21);
		cout << "Total a pagar:                " << obj.gettotal() << endl;
	}
	else
	{
		cout << "No se encontro el codigo a buscar\n";
	}
	gotoxy(40, 22);
	system("pause");
	system("cls");
	menuOpcionesUsuarioPersonal();
}


void eliminarFactura()
{
	int cod;
	cuadro(35, 3, 80, 25);
	gotoxy(40, 6);
	cout << "Ingrese la factura a eliminar: ";
	cin >> cod;
	Venta objAEliminar = vntController->buscarPorCodigo(cod);
	if (objAEliminar.getcodigo() == cod)
	{
		vntController->eliminar(objAEliminar);
		gotoxy(40, 7);
		cout << "Factura eliminado con exito\n";
		vntController->grabarModificarEnArchivo();
	}
	else
	{
		gotoxy(40, 7);
		cout << "No se encontro la factura a eliminar\n";
	}
	system("pause");
	system("cls");
	menuOpcionesUsuarioPersonal();
}
//VENTA_FACTURA

//PRODUCTO
void menuDeOpcionesProducto()
{
	int opt;
	do
	{
		system("cls");
		cuadro(35, 3, 80, 25);
		gotoxy(40, 6);
		cout << "MENU DE OPCIONES DE PRODUCTO\n";
		gotoxy(40, 9);
		cout << "Agregar nuevos Productos*******[1]\n";
		gotoxy(40, 11);
		cout << "Buscar Productos***************[2]\n";
		gotoxy(40, 13);
		cout << "Modificar Productos************[3]\n";
		gotoxy(40, 15);
		cout << "Eliminar Productos*************[4]\n";
		gotoxy(40, 17);
		cout << "Listar Productos***************[5]\n";
		gotoxy(40, 19);
		cout << "Salir del menu de Productos****[6]\n";
		gotoxy(40, 21);
		cout << "Ingrese una opcion: ";
		cin >> opt;
		switch (opt)
		{
		case 1:system("cls"); addItemsProducto(); break;
		case 2:system("cls"); buscarProducto(); break;
		case 3:system("cls"); modificarProducto(); break;
		case 4:system("cls"); eliminarProducto(); break;
		case 5:system("cls"); listOfItemsProducto(); break;
		case 6:system("cls"); menuOpcionesUsuarioAdmin(); break;
		default:system("cls"); cout << "Ingresa una opcion correcta[1-6]\n";
		}
	} while (opt != 6);
}

void addItemsProducto()
{
	int d = 9;
	string flag;
	int 	cod;
	string 	nPro;
	float	preProd;
	int stkProd;
	int 	codCate;
	do
	{
		cod = regisProController->getCorrelativo();
		cuadro(35, 3, 90, 28);
		gotoxy(40, 5);
		cout << "******(" << cod << ")*******\n";
		cin.ignore();
		gotoxy(40, 7);
		cout << "Nombre del producto: ";
		getline(cin, nPro);
		gotoxy(40, 9);
		cout << "Precio del producto: ";
		cin >> preProd;
		gotoxy(40, 11);
		cout << "Stock del Producto: ";
		cin >> stkProd;
		system("cls");
		
		gotoxy(15, 5);
		cout << "*******Categorias existentes*******\n";
		for (int i = 0; i < regisCatController->size(); i++)
		{
			
			cout << "\t["<<regisCatController->get(i).getCodCategoria()<<"]" << regisCatController->get(i).getNomCat() << endl;
		}
		cuadro(5, 3, 90, 28);
		gotoxy(8, 10);
		
		cout << "Codigo de categoria: ";
		cin >> codCate;
		gotoxy(8, 13);
		cout << "Continuar(S/s): ";
		cin >> flag;
		/*Crear el objeto de tipo alumno*/
		RegistroProducto objPro(cod, nPro, preProd, stkProd, codCate);
		/*Agregar el objeto alarreglo*/
		regisProController->add(objPro);
		//grabar en archivo
		regisProController->grabarEnArchivo(objPro);
		system("cls");
	} while (flag == "S" || flag == "s");
}

void buscarProducto()
{
	int cod;
	cuadro(35, 3, 90, 28);
	gotoxy(50, 5);
	cout << "Ingrese el codigo a buscar: ";
	cin >> cod;

	RegistroProducto objPro = regisProController->buscarPorCodigo(cod);
	if (objPro.getNomPro() != "Error")
	{
		gotoxy(40, 7);
		cout << "Codigo: " << objPro.getCodProducto() << endl;
		gotoxy(40, 9);
		cout << "Nombre del producto: " << objPro.getNomPro() << endl;
		gotoxy(40, 11);
		cout << "Precio del producto: " << objPro.getPrePro() << endl;
		gotoxy(40, 11);
		cout << "Stock del producto: " << objPro.getStkPro() << endl;
		gotoxy(40,13);
		cout << "Codigo de categoria: " << objPro.getCodCategoria() << endl;
	}
	else
	{
		gotoxy(40, 7);
		cout << "No se encontro el codigo a buscar\n";
	}
	gotoxy(40, 14);
	system("pause");
	system("cls");
}

void modificarProducto()
{
	int cod;
	cuadro(35, 3, 80, 30);
	gotoxy(45, 6);
	cout << "Ingrese el codigo a buscar: ";
	cin >> cod;
	RegistroProducto objAModificar = regisProController->buscarPorCodigo(cod);
	if (objAModificar.getNomPro() != "Error")
	{
		gotoxy(40, 9);
		cout << "Codigo: " << objAModificar.getCodProducto() << endl;
		gotoxy(40, 10);
		cout << "Nombre del producto: " << objAModificar.getNomPro() << endl;
		gotoxy(40, 11);
		cout << "Precio del producto: " << objAModificar.getPrePro() << endl;
		gotoxy(40, 12);
		cout << "Stock producto: " << objAModificar.getStkPro() << endl;
		gotoxy(40, 13);
		cout << "Codido de categoria: " << objAModificar.getCodCategoria() << "\n\n";
		cin.ignore();

		string  nomProd;
		float preProd;
		int 	stkProd;
		int codCate;
		int k = 19;
		gotoxy(40, 15);
		cout << "Modificar Nombre del producto: ";
		getline(cin, nomProd);
		gotoxy(40, 16);
		cout << "Modificar precio del producto: ";
		cin >> preProd;
		gotoxy(40, 17);
		cout << "Modificar Stock del producto: ";
		cin >> stkProd;
		gotoxy(40, 18);
		cout << "*******Categorias existentes*******\n";
		for (int i = 0; i < regisCatController->size(); i++ && k++)
		{
			gotoxy(40, k);
			cout << "\t[" << regisCatController->get(i).getCodCategoria() << "]" << regisCatController->get(i).getNomCat() << endl;
		}
		gotoxy(40, 25);
		cout << "Modificar codigo de categoria del producto: ";
		cin >> codCate;
		RegistroProducto objNuevosDatos(objAModificar.getCodProducto(),
			nomProd,
			preProd,
			stkProd,
			codCate);
		bool estadoModificado = regisProController->modificar(objAModificar, nomProd, preProd, stkProd, codCate);
		if (estadoModificado = true)
		{
			gotoxy(40, 26);
			cout << "Registro modificado satisfactoriamente\n";
			/*Grabar en archivo*/
			regisProController->grabarModificarEnArchivo();
		}
		else
		{
			gotoxy(40, 27);
			cout << "No se modifico el registro\n";
		}
	}
	else
	{
		gotoxy(40, 26);
		cout << "No se encontro el codigo a buscar";
	}
}

void eliminarProducto()
{
	int cod;
	cuadro(35, 3, 80, 15);
	gotoxy(45, 6);
	cout << "Ingrese el codigo a buscar: ";
	cin >> cod;
	RegistroProducto objAEliminar = regisProController->buscarPorCodigo(cod);
	if (objAEliminar.getNomPro() != "Error")
	{
		regisProController->eliminar(objAEliminar);
		gotoxy(40, 9);
		cout << "Registro eliminado satisfactoriamente\n";
		regisProController->grabarModificarEnArchivo();
	}
	else
	{
		gotoxy(40, 9);
		cout << "No se encontro el codigo a buscar\n";
	}
}

void listOfItemsProducto()
{
	cout << "CODIGO PRODUCTO" << "\t" << "NOMBRE PRODUCTO" << "\t\t" << "PRECIO PRODUCTO" << "\t\t" << "STOCK PRODUCTO" << "\t\t" << "CODIGO CATEGORIA" << endl;
	for (int i = 0; i < regisProController->size(); i++)
	{
		cout << regisProController->get(i).getCodProducto() << "\t\t\t" << regisProController->get(i).getNomPro()
			<< "\t\t\t" << regisProController->get(i).getPrePro() << "\t\t\t" << regisProController->get(i).getStkPro()
			<< "\t\t\t" << regisProController->get(i).getCodCategoria() << endl;
	}

	system("pause");
	system("cls");
}

void listOfItemsProducto2()
{
	cuadro(0, 3, 119, 40);
	gotoxy(2, 4);
	cout << "CODIGO PRODUCTO" << "\t\t" << "NOMBRE PRODUCTO" << "\t\t" << "PRECIO PRODUCTO" << "\t\t" << "STOCK PRODUCTO" << "\t\t" << "CODIGO CATEGORIA" << endl;
	for (int i = 0; i < regisProController->size(); i++)
	{
		cout << "\t"<<regisProController->get(i).getCodProducto() << "\t\t\t" << regisProController->get(i).getNomPro()
			<< "\t\t\t" << regisProController->get(i).getPrePro() << "\t\t\t" << regisProController->get(i).getStkPro()
			<< "\t\t\t" << regisProController->get(i).getCodCategoria() << endl;
	}

	system("pause");
	system("cls");
}
//PRODUCTO

//PERSONAL
void menuDeOpcionesPersonal()
{
	int opt;
	do
	{
		system("cls");
		cuadro(35, 3, 80, 25);
		gotoxy(45, 6);
		cout << "MENU DE OPCIONES DE PERSONAL\n";
		gotoxy(40, 9);
		cout << "Agregar nuevo Personal********[1]\n";
		gotoxy(40, 11);
		cout << "Buscar Personal***************[2]\n";
		gotoxy(40, 13);
		cout << "Modificar Personal************[3]\n";
		gotoxy(40, 15);
		cout << "Eliminar Personal*************[4]\n";
		gotoxy(40, 17);
		cout << "Listar Personal***************[5]\n";
		gotoxy(40, 19);
		cout << "Salir del menu de Personal****[6]\n";
		gotoxy(40, 21);
		cout << "Ingrese una opcion: ";
		cin >> opt;
		switch (opt)
		{
		case 1:system("cls"); addItemsPersonal(); break;
		case 2:system("cls"); buscarPersonal(); break;
		case 3:system("cls"); modificarPersonal(); break;
		case 4:system("cls"); eliminarPersonal(); break;
		case 5:system("cls"); listOfItemsPersonal(); break;
		case 6:system("cls"); menuOpcionesUsuarioAdmin(); break;
		default:system("cls"); cout << "Ingresa una opcion correcta[1-6]\n";
		}
	} while (opt != 6);
}

void addItemsPersonal()
{
	string	flag;
	int 	codPer;
	string 	nomApePer;
	string	usuPer;
	string	passPer;
	int		codTipPer;
	do
	{
		cuadro(35, 3, 80, 25);
		gotoxy(45, 6);
		codPer = regisPerController->getCorrelativo();
		cout << "******(" << codPer << ")*******\n";
		cin.ignore();
		gotoxy(40, 8);
		cout << "Nombre y apellido del Personal: ";
		getline(cin, nomApePer);
		gotoxy(40, 10);
		cout << "Usuario del Personal: ";
		getline(cin, usuPer);
		gotoxy(40, 12);
		cout << "Password del Personal: ";
		getline(cin, passPer);
		gotoxy(40, 14);
		cout << "Codigo del Tipo de Personal: ";
		cin >> codTipPer;
		gotoxy(40, 16);
		cout << "Continuar(S/s): ";
		cin >> flag;
		/*Crear el objeto de tipo alumno*/
		RegistroPersonal objPer(codPer, nomApePer, usuPer, passPer, codTipPer);
		/*Agregar el objeto alarreglo*/
		regisPerController->add(objPer);
		//grabar en archivo
		regisPerController->grabarEnArchivo(objPer);
		system("cls");
	} while (flag == "S" || flag == "s");
}

void buscarPersonal()
{
	int cod;
	cuadro(35, 3, 80, 25);
	gotoxy(40, 6);
	cout << "Ingrese el codigo a buscar: ";
	cin >> cod;

	RegistroPersonal objPer = regisPerController->buscarPorCodigo(cod);
	if (objPer.getNomApePer() != "Error")
	{
		gotoxy(40, 8);
		cout << "Codigo: " << objPer.getCodPersonal() << endl;
		gotoxy(40, 9);
		cout << "Nombre y apellido del Personal: " << objPer.getNomApePer() << endl;
		gotoxy(40, 10);
		cout << "Usuario del Personal: " << objPer.getUsuPer() << endl;
		gotoxy(40, 11);
		cout << "Password del Personal: " << objPer.getPassPer() << endl;
		gotoxy(40, 12);
		cout << "Codigo del Tipo de Personal: " << objPer.getCodTipPer() << endl;
	}
	else
	{
		gotoxy(40, 13);
		cout << "No se encontro el codigo a buscar\n";
	}
	gotoxy(40, 14);
	system("pause");
	system("cls");
}

void modificarPersonal()
{
	int cod;
	cuadro(35, 3, 80, 25);
	gotoxy(40, 6);
	cout << "Ingrese el codigo a buscar: ";
	cin >> cod;
	RegistroPersonal objAModificar = regisPerController->buscarPorCodigo(cod);
	if (objAModificar.getNomApePer() != "Error")
	{
		gotoxy(40, 8);
		cout << "Codigo: " << objAModificar.getCodPersonal() << endl;
		gotoxy(40, 9);
		cout << "Nombre y apellido del Personal: " << objAModificar.getNomApePer() << endl;
		gotoxy(40,10);
		cout << "Usuario del Personal: " << objAModificar.getUsuPer() << endl;
		gotoxy(40, 11);
		cout << "Password del Personal: " << objAModificar.getPassPer() << endl;
		gotoxy(40, 12);
		cout << "Codido del Tipo de Personal: " << objAModificar.getCodTipPer() << endl;
		cin.ignore();

		string 	nomApePer;
		string	usuPer;
		string	passPer;
		int		codTipPer;
		gotoxy(40, 14);
		cout << "Modificar nombre y apellido del Personal: ";
		getline(cin, nomApePer);
		gotoxy(40, 15);
		cout << "Modificar usuario del Personal: ";
		getline(cin, usuPer);
		gotoxy(40, 16);
		cout << "Modificar password del Personal: ";
		getline(cin, passPer);
		gotoxy(40, 17);
		cout << "Modificar codigo del Tipo de Personal: ";
		cin >> codTipPer;
		RegistroPersonal objNuevosDatos(objAModificar.getCodPersonal(),
			nomApePer,
			usuPer,
			passPer,
			codTipPer);
		bool estadoModificado = regisPerController->modificar(objAModificar, nomApePer, usuPer, passPer, codTipPer);
		if (estadoModificado = true)
		{
			
			/*Grabar en archivo*/
			regisPerController->grabarModificarEnArchivo();
			gotoxy(40, 18);
			cout << "Registro modificado satisfactoriamente\n";
		}
		else
		{
			gotoxy(40, 18);
			cout << "No se modifico el registro\n";
		}
	}
	else
	{
		gotoxy(40, 18);
		cout << "No se encontro el codigo a buscar";
	}
}

void eliminarPersonal()
{
	int cod;
	cuadro(35, 3, 80, 25);
	gotoxy(40, 6);
	cout << "Ingrese el codigo a buscar: ";
	cin >> cod;
	RegistroPersonal objAEliminar = regisPerController->buscarPorCodigo(cod);
	if (objAEliminar.getNomApePer() != "Error")
	{
		regisPerController->eliminar(objAEliminar);
		regisPerController->grabarModificarEnArchivo();
		cout << "Registro eliminado satisfactoriamente\n";
	}
	else
	{
		cout << "No se encontro el codigo a buscar\n";
	}
}

void listOfItemsPersonal()
{
	cout << "CODIGO PERSONAL" << "\t\t" << "NOMBRE Y APELLIDO DEL PERSONAL" << "\t\t" << "USUARIO DEL PERSONAL"
		<< "\t\t" << "PASSWORD DEL PERSONAL" << "\t\t" << "CODIGO DEL TIPO DE PERSONAL" << endl;
	for (int i = 0; i < regisPerController->size(); i++)
	{
		cout << regisPerController->get(i).getCodPersonal() << "\t\t\t" << regisPerController->get(i).getNomApePer()
			<< "\t\t\t\t" << regisPerController->get(i).getUsuPer() << "\t\t\t\t" << regisPerController->get(i).getPassPer()
			<< "\t\t\t\t" << regisPerController->get(i).getCodTipPer() << endl;
	}

	system("pause");
	system("cls");
}
//PERSONAL

//CLIENTE
void menuDeOpcionesCliente()
{
	int opt;
	do
	{
		system("cls");
		cuadro(35, 3, 80, 28);
		gotoxy(44, 5);
		cout << "MENU DE OPCIONES DE CLIENTE\n";
		gotoxy(40, 8);
		cout << "Agregar nuevos Cliente***********[1]\n";
		gotoxy(40, 10);
		cout << "Buscar Clientes******************[2]\n";
		gotoxy(40, 12);
		cout << "Modificar Clientes***************[3]\n";
		gotoxy(40, 14);
		cout << "Eliminar Clientes****************[4]\n";
		gotoxy(40, 16);
		cout << "Listar Clientes******************[5]\n";
		gotoxy(40, 18);
		cout << "Mostrar Productos Disponibles****[6]\n";
		gotoxy(40, 20);
		cout << "Salir del menu de Clientes*******[7]\n";
		gotoxy(40, 22);
		cout << "Ingrese una opcion: ";
		cin >> opt;
		switch (opt)
		{
		case 1:system("cls"); addItemsCliente(); break;
		case 2:system("cls"); buscarCliente(); break;
		case 3:system("cls"); modificarCliente(); break;
		case 4:system("cls"); eliminarCliente(); break;
		case 5:system("cls"); listOfItemsCliente(); break;
		case 6:system("cls"); listOfItemsProducto2(); break;
		case 7:system("cls"); interfazprincipal(); break;
		default:system("cls"); cout << "Ingresa una opcion correcta[1-7]\n";
		}
	} while (opt != 7);
}

void addItemsCliente()
{
	string flag;
	int 	codCliente;
	string 	nomApeCliente;
	string dirCliente;
	string rucCliente;
	do
	{
		codCliente = regisCliController->getCorrelativo();
		
		cuadro(35, 3, 90, 28);
		gotoxy(55, 5);
		cout << "******(" << codCliente << ")*******\n";
		cin.ignore();
		gotoxy(40, 8);
		cout << "Nombre y apellido del cliente: ";
		getline(cin, nomApeCliente);
		gotoxy(40, 10);
		cout << "Direccion del cliente: ";
		getline(cin,dirCliente);
		gotoxy(40,12);
		cout << "Ruc del cliente: ";
		cin >> rucCliente;
		gotoxy(40, 14);
		cout << "Continuar(S/s): ";
		cin >> flag;
		/*Crear el objeto de tipo alumno*/
		RegistroClientes objCli(codCliente, nomApeCliente, dirCliente, rucCliente);
		/*Agregar el objeto alarreglo*/
		regisCliController->add(objCli);
		//grabar en archivo
		regisCliController->grabarEnArchivo(objCli);
		system("cls");
	} while (flag == "S" || flag == "s");
}

void buscarCliente()
{
	int cod;
	cuadro(35, 3, 90, 28);
	gotoxy(50, 5);
	cout << "Ingrese el codigo a buscar: ";
	cin >> cod;

	RegistroClientes objCli = regisCliController->buscarPorCodigo(cod);
	if (objCli.getNomApeCliente() != "Error")
	{
		gotoxy(40, 11);
		cout << "Codigo: " << objCli.getCodCliente() << endl;
		gotoxy(40, 12);
		cout << "Nombre y apellido del cliente: " << objCli.getNomApeCliente() << endl;
		gotoxy(40, 13);
		cout << "Direccion del cliente: " << objCli.getDirCliente() << endl;
		gotoxy(40, 14);
		cout << "Ruc del cliente: " << objCli.getRucCliente() << endl;
	}
	else
	{
		gotoxy(42, 16);
		cout << "No se encontro el codigo a buscar\n";
	}
	gotoxy(42, 16);
	system("pause");
	system("cls");
}

void modificarCliente()
{
	int cod;
	cuadro(35, 3, 100, 28);
	gotoxy(50, 4);
	cout << "Ingrese el codigo a buscar: ";
	cin >> cod;
	RegistroClientes objAModificar = regisCliController->buscarPorCodigo(cod);
	if (objAModificar.getNomApeCliente() != "Error")
	{
		gotoxy(40, 6);
		cout << "Codigo: " << objAModificar.getCodCliente() << endl;
		gotoxy(40, 8);
		cout << "Nombre y apellido del cliente: " << objAModificar.getNomApeCliente() << endl;
		gotoxy(40, 10);
		cout << "Direccion del cliente: " << objAModificar.getDirCliente() << endl;
		gotoxy(40, 12);
		cout << "Ruc del cliente: " << objAModificar.getRucCliente() << endl;
		cin.ignore();
		string nomApeCliente;
		string dirCliente;
		string rucCliente;
		gotoxy(40, 16);
		cout << "Modificar Nombre y apellido del Cliente: ";
		getline(cin, nomApeCliente);
		gotoxy(40, 18);
		cout << "Modificar Direccion del cliente: ";
		getline(cin, dirCliente);
		gotoxy(40, 20);
		cout << "Modificar Ruc del cliente: ";
		cin >> rucCliente;
		RegistroClientes objNuevosDatos(objAModificar.getCodCliente(),
			nomApeCliente,
			dirCliente,
			rucCliente);
		bool estadoModificado = regisCliController->modificar(objAModificar, nomApeCliente, dirCliente, rucCliente);
		if (estadoModificado = true)
		{
			gotoxy(40, 21);
			cout << "Registro modificado satisfactoriamente\n";
			/*Grabar en archivo*/
			regisCliController->grabarModificarEnArchivo();
		}
		else
		{
			gotoxy(40, 21);
			cout << "No se modifico el registro\n";
		}
	}
	else
	{
		gotoxy(40, 21);
		cout << "No se encontro el codigo a buscar";
	}
}

void eliminarCliente()
{
	int cod;
	cuadro(25, 3, 100, 20);
	gotoxy(50, 4);
	cout << "Ingrese el codigo a buscar: ";
	cin >> cod;
	RegistroClientes objAEliminar = regisCliController->buscarPorCodigo(cod);
	if (objAEliminar.getNomApeCliente() != "Error")
	{
		regisCliController->eliminar(objAEliminar);
		regisCliController->grabarModificarEnArchivo();
		gotoxy(40, 15);
		cout << "EL REGISTRO HA SIDO ELIMINADO SATISFACTORIAMENTE"<<endl;
		gotoxy(40, 16);
		system("pause");
		
		
	}
	else
	{
		gotoxy(40, 10);
		cout << "NO SE ENCONTRO EL CODIGO A BUSCAR"<<endl;
		gotoxy(40, 12);
		system("pause");
	}
}

void listOfItemsCliente()
{

	cuadro(0, 3, 119, 40);
	gotoxy(5, 4);
	cout << "CODIGO CLIENTE" << "\t\t" << "NOMBRE Y APELLIDO DEL CLIENTE" << "\t\t" << "DIRECCION DEL CLIENTE" << "\t\t" << "RUC DEL CLIENTE" << endl;
	for (int i = 0; i < regisCliController->size(); i++ )
	{
		
		cout << regisCliController->get(i).getCodCliente() << "\t\t\t" << regisCliController->get(i).getNomApeCliente()
			<< "\t\t\t\t\t" << regisCliController->get(i).getDirCliente() << "\t\t\t" << regisCliController->get(i).getRucCliente() << endl;
	}

	system("pause");
	system("cls");
}
void menuDeOpcionesCategoria()
{
	int optCat;
	do
	{
		system("cls");
		cuadro(35, 3, 80, 25);
		gotoxy(40, 6);
		cout << "MENU DE OPCIONES DE CATEGORIA\n";
		gotoxy(40, 9);
		cout << "Agregar nuevas Categorias*******[1]\n";
		gotoxy(40, 11);
		cout << "Modificar Categorias************[2]\n";
		gotoxy(40, 13);
		cout << "Eliminar Categorias*************[3]\n";
		gotoxy(40, 15);
		cout << "Listar Categorias***************[4]\n";
		gotoxy(40, 17);
		cout << "Salir del menu de Categoria*****[5]\n";
		gotoxy(40, 19);
		cout << "Ingrese una opcion: ";
		cin >> optCat;
		switch (optCat)
		{
		case 1:system("cls"); addItemsCategoria(); break;
		case 2:system("cls"); modificarCategoria(); break;
		case 3:system("cls"); eliminarCategoria(); break;
		case 4:system("cls"); listOfItemsCategoria(); break;
		case 5:system("cls"); menuOpcionesUsuarioAdmin(); break;
		default:system("cls"); cout << "Ingresa una opcion correcta[1-6]\n";
		}
	} while (optCat != 5);
}

void addItemsCategoria()
{
	string flag;
	int 	codCategoria;
	string 	nomCat;
	do
	{
		cuadro(35, 3, 80, 25);
		gotoxy(45, 6);
		codCategoria = regisCatController->getCorrelativo();
		cout << "******(" << codCategoria << ")*******\n";
		cin.ignore();
		gotoxy(40, 10);
		cout << "Nombre de la Categoria: ";
		getline(cin, nomCat);
		gotoxy(40, 12);
		cout << "Continuar(S/s): ";
		cin >> flag;
		/*Crear el objeto de tipo alumno*/
		Categoria objPro(codCategoria, nomCat);
		/*Agregar el objeto alarreglo*/
		regisCatController->add(objPro);
		//grabar en archivo
		regisCatController->grabarEnArchivo(objPro);
		system("cls");
	} while (flag == "S" || flag == "s");
}
//categorias
void modificarCategoria()
{
	int cod;
	cuadro(35, 3, 80, 25);
	gotoxy(40, 6);
	cout << "Ingrese el codigo a buscar: ";
	cin >> cod;
	Categoria objAModificar = regisCatController->buscarPorCodigo(cod);
	if (objAModificar.getNomCat() != "Error")
	{
		gotoxy(40, 8);
		cout << "Codigo: " << objAModificar.getCodCategoria() << endl;
		gotoxy(40, 9);
		cout << "Nombre del producto: " << objAModificar.getNomCat() << endl;
		cin.ignore();

		string 	nomCat;
		gotoxy(40, 12);
		cout << "Modificar Nombre de la Categoria: ";
		getline(cin, nomCat);
		Categoria objNuevosDatos(objAModificar.getCodCategoria(),
			nomCat);
		bool estadoModificado = regisCatController->modificar(objAModificar, nomCat);
		if (estadoModificado = true)
		{
			gotoxy(40, 13);
			cout << "Registro modificado satisfactoriamente\n";
			/*Grabar en archivo*/
			regisProController->grabarModificarEnArchivo();
		}
		else
		{
			gotoxy(40, 13);
			cout << "No se modifico el registro\n";
		}
	}
	else
	{
		gotoxy(40, 13);
		cout << "No se encontro el codigo a buscar";
	}
}

void eliminarCategoria()
{
	int cod;
	cuadro(35, 3, 80, 25);
	gotoxy(40, 8);
	cout << "Ingrese el codigo a buscar: ";
	cin >> cod;
	Categoria objAEliminar = regisCatController->buscarPorCodigo(cod);
	if (objAEliminar.getNomCat() != "Error")
	{
		regisCatController->eliminar(objAEliminar);
		gotoxy(40, 10);
		cout << "Registro eliminado satisfactoriamente\n";
		regisCatController->grabarModificarEnArchivo();
	}
	else
	{
		gotoxy(40, 10);
		cout << "No se encontro el codigo a buscar\n";
	}
}

void listOfItemsCategoria()
{
	int j=8;
	cuadro(35, 3, 88, 25);
	gotoxy(40, 6);
	cout << "CODIGO CATEGORIA" << "\t\t" << "NOMBRE CATEGORIA" << endl;
	for (int i = 0; i < regisCatController->size(); i++ && j++)
	{
		gotoxy(40, j);
		cout << regisCatController->get(i).getCodCategoria() << "\t\t\t" << regisCatController->get(i).getNomCat() << endl;
	}
	gotoxy(40, 20);
	system("pause");
	system("cls");
}