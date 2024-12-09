# FUNCIONES PARA FT_CD 

## int ft_cd(t_ast *cmd)

Esta función maneja realmente el comando 'cd' aunque tambien dependa de otras que veremos en breves instantes.

EL parámetro que recibe la función es básicamente el comando ya apuntado por una estrucutra AST que hemos creado (marigome & drosales). EL flujo de trabajo de la función es el siguiente:

1. Utiliza getcwd para almacenar realmente el directorio actual en la variable 'previous_cwd'.

2. Se utiliza getenv() para obtener el valor actual de PWD que más adelante nos será útil.

3. Llamamos a ft_get_cd_path() para obtener la ruta a la que se desea cambiar, y dentro de esta función se determina si volveremos a HOME, a un directorio específico o a OLDPWD.

4. A continuación se llama a ft_chdirectory() para cambiar al directorio.

5. Si el cambio existe, usaremos la función ft_printf_current_cwd() para imprimir el directorio al que hemos cambiado (comportamiento de bash).

6. Con la función ft_update_env_vars() vamos a actualizar las variables de entorno para poder establecer OLDPWD y PWD dentro del sistema.

## const char   *ft_get_cd_path()

Aquí directamente voy a pasar al flujo de trabajo porque a estas alturas debemos saber perfectamente cuales son los parámetros que recibe ya que hemos hecho todas las estructuras con cariño y esfuerzo (si no eres marigome o drosales, ahora te toca estudiar el método que hemos usado para crear todas las estructuras).

1. Primeramente se comprueban los argumentos, y si por ejemplo no los hay, se obtiene y se devuelve el directorio HOME usando la función getenv().

2. Ahora toca manejar el caso de 'cd -' obteniendo el valor de la variable de entorno OLDPWD usando getenv(). En el caso que ya esté definida en el sistema se devuelve, sino devolvemos NULL.

3. Si hay algún argumento diferente a HOME o '-', se devuelve el valor del argumento directamente.

4. El retorno de la función es un puntero a la cadena que representa la ruta a la que se desea cambiar, o NULL si no se ha podido determinar la ruta.

## int  ft_chdirectory()

Aquí el parámetro que recibe la función es el path (ruta del directorio al que se quiere cambiar).

Y su flujo de trabajo es corto y preciso, se retorna el resultado de la función chdir() que nos hará cambiar al directorio deseado.

## int  ft_printf_current_cwd()

Esta funciónm recibe como parámetro el 'previous_cwd' que básicamente es la ruta del directorio anterior, antes del cambio.

Flujo:

1. Se usa getcwd() para obtener el directorio actual.

2. Compara el nuevo directorio con el anterior, y siendo diferentes imprime un mensaje indicando el cambio de path realizado.

3. Retorno de OK (0) si todo ha sido satisfactorio.

## void ft_update_env_vars()

Los parámetros que recibe es el 'OLDPWD' y el 'CWD' que este último sería el directorio actual.

Flujo:

1. Se actualiza el OLDPWD llamando a la función setenv() para establecer OLDPWD con el valor del directorio anterior.

2. Ahora toca actualizar el PWD usando getcwd() para obtener el directorio actual y se establece PWD como variable de entorno usando setenv()

3. NO TIENE RETORNO (VOID)

## FUNCIONALIDADES DE NUESTRO CD

Usos:

1. marigome@drosales:~$ cd
2. marigome@drosales:~$ cd ..
3. marigome@drosales:~$ cd -
4. marigome@drosales:~$ cd --
5. marigome@drosales:~$ cd /home/drosales/Escritorio/Mini_hell [RUTA ABSOLUTA]
6. marigome@drosales:~$ cd ../Escritorio                       [RUTA RELATIVA]