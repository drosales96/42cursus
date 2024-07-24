#include <stdlib.h>
#include <stdio.h>

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;


void    ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
    while (begin_list)
    {
        (*f)(begin_list->data);
        begin_list = begin_list->next;
    }
}

/*void print_int(void *data)
{
    printf("%d\n", *(int *)data);
}

t_list *create_node(void *data)
{
    t_list *new_node = (t_list *)malloc(sizeof(t_list));
    if (new_node)
    {
        new_node->data = data;
        new_node->next = NULL;
    }
    return (new_node);
}

int main()
{
    int data1 = 1, data2 = 2, data3 = 3;

    t_list *node1 = create_node(&data1);
    t_list *node2 = create_node(&data2);
    t_list *node3 = create_node(&data3);

    node1->next = node2;
    node2->next = node3;

    ft_list_foreach(node1, print_int);

    free(node1);
    free(node2);
    free(node3);

    return (0);
}
*/