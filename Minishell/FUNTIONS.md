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

readdir() necesitará de una estructura debido a que la función retornará un puntero a
una estructura que contiene información sobre la entrada actual del directorio, como
puede ser su nombre...


