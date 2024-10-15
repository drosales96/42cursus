# README de Minishell

## Función `ft_parsing_cmd`

Esta función se usa para parsear los comandos y sus argumentos respectivos. Usamos la estructura AST para crear una estructura sintáctica lógica para cada proceso.

### Código de la Función

```c
t_ast   *ft_parsing_cmd(token_list *tokens)
{
    t_ast   *arg_node;
    t_ast   *node_cmd;
    t_ast   *args_list;
    t_ast   *last_arg;

    if (!tokens || tokens->token.token_type != TOKEN_COMMAND)
    {
        ft_printf("Sintax Error : A command was expected!\n");
        return (NULL);
    }
    node_cmd = ft_create_node_for_ast(TOKEN_COMMAND, tokens->token.token_value);
    tokens = tokens->next;
    args_list = NULL;
    last_arg = NULL;
    while (tokens && tokens->token.token_type == TOKEN_ARGUMENT)
    {
        arg_node = ft_create_node_for_ast(TOKEN_ARGUMENT, tokens->token.token_value);
        if (!arg_node)
            return (NULL);
        if (!args_list)
            args_list = arg_node;
        else
            last_arg->right = arg_node;
        last_arg = arg_node;
        tokens = tokens->next;
    }
    node_cmd->left = args_list;
    return (node_cmd);
}
Descripción de Variables

En este caso, si metiéramos como input un comando con argumentos, como puede ser "ls -la", el código actuaría de la siguiente manera:

    arg_node: Es el nodo que va a almacenar el TOKEN_ARGUMENT.
    node_cmd: Es el nodo donde se almacena el TOKEN_COMMAND (el principal protagonista).
    args_list: Es una lista que contiene los futuros nodos de TOKEN_ARGUMENT.
    last_arg: Es el último nodo de la lista donde van los TOKEN_ARGUMENT.

Flujo de la Función

    Validación de Tokens: Lo primero que hacemos es comprobar que lo que recibimos es un token existente y que es de tipo TOKEN_COMMAND. Si el token no existe o es NULL, se lanza un mensaje de error y se retorna NULL.

    Creación del Nodo: Si todo va bien, crearemos con la función ft_create_node_for_ast() un nodo donde irá el token de tipo TOKEN_COMMAND. Una vez que se almacena el TOKEN_COMMAND, pasamos al siguiente token existente.

    Inicialización: Antes de realizar cualquier acción, se inicializan args_list y last_arg a NULL, ya que en nuestro AST no hay nada dentro de esas variables (AÚN).

    Bucle para Argumentos: Con un bucle while, verificamos que todos los tokens que tratemos sean de tipo TOKEN_ARGUMENT. Se creará un nodo donde almacenar el token y, tras asegurar esa reserva, comprobamos si args_list es NULL. Si es así, ese token será el primero en la lista de argumentos del comando padre.

    Adición de Argumentos: Si hay más TOKEN_ARGUMENT para agregar a args_list, iremos insertando en orden los TOKEN_ARGUMENT que haya después del comando.

    cmd_node:

    +-------------------+
    | TOKEN_COMMAND     |  -> "ls"
    +-------------------+
    |       left        |  -> arg_node (primer argumento)
    +-------------------+
         |
         v
    arg_node:
    +-------------------+
    | TOKEN_ARGUMENT    |  -> "-la"
    +-------------------+
    |       NULL        |
    +-------------------+
