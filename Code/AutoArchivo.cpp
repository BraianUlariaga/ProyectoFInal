#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "AutoArchivo.h"
#include "Validaciones.h"


AutoArchivo::AutoArchivo() {
    _nombre = "Autos.dat";
}

bool AutoArchivo::AgregarAuto(Automovil& vehiculo) {
    FILE* pFILE;
    bool resultado;


    pFILE = fopen(_nombre.c_str(), "ab");

    if (pFILE == nullptr) {
        return false;
    }

    resultado = fwrite(&vehiculo, sizeof(Automovil), 1, pFILE) == 1;

    fclose(pFILE);

    return resultado;
}

Automovil AutoArchivo::ListarAuto(int pos) {
    FILE* pFILE;
    Automovil vehiculo;

    pFILE = fopen(_nombre.c_str(), "rb");

    if (pFILE == nullptr) {
        return vehiculo;
    }
    fseek(pFILE, sizeof(Automovil) * pos, 0);
    fread(&vehiculo, sizeof(Automovil), 1, pFILE);

    return vehiculo;

}

int AutoArchivo::CantidadRegistros() {
    FILE* pFILE;
    int cantidad, total;

    pFILE = fopen(_nombre.c_str(), "rb");

    if (pFILE == nullptr) {
        return 0;
    }

    fseek(pFILE, 0, 2);
    cantidad = ftell(pFILE);
    fclose(pFILE);
    return total = cantidad / sizeof(Automovil);

}

bool AutoArchivo::ListarAutos(Automovil registros[], int cantidad) {
    FILE* pFILE;
    bool result;


    pFILE = fopen(_nombre.c_str(), "rb");

    if (pFILE == nullptr) {
        return false;

    }

    result = fread(registros, sizeof(Automovil), cantidad, pFILE) == cantidad;

    fclose(pFILE);

    return result;

}

int AutoArchivo::BuscarAuto(char* patente) {
    FILE* pFILE;
    Automovil registro;
    int pos = 0;


    pFILE = fopen(_nombre.c_str(), "rb");

    if (pFILE == nullptr) {
        return -1;
    }

    while (fread(&registro, sizeof(Automovil), 1, pFILE) == 1) {

        //stricmp compara las palabras sin tener en cuenta mayusculas/minusculas

        if (_stricmp(registro.getPatente(), patente) == 0) {
            break;
        }
        pos++;
    }
    fclose(pFILE);

    if (_stricmp(registro.getPatente(), patente) == 0) {
        return pos;
    }
    else { return -2; }


}

bool AutoArchivo::ModificarAuto(Automovil& vehiculo, int pos) {
    FILE* pFILE;
    bool result;

    pFILE = fopen(_nombre.c_str(), "rb+");

    if (pFILE == nullptr || pos < 0) {
        return false;
    }
    else {
        fseek(pFILE, sizeof(Automovil) * pos, 0);
        result = fwrite(&vehiculo, sizeof(Automovil), 1, pFILE) == 1;
        fclose(pFILE);
        return result;
    }
}

void AutoArchivo::BuscarAutosPorMarca() {
    int total;
    Automovil* registros;
    AutoArchivo archi;

    total = archi.CantidadRegistros();

    registros = new Automovil[total];
    if (registros == nullptr) {
        std::cout << "EXCEDE LA MEMORIA." << std::endl;
        return;
    }

    bool result = archi.ListarAutos(registros, total);

    std::string* vecMarcas = new std::string[total];
    int cont = 0;
    for (int i = 0; i < total; ++i) {
        std::string marcaActual = registros[i].getMarca();
        bool encontro = false;

        for (int j = 0; j < cont; ++j) {
            if (vecMarcas[j] == marcaActual) {
                encontro = true;
            }
        }
        if (!encontro) {
            vecMarcas[cont] = marcaActual;
            cont++;
        }
    }
    std::cout << "Seleccione una marca a buscar:" << std::endl;
    for (int x = 0; x < cont; ++x) {
        std::cout << x + 1 << " - " << vecMarcas[x] << std::endl;
    }

    int opc;
    std::cin >> opc;
    if (opc < 1 || opc > cont) {
        std::cout << "Opción incorrecta." << std::endl;
        delete[] registros;
        delete[] vecMarcas;
        return;
    }


    for (int y = 0; y < total; ++y) {
        if (registros[y].getMarca() == vecMarcas[opc - 1]) {
            registros[y].MostrarAuto();
        }
    }


    delete[] registros;

}


void AutoArchivo::BuscarAutosPorAnio() {
    int total;
    Automovil* registros;
    AutoArchivo archi;

    total = archi.CantidadRegistros();

    registros = new Automovil[total];
    if (registros == nullptr) {
        std::cout << "EXCEDE LA MEMORIA." << std::endl;
        return;
    }

    bool result = archi.ListarAutos(registros, total);

    int* vecAnio = new int[total];
    int cont = 0;

    for (int i = 0; i < total; ++i) {
        int anioActual = registros[i].getAnio();
        bool encontro = false;

        for (int j = 0; j < cont; ++j) {
            if (vecAnio[j] == anioActual) {
                encontro = true;
            }
        }

        if (!encontro) {
            vecAnio[cont] = anioActual;
            cont++;
        }
    }
    std::cout << "Seleccione el año a buscar:" << std::endl;
    for (int x = 0; x < cont; ++x) {
        std::cout << x + 1 << " - " << vecAnio[x] << std::endl;
    }

    int opc;
    std::cin >> opc;

    if (opc < 1 || opc > cont) {
        std::cout << "Opcion incorrecta." << std::endl;
        delete[] registros;
        delete[] vecAnio;
        return;
    }

    for (int y = 0; y < total; ++y) {
        if (registros[y].getAnio() == vecAnio[opc - 1]) {
            registros[y].MostrarAuto();
        }
    }

    delete[] registros;
    delete[] vecAnio;

}


void AutoArchivo::BuscarAutosPorTipo() {
    int total;
    Automovil* registros;
    AutoArchivo archi;

    total = archi.CantidadRegistros();

    registros = new Automovil[total];
    if (registros == nullptr) {
        std::cout << "EXCEDE LA MEMORIA." << std::endl;
        return;
    }

    bool result = archi.ListarAutos(registros, total);

    std::string* vecTipo = new std::string[total]{};
    int cont = 0;

    //Veo si la marca del registro actual esta en el vector, sino esta lo inserto
    for (int i = 0; i < total; ++i) {
        std::string tipoActual = registros[i].getTipo();
        bool encontro = false;

        for (int j = 0; j < cont; ++j) {
            if (vecTipo[j] == tipoActual) {
                encontro = true;
            }
        }

        if (!encontro) {
            vecTipo[cont] = tipoActual;
            cont++;
        }
    }

    std::cout << "Seleccione el tipo de auto a buscar: " << std::endl ;
        for (int x = 0; x < cont; x++)
        {
            std::cout << x + 1 << " - " << vecTipo[x] << std::endl;
        }
        int opc;
        std::cin >> opc;

            if (opc <1 || opc > cont)
            {
                std::cout << "Opcion incorrecta" << std::endl;

                delete[] registros;
                delete[] vecTipo;
                return;
            }

        for (int y = 0; y < total; y++)
        {
            if (registros[y].getTipo() == vecTipo[opc-1]) {
                registros[y].MostrarAuto();
            }

        }

    delete[] registros;
    delete[] vecTipo;

}

void AutoArchivo::BuscarAutosPorKm(int km) {
    int total;
    Automovil* registros;
    AutoArchivo archi;

    total = archi.CantidadRegistros();

    registros = new Automovil[total];
    if (registros == nullptr) {
        std::cout << "EXCEDE LA MEMORIA." << std::endl;
        return;
    }

    bool result = archi.ListarAutos(registros, total);

        bool encontrado = false;
        for (int i = 0; i < total; ++i) {
            if (registros[i].getKm() >= km) {
                registros[i].MostrarAuto();
                encontrado = true;
            }
        }
        if (!encontrado) {
            std::cout << "No se tenemos disponibles autos con mas de " << km << " kilometros." << std::endl;
        }


    delete[] registros;
}
void AutoArchivo::BuscarAutosPorPrecio(double precio) {
    int total;
    Automovil* registros;
    AutoArchivo archi;

    total = archi.CantidadRegistros();

    registros = new Automovil[total];
    if (registros == nullptr) {
        std::cout << "EXCEDE LA MEMORIA." << std::endl;
        return;
    }

    bool result = archi.ListarAutos(registros, total);

        bool encontrado = false;
        for (int i = 0; i < total; ++i) {
            if (registros[i].getPrecio() >= precio) {
                registros[i].MostrarAuto();
                encontrado = true;
            }
        }
        if (!encontrado) {
            std::cout << "No se hay disponibles autos con un precio mayor a " << precio << "." << std::endl;
        }


    delete[] registros;
}

void AutoArchivo::MarcaMasVendida() {

    int total;
    Automovil* registros;
    AutoArchivo archi;

    total = archi.CantidadRegistros();
    registros = new Automovil[total];

    if (registros == nullptr) {
        std::cout << "EXCEDE LA MEMORIA." << std::endl;
        return;
    }

    bool result = archi.ListarAutos(registros, total);

    std::string* vecMarcas = new std::string[total];
    int cont = 0;

    //Veo si la marca del registro actual esta en el vector, sino esta lo inserto
    for (int i = 0; i < total; ++i) {
        std::string marcaActual = registros[i].getMarca();
        bool encontro = false;

        for (int j = 0; j < cont; ++j) {
            if (vecMarcas[j] == marcaActual) {
                encontro = true;
            }
        }

        if (!encontro) {
            vecMarcas[cont] = marcaActual;
            cont++;
        }
    }

    //Registro las ventas
    int* vecVentas = new int[cont] {0};
    for (int i = 0; i < total; ++i) {
        std::string marcaActual = registros[i].getMarca();
        bool vendido = registros[i].getEstado();

        for (int j = 0; j < cont; ++j) {
            if (vecMarcas[j] == marcaActual && !vendido) {
                vecVentas[j]++;
                break;
            }
        }
    }

    // Encontrar la marca con el mayor número de ventas
    int maxVentas = vecVentas[0];
    int marca = 0;
    for (int i = 1; i < cont; ++i) {
        if (vecVentas[i] > maxVentas) {
            maxVentas = vecVentas[i];
            marca = i;
        }
    }

    std::cout << "Marca mas vendida: " << vecMarcas[marca] << std::endl;
    std::cout << "Unidades vendidas: " << maxVentas << std::endl;

    delete[] registros;
    delete[] vecMarcas;
    delete[] vecVentas;

}
