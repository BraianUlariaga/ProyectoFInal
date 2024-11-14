#include "Validaciones.h"
#include <cmath>


/*Metodos*/
bool Validaciones::ValidarStringVacio(const std::string& dato) {

	if (dato.empty())
	{
		return (true);
	}
	else
	{
		return (false);
	}

}

bool Validaciones::ValidarLetras(const std::string& texto) {

	for (int i = 0; i < texto.size(); i++) {

		if (!isalpha(texto[i]) && texto[i] != ' ') {
			return false;
		}
	}
	return true; // si esta todo ok
}
bool Validaciones::ValidarSoloNum(const int num) {

	std::string texto = std::to_string(num);
	for (int i = 0; i < texto.size(); i++) {

		if (!isdigit(texto[i])) {
			return false;
		}
	}
	return true;
}

bool Validaciones::ValidaPositivo(const int& num) {
	// Validar que no sea negativo
	if (num > 0) {
		return true;
	}
	return false;
}

bool Validaciones::ValidaLongitudNumMayorA6(const int& num) {

	// Validar que tenga al menos 6 dígitos
	//Operador ternario (condición) ? expresión1 : expresión2;
	int cantidadDigitos = (num == 0) ? 1 : (int)log10(num) + 1;
	if (cantidadDigitos < 6) {
		return true;
	}

	return false;
}

bool Validaciones::ValidarMail(const std::string& mail) {

	if (mail.find('@') != std::string::npos && mail.find('.') != std::string::npos) { //la funcion find() lo que hace es buscar el caracter que se le indica buscar
		return true;                                                        //y siempre se compara con "npos" que es un valor especial que indica "que no se encontro el caracter buscado".
	}

	return false;
}


bool Validaciones::Bisiesto(int anio) {
	if ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0)) {
		return 1;
	}
	else { return 0; }
}

bool Validaciones::ValidaPatente(std::string& patente) {
	// Convertir cada carácter a mayúscula
	for (int i = 0; i < patente.size(); i++) {
		patente[i] = toupper(patente[i]);
	}

	if (patente.size() == 6) {
		if (isalpha(patente[0]) && isalpha(patente[1]) && isalpha(patente[2]) && isdigit(patente[3]) && isdigit(patente[4]) && isdigit(patente[5])) {
			return true;
		}
	}
	else {
		if (patente.size() == 7) {
			if (isalpha(patente[0]) && isalpha(patente[1]) && isdigit(patente[2]) && isdigit(patente[3]) && isdigit(patente[4]) && isalpha(patente[5]) && isalpha(patente[6])) {
				return true;
			}
		}
	}
	return false;
}
