// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: CC
// Curso: 3º
// Práctica 02 : Maquina_turing
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 10/20/25
// Archivo Alfabeto.h : Declaración de la clase Alfabeto
//        En este fichero se declara la clase Alfabeto
//
// Historial de revisiones
//        10/20/25 - Creación (primera versión) del código
#ifndef C_Alfabeto_H
#define C_Alfabeto_H
#include <iostream>
#include <vector>
using namespace std;

class Alfabeto {
 public:
  Alfabeto();
  Alfabeto(const vector<string>& simbolos);
  void Insert(string); // añade un símbolo al alfabeto
  bool In(string) const; // comprueba si un símbolo está en el alfabeto
  bool In(char) const; // comprueba si un símbolo está en el alfabeto
  bool AllIn(const vector<string>&) const; // comprueba si todos los símbolos están en el alfabeto
  bool AllIn(const vector<char>&) const; // comprueba si todos los símbolos están en el alfabeto
  vector<string> GetSimbolos() const; // devuelve un vector con todos los símbolos del alfabeto
 private:
  vector<string> simbolos_;
};

#endif