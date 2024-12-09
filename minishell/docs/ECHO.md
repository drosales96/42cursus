# FUNCIONES PARA ECHO

## ft_print_echo_args()

Primeramente hablemos de los parámetros pues en este caso recibe un puntero a la lista de elementos de la estructura del árbol, donde realmente tenemos los tokens con los que estamos jugando.

En segundo lugar tenemos un integer llamado flag que básicamente es una bandera que se inicializa en 1 determinando que el comando echo va solo sin llevar el argumetno "-n".

Una vez entramos en el bucle de elementos del árbol, vamos a comprobar si su tipo es TOKEN_ARGUMENT y siendo así se imprime el valor del argumento.

Lo que hace el bucle es que si hay nodo a la derecha añade un espacio para ir separando cada argumento y que se imprima de manera natural.

Abajo del bucle tenemos "args = args->right" para ir avanzando a los siguientes argumentos ya que todos los argumentos que acompañen al comando van en el nodo "right".

Ahora imprimimos al final de todos los tokens impresos un salto de línea ya que es el comportamiento natural de bash.

Finalemente si hay éxito el retorno es de 0.

## int ft_echo_cmd()

Los paŕametro de esta función son en primer lugar un puntero a la estructura del AST donde se encuentra la lista con los comandos, argumentos, etc...

En segundo lugar recibe un puntero a la estructura de minishell (t_mini) que es la estructura principal realmente.

Dentro del código, usando una variables de tipo ast y puntero, podremos obtener el primer argumento si la igualamos a "cmd->left" ya que siempre y cuando un comando exista y vaya con argumentos el primer argumento estará a su izquierda y los demás a su derecha.

Se hace una verificación en el caso que no hayan argumentos y si es así se lanza un mensaje de error por la salida STDOUT.

Ahora continuamos verificando si el primer argumento se trata de un "-n" y siendo así el caso la "flag" se pone en 0 activándola para tener en cuenta que no irá con salto de línea, después continuamos al siguiente nodo.

Ahora llamaremos a la anterior función ft_print_echo_args() para imprimir los demás argumentos (nodos) y pasándole la "flag" para la impresión sin el salto de línea.