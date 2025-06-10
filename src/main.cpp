#include <iostream>
#include <cstdlib> // Necesario para system()
#include <limits>
#include <string>

#include "Biblioteca.h"


using namespace std;

int main() {
    Biblioteca biblioteca;
    const string nombreArchivo = "data/libros.txt";
    // Carga libros desde archivo al iniciar
    biblioteca.cargarDesdeArchivo(nombreArchivo);

    int opcion = 0;
    do {
        cout << "\n=== Sistema de Gestion de Libros ===\n";
        cout << "1. Listar libros\n";
        cout << "2. Agregar libro\n";
        cout << "3. Guardar y salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // limpiar buffer

        switch (opcion) {
        	
            case 1:
            	system("cls");
                biblioteca.listarLibros();
                break;
            case 2: {
            	system("cls");
                string isbn, titulo, autor;
                cout << "Ingrese ISBN: ";
                getline(cin, isbn);
                cout << "Ingrese titulo: ";
                getline(cin, titulo);
                cout << "Ingrese autor: ";
                getline(cin, autor);

                Libro nuevoLibro(isbn, titulo, autor);
                biblioteca.agregarLibro(nuevoLibro);
                cout << "Libro agregado en memoria.\n";
                break;
            }
            case 3:
                system("cls");
                biblioteca.guardarEnArchivo(nombreArchivo);
                cout << "Libros guardados. Saliendo...\n";
                break;
            default:
            	system("cls");
                cout << "Opcion invalida. Intente de nuevo.\n";
        }
        
    } while (opcion != 3);

    return 0;
}


