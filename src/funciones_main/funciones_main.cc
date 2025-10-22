// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: CC
// Curso: 3º
// Práctica 02 : Maquina_turing
// Autor: javier Gómez Alayón
// Correo: alu0101562445@ull.edu.es
// Fecha: 10/20/25
// Archivo funciones_main.cc: Implementación de las funciones del main
//        En este fichero se implementa las funciones utilizadas en el main
//
// Historial de revisiones
//        10/20/25 - Creación (primera versión) del código

#include"funciones_main.h"

/**
 * @brief Recoge los parámetros que se han enviado por linea del comando. Comprobando si los parámetros son correctos.
 * @param numero_argumentos 
 * @param argv 
 * @return retorna un booleano que indica si se ha recogido correctamente los parámetros (true si es correcto, false si no)
 */
Dato recoger_parametro(int numero_argumentos, char *argv[]) {
  Dato datos;
  const std::string kHelp = "--help";
  const std::string kH = "-h";
  switch (numero_argumentos) {
    case 1:
      std::cerr << "Error: No se han introducido los argumentos necesarios" << std::endl;
      mostrar_ayuda_resumida();
      datos.correcto = false;
      return datos;
    case 2:
      if (argv[1] == kHelp || argv[1] == kH) {
        mostrar_ayuda();
        datos.correcto = true;
      } else {
        datos.fichero = argv[1];
        datos.correcto = true;
      }
      return datos;
    default:
      datos.correcto = false;
      return datos;
  }
}
/**
 * @brief Muestra una ayuda detallada del programa
 */
void mostrar_ayuda() {
  std::cout << "\nEste programa se encarga de realizar la simulación de una máquina de turing" << std::endl;
  std::cout << "El programa recibe como argumento la dirección relativa + el nombre del fichero que contiene los parámetros necesarios para instanciar la MT" << std::endl;
  std::cout << "Usage: ./Maquina_turing path/fichero " << std::endl;
  std::cout << "Para más información consulte el README.md" << std::endl;
}

/**
 * @brief Muestra una ayuda resumida del programa
 */
void mostrar_ayuda_resumida() {
  std::cout << "\nUsage: ./Maquina_turing path/fichero.txt" << std::endl;
  std::cout << "Usa el parámetro -h para más información" << std::endl;
}

/**
 * @brief Muestra las opciones del menú
 */
void mostrar_ayuda_menu() {
  std::cout << "Introduce una de las siguientes opciones: " << std::endl;
  std::cout << "0. Salir" << std::endl;
  std::cout << "1. Mostrar ayuda" << std::endl;
  std::cout << "2. indicar nodo inicial y nodo final" << std::endl;
}

/**
 * @brief implementación del menú del programa
 */
void menu() { 
  mostrar_ayuda_menu();
  int opcion;
  while (true) {
    std::cout << std::endl;
    std::cout << "Introduzca una opción: ";
    std::cin >> opcion;
    switch (opcion) {
      case 1:
        mostrar_ayuda_menu();
        break;
      case 0:
        return;
        break;
      default:
        throw std::invalid_argument("Error: Opción no válida");
        break;
    }
  }
}


/**
 * @brief Lee el fichero y devuelve un struct con los parámetros del APv
 * @param nombre_fichero 
 * @return struct con los parámetros del APv
*/
parametros_MT leer_fichero(const std::string& nombre_fichero) {
  parametros_MT parametros;
  std::ifstream archivo(nombre_fichero);
  if (!archivo.is_open()) {
    throw std::invalid_argument("Error: No se pudo abrir el archivo " + nombre_fichero);
  }
  std::istringstream linea_stream;
  // Leer el alfabeto de estados
  linea_stream = siguiente_linea_valida(archivo);
  std::string estado;
  while (linea_stream >> estado) {
    if (estado.empty()) {
      throw std::invalid_argument("Error: El alfabeto de estados no puede contener estados vacíos");
    } else if (parametros.alfabeto_estados.In(estado)) {
      throw std::invalid_argument("Error: El alfabeto de estados no puede contener estados repetidos");
    }
    parametros.alfabeto_estados.Insert(estado);
  }

  // Leer el alfabeto de entrada
  linea_stream = siguiente_linea_valida(archivo);
  std::string simbolo_entrada;
  while (linea_stream >> simbolo_entrada) {
    if (simbolo_entrada.empty()) {
      throw std::invalid_argument("Error: El alfabeto de entrada no puede contener símbolos vacíos");
    } else if (parametros.alfabeto_entrada.In(simbolo_entrada)) {
      throw std::invalid_argument("Error: El alfabeto de entrada no puede contener símbolos repetidos");
    }
    parametros.alfabeto_entrada.Insert(simbolo_entrada);
  }

  // Leer el alfabeto de cinta (tiene que tener todos los símbolos del alfabeto de entrada)
  // para eso hago una función en el alfabeto para que saque en un vector todos los símbolos y después compruebo con AllIn
  linea_stream = siguiente_linea_valida(archivo);
  std::string simbolo_cinta;
  while (linea_stream >> simbolo_cinta) {
    if (simbolo_cinta.empty()) {
      throw std::invalid_argument("Error: El alfabeto de cinta no puede contener símbolos vacíos");
    } else if (parametros.alfabeto_cinta.In(simbolo_cinta)) {
      throw std::invalid_argument("Error: El alfabeto de cinta no puede contener símbolos repetidos");
    }
    parametros.alfabeto_cinta.Insert(simbolo_cinta);
  }
  // si el alfabeto de cinta no contiene todos los símbolos del alfabeto de entrada
  if (!parametros.alfabeto_cinta.AllIn(parametros.alfabeto_entrada.GetSimbolos())) {
    throw std::invalid_argument("Error: El alfabeto de cinta debe contener todos los símbolos del alfabeto de entrada");
  }

  // Leer el estado inicial
  linea_stream = siguiente_linea_valida(archivo);
  linea_stream >> parametros.estado_inicial;
  if (!parametros.alfabeto_estados.In(parametros.estado_inicial)) {
    throw std::invalid_argument("Error: El estado inicial no pertenece al alfabeto de estados");
  }

  // Leer el símbolo blanco de la cinta
  linea_stream = siguiente_linea_valida(archivo);
  linea_stream >> parametros.simbolo_blanco;
  if (!parametros.alfabeto_cinta.In(parametros.simbolo_blanco)) {
    throw std::invalid_argument("Error: El símbolo blanco " + std::string(1, parametros.simbolo_blanco) + " no pertenece al alfabeto de cinta");
  }
  // Leer Conjunto de estados finales
  linea_stream = siguiente_linea_valida(archivo);
  std::string estado_final;
  while (linea_stream >> estado_final) {
    if (!parametros.alfabeto_estados.In(estado_final)) {
      throw std::invalid_argument("Error: El estado final " + estado_final + " no pertenece al alfabeto de estados");
    }
    parametros.estados_finales.Insert(estado_final);
  }

  // Hago el Alfabeto de los movimientos de la cinta
  Alfabeto alfabeto_movimientos;
  alfabeto_movimientos.Insert("L");
  alfabeto_movimientos.Insert("R");
  alfabeto_movimientos.Insert("S");

  // Leer las transiciones
  std::string estado_origen, estado_destino;
  char simbolo_entrada_t, simbolo_escrito_t, movimiento_t;
  int id = 0;
  while (true) {
    linea_stream = siguiente_linea_valida(archivo);
    if (linea_stream.str().empty()) {
      break; // si está vacía, significa que no hay más líneas que leer
    } else {
      linea_stream >> estado_origen >> simbolo_entrada_t >> estado_destino >> simbolo_escrito_t >> movimiento_t;
      if (!parametros.alfabeto_estados.In(estado_origen)) {
        throw std::invalid_argument("Error: El estado de origen " + estado_origen + " no pertenece al alfabeto de estados");
      }
      if (!parametros.alfabeto_estados.In(estado_destino)) {
        throw std::invalid_argument("Error: El estado de destino " + estado_destino + " no pertenece al alfabeto de estados");
      }
      if (!parametros.alfabeto_cinta.In(simbolo_entrada_t)) {
        throw std::invalid_argument("Error: El símbolo de entrada " + std::string(1, simbolo_entrada_t) + " no pertenece al alfabeto de entrada");
      }
      if (!parametros.alfabeto_cinta.In(simbolo_escrito_t)) {
        throw std::invalid_argument("Error: El símbolo de cinta " + std::string(1, simbolo_escrito_t) + " no pertenece al alfabeto de cinta");
      }
      if (!alfabeto_movimientos.In(movimiento_t)) {
        throw std::invalid_argument("Error: La inserción en la cinta " + std::string(1, movimiento_t) + " contiene símbolos que no pertenecen al alfabeto de cinta");
      }
      parametros.transiciones.emplace(estado_origen, Transicion(simbolo_entrada_t, estado_destino, simbolo_escrito_t, movimiento_t, id++));
    }
  }
  archivo.close();
  return parametros;
}

std::istringstream siguiente_linea_valida(std::ifstream& archivo) {
  std::string linea;
  while (std::getline(archivo, linea)) {
    if (linea.empty() || linea[0] == '#') {
      continue; // Saltar líneas vacías o comentarios
    } else {
      return std::istringstream(linea); // Devolver la primera línea válida
    }
  }
  return std::istringstream(); // Devolver un istringstream vacío si no hay líneas válidas
}


