#pragma once
#include "AutoArchivo.h"
#include "ClienteArchivo.h"
#include "FacturaArchivo.h"
#include "VendedorArchivo.h"


class sistemaGestion {
private:
    void MenuPrincipal();
    void SubMenu(int opc);
    void MenuBusquedaAuto();

public:
    void gestionarOpciones();
    void AutosenStockParaVender();
    void AgregarAutomovil();
    void realizarVenta();
    void historial_clientes();
    void vendedores_activos();
    void historial_vendedores();
    void AgregarVendedor();
    bool generarFactura(Cliente& registroCliente, Vendedor& registroVendedor, Automovil& registroAuto, DetalleFactura& registroFactura);
    void historialFacturas();
    void ModificarVendedor();
    void AgregarPuntoDeRetiro();
    void ListarPuntosDeRetiros();
    void ModificarPuntoDeRetiro();
    void Ventas_anuales();
    int Mes_masvendido();
    void Ventas_vendedores();
};
