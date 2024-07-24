/*SWAP DE DOS PUNTEROS INTEGER*/

void	ft_swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}