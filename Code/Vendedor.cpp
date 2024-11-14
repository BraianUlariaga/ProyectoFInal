#include <iostream>
#include "Vendedor.h"
#include "VendedorArchivo.h"

//constructor
Vendedor::Vendedor(){
    _Legajo = 0;
    _Estado = false;
}
//setters
void Vendedor::setLegajo(int legajo){
    _Legajo = legajo;
}
void Vendedor::setEstado(bool estado){
    _Estado = estado;
}
//getters
int Vendedor::getLegajo()const{
    return _Legajo;
}
bool Vendedor::getEstado()const{
    return _Estado;
}
//metodos

void Vendedor::CargarVendedor(){
    VendedorArchivo archi;
    int legajo;
    Persona::CargarPersona();
    /*std::cout<< "LEGAJO: ";
    std::cin>> legajo;*/
    legajo = archi.CantidadRegistros() +1;
    setLegajo(legajo);

    setEstado(true);

//cambio el cargar desde aca porque si lo hacia desde la clase la clase en si me pedia que borre los #include y encima creo que iba a ser un poco engorroso
}

void Vendedor::BajaVendedor() {

    setEstado(false);

}

void Vendedor::ModificarVendedor() {

    Persona::CargarPersona();
    setEstado(true); //CAMBIO

}
void Vendedor::MostrarVendedor(){
    Persona::MostrarPersona();
    std::cout<< "LEGAJO: " << getLegajo() <<std::endl;
    std::cout<< "-------------------------" <<std::endl;
}
