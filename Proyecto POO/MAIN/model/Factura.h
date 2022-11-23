#include <iostream>
using namespace std;

class Factura
{
private:
    int codFactura;
    int codProducto;
    int cantidad;
    float precioVenta;
    float importe;
public:
    Factura()
    {

    }

    Factura(int codFactura, int codProducto, int cantidad, float precioVenta, float importe)
    {
        this->codFactura = codFactura;
        this->codProducto = codProducto;
        this->cantidad = cantidad;
        this->precioVenta = precioVenta;
        this->importe = importe;
    }

    ~Factura()
    {

    }

    void setCodFactura(int codFactura)
    {
        this->codFactura = codFactura;
    }

    void setCodProducto(int codProducto)
    {
        this->codProducto = codProducto;
    }

    void setCantidad(int cantidad)
    {
        this->cantidad = cantidad;
    }

    void setPrecioVenta(float precioVenta)
    {
        this->precioVenta = precioVenta;
    }

    void setImporte(float importe)
    {
        this->importe = importe;
    }

    int getCodFactura() 
    {
        return codFactura;
    }

    int getCodProducto() 
    {
        return codProducto;
    }

    int getCantidad() 
    {
        return cantidad;
    }

    float getPrecioVenta() 
    {
        return precioVenta;
    }

    float getImporte() 
    {
        return importe;
    }
};