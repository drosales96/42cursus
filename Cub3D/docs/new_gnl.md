# Estructura General de la Función

Esta implementación de get_next_line se basa en la lectura de un archivo línea por línea. El propósito de esta función es manejar eficientemente la lectura de archivos, como los mapas en proyectos de juegos, procesando cada línea individualmente a medida que es solicitada.
Explicación Detallada de las Funciones

1. ft_gnl_len (longitud de una cadena)
```c
size_t ft_gnl_len(char *str)
{
    size_t i = 0;
    if (!str) 
        return 0;
    while (str[i] != '\0') 
        i++;
    return i;
}
```
    Objetivo: Esta función calcula la longitud de una cadena str.
    Razón: Se utiliza en varias partes del código (por ejemplo, en ft_gnlstrjoin) para determinar el tamaño de las cadenas y manejar las asignaciones de memoria dinámicas.

2. ft_gnl_strchr (búsqueda de un carácter en una cadena)
```c
char ft_gnl_strchr(char *str, int c)
{
    size_t i = 0;
    if (!str) 
        return 0;
    if (c == '\0') 
        return ((char *)&str[ft_gnl_len(str)]);
    while (str[i]) 
    {
        if (str[i] == (char)c) 
            return ((char *)&str[i]);
        i++;
    }
    return 0;
}
```
    Objetivo: Esta función es similar a la función estándar strchr, pero busca un carácter c en la cadena str y devuelve un puntero a la primera aparición.
    Razón: Se utiliza para encontrar el carácter de nueva línea ('\n') que indica el final de una línea. También se usa para gestionar el final de la cadena, en el caso de la búsqueda del '\0'.

3. ft_gnlstrjoin (concatenar dos cadenas)
```c
char *ft_gnlstrjoin(char *str1, char *str2)
{
    size_t  i;
    size_t  j;
    char *end;

    if (!str1) 
    {
        str1 = (char *)malloc(sizeof(char) * 1);
        str1[0] = '\0';
    }
    if (!str2) 
        return (NULL);
    end = (char *)malloc(sizeof(char) * (ft_len(str1) + ft_len(str2) + 1));
    if (end == NULL) 
        return (NULL);
    i = 0;
    j = 0;
    while (str1[i]) 
        end[j++] = str1[i++];
    i = 0;
    while (str2[i]) 
        end[j++] = str2[i++];
    i = 0;
    end[j] = '\0';
    free(str1);
    return end;
}
```
    Objetivo: Esta función concatena dos cadenas (str1 y str2) y retorna una nueva cadena con el resultado.
    Razón: La concatenación es necesaria para almacenar temporalmente el contenido del archivo a medida que se lee. Cuando no se encuentra un salto de línea, los datos se concatenan para formar una cadena más grande.
    Importante: Esta función maneja la memoria de manera cuidadosa, asegurando que el primer puntero (str1) se libere después de la concatenación.

4. ft_alloc (asignación y lectura de bloques)
```c
char *ft_alloc(int fd, char *str)
{
    char    *buff;
    ssize_t len;

    buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buff) 
        return (NULL);
    len = 1;
    while (!(ft_gnlstrchr(str, '\n')) && len > 0) 
    {
        len = read(fd, buff, BUFFER_SIZE);
        if (len == -1) 
        {
            free(buff);
            return (NULL);
        }
        buff[len] = '\0';
        str = ft_gnlstrjoin(str, buff);
    }
    free(buff);
    return (str);
}
```
    Objetivo: Esta función gestiona la lectura del archivo. Lee bloques de datos en un búfer de tamaño BUFFER_SIZE, hasta que encuentra un salto de línea o el final del archivo.
    Razón: Es crucial en get_next_line porque gestiona la lectura de los datos en porciones de tamaño fijo, asegurando que la memoria se maneje de forma eficiente y evitando la sobrecarga de leer carácter por carácter.

5. ft_nline (extraer una línea del contenido leído)
```c
char *ft_nline(char *str)
{
    char *new;
    int i = 0;

    if (str[i] == 0) 
        return (NULL);
    while (str[i] && str[i] != '\n') 
        i++;
    new = (char *)malloc(sizeof(char) * (i + 2));
    if (!new) 
        return (NULL);
    i = 0;
    while (str[i] && str[i] != '\n') 
    {
        new[i] = str[i];
        i++;
    }
    if (str[i] == '\n') 
    {
        new[i] = '\n';
        i++;
    }
    new[i] = '\0';
    return (new);
}
```
    Objetivo: Esta función extrae la siguiente línea de la cadena str, que contiene los datos leídos del archivo.
    Razón: Es esencial para devolver solo una línea de texto en cada llamada a get_next_line.

6. ft_rline (remover la línea extraída del contenido restante)
```c
    char *ft_rline(char *line)
    {
        char *str;
        int i; 
        int j;

        i= 0; 
        j = 0;

        while (line[i] && line[i] != '\n') 
            i++;
        if (!line[i]) 
        {
            free(line);
            return NULL;
        }
        str = (char *)malloc(sizeof(char) * (ft_len(line) - i + 1));
        if (!str) 
            return (NULL);
        i++;
        j = 0;
        while (line[i]) 
            str[j++] = line[i++];
        str[j] = '\0';
        free(line);
        return str;
    }
```
        Objetivo: Elimina la línea que fue extraída (usando ft_nline) del contenido restante de la cadena.
        Razón: Esto asegura que la función get_next_line pueda seguir leyendo la siguiente línea en las futuras llamadas, manteniendo el contenido restante de la cadena para ser procesado.

### Función Principal: get_next_line
```c
char *get_next_line(int fd)
{
    char        *out;
    static char *str;

    if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) == -1) 
    {
        free(str);
        str = NULL;
        return NULL;
    }
    str = ft_alloc(fd, str);
    if (!str) 
        return NULL;
    out = ft_nline(str);
    str = ft_rline(str);
    return out;
}
```
    Objetivo: Esta es la función principal que se utiliza para obtener la siguiente línea de un archivo. Utiliza un búfer estático str para almacenar los datos leídos entre llamadas.
    Razón: El uso de un búfer estático permite que get_next_line mantenga su estado entre invocaciones, lo cual es clave para leer el archivo de manera incremental y devolver una línea cada vez que se llama.
    Manejo de errores: Si hay un error en la lectura del archivo (como un descriptor de archivo no válido), se liberan los recursos y se devuelve NULL.

### En el Contexto de Cub3D

En un proyecto como Cub3D, este código se usa principalmente para:

    Leer el archivo que contiene el mapa 3D del juego, línea por línea.
    Procesar cada línea (que podría representar una fila de un mapa o datos sobre el entorno del juego).
    Interpretar las líneas y convertirlas en elementos que el juego puede usar (paredes, pasillos, posiciones de inicio, etc.).

En resumen, esta implementación de get_next_line es eficiente para gestionar la memoria, leer el archivo de manera incremental y garantizar que se pueda acceder a los datos del archivo en trozos manejables.