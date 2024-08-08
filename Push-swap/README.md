## PUSH_SWAP

# 1. Tratamiento de los argumentos

Para este proyecto necesitamos poder recibir una cantidad aleatoria de números
desordenados que debemos ordenar con un algoritmo. Será necesario poder recibir 
tanto un argumento como varios puesto que si metemos ARG="0 1 15 95 122", el pro-
grama tartará esta entrada como un argumento aunque contenga 5 números. También 
podrá recibir  ARG= 0 1 15 95 122 y directamente tendríamos 5 argumentos que debe-
mos tratar.

En primer lugar si nos vamos al main del programa veremos que lo primero que haremos
será aplicar un " ft_split (av[i], '  ') " para poder extraer cada número como un 
nodo/elemento de la lista que vamos a manejar, para poder tartar individualmente cada dato como un
número independiente asociado a un nodo.

En segundo lugar nos iremos a "argv_tartement.c" donde podremos encontrarnos algunas 
funciones que se encargarán de manejar las entradas por teclados de los argumentos.

La función "ft_correct_input" se encargará de recibir ese string que contiene los 
números y lo que hará será verificar caracter por caracter el string, mirando si hay
un signo '+' o '-' y si la longitud del string es mayor de 1, en ese caso haremos i++
para seguir verificando la siguiente posición.

Por lo tanto si hay un signo solo sería un caso de error, si hay signo acompañado de
números se considera correcto y sigue verificando, e incluso si no hay signo pero si
hay números pues sigue verificando porque estamos ante un número. Desṕues de verificar
si hay signo y numero después verificamos que todo lo que haya después del signo no sea 
un dígito decimal, y si es así saldremos retornando '1', que es caso de error, y retornará 
'0' si todo es correcto.

La siguiente función que nos vamos a encontrar sería "ft_duplicate" y veremos que en este
caso estamos manejando la lista directamente. Lo que haremos será crear dos variables del
tipo "t_stack" que una de ellas almacenará el puntero al nodo actual (current) y la otra
almacena el puntero al siguiente nodo de la list (next_nb). El código verifica que exista
una lista y siendo así, mientras haya nodo actual, miraremos al siguiente nodo y si ambos
nodos poseen un 'value' igual, significa que hay un número duplicado. Gracias a "current = 
current->next" y a "next_nb = next_nb->next" iremos siempre verificando cada número en busca
de alguna duplicación. En el caso de duplicación retorna '1' y en el contrario '0'.

La siguiente función es "ft_atol" y básicamente es lo mismo que la función previamente usada
en otros proyectos que se llama "ft_atoi" pero modificando los límites del número que pasa de
ser entero (int) a ser long int, para que si se prueban casos de números por debajo o por en-
cima del valor de un entero que haya posibilidad de analizarlos sin que el programa se rompa,
para poder lanzar un ERROR.

int main(int ac, char **av)


    t_stack *stack_a;
    t_stack *stack_b;
    int     stack_size;
    int     i;

    i = 1;
    stack_a = NULL;
    stack_b = NULL;
    while (i < ac)
    {
        numbers(av[i], &stack_a);
        i++;
    }
    if (ft_duplicate(stack_a))
        errors(&stack_a, NULL);
    stack_size = size_stack(stack_a);
    ft_get_index(stack_a, stack_size + 1);
    push_swap(&stack_a, &stack_b, stack_size);
    free_stacks(&stack_a);
    free_stacks(&stack_b);
    return (0);


En base a lo visto en el tratamiento de los argumentos, una vez que ambos stack se inicializan en NULL,
y nuestro iterador 'i' se inicie en 1 (puesto que no queremos contar con el nombre del ejecutable),
recorreremos cada argumento (número) para tratarlos y con la función "numbers" que básicamente se encarga
de rellenar el stack_a de números y a su vez tartarlos con las funciones que hemos visto anteriormente.

Una vez que tenemos el stack_a lleno de números y ya listos para ser tratados, lo que haremos será veri-
ficar si hay alguna duplicación, y siendo ese el caso, entraremos a la función "errors" que como podréis
comprobar en "utils.c" recibe como parámetros ambos stacks (a y b) y si en algún caso alguno de los stacks
es NULL o contiene datos ya tratados se liberan, y directamente se escribe un mensaje de ERROR con un
salto de línea.

# 2. Comprobar el tamaño del stack_a

Como pone en el subtítulo, recurriremos a la función "size_stack" que básicamente se va a encargar de "medir"
la longitud del stack que necesitemos (que en este caso es el 'a'). Debemos recordar que comprobamos el tama-
ño del stack_a cuando ya tenemos los números en el.

Tras esto, usaremos la función "ft_get_index" que nos va a permitir asignar un 'index' a los nodos de la
lista enlazada dependiendo del 'value' que tengan. Iremos poco a poco, la función recibe un puntero al
stack_a y un entero que será el tamaño máximo de stack_a. A continuación creamos variables que son necesa-
rias para asignar los 'index', creamos un t_stack *ptr para recorrer la lista, y un *bigger que se asignará 
al mayor valor del nodo (como aún no exite, inicializa en NULL); 'value' irá almacenando el valor más grande
que vayamos encontrando durante cada iteración de la lista.

Con un bucle while que recorrerá la lista de atrás hacia adelante (gracias a la condición "--stack_len_max >
 0"), lo que haremos será ir comprobando todos los casos posible. El primer caso es si 'ptr->value' es el
 INT_MIN (–2147483648) y además no hay aún ningún indice asignado a ningún nodo (ptr->index == 0), entonces
se le da el valor '1'.

El segundo caso es que si 'ptr->value' es mayor que el valor almacenado en la variable 'value' (int), y además aún no hay un 'index' asignado a ese nodo, entonces se actualiza value y bigger para asignar a ese
nodo como el mayor encontrado en esa iteración, y se avanza al siguiente nodo gracias a 'ptr = ptr->next'.

Si los dos casos anteriores no se cumplen, avanzamos al siguiente nodo directamente (condición del else).

Finalmente si 'bigger' no es NULL y por lo tanto contiene un nodo con mayor valor, se le asigna el índice
'stack_max_len'. Y se repite de nuevo el proceso hasta que todos los nodos tengan un índice asignado, por lo que al final del proceso cada nodo en la lista tendrá un índice que reflejará su posición relativa en 
función de su valor.

# 3. Proceso de ordenación de los números

Una vez que tenemos el/los argumento/s tratados, y hemos rellenado el stack_a de números, pero además hemos
comprobado el tamaño del stack, y también hemos asignado un 'index' a cada nodo dependiendo del 'value' del
número que hay en ese nodo, ya podemos decir que estamos listos para ordenar, puesto que gracias a todo lo
anterior tenemos todo colocado a favor.

Ahora pasaremos a llamar a la función principal del proyecto que es push_swap, esta función recibe como pa-
rámetros la dirección de memoria de stack_a, la de stack_b y una variable de entero que es el tamaño del
stack.

En esta función directamente asignaremos un stack_size manualmente para manejar 3 casos. En primer lugar
vamos a manejar el caso en el que el tamaño del stack es de 2 números que además están desordenados (para
saber si están desordenados usaremos la negación de la función "ft_is_sorted") en stack_a (recuerda que es
el stack que recibe los números que pasamos por argumento). Si se da este caso, haremos el movimiento "sa"
que es básicamente cambiar el primer número por l segundo. EJEMPLO: ARG= "3  2" ----> sa ----> ARG= "2  3".

El siguiente caso será cuando el stack tiene un tamaño de 3 números, que si se da el caso, llamaremos a la
función sort_three, que recibe como parámetro el stack_a (donde están los tres números).

<h3>SORT_THREE</h3>

En esta función vamos a crear una variable de tipo entero que se llame 'biggest' que nos
va a servir para almacenar el mayor 'index' de los tres números que recibe.

