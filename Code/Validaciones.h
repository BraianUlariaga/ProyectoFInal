#pragma once
#include <string>

class Validaciones
{
public:
	Validaciones()
	{
	}

	/*Funciones*/
	static bool ValidarStringVacio(const std::string& dato);
    static bool ValidarLetras(const std::string& texto);
    static bool ValidarSoloNum(const int num);
    static bool ValidaPositivo(const int& numero);
    static bool ValidaLongitudNumMayorA6(const int& numero);
    static bool ValidarMail(const std::string& mail);
    static bool Bisiesto(int anio);
    static bool ValidaPatente(std::string& patente);

private:

};
