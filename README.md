Simulador de Mundos - Etapa 1

Integrantes:
Guillen Trejos Dana
Arias González Raúl
Vergara Valverde Gipzy

Curso: Programación I
Profesor: Jorge Arturo Villalobos Madrigal
Universidad: Universidad Nacional

De qué trata el proyecto:
Esta es la primera parte de nuestro simulador de mundos vivos usando autómatas celulares multiespecie. El programa trabaja sobre una cuadrícula de celdas que van cambiando generación tras generación. Dependiendo de cuántos vecinos tengan alrededor, usando la vecindad de Moore de 8 celdas, las especies nacen, se mantienen vivas o mueren en un tablero con bordes cerrados.

Configuraciones que incluye:
De acuerdo a lo asignado, el código soporta las siguientes reglas:
Toroide: Funciona con 3 especies y la regla de nacimiento se activa con 3 vecinos.
Cruz: Trabaja con 4 especies y la regla de nacimiento se activa con 2 o 3 vecinos.
Desempate: Si hay empate de vecinos para que nazca una especie, el sistema decide cuál entra usando el índice asignado.

Cómo está organizado el código:
El proyecto está escrito en C++ orientado a objetos. El manejo de datos se hizo de forma manual con punteros dobles y memoria dinámica, sin usar librerías automáticas como lo que son las std::vector:
SpeciesConfig y Header: Guarda la información de las especies, reglas de nacimiento y supervivencia.
World: Maneja la matriz del tablero, cuenta los 8 vecinos alrededor de cada casilla y aplica los cambios entre generaciones.
ConsoleUI y Main: Controla la interfaz de la pantalla negra de consola, los menús y la siembra inicial del tablero.
