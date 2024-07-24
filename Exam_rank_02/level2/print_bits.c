/*OBJETIVO, PRINTAR LOS BITS DEL VALOR DE UN CARACTER DADO*/

#include <unistd.h>
#include <stdio.h>

void	print_bits(unsigned char octet)
{
    unsigned int    i = 8; //1 char = 8 bits
    unsigned char   bits;

    while (i--)
    {
        bits = (octet >> i & 1) + 48;
        write(1, &bits, 1);
    }
}

/*int main(void)
{
    unsigned char   octet = 'a';

    print_bits(octet);
    return (0);
}*/