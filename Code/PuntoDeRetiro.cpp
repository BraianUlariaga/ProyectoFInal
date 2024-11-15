#define _CRT_SECURE_NO_WARNINGS
#include "Validaciones.h"
#include "PuntoDeRetiro.h"
#include "PuntoDeRetiroArchivo.h"
#include <iostream>
#include <cstring>


/*Setters*/
void PuntoDeRetiro::setIdPuntoRetiro(int id) { _IdPuntoRetiro = id; }
void PuntoDeRetiro::setDomicilio(std::string domicilio) {
	if (domicilio.size() < 100) {
		strcpy(_Domicilio, domicilio.c_str());
	}
}
void PuntoDeRetiro::setLocalidad(std::string localidad) {
	if (localidad.size() < 100) {
		strcpy(_Localidad, localidad.c_str());
	}
}
void PuntoDeRetiro::setVigente(bool vigencia) { _Estado = vigencia; }

/*Getters*/
int PuntoDeRetiro::getIdPuntoRetiro() { return _IdPuntoRetiro; }
std::string PuntoDeRetiro::getDomicilio() { return _Domicilio; }
std::string PuntoDeRetiro::getLocalidad() { return _Localidad; }
bool PuntoDeRetiro::getVigente() { return _Estado; }

/*constructor*/

PuntoDeRetiro::PuntoDeRetiro() {

	strcpy(_Domicilio,"S/N");
	strcpy(_Localidad,"S/N");
	_Estado = true;

}
/*metodos*/
void PuntoDeRetiro::CargarPuntoDeRetiro() {
	std::string domicilio, localidad;
	bool vigente;

	PuntoDeRetiroArchivo archivo;
	setIdPuntoRetiro(archivo.ObtenerUltimoId());

	// Limpia el buffer de entrada para evitar problemas con getline()
	//std::cin.ignore();
	do
	{

	std::cout << "Ingrese calle y altura del punto de retiro." << std::endl;

	getline(std::cin, domicilio);

	if (Validaciones::ValidarStringVacio(domicilio))
	{
		std::cout << "El domicilio no puede estar vacio." << std::endl;
	}
	else
	{
		setDomicilio(domicilio);
	}
	system("pause");
	system("cls");
	} while (true);

	do
	{

	std::cout << "Ingrese la localidad del punto de retiro." << std::endl;
	getline(std::cin, localidad);

	if (Validaciones::ValidarStringVacio(localidad))
	{
		std::cout << "la localidad no puede estar vacia." << std::endl;
	}
	else
	{
		setLocalidad(localidad);
	}
	system("pause");
	system("cls");
	} while (true);
	setVigente(true);
}
void PuntoDeRetiro::MostrarPuntoDeRetiro() {
	std::cout << "*****Punto de retiro****" << std::endl;
	std::cout << "ID: " << getIdPuntoRetiro() << std::endl;
	std::cout << "Domicilio: " << getDomicilio() << std::endl;
	std::cout << "Localidad: " << getLocalidad() << std::endl;
	std::cout << std::boolalpha; // Imprime verdadero o falso.
	std::cout << "Vigencia: " << getVigente() << std::endl;
}

void PuntoDeRetiro::BajaPuntoDeRetiro() {

	setVigente(false);
}


void PuntoDeRetiro::ModificarPuntoDeRetiro() {
	std::string domicilio, localidad;

	// Limpia el buffer de entrada para evitar problemas con getline()
	//std::cin.ignore();

	do
	{
	std::cout << "Ingrese calle y altura del punto de retiro." << std::endl;

	getline(std::cin, domicilio);

	if (!Validaciones::ValidarStringVacio(domicilio))
	{
		std::cout << "El domicilio no puede estar vacio." << std::endl;
	}
	else
	{
		setDomicilio(domicilio);
		break;

	}
	system("pause");
	system("cls");

	} while (true);

	do
	{

	std::cout << "Ingrese la localidad del punto de retiro." << std::endl;
	getline(std::cin, localidad);

	if (Validaciones::ValidarStringVacio(localidad))
	{
		std::cout << "la localidad no puede estar vacia." << std::endl;
	}
	else
	{
		setLocalidad(localidad);
		break;
	}
	system("pause");
	system("cls");
	} while (true);

	setVigente(true);
}
