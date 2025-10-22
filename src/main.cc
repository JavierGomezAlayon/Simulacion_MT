// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: CC
// Curso: 3º
// Práctica 02 : Maquina_turing
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 10/20/25
// Archivo main.cc: Implementación del programa cliente
//        En este fichero se implementa la función del main
//
// Historial de revisiones
//        10/20/25 - Creación (primera versión) del código
#include"funciones_main/funciones_main.h"
#include"MT/MT.h"
#include<iostream>

int main(int argc, char *argv[]) {
  const std::string exit_string = "0";
  //Compruebo si se han introducido los argumentos necesarios
  Dato datos = recoger_parametro(argc, argv);
  if (datos.correcto == false) {
    std::cerr << "Error no se han introducido los datos correctamente" << std::endl;
    return 1;
  }
  try {
    // leo los datos del fichero
    parametros_MT parametros = leer_fichero(datos.fichero);
    // creo la máquina de Turing
    MT Maquina_turing(parametros);
    // empiezo el menú.
    std::string cadena;
    std::cout << "Introduzca la cadena a evaluar (o '0' para salir): ";
    while (std::cin >> cadena) {
      if (cadena == exit_string) {
        break;
      } else {
        if (Maquina_turing.procesar_cadena(cadena)) {
          std::cout << "Cadena aceptada" << std::endl;
        } else {
          std::cout << "Cadena no aceptada" << std::endl;
        }
        Maquina_turing.reset();
        std::cout << "Introduzca la cadena a evaluar (o '0' para salir): ";
      }
    }
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }
  return 0;
}