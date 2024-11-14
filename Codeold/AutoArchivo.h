#pragma once
#include "Auto.h"

class AutoArchivo {
private:
    std::string _nombre;

public:
    AutoArchivo();
    bool AgregarAuto(Automovil& vehiculo);
    Automovil ListarAuto(int pos);
    bool ListarAutos(Automovil registros[], int cantidad);
    int CantidadRegistros();
    int BuscarAuto(char* patente);
    bool ModificarAuto(Automovil& vehiculo, int pos);
    static void BuscarAutosPorMarca();
    static void BuscarAutosPorAnio();
    static void BuscarAutosPorTipo();
    static void BuscarAutosPorKm();
    static void BuscarAutosPorPrecio();
    static void MarcaMasVendida();

};
