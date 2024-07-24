# Libft

ANTES QUE NADA OS/ME RECOMIENDO LEER EN GIT HUB ESTE DOCUMENTO EN MODO CÓDIGO, PORQUE ASÍ SE DISTINGUEN LOS COLORES ENTRE TÍTULO DE FUNCIÓN Y DESARROLLO DE LA MISMA.
## Descripción

Básicamente necesitamos replicar las funciones que se encuentran en <string.h> + algunas adicionales y bonus que no pertenecen a la librería. La clave es la paciencia y el insistir e ir todos los días e ir sumando avances.

Siempre que necesites información RTFM y sino, busca en Google.

## Descripción de las funciones

*ft_atoi*: En esta función ignoraremos símbolos o espacios hasta llegar a los números a obtener y se operará con los símbolos negativos para conseguir nuestro objetivo.

@params1: unsigned int (para iterar sobre el string, y es unsigned para poder operar con los signos)
@params2: int res (variable que entra en juego para guardar el valor de la operación para convertir los numeros que aparecen de tipo char a tipo int (str[i] - '\0'))
@params3: int sign (variable que entra en juego a la hora de operar con los signos y poder convertirlos en caso necesario o directamente saltarlos con nuestro i++)

*ft_bzero*: En esta función tenemos un void *str y un size_t n(len), y lo que haremos es un índice y mientras que el recorrido del mismo sea menor que n(len), casteamos el *str para darle valor (char) y lo llenaremos de '\0'.

@params1: void *str (string a recorrer).
@params2: size_t n (para obtener el len).

*ft_calloc*: Básicamente consiste en hacer una reserva de memoria con malloc y dentro de esta asegurarla con tu (!buffer). Después llenarás de '\0' esa memoria asegurada(es más rapido usando bzero dentro).

@params1: size_t count (ancho de memoria).
@params2 size_t size (largo de memoria)

*ft_isalnum*: Función auxiliar para detectar si hay alguna letra mayúscula o minúscula, y también si hay algún número.

@params1: int c (variable que usaremos para decirle que si se encuentra alguna coincidencia con lo que busca la misma función, que retorne (1), y sino retorna (0)).

*ft_isalpha*: Función auxiliar que detecta que lo que se encuentre sea una letra mayúscula o minúscula.

@params1: int c (la variable hace lo mismo que en ft_isalnum, pero buscanso solo letras).

*ft_isascii*: Función auxiliar que detecta caracteres en ASCII, comprendiendo entre 0 y 127 dentro de la tabla.

@params1: int c (Al igual que las funciones anteriores, retorna (1) si se ecuentra el caracter a buscar y retorna (0) en el caso contrario)

*ft_isdigit*: Función auxiliar que detecta si hay algún numero de base 10 (del 0 al 9).

@params1: int c (Si se encuentra algún dígito de los que he mencionado anteriormente, retorna (1) y sino es así retorna (0))

*ft_isprint*: Función auxiliar que busca una coincidencia de caracteres imprimibles de ASCII, que se comprenden entre el 32 y el 127.

@params1: int c (Con esta variable te ayudas para detectar si hay algun caracter imprimible de ASCII y devuelve (1) si es correcto y retorna (0) si es el caso contrario)

*ft_memchr*: Esta función localiza la coincidencia de un caracter que te pasarán como tipo (int) y que tendrás que castear a (char) dentro de tu función. Necesitaremos un indice para recorrer el string. Este string es de tipo void *, por lo tanto tendremos que crear una variable donde guardar el valor del puntero original, pero casteándolo a tipo (const char) [str = (char *)s]. Cuando finalmente se encuentre la coincidencia del char dentro de tu str[i] (usando la condición de que (i < n)), se retorna la dirección de memoria del primer char que señala el puntero, y por sonsiguiente el indice (return(&str[i])).

@params1: const void *s (puntero original que señala al string)
@params2: int c (caracter a buscar (CASTEALO POR DIOS))
@params3: size_t n (parámetro que será las 'n' posiciones que se van a recorrer en la memoria, nos servirá como 'len')

*ft_memcmp*: Esta función va a comparar dos strings (s1 y s2), siempre va a retornar un resultado int ya que se restarán lo que vale el caracter que contiende s1, que lo comparas con el que se encuentra en la misma posición en s2. Por lo tanto si en size_t n le metes como parámetro un 4, revisará la cuarta posición de s1 y la cuarta posición de s2 y las compara (s1 - s2). Hay que tener en cuenta que al jugar con memoria y que se proporcione como parámetro un const void *s1/s2, necesitaremos crear variables donde guardar el casteo de cada string de void a char. En este caso al poderse emitir un resultado negativo o positivo, haremos el casteo con (unsigned char).

@params1: const void *s1 (puntero que señala al primer string a comparar)
@params2: const void *s2 (puntero que señala al segundo string a comparar)
@params3: size_t n(posición dentro de ambos strings a comparar)

*ft_itoa*: Esta función es compleja y necesita alguna función auxiliar. Primeramente haremos una función que comprueba que el número sea negativo, y mediante la división de 10 y un incremento del numero que reciben, extrae la longitud total del número a operar, ya desglosado número a número ( longitud de la cadena de números ). A continuación, usaré una función que  cuando se encuentre un signo negativo lo transforme a positivo. la tercera función es la reserva de memoria que será necesaria en este ejercicio y que la haremos fuera para no superar las 25 líneas en la función principal.

Dentro de la principal, verificamos si el número es negativo, y siendo así la variable signo adquiere el valor de 1 para que en el caso que lo sea retorne 1, como que es verdadera la condición . A continuación la variable 'len' almacenará el resultado de nuestra función que sacaba la longitud del número que recibe. Luego en la variable buffer ( que almacenará la función que hace la reserva de memoria ) aplicaremos la función 'memnum' y acontinuación aseguramos con ( !buffer ) / return (NULL); . A continuación haremos un bucle que decrece ( ya que tenemos el len del número ), y el buffer ( memoria ) + len ( longitud del numero que recibe ), hará la transformación a char, usando el 48 + nbr % 10, que irá haciendo la transformación dígito a dígito gricias al % de 10 y la / 10. Finalmente, si la condición del signo es verdadera y por lo tanto es negativo, se añade el símbolo '-' que es 45 en ascii, al primer caracter de buffer. Al final del todo retornamos buffer que contiene el número en formato char.

@params1: int n ( El número que recibes como parámetro y que vas a convertir a char )

*ft_memcpy*: Esta función realizará una copia del bloque de memoria src a dest. Crearemos 3 variables, la primera es un size_t que la llamaremos 'i' y que la usaremos para recorrer las siguientes dos variables que contendrán src y dst ( originales ), La segunda variable ( llamada *source ) almacenará el parámetro *src que se castea a ( char * ), debido a que queremos trabajar sobre un const void. La última variable es de tipo char y almacena el casteo de dst. A continuación entramos en código y verificamos que source ( que contiene src ) y que dest ( que contiene dst ) no sean nulas. En el caso opuesto entonces entraremos en código y mientras 'i' sea menor que los n caracteres ( que entraran por el main ) que queremos copiar de src en dst ( SIEMPRE QUE SE COPIE LA VARIABLE QUE RECORRE DEBE SER ++ O -- ( dependiendo del caso )). Finalmente retornamos dest ( variable que almacena la copia que se ha hecho en dst ), donde está realizada la copia.

@params1: void *dst ( Destino de la futura copia )
@params2: const void *src ( Origen de los 'n' caracteres que se buscarán para hacer la copia en dst)

*ft_memmove*: Esta función se va a encargar de copiar un bloque de memoria sobre otro, incluso si se da el caso que se solapan. Primero necesitamos crear 3 variables, la primera será un size_t llamado 'i' que básicamente va a recorrer dest y src durante ls copia de memoria ( en el caso que los bloques no se solapen ) . En segundo lugar crearemos una variable que se llamará dest y que va a almacenar el valor del puntero original de dst casteado a ( char * ). Por último crearemos otra variable que se llamará source que va a almacenar el valor del puntero de src original con su respectivo casteo a ( char * ). 

Continuaremos metiéndonos en código, y lo que haremos será comprobar si dst y src son NULL ( se haría de la siguiente manera. if ( !dest && !source ) / return ( NULL ); . Ahora nos pondremos en el caso  que dest sea > que src ( Para que se de el caso de que puedan solaparse), entonces haremos un decrecimiento de i ( i-- ) ya que tenemos el len de ambas fuentes ( source y dest ) , y se decrece puesto que al poder solaparse la copia de adelante hacia atrás es la manera más segura de hacerlo. La manera de copiarlos seria dest [len] = source [len] ( PORFAVOR SIEMPRE DEBES PONER REFLEJADO EL CRECIMIENTO O DECRECIMIENTO DE LA VARIABLE QUE RECORRE DURANTE LA COPIA ).

Por último si no se da el caso anterior y no se llegan a solapar los bloques de memoria, directamente ponemos la condición de que ( i < len ) y ya hacemos la copia pero con nuestro índice 'i'. La copia sería dest [i] = source [i]; (ACUÉRDATE DEL  I++).

Finalmente vamos a retornar dest que es dónde se habrá realizado la copia.

@params1: void *dst ( donde harás la copia de src según el len que se pase por el main )
@params2: const void *src ( fuente de origen de donde haremos la copia )
@params3: len ( la longitud de caracteres que queremos copiar y que se mandará por el main )

*ft_memset*: Esta función nos va a servir para llenar de x caracteres un bloque de memoria que señalará un puntero específico. Lo que necesitamos es un contador que será de tipo size_t y que se llama´ra 'i'. Además necesitamos crear un puntero que será de tipo char, que va a almacenar el valor del puntero ( void ) específico que queremos llenar de x caracteres ( esa variable puntero que almacena el puntero original, tenemos que castearlo a unsigned char, debido a que necesitamos llenar de caracteres y por lo tanto tenemos que movernos por el puntero que hemos creado byte por byte para ir rellenando 1 a 1). 

Ya nos metemos en código y hacemos el caso de que i sea < que len, y siendo así entraremos en el puntero que hemos creado ( que se llamará buffer ), iterando con nuestro contador 'i' ( buffer [ i ]) y lo igualaremos a ( unsigned char ) c para rellenar de esos caracteres x el buffer. Te preguntarás por que se castea el char y es porque necesitamos que sea forzado a ser char puesto que nos lo pasan como integer, y como hemos dicho necesitamos caracteres que que irán de 1 en 1 puesto que pesan 1 byte ( al contrario que los integers que pesan 4 bytes cada unidad ). METEMOS EL FUCKING I++ SINO SE NOS VA A LA MIERDA EL CÓDIGO. 

Finalmente retornamos el buffer que básicamente contiene que valor del puntero original que viene en el prototipo.

*ft_strchr*: En esta función lo que haremos es recorrer un string y si nos encontramos la primera coincidencia de un char c que entrará por main como int c ( HAY QUE CASTEARLO ), retornará la dirección de memoria de s que va a apuntar a la coincidencia del char encontrado + i para que te saque por pantalla ese char que encuentra y lo que viene después. Necesitaremos un contador de tipo size_t que se llamará 'i' y que se inicializa a 0. Ese contador recorre 's' hasta que llegue al nulo,  y ponemos también la posibilidad de que s[ i ] != ( char )c, y en esos casos avanzaremos.  Ahora tras avanzar si se da el caso que s[i] == (char) c pues lo que haremos retornaremos el puntero que señala al char c que coincide más lo que le sigue usando [i].

@params1: const char *s ( string sobre el que vamos a trabajar ).
@params2: int c ( char c que se casteará para ser convertido y que buscaremos como coincidencia dentro de s).

*ft_strrchr*: Esta función se encarga de encontrar la última coincidencia de un caracter que meterás por main. En primer lugar crearemos un contador de tipo int que en este caso en vez de inicializarse en 0 , meteremos dentro un ft_strlen ( s ) para saber la longitud total de la cadena y empezar a buscar el caracter desde atrás. Por lo tanto mientras i sea > o = que 0 si s[ i ] == ( char )c retornará la dirección de memoria que apunta a ese caracter que encuentra desde el final mas el i para que salga en pantalla el caracter coincidente mas el resto del string.


@params1: const char *s ( string sobre el que vamos a trabajar ).
@params2: int c ( char c que se casteará para ser convertido y que buscaremos como coincidencia dentro de s).

*ft_strlcat*: En esta función concatenaremos src y dest sin desbordamientos . Primeramente tenemos 3 variables que son 'i' que va a recorrer dest, 'res' que va a recorrer src y que al final será retornada con la concatenación, y por último tenemos 'j' que recorre src en el momento en el que necesitamos concatenar. Mirando el código primero recorremos dst con 'i' y src con 'res' ( USANDO ++ PARA LLEGAR AL NULO ), después si el tamaño a concatenar es menor o igual que 'i' que corre destino, entonces añadiremos src + 'i' ( que recorre dest ). Si esto no pasa y por lo tanto si hay espacio para la concatenación, recorreremos src con 'j' y nos aseguramos que no llegue a null y que también se de el caso de que 'i' + 1 ( para asegurar espacio al nulo que meteremos al final ) sea menor que el tamaño a concatenar, si que haremos la concatenacion de la siguiente manera ( dst[i] = src[j] ), incluyendo siempre nuestro I++ y J++.

Finalmente tras la concatenación meteremos un null al final de la concatenación que esta en dst [i] y retornaremos res que contiene la concatenación,

@params1: char *dst ( destino donde depositaremos la concatenación total )
@params2: char *src ( es la fuente origen de la que extraeremos el qué concatenar )
@params3: size_t dstsize ( es la cantidad a concatenar )

*ft_strlcpy*: En esta función haremos una copia de un string dado que se hará desde el final al principio para asegurar que la copia sea segura. Primeramente inicializamos un contador de tipo size_t y que se llama 'i', y que se inicializa en 0. Tras esto verificamos si la cantidad a copiar es 0, y si es así retornaremos un ft_strlen( s ), es decir la longitud de la cadena original, ya que no hay nada que copiar. Ahora si se da el caso que mientras src[ i ] no llega a null y que i sea menos que dstsize - 1 ( traducido al español, el final ), entonces haremos la copia de src en dst con nuestro i++ ( dst[i] = src[i] ), además tras esto pondremos el null al final de dst y se haría poniendo ( dst[i] = '\0' ). Además en esta función devolvemos la copia y el tamaño de esta, y se hace retornando el ft_strlen (src);

@params1: char *dst ( destino donde se hará la copia )
@params2: const char *src ( fuente origen que se deberá copiar en dst )
@params3: size_t dstsize ( cantidad que queremos copiar y que se indicará en el main )

*ft_strlen*: Función básica que determina la longitud de un string ( no hace falta repasarla )

*ft_strncmp*: Esta función nos ayudará a comparar caracteres entre sí entre dos cadenas de string. Para ello necesitamos un contador de tipo size_t que se llama 'i' y se inicializa en 0. Mientras que  s1 y s2 no lleguen al null y que 'i' sea menor que n. Si s1 es diferente a s2 retornará s1 - s2, y que no se te olvide fuera el incremento de i ( i++ ). Ahora especificamos para asegurar que si i es menor que n pues que nos retorne la misma resta que hemos hecho en las líneas anteriores.

@params1: const char *s1 ( primer string )
@params2: const char *s2 ( segundo string )
@params3: size_t n ( n caracteres a comparar que entrarán por el main )

*ft_tolower*: Función que sirve para convertir en minúscula aquel caracter mayúscula que se encuentre.

@params1: int c ( caracter que analiza y al cual si es mayúscula sumará 32 para hacer la conversión )

*ft_toupper*: Función que sirve para convertir en mayúscula aquel caracter minúscula que se encuentre.

@params1: int c ( caracter que analiza y al cual si es minúscula restará 32 para hacer la conversión )

*ft_substr*: Esta función la vamos a usar literalmente para extraer un substring de un string principal, realizandole su creación de memoria con malloc y además asegurándola correctamente. En primer lugar declaramos una variable que es un puntero de tipo char que es donde vamos a hacer la reserva de memoria para el substring que queremos obtener.

Primeramente comprobamos que el string que nos pasan como parámetro no sea nulo if(!s) / return (NULL), de esta manera si no es nulo continua el proceso. Ahora toca proporcionar la casuística de la función, primero si el ft_strlen(s) < start, retornamos una duplicación de un string nulo con ft_strdup(""), que de por sí le creará un espacio de memoria null con malloc (esto es buena praxis). A continuación si se da el caso que el len a buscar es mayor que la longitud de la palabra + start (start es el punto de partida de nuestro substring), entonces la varible len del prototipo pasa a valer la longitud del string gracias a ft_strlen + start. 

Ahora es momento de crear la memoria y lo haremos poniendo (buffer = (char *)malloc(sizeof(char)* (len + 1))). Lo siguiente a cualquier creación de memoria es asegurarla con si negación. Entonces haremos que if(!buffer)/return (NULL);.

Lo último a realizar ya que tenemos la memoria creada, tenemos la longitu de todo el string y también nuestro start. Usaremos la funcion ft_strlcpy (ya que podría haber un desbordamiento), y contendrá ft_strlcpy(buffer, s + start, len + 1);.

Por último solo nos quedA retornar el buffer que es nuestra memoria creada con malloc que va a contener el substring.

@params1: char const *s (string principal).
@params2: unsigned int start (punto de partida de nuestro futuro nuevo substring)
@params3: size_t len (longitud que queremos extraer como nuevo substring del string principal)

*ft_strjoin*: Esta función nos va a servir para crear memoria con malloc de la dimensión de dos strings diferentes para almacenar ahí a los dos juntos, como quien dice, uniéndolos.

Vamos a necesitar 4 variables, primero una tipo size_t que se llame totallen, otra size_t i, otra size_t j y la última será un puntero char donde crear memoria y se llamará buffer.

Totallen va a ser = a ft_strlen (s1) + ft_strlen(s2) y vamos a pasar a inicializar a 0 tanto 'i' como 'j'. Ahora que tenemos la longitud de todo lo que tenemos que usar, vamos a crear la memoria y lo haríamos asi, buffer = [(char *)malloc(sizeof(char)*] totallen + 1);. Acontinuación, aseguramos la memoria con la negación de buffer, que debe retornal NULL en ese caso.

Como resulta que en este caso no va a ser NULL, recorreremos s1 con un while y usando el contador 'i' y dentro copiamos de manera normal lo que hay en s1(src) en buffer(dest), y recuerda el i++. Tras haber copiado el primer s1, haremos exactamente el mismo proceso del while de s2 pero con la variable 'j' y tambien copiaremos en buffer, puesto que continuará por donde lo habia dejado.  Ahora si avanzamos tanto j++ como i++ para terminar la copia. La copia sería (buffer[i] = s2[j]). Finalmente cerramos el string con un NULL (buffer[i] = '\0') y retornamos buffer.

@params1: char const s1 (primer string)
@params2: char const s2 (segundo string)

*ft_strtrim*: Esta función básicamente sirve para eliminar cualquier sobrante, caracter, espacio, tab o lo que sea que rodee a un string (tanto por la derecha como por la izquierda).

Primero tenemos que crear un contador para recorrer el string y este será un unsigned int llamado 'i' que se inicializará en 0. A continuación comprobamos si s1 o set (set son los caracteres que queremos eliminar) con su negación y siendo así retorna NULL. 

Miraremos por la izquierda buscando los elementos a quitar y lo haremos con un while al cual le aplicamos la función ft_strchr sobre set y *s1 y contemplando que s1[i] no llegue al NULL. Es decir que si analiza el string y se encuentra algún set lo va a saltar hasta llegar a lo que no sea un set, y será haciendole s1++;

Ahora nuestra variable i va a tomar el valor de ft_strlen((char *)s1), y lo haremos con el proposito de ahora revisar el string por la derecha yendo desde el final hacia el principio. Lo haremos usando un whilr para recorrer y le aplicamos ft_strchr de ser y s1[i] y mientras i != 0, y decrementamos con i--; para ir hacia atras buscando coincidencias para saltarlas hasta encontrar lo que no sea igual que set.

Una vez delimitado el string haremos un return de la función ft_substr((char *)s1, 0, i + 1);

@params1: char const *s1 (string con el que vamos a trabajar)
@params2: char const *set (puntero que señala al caracter delimitador o que queremos quitar mejor dicho)

*ft_strnstr*: Esta función se va a encargar de extraer un string (substring) de un string principal. Primeramente empezaremos creando dos contadores, uno de ellos se encarga de recorrer el string principal (en este caso le llamamos 'i'), y el otro recorrerá el substring o tofind según mi prototipo. Iniciaremos 'i' a 0, y primeramente si la palabra a buscar (tofind[i]) es null (basicamente no tenemos palabra que buscar dentro de nuestro string principal), retornamos directamente el string principal con un casteo a (char *), ya que es un const char (return (char *)str1). A continuación comprobamos el string principial iniciando un bucle, que será, mientras str[i] no llegue al nulo y que i sea menos que 'n' tamaño que extraer, el contador 'j' se inicia a 0, y si resulta que str1[i] es == a tofind[j], mientras que (while) str[j + i] == tofind[j] y que (&&) i + j sea menos que 'n' tamaño, entonces si tofind [j + 1] ya llega al null (final del substring), retornamos str1 + i casteado a (char *). Finalmente se incrementa j++ y fuera del ultimo while incrementamos i++. Si nada de esto ocurre return (0).

@params1: const char *str1 (string principal donde buscar nuestro substring)
@params2: const char *tofind (es el string que vamos a buscar dentro del string principal)
@params3: size_t n (tamaño que vamos a buscar dentro del string principal)

*ft_strdup*: Esta función es útil cuando queremos crear un espacio de memoria donde vamos a realizar una copia de un bloque de memoria concreto. Para ello necesitamos crear una variable char * que llamará buffer y que será donde dentro guardaremos el malloc de memoria. Por supuesto necesitamos un contador para recorrer el string (bloque de memoria a copiar).

A continuación a nuestra variable size_t que llamaremos count, le daremos el valor de un ft_strlen del string (así tenemos la longitud totaal del string que se encuentra en el bloque de memoria). Tras esto haremos la reserva de memoria y la haremos de la siguiente manera: (char *)malloc(sizeof(char) * count + 1). Ahora aseguramos nuestra nueva memoria diciendo que: if (!buffer)/return (NULL). Tras esta comprobación y dentro de un else haremos la copia usando ft_memcpy(buffer, str, count + 1);

Finalmente retornamos el buffer que ya tiene la copia.

@params1: const char *str (string que vamos a copia mediante el ft_memcpy dentro de la memoria que creamos mediante malloc)

*ft_striteri*: Esta función básicamente nos permite que en un string podremos aplicar una función no definida a las iteraciones del contador que recorre el string y del mismo puntero que se mueve con el iterador. Crearemos un contador/iterador que es de tipo size_t y que se llamará 'i'. Antes de posicionarlo a 0, primero diremos que si el string y la función existen y se dan a la vez, entonces el contador se posiciona en 0 y mientras el string no llegue al nulo, se aplica la función sobre i++ y s++.

No retornará nada puesto que es una función iniciada en void.

@params1: char *s (string que será analizado y sobre el cual se aplicará la función no definida)
@params2: void (*f) (es void puesto que no se sabe que función se usará y qué rertornará)
@params3: unsigned int, char * (el unsigned int puesto que será el iterador que recorre el string y el char* puesto que es el puntero del string que se mueve a la vez que el iterador)

*ft_putchar_fd*: Es una función muy básica que se encarga de escribir caracter a caracter y que en lo que va a variar con la original es que podemos elegir el file descriptor (que pueden ser 1, 2 o 3, por lo general). El codigo se vería así:

void    ft_putchar_fd(char c, int fd)
{
    write(fd, &c, 1);
}

@params1: char c (caracter que imprime)
@params2: int fd (file descriptor o mejor conocido como fd)

*ft_putendl_fd*: Función que básicamente escribe un string completo por un fd usando la función ft_putstr_fd sobre el string, y después como pide un salto de línea usaremos la función ft_putchar_fd que sacará un \n y por el fd que se concrete.

@params1: char *s (string sobre el que trabajar)
@params2: int fd (file descriptor por el cual se lanzará el programa)

*ft_putstr_fd*: Función que básicamente es como la ft_putstr normal pero solo cambiará el incluir el fd. El código sería el siguiente:

char    ft_putstr_fd(char *s, int fd)
{
    size_t  i;

    i = 0;
    while (s[i])
    {
        ft_putchar_fd(s[i], fd);
        i++;
    }
    return (s);
}

@params1: char *s (string sobre el que trabajaremos)
@params2: int fd (file descriptor que se especificará futuramente)

*ft_putnbr_fd*: Esta función básicamente es igual que el putnbr de piscina solamente que cambia que se usará ft_putchar_fd a la hora de imprimir signos o numeros. Si no se te ha olvidado esta función usa la recursividad y lo que hará es cogerá un número que entrará por el main que se irá operando mediante si división entre 10 y el módulo de 10 para extraer cifra a cifra y luego sacarla por el fd correspondiente pero convertidas una a una a tipo char.

@params1: int n (numero sobre el que se va a operar)
@params2: int fd (file descriptor)

*ft_split*: Esta función tiene como propósito, detectar primeramente la longitud de todas las posibles palabras, sin contar los delimitadores (esto se hará gracias a la función auxiliar word() // MIRAR CODIGO EN GITHUB). En segundo lugar usaremos la función wordlen() (MIRAR CÓDIGO) para conseguir la longitud de cada palabra que se va a extraer y se va a convertir a un array individual con su propia reserva de memoria dentro de la reserva principal. En tercer lugar tenemos una función llamada free_array() que nos permite liberar toda la memoria que se va a crear y que después no aparezcan esos odiosos leaks de memoria. 

Finalmente, usando las tres funciones auxiliares entramos en materia y dentro de la función principal necesitamos crear una variable char **buffer (reserva principal de memoria que es un puntero que señala a subpunteros), un int llamado 'i' que servirá como iterador sobre el string, y un int 'is' que itera sobre el **buffer. 

Primero hacemos como ya sabemos la reserva de memoria del **buffer con malloc y a continuación aseguramos la reserva: 

buffer = malloc(sizeof(char *) * (word(s, c) + 1));
	if (!buffer)
		return (NULL);

Después entramos en el buffer con la condición mientras que 'is' que va incrementando sea menor que la función word(s, c), y mientras que s[i] sea == c incrementamos i++ para saltar el delimitador e interpretar que estas en una nueva palabra. Entonces ahí volvemos a usar malloc para la reserva individual de cada palabra: 

buffer[is] = ft_substr(s, i, wordlen(s, c, i));

Tras esto en vez de asegurar memoria de manera normal, vamos a liberar toda la memoria creada con la funcion free_array():

if (!(buffer[is]))
{
	free_array(buffer, is);
	return (0);
}

Tras esto al índice i le añadimos la longitud total de todas las palabras (una a una ya que es un bucle).

Finalmente le ponemos el null a la reserva grande de memoria y retornamos el buffer:

buffer[is] = NULL;
return (buffer);

word()

@params1: char const *s (string que se va a analizar)
@params2: char c (caracter delimitador)

wordlen()

@params1: char const *s (string que se va a analizar)
@params2: char c (caracter delimitador)
@params3: int i (iterador que trabaja sobre *s)

free_array()

@params1: char **buffer (reserva futura de memoria en Split (buffer **))
@params2: int is (futuro iterador que recorre el **buffer)

split()

@params1: char const *s (string que se va a analizar)
@params2: char c (caracter delimitador)

*ft_strmapi*: Esta función nos va a ayudar a crear una reserva de memoria con malloc del tamaño del string indicado, gracias a que usaremos ft_strlen(s), y tras esto recorremos el string iterando sobre el buffer de memoria añadiendole ++ y dentro de el, usaremos f(i++, s++) para iterar con una función aún no definidad moviendo tanto el iterador como el puntero de s para ejecutar dicha función en cada iteración.

newbuff()

@params1: size_t n ('n' cantidad de reserva de memoria)

EJECUCIÓN:

static char	*newbuff(size_t n)
{
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * (n + 1));
	if (!buffer)
		return (NULL);
	return (buffer);
}

ft_strmapi()

@params1: char const *s (string que se va a analizar)
@params2: char (*f) (determina que trabajaremos bite a bite, y también da pie a la función que se usará)
@params3: unsigned int, char * (el unsigned int puesto que será el iterador que recorre el string y el char* puesto que es el puntero del string que se mueve a la vez que el iterador)

*ft_lstnew*: Esta función basicamente crea una nueva lista usando la estructura t_list que te proporciona el pdf del subject. Es la siguiente estructura:

typedef struct      s_list
{
    void            *content;
    struct s_list   *next;
}                   t_list;

Como en cualquier creación de memoria usaremos malloc y será de la siguiente manera:

t_list	*list;

list = (t_list *)malloc(sizeof(t_list));
if (!list)
	return (NULL);

Lo siguiente que toca es entender las listas y como se trabajan con ella, daré ejemplos de este ejercicio para entender más:

list->content = content; (aqui entramos en la lista y con '->' indicamos que queremos señalar con el puntero de la lista al 'content' y que eso será igual al 'content').

list->next = NULL; (ahora entramos en list y usamos el intermediario next que gracias a el podremos señalar al siguiente nodo, pero como en este caso no hay más, señala a NULL, para dar a entender que no sigue nada más después del primer nodo).

Finalmente se retorna (list)

@params1: void *content (La función para crear una nueva lista directamente nos proporciona este puntero que señala al contenido de esta)

*ft_lstsize*: Esta función nos ayudará a contar el tamaño de un nodo ua creado anteriormente. Necesitaremos como de costumbre un contador de tipo int y que se inicie en 0, lo llamaremos 'count'. Recorreremos el nodo usando un while(lst != NULL), incrementamos el count++ y nos posicionamos en el siguiente elemento del nodo de la siguiente manera:

lst = lst->next;

Finalmente fuera del bucle retornamos el count.

@params1: t_list *lst (Será el puntero que señala al inicio de la lista (aparece la declaración t_list que es la estructura de las listas)).

*ft_lstadd_back*: La función ft_lstadd_back toma un puntero al primer elemento de una lista vinculada (lst) y un puntero al elemento que se agregará (nuevo). Comienza comprobando si 'lst' o 'new' es NULL. Si alguno de ellos es NULL, indica una operación no válida y la función regresa sin realizar ningún cambio. Comprueba si el puntero al primer elemento de la lista (*lst) es NULL. Si es NULL, significa que la lista está vacía. En este caso, asigna el elemento 'nuevo' al puntero del primer elemento (*lst) y regresa. Este paso es necesario para manejar el caso en el que la lista está inicialmente vacía. Si la lista no está vacía, inicializa un puntero temporal 'temp' y le asigna el valor del puntero al primer elemento (*lst). Luego recorre la lista usando un bucle hasta llegar al último elemento, que se indica mediante un puntero NULL 'siguiente'. Dentro del bucle, actualiza el puntero 'temp' para que apunte al siguiente elemento en cada iteración. Una vez que el bucle llega al último elemento, asigna el elemento 'nuevo' al puntero 'siguiente' del último elemento, agregándolo efectivamente al final de la lista. Finalmente, la función regresa y la lista ahora contiene el nuevo elemento al final.

@params1: t_list **lst (Aquí ya estamos recibiendo un doble puntero que básicamente es un puntero inicial que contiene otros punteros dentro y por lo tanto el primer puntero señala al primer lugar de memoria del puntero principal, y ese punto a su vez apunta al primer elemento quer contiene). 
@params2: t_list *new (Aquí tenemos el puntero interno que se encuentra dentro de lst, al que mismamente señala el segundo puntero de lst, [**lst], en este caso se le llama new puesto que no contiene nada).

*ft_lstadd_front*: La función ft_lstadd_front toma un puntero al primer elemento de una lista vinculada (lst) y un puntero al elemento que se agregará (nuevo). Comienza comprobando si 'lst' o 'new' es NULL. Si alguno de ellos es NULL, indica una operación no válida y la función regresa sin realizar ningún cambio. Asigna el puntero 'siguiente' del elemento 'nuevo' al puntero del primer elemento (*lst), haciendo efectivamente que el elemento 'nuevo' apunte al primer elemento actual de la lista. Luego, actualiza el puntero al primer elemento (*lst) para que apunte al elemento 'nuevo', convirtiéndolo en el nuevo primer elemento de la lista. Este paso garantiza que el elemento 'nuevo' se agregue al principio de la lista. Finalmente, la función regresa y la lista ahora contiene el nuevo elemento al principio.

@params1: t_list **lst (Aquí ya estamos recibiendo un doble puntero que básicamente es un puntero inicial que contiene otros punteros dentro y por lo tanto el primer puntero señala al primer lugar de memoria del puntero principal, y ese punto a su vez apunta al primer elemento quer contiene). 
@params2: t_list *new (Aquí tenemos el puntero interno que se encuentra dentro de lst, al que mismamente señala el segundo puntero de lst, [**lst], en este caso se le llama new puesto que no contiene nada).

*ft_lstdelone*: Esta función nos va a servir para eliminar el contenido de una lista, y a continuación liberarla mediante un free. Al final del todo al hacer la eliminación del contenido de esta. se  le añade el NULL para interpretar que esta creada pero vacía.

Código:

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	(del)(lst->content);
	free(lst);
	lst = NULL;
}

@params1: t_list *lst (Puntero que señala al primer elemento de una lista existente)
@params2: void (*del) (se trata de un puntero que básicamente recorrerála lista eliminando el contenido de esta si así se requiere. De ahí proviene el que se llame (*del), de la palabra DELETE).


*ft_lstclear*: Esta función nos va a ayudar a eliminar el contenido de una lista. Primeramente verificamos con un if (lst) si exite una lista y si es así entramos en código y recorremos el *lst con un bucle while (ya que el puntero sobre lst se moverá recorriendo). Y ahora mediante una variable previamente declarada con el nombre *aux (puntero ya que estamos trabajando sobre una lista de listas), y le damos el valor de ( * lst )->next. Tras esto usaremos la función ft_lstdelone sobre el ( * lst ) y usando del (ya que te lo pedirán los parámetros de la función para eliminar). Finalemte el  * lst se iguala a aux para devolverle el valor.

@params1: t_list **lst (Aquí ya estamos recibiendo un doble puntero que básicamente es un puntero inicial que contiene otros punteros dentro y por lo tanto el primer puntero señala al primer lugar de memoria del puntero principal, y ese punto a su vez apunta al primer elemento quer contiene)
@params2: void (*del) (se trata de un puntero que básicamente recorrerála lista eliminando el contenido de esta si así se requiere. De ahí proviene el que se llame (*del), de la palabra DELETE)

*ft_lstiter*: Esta función nos será útil para iterar con una función 'f' (se deberá especificar en caso de usar ft_lstiter en otro código), sobre el contenido de la lista. De manera que después de la negación de lst y de f (por si se da el caso de que alguna de las dos son NULL), haremos un bucle while para recorrer 'lst' y dentro del bucle aplicaremos la función sobre el contenido de 'lst'.

@params1: t_list *lst (puntero que señala directamente a la primera dirección de memoria de la lista)
@params2: void (*f)(void *) (Tenemos aquí el puntero sobre f puesto que la función que apliques va a iterar por cada lugar de memoria de lst, y también tenemos el void * puesto que estaremos aplicando dicha función sobre un puntero que no se sabe expresamente de que tipo será).

*ft_lstlast*: Esta función nos va a ayudar a posicionar el primer puntero, que señala a la primera dirección de memoria de lst, en el último ligar, posicionando así el que sería el último elemento como el primero, por supuesto siempre y cuando se de el caso que el último elemento de la lista contenga datos y no sea NULL.

@params1: t_list *lst (puntero que señala a la primera dirección de memoria de la lista, y sobre el cual vamos a estar trabajando).

*ft_lstmap*: En esta función vamos a recibir un puntero a un elemento existente que es *lst, y vamos a necesitar un un puntero a un nuevo elemento que en este caso se va a llamar *new, y necesitamos también un puntero llamado *node en el cual vamos a dar el valor de la función ft_lstnew a aplicar, sobre el contenido de lst, es decir vamos a crear un nuevo nodo con el contenido de lst. También creamos una variable void *set para almacenar dentro la operación anterior (f(lst->content))

Vamos a ir paso por paso, primeramente hacemos dentro de un if, la negación de lst, de del y de f para evitar errores, puesto que si alguno de ellos es null, tenemos que retornar NULL y abandonar el proceso.

Tras esto vamos a trabajar dentro de lst siempre y cuando exista (lo vamos a recorrer con un while). Dentro de lst, a nuestra variable set le introducimos/damos el valor de f(lst->content), y seguidamente a node le introducimos/damos el valor de la función para crear un nuevo nodo (ft_lstnew) que tomará como parámentro set.

A continuación si ocurre l negación de node, eliminamos el set (que es básicamente el contenido de lst), y tras esto usamos la función ft_lstclear sobre la dirección de memoria de new, eliminando así el null que contenía. Tras esto retornamos new.

Por último añadimos al final de la lista a node y posicionamos en primer lugar a new.

Retornaremos a new.

Esta función es una locura y es difícil de entender por eso es mejor mirar referencias y videos para entenderlo mejor.

@params1: t_list *lst (puntero al primer lugar de memoria de lst)
@params2: void *(*f)(void *) (puntero para aplicar una función iterando por los elementos de un nodo)
@params3: void (*del)(void *) (puntero para eleminar el contenido de un nodo)







