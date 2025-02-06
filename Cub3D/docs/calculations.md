# Calculations

Aquí tendremos la info necesaria para entender funciones que incluye ft_callback() que son una fumada increíble.

## ft_valid_movement

Descripción: La función ft_valid_movement se encarga de verificar si el jugador puede moverse a una nueva posición en el mapa sin chocar con ninguna pared. Utiliza las posiciones actuales del jugador y calcula si las celdas alrededor de la nueva posición están libres de obstáculos. Si alguna de las celdas está ocupada por una pared ('1'), devuelve false, indicando que el movimiento no es válido.

Funcionamiento:

    La función toma las coordenadas actuales del jugador (x_player_pos y y_player_pos), y calcula las nuevas posiciones a donde el jugador intentaría moverse, teniendo en cuenta un pequeño margen (sumando y restando 0.25 unidades).

    Luego, verifica las celdas adyacentes en el mapa en esas nuevas posiciones (alrededor del jugador) y comprueba si están ocupadas por una pared ('1').

    Si alguna de las posiciones verificadas está ocupada por una pared, el movimiento es inválido y la función retorna false.

    Si no hay obstáculos, el movimiento es válido y la función retorna true.

Retorno:

    true: Si el movimiento es válido.
    false: Si el movimiento colisiona con una pared.

## ft_check_next_step

Descripción: La función ft_check_next_step verifica si el jugador puede dar un paso hacia la nueva posición determinada por los movimientos en los ejes x y y. Utiliza la función ft_valid_movement para validar si el jugador puede moverse a la nueva posición sin chocar con una pared.

Funcionamiento:

    La función llama a ft_valid_movement para verificar si el jugador puede moverse en las direcciones x y y especificadas (es decir, se mueve en el eje x y el eje y por separado).

    Si ft_valid_movement retorna true, actualiza las coordenadas del jugador (x_map y y_map) sumando las distancias de movimiento a las posiciones actuales del jugador.

    Si el movimiento es válido, retorna true, lo que indica que el jugador puede avanzar a la siguiente celda en el mapa.

    Si el movimiento no es válido, retorna false.

Retorno:

    true: Si el paso siguiente es válido y el jugador puede moverse.
    false: Si el movimiento colisiona con una pared.

## ft_movement

Descripción: La función ft_movement gestiona el movimiento del jugador en el mapa, calculando la nueva posición en los ejes x y y basándose en el ángulo de dirección del jugador.

Funcionamiento:

    Primero, calcula las distancias a mover en el eje x y y utilizando las funciones trigonométricas coseno y seno. El ángulo de movimiento del jugador es pasado como parámetro, y las distancias se ajustan por el valor de cub->move, que representa la velocidad de movimiento.

    Luego, la función verifica si el jugador puede moverse en el eje y llamando a ft_check_next_step con un movimiento de y (sin mover en x). 
    
    Si el movimiento es válido, la posición en y se actualiza.

    De manera similar, verifica si el jugador puede moverse en el eje x llamando a ft_check_next_step con un movimiento de x (sin mover en y). 
    
    Si el movimiento es válido, la posición en x se actualiza.

Retorno:

    No tiene valor de retorno. Esta función actualiza las posiciones del jugador directamente si el movimiento es válido.

## ft_moves

Descripción: La función ft_moves gestiona las entradas de teclado que permiten mover al jugador en el mapa. Comprueba si el jugador está presionando las teclas correspondientes a los movimientos hacia adelante, atrás, izquierda, derecha y un cambio en la velocidad.

Funcionamiento:

    Utiliza la función mlx_is_key_down para detectar si una de las teclas definidas para el movimiento (W, S, A, D) está siendo presionada.

        Si se presiona W: el jugador se mueve hacia adelante según el ángulo actual.

        Si se presiona S: el jugador se mueve hacia atrás (se mueve en la dirección opuesta al ángulo actual).

        Si se presiona A: el jugador se mueve hacia la izquierda (rotación de -90 grados respecto al ángulo actual).

        Si se presiona D: el jugador se mueve hacia la derecha (rotación de +90 grados respecto al ángulo actual).

    Si la tecla E es presionada, la velocidad de movimiento se ajusta a 12. De lo contrario, la velocidad de movimiento se restablece a 4.

Retorno:

    No tiene valor de retorno. Esta función actualiza las posiciones del jugador en base a las teclas presionadas.

## ft_rotation

Descripción: La función ft_rotation gestiona la rotación del jugador, permitiéndole girar a la izquierda o a la derecha en el mapa. Detecta las teclas presionadas (izquierda y derecha) y ajusta el ángulo de visión del jugador en consecuencia.

Funcionamiento:

    Utiliza la función mlx_is_key_down para comprobar si el jugador está presionando las teclas izquierda o derecha.

    Si la tecla izquierda (flecha izquierda o la tecla asignada para girar a la izquierda) está presionada, se llama a ft_angles_checker con un valor negativo de -3, lo que hace que el ángulo del jugador disminuya en 3 grados (es decir, gira a la izquierda).

    Si la tecla derecha (flecha derecha o la tecla asignada para girar a la derecha) está presionada, se llama a ft_angles_checker con un valor positivo de 3, lo que hace que el ángulo del jugador aumente en 3 grados (es decir, gira a la derecha).

Retorno:

    No tiene valor de retorno. Esta función simplemente actualiza el ángulo del jugador si las teclas de rotación son presionadas.

## ft_angles_checker

Descripción: La función ft_angles_checker se encarga de ajustar un ángulo para asegurarse de que siempre esté dentro del rango de 0° a 360°. Esta función es útil para mantener los ángulos de rotación del jugador dentro de un rango válido, evitando valores fuera de este rango que podrían generar comportamientos inesperados.

Funcionamiento:

    La función toma un puntero al ángulo (probablemente el ángulo de visión o dirección del jugador) y un valor i que indica la cantidad en la que el ángulo debe ser ajustado (positivo o negativo).

    Se suma i al ángulo actual. Si el ángulo resulta ser mayor o igual a 360°, se le resta 360° para devolverlo dentro del rango.

    Si el ángulo es menor a 0°, se le suma 360° para asegurar que siempre esté dentro del intervalo [0°, 360°).

Retorno:

    No tiene valor de retorno, ya que se pasa el ángulo por referencia y se modifica directamente.

## ft_raycasting

Descripción: La función ft_raycasting es responsable de realizar el proceso de raycasting para generar la visión 3D del jugador. Para cada columna de la pantalla (de 0 a WIDTH), se dispara un rayo desde la posición del jugador y se calcula el impacto con las paredes del mapa. Después de obtener los datos de impacto, la función también se encarga de "pintar" la columna correspondiente en la pantalla.

Funcionamiento detallado:

    Inicialización del raycasting: Se llama a ft_ray_init(cub), que prepara todos los rayos que se utilizarán para cada columna de la pantalla.
    Raycasting por cada columna: Se inicia un bucle que recorre cada píxel de la pantalla (de 0 a WIDTH) y, para cada índice i:
        Se llama a ft_ray_impact(cub, &player->ray[i]) para calcular el impacto del rayo en el mapa. Esto incluye el cálculo de las distancias y la ubicación del impacto.
        Después, se llama a ft_painting_col(cub, &player->ray[i], i) para dibujar la columna correspondiente en la pantalla en base al impacto del rayo calculado.
    Este proceso se repite para cada columna, creando la imagen 3D del entorno visto por el jugador.

Retorno:

    No tiene valor de retorno. Su propósito es actualizar el estado de los rayos y dibujar la escena en pantalla.

Ahora iremos una por una:

### ft_ray_init

Descripción: La función ft_ray_init inicializa los rayos para el raycasting, es decir, establece el ángulo de visión de cada rayo según el ángulo de la cámara del jugador y el campo de visión (FOV). Para cada columna de la pantalla, se calcula el ángulo específico del rayo y se prepara para su impacto.

Funcionamiento detallado:

    Campo de visión (FOV): Se define el campo de visión del jugador. El valor de FOV se convierte a radianes utilizando FOV * M_PI / 180. Esto se hace porque las funciones trigonométricas trabajan con radianes.

    Ángulo del jugador: El ángulo de la cámara del jugador se convierte a radianes utilizando cub->player.angle * M_PI / 180.

    Cálculo del ángulo de cada rayo:

        Para cada columna de la pantalla, el ángulo del rayo se ajusta según su posición en la pantalla. El ángulo se establece de forma que los rayos cubran todo el campo de visión del jugador, desde el ángulo izquierdo hasta el ángulo derecho.

        angle - (fov / 2): El primer rayo se genera en el ángulo más a la izquierda.

        (fov / WIDTH) * i: Cada rayo siguiente tiene un pequeño incremento en su ángulo, dependiendo de la columna en la que se encuentre.

        Si el ángulo del rayo es negativo, se ajusta sumándole 2 * M_PI para que se mantenga dentro de un rango válido de [0, 2π).

Retorno:

    No tiene valor de retorno. Su objetivo es calcular y almacenar los ángulos de los rayos.

### ft_ray_impact

Descripción: La función ft_ray_impact calcula el impacto de un rayo en el mapa. Esto incluye varios pasos complejos: 

Inicialización de valores del rayo, cálculo de distancias entre el jugador y la pared, y la determinación de la pared que el rayo golpea primero.

Funcionamiento detallado:

    Inicialización de valores del rayo: Se llama a ft_init_ray_values(cub, ray) para establecer los valores iniciales del rayo, como la dirección del rayo, las distancias, etc.

    Cálculo de distancias: Se llama a ft_dist_player_to_wall(cub, ray) para calcular la distancia inicial entre el jugador y las paredes del mapa.

    Búsqueda de la pared: La función ft_wall_finder(cub, ray) se encarga de encontrar la pared más cercana que el rayo golpea, calculando en qué dirección se mueve el rayo (horizontal o vertical) y actualizando la distancia de impacto.

    Cálculo de la distancia del impacto:

        Si el rayo se mueve verticalmente (es decir, se mueve a lo largo de las líneas del eje y), se calcula la distancia entre el jugador y el impacto de la pared en el mapa mediante ray->ray_hit_in_map_dist = ray->y_player_pos + (ray->wall_ray_hit_dist * ray->ray_y).

        Si el rayo se mueve horizontalmente, la distancia se calcula de manera similar pero en el eje x.

    Impacto vertical u horizontal:

        Se determina si el rayo ha golpeado una pared vertical o horizontal, y se llama a las funciones correspondientes (ft_vertical_impact(ray) o ft_horizontal_impact(ray)) para calcular el impacto específico.

    Hipotenusa: Se calcula la distancia total del impacto utilizando ft_hypo(ray), que probablemente usa el teorema de Pitágoras para calcular la distancia diagonal si el rayo no se mueve exclusivamente a lo largo de uno de los ejes.

    Determinación de la columna de impacto: Se calcula la columna donde se debe pintar el rayo en la pantalla utilizando la función ft_vert(cub, ray).

Retorno:

    No tiene valor de retorno. Su propósito es calcular y almacenar los detalles sobre el impacto del rayo, que luego serán utilizados para dibujar la escena.

A continuación iré añadiendo explicaciones sobre las funciones que se encuentran dentro de ft_ray_impact y que son MUY importantes:

#### ft_init_ray_values

Descripción: Esta función inicializa los valores necesarios para el raycasting de cada rayo. Establece la dirección del rayo, las posiciones del jugador, y las distancias necesarias para el cálculo del impacto en las paredes.

Funcionamiento detallado:

    Posición inicial: La posición inicial del rayo (en las coordenadas del mapa y la posición del jugador) se obtiene directamente de las posiciones del jugador, como cub->player.x_map y cub->player.y_map.

    Dirección del rayo: Se calcula la dirección del rayo usando cos(ray->angle) para obtener la componente X y sin(ray->angle) para obtener la componente Y del vector de dirección del rayo.

    Distancias para cruzar celdas: Se calculan las distancias que el rayo necesita para cruzar las celdas del mapa, usando 1 / fabs(ray->ray_x) y 1 / fabs(ray->ray_y). Estas distancias son esenciales para determinar la rapidez con que el rayo avanza a través del mapa.

    Dirección del movimiento:

        Si la componente X es negativa (rayo se mueve hacia la izquierda), se ajusta el valor de ray_move_x a -1.

        Si la componente X es positiva (rayo se mueve hacia la derecha), se ajusta el valor de ray_move_x a 1.

        Similarmente, se ajustan los valores de ray_move_y para el movimiento en la dirección Y.

    Inicialización de la bandera: Se inicializa la variable flag a 0 para indicar que aún no se ha determinado si el rayo ha impactado una pared vertical o horizontal.

Retorno:

    No tiene valor de retorno. Su objetivo es preparar todos los valores del rayo que se utilizarán en los cálculos posteriores.


#### ft_dist_player_to_wall

Descripción: Esta función calcula las distancias iniciales del rayo hasta la pared más cercana, tanto en la dirección X como en la dirección Y.

Funcionamiento detallado:

    Distancia en la dirección X:

        Si el rayo se mueve hacia la derecha (ray->ray_x > 0), se calcula la distancia desde la posición del jugador hasta la celda de la pared en la dirección X.

        Si el rayo se mueve hacia la izquierda (ray->ray_x < 0), se realiza un cálculo similar para la celda de la pared a la izquierda del jugador.

    Distancia en la dirección Y:

        Similar al cálculo de la distancia en X, se calcula la distancia en la dirección Y dependiendo de si el rayo se mueve hacia abajo (ray->ray_y > 0) o hacia arriba (ray->ray_y < 0).

Estas distancias son fundamentales para saber cuánto debe avanzar el rayo antes de impactar con una pared.

Retorno:

    No tiene valor de retorno. Actualiza las variables cell_crossing_dist_x y cell_crossing_dist_y que son utilizadas en el proceso de búsqueda de la pared.

#### ft_wall_finder

Descripción: Esta función se encarga de encontrar la pared más cercana al rayo. A medida que el rayo avanza, se van actualizando las distancias de cruce y se avanza a través del mapa en la dirección correspondiente (horizontal o vertical), hasta que el rayo impacta con una pared.

Funcionamiento detallado:

    Bucle de búsqueda: La función entra en un bucle while (cub->map.map[ray->y_map][ray->x_map] != '1') que sigue ejecutándose mientras el rayo no haya alcanzado una pared (representada por '1' en el mapa).

        Si la distancia de cruce en X es menor que la distancia de cruce en Y, el rayo avanza en la dirección X (horizontal).

            Se incrementa la distancia de cruce en X y se avanza a la siguiente celda en la dirección X.

            La flag se establece a 0 para indicar que el rayo se mueve en dirección horizontal.

        Si la distancia de cruce en Y es menor, el rayo avanza en la dirección Y (vertical).

            Se incrementa la distancia de cruce en Y y se avanza a la siguiente celda en la dirección Y.

            La flag se establece a 1 para indicar que el rayo se mueve en dirección vertical.

    Cálculo de la distancia de impacto:

        Si el rayo se mueve en la dirección X, se calcula la distancia de impacto usando la fórmula:

        ray->wall_ray_hit_dist = (ray->x_map - ray->x_player_pos + (1 - ray->ray_move_x) / 2) / ray->ray_x.

        Si el rayo se mueve en la dirección Y, se calcula la distancia de impacto utilizando la fórmula correspondiente para el eje Y.

Retorno:

    No tiene valor de retorno. Su función es encontrar la pared más cercana e inicializar las distancias de impacto.

#### ft_vertical_impact

Descripción: Esta función calcula la distancia de impacto cuando el rayo golpea una pared vertical. Dependiendo de la dirección del rayo, se determina cómo calcular la distancia del impacto.

Funcionamiento detallado:

    Se verifica la dirección del rayo en X y Y.

    Dependiendo de si el rayo se mueve hacia la derecha o hacia la izquierda, y si se mueve hacia abajo o hacia arriba, se ajusta el cálculo de la distancia de impacto en el eje vertical.

    El cálculo implica multiplicar la distancia hasta la pared por un factor (probablemente relacionado con la resolución de la pantalla o el tamaño de las celdas del mapa).

Retorno:

    No tiene valor de retorno. Modifica wall_visible_height para indicar la altura visible de la pared.

#### ft_horizontal_impact

Descripción: Esta función calcula la distancia de impacto cuando el rayo golpea una pared horizontal. El proceso es similar al de la función ft_vertical_impact, pero en este caso se calcula el impacto en paredes horizontales.

Funcionamiento detallado:

    Se verifica la dirección del rayo en X y Y.

    Dependiendo de si el rayo se mueve hacia la derecha o hacia la izquierda, y si se mueve hacia abajo o hacia arriba, se ajusta el cálculo de la distancia de impacto en el eje horizontal.

    Similar a ft_vertical_impact, el cálculo implica multiplicar la distancia hasta la pared por un factor.

Retorno:

    No tiene valor de retorno. Modifica wall_ray_hit_dist para almacenar la distancia del impacto.

### ft_hypo

Descripción: Esta función calcula la distancia real entre el jugador y el impacto del rayo sobre la pared utilizando el teorema de Pitágoras. 

El cálculo se realiza tomando en cuenta la distancia proyectada en los ejes X y Y, y usa estos valores para obtener la distancia final, que es fundamental para la visualización del raycasting.

Funcionamiento detallado:

El cálculo de la distancia del rayo hasta la pared se hace considerando las coordenadas de la posición del jugador y el punto de impacto en la pared. 

La distancia en línea recta entre estos dos puntos es la hipotenusa del triángulo rectángulo formado por las distancias recorridas en los ejes X y Y.

    Condiciones en función de ray->flag:

        ray->flag == 0: Este caso ocurre cuando el rayo ha impactado una pared vertical.

            Si ray->ray_x > 0, significa que el rayo se está desplazando hacia la derecha, por lo que se utiliza la distancia entre la posición X del jugador y la X del mapa donde ocurrió el impacto, sumando la diferencia en el eje Y.

            Si ray->ray_x < 0, significa que el rayo va hacia la izquierda, entonces se ajusta la posición X añadiendo 1 (ya que el impacto se considera en el borde izquierdo de la celda).

        ray->flag == 1: Este caso ocurre cuando el rayo ha impactado una pared horizontal.

            Si ray->ray_y > 0, el rayo va hacia abajo, y la distancia se calcula usando las diferencias en los ejes Y y X.

            Si ray->ray_y < 0, el rayo va hacia arriba, y se ajusta la posición en el eje Y añadiendo 1 (similar al caso anterior en el eje X).

    Cálculo final: Se usa el teorema de Pitágoras para calcular la distancia real:

    hipotenusa=(xmapa−xjugador)2+(yimpacto−yjugador)2
    hipotenusa=(xmapa​−xjugador​)2+(yimpacto​−yjugador​)2

​
Este valor es crucial para determinar la visualización de las paredes a diferentes distancias del jugador.

### ft_vert

Descripción: Esta función ajusta la distancia del rayo en su componente vertical, que es la distancia medida en el mundo real (no en el mapa de celdas), y se utiliza para calcular la proyección de las paredes en la pantalla del juego. 

La distancia vertical se ajusta para considerar el ángulo del rayo con respecto a la posición del jugador.

Funcionamiento detallado:

    Cálculo del ángulo entre el rayo y el jugador:

        El ángulo se calcula entre la dirección del jugador y la dirección en la que viaja el rayo. Usamos la diferencia entre los ángulos del rayo y del jugador.

        angle = fabs(ray->angle_ret - player): Calcula la diferencia de ángulos de forma absoluta.

        Si la diferencia de ángulos es mayor a π (180°), se ajusta para tomar el ángulo más corto entre el rayo y la dirección del jugador, usando:
        angle=2π−angle
        angle=2π−angle

        Esto garantiza que el rayo se proyecte en la forma correcta, evitando inconsistencias cuando el rayo gira alrededor de 180 grados.

    Cálculo de la distancia de desplazamiento vertical:

        ray->vertical_ray_travel se calcula multiplicando la distancia de la hipotenusa (obtenida previamente en ft_hypo) por el coseno del ángulo entre el rayo y el jugador.

        distancia vertical=hipotenusa×cos⁡(angle)
        distancia vertical=hipotenusa×cos(angle)

        Este cálculo proporciona la distancia proyectada del rayo a lo largo de la dirección del jugador, ajustada para la visualización en la pantalla. De esta forma, las distancias de las paredes se escalan correctamente en función de la dirección del rayo.

    Condición de ajuste por mínima distancia:

        Si ray->vertical_ray_travel resulta ser demasiado pequeña (menor que 0.0001), se ajusta a un valor muy alto (9999999999999.0). 
        
        Este ajuste es una técnica para evitar valores extremos que puedan causar errores visuales o de cálculo en el raycasting.


ft_hypo: Calcula la distancia real (hipotenusa) entre el jugador y la pared usando el teorema de Pitágoras, ajustando según la dirección del rayo (horizontal o vertical).

ft_vert: Calcula la distancia del rayo en el eje vertical y la ajusta según el ángulo de visión del jugador, lo que permite una correcta proyección de las paredes en la pantalla del juego.

