# Documentación de la Función ft_mapping y Funciones Auxiliares

Este documento explica la función principal ft_mapping y las funciones asociadas que se utilizan en el flujo de lectura y procesamiento del mapa dentro del proyecto. Estas funciones forman parte del manejo del mapa en un juego tipo Cub3D.
## 1. Función ft_mapping
```c
int	ft_mapping(t_cub3d *cub, int fd)
{
	char	*lines;
	char	*map;

	lines = NULL;
	map = NULL;
	lines = get_next_line(fd);
	if (!lines)
		return (ft_manage_err(READ_ERR), EXIT_FAILURE);
	map = ft_matrix_to_str(lines, fd);
	if (!map)
		return (ft_manage_err(MATRIX_TO_STR_ERR), EXIT_FAILURE);
	map = ft_strtrim(map, "\n");
	if (!map)
		return (ft_manage_err(FT_STRTRIM_ERR), EXIT_FAILURE);
	if (ft_map_spliting(cub, map))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
```
### Propósito:

La función ft_mapping se encarga de leer el mapa del archivo, convertirlo a una cadena de caracteres, eliminar saltos de línea innecesarios y luego dividirlo en líneas para su posterior procesamiento. Si ocurre cualquier error en el proceso, se maneja y se devuelve EXIT_FAILURE.
Flujo de la Función:

    Lectura de líneas:
    Llama a get_next_line(fd) para leer la primera línea del archivo.
    Conversión a cadena:
    Usa ft_matrix_to_str() para leer todas las líneas y concatenarlas en una sola cadena.
    Eliminación de saltos de línea:
    Aplica ft_strtrim() para eliminar los saltos de línea al principio y al final de la cadena.
    División del mapa:
    Llama a ft_map_spliting() para dividir la cadena en líneas y almacenarlas en la estructura cub.

Si alguna de las operaciones falla, se devuelve EXIT_FAILURE.

## 2. Función ft_checking_lines
```c
int	ft_checking_lines(char	*map)
{
	int	i;

	if (!map || !map[0])
		return (ft_manage_err(MAP_ERR), EXIT_FAILURE);
	i = 0;
	while (map[i])
	{
		if (map[i] == '\n')
		{
			i++;
			while (map[i] == ' ')
				i++;
			if (map[i] == '\n' || map[i] == '\0')
				return (ft_manage_err(EXTRA_LINE_ERR), EXIT_FAILURE);
		}
		else
			i++;
	}
	return (EXIT_SUCCESS);
}
```
### Propósito:

Esta función verifica si el mapa tiene líneas vacías o líneas extra que no deberían existir, lo que podría indicar un error en la estructura del mapa.
Flujo de la Función:

    Se recorre la cadena de texto que representa el mapa.
    Si se encuentra un salto de línea (\n), verifica si hay espacios innecesarios o saltos de línea consecutivos (\n\n).
    Si encuentra un salto de línea extra o innecesario, devuelve un error.

## 3. Función ft_matrix_to_str
```c
char	*ft_matrix_to_str(char	*c, int fd)
{
	char	*map;

	map = NULL;
	while (c)
	{
		if (!c)
			return (ft_manage_err(READ_ERR), NULL);
		map = ft_new_strjoin(map, c);
		if (!map)
			return (ft_manage_err(MATRIX_TO_STR_ERR), NULL);
		c = get_next_line(fd);
	}
	return (map);
}
```
### Propósito:

Convierte el contenido del archivo (leído línea por línea) en una única cadena que representa el mapa completo.
Flujo de la Función:

    Llama a get_next_line(fd) para leer cada línea del archivo.
    Usa ft_new_strjoin() para concatenar cada línea al mapa.
    Si ocurre un error en el proceso de concatenación, maneja el error y retorna NULL.

## 4. Función ft_new_strjoin

```c
char	*ft_new_strjoin(char const *s1, char const *s2)
{
	size_t		totallen;
	char		*buffer;

    if (!s2)
        return (s1);
    if (!s1)
        return (ft_strdup(s2));
	totallen = ft_strlen(s1) + ft_strlen(s2);
	buffer = (char *)malloc(sizeof(char) * (totallen + 1));
	if (!buffer)
		return (NULL);
	ft_memcpy(buffer, s1, ft_strlen(s1));
    ft_memcpy(buffer + ft_strlen(s1), s2, ft_strlen(s2));
	buffer[totallen] = '\0';
    free (s1);
	return (buffer);
}
```

### Propósito:

Concatena dos cadenas de caracteres de manera segura, gestionando correctamente la memoria y liberando la memoria de la primera cadena (s1) después de la concatenación.
Flujo de la Función:

    Verifica si alguna de las cadenas (s1 o s2) es NULL, manejando esos casos de manera especial.
    Calcula la longitud total de la nueva cadena.
    Usa malloc para reservar espacio para la nueva cadena concatenada.
    Usa ft_memcpy para copiar ambas cadenas en el nuevo buffer.
    Libera la memoria de s1 y retorna el nuevo buffer.

## 5. Función ft_map_spliting

```c
int ft_map_spliting(t_cub3d *cub, char *map)
{
    int flag;

    flag = 0;
    if (ft_checking_lines(map))
        flag = 1;
    if (flag == 1)
        return (free(map), EXIT_FAILURE);
    cub->map.map = ft_split(map, '\n');
    free(map);
    if (!cub->map.map)
        return (ft_manage_err(FT_SPLIT_ERR), EXIT_FAILURE);
    cub->map.line_map = ft_split_len(cub->map.map);
    return (EXIT_SUCCESS);
}
```

Propósito:

Divide el mapa en líneas, almacenando cada línea en una estructura de datos y verificando posibles errores como líneas extra o vacías.
Flujo de la Función:

    Llama a ft_checking_lines() para verificar si el mapa tiene líneas extra.
    Usa ft_split() para dividir la cadena del mapa en un arreglo de cadenas (una por cada línea).
    Almacena el número de líneas en la estructura cub->map.line_map utilizando ft_split_len().

## 6. Función ft_split_len

```c
int ft_split_len(char **str)
{
    int i;

    i = 0;
    if (!str)
        return (NULL);
    while (str[i])
        i++;
    return (i);
}
```

### Propósito:

Cuenta el número de líneas en un arreglo de cadenas generado por ft_split().
Flujo de la Función:

    Recorre el arreglo de cadenas y cuenta cuántas cadenas existen.


## 7. Función ft_map_dimensions

```c
void	ft_map_dimensions(t_map *map)
{
	int	i;
	int	j;
	int	len;

	if (!map->map || !map->map[0])
		return;
	i = 0;
	j = 0;
	while (map->map[i])
	{
		len = ft_strlen(map->map[i]);
		if (len > j)
			j = len;
		i++;
	}
	map->x_map = j;
	map->y_map = i;
}
```

### Propósito

El propósito de ft_get_size_map es calcular las dimensiones de un mapa almacenado como un array de cadenas (arreglo de filas). El mapa tiene:

    map_size_x: El ancho del mapa, que es la longitud de la fila más larga.
    map_size_y: El alto del mapa, que es la cantidad de filas.

## Resumen del Flujo:

    ft_analyzer inicia el proceso abriendo el archivo, obteniendo los datos de las texturas y llamando a ft_mapping.
    ft_mapping lee el mapa, lo convierte en una cadena, elimina saltos de línea innecesarios y lo divide en líneas.
    ft_checking_lines asegura que no haya líneas vacías o extra en el mapa.
    ft_matrix_to_str convierte el mapa en una cadena completa.
    ft_new_strjoin concatena las cadenas de manera segura.
    ft_map_spliting divide el mapa en líneas y almacena el resultado.
    ft_split_len cuenta las líneas del mapa.
    ft_map_dimensions recorre todas las filas del mapa, calcula la fila más larga y cuenta cuántas filas hay. Es una forma simple y efectiva de determinar las dimensiones de un mapa bidimensional. 

Este flujo asegura que el mapa se cargue, se verifique y se divida correctamente para su uso en el programa, garantizando que no haya líneas vacías o errores de formato en los datos del mapa.