// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: CC
// Curso: 3º
// Práctica 02 : Maquina_turing
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 10/20/25
// Archivo MT.cc: Implementación de MT
//        En este fichero se implementa las funciones de la clase MT
//
// Historial de revisiones
//        10/20/25 - Creación (primera versión) del código

#include"MT.h"

/** MT::MT()
  * @brief Crea el objeto de la clase MT.
  * @param parametros Estructura que contiene los parámetros necesarios para crear el objeto MT
  * @return objeto de la clase MT
  */
MT::MT(parametros_MT const& parametros) { 
  this->estado_inicial_ = parametros.estado_inicial;
  this->alfabeto_estados_ = parametros.alfabeto_estados;
  this->alfabeto_entrada_ = parametros.alfabeto_entrada;
  this->alfabeto_cinta_ = parametros.alfabeto_cinta;
  this->estados_finales_ = parametros.estados_finales;
  this->transiciones_ = parametros.transiciones;
  this->estado_actual_ = parametros.estado_inicial;
  this->cinta_ = Cinta(parametros.simbolo_blanco);
}

/** bool MT::procesar_cadena(const string& cadena)
  * @brief Función que procesa la cadena y devuelve si es aceptada o no
  * @param cadena: cadena a evaluar
  * @return booleano que indica si la cadena es aceptada o no (true si es aceptada, false en caso contrario)
  */
bool MT::procesar_cadena(const string& cadena) {
  // compruebo que la cadena está en el alfabeto de entrada
  vector<char> caracteres_cadena(cadena.begin(), cadena.end());
  if (!alfabeto_entrada_.AllIn(caracteres_cadena)) {
    throw std::invalid_argument("La cadena contiene símbolos que no pertenecen al alfabeto de entrada");
  }
  this->solve(cadena);
  if (this->estados_finales_.In(this->estado_actual_)) {
    return true;
  } else {
    return false;
  }
}

/** void MT::reset()
  * @brief Resetea la máquina de Turing a su estado inicial
  */
void MT::reset() {
  this->estado_actual_ = this->estado_inicial_;
  // reseteo la cinta
}

/** bool MT::solve(const string& cadena)
  * @brief Resuelve si la cadena es aceptada o no por la máquina de Turing.
  * @param cadena: cadena a evaluar
  * @return booleano que indica si la cadena es aceptada o no (true si es aceptada, false en caso contrario)
  */
bool MT::solve(const string& cadena) {
  // Implementación del algoritmo de la máquina de Turing
  this->cinta_.poner_palabra(cadena);
  while (true) {
    char simboloEntrada = this->cinta_.leer();
    Transicion transicion = this->Obtener_transicion(simboloEntrada);
    this->traza(cadena, transicion);
    if (transicion.get_id() == -1) {
      // No hay transicion posible
      return false;
    }
    // Ejecuto la transicion
    auto [simbolo_leido, nuevo_estado, simbolo_escrito, movimiento_cinta] = transicion.get_transicion();
    this->estado_actual_ = nuevo_estado;
    this->cinta_.escribir(simbolo_escrito);
    this->cinta_.mover(movimiento_cinta);
  }
  return false;
}

/** 
 * @brief Devuelve la transicion según el símbolo de entrada
 * @param simbolo_leido: símbolo de entrada
 * @return transicion correspondiente al símbolo de entrada y al estado actual
 */
Transicion MT::Obtener_transicion(char simbolo_leido) {
  auto range = this->transiciones_.equal_range(this->estado_actual_);
  for (auto it = range.first; it != range.second; ++it) {
    auto [simbolo_leido_, nuevo_estado, simbolo_escrito, movimiento_cinta] = it->second.get_transicion();
    if (simbolo_leido_ == simbolo_leido) {
      return it->second;
    }
  }
  return Transicion('\0', "", '\0', '\0', -1); // transicion nula si no se encuentra
}

/**
 * @brief Muestra la traza de la máquina de Turing
 */
void MT::traza(const string& cadena, const Transicion& transicion) {
  // transformo la cadena en un vector de chars para facilitar la impresión
  std::cout << "Estado actual: " << std::setw(2) << this->estado_actual_ << std::setw(9);
  std::cout << "Cinta: " << std::setw(20) << this->cinta_.to_string() << std::setw(26);
  std::cout << "Transición utilizada: "<< (transicion.get_id() == -1 ? "-" : std::to_string(transicion.get_id())) << std::endl;
  std::cout << "-------------------------------------------------------------------------------" << std::endl;
}