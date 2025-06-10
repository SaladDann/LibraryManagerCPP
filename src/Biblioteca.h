//Biblioteca.h

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include "Libro.h"
#include <vector>
#include <string>

class Biblioteca {
private:
    std::vector<Libro> libros;

public:
    Biblioteca();

    void agregarLibro(const Libro& libro);
    void listarLibros() const;
    void guardarEnArchivo(const std::string& rutaArchivo) const;
    void cargarDesdeArchivo(const std::string& rutaArchivo);
};

#endif

