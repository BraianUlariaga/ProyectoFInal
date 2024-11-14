#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Persona.h"
#include "Validaciones.h"
#include <string>
#include <cstring>


//constructor
Persona::Persona() {
	strcpy(_Nombre, "S/N");
	strcpy(_Apellido, "S/A");
	_DNI = 0;
	_FechaNacimiento.toString();
	strcpy(_Telefono, "S/T");
	strcpy(_Email, "S/E");
}
//setters
void Persona::setNombre(std::string nombre) {
	if (nombre.length() < 100)
	{
		strcpy(_Nombre, nombre.c_str());
	}
}
void Persona::setApellido(std::string apellido) {
	if (apellido.length() < 100)
	{
		strcpy(_Apellido, apellido.c_str());
	}
}
void Persona::setDNI(int dni) {
	_DNI = dni;
}
void Persona::setFechaNacimiento(Fecha nacimiento) {
	_FechaNacimiento = nacimiento;
}
void Persona::setTelefono(std::string telefono) {
	if (telefono.length() < 13)
	{
		strcpy(_Telefono, telefono.c_str());
	}
}
void Persona::setEmail(std::string email) {
	if (email.length() < 100)
	{
		strcpy(_Email, email.c_str());
	}
}
//getters
std::string Persona::getNombre()const {
	return _Nombre;
}
std::string Persona::getApellido()const {
	return _Apellido;
}
int Persona::getDNI()const {
	return _DNI;
}
Fecha Persona::getFechaNacimiento()const {
	return _FechaNacimiento;
}
std::string Persona::getTelefono()const {
	return _Telefono;
}
std::string Persona::getEmail()const {
	return _Email;
}
//metodos
//metodos
void Persona::CargarPersona() {
	std::string nombre, apellido, telefono, email;
	int dni;
	Fecha nacimiento;

	do
	{

		std::cout << "Ingrese el nombre: ";
		getline(std::cin, nombre);
		if (!Validaciones::ValidarStringVacio(nombre) || Validaciones::ValidarLetras(nombre)) // valido que el nombre no este vacio
		{
			setNombre(nombre);
			break;
		}
		else
		{
			std::cout << "El nombre no puede estar vacio y debe contener solo letras." << std::endl;
		}
		system("pause");
		system("cls");
	} while (true);

	do
	{

		std::cout << "ingrese el apellido: ";
		getline(std::cin, apellido);
		if (!Validaciones::ValidarStringVacio(apellido) || Validaciones::ValidarLetras(apellido)) // valido que el nombre no este vacio
		{
			setApellido(apellido);
			break;
		}
		else
		{
			std::cout << "El apellido no puede estar vacio." << std::endl;
		}
		system("pause");
		system("cls");
	} while (true);

	do
	{

		std::cout << "Ingres ele DNI: ";
		std::cin >> dni;
		if (!Validaciones::ValidaPositivo(dni))// valido que el DNI sea negativo
		{
			std::cout << "El numero no puede ser negativo." << std::endl;
		}
		else
		{
			if (Validaciones::ValidaLongitudNumMayorA6(dni)) // valido que el dni tenga mas de 6 digitos
			{
				std::cout << "El DNI debe tener 6 digitos." << std::endl;
			}
			else
			{
				setDNI(dni);
				break;
			}
		}
		system("pause");
		system("cls");
	} while (true);


	std::cout << " Ingrese la fecha de nacimiento: ";
	nacimiento.CargarFecha();
	setFechaNacimiento(nacimiento);
	std::cin.ignore();

	do
	{

		std::cout << "Ingrese el telefono: ";
		getline(std::cin, telefono);
		if (!Validaciones::ValidarStringVacio(telefono) || telefono.size() >= 8)
		{
			setTelefono(telefono);
			break;
		}
		else
		{
			std::cout << "El telefono no puede estar vacio y debe tener al menos 8 digitos." << std::endl;
		}
		system("pause");
		system("cls");
	} while (true);


	do
	{

		std::cout << "Ingrese el email: ";
		getline(std::cin, email);
		if (Validaciones::ValidarMail(email)) {

			setEmail(email);
			break;
		}
		else
		{
			std::cout << "Mail invalido" << std::endl;
		}
		system("pause");
		system("cls");
	} while (true);
}
void Persona::MostrarPersona()const {
	std::cout << "NOMBRE: " << getNombre() << std::endl;
	std::cout << "APELLIDO: " << getApellido() << std::endl;
	std::cout << "DNI: " << getDNI() << std::endl;
	std::cout << "FECHA DE NACIMIENTO: " << getFechaNacimiento().toString() << std::endl;
	std::cout << "TELEFONO: " << getTelefono() << std::endl;
	std::cout << "EMAIL: " << getEmail() << std::endl;
	std::cout << "-------------------------------" << std::endl;
}

