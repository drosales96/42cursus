A continuación habrá explicaciones y contexto de las funciones que participan en la impresión de las columnas y colores del mapa.

## ft_walls_color()

Descripción: Esta función se encarga de seleccionar el color de la pared que un rayo ha impactado, basándose en la dirección del rayo y el tipo de pared.

Dependiendo de la dirección del rayo, la función decide qué textura usar (este, oeste, norte, sur). Se basa en los valores proporcionados por la estructura t_ray.

Parámetros:

    t_cub3d *cub: Un puntero a la estructura principal del juego, que contiene los datos de las texturas de las paredes (este, oeste, norte, sur).

    t_ray *ray: Un puntero a la estructura que representa el rayo que se está procesando.

    Contiene información sobre la dirección del rayo y el punto de impacto en el mapa.

    double size: La fracción de la pared que debe ser mapeada a la textura (determinada por el tamaño de la pared en la pantalla).

Explicación del Código:

    Se comprueba la dirección del rayo mediante ray->flag (0 para este/oeste y 1 para norte/sur).
    
    Dependiendo de si ray->ray_x o ray->ray_y es positivo o negativo, se selecciona la textura correspondiente (por ejemplo, si el rayo va hacia la derecha, se usa la textura del este).

    Se calcula la fracción de la distancia que el rayo ha recorrido dentro de la pared, usando la parte decimal de ray->ray_hit_in_map_dist (esto es lo que se pasa como x a la función ft_get_the_colors).

    La función devuelve un color obtenido de la textura de la pared.

Tipo de dato uint32_t:

    uint32_t es un tipo de dato sin signo de 32 bits que se utiliza para almacenar valores de color en formato RGBA (rojo, verde, azul, alfa). 

    En esta función, c es un color de 32 bits, donde cada byte representa uno de los componentes de color.

## ft_wallsize()

Descripción: Esta función calcula el tamaño de la pared proyectada en la pantalla, basado en la distancia del rayo. Es utilizada para determinar cómo se deben escalar las texturas de las paredes en la pantalla.

Parámetros:

    t_ray *ray: Un puntero a la estructura t_ray, que contiene la información sobre las distancias de los rayos y sus respectivos viajes verticales.

Explicación del Código:

    Compara dos valores: ray->ray_hypoteneuse_dist (la distancia total del rayo) y ray->vertical_ray_travel (la distancia en la dirección vertical).

    Devuelve un valor size, que es la proporción de la pared que debe ser representada en la pantalla. Este valor es utilizado más adelante para escalar la textura correctamente.

Uso de double:

    El tipo double se utiliza para representar números con decimales, ya que las distancias de los rayos pueden tener valores no enteros. Esto es importante para obtener precisión al calcular el tamaño de la pared en la pantalla.

## ft_painting_col()

Descripción: Esta función pinta una columna de la pared en la pantalla, usando la textura correspondiente a la pared y calculando su tamaño y color.

Parámetros:

    t_cub3d *cub: Puntero a la estructura principal del juego, que contiene las texturas de las paredes.

    t_ray *ray: Puntero a la estructura que contiene la información sobre el rayo (distancias, ángulos, etc.).

    int c: La posición horizontal de la columna en la pantalla (en la ventana de visualización).

Explicación del Código:

    La función calcula el tamaño de la pared proyectada en la pantalla usando la función ft_wallsize().

    Calcula el primer píxel de la pared que se debe dibujar, teniendo en cuenta la distancia del rayo.

    Luego, recorre cada fila vertical de la pared que debe pintarse y calcula el color correspondiente utilizando la función ft_walls_colors().

    La función mlx_put_pixel() se encarga de dibujar cada píxel de la pared en la pantalla.

Uso de uint32_t:

    El color de cada píxel de la pared se representa como un valor uint32_t, donde cada byte contiene uno de los componentes de color RGBA (rojo, verde, azul, alfa). 
    
    Este valor es utilizado por mlx_put_pixel() para pintar la pantalla.

## ft_rgba()

Descripción: Esta función convierte un array de 4 bytes (RGBA) en un valor de color de 32 bits (uint32_t). Los bytes representan los componentes de color de la imagen (rojo, verde, azul y alfa).

Parámetros:

    uint8_t pixel[4]: Un array de 4 bytes que representa los componentes RGBA del color (rojo, verde, azul, alfa).

Explicación del Código:

    La función toma los 4 valores de color (rojo, verde, azul y alfa) de pixel y los coloca en un único valor uint32_t utilizando el operador de desplazamiento de bits (<<). 
    
    Esto empuja los valores de cada componente a la posición correcta dentro del entero de 32 bits.

Uso de uint32_t:

    El tipo uint32_t es utilizado para almacenar el color en formato RGBA como un valor entero de 32 bits. Cada componente (rojo, verde, azul y alfa) ocupa un byte (8 bits), lo que da un total de 32 bits para representar el color.

## ft_get_the_colors()

Descripción: Esta función obtiene el color de un píxel específico de una textura de pared en función de la posición x (distancia recorrida dentro de la textura) y el tamaño de la pared (size).

Parámetros:

    double x: La posición horizontal dentro de la textura, calculada como la fracción de la distancia recorrida por el rayo.
    
    double size: El tamaño de la pared proyectada en la pantalla (calculado anteriormente).

    mlx_texture_t *texture: Un puntero a la estructura de la textura de la pared (que contiene los píxeles de la imagen).

Explicación del Código:

    La función calcula el índice de píxel correspondiente en la textura usando x y size.

    Luego, obtiene los valores RGBA de ese píxel y los pasa a la función ft_rgba(), que devuelve un valor uint32_t con el color.

    Si los valores x o size son inválidos (por ejemplo, mayores o iguales a 1), la función retorna 0, que es un color negro.

Uso de uint32_t:

    El color devuelto es de tipo uint32_t, que se utiliza para representar colores en el formato RGBA (32 bits: 8 bits para cada componente de color).