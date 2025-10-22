// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: CC
// Curso: 3º
// Práctica 02 : Maquina_turing
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 10/20/25
// Archivo Cinta.h : Declaración de la clase Cinta
//        En este fichero se declara la clase Cinta
//
// Historial de revisiones
//        10/20/25 - Creación (primera versión) del código
#ifndef C_Cinta_H
#define C_Cinta_H
#include <deque>
#include <string>

class Cinta {
 public:
  Cinta(char simbolo_blanco = '-');
  char leer() const;
  void escribir(char simbolo);
  void mover(char direccion); // 'L' para izquierda, 'R' para derecha
  void poner_palabra(const std::string& palabra);
  void reset();
  int get_cabeza() const;
  std::string to_string() const;
 private:
  std::deque<char> cinta_;
  int cabeza_;
  char simbolo_blanco_;
};

#endif