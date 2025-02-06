# Documentación del Código: Funciones de Inicialización de CUBED

Este archivo contiene las explicaciones de las funciones relacionadas con la inicialización de las variables y estructuras utilizadas en el proyecto CUBED. Cada función está diseñada para configurar ciertas partes de la estructura `t_cub3d`, que es el corazón de nuestro programa.

## `ft_init_coord_flags`

Esta función inicializa las banderas asociadas a las texturas del juego. Las banderas se usan para determinar si una textura está correctamente cargada o no. Se configuran todas las banderas como `0` (sin texturas cargadas).

### Propósito:
Inicializar las banderas de texturas en la estructura `textures` dentro de `t_cub3d`.

### Explicación:
- **`sky_flag`**: Bandera para la textura del cielo.
- **`floor_flag`**: Bandera para la textura del suelo.
- **`north_flag`, `south_flag`, `west_flag`, `east_flag`**: Banderas para las texturas de las paredes de las direcciones correspondientes.

---

## `ft_init_player`

Esta función inicializa las coordenadas y los parámetros del jugador en el mapa del juego. La posición y el ángulo iniciales del jugador son establecidos a valores predeterminados.

### Propósito:
Establecer las posiciones iniciales del jugador en el mapa y su ángulo de visión.

### Explicación:
- **`x_map` y `y_map`**: Coordenadas en el mapa donde el jugador se encuentra inicialmente.
- **`x_player_pos` y `y_player_pos`**: Coordenadas exactas de la posición del jugador en el juego.
- **`angle`**: Ángulo inicial de visión del jugador.

---

## `ft_init_textures`

Esta función inicializa las texturas y las rutas de las mismas, así como los colores del cielo y el suelo. Llama a `ft_init_coord_flags` para asegurarse de que las banderas de textura estén correctamente configuradas.

### Propósito:
Inicializar las texturas y sus rutas, asegurándose de que todas las variables estén listas para ser usadas en la carga de las texturas.

### Explicación:
- **`north_text`, `south_text`, `west_text`, `east_text`**: Punteros a las texturas correspondientes a las direcciones.
- **`north_path`, `south_path`, `west_path`, `east_path`**: Rutas a las imágenes de texturas para cada dirección.
- **`sky_color`, `floor_color`**: Colores para el cielo y el suelo si las texturas no se cargan correctamente.

---

## `ft_setup`

Esta función configura toda la estructura `t_cub3d` inicializando las texturas, las coordenadas del jugador, los mapas, y otros parámetros importantes. Llama a `ft_init_textures` y `ft_init_player` para asegurarse de que todas las variables estén correctamente configuradas.

### Propósito:
Realizar la configuración inicial de todas las variables de la estructura `t_cub3d`.

### Explicación:
- **`mlx`**: Puntero a la librería de gráficos (MLX).
- **`file`**: Puntero a un archivo (probablemente el mapa o configuración).
- **`map.map`**: El mapa del juego, que inicialmente está vacío.
- **`map.line_map`**: El número de líneas en el mapa.
- **`map.x_map` y `map.y_map`**: Las dimensiones del mapa en el juego.
- **`background` y `walls`**: Punteros a las imágenes del fondo y las paredes.
- **`move`**: Variable para manejar el movimiento del jugador.
- **`ray_number`**: Número de rayos que se calculan durante la ejecución (para la simulación de la visión del jugador).

---

## `ft_init_walls`

Esta función inicializa las paredes del juego creando una nueva imagen con dimensiones predefinidas (ancho y alto) usando la librería MLX. Si hay un error en la creación de la imagen o al mostrarla en la ventana, se produce un error y se termina la ejecución del programa.

### Propósito:
Inicializar las paredes del juego y mostrarlas en la ventana de la aplicación.

### Explicación:
- **`mlx_new_image`**: Crea una nueva imagen con las dimensiones especificadas.
- **`mlx_image_to_window`**: Coloca la imagen creada en la ventana de la aplicación.
- Si cualquiera de estos pasos falla, se imprime un mensaje de error y el programa se detiene.

---

## Conclusión

Las funciones descritas arriba son esenciales para la configuración inicial del juego CUBED. Aseguran que las texturas, el jugador, las paredes y otros parámetros importantes estén listos para su uso en la simulación de un entorno 3D basado en raycasting.
