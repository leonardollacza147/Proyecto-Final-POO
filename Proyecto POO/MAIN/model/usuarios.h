#include <iostream>
using namespace std;

class Usuarios
{
private:
	string Nickname;
	string Password;

public:
	Usuarios()
	{

	}

	Usuarios( string usuario, string contrasenia)
	{
		this->Nickname = usuario;
		this->Password = contrasenia;
	}

	~Usuarios()
	{

	}

	string getUsuario()
	{
		return Nickname;
	}

	string getContrasenia()
	{
		return Password;
	}
};