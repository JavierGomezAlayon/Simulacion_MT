// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: CC
// Curso: 3º
// Práctica 02 : Maquina_turing
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 10/20/25
// Archivo Transicion.h : Declaración de la clase Transicion
//        En este fichero se declara la clase Transicion
//
// Historial de revisiones
//        10/20/25 - Creación (primera versión) del código
#ifndef C_Transicion_H
#define C_Transicion_H
#include <iostream>
#include <tuple>
#include <string>
using namespace std;

class Transicion {
 public:
  Transicion(char, string, char, char, int id = 0);
  tuple<char, string, char, char> get_transicion() const;
  int get_id() const { return id_; }

 private:
  tuple<char, string, char, char> transicion_; // (símbolo entrada, nuevo estado, símbolo escrito, movimiento cinta)
  int id_; // identificador de la transición
};

#endif