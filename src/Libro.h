//Libro.h

#ifndef LIBRO_H
#define LIBRO_H

#include <string>
#include <iostream>

class Libro {
private:
    std::string isbn;
    std::string titulo;
    std::string autor;

public:
    Libro();
    Libro(std::string isbn, std::string titulo, std::string autor);

    std::string getISBN() const;
    std::string getTitulo() const;
    std::string getAutor() const;

    void mostrarInfo() const;

    std::string toFileString() const;
};

#endif

