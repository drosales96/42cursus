# Funciones autorizadas para Minishell

## Readline

### readline();

Dentro de Minishell, esta función es útil por ejemplo para recibir comandos que
ingrese el usuario (en vez de usar por ejemplo scanf o fgets...), de hecho se usa
readline() porque además de leer la línea que se ingresa, también permite que se
usen las flechas para que el usuario pueda modificar el comando que pretende
ejecutar directamente en terminal. También, uno de las cosas que incrementa su uso
es que puedes añadir un historial de comandos previamente ejecutados, además de que
permite tener autocompletado de comandos.

También debemos tener en cuenta que esta función interactúa bien con señales como
SIGINT para Ctrl+C, que se usa si se desea interrumpir un comando en ejecución sin
que se llegue a cerrar el Shell.

Ejemplo:

```c
char *input = readline("minishell> ");
if (input && *input) 
{
    add_history(input);  // Agregar comando al historial
    execute_command(input);
}
free(input);
```

Devolverá la línea leída o NULL en el caso de que haya algún error.

### rl_clear_history();

Dentro del contexto de Minishell, esta función nos permitiría crear un comando que
borraría el historial de comandos realizados al terminar o reiniciar el Shell, aun 
existiendo un comando propio en bash como es 'history -c'. También sería muy útil 
cuando queremos manejar errores, por ejemplo, si queremos reiniciar el estado interno 
tras un error crítico o una interrupción usaríamos la función para borrar el historial.

Ejemplo:

```c
int main() {
    // Simulación de un ciclo de shell
    while (1) {
        char *input = readline("minishell> ");
        if (!input)
            break;  // Ctrl+D o EOF
        if (*input)
            add_history(input);

        // Simular un comando "clear_history"
        if (strcmp(input, "clear_history") == 0) 
        {
            rl_clear_history();
            printf("Historial borrado.\n");
        }
        free(input);  // Liberar la memoria de readline
    }
    // Antes de salir, limpiar el historial si es necesario
    rl_clear_history();
    return (0);
}
```

### rl_on_new_line();

Esta función se encarga de actualizar la línea de comandos para que el usuario
pueda seguir introduciendo comandos, en casos como SIGINT (Ctrl+C) o tareas en
segundo plano en el caso que se implementen. Además también se usa si se experi
menta un error durante la entrada del usuario, con el fin de restablecer correc-
tamente la línea de entrada.

Ejemplo:

```c
void handle_sigint(int sig) {
    (void)sig; // Evitar advertencias por argumento sin usar

    // Indicar que queremos comenzar una nueva línea
    rl_on_new_line();

    // Borrar la línea actual
    rl_replace_line("", 0);

    // Forzar la actualización del prompt
    rl_redisplay();
}

int main() {
    // Asignar el manejador de la señal SIGINT
    signal(SIGINT, handle_sigint);

    while (1) {
        // Leer el comando del usuario
        char *input = readline("minishell> ");
        if (!input) {
            // Detectar EOF (Ctrl+D) y salir del loop
            break;
        }

        // Si la entrada no está vacía, agregarla al historial
        if (*input) {
            add_history(input);
        }

        // Simular comando para salir
        if (strcmp(input, "exit") == 0) {
            free(input);
            break;
        }

        // Procesar el comando ingresado
        printf("Ejecutando comando: %s\n", input);

        // Liberar la memoria usada por readline
        free(input);
    }

    return (0);
}
```

### rl_replace_line();

Esta función se va a encargar de reemplazar el contenido de la línea de entrada
de readline(); por una cadena nueva. Esto permite modificar la línea actual del
prompt sin necesidad de realizar nada por parte del usuario, ni si quiera borrar
la línea que ha escrito. En Minishell especialmente se usa para los tres siguientes
casos:

1. Manejor de señales: como por ejemplo SIGINT (Ctrl+C), pues si el usuario inte-
rrumpe el comando debemos limpiar la línea actual para que el shell quede limpio.

2. Autocompletado: si se implementa esta funcionalidad, querremos reemplazar la
línea actual por la línea correctamente autocompletada sin que el usuario lo haga
manualmente. Incluso si el usuario se equivoca en la sintaxis de un comando, podremos
usar la función para corregir el error y mostrar la línea correcta.

3. Cambios de estado en el prompt: si por ejemplo se cambia de directorio (cambio
dinámico del prompt), podrías querer modificar lo que el usuario ve en la línea.

Ejemplo:

```c
// Manejador de señal SIGINT (Ctrl+C)

void handle_sigint(int sig) {
    (void)sig; // Ignorar advertencias por argumento no utilizado

    // Reemplazar la línea con una cadena vacía
    rl_replace_line("", 0);

    // Redisplay del prompt después de borrar la línea
    rl_redisplay();
}

int main() {
    // Configurar el manejador de la señal Ctrl+C
    signal(SIGINT, handle_sigint);

    while (1) {
        // Leer el comando del usuario
        char *input = readline("minishell> ");
        if (!input) {
            // Detectar EOF (Ctrl+D) y salir
            break;
        }

        // Si la entrada no está vacía, agregarla al historial
        if (*input) {
            add_history(input);
        }

        // Simular un comando 'exit' para salir
        if (strcmp(input, "exit") == 0) {
            free(input);
            break;
        }

        // Procesar el comando ingresado
        printf("Ejecutando comando: %s\n", input);

        // Liberar la memoria asignada por readline
        free(input);
    }
    return (0);
}
```

### rl_redisplay_line();

Esta función forzaría a readline, a actualizar el contenido de la línea de com-
andos y el prompt en la terminal, cuando por ejemplo ocurre un cambio en la
entrada de línea por editarla (el USER), o porque el Shell modifique su contenido
internamente.

Casos en los que se usa esta función en Minishell:

1. Menejo de señales: al llegar la señal SIGINT es común borrar la línea actual
y mostrar un nuevo prompt limpio para que el usuario pueda reanudar un comando, pues
es ahí donde usaremos la función para forzar al prompt y a la línea a que se
actualicen.

2. Después de modificar la línea con rl_replace_line: necesitarás
llamar sí o sí a la función rl_redisplay_line() para asegurarte de que el nuevo
contenido se vea en pantalla.

3. Uso de prompt dinámico: si por ejemplo se muestra información del directorio o el
estado del usuario, se podría necesitar la función para que el nuevo prompt se muestre
automáticamente.

4. Manejo de salida asíncrona: hay situaciones donde el shell recive eventos asíncronos,
como mensajes de fondo o notificaciones de trabajos en segundo plano. Aquí la función
puede ser útil para redibujar el prompt después de la impresión de dichos mensajes,
asegurando así que la línea de comandos no se sobreescriba o quede desordenada.

Ejemplo:

```c
// Manejador de la señal SIGINT (Ctrl+C)
void handle_sigint(int sig) {
    (void)sig;  // Evitar advertencias por no usar el parámetro

    // Reemplazar la línea actual con una vacía
    rl_replace_line("", 0);

    // Redibujar el prompt con la línea vacía
    rl_redisplay();
}

int main() {
    // Configurar el manejador para SIGINT (Ctrl+C)
    signal(SIGINT, handle_sigint);

    while (1) {
        // Leer el comando del usuario con readline
        char *input = readline("minishell> ");
        if (!input) {
            // Detectar EOF (Ctrl+D) y salir del loop
            break;
        }

        // Si la entrada no está vacía, agregarla al historial
        if (*input) {
            add_history(input);
        }

        // Simular un comando 'exit' para salir del minishell
        if (strcmp(input, "exit") == 0) {
            free(input);
            break;
        }

        // Procesar el comando ingresado
        printf("Ejecutando comando: %s\n", input);

        // Liberar la memoria asignada por readline
        free(input);
    }
    return (0);
}
```

### add_history();

Esta función agrega la línea de entrada actual al historial de comandos 
gestionado por readline. De este modo, cada vez que el usuario ingresa 
un comando, este se guarda y luego puede ser recordado y reutilizado por 
el usuario sin tener que volver a escribirlo.

Ejemplo:

```c
int main() {
    while (1) {
        // Leer el comando del usuario
        char *input = readline("minishell> ");
        if (!input) {
            // Detectar EOF (Ctrl+D) y salir
            break;
        }

        // Si la entrada no está vacía, agregarla al historial
        if (strlen(input) > 0) {
            add_history(input);
        }

        // Simular un comando 'exit' para salir del minishell
        if (strcmp(input, "exit") == 0) {
            free(input);
            break;
        }

        // Procesar el comando ingresado
        printf("Ejecutando comando: %s\n", input);

        // Liberar la memoria asignada por readline
        free(input);
    }
    return (0);
}
```

Hay una curiosidad y es que si queremos guardar el historial de comandos en un
.txt, podriamos hacerlo añadiendo la función write_history() antes de retornar
0 en nuestro main. [VERIFICAR QUE SE PUEDA USAR]

## Gestión de archivos

### access();

La función access() se utiliza para comprobar los permisos de acceso a archivos o directorios. En el contexto de un minishell, es especialmente útil para verificar si un comando se puede ejecutar, si un archivo existe o si el usuario tiene permiso para leer o escribir en un archivo.

Tiene diferentes banderas para verificar permisos:

1. R_OK : archivo legible.
2. W_OK : archivo escribible.
3. X_OK : archivo ejecutable.
4. F_OK : archivo existente.

Dentro de Minishell puede tener dos diferentes usos:

1. Verificación de comandos: por ejemplo podemos usar access() para verificar si se
encuentra en el sistema el ejecutable a usar y si el usuario tiene permisos para poder
ejecutarlo.

2. Verificación de archivos: al manejar redirecciones o archivos de entrada o salida,
se puede usar access() para asegurarnos de que dichos archivos existen y que además te-
nemos permisos para usarlos.

Ejemplo:

```c
int main() {
    const char *command = "/bin/ls";  // Ruta al comando
    // Verificar si el comando es ejecutable
    if (access(command, X_OK) == 0) {
        printf("El comando '%s' es ejecutable.\n", command);
    } else {
        printf("Error: El comando '%s' no se puede ejecutar. %s\n", command, strerror(errno));
    }
    return (0);
}
```

### unlink();

En minshell podrían existir dos tipos de usos de esta función y estos son:

1. Eliminar archivos: podríamos querer que el usuario elimine archivos indicados por
el mismo mediante un comando específico.

2. Verificación previa: al intentar eliminar un archivo, es importante verificar si el
archivo existe y si el usuario tiene los permisos para poder eliminarlo.

Ejemplo:

```c
int main() {
    const char *filename = "archivo_a_eliminar.txt"; // Archivo a eliminar

    // Intentar eliminar el archivo
    if (unlink(filename) == 0) {
        printf("El archivo '%s' ha sido eliminado.\n", filename);
    } else {
        printf("Error: No se pudo eliminar el archivo '%s'. %s\n", filename, strerror(errno));
    }
    return (0);
}
```
Dentro de un Minishell se podría integrar de la siguiente manera:

```c
int main() {
    char command[256];

    while (1) {
        printf("minishell> ");
        if (!fgets(command, sizeof(command), stdin)) {
            break;  // Manejo de EOF (Ctrl+D)
        }

        // Eliminar el salto de línea
        command[strcspn(command, "\n")] = 0;

        // Comprobar si el comando es 'exit'
        if (strcmp(command, "exit") == 0) {
            break;
        }

        // Intentar eliminar el archivo si el comando es 'rm'
        if (strncmp(command, "rm ", 3) == 0) {
            const char *filename = command + 3; // Obtener el nombre del archivo
            filename[strcspn(filename, "\n")] = 0; // Eliminar salto de línea

            // Intentar eliminar el archivo
            if (unlink(filename) == 0) {
                printf("El archivo '%s' ha sido eliminado.\n", filename);
            } else {
                printf("Error: No se pudo eliminar el archivo '%s'. %s\n", filename, strerror(errno));
            }
        } else {
            printf("Comando no reconocido: %s\n", command);
        }
    }
    return (0);
}
```
### opendir(); || readdir(); || closedir();

Básicamente como sus nombres indican son funciones para gestionar la info de un
directorio. opendir() se encarga de abrir un directorio, readdir() de leerlo y por
último closedir() de cerrarlo.

Ejemplo de implementación en Minishell:

```c
int main() {
    char command[256];

    while (1) {
        printf("minishell> ");
        if (!fgets(command, sizeof(command), stdin)) {
            break;  // Manejo de EOF (Ctrl+D)
        }

        // Eliminar el salto de línea
        command[strcspn(command, "\n")] = 0;

        // Comprobar si el comando es 'exit'
        if (strcmp(command, "exit") == 0) {
            break;
        }

        // Comprobar si el comando es 'ls'
        if (strcmp(command, "ls") == 0) {
            DIR *dir;
            struct dirent *entry;

            // Abrir el directorio actual
            dir = opendir(".");
            if (dir == NULL) {
                perror("Error al abrir el directorio");
                continue;
            }

            // Leer y listar el contenido del directorio
            while ((entry = readdir(dir)) != NULL) {
                // Ignorar '.' y '..'
                if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                    printf("%s\n", entry->d_name);
                }
            }

            // Cerrar el directorio
            if (closedir(dir) == -1) {
                perror("Error al cerrar el directorio");
            }
        } else {
            printf("Comando no reconocido: %s\n", command);
        }
    }
    return (0);
}
```

readdir() necesitará de una estructura debido a que la función retornará un 
puntero a una estructura que contiene información sobre la entrada actual 
del directorio, como puede ser su nombre...

## Funciones de procesos

### fork();

Esta función hará una llamada al sistema que creará un proceso hijo que básica-
mente es un duplicado del proceso padre (el abierto inicialmente), que además
posee su memoria propia para ejecutar sus propios comandos sin interferir en el
proceso padre. 

Dentro de Minishell fork() es útil pues permite que los comandos a ejecutar que
mete el usuario, se ejecuten en segundo plano en el proceso hijo, mientras el
proceso padre espera a que termine. Esto conseguirá que después de ejecutar co-
mandos, el shell (padre) seguirá siendo interactivo después de la ejecución de
cualquier comando.

Un ejemplo podría ser el comando 'ls -l', lo que haríamos sería llamar a fork(),
para crear el proceso hijo. Si es exitoso nuestro fork(), el proceso padre nos va
a proporcionar el PID del proceso hijo, y el proceso hijo devuelve '0'.

Mediante otra función [execve], haremos que el hijo ejecute el comando que
se introduce por shell padre, y mientras se ejecuta, el padre (MINISHELL) nece-
sitará del uso de wait() o  waitpid() para esperar a que el hijo termine, y así
el padre podrá futuramente seguir esperando comandos.

Ejemplo:

```c
pid_t pid = fork();

if (pid == 0)
{
    // Este es el proceso hijo
    char *args[] = {"/bin/ls", "-l", NULL};
    execve("/bin/ls", args, envp);  // Reemplaza el proceso hijo con el comando
    perror("execve");  // Si execve falla
    exit(EXIT_FAILURE);
} else if (pid > 0) 
{
    // Este es el proceso padre
    int status;
    waitpid(pid, &status, 0);  // Espera a que el hijo termine
} else {
    // Error al hacer fork
    perror("fork");
}
```

### wait(); || waitpid(); || wait3(); || wait4();

1. wait() : Función con la que el proceso padre puede esperar a que CUALQUIER
proceso hijo acabe, sin importar cual.

```c
pid_t wait(int *status);
```

2. waitpid() : Función que hace la misma función que wait(), solo que puedes
especificar el PID concreto del hijo al que quieres esperar que acabe.

```c
pid_t waitpid(pid_t pid, int *status, int options);
```

3. wait3() : Hace lo mismo que wait(),  pero permite recuperar estadísticas de
uso de recursos como tiempo de CPU y memoria. Espera de igual manera que wait() 
a cualquier hijo, y además devuelve información adicional a través de la 'struct'
'rusage'.

```c
pid_t wait3(int *status, int options, struct rusage *rusage);
```

4. wait4() : Es una combinación de waitpid() y wait3(). Te permite esperar a un 
proceso hijo específico como waitpid(), y además obtener estadísticas de uso de 
recursos como wait3().

```c
pid_t wait4(pid_t pid, int *status, int options, struct rusage *rusage);
```
### execcve();

Esta función depende de la creación del proceso hijo (usando fork()), pues lo
que hace es reemplazar la imagen actual (hijo) por la de un programa ejecutable
que seguramente será el comando que queremos que se ejecute tras ser introducido
por el usuario.

Si todo sale bien, execve() no retorna SUCCESS sino que solamente adquiere valor de
retorno '-1' si hay fallo.

Sintaxis:

```c
int execve(const char *pathname, char *const argv[], char *const envp[]);
```
Detalles:

1. pathname : Ruta del archivo ejecutable que queremos correr, por ejemplo en el
caso de 'ls', será 'bin/ls'.

2. argv : Array de cadenas de texto que representan los argumentos que se pasan
al programa. EL primer argumento suele ser el nombre del programa [argv[0]].

3. envp[] : Array de cadenas de texto que representan las *variables de entorno*
que se pasan al programa.

Caso en Minishell:

```c
int main(int argc, char *argv[], char *envp[]) {
    pid_t pid = fork();  // Crea un proceso hijo

    if (pid == 0) 
    {
        // Proceso hijo
        char *args[] = {"/bin/ls", "-l", NULL};  // Programa y argumentos
        execve("/bin/ls", args, envp);           // Reemplaza el proceso hijo con 'ls'
        
        // Si execve falla:
        perror("execve failed");
        exit(EXIT_FAILURE);
    } 
    else if (pid > 0) 
    {
        // Proceso padre
        int status;
        waitpid(pid, &status, 0);  // Espera que el proceso hijo termine
    } 
    else
        // Error en fork
        perror("fork failed");
    return (0);
}
```

Cosas a tener en cuenta:

1. Antes de llamar a execve(), el shell debe manejar las redirecciones (>, <, |) modificando los descriptores de archivo. Esto se puede hacer con las funciones dup2() y pipe().

2. Por ejemplo, si el usuario escribe ls > output.txt, el shell debe redirigir la salida estándar (stdout) del proceso hijo para que escriba en el archivo output.txt en lugar de en la terminal.

### pipe();

Primeramente debemos saber que un 'pipe' es un mecanismo que conecta dos procesos,
permitiendo que el proceso escriba datos en el 'pipe' y que el proceso B lea esos
datos que hay en el 'pipe'. En el caso de Minishell, cuando el usuario ingresa un
comando con |, se deben crear dos procesos (uno para cada comando) y establecer
una comunicación entre ellos mediante un pipe. Esto se hace con la función pipe() 
y redirigiendo los descriptores de archivo adecuados.

Esta función crea un canal unidireccional de comunicación entre los procesos, y su
sintaxis sería así:

```c
int pipe(int pipefd[2]);
```
1. pipefd[] : es un array de enteros que contiene dos [fd] que son el 0 (para leer
del pipe) y 1 (para escribir en el).

En Minishell, podriamos usar pipe, en comandos como 'ls | grep .txt', ya que 'ls'
se ejecuta y su salidad estandar se redirige al pipe, y 'grep' lee la info de ese
pipe como si fuera su salida estandar.

Un ejemplo bastante claro sería:

```c
int main(int argc, char *argv[], char *envp[]) {
    int pipefd[2];    // Array para los descriptores de archivo del pipe
    pid_t pid1, pid2;

    if (pipe(pipefd) == -1) 
    {
        perror("pipe failed");
        exit(EXIT_FAILURE);
    }

    // Primer hijo (ejecuta "ls")
    pid1 = fork();
    if (pid1 == -1) 
    {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }

    if (pid1 == 0) 
    {
        // En el hijo 1 (ejecutar "ls")
        close(pipefd[0]);              // Cerramos el extremo de lectura del pipe
        dup2(pipefd[1], STDOUT_FILENO); // Redirigimos stdout al extremo de escritura del pipe
        close(pipefd[1]);              // Cerramos el extremo de escritura del pipe

        // Ejecutar "ls"
        char *args[] = {"/bin/ls", NULL};
        execve("/bin/ls", args, envp);

        // Si execve falla
        perror("execve failed");
        exit(EXIT_FAILURE);
    }

    // Segundo hijo (ejecuta "grep txt")
    pid2 = fork();
    if (pid2 == -1) 
    {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }

    if (pid2 == 0) 
    {
        // En el hijo 2 (ejecutar "grep txt")
        close(pipefd[1]);              // Cerramos el extremo de escritura del pipe
        dup2(pipefd[0], STDIN_FILENO); // Redirigimos stdin al extremo de lectura del pipe
        close(pipefd[0]);              // Cerramos el extremo de lectura del pipe

        // Ejecutar "grep txt"
        char *args[] = {"/bin/grep", "txt", NULL};
        execve("/bin/grep", args, envp);

        // Si execve falla
        perror("execve failed");
        exit(EXIT_FAILURE);
    }

    // En el proceso padre (Minishell)
    close(pipefd[0]); // Cerramos ambos extremos del pipe
    close(pipefd[1]);

    // Esperamos a que los hijos terminen
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
    return (0);
}
```
En este código podemos ver como primero se crea el pipe para tener un canal de co-
municación entre ambos procesos. Después en el proceso hijo (comando) se cierra el
extremo de lectura del pipe, se redirige la salida estandar al pipe usando la fun-
ción dup2() [futuramente la veremos] y se acaba ejecutando el comando que se intro-
duce por shell (usando la función ya vista execve()).

Después en el segundo proceso hijo se cierra el extremo de lectura del pipe y se
redirige a la salida estandar.

PRIMER HIJO = 'ls'
SEGUNDO HIJO = 'grep'

## Funciones del sistema de archivos

### getcwd(); || chdir();

La función getcwd() se encarga de proporcionarnos la ruta absoluta sobre la que se
encontrará el usuario (básicamente proporciona lo que da el comando 'pwd' en shell)

Para usarla se necesitará un buffer donde almacenar la ruta, buffer que puede ser
de memoria dinámica o de memoria con tamaño fijo.

Se usaría de la siguiente manera:

```c

void print_working_directory() 
{
    char cwd[1024];  // Buffer para almacenar la ruta

    // Llamada a getcwd() para obtener el directorio actual
    if (getcwd(cwd, sizeof(cwd)) != NULL)
        printf("%s\n", cwd);  // Imprimir el directorio actual
    else
        perror("getcwd() error");  // Imprimir el error si falla
}

int main() {
    // Simula el comportamiento del comando 'pwd'
    print_working_directory();
    return (0);
}
```

Ahora pasamos a chdir(), que básicamente es la función que nos permitirá repl-
icar el comando 'cd' para cambiar de directorio.

En Minishell lo que haremos será parsear el comando 'cd' para obtener la ruta
a la que el usuario quiere cambiar, y después se llamará a chdir() para ello,
además justo depués habrá que actualizar la variable de entorno PWD para poder
reflejar el nuevo directorio (imagino que con getcwd()).

Implementación en un Minishell:

```c
void change_directory(const char *path) {
    // Verificar si se proporciona una ruta
    if (path == NULL) 
    {
        // Si no se proporciona ninguna ruta, normalmente se cambiaría al home directory
        // Esto puede obtenerse con getenv("HOME")
        const char *home = getenv("HOME");
        if (home == NULL) 
        {
            fprintf(stderr, "No home directory found\n");
            return;
        }
        path = home;
    }

    // Intentar cambiar de directorio usando chdir()
    if (chdir(path) == 0) 
    {
        // Si chdir tiene éxito, actualizar la variable PWD
        char cwd[1024];
        if (getcwd(cwd, sizeof(cwd)) != NULL)
            setenv("PWD", cwd, 1);  // Actualizar PWD en las variables de entorno
        else 
            perror("getcwd() error");
    } 
    else 
        // Si chdir falla, imprimir el error
        fprintf(stderr, "cd: %s: %s\n", path, strerror(errno));
}

int main(int argc, char *argv[]) 
{
    // Simular un comando 'cd' con el primer argumento
    if (argc > 1) {
        change_directory(argv[1]);
    } else {
        // Si no se pasa ningún argumento, se cambia al home directory
        change_directory(NULL);
    }

    return (0);
}
```

Cosideraciones que tener en cuenta:

1. cd < vacío > : Si el usuario escribe solo 'cd' debemos irnos al directorio de
inicio del usuario (normalmente con la función getenv("HOME")).

2. cd - : Debemos cambiar al directorio anterior (posiblemente almacenado en la
variable de entorno OLDPWD). Hay que tener en cuenta que el valor actual de PWD
se guardará en OLDPWD antes de llamar a chdir() para cambiar de directorio. Y
después se deben actualizar tanto PWD como OLDPWD.

Ejemplo del caso 'cd -' :

```c
const char *oldpwd = getenv("OLDPWD");
if (oldpwd != NULL) 
{
    chdir(oldpwd);
    printf("%s\n", oldpwd);  // Imprime el directorio al que se cambió
    setenv("OLDPWD", getenv("PWD"), 1);
    setenv("PWD", oldpwd, 1);
} 
else
    fprintf(stderr, "OLDPWD not set\n");
```
3. Error al cambiar de 'dir' : si chdir() falla por alguna razón hay que mostrar un
mensaje de error claro, como por ejemplo usando stderror(errno), que nos permitirá
obtener una descripción del error basado en el código.

Ejemplo:

```c
if (chdir(path) == -1) 
    fprintf(stderr, "cd: %s: %s\n", path, strerror(errno));
```
### stat(); || lstat(); || fstat();

La función stat recopila información sobre un archivo o directorio, almacenando
los resultados en una estructura de tipo struct stat. En Minishell, se puede
utilizar para verificar si un archivo existe, conocer el tipo de archivo (por
ejemplo, si es un archivo regular o un directorio), y obtener otros metadatos
como permisos, tamaño y fechas de modificación.

Sintaxis:

```c
int stat(const char *pathname, struct stat *statbuf);
```
1. pathname : ruta del archivo o directorio.

2. statbuf : puntero a una estructura 'stat' donde se alamcenará la info.

Dentro de esa estructura de info podriamos ver:

```c
struct stat {
    dev_t     st_dev;     // ID del dispositivo
    ino_t     st_ino;     // Número de inodo
    mode_t    st_mode;    // Tipo de archivo y permisos
    nlink_t   st_nlink;   // Número de enlaces duros
    uid_t     st_uid;     // ID del propietario
    gid_t     st_gid;     // ID del grupo
    dev_t     st_rdev;    // ID del dispositivo (si es especial)
    off_t     st_size;    // Tamaño del archivo en bytes
    blksize_t st_blksize; // Tamaño de bloque preferido para I/O
    blkcnt_t  st_blocks;  // Número de bloques asignados
    time_t    st_atime;   // Último acceso
    time_t    st_mtime;   // Última modificación
    time_t    st_ctime;   // Último cambio de estado
};
```

En Minishell su uso común suele ser en comandos como 'ls' para obtener info
detallada de un archivo o directorio, de la siguiente manera se podría im-
plementar en un shell:

```c
void print_file_info(const char *filename) {
    struct stat fileStat;

    // Llamada a stat() para obtener información del archivo
    if (stat(filename, &fileStat) < 0) {
        // Si stat() falla, imprimir el error
        fprintf(stderr, "Error: %s: %s\n", filename, strerror(errno));
        return;
    }

    // Imprimir información básica del archivo
    printf("Archivo: %s\n", filename);
    printf("Tamaño: %ld bytes\n", fileStat.st_size);
    printf("Permisos: %o\n", fileStat.st_mode & 0777);  // Permisos en formato octal
    printf("Última modificación: %ld\n", fileStat.st_mtime);

    // Comprobar si es un directorio
    if (S_ISDIR(fileStat.st_mode)) {
        printf("Es un directorio\n");
    } else if (S_ISREG(fileStat.st_mode)) {
        printf("Es un archivo regular\n");
    } else {
        printf("Es otro tipo de archivo\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Uso: %s <archivo>\n", argv[0]);
        return 1;
    }

    // Obtener información del archivo pasado como argumento
    print_file_info(argv[1]);

    return 0;
}
```

Algunas macros utiles para la funcion stat() pueden ser:

1. S_ISREG(st_mode): Verifica si es un archivo regular.
2. S_ISDIR(st_mode): Verifica si es un directorio.
3. S_ISCHR(st_mode): Verifica si es un dispositivo de carácter.
4. S_ISBLK(st_mode): Verifica si es un dispositivo de bloque.
5. S_ISFIFO(st_mode): Verifica si es un archivo FIFO (pipe con nombre).
6. S_ISLNK(st_mode): Verifica si es un enlace simbólico.
7. S_ISSOCK(st_mode): Verifica si es un socket.

Ahora le toca a la función lstat(), que básicamente se parece mucho a la
anterior...

La diferencia entre una y otra es que lstat() si te proporcionará info sobre
enlaces simbólicos o incluso verificará la existencia de estos, por lo que
será realmente útil en comandos como 'ls -l'. Además las funciones que estamos
viendo (stat, lstat y fstat) comparte la misma estructura donde se almacena la
información.

Ejemplo de implementación:

```c
void print_file_info(const char *filename) {
    struct stat fileStat;

    // Llamada a lstat() para obtener información del archivo o enlace simbólico
    if (lstat(filename, &fileStat) < 0) {
        // Si lstat() falla, imprimir el error
        fprintf(stderr, "Error: %s: %s\n", filename, strerror(errno));
        return;
    }

    // Imprimir información básica del archivo o enlace simbólico
    printf("Archivo: %s\n", filename);
    printf("Tamaño: %ld bytes\n", fileStat.st_size);
    printf("Permisos: %o\n", fileStat.st_mode & 0777);  // Permisos en formato octal
    printf("Última modificación: %ld\n", fileStat.st_mtime);

    // Comprobar si es un enlace simbólico, archivo regular o directorio
    if (S_ISLNK(fileStat.st_mode)) {
        printf("Es un enlace simbólico\n");
    } else if (S_ISDIR(fileStat.st_mode)) {
        printf("Es un directorio\n");
    } else if (S_ISREG(fileStat.st_mode)) {
        printf("Es un archivo regular\n");
    } else {
        printf("Es otro tipo de archivo\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Uso: %s <archivo>\n", argv[0]);
        return 1;
    }

    // Obtener información del archivo o enlace simbólico pasado como argumento
    print_file_info(argv[1]);

    return 0;
}
```

En esta función también puedes y debes usar las macros anteriormente mencionadas.

La función fstat() permite obtener información detallada sobre un archivo abierto,
como su tamaño, permisos, tipo y otras propiedades, utilizando el descriptor de
archivo. Esta función es particularmente útil en situaciones donde ya se tiene
un archivo abierto y se desea obtener información adicional sin necesidad de
volver a abrirlo.

Sintaxis:

```c
int fstat(int fd, struct stat *statbuf);
```

Los usos más comunes en Minishell pueden ser:

1. Comandos que Procesan Archivos Abiertos: Cuando se manipulan archivos
abiertos, como al redirigir la entrada o salida de un comando, se puede usar 
fstat() para obtener información sobre el archivo al que se ha redirigido.

2. Verificación de Propiedades de Archivos: Se puede utilizar fstat() para
verificar el tipo de archivo y sus permisos sin necesidad de volver a abrir 
el archivo.

3. Comando cat o head: Al implementar comandos que procesan archivos, como 
cat o head, puedes usar fstat() para verificar propiedades del archivo antes
de realizar la lectura.

Ejemplo:

```c
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

void print_file_info(int fd) {
    struct stat fileStat;

    // Llamada a fstat() para obtener información del archivo asociado al descriptor
    if (fstat(fd, &fileStat) < 0) {
        // Si fstat() falla, imprimir el error
        fprintf(stderr, "Error: fstat: %s\n", strerror(errno));
        return;
    }

    // Imprimir información básica del archivo
    printf("Tamaño: %ld bytes\n", fileStat.st_size);
    printf("Permisos: %o\n", fileStat.st_mode & 0777);  // Permisos en formato octal
    printf("Última modificación: %ld\n", fileStat.st_mtime);

    // Comprobar si es un archivo regular o directorio
    if (S_ISDIR(fileStat.st_mode)) {
        printf("Es un directorio\n");
    } else if (S_ISREG(fileStat.st_mode)) {
        printf("Es un archivo regular\n");
    } else {
        printf("Es otro tipo de archivo\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Uso: %s <archivo>\n", argv[0]);
        return 1;
    }

    // Abrir el archivo para obtener su descriptor
    int fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        fprintf(stderr, "Error: open: %s\n", strerror(errno));
        return 1;
    }

    // Obtener información del archivo usando fstat
    print_file_info(fd);

    // Cerrar el descriptor de archivo
    close(fd);

    return 0;
}
```

## Redirección de archivos

### dup(); || dup2();

La función dup() se utiliza para duplicar un descriptor de archivo
existente y devuelve un nuevo descriptor que es una copia del
original. El nuevo descriptor será el menor número entero de
descriptor disponible.

Sintaxis:

```c
int dup(int oldfd);
```

1. oldf : fd existente que se quiere duplicar.

Ejemplo:

```c
int main() {
    int fd = open("file.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    int new_fd = dup(fd); // Duplica fd
    if (new_fd < 0) {
        perror("dup");
        return 1;
    }

    // Ahora puedes usar new_fd para escribir en el mismo archivo
    write(new_fd, "Hello, World!\n", 14);

    // Cerrar los descriptores
    close(fd);
    close(new_fd);

    return 0;
}
```

La función dup2() también se utiliza para duplicar descriptores de
archivo, pero permite especificar el descriptor de archivo que se
desea sobrescribir. Si el descriptor de destino ya está abierto, se
cierra antes de ser sobrescrito.

Sintaxis: 

```c
int dup2(int oldfd, int newfd);
```

1. oldfd : fd actual que se quiere duplicar.
2. newfd : el fd al que expresamente se quiere copiar el oldfd

Ejemplo: 

```c
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main() {
    int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    // Redirigir stdout (descriptor 1) a fd
    if (dup2(fd, STDOUT_FILENO) < 0) {
        perror("dup2");
        return 1;
    }

    // Ahora cualquier salida que vaya a stdout se escribirá en output.txt
    printf("Este texto irá a output.txt\n");

    // Cerrar el descriptor original
    close(fd);

    return 0;
}
```

El uso de ambas funciones en Minishell puede ser:

1. dup() : Usado en situaciones donde necesitas múltiples descriptores
para el mismo archivo, como en tuberías, donde puedes querer tener un
descriptor para leer y otro para escribir.

2. dup2() : Comúnmente utilizado para redirigir la salida estándar o
la entrada estándar a un archivo o a otro descriptor, facilitando la
implementación de comandos que requieren redirección, como ls > output.
txt o cat < input.txt.


# Flujo General del Proyecto Minishell

## 1. Inicialización
- **Configuración Inicial:**
  - Configurar el entorno del shell (variables de entorno, manejar la entrada y salida estándar).
  - Inicializar cualquier estructura de datos necesaria (por ejemplo, lista de historial de comandos).
- **Manejo de Señales:**
  - Configurar manejadores de señales (como `SIGINT`, `SIGQUIT`) para permitir la interrupción adecuada de procesos.

## 2. Bucle Principal del Shell
- **Mostrar el Prompt:**
  - Mostrar el prompt para indicar que el shell está listo para recibir un comando.
- **Lectura de Entrada:**
  - Utilizar `readline` para leer el comando ingresado por el usuario.
  - Usar `add_history` para agregar el comando al historial.

## 3. Análisis del Comando
- **Tokenización:**
  - Separar el comando y sus argumentos (tokens) utilizando espacios y otros delimitadores.
- **Manejo de Redirecciones y Tuberías:**
  - Detectar si el comando incluye redirecciones (como `>`, `<`) y tuberías (`|`).
  - Crear un árbol de procesos si hay múltiples comandos encadenados por tuberías.

## 4. Ejecutar el Comando
- **Crear Procesos:**
  - Utilizar `fork()` para crear un nuevo proceso para ejecutar el comando.
- **Redirección de Entrada/Salida:**
  - Usar `dup()` o `dup2()` para redirigir la entrada/salida según sea necesario (por ejemplo, redirigir `stdout` a un archivo).
- **Ejecutar el Comando:**
  - Usar `execve()` para reemplazar el proceso hijo con el comando especificado.
- **Esperar a que el Proceso Termine:**
  - Usar `wait()` o `waitpid()` para esperar que el proceso hijo termine y manejar su estado de salida.

## 5. Manejo de Errores
- **Errores de Ejecución:**
  - Si `execve()` falla, manejar el error e imprimir un mensaje apropiado (usando `perror()`).
- **Comandos no Encontrados:**
  - Verificar si el comando existe en el sistema y, si no, imprimir un mensaje de error adecuado.

## 6. Finalización del Proceso
- **Liberar Recursos:**
  - Liberar memoria, cerrar descriptores de archivos abiertos, etc.
- **Finalizar el Shell:**
  - Permitir que el usuario salga del shell con un comando como `exit` y realizar una limpieza final.


```mermaid
graph TD;
    A[Inicialización] --> B[Bucle Principal del Shell];
    B --> C[Lectura de Entrada];
    B --> D[Análisis del Comando];
    D --> E[Tokenización];
    D --> F[Manejo de Redirecciones y Tuberías];
    B --> G[Ejecución];
    G --> H[Crear Procesos];
    G --> I[Redirección de Entrada/Salida];
    G --> J[Ejecutar el Comando];
    G --> K[Esperar a que el Proceso Termine];
    B --> L[Manejo de Errores];
    B --> M[Finalización del Proceso];
