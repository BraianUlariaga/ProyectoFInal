#pragma once
#include "AutoArchivo.h"
#include "ClienteArchivo.h"
#include "FacturaArchivo.h"
#include "VendedorArchivo.h"


class sistemaGestion {
private:
    void mostrarMenu();
    void ejecutarOpcion(int opcion);

public:
    void gestionarOpciones();
    void AutosenStock();
    void AgregarAutomovil();
    void realizarVenta();
    void historial_clientes();
    void vendedores_activos();
    void historial_vendedores();
    void AgregarVendedor();
    bool generarFactura(Cliente& registroCliente, Vendedor& registroVendedor, Automovil& registroAuto, DetalleFactura& registroFactura);
    void historialFacturas();
    void bajaVendedor();
    void Ventas_anuales();
    int Mes_masvendido();
    void Ventas_vendedores();
};
