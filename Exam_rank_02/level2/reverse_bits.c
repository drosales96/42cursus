/*HACE LO MISMO QUE PRINT_BITS PERO DEL REVERSO*/

#include <unistd.h>
#include <stdio.h>


unsigned char	reverse_bits(unsigned char octet)
{
    int    i = 8;
    unsigned char   bits = 0;

    while (i > 0)
    {
        bits = bits * 2 + (octet % 2);
        octet = octet / 2;
        i--;
    }
    return (bits);
}