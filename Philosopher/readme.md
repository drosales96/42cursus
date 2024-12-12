# Estructura de datos

Dentro del archivo ".h", se crearán dos bloques de datos principales, el primero se trata del bloque que abarca todo lo necesario de cada filósofo. Iremos poco a poco desglosando los datos:

1. pthread_t threads: es un tipo de dato específico que se asigna a ese hilo que a su vez esta asociado con un filósofo en específico, siendo así el proceso paralelo que se encargará de realizar acciones en segundo plano como son en este caso comer, dormir y pensar. (dato: el uso de multihilos se puede ver en las paginas web, por ejemplo cuando estás visualizando la hoja de proyecto en 42 Intra, y a su vez le das a descargar al subject y se empieza a descargar en segundo plano).

2. int id: número de identificación único de cada filósofo.

3. int eat: bandera que se usará para indicar que el filósofo está comiendo actualmente (pues se activará cuando en el código se detecte esa acción).

4. int meals_eaten: contador del número de comidas que ha hecho el filósofo (básicamente el numero de acciones que realizar el hilo del proceso).

5. int philos_no: número de filósofos en simulación.

6. int eat_time_needed: tiempo requerido por el filósofo para comer.

7. size_t last_meal: momento (tiempo) en el que el filósofo comió por última vez.

8. size_t time_to_eat, time_to_die, time_to_sleep: parámetros de tiempo específicos para informar o para usarlos como parámetros para las acciones.

9. size_t starting_time: tiempo de inicialización de la simulación.

10. pthread_mutex_t *right_fork, *left_fork: básicamente se va a necesitar para que solo un filósofo pueda usar los tenedores.

11. pthread_mutex_t *write_lock: mutex para evitar que en la salida estándar de la consola se mezclen salidas de diferentes hilos.

12. pthread_mutex_t *dead_lock, *meal_lock: mutexes adicionales para proteger y sincronizar el estado de muerto y las cuentas de comidas.

13. int *dead: variable de estado global, ya que siempre se va a mantener con un valor para asignar el estado de vivo, y cambiará para señalar el estado de muerto.

Ahora le toca el turno a la estructura de la "mesa", y la llamaré así porque realmente simula la mesa donde los filósofos se van a sentar. Por lo tanto dentro de esta estructura los filósofos van a compartir información común.

1. int dead_flag: bandera para indicar la muerte.

2. pthread_mutex_t write_lock: mutex para la escritura en pantalla, así evitamos mensajes mezclados.

3. pthread_mutex_t dead_lock: mutex para proteger la variable dead.

4. pthread_mutex_t meal_lock: mutex para sincronizar el seguimiento de números de comidas.

5. t_philo *philo: puntero a un array de estructuras que representa a todos los filósofos en la simulación.

¿QUE SON LOS MUTEX?: Para entender bien el proyecto se necesita saber que son los mutex y porqué se usan... Básicamente los mutex son herramientas de sincronización que se usan para garantizar que varios hilos no puedan entrar a datos (punteros) a la misma vez, ya que esto podría interferir el resulltado de la variable.

Los mutex tienen siempre una inicialización, un lock, un unlock y por último un destroy.

