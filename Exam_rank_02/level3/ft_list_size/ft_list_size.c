/*CALCULA LA LONGITUD DE UNA LISTA*/

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
    int i = 0;

    while (begin_list->next)
    {
        begin_list = begin_list->next;
        i++;
    }
    return (i);//dependiendo de la situación a veces funciona return(i), pero si da error usar return (i + 1);
}