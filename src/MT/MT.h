// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: CC
// Curso: 3º
// Práctica 02 : Maquina_turing
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 10/20/25
// Archivo MT.h : Declaración de la clase MT
//        En este fichero se declara la clase MT
//
// Historial de revisiones
//        10/20/25 - Creación (primera versión) del código
#ifndef C_MT_H
#define C_MT_H
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <tuple>
#include <map>
#include <iomanip>
#include "../Transicion/Transicion.h"
#include "../Alfabeto/Alfabeto.h"
#include "../funciones_main/funciones_main.h"
#include "../Cinta/Cinta.h"
using namespace std;

class MT {
 public:
  MT(const parametros_MT& parametros);
  bool procesar_cadena(const string& cadena);
  void reset();
 private:
  bool solve(const string& cadena); // el propio método saca la solución por pantalla
  Transicion Obtener_transicion(char simbolo_entrada); // transiciones posibles en cada paso
  void traza(const string& cadena, const Transicion& transicion);
  Alfabeto alfabeto_estados_;
  Alfabeto alfabeto_entrada_;
  Alfabeto alfabeto_cinta_;
  Alfabeto estados_finales_;
  std::multimap<std::string, Transicion> transiciones_;
  Cinta cinta_;
  string estado_inicial_;
  string estado_actual_;
};


#endif