// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: CC
// Curso: 3º
// Práctica 02 : Maquina_turing
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 10/20/25
// Archivo Transicion.cc: Implementación de Transicion
//        En este fichero se implementa las funciones de la clase Transicion
//
// Historial de revisiones
//        10/20/25 - Creación (primera versión) del código

#include"Transicion.h"

/** Transicion::Transicion(char simbolo_leido, string nuevo_estado, char simbolo_escrito, char Movimiento)
  * @brief Crea el objeto de la clase Transicion.
  * @param simbolo_leido Símbolo leído de la cinta
  * @param nuevo_estado Nuevo estado al que se transita
  * @param simbolo_escrito Símbolo que se escribe en la cinta
  * @param Movimiento Movimiento que se realiza en la cinta
  * @param id Identificador de la transición
  * @return objeto de la clase Transicion
  */
Transicion::Transicion(char simbolo_leido, string nuevo_estado, char simbolo_escrito, char Movimiento, int id) : id_(id) {
  this->transicion_ = make_tuple(simbolo_leido, nuevo_estado, simbolo_escrito, Movimiento);
}

/**
 * @brief Getter para obtener la transición completa
 * @return tupla con los parámetros de la transición (símbolo entrada, símbolo cinta, nuevo estado, inserción cinta)
 */
tuple<char, string, char, char> Transicion::get_transicion() const {
  return this->transicion_;
}
