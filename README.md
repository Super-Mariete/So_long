# So Long - 42 Project

Un pequeño videojuego 2D desarrollado en C utilizando la librería gráfica **MiniLibX**. El objetivo es recoger todos los objetos del mapa y llegar a la salida en el menor número de movimientos posible.

## Requisitos

- Un compilador de C (`gcc` o `clang`).
- Librerías de desarrollo de X11 (si usas Linux).
- MiniLibX instalada en el directorio del proyecto.

## Instalación y Ejecución

1. Clona la **libft** de GitHub dentro de la raíz del proyecto:
   ```bash
   git clone https://github.com/tu-usuario/libft.git libft
   ```

2. Compila el proyecto con el Makefile:
   ```bash
   make
   ```

3. Ejecuta el juego pasando un mapa como argumento:
   ```bash
   ./so_long maps/valid.ber
   ```

## Controles

| Tecla | Acción |
| :--- | :--- |
| **W** | Mover hacia arriba |
| **A** | Mover hacia la izquierda |
| **S** | Mover hacia abajo |
| **D** | Mover hacia la derecha |
| **ESC** | Cerrar el juego |

## Formato del Mapa
El archivo `.ber` debe estar compuesto por:
- `1` para muros.
- `0` para espacios vacíos.
- `P` para la posición inicial del jugador.
- `C` para coleccionables.
- `E` para la salida.