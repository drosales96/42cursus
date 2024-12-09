# FUNCIONES PARA *ft_execute_cmd()

## *ft_strcpy()

La necesitamos para poder ir copiando el nombre de cada directorio donde vamos entrando para buscar el exe del comando que se ha tokenizado anteriormente.

## *ft_strcat()

La vamos a usar para cuando tengamos en orden esos directorios que son la ruta hacia los exe del comando o comandos que se han introducido, puesto que luego hay que unir cada directorio formando una ruta que futuramente necesitará la función de ejecución.

Ejemplo:

Comando: ls
Token: ls

Rutas extraídas:

1. usr/
2. local/
3. sbin/
4. bin/
5. ls/

ls: /usr/bin/ls

## char ft_creating_cmd_path()

Función donde llamando a cmd_path, al doble puntero donde estamos almacenando las carpetas donde buscamos dentro de path, y al arbol sintáctico abstracto puesto que tenemos que acceder al valor de tipo char * de nuestro comando.

El retorno es el path final ya copiado y concatenado.

## *ft_find_cmd_path()

Esta función es la que trabaja todo el proceso de búsqueda del path que necesitamos encontrar.

Primeramente las variables que recibe son:

1. char **dir: path fraccionado y guardado como un doble puntero puesto que habrán diferentes carpetas que necesitamos tener por separado para acceder a ellas.

2. char *path: Simplemente el path.

3. *cmd_path: EL futuro path del comando introducido como input.

4. i : iterador para movernos por los nombres de cada carpeta que hemos fraccionado con ft_split dentro de **dir

5. len: nos va a servir para calcular la longitud de cada directorio que hemos fraccionado + 2 puesto que la estructura del path siempre es '/' + NOMBRE + '/0' (EJ: "/usr")

Tras esto primero silenciamos el warning de minishell poniendolo como void, aseguramos ciertos errores como de costumbre y entramos a la acción.

Primero path lo igualamos a la función getenv("PATH") para conseguir el $PATH 

Segundo dir se iguala a ft_split para hacer lo que hemos dicho antes sobre fraccionar el path.

Después vamos a ir recorriendo con i el array dir para ir entrando en cada carpeta fraccionada con su malloc correspondiente, se calcula el len + 2 de cada carpeta y se le hace una reserva individual a cada carpeta.

Tras esto si hay errores se libera dir y se lanza error, en el caso contrario si access() nos devuelve F_OK (access está en el documento de FUNCTIONS.md, asi que te toca leer), pues nos retornará el nombre del path, previamente generado en la línea anterior en la función ft_creating_cmd_path(), puesto que a medida que le entra carpeta copia y concatena siempre y cuando hayan más carpetas que concatenar.

Si algo falla se acabará liberando dir y cmd_path para lanzar un error.