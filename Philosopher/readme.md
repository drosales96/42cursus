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

# Argumentos

Ahora que tenemos todo lo necesario en cuanto a estructura de datos del proyecto para una futura proyección, pasemos entonces al tratamiento de los argumentos que vamos a recibir. Ya sabemos por el subject que vamos a recibir el nombre del programa (./philo) + otros 5 argumentos que son:

av[1] = Número de filósofos que van a participar en la simulación.
av[2] = Tiempo en el que morirá el filósofo.
av[3] = Tiempo de comer del filósofo.
av[4] = Tiempo de dormir del filósofo.
av[5] (OPCIONAL) = Las comidas que debe hacer cala filósofo.

Si le das una vuelta a la carpeta src/ vas a encontrar un archivo llamado ft_arg_checker.c, donde vas a comprobar que lo que se hace es verificar en una de las funciones que el contenido de los argumentos no sea un caracter alfabético, sino que debe ser de tipo numérico. En la función principal, lo que haremos será ir argumento por argumento verificando posibles errores, por ejemplo en el primer argumento le indico que el número de filósofos máximo va a ser 250 (porque si son infinitos, con números grandes al final acabrán ocurriendo errores), además también se verifica que el numero que se introduzca no sea menor que 0 y por último que sea una cifra, y no un caracter alfabético.

Desde el argumento 2 hasta el 4 las verificacione son las mismas, que el número no sea negativo y que sea un argumento válido (NUMÉRICO).

En el argumento opcional, usaremos un condicional porque solo si se da su existencia, entonces se veririca lo mismo que los argumentos del 2 al 4 y se pondrá en funcionamiento.

# Inicialización

Toca el proceso de inicialización del programa y restos de elementos, en primer lugar empezaremos inicializando la "mesa" que es la base principal, dentro de la carpeta init/ en el archivo ft_init_table.c encontraremos la función a la que nos referimos que recoge como argumentos, t_table *table y t_philo *philo , que son los dos argumentos que vamos a necesitar.

Dentro de la función vamos a ir inicializando elementos como por ejemplo la "flag" que la usaremos en caso de muerte, después "philo" que recogerá a los filósofos que entren por argumento en el programa. Por último llamamos a la función de inicialización de mutex para el manejo de los hilos (cosa principal en el proyecto), así que se inicializa los futuros "locks" de lo que se escriba por pantalla (write_lock), la muerte (dead_lock) y por último las comidas (meal_lock).

En segundo lugar se van ainicializar los input que recibimos de la llamada al prgrama, básicamente asignando a cada argumento el papel que va a tener dentro de la estructura de datos, para el futuro manejo dentro de nuestro código, creo que visualmente es bastante fácil de comprender si vas a ft_init_arguments.c dentro de la carpeta de init/.

En tercer lugar pasamos a inicializar la información de cada filósofo que participará en el programa. Primeramente mediante un bucle decreciente de los filósofos que entre por el STDOUT, iremos inicializando cada elemento del nodo filósofos.

1. philos[i].id = i + 1; -> de esta manera el primer filósofo será el 1 y no el 0.
2. philos[i].eat = 0;
3. philos[i].meals_eaten = 0;
4. ft_init_arguments(&philos[i], av) -> inicializa los argumentos
5. philos[i].starting_time = get_current_time();
6. philos[i].last_meal = get_current_time();

Asignación de punteros a los mutex compartidos en el programa:

7. philos[i].write_lock = &table->write_lock;
8. philos[i].dead_lock = &table->dead_lock;
9. philos[i].meal_lock = &table->meal_lock;
10. philos[i].dead = &table->flag;

Accesso a los tenedores:

11. philos[i].l_fork = &forks[i];

Condicional para el tenerdor de la derecha:

12. if (i == 0)
        philos[i].r_fork = &forks[philos[i].philos_no - 1];
    else
        philos[i].r_fork = &forks[i - 1];

Te preguntarás por que se opera para conseguir la referencia del tenerdor derecho de cada filósofo, y es que en el subject ya te lo dice si le has prestado atención. En este caso lo hacemos de la siguiente manera, comprobamos si nos escontramos con que es el caso del primer filósofo (i == 0), y si es así entonces, restamos uno al numero de filósofos porque el primer filósofo será el último del array.

En todos los demás caso simplemente se le resta 1 al indice del filósofo actual.

En cuarto lugar inicializamos los forks, que mediante un bucle while recorremos uno a uno dándole su inicialización.

# Rutina del filósofo

Ahora toca comprender la rutina que debe seguir cada filósofo, y sería de la siguiente manera:

1. Pensar: Espera antes de coger los tenedores.
2. Toma los tenedores (2): Bloquea mutex y verifica si es seguro comer.
3. Comer: Actualiza el tiempo de la última comida, se pone un temporizador para simular la comida y se incrementa el contador de comidas.
4. Deja los tenedores: Desbloquea mutexes
5. Duerme: Temporizador para simular el sueño.

Ejemplo simple:

```c
void *philosopher_routine(void *arg) {
    t_philo *philo = (t_philo *)arg;

    while (1) {
        // Pensar
        printf("Philosopher %d is thinking\n", philo->id);

        // Tomar tenedores
        pthread_mutex_lock(philo->left_fork);
        pthread_mutex_lock(philo->right_fork);

        // Comer
        philo->last_meal = ft_get_times();
        printf("Philosopher %d is eating\n", philo->id);
        ft_usleep(philo->time_to_eat);

        // Dejar tenedores
        pthread_mutex_unlock(philo->right_fork);
        pthread_mutex_unlock(philo->left_fork);

        // Dormir
        printf("Philosopher %d is sleeping\n", philo->id);
        ft_usleep(philo->time_to_sleep);
    }

    return NULL;
}
```

Esto anterior sería un ejemplo práctico que no tiene por que coincidir exactamente con el obejtivo del proyecto, solo sirve para ver como se usarían los locks y demás elementos que intervienen en los hilos.

# Funciones "vitales"

## ft_eating_checker()

Primeramente me gustaría empezar por una función que va a checkear las comidas o comidas objetivo que tienen los filósofos que realizar.

Si vamos a src/ en ft_eating_checker.c podemos ver que dentro está la función ft_eating_checker() que nos va a servir para checker lo relacionado a las comidas. La función solamente recibe a un t_philo *philos, porque necesitamos acceder a la info de los folósofos.

Primeramente checkea si el argumento opcional existe y si es así continúa. Con un bucle while que recorre el array de los filósofos uno a uno, vamos a hacer lock a la variable o puntero relacionado con las comidas para que no pueda interferir otro hilo, pudiendo sobreescribir la variable. Después se comprueba si las comidas realizadas son iguales o más que las comidas que se han metido en el argumento opcional, siendo así se suma la variable eating_times, cada vez que se de el condicional, y por supuesto en cada iteración se hace lock, se modifica la variable, y se hace unlock para asegurarla.

En segundo lugar se pasa al siguiente bloque donde comparamos el argumento opcional (cantidad) con la cantidad de filósofos del primer argmento que recibe philo. Si son iguales, se actualiza el puntero dead con el que se da fin a la simulación saliendo con 1 simulando que los filósofos han acabado de comer dandole muerte a la simulación.

En todos los demás casos se continúa retornando 0, dando a entender que aun los filósofos deben seguir comiendo pues no se ha llegado al número máximo de filósofos y comidas.

## ft_dead_philo_checker()

Esta función es para verificar la vida o la muerte de solo un filósofo, básicamente a nivel individual, como se puede apreciar tiene que recibir la estructura de philo y el tiempo de muerte. Lo que se hará será primeramente hacer lock a la comida, y llamaremos a ft_get_times() para que nos de el tiempo actual que será restado al tiempo estimado para la muerte, y por supuesto siempre y cuando también no haya comido el filósofo, verificando así si aún le queda vida o no.

## ft_checking_all_philos()

Esta función es muy muy parecida a la anterior, solo que en este caso recorre el array de philo para poder mirar TODOS los philos, verificando así la vida o la muerte de alguno de ellos.

Primero, gracias al bucle recorremos el array de los filósofos, y si la función ft_dead_philo_checker() retorna muerte como resultado de alguno de loa filósofos que estamos verificando, hacemos lock a dead_lock para poder modificarla sin que hayan errores por culpa de otros hilos (previamente se ha sacado por pantalla el filósofo muerto), y después de hacer unlock, se retorna muerte, saliendo de la simulación. En cualquier otro caso retorna ALIVE que es la vida (0).

