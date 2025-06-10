//Biblioteca.cpp

#include "Biblioteca.h"
#include <fstream>
#include <sstream>

Biblioteca::Biblioteca() {}

void Biblioteca::agregarLibro(const Libro& libro) {
    libros.push_back(libro);
}

void Biblioteca::listarLibros() const {
    if (libros.empty()) {
        std::cout << "No hay libros registrados.\n";
        return;
    }

    std::cout << "Lista de libros:\n";
    for (size_t i = 0; i < libros.size(); ++i) {
        libros[i].mostrarInfo();
    }
}

void Biblioteca::guardarEnArchivo(const std::string& rutaArchivo) const {
    std::ofstream archivo(rutaArchivo.c_str(), std::ios::out);
    if (!archivo) {
        std::cerr << "Error al abrir el archivo para guardar.\n";
        return;
    }

    for (size_t i = 0; i < libros.size(); ++i) {
        archivo << libros[i].toFileString() << std::endl;
    }
}


void Biblioteca::cargarDesdeArchivo(const std::string& rutaArchivo) {
    std::ifstream archivo(rutaArchivo.c_str());
    if (!archivo) {
        std::cerr << "No se pudo abrir el archivo para lectura.\n";
        return;
    }

    std::string linea;
    while (std::getline(archivo, linea)) {
        std::stringstream ss(linea);
        std::string isbn, titulo, autor;

        std::getline(ss, isbn, '|');
        std::getline(ss, titulo, '|');
        std::getline(ss, autor);

        if (!isbn.empty() && !titulo.empty() && !autor.empty()) {
            libros.push_back(Libro(isbn, titulo, autor));
        }
    }
}

