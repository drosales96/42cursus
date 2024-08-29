# So Long

El objetivo es desarrollar un videojuego en 2D, en el que haya un punto de
salida y otro punto de fin, en el trayecto el objetivo es que el personaje
principal recoja 'X' cantidad de coleccionables para dar por finalizada la
partida al 100%.

## Conceptos básicos

### ASSETS

1. Tiles:

Los tiles son pequeñas imágenes o gráficos individuales que representan una unidad básica de un terreno o un entorno en un juego 2D. Por ejemplo, un tile podría ser una porción de césped, una piedra, o una parte de un camino. Los tiles suelen tener un tamaño fijo, como 16x16 píxeles o 32x32 píxeles, y se colocan en una cuadrícula para formar el mapa o el fondo del juego.

2. Tilesets:

Un tileset es una colección de tiles que se agrupan en una sola imagen o archivo. Esta colección incluye todos los tiles necesarios para construir diferentes partes de un nivel o entorno en el juego. Un tileset podría incluir gráficos para suelos, paredes, agua, montañas, etc. Al tener todos los tiles en un solo archivo, es más fácil diseñar y modificar los niveles del juego y mantener consistencia en los gráficos.

3. Sprites:

Los sprites son imágenes que representan a los personajes, enemigos, objetos, o cualquier elemento móvil o interactivo dentro del juego. A diferencia de los tiles, que generalmente forman parte del fondo o terreno del juego, los sprites se mueven y cambian de apariencia para mostrar diferentes estados (por ejemplo, caminar, saltar, atacar). Un sprite es una imagen individual que puede tener diferentes variaciones o poses.

4. Sprite Sheets:

Un sprite sheet es una imagen que contiene todos los sprites de un personaje o de un conjunto de objetos en diferentes estados o animaciones. En lugar de tener archivos separados para cada frame de animación de un personaje, todos estos frames se colocan juntos en una sola imagen. El uso de sprite sheets facilita la gestión de gráficos, reduce la cantidad de archivos, y mejora la eficiencia del juego al cargar gráficos de manera más rápida. Durante el juego, se "corta" la imagen del sprite sheet para mostrar el frame adecuado según la animación o acción que esté ocurriendo.


Resumen:

Tiles: Elementos gráficos individuales pequeños que forman los fondos del juego. <br>
Tilesets: Conjunto de tiles agrupados en un solo archivo para facilitar la construcción de niveles. <br>
Sprites: Imágenes que representan personajes, enemigos, y objetos móviles o interactivos. <br>
Sprite Sheets: Imagen que contiene todos los sprites de un personaje u objeto en sus diferentes estados de animación. <br>

### Minilibx

Estamos hablando en este caso de una librería gráfica que está en poder de 42, y que es muy fácil de usar,
y aunque en el subject te viene un enlace o varios enlaces para conseguir tu librería y sus archivos que
lleva como consecuencia, no te va a funcionar por errores técnicos. Así que para ahorrar tiempo dejo el
siguiente enlace para descargar la nueva versión:

[MLX42](https://github.com/codam-coding-college/MLX42/tree/master)
<br>
Sigue los pasos que te proporciona el README.md del autor para instalar y usar la librería.

Importante revisar (si estas con tu PC personal), que tengas instalado la orden 'cmake', glfw y OpenGL.

Comandos de instalación en LINUX:

1. GLFW:

sudo apt update <br>
sudo apt install libglfw3 libglfw3-dev <br>

2. OpenGL

sudo apt update <br>
sudo apt install libglu1-mesa-dev freeglut3-dev mesa-common-dev <br>

Una vez instalada in compilada la librería tocaría revisar las funciones que tiene y sus usos.



