// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: CC
// Curso: 3º
// Práctica 02 : Maquina_turing
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 10/20/25
// Archivo Cinta.cc: Implementación de Cinta
//        En este fichero se implementa las funciones de la clase Cinta
//
// Historial de revisiones
//        10/20/25 - Creación (primera versión) del código

#include "Cinta.h"
/** Cinta::Cinta(char simbolo_blanco)
  * @brief Crea el objeto de la clase Cinta.
  * @param simbolo_blanco: símbolo que representa el espacio en blanco en la cinta
  * @return objeto de la clase Cinta
  */
Cinta::Cinta(char simbolo_blanco) {
  this->simbolo_blanco_ = simbolo_blanco;
  this->cinta_.push_back(simbolo_blanco_);
  this->cabeza_ = 0;
}

/** char Cinta::leer() const
  * @brief Lee el símbolo en la posición actual de la cabeza
  * @return símbolo leído
  */
char Cinta::leer() const {
  return this->cinta_[this->cabeza_];
}

/** void Cinta::escribir(char simbolo)
  * @brief Escribe un símbolo en la posición actual de la cabeza
  * @param simbolo: símbolo a escribir
  */
void Cinta::escribir(char simbolo) {
  this->cinta_[this->cabeza_] = simbolo;
}

/** void Cinta::mover(char direccion)
  * @brief Mueve la cabeza de lectura/escritura en la dirección indicada
  * @param direccion: 'L' para izquierda, 'R' para derecha
  */
void Cinta::mover(char direccion) {
  if (direccion == 'L') {
    if (this->cabeza_ == 0) {
      this->cinta_.push_front(this->simbolo_blanco_);
      // cabeza_ sigue apuntando al nuevo 0 (celda creada)
    } else {
      --this->cabeza_;
    }
  } else if (direccion == 'R') {
    if (this->cabeza_ + 1 == this->cinta_.size()) {
      this->cinta_.push_back(this->simbolo_blanco_);
    }
    ++this->cabeza_;
  }
}

/** void Cinta::poner_palabra(const std::string& palabra)
  * @brief Coloca una palabra en la cinta, empezando desde la posición 0
  * @param palabra: palabra a colocar en la cinta
  */
void Cinta::poner_palabra(const std::string& palabra) {
  this->cinta_.clear();
  for (char simbolo : palabra) {
    this->cinta_.push_back(simbolo);
  }
  this->cabeza_ = 0;
}

/** void Cinta::reset()
  * @brief Resetea la cinta a su estado inicial
  */
void Cinta::reset() {
  this->cinta_.clear();
  this->cinta_.push_back(this->simbolo_blanco_);
  this->cabeza_ = 0;
}

/** int Cinta::get_cabeza() const
  * @brief Devuelve la posición actual de la cabeza de lectura/escritura
  * @return posición de la cabeza
  */
int Cinta::get_cabeza() const {
  return this->cabeza_;
}

/** std::string Cinta::to_string() const
  * @brief Devuelve una representación en cadena de la cinta
  * @return representación en cadena de la cinta
  */
std::string Cinta::to_string() const {
  std::string resultado;
  for (int i = 0; i < this->cinta_.size(); ++i) {
    if (i == this->cabeza_) {
      resultado += '[';
      resultado += this->cinta_[i];
      resultado += ']';
    } else {
      resultado += this->cinta_[i];
    }
  }
  return resultado;
}