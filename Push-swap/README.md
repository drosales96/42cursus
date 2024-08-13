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

### SORT_TWO

Este apartado en sí no exite como función puesto que si os fijáis en la función
push_swap que aparece en mi main, compruebo si el tamaño del stack es de dos y
que si es así y además NO está ordenado ese stack simplemente haremos un movi-
miento 'sa'. Así que graficamente sería así:

stack_a : 5 -1 (!sorted)

'sa'

stack_a : -1 5 (AHORA SI ESTÁ ORDENADO)

### SORT_THREE

En este apartado del proyecto vamos a ordenar tres números diferentes en orden
aleatorio. (Obviamente en el código hemos implementado la condición de que si
tenemos 3 números pero están ordenados, tendremos un 'return' como una casa)

En primer lugar tenemos una función llamada 'find_biggest' que literalmente se
va a encargar de encontrar el número mayor de los tres.

Imaginemos que tenemos los siguientes números: 5 -20 65

EL código funcionaría de la siguiente manera, almacenamos en 'res' el primer ele-
mento de la lista (5), y con el bucle while empezaremos comparandolo con el sigui-
ente número (-20). ¿Es -20 > que 5? La respuesta es NO, por lo que no se cumple,
ahora pasamos a comparar 65 con 'res'. ¿Es 65 > que 5? La respuesta es SI, por lo
que ahora 'res' se actualiza con 65 como el número más grande, y como no hay más
que comparar retornamos 65 como el mayor.

En la función principal de ordenamiento de 3 números (sort_three), usando la fun-
ción anterior ya sabemos que 65 es el número mayor. Así que toca buscar de nuevo
en la lista para poder ordenar. Ahora iremos verificando número a número para po-
der ejecutar movimientos (sa, sb, ra, rb...).

En la variable 'biggest' ya tenemos almacenado el 65 (en este caso claro), asi que
buscamos si el primer número es el mayor (5 -20 65), cosa que no es, por lo que no
se cumple y pasaríamos a la siguiente condición. Es ahora el segundo número de la
lista el famoso 'biggest', pues NO así que no vamos a la última condición, donde
el último número si es el 'biggest' así que se ejecuta un 'sa' en stack y la cosa
quedaría de la siguiente manera: -20 5 65

¡YA TENEMOS LA PILA ORDENADA!

### SORTING (+3 números)

Ahora si viene la acción, porque empezamos con el algoritmo que es la parte princ-
ipal de este proyecto TAN complejo que te quitará al menos 1 mes de vida.

Lo que primeramente hará el programa push_swap en la función push_swap, es veri-
ficar que el tamaño del stack_a (el que recibe los numeros desordenados o NO) sea 
de más de 3 números y que además estén desordenados. Siendo este el caso, vamos
a llamar a la función 'nb_partition' que es la que se va a encargar de gestionar
los números de los dos stacks.

#### NB_PARTITION

Vamos a ponernos en situación, imaginemos que tenemos 5 números desordenados y sin repeticiones, por ejemplo: 

(100, 25, -15, 45, 2)

La función en cuestión cuenta con la variable 'pushes' que cont-
abiliza las veces que mandamos números de stack_a a stack_b.

Luego tenemos 'stack_size' para saber el tamaño de la pila que
en este caso es de '5', y por último tenemos 'i' que va a iterar
por los números de los stacks.

En este caso de 5 números el primer bucle while no se cumple por
que directamente el stack_size no es mayor de '6' por lo que pa-
saremos al siguiente condicional en el que restaremos al stack_
size las veces que se hagan 'pushes'.

Así que en la primera iteración graficamente sería (5 - 0 > 3)
, la respuesta es SÍ, asi que el primer numero pasa al stack_b
y sumamos 1 a 'pushes'. En la segunda iteración tenemos lo si-
guiente (5 - 1 > 3), y también sería un SÍ por lo que pasamos
el numero al stack_b y sumamos 1 a 'pushes'. Siguiente itera-
ción (5 - 2 > 3), en este caso es un NO y graficamente tenemos:

stack_a                    stack_b
-15                         100
45                          25
2

Como ya no se cumple ningún bucle de la función actual, nos sal-
imos de ella y toca llamar a la función que ya conocéis, que es 'sort_three'.

Asi que por lo tanto para no tener que repetir la misma explicación, repásate
el funcionamiento de 'sort_three' para saber como va a ordenar los tres números
que hemos dejado en stack_a.

Tras el funcionamiento de la función, los stacks quedarían:

stack_a                    stack_b
-15                         100
2                          25
45

#### GET_TARGET_POSITION

Ahora como podemos ver en la función 'sorting' entramos en un bucle while que es-
tará en funcionamiento mientras existan números que estén en stack_b. Primeramente
vamos a entrar en la función 'get_target_position'.

Esta función tiene como argumentos ambos stack para poder encontrar la posición de
mi target. ¿Qué es un target? Relax...

TARGET: posición objetivo de un número que queremos averiguar constantemente, por
que queremos saber en que posición en stack_a es mejor mover un número del stack b
, para que eventualmente stack_a (donde se van pasando números de manera lógica
para que se vaya quedando todo ordenado) esté ordenado, aun durante el proceso.

Así que empecemos por crear dos variables, una del tipo t_stack que se llama *tmp,
y otra de tipo int que se llame target. 'Tmp' almacena el puntero que señala al
stack_b y target futuramente se inicializará en '0', pero antes hay que averiguar
la posición que se va asignar a los números tanto en stack_a como en stack_b.

La función 'get_position' básicamente mediante un bucle while, irá asignando posi-
ciones a los números a medida que va incrementandose. Así que lo que haremos será asignar graficamente esas posiciones;

stack_a                      stack_b

-15 (pos 0)                     100 (pos 0)
2 (pos 1)                       25(pos 1)
45 (pos 2)

Una vez hemos conseguido las posiciones, 'target' ya está inicializada a '0' y to-
ca mediante un bucle while conseguir nuestro 'target'. Así que target lo igualamos
a la función 'get_target', que explicaré detenidamente abajo.

Tenemos una variable t_stack que se llama tmp y que es un puntero que señala al
stack_a, pero tenemos que acordarnos que previamente estabamos posicionando los
números en el stack_a, y ahoara queremos meter esos numeros 1 a 1 en el mejor lu-
gar dentro del stack_a. Por lo que debemos contar con que la función get_target,
de por sí está contando lo con los números de stack_b que están en la variable
'index_b'.

Así que mirando en el stack_a vamos a comparar si primer numero es mas grande que
el que hay en stack b (que queremos meter en su target correcto), y si además es
más grande que el 'target_i' que en el primer caso sería el INT_MAX, como -15 no cumple una de las condiciones pasamos al siguiente número y así sucesivamente, por
lo que al final no se cumplirá el primer bucle ya que 100 es más grande que todos
los números que hay en el stack_a.

Así que entraremos en el segundo bucle que se va a encargar que en el caso que el
número que queremos colocar en stack_a (que viene de stack_b) es mayor que los que
hay en stack_a, lo que haremos será buscar en el stack_a el número con menos index
que tengamos, así que graficamente sería:

Primera iteración:

if (tmp->index < target_i)
if (-15 < target_i (INT_MAX en el primer movimiento)) Sí es el caso.
{
    target_i = -15;
    target = tmp -> pos (0);
}
tmp = tmp->next (siguiente numero)

Segunda iteración:

if (2 < -15)
{
    target_i = NO SE CUMPLE NADA, NO SE HACE NADA;
    traget = NO SE CUMPLE NADA, NO SE HACE NADA;
}
tmp = tmp->next (siguiente numero)

Tercera iteración:

if (45 < -15)
{
    target_i = NO SE CUMPLE NADA, NO SE HACE NADA;
    traget = NO SE CUMPLE NADA, NO SE HACE NADA;
}
tmp = tmp->next (siguiente numero)

Finalmente tenemos el número con menor index, y como 100 no tiene lugar donde de
verdad debería ir colocado, gracias a la lógica del algoritmo acabará futuramente
pasando al final de la lista.

Como retorno tendremos el target apropiado para los numeros de stack_b en stack_a.

#### MOVE_COST

Ahora pasaríamos a calcular lo que valdría cada movimiento entre las pilas e inc-
luso dentro de cada pila según el caso porque el proyecto tiene diferentes puntu-
aciones dependiendo de la cantidad de movimientos que se usen para ordenar la se-
cuencia de números que recibe.

Así que vamos al lío, primeramente vamos a la función 'move_cost' que como argume-
ntos recibe a ambos stacks para poder calcular.

Tendremos dos variables t_stack que serán para almacenar los punteros a los stacks
y además tendremos dos variables de tipo int que almacenarán el tamaño de ambos
stacks.

tmp_a = *stack_a
tmp_b = *stack_b

size_a = size_stack(tmp_a) [FUNCIÓN PARA AVERIGUAR EL TAMAÑO DE LA PILA 'A']
size_b = size_stack(tmp_b) [FUNCIÓN PARA AVERIGUAR EL TAMAÑO DE LA PILA 'B']

Vamos primeramente a recorrer el stack_b en busca del coste de mover dicho
númewro por el mismo stack para poscionarlo lo mejor posible para después
moverlo a su target en stack_a. Así que "tmp_b->cost_b = tmp->pos", es decir el
coste en stack_b es su posición. Sí la posición está en la segunda mitad del
stack_b, entonces la operación sería negativa para que se mueva en dirección con-
traria del stack para que cueste menos movimientos.

Ahora calcularemos el coste de target en stack_a, si el target en stack_a del nú-
mero que queremos mover de stack_b está en la segunda mitad de la pila stack_a,
la operación será negativa para movernos en dirección contraria para ordenar. Si
ambos casos anteriores se dan en la primera mitad de la pila el coste del movimi-
ento empezará en positivo.

Ejemplo gráfico:

stack_a                      stack_b

-15 (pos 0)                     100 (pos 0)
2 (pos 1)                       25(pos 1)
45 (pos 2)

Empezaremos calculando el coste con el número 100, sabemos que la posición suya es
'0'y que además se encuentra en la primera mitad de su pila (porque son solo dos
números y está el primero), así que sus movimientos costarán 0. Su posición obje-
tivo sería la posición '2' en stack_a para que vaya en el último lugar, asi que 
como dicha posición está en la segunda mitad de la pila stack_a, su coste será
negativo para movernos en el sentido opuesto.

Si quisiéramos buscar el coste del '25' primeramente el coste de moverlo en su mi-
smo stack sería -1 puesto que la operación sería ((2 - 1) * -1) que es igual a -1.
Por lo que el coste sería un movimiento en sentido contrario (para posicionarlo dentro de su stack).

Después para calcular su target sería de la siguiente manera ((3 - 1) * -1) que 
es igual a -2.

Esperon que haya quedado claro pero igualmente se irá entendiendo mejor a medida
que avancemos en la explicación.

#### CHEAPEST_MOVE

Creo que solo con el nombre de la función queda bastante claro que lo que queremos
es encontrar el movimiento que nos cueste lo menos posible para optimizar el algo-
ritmo de ordenación.

Ya una vez hemos entendido cómo obtener el coste que puede conllevar los movimien-
tos que hagamos tanto en stack_b (cost_b) como en stack_a (cost_a), ahora debemos
comparar la sumatoria de los costes para averiguar y usar el movimiento que nos 
haya salido mas bajo en cuanto a gasto.

Creo que graficamente lo vamos a ver mejor:

stack_a                      stack_b

-15 (pos 0)                     100 (pos 0)
2 (pos 1)                       25(pos 1)
45 (pos 2)

Número 100:

cost_a = -1
cost_b = 0

Operación (1 + 0 = 1)

Número 25:

cost_a = -2
cost_b = -1

Operación: (2 + 1 = 3)

Con la función que véis llamada 'neg_to_pos' pasamos a positivo los valores nega-
tivos de los costes para comparar mejor y poder operar.

Así que como aprece en el codigo (1 + 0 = 1)

¿Por qué es así?

while (tmp)
{
    if(neg_to_pos(tmp->cost_a) + neg_to_pos(tmp->cost_b) < cheapest)
    {
        cheapest = neg_to_pos(tmp->cost_a) + neg_to_pos(tmp->cost_b);
        cost_a = tmp->cost_a;
        cost_b = tmp->cost_b;
    }
    tmp = tmp->next;
}

TRADUCCIÓN VISUAL:

if (1 + 0) < cheapest(INT_MAX en la primera iteración)
{
    cheapest = 1 + 0;
    cost_a = 1;
    cost_b = 0;
}
SIGUIENTE NÚMERO;

Ahora tenemos como referencia en cheapest el primer coste que es 1.

Iremos comparando con el coste de los siguientes números y si esos costes son ma-
yores a los de referencia se mantiene el que tenemos, pero si aparece un coste menor nos quedaremos con el coste total menor de esa operación como referencia, y
entonces se guarda su resultado en la variable cheapest y se va comparando hasta
el final.

Finalmente vamos a llamar a la función 'ft_moves' para realizar los movimientos
que necesitemos teniendo en cuenta el coste menor ya encontrado.

La función 'ft_moves' básicamente una vez que recibe los parámetros para poder ma-
ndar números de stack_b al stack_a por el menor precio posible, va a verificar y
ordenar dichos movimientos.

Por lo que por ejemplo en la secuencia que llevamos usando un rato, sería:


stack_a                      stack_b

-15                         100 (cost_a = -1 || cost_b = 0) = 1
2                           25  (cost_a = -2 || cost_b = 1) = 3
45 

void ft_moves(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
    if (cost_a < 0 && cost_b < 0)
        reverse_ab(a, b, &cost_a, &cost_b);
    else if (cost_a > 0 && cost_b > 0)
        rotate_ab(a, b, &cost_a, &cost_b);
    rotate_a(a, &cost_a);
    rotate_b(b, &cost_b);
    pa(a, b);
}

Teniendo en cuenta las referencias, y sabiendo que el movimiento de menor coste es
la referencia del numero 100. La primera condicion no se cumple porque ambos cos-
tes no son negativos, la segunda condición tampoco se cumple porque ambos no son
completamente positivos, asi que haremos los últimos tres movimientos, y sería:

Movimiento 1: rotate_a

stack_a                      stack_b

45                             100
2                               25
-15

Movimiento 2: pa

stack_a                      stack_b

100                            25
-15                            
2                               
45

EL siguiente número a pasar y por lo tanto final sería el '25' y que tiene un cos-
te de 0 y 0 porque ahora tenemos en stack_b solamente un número y eso sería 0 mo-
vimientos con un coste de 0. Y además en stack_a como se va a pasar el '25' sobre
la pila en la primera posición el gasto es también 0.

Entonces si revisamos la función 'ft_moves' no haremos ningún movimiento que tenga
coste ya que ambos para 25 son de 0. Solo se hará el pa para pasarlo a stack_a

stack_a                      stack_b

25
100                            NULL
-15                            
2                               
45

Una vez tenemos todos los elementos pasados al stack_a habiéndo encontrado el tar-
get de cada número y habiendo calculado los costes y habiendo hecho todos los mo-
vimientos que costaban menos ahora toca pasar a ordenar todos los números de la 
pila stack_a.

