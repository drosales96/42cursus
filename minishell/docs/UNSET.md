# FUNCIONES PARA UNSET

## static int	ft_is_valid_env(char *str)

Función que recorrerá la variable de entorno para verificar que la variable de entorno comienze con una letra o un guión bajo, y que además no comience por un número ya que no es el comportamiento natural de bash.

## static char	*ft_get_env_key(char *dest, char *src)

Función que se va a encargar de recorrer la variable de entorno para poder copiar en una char * destino la key, que es lo que necesitamos buscar futuramente para borrar las var.

EJEMPLO: _VAR1=DIEGO

key = _VAR1
value = DIEGO

## int ft_find_var(t_env *env, char *key)

Esta función se va a encargar de recorrer la lista de las variables de entorno hasta que encuentre la coincidencia de la variable que entra por input. Por ejemplo si dentro de mis variables de entorno encuentro '_VAR1' el código primeramente se saltará las condiciones de recolocar la lista, ya que aún no hay ningún nodo NULL (borrado) y pueston que es tamos sobre el nodo a eliminar hacemos free a la key,al valor y al nodo.

Una vez eliminado ahora si entra la condición que recorre lista recolocando los nodos para que no haya ninguno NULL que pueda romper el programa.

## int ft_unset_cmd(t_ast *cmd, t_mini *minishell)

En esta función desarrollamos el resto a trabajar, primeramente verificamos cualquier error por ejemplo, el comando unset sin argumentos y unset con más de uyn argumento.

Tras verificar que unset tiene un solo argumento, haremos una reserva de memoria para la copia de la key que vamos a extraer con la función explicada anteriormente. Así que tras asegurar correctamente la reserva, si la función ft_is_valid_key() retorna '1' que significa que es correcto, haremos la copia de la key con ft_get_env_key() y procederemos si todo sale bien a encontrar la key a buscar comparando con la copia siempre.

Si no se cuentra la copia habrá un mensaje de error y si se encuentra se habrá borrado y saldrá un mensaje para saber nosotros que ha la variable 'X' ha sido borrada satisfactoriamente.

Finalmente liberamos la key para no dejar rastros de leaks...