#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include "Auto.h"
#include "Validaciones.h"

//constructor
Automovil::Automovil() {
    strcpy(_Patente, "S/P");
    strcpy(_Color, "S/C");
    strcpy(_Marca, "S/M");
    strcpy(_Tipo, "S/T");
    _Anio = 0;
    _Km = 0;
    _Precio = 0;
    _Estado = false;

}
//setters
void Automovil::setPatente(std::string patente) {
        strcpy(_Patente, patente.c_str());
}
void Automovil::setColor(std::string color) {
        strcpy(_Color, color.c_str());
}
void Automovil::setMarca(std::string marca) {
       strcpy(_Marca, marca.c_str());
}
void Automovil::setTipo(std::string tipo) {
       strcpy(_Tipo, tipo.c_str());
}
void Automovil::setAnio(int anio) {
        _Anio = anio;
}
void Automovil::setKm(int km) {
        _Km = km;
}
void Automovil::setPrecio(float precio) {
        _Precio = precio;
}
void Automovil::setEstado(bool estado) {
    _Estado = estado;
}
//getters
const char* Automovil::getPatente()const {
    return _Patente;
}
const char* Automovil::getColor()const {
    return _Color;
}
const char* Automovil::getMarca()const {
    return _Marca;
}
const char* Automovil::getTipo()const {
    return _Tipo;
}
int Automovil::getAnio()const {
    return _Anio;
}
int Automovil::getKm()const {
    return _Km;
}
float Automovil::getPrecio()const {
    return _Precio;
}
bool Automovil::getEstado() const {
    return _Estado;
}
//metodos
void Automovil::CargarAuto() {
    std::string patente, color, marca, tipo;
    int anio, km, precio;

    do
    {
        std::cout << "Ingrese la patente: ";
        getline(std::cin, patente);
        if (Validaciones::ValidaPatente(patente))
        {
            setPatente(patente);
            break;
        }
        else
        {
            std::cout << "Patente no valida. " << std::endl;
        }
        system("pause");
        system("cls");
    } while (true);


    do
    {
         std::cout << "Ingrese la marca: ";
         getline(std::cin, marca);
        if (!Validaciones::ValidarStringVacio(marca) || Validaciones::ValidarLetras(marca))
        {
            setMarca(marca);
            break;
        }
        else
        {
            std::cout << "El dato no puede estar vacio o contiene nuemeros" << std::endl;
        }
        system("pause");
        system("cls");
    } while (true);

    do
    {
        std::cout << "Ingrese el tipo de vehiculo: ";
        getline(std::cin, tipo);
        if (!Validaciones::ValidarStringVacio(tipo) || Validaciones::ValidarLetras(tipo))
        {
            setTipo(tipo);
            break;
        }
        else
        {
            std::cout << "El dato no puede estar vacio o contiene nuemeros" << std::endl;
        }
        system("pause");
        system("cls");
    } while (true);


    do
    {
        std::cout << "Ingrese el Color: ";
        getline(std::cin, color);
        if (!Validaciones::ValidarStringVacio(color) || Validaciones::ValidarLetras(color))
        {
            setColor(color);
            break;
        }
        else
        {
            std::cout << "El dato no puede estar vacio o contiene nuemeros" << std::endl;
        }
        system("pause");
        system("cls");
    } while (true);

    do
    {
           std::cout << "Ingrese el año: ";
           std::cin >> anio;
           if (Validaciones::ValidaPositivo(anio) || Validaciones::ValidarSoloNum(anio)|| anio >= 1990)
           {
            setAnio(anio);
            break;
           }
           else
           {
               std::cout << "El dato no deber ser numerico, positivo y mayor a 1990" << std::endl;
           }
           system("pause");
           system("cls");
    } while (true);

    do
    {
        std::cout << "Ingrese los kilometros: ";
        std::cin >> km;
        if (Validaciones::ValidaPositivo(km) || Validaciones::ValidarSoloNum(km))
        {
            setKm(km);
            break;
        }
        else
        {
            std::cout << "El dato no deber ser numerico y positivo " << std::endl;
        }
        system("pause");
        system("cls");


    } while (true);

    do
    {
        std::cout << "Ingrese el precio: ";
        std::cin >> precio;
        if (Validaciones::ValidaPositivo(precio) || Validaciones::ValidarSoloNum(precio))
        {
            setPrecio(precio);
            break;
        }
        else
        {
            std::cout << "El dato no deber ser numerico y positivo " << std::endl;
        }
        system("pause");
        system("cls");


    } while (true);


    setEstado(true);


}
void Automovil::MostrarAuto()const {
    std::cout << std::setw(25) << std::setfill('-') << "-" << std::endl;
    std::cout << "MARCA: " << getMarca() << std::endl;
    std::cout << std::setw(std::string(getMarca()).length() + 10) << std::setfill('-') << "-" << std::endl;
    std::cout << "PATENTE: " << getPatente() << std::endl;
    std::cout << "TIPO: " << getTipo() << std::endl;
    std::cout << "COLOR: " << getColor() << std::endl;
    std::cout << "ANIO: " << getAnio() << std::endl;
    std::cout << "KILOMETROS: " << getKm() << std::endl;
    std::cout << std::fixed;
    std::cout << std::setprecision(2);
    std::cout << "PRECIO: " << getPrecio() << std::endl;
    std::cout << "ESTADO: " << getEstado() << std::endl;
    std::cout << std::setw(25) << std::setfill('-') << "-" << std::endl;
}



