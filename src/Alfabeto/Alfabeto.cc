// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: CC
// Curso: 3º
// Práctica 02 : Maquina_turing
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 10/20/25
// Archivo Alfabeto.cc: Implementación de Alfabeto
//        En este fichero se implementa las funciones de la clase Alfabeto
//
// Historial de revisiones
//        10/20/25 - Creación (primera versión) del código

#include"Alfabeto.h"

/** Alfabeto::Alfabeto()
  * @brief Crea el objeto de la clase Alfabeto.
  * @param 
  * @return objeto de la clase Alfabeto
  */
Alfabeto::Alfabeto() {
  
}

/** Alfabeto::Alfabeto(const vector<char>& simbolos)
  * @brief Crea el objeto de la clase Alfabeto con los símbolos dados.
  * @param simbolos: vector de símbolos que contendrá el alfabeto
  * @return objeto de la clase Alfabeto
  */
Alfabeto::Alfabeto(const vector<string>& simbolos) {
  simbolos_ = simbolos;
}

/** void Alfabeto::Insert(char simbolo)
  * @brief Añade un símbolo al alfabeto.
  * @param simbolo: símbolo a añadir al alfabeto
  * @return void
  */
void Alfabeto::Insert(string simbolo) {
  simbolos_.push_back(simbolo);
}

/** bool Alfabeto::In(char simbolo) const
  * @brief Comprueba si un símbolo está en el alfabeto.
  * @param simbolo: símbolo a comprobar si está en el alfabeto
  * @return true si el símbolo está en el alfabeto, false en caso contrario
  */
bool Alfabeto::In(string simbolo) const {
  for (const string& element : simbolos_) {
    if (element == simbolo) {
      return true;
    }
  }
  return false;
}
/** bool Alfabeto::In(char simbolo) const
  * @brief Comprueba si un símbolo está en el alfabeto.
  * @param simbolo: símbolo a comprobar si está en el alfabeto
  * @return true si el símbolo está en el alfabeto, false en caso contrario
  */
bool Alfabeto::In(char simbolo) const {
  return In(string(1, simbolo));
}

/** bool Alfabeto::AllIn(const vector<string>& simbolos) const
  * @brief Comprueba si todos los símbolos de un vector están en el alfabeto.
  * @param simbolos: vector de símbolos a comprobar si están en el alfabeto
  * @return true si todos los símbolos están en el alfabeto, false en caso contrario
  */
bool Alfabeto::AllIn(const vector<string>& simbolos) const {
  for (const string& simbolo : simbolos) {
    if (!this->In(simbolo)) {
      return false;
    }
  }
  return true;
}

/** bool Alfabeto::AllIn(const vector<char>& simbolos) const
  * @brief Comprueba si todos los símbolos de un vector están en el alfabeto.
  * @param simbolos: vector de símbolos a comprobar si están en el alfabeto
  * @return true si todos los símbolos están en el alfabeto, false en caso contrario
  */
bool Alfabeto::AllIn(const vector<char>& simbolos) const {
  for (const char& simbolo : simbolos) {
    if (!this->In(simbolo)) {
      return false;
    }
  }
  return true;
}

/** vector<string> Alfabeto::GetSimbolos() const
  * @brief Devuelve un vector con todos los símbolos del alfabeto.
  * @param 
  * @return vector con todos los símbolos del alfabeto
  */
vector<string> Alfabeto::GetSimbolos() const {
  return simbolos_;
}
