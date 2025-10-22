# Simulador de Máquina de Turing (MT)

Este proyecto implementa un simulador de una Máquina de Turing (MT) que se define a través de un archivo de configuración externo.
Esta máquina de turing tiene: 
- Escritura y movimientos simultáneos.
- Incluye la posibilidad de no moverse(S).
- La cinta infinita en ambas direcciones.

## Compilación

Para la compilación se ha elegido la utilización de make para dar una mayor facilidad al usuario.
Para realizar dicha acción póngase en el directorio principal y ejecute el siguiente comando:

```bash
make
```

## Directorio de configuración de la MT

Como norma general el archivo de configuración de la MT deberá estar en el directorio "data", aunque la posición del archivo puede ser modificado si se prefiere, siempre y cuando se siga las indicaciones de la ejecución del programa correctamente.

## Inputs y ejecución del programa

Suponiendo que está en el directorio principal:
Para ejecutar el programa tendrá que especificar el archivo de configuración de la máquina de Turing, de la siguiente forma:

```bash
./Maquina_turing path/fichero.txt
```

Siendo "path" el camino desde tu pwd hasta la localización del archivo de configuración
y siendo "fichero.txt" el nombre del archivo de configuración de la máquina de Turing.

## Formato del fichero de configuración

El fichero de configuración debe seguir el siguiente formato:

```
# Comentarios
q1 q2 q3 … # conjunto Q
a1 a2 a3 … # conjunto Σ
A1 A2 A3 … # conjunto Γ
q1 # estado inicial
b # símbolo blanco
q2 q3 # conjunto F
q1 a1 q2 a2 m # función de transición : δ (q1, a1) = (q2, a2, m)
... # cada una de las transiciones en una línea distinta
```

Los comentarios pueden ser puestos en cualquier línea del fichero siempre que estén precedidos por el símbolo #.

## Ejemplo

Estando en el directorio principal se puede ejecutar una prueba del programa con el siguiente comando:

```bash
./Maquina_turing data/Ejemplo_MT.txt
```