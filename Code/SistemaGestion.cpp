#include <iostream>
#include "sistemaGestion.h"
#include "PuntoDeRetiro.h"
#include "PuntoDeRetiroArchivo.h"

void sistemaGestion::MenuPrincipal() {

	std::cout << "--------MENU PRINCIPAL--------" << std::endl << std::endl;
	std::cout << "1- AUTOMOVILES" << std::endl;
	std::cout << "2- VENDEDORES" << std::endl;
	std::cout << "3- CLIENTES" << std::endl;
	std::cout << "4- VENTAS" << std::endl;
	std::cout << "5- PUNTOS DE RETIROS" << std::endl;
	std::cout << "6- INFORMES" << std::endl;
	std::cout << "0- SALIR" << std::endl;
	std::cout << "ELEGIR OPCION: ";
}

void sistemaGestion::SubMenu(int opc) {
	int opcSubmenu;
	switch (opc)
	{
	case 1:
		std::cout << "--------SUB MENU--------" << std::endl << std::endl;
		std::cout << "1- Buscar autos en stock." << std::endl;
		std::cout << "2- Listar autos para la venta." << std::endl;
		std::cout << "3- Agregar auto." << std::endl;
		std::cout << "0- SALIR" << std::endl;
		std::cout << "ELEGIR OPCION: ";
		std::cin >> opcSubmenu;
		system("pause");
		system("cls");
		switch (opcSubmenu)
		{
		case 1:
			MenuBusquedaAuto();
			break;
		case 2:
			AutosenStockParaVender();
			break;
		case 3:
			AgregarAutomovil();
			break;
		case 0:
			MenuPrincipal();
			break;
		default:
			std::cout << "Opcion Incorrecta. " << std::endl;
			break;
		}
		break;
	case 2:
		std::cout << "--------SUB MENU--------" << std::endl << std::endl;
		std::cout << "1- Listar vendedores activos." << std::endl;
		std::cout << "2- Alta de vendedor." << std::endl;
		std::cout << "3- Baja/Modificacion de vendedor." << std::endl;
		std::cout << "4- Historial de vendedores." << std::endl;
		std::cout << "0- SALIR" << std::endl;
		std::cout << "ELEGIR OPCION: ";
		std::cin >> opcSubmenu;
		system("pause");
		system("cls");
		switch (opcSubmenu)
		{
		case 1:
			vendedores_activos();
			break;
		case 2:
			AgregarVendedor();
			break;
		case 3:
			ModificarVendedor();
			break;
		case 4:
			historial_vendedores();
			break;
		case 0:
			MenuPrincipal();
			break;
		default:
			std::cout << "Opcion Incorrecta. " << std::endl;
			break;
		}
		break;
	case 3:
		std::cout << "--------SUB MENU--------" << std::endl << std::endl;
		std::cout << "1- Historial de clientes." << std::endl;
		std::cout << "0- SALIR" << std::endl;
		std::cout << "ELEGIR OPCION: ";
		std::cin >> opcSubmenu;
		system("pause");
		system("cls");
		switch (opcSubmenu)
		{
		case 1:
			historial_clientes();
			break;
		case 0:
			MenuPrincipal();
			break;
		default:
			std::cout << "Opcion Incorrecta. " << std::endl;
			break;
		}
		break;
	case 4:
		std::cout << "--------SUB MENU--------" << std::endl << std::endl;
		std::cout << "1- Realizar ventas." << std::endl;
		std::cout << "2- Historial de facturas." << std::endl;
		std::cout << "0- SALIR" << std::endl;
		std::cout << "ELEGIR OPCION: ";
		std::cin >> opcSubmenu;
		system("pause");
		system("cls");
		switch (opcSubmenu)
		{
		case 1:
			realizarVenta();
			break;
		case 2:
			historialFacturas();
			break;
		case 0:
			MenuPrincipal();
			break;
		default:
			std::cout << "Opcion Incorrecta. " << std::endl;
			break;
		}
		break;
	case 5:
		std::cout << "--------SUB MENU--------" << std::endl << std::endl;
		std::cout << "1- Listar puntos de retiro." << std::endl;
		std::cout << "1- Alta de punto de retiro." << std::endl;
		std::cout << "2- Baja/Modificacion de punto de retiro." << std::endl;
		std::cout << "0- SALIR" << std::endl;
		std::cout << "ELEGIR OPCION: ";
		std::cin >> opcSubmenu;
		system("pause");
		system("cls");
		switch (opcSubmenu)
		{
		case 1:
			AutosenStockParaVender();
			break;
		case 2:
			AgregarPuntoDeRetiro();
			break;
		case 3:
			ModificarPuntoDeRetiro();
			break;
		case 0:
			MenuPrincipal();
			break;
		default:
			std::cout << "Opcion Incorrecta. " << std::endl;
			break;
		}
		break;
	case 6:
		std::cout << "--------SUB MENU--------" << std::endl << std::endl;
		std::cout << "1- Mes con mas ventas del anio actual" << std::endl;
		std::cout << "2- Ventas anulaes." << std::endl;
		std::cout << "3- Ventas por vendedor." << std::endl;
		std::cout << "4- Marca mas vendida." << std::endl;
		std::cout << "0- SALIR" << std::endl;
		std::cout << "ELEGIR OPCION: ";
		std::cin >> opcSubmenu;
		system("pause");
		system("cls");
		switch (opcSubmenu)
		{
		case 1:
			Mes_masvendido();
			break;
		case 2:
			Ventas_anuales();
			break;
		case 3:
			Ventas_vendedores();
			break;
		case 4:
			AutoArchivo::MarcaMasVendida();
			break;
		case 0:
			MenuPrincipal();
			break;
		default:
			std::cout << "Opcion Incorrecta. " << std::endl;
			break;
		}
		break;
	case 0:
		std::cout << "Saliendo del programa.";
		break;
	default:
		std::cout << "Opción no válida. Intente de nuevo.";
		break;
	}
}

void sistemaGestion::MenuBusquedaAuto() {
	int opcMenubusqueda;

		std::cout << "--------Busqueda--------" << std::endl << std::endl;
		std::cout << "1- Busqueda de auto por marca" << std::endl;
		std::cout << "2- Busqueda de auto por anio" << std::endl;
		std::cout << "3- Busqueda de auto por tipo" << std::endl;
		std::cout << "4- Busqueda de auto por km" << std::endl;
		std::cout << "5- Busqueda de auto por precio" << std::endl;
		std::cout << "0- SALIR" << std::endl;
		std::cout << "ELEGIR OPCION: ";
		std::cin >> opcMenubusqueda;
		system("pause");
		system("cls");
		switch (opcMenubusqueda) {
		case 1:
			AutoArchivo::BuscarAutosPorMarca();
			break;
		case 2:
			AutoArchivo::BuscarAutosPorAnio();
			break;
		case 3:
			AutoArchivo::BuscarAutosPorTipo();
			break;
		case 4:
			AutoArchivo::BuscarAutosPorKm();
			break;
		case 5:
			AutoArchivo::BuscarAutosPorPrecio();
			break;
		case 0:
			MenuPrincipal();
			break;
		default:
			std::cout << "Opción no válida. Intente de nuevo." << std::endl;
			break;
		}

}

void sistemaGestion::gestionarOpciones() {
	int opcion;
	do {
		MenuPrincipal();
		std::cin >> opcion;
		std::cin.ignore();
		system("cls");

		SubMenu(opcion);
		system("pause");
		system("cls");

	} while (opcion != 0);

}

void sistemaGestion::AutosenStockParaVender() {
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

	if (result) {
		for (int X = 0; X < total; X++) {
			if (registros[X].getEstado()) {
				registros[X].MostrarAuto();
			}
		}
	}
	else {
		std::cout << "NO SE PUDO LEER EL ARCHIVO." << std::endl;
	}

	delete[] registros;
}

void sistemaGestion::AgregarAutomovil() {
	bool result;
	Automovil registro;
	AutoArchivo archi;

	registro.CargarAuto();
	result = archi.AgregarAuto(registro);

	if (result) {
		std::cout << "SE AGREGO CON EXITO." << std::endl;
	}
	else {
		std::cout << "NO SE PUDO AGREGAR EL REGISTRO." << std::endl;
	}
}

void sistemaGestion::vendedores_activos() {
	int total;
	Vendedor* registros;
	VendedorArchivo archi;

	total = archi.CantidadRegistros();

	registros = new Vendedor[total];
	if (registros == nullptr) {
		std::cout << "EXCEDE LA MEMORIA." << std::endl;
		return;
	}

	bool result = archi.ListarVendedores(registros, total);

	if (result) {
		for (int X = 0; X < total; X++) {
			if (registros[X].getEstado()) {
				registros[X].MostrarVendedor();
			}
		}
	}
	else {
		std::cout << "NO SE PUDO LEER EL ARCHIVO." << std::endl;
	}

	delete[] registros;
}

void sistemaGestion::AgregarVendedor() {
	Vendedor registroVendedor;
	VendedorArchivo archiVendedor;

	registroVendedor.CargarVendedor();
	bool result = archiVendedor.AgregarVendedor(registroVendedor);

	if (result) {
		std::cout << "VENDEDOR AGREGADO CON EXITO." << std::endl;
	}
	else { std::cout << "NO SE PUDO GUARDAR EL VENDEDOR." << std::endl; }
}

void sistemaGestion::ModificarVendedor() {
	Vendedor registroVendedor;
	VendedorArchivo archi;
	int legajo, pos = -1;
	int opc;

	std::cout << "Elija una opcion: " << std::endl;
	std::cout << "1 - Modificar registro." << std::endl;
	std::cout << "2 - Dar de baja." << std::endl;
	std::cin >> opc;

	system("pause");
	std::cout << "      Presione una tecla para continuar..." << std::endl;
	system("cls");

	if (opc != 1 && opc != 2)
	{
		std::cout << "Opcion incorrecta " << std::endl;
		return;
	}
	else
	{
		std::cout << "Ingrese el legajo. " << std::endl;
		std::cin >> legajo;
		system("cls");
		pos = archi.BuscarVendedor(legajo);
	}
	if (opc == 1)
	{
		registroVendedor = archi.ListarVendedor(pos);

		std::cout << "Datos a modificar: " << std::endl;
		registroVendedor.MostrarVendedor();

		system("pause");
		std::cout << "      Presione una tecla para continuar..." << std::endl;
		system("cls"); // Limpia la pantalla antes de mostrar el menú nuevamente

		std::cout << "MODIFICAR: " << std::endl;

		registroVendedor.ModificarVendedor();

		if (archi.ModificarVendedor(registroVendedor, pos))
		{
			std::cout << "Modificacion exitosa " << std::endl;
		}
		else
		{
			std::cout << "ERROR al guardar la modificacion." << std::endl;
		}

	}
	else if (opc == 2)
	{
		registroVendedor = archi.ListarVendedor(pos);
		system("pause");
		std::cout << "      Presione una tecla para continuar..." << std::endl;
		system("cls");
		registroVendedor.BajaVendedor();
		archi.ModificarVendedor(registroVendedor, pos);
		registroVendedor.MostrarVendedor();
		std::cout << "Modificacion exitosa " << std::endl;
	}
}

void sistemaGestion::historial_vendedores() {
	int total;
	Vendedor* registros;
	VendedorArchivo archi;

	total = archi.CantidadRegistros();

	registros = new Vendedor[total];
	if (registros == nullptr) {
		std::cout << "EXCEDE LA MEMORIA." << std::endl;
		return;
	}

	bool result = archi.ListarVendedores(registros, total);

	if (result) {
		for (int X = 0; X < total; X++) {
			registros[X].MostrarVendedor();
		}
	}
	else {
		std::cout << "NO SE PUDO LEER EL ARCHIVO." << std::endl;
	}

	delete[] registros;
}

void sistemaGestion::historial_clientes() {
	int total;
	Cliente* registros;
	ClienteArchivo archi;

	total = archi.CantidadRegistros();

	registros = new Cliente[total];
	if (registros == nullptr) {
		std::cout << "EXCEDE LA MEMORIA." << std::endl;
		return;
	}

	bool result = archi.ListarClientes(registros, total);

	if (result) {
		for (int X = 0; X < total; X++) {
			registros[X].MostrarCliente();
		}
	}
	else {
		std::cout << "NO SE PUDO LEER EL ARCHIVO." << std::endl;
	}

	delete[] registros;
}

void sistemaGestion::realizarVenta() {
	bool viejo, eleccion1, eleccion2, result, exitoso;
	int dni, posicionCliente = -1, posicionPatente = -1, posVendedor, legajoVendedor, idpago;
	Cliente registroCliente;
	ClienteArchivo archiCliente;

	Automovil registroAuto;
	DetalleFactura registroFactura;
	AutoArchivo archiAuto;
	Vendedor registroVendedor;
	VendedorArchivo archiVendedor;
	char patente[8];


	std::cout << "ES CLIENTE: 1-SI 0-NO: ";
	std::cin >> viejo;
	std::cin.ignore();
	system("cls");
	if (viejo) {
		std::cout << "PEDIR DNI: ";
		std::cin >> dni;
		posicionCliente = archiCliente.BuscarCliente(dni);
		registroCliente = archiCliente.ListarCliente(posicionCliente);
		system("cls");
	}
	else {
		registroCliente.CargarCliente();
		//exitoso = archiCliente.agregarRegistro(registroCliente);
		//posicionCliente = archiCliente.buscarRegistro(registroCliente.getdni());
		posicionCliente = archiCliente.CantidadRegistros() + 1;
		system("cls");
	}
	if (posicionCliente >= 0) {
		//std::cout<< posicionCliente;
		std::cout << "QUE AUTO ESTAS BUSCANDO: " << std::endl;
		AutosenStockParaVender();
		std::cout << "TE INTERESA ALGUNO: 1-SI 0-NO: ";
		std::cin >> eleccion1;
		if (eleccion1) {
			std::cin.ignore();
			std::cout << "PATENTE: ";
			std::cin.getline(patente, 8, '\n');
			posicionPatente = archiAuto.BuscarAuto(patente);
			//aca yo yo tengo las pantentes en consola de AutosenStock() pero si yo pongo una patente que antes estuvo tambien me la toma
			//se entiende que no va a haber un auto que no figura en autos en stock, le cambio la logica ?
			system("cls");
			if (posicionPatente >= 0) {
				registroAuto = archiAuto.ListarAuto(posicionPatente);
				registroAuto.MostrarAuto();
				std::cout << "Es EL AUTO QUE ESTAS BUSCANDO 1-SI 0-NO: ";
				std::cin >> eleccion2;
				system("cls");
				if (eleccion2) {
					std::cout << "MEDIO DE PAGO: 1-EFECTIVO. 2-FINANCIACION TARJETA. 3-CREDITO PERSONAL: ";
					std::cin >> idpago;
					if (idpago > 0 && idpago <= 3) {
						registroFactura.setIDPago(idpago);
						std::cout << "LEGAJO DEL VENDEDOR: ";
						std::cin >> legajoVendedor;
						posVendedor = archiVendedor.BuscarVendedor(legajoVendedor);
						if (posVendedor >= 0) {
							registroVendedor = archiVendedor.ListarVendedor(posVendedor);
							if (archiCliente.BuscarCliente(dni) < 0) {
								exitoso = archiCliente.AgregarCliente(registroCliente);
							}
							registroAuto.setEstado(false);
							archiAuto.ModificarAuto(registroAuto, posicionPatente);
							result = generarFactura(registroCliente, registroVendedor, registroAuto, registroFactura);
							if (result) {
								//exitoso = archiCliente.agregarRegistro(registroCliente); hacer logica para ver si existe, sino no lo puedo agregar.
								std::cout << "Venta realizada con exito.";
							}
							else {
								std::cout << "no se pudo realizar la venta";
							}
						}
						else {
							std::cout << "NO SE ENCONTRO EL VENDEDOR.";
							system("pause");
						}
					}
					else {
						std::cout << "FORMA DE PAGO INCORRECTO";
						system("pause");
					}

				}
			}
			else {
				std::cout << "NO SE ENCONTRO LA PATENTE.";
				system("pause");
			}
		}
	}
	else {
		std::cout << "NO SE ENCONTRO EL CLIENTE." << std::endl;
		system("pause");
	}

}

bool sistemaGestion::generarFactura(Cliente& registroCliente, Vendedor& registroVendedor, Automovil& registroAuto, DetalleFactura& registroFactura) {
	FacturaArchivo archiFactura;
	Fecha sistema;
	std::string patente;
	int total;
	total = archiFactura.CantidadRegistros() + 1;


	registroFactura.setIDVenta(total);
	registroFactura.setIDVendedor(registroVendedor.getLegajo());
	registroFactura.setIDCliente(registroCliente.getIDCliente());
	patente = registroAuto.getPatente();
	registroFactura.setPatente(patente);
	registroFactura.setSubtotal(registroAuto.getPrecio());
	registroFactura.CalcularTotal();
	sistema.FechaSistema();
	registroFactura.setFecha(sistema);

	bool result = archiFactura.AgregarFactura(registroFactura);
	return result;

}

void sistemaGestion::historialFacturas() {
	int total;
	DetalleFactura* registros;
	FacturaArchivo archi;

	total = archi.CantidadRegistros();

	registros = new DetalleFactura[total];
	if (registros == nullptr) {
		std::cout << "EXCEDE LA MEMORIA." << std::endl;
		return;
	}

	bool result = archi.ListarFacturas(registros, total);

	if (result) {
		for (int X = 0; X < total; X++) {
			registros[X].MostrarFactura();
		}
	}
	else {
		std::cout << "NO SE PUDO LEER EL ARCHIVO." << std::endl;
	}

	delete[] registros;
}

void sistemaGestion::ListarPuntosDeRetiros() {
	PuntoDeRetiro* pPuntoDeRetiro;
	PuntoDeRetiroArchivo archiPunto;

	int total = archiPunto.CantidadRegistros();
	pPuntoDeRetiro = new PuntoDeRetiro[total];
	if (pPuntoDeRetiro == nullptr) {
		std::cout << "EXCEDE LA MEMORIA." << std::endl;
		return;
	}
	bool result = archiPunto.ListarPuntosDeRetiros(pPuntoDeRetiro, total);

	if (result) {
		for (int i = 0; i < total; i++)
		{
			pPuntoDeRetiro[i].MostrarPuntoDeRetiro();
		}
	}
	else { std::cout << "No se pudo guardar el Punto de retiro." << std::endl; }
}

void sistemaGestion::AgregarPuntoDeRetiro() {
	PuntoDeRetiro puntoDeRetiro;
	PuntoDeRetiroArchivo archiPunto;

	puntoDeRetiro.CargarPuntoDeRetiro();
	bool result = archiPunto.AgregarPuntoDeRetiro(puntoDeRetiro);

	if (result) {
		std::cout << "Punto de retiro agreagdo con exito." << std::endl;
	}
	else { std::cout << "No se pudo guardar el Punto de retiro." << std::endl; }
}

void sistemaGestion::ModificarPuntoDeRetiro() {

	PuntoDeRetiro puntoDeRetiro;
	PuntoDeRetiroArchivo archiPunto;

	int total = archiPunto.CantidadRegistros(); // Traemos la cantiad de registros para el for

	for (int i = 0; i < total; i++)
	{
		puntoDeRetiro = archiPunto.ListarPuntoDeRetiro(i);
		puntoDeRetiro.MostrarPuntoDeRetiro();
	}
	int id;
	std::cout << "Ingrese el ID del registro a modificar" << std::endl;
	std::cin >> id;
	system("pause");
	std::cout << "      Presione una tecla para continuar..." << std::endl;
	system("cls");
	archiPunto.ModificarPuntoDeRetiro(id);
}

int sistemaGestion::Mes_masvendido() {

	int anio = Fecha::AnioActual(), meses[12] = {}, total, mayor, pos;
	FacturaArchivo archi;
	DetalleFactura* registroFactura;
	bool result;

	total = archi.CantidadRegistros();

	registroFactura = new DetalleFactura[total];

	if (registroFactura == nullptr) {
		return -1;
	}
	result = archi.ListarFacturas(registroFactura, total);

	if (result) {
		for (int X = 0; X < total; X++) {
			if (registroFactura[X].getFecha().getAnio() == anio) {
				meses[registroFactura[X].getFecha().getMes() - 1]++;
			}
		}
	}
	else {
		return -2;
	}

	for (int X = 0; X < 12; X++) {
		if (X == 0) {
			mayor = meses[X];
			pos = X + 1;
		}
		else {
			if (mayor < meses[X]) {
				mayor = meses[X];
				pos = X + 1;
			}
		}
	}
	delete[] registroFactura;
	return pos;

}

void sistemaGestion::Ventas_anuales() {
	FacturaArchivo archi;
	DetalleFactura* registroFactura;
	int total, anio_actual, cantidad_anios, * vAnios, numero;
	const int anio_inicio = 2015;
	Fecha fecha_actual;

	fecha_actual.FechaSistema();
	anio_actual = fecha_actual.getAnio();
	cantidad_anios = anio_actual - anio_inicio;

	vAnios = new int[cantidad_anios] {};

	if (vAnios == nullptr) {
		std::cout << "EXCEDE LA MEMORIA LA CANTIDAD DE ANIOS" << std::endl;
		return;
	}

	total = archi.CantidadRegistros();

	registroFactura = new DetalleFactura[total];

	if (registroFactura == nullptr) {
		std::cout << "EXCEDE LA MEMORIA LA CANTIDAD DE REGISTROS." << std::endl;
		return;
	}

	bool result = archi.ListarFacturas(registroFactura, total);

	if (result) {
		for (int X = 0; X < cantidad_anios; X++) {
			vAnios[X] = 0;
		}

		for (int X = 0; X < total; X++) {
			numero = registroFactura[X].getFecha().getAnio() - anio_inicio;
			vAnios[numero]++;
		}
	}
	else {
		std::cout << "NO SE PUDO LEER LOS REGISTROS.." << std::endl;
	}

	for (int X = 0; X <= cantidad_anios; X++) {
		std::cout << vAnios[X] << std::endl;
	}

	delete[] vAnios;
	delete[] registroFactura;
}

void sistemaGestion::Ventas_vendedores() {
	FacturaArchivo archiFactura;
	VendedorArchivo archiVendedores;
	int* vVendedores, totalfacturas, totalvendedores, numero;
	DetalleFactura* registroFactura;

	totalfacturas = archiFactura.CantidadRegistros();

	registroFactura = new DetalleFactura[totalfacturas];

	if (registroFactura == nullptr) {
		std::cout << "EXCEDE LA MEMORIA DE FACTURAS." << std::endl;
		return;
	}
	bool result = archiFactura.ListarFacturas(registroFactura, totalfacturas);
	if (result) {

		totalvendedores = archiVendedores.CantidadRegistros();


		vVendedores = new int[totalvendedores];

		if (vVendedores == nullptr) {
			std::cout << "EXCEDE LA MEMORIA DE vendedores." << std::endl;
			return;
		}

		for (int X = 0; X < totalvendedores; X++) {
			vVendedores[X] = 0;
		}

		for (int X = 0; X < totalfacturas; X++) {
			numero = registroFactura[X].getIDVendedor();
			vVendedores[numero - 1]++;
		}

		for (int X = 0; X < totalvendedores; X++) {
			std::cout << vVendedores[X] << std::endl;
		}
		delete[] registroFactura;
		delete[] vVendedores;
	}
	else {
		std::cout << "NO SE PUDO ABRIR EL ARCHIVO" << std::endl;
	}

}

