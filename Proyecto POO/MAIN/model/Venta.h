#include <iostream>
using namespace std;

class Venta
{
private:
    int codigo;
    string fecha;
    float subtotal;
    float igvVenta;
    float igv;
    float total;
    string estado;
    int codCliente;
    int codVendedor;
    string tipoVenta;

public:
    Venta() 
    {

    }

    Venta(int codigo, string fecha, float subtotal, float igvVenta, float igv, float total, string estado, int codCliente, int codVendedor, string tipoVenta)
    {
        this->codigo = codigo;
        this->fecha = fecha;
        this->subtotal = subtotal;
        this->igvVenta = igvVenta;
        this->igv = igv;
        this->total = total;
        this->estado = estado;
        this->codCliente = codCliente;
        this->codVendedor = codVendedor;
        this->tipoVenta = tipoVenta;
    }

    ~Venta()
    {

    }

    void setcodigo(int codigo)
    {
        this->codigo = codigo;
    }

    void setfecha(string fecha)
    {
        this->fecha = fecha;
    }

    void setsubtotal(float subtotal)
    {
        this->subtotal = subtotal;
    }

    void setigvVenta(float igvVenta)
    {
        this->igvVenta = igvVenta;
    }

    void setigv(float igv)
    {
        this->igv = igv;
    }

    void settotal(float total)
    {
        this->total = total;
    }

    void setestado(string estado)
    {
        this->estado = estado;
    }

    void setcodCliente(int codCliente)
    {
        this->codCliente = codCliente;
    }

    void setcodVendedor(int codVendedor)
    {
        this->codVendedor = codVendedor;
    }

    void settipoVenta(string tipoVenta)
    {
        this->tipoVenta = tipoVenta;
    }

    int getcodigo() 
    {
        return codigo;
    }

    string getfecha()
    {
        return fecha;
    }

    float getsubtotal() 
    {
        return subtotal;
    }

    float getigvVenta() 
    {
        return igvVenta;
    }

    float getigv() 
    {
        return igv;
    }

    float gettotal() 
    {
        return total;
    }

    string getestado() 
    {
        return estado;
    }

    int getcodCliente() 
    {
        return codCliente;
    }

    int getcodVendedor() 
    {
        return codVendedor;
    }

    string gettipoVenta() 
    {
        return tipoVenta;
    }

};