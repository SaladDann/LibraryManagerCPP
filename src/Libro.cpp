//Libro.cpp

#include "Libro.h"

Libro::Libro() {}

Libro::Libro(std::string isbn, std::string titulo, std::string autor)
    : isbn(isbn), titulo(titulo), autor(autor) {}

std::string Libro::getISBN() const { return isbn; }
std::string Libro::getTitulo() const { return titulo; }
std::string Libro::getAutor() const { return autor; }

void Libro::mostrarInfo() const {
    std::cout << "ISBN: " << isbn << ", Titulo: " << titulo << ", Autor: " << autor << std::endl;
}

std::string Libro::toFileString() const {
    return isbn + "|" + titulo + "|" + autor;
}

