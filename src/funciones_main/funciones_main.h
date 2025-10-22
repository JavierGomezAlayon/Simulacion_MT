// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: CC
// Curso: 3º
// Práctica 02 : Maquina_turing
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 10/20/25
// Archivo funciones_main.h: Declaración de las funciones del main
//        En este fichero se declara las funciones que se utilizan en el main.cc
//
// Historial de revisiones
//        10/20/25 - Creación (primera versión) del código
#ifndef C_funciones_main_H
#define C_funciones_main_H

#include<iostream>
#include<string>
#include<exception>
#include<sstream>
#include<fstream>
#include<vector>
#include<map>
#include "../Transicion/Transicion.h"
#include "../Alfabeto/Alfabeto.h"


struct Dato {
  bool correcto;
  std::string fichero;
};

/**
 * @brief Estructura para almacenar los parámetros del APv
 * @param estado_inicial Estado inicial del autómata
 * @param estados Alfabeto de estados
 * @param alfabeto_entrada Alfabeto de entrada
 * @param alfabeto_cinta Alfabeto de cinta
 * @param transiciones Map de transiciones
 */
struct parametros_MT {
  std::string estado_inicial;
  Alfabeto alfabeto_estados;
  Alfabeto alfabeto_entrada;
  Alfabeto alfabeto_cinta;
  Alfabeto estados_finales;
  char simbolo_blanco;
  std::multimap<std::string, Transicion> transiciones;
};

Dato recoger_parametro(int argc, char *argv[]);
void mostrar_ayuda();
void mostrar_ayuda_resumida();
void menu();
void mostrar_ayuda_menu();

parametros_MT leer_fichero(const std::string& nombre_fichero);
std::istringstream siguiente_linea_valida(std::ifstream& archivo);
#endif