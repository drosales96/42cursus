# Printf

## Descripción del proyecto

'Printf' es seguramente la función más querida de los piscineros y estudiantes a la hora de "escribir". Esta función será nuestro objetivo pues tenemos que replicarla para incluirla (en el caso de hacerla con bonus...seamos realistas, no lo vais a hacer).

Para usar la librería original siempre se usa #include <stdio.h>, en nuestro caso lo haremos de manera diferente puesto que la estamos replicando, aunque es recomendable ir comparando los resultados tu ft_printf personal y el original.

Debéis leer el subject (lo dejaré en el repo), pero básicamente cuando recorramos el ft_printf y nos topemos con un '%' significa que depués vendrá una letra clave que decidirá qué camino tomar nuestra *función variádica*, es decir, distinguirá si es alguno de los casos que aparecen en el subject y que son:

cspdiuxX% (Caracteres,Strings,Decimal,Integer,Unsigned, hexadecimal minúscula,heXadecimal mayúscula y '%').

## Descripción del código

Primeramente deberíais crear un archivo principal donde vamos a tener nuestra función variádica, y los casos que pueden haber después de porcentaje (casos que cada uno de ellos, llamarán a una función que se encargará de escribir, operar o lo que sea, y que además contará la cantidad de caracteres que contiene tu resultado de ft_printf).

Es decir si en el terminal tu ft_printf devuelve: "He contabilizado 7 caracteres" (resultado de: ft_printf("He contabilizado %d caracteres")). Tu printf debe decirte también que ha contabilizado x caracteres.

Vamos a empezar con lo principal, la función variádica:

*ft_printf*: 

Prototipo: int	ft_printf(const char *str, ...);

Básicamente retorna un int porque siempre vamos a estar escribiendo resultados y a la vez retornando un contador para contabilizar todo lo que escriba tu función.

El *str, puesto que tenemos que analizar cada caracter de nuestro ft_printf, que al final es un string, ejemplo:

ft_printf("Hola mundo, tengo %d años");

Desde la 'H' hasta la 's' del final tenemos que estar analizando, contabilizando y operando.

Tras esto lo primero que nos llamará la atención son los puntos suspensivos, y esto lo que quiere decir básicamente es que dentro de nuestra función, a partir de nuestro primero argumento (const char *str) podremos incluir una cantidad indefinidad de argumentos de cualquier tipo.

A continuación una breve ilustración de la estructura de una función variádica:

va_list: es un tipo de dato que define un puntero a la lista de argumentos variable, se maneja a través de las macros siguientes:

va_start: donde incluiremos a nuestra va_list y al primer argumento que se encuentre definido en el prototipo de la función. En este caso estaríamos hablandon de va_start(va, str).

va_arg: Es la forma que tenemos de llamar a los argumentos que no se encuentran definidos en el prototipo y que pueden ser de indefinida cantidad y de diferente tipo. Dentro de nuestro va_arg vamos a incluir a todos los casos de %. ¿Porqué no lo ves en la función ft_printf?, por que tienes que hacer scroll hacia arriba para ver ft_check, que es una llamada a una función externa que si contiene nuestros va_args, ya que nuestra querida norma no nos deja pasar las 25 líneas de código.

Tras operar con nuestros va_args, ¡¡toca ver el final!!.

va_end: donde incluimos a nuestro va_list (en mi caso se llama 'va'), para cerrar la lectura de todos los argumentos, y para culminar retornamos el contador.

LINKS DONDE ESTUDIAR UN POQUITO:

https://42-cursus.gitbook.io/guide/rank-01/ft_printf/variadic-functions

https://www.programacionenc.net/index.php?option=com_content&view=article&id=61:funciones-en-c-con-lista-de-argumentos-variable&catid=37:programacion-cc&Itemid=55

Ahora toca analizar el código de ft_printf poco a poco, vamos al lío. primero necesitamos nuestra varible 'va_list' que se llamará 'va' que viene siendo nuestra estructura de las variádicas, después usaremos una variable de tipo 'int' que se llamará 'count' y por último necesitamos la típica 'i' para ir iterando sobre nuestro string. 'Count' e 'int' se inicialñizan a 0 y arrancamo llamando a nuestra va_start(va, str).

Ya iniciado nuestro esqueleto variádico, con un bucle while recorremos str (str[i]), y le damos el primer caso que es que si nos econtramos elementos diferentes a un '%' me escribes cada caracter y almacenamos dicha escritura contabilizandola en count. El siguiente caso es que si nos encontramos un %, haremos un i++ para avanzar al siguiente caracter para entonces poder verificar con la función ft_check que letra viene (cspdiuxX %), y con eso que argumento operar. Entonces lo que haremos es añadir a count la mención de ft_check de la dirección de memoria de 'va', nuestro string a seguir analizando y un int 'i' que recorrerá dicho string.

Ahora nos desplazamos a la función ft_check que lo que va a hacer es crear una variable int que se llamará 'res' donde almacenaremos las operaciones que se hagan dependiendo del argumento que actúe. Por lo tanto inicializamos res a 0 y crearemos los casos que pueden llegar a pasar recorriendo el string con 'i'. Ahora lo verás mejor:

static int	ft_check(va_list *va, const char *type, int i)

	int	res;

	res = 0;
	if (type[i] == 'c')
		res += ft_putcharf((char)va_arg(*va, int));
	else if (type[i] == 's')
		res += ft_putstrf(va_arg(*va, char *));
	else if (type[i] == 'p')
		res += ft_pointer(va_arg(*va, uintptr_t));
	else if (type[i] == 'd' || type[i] == 'i')
		res += ft_putnbrf(va_arg(*va, int));
	else if (type[i] == 'u')
		res += ft_putunsgf(va_arg(*va, unsigned int));
	else if (type[i] == 'x' || type[i] == 'X')
		res += ft_puthex(va_arg(*va, unsigned int), type[i]);
	else if (type[i] == '%')
		res += ft_putcharf('%');
	return (res);


Type que es el string (le he cambiado simplemente el nombre) a analizar, será recorrido por 'i' y si se ecuentra alguna coincidencia con los casos 'cspdiuxX%' nos iremos a otras funciones que operarán dependiendo del tipo. Ahora vamos a por dichas funciones:

(%c)*ft_putcharf*: Es literalmente un ft_putchar pero que siempre retorna un valor int de 1, por lo que cada vez que escriba un caracter está sumando de 1 en 1 sus movimientos.

@params1: char c (CARACTER A ESCRIBIR)

(%s)*ft_putstrf*: Esta función se parece un poco al clásico ft_putstr pero con alguna modificación que te dejará loco/a/e. Primero necesitamos crear dos variables de tipo int que se llamarán 'i' (para iterar en el string) y 'count' (para contabilizar cada vez que vayamos escribiendo con la función).

RECUERDA QUE TODAS LAS FUNCIONES PARA TODOS LOS CASOS cspdiuxX % DEBEN CONTAR LO QUE HACEN.

Entonces primero vamos a dar el caso de que nuestro string sea NULL y si es así se llama recursivamente así misma (ft_putstrf) porque en el momento que sube al autollamarse el puntero del prototipo para a ser NULL y lo que directamente va a hacer es escribir lo que hay dentro de las comillas dobles.

return (ft_putstrf("(null)"));

¿Por qué (null)?: Porque printf original cuando detecta un puntero NULL lo escribe así y contabiliza 6.

Ahora haremos un bucle While del string iterando en el y le añadiremos al count lo que escriba nuestro putcharf(s[i]), y por su puesto haremos i++ para ir escribiendo, sino lo haces escribirás un caracter y adiós función.

Finalmente retornamos el 'count'.

@params1: char *s (string sobre el que vamos a trabajar)

(%d y %i)*ft_putnbrf*: En esta función apenas me voy a enrrollar porque es literalmente el ft_putnbr de piscina pero metiéndole el valor de cada cosa que escribes y cada operación que hagas dentro del contador. Creo que visulmente lo verás mejor: 

int	ft_putnbrf(int nb)

	int	count;

	count = 0;
	if (nb == -2147483648)
	{
		count += ft_putcharf('-');
		count += ft_putcharf('2');
		count += ft_putnbrf(147483648);
	}
	else if (nb < 0)
	{
		count += ft_putcharf('-');
		nb = -nb;
		count += ft_putnbrf(nb);
	}
	else if (nb > 9)
	{
		count += ft_putnbrf(nb / 10);
		count += ft_putnbrf(nb % 10);
	}
	else
	{
		count += ft_putcharf(nb + '0');
	}
	return (count);


@params1: int nb (numero con el que operar)

(%u)*ft_putunsgf*: Basicamente queremos imprimir un número sin signo así que lo que haremos es simplemente de manera recursiva dividir entre 10 para desglosar el número y después y convirtiendo cada dígito a tipo char.

Siempre tenemos que incluir dentro de count cada movimiento o operación.

Visualmente sería asi:

int	ft_putunsgf(unsigned int n)

	int	count;

	count = 0;
	if (n > 9)
		count += ft_putunsgf(n / 10);
	count += ft_putcharf(n % 10 + '0');
	return (count);

@params1: unsigned int n (Número sin signo con el que operaramos)

(%x y %X)*ft_puthex*: En esta función vamos a tener que aprender bien como tratar un número el cual queremos pasarlo a hexadecimal, ya que al igual que el ft_putnbr dividía entre 10 dicho número hasta conseguir el número mínimo con el que operar, los hexadecimales también tienen un proceso.

Primeramente imaginemos un número que queremos pasar a hexadecimal que en mi caso va a ser: 68702702552.

Acontinuación si miramos el código primero hace una operación recursiva para fraccionar el número, que en este caso hace ft_puthex (nb / 16) hasta conseguir el número mínimo con el que operar. Se vería así:

68702702552
4293918909
268369931
16773120
1048320
65520
4095
255
15

Ahora lo que hace nuestro programa es cuando ya ha evaluado si lo que se ha encontrado era 'x' o 'X', usa la base correspondiente:

'x' : "0123456789abcdef"
'X' : "0123456789ABCDEF"

Lo siguiente que hará será coger los números de manera ascendiente, asi que como 15 ya es representable en la base hexadecimal le daremos el valor de 'f' y lo escribirá.

"0 1 2 3 4 5 6 7 8 9 a b c d e f"

posiciones:

 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15

 Por lo tanto el 15 en hexadecimal es la 'f'

 Sigamos, ahora cogemos el 255 y le aplicamos esa operación tan rara entre corchetes (ft_putcharf("0123456789abcdef"[nb % 16])), que lo que hará es hacerle el módulo de 16 a todos los números de la pirámide invertida anterior para sacar el número hexadecimal. Sería así:

255 % 16 = 15. ('f')
4095 % 16 = 15 ('f')
65520 % 16 = 0 (Es igual a cero porque el calculo da un resultado entero, sin decimales, por lo tanto el hexadecimal es '0')
1048320 % 16 = 0
16773120 % 16 = 0
268369931 % 16 = 11 ('b')
4293918909 % 16 = 13 ('d')
68702702552 % 16 = 8 ('7')

HEX: 0xff000bd7

Al final tenemos que hacer i++ para que el número pueda ir calculándose, sino solo se haría una vez el proceso.

Retornamos 'i' puesto que es el contador (contador que se contiene en la función)

@params1: unsigned long long nb (Es un número mucho mayor que un integer que además es sin signo)

@params2: char c (el char a comprobar puesto que necesitamos saber si es 'x' o 'X' para decir la base con la que operar)

(%p)*ft_pointer*: Esta función nos va a permitir poder imprimir en hexadecimal la dirección de memoria de un puntero. Vamos a usar una variable nueva muy útil y que te ayudará a pasar esta función de una manera más cómoda, y se llama UINTPTR_T que es un primo del SIZE_T.

Esta variable destaca porque es un tipo entero sin signo que es capaz de almacenar un puntero de datos. Lo que típicamente significa que tiene el mismo tamaño que un puntero, así que nos ayudará a facilitarnos la vida.

A continuación para acompañar al tipo de variable crearemos un contador de tipo size_t (son compatibles) y que inicializa en 0 y se llamará 'counter'. Después le incluiremos dentro el valor de un write(1, "0x", 2), puesto que necesitamos escribir y contar el prefijo que printf usa para decir que lo que venga después es un hexadecimal. Tras esto counter almacena contabilizando la función ft_puthex que como anteriormente habrás visto y TE HABRÁS ESTUDIADO A FUEGO, para imprimir en hexadecimal la dirección de memoria del puntero, que de manera predeterminada el ordenador te facilita en formato decimal (de ahí que lo pasemos a hexadecimal).

Finalmente retornamos el counter.

## Final de la guía

Espero que sirva como ayuda para cualquier persona que vaya a hacer el proyecto, si se le ocurre a alguien alguna idea para mejorar el código o lo que sea, que lo informe. GRACIAS




