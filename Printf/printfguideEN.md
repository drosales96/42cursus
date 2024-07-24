# Printf

## Project Description

'Printf' is arguably the most beloved function among students and pisciners when it comes to "writing". This function will be our target as we need to replicate it to include it (in case you do it with bonus... let's be realistic, you're not going to do it).

To use the original library, #include <stdio.h> is always used. In our case, we will do it differently since we are replicating it, although it is advisable to compare the results between your personal ft_printf and the original one.

You should read the subject (I will leave it in the repo), but basically, when we traverse the ft_printf and encounter a '%', it means that after it will come a key letter that will decide which path our variadic function will take, meaning it will distinguish if it is any of the cases mentioned in the subject, which are:

cspdiuxX% (Characters, Strings, Decimal, Integer, Unsigned, lowercase hexadecimal, uppercase hexadecimal, and '%').

## Code Description

Firstly, you should create a main file where we will have our variadic function, and the cases that may follow after the percentage sign (each of them will call a function responsible for writing, operating, or whatever, and will also count the number of characters that your ft_printf result contains).

That means if your ft_printf returns: "I have counted 7 characters" (result of: ft_printf("I have counted %d characters")). Your printf should also tell you that it has counted x characters.

Let's start with the main thing, the variadic function:

*ft_printf*:

Prototype: int ft_printf(const char *str, ...);

Basically, it returns an int because we will always be writing results and at the same time returning a counter to count everything your function writes.

The *str, since we have to analyze each character of our ft_printf, which in the end is a string, for example:

ft_printf("Hello world, I am %d years old");

From 'H' to the final 's', we have to be analyzing, counting, and operating.

After this, the first thing that will catch our attention is the ellipses, and this basically means that inside our function, from our first argument (const char *str) we can include an indefinite number of arguments of any type.

Next, a brief illustration of the structure of a variadic function:

va_list: it is a data type that defines a pointer to the variable argument list, it is managed through the following macros:

va_start: where we will include our va_list and the first argument defined in the prototype of the function. In this case, we would be talking about va_start(va, str).

va_arg: This is how we call the arguments that are not defined in the prototype and that can be of indefinite quantity and different type. Inside our va_arg, we will include all the cases of %. Why don't you see it in the ft_printf function? Because you have to scroll up to see ft_check, which is a call to an external function that contains our va_args, since our beloved norm does not allow us to exceed 25 lines of code.

After operating with our va_args, it's time to see the end!

va_end: where we include our va_list (in my case called 'va'), to close the reading of all arguments, and to finish, we return the counter.

*LINKS WHERE TO STUDY A LITTLE BIT*:

https://42-cursus.gitbook.io/guide/rank-01/ft_printf/variadic-functions

https://www.programacionenc.net/index.php?option=com_content&view=article&id=61:funciones-en-c-con-lista-de-argumentos-variable&catid=37:programacion-cc&Itemid=55

Now it's time to analyze the ft_printf code little by little, let's get to it. First, we need our 'va_list' variable which will be called 'va' which is our structure for variadics, then we will use a variable of type 'int' called 'count', and finally, we need the typical 'i' to iterate over our string. 'Count' and 'int' are initialized to 0 and we start by calling our va_start(va, str).

With our variadic skeleton already started, we use a while loop to traverse str (str[i]), and we give it the first case, which is if we encounter elements different from '%', write each character and store said writing while counting it in count. The next case is if we encounter a %, we will do i++ to advance to the next character so that we can then verify with the ft_check function which letter comes next (cspdiuxX %), and with that, what argument to operate on. So what we will do is add to count the mention of ft_check of the memory address of 'va', our string to continue analyzing, and an int 'i' that will iterate through said string.

Now let's move on to the ft_check function, which will create an int variable called 'res' where we will store the operations that are performed depending on the argument that acts. Therefore, we initialize res to 0 and create the cases that may happen by traversing the string with 'i'. Now you'll see it better:

static int ft_check(va_list *va, const char *type, int i)
{
    int res;

    res = 0;
    if (type[i] == 'c')
        res += ft_putcharf((char)va_arg(*va, int));
    else if (type[i] == 's')
        res += ft_putstrf(va_arg(*va, char *));
    else if (type[i] == 'p')
        res += ft_pointer(va_arg(*va, uintptr_t));
    else if (type[i] == 'd' || type[i] == 'i')
        res += ft_putnbrf(va_arg(*va, int));
    else if (type[i] == 'u')
        res += ft_putunsgf(va_arg(*va, unsigned int));
    else if (type[i] == 'x' || type[i] == 'X')
        res += ft_puthex(va_arg(*va, unsigned int), type[i]);
    else if (type[i] == '%')
        res += ft_putcharf('%');
    return (res);
}

Type which is the string (I simply changed the name), will be traversed by 'i' and if there is any match with the cases 'cspdiuxX%' we will go to other functions that will operate depending on the type. Now let's go for those functions:

(%c)*ft_putcharf*: It is literally an ft_putchar but it always returns an int value of 1, so every time it writes a character, it adds 1 to its movements.

@params1: char c (CHARACTER TO WRITE)

(%s)*ft_putstrf*: This function resembles the classic ft_putstr but with some modifications that will leave you amazed. First, we need to create two variables of type int called 'i' (to iterate over the string) and 'count' (to count each time we write with the function).

REMEMBER THAT ALL FUNCTIONS FOR ALL CASES cspdiuxX % MUST COUNT WHAT THEY DO.

So first, we'll handle the case where our string is NULL and if so, we recursively call itself (ft_putstrf) because when it self-calls the pointer of the prototype becomes NULL and it will simply write what is inside the double quotes.

return (ft_putstrf("(null)"));

Why "(null)"? Because the original printf, when it detects a NULL pointer, writes it like this and counts 6.

Now we will make a While loop of the string iterating over it and add to count what our putcharf(s[i]) writes, and of course, we will do i++ to keep writing, if you don't, you'll write one character and bye function.

Finally, we return 'count'.

@params1: char *s (string to work on)

(%d and %i)*ft_putnbrf*: In this function, I won't go into much detail because it is literally the piscine ft_putnbr but adding the value of each thing you write and each operation you do within the counter. I think you will see it better visually:

int ft_putnbrf(int nb)
{
    int count;

    count = 0;
    if (nb == -2147483648)
    {
        count += ft_putcharf('-');
        count += ft_putcharf('2');
        count += ft_putnbrf(147483648);
    }
    else if (nb < 0)
    {
        count += ft_putcharf('-');
        nb = -nb;
        count += ft_putnbrf(nb);
    }
    else if (nb > 9)
    {
        count += ft_putnbrf(nb / 10);
        count += ft_putnbrf(nb % 10);
    }
    else
    {
        count += ft_putcharf(nb + '0');
    }
    return (count);
}
@params1: int nb (number to operate with)

(%u)*ft_putunsgf*: Basically, we want to print an unsigned number, so what we will do is simply recursively divide by 10 to break down the number and then converting each digit to a char type.

We always have to include within count each movement or operation.

Visually it would be like this:

int ft_putunsgf(unsigned int n)
{
    int count;

    count = 0;
    if (n > 9)
        count += ft_putunsgf(n / 10);
    count += ft_putcharf(n % 10 + '0');
    return (count);
}
@params1: unsigned int n (Unsigned number to operate with)

(%x and %X)*ft_puthex*: In this function, we will have to learn well how to treat a number that we want to convert to hexadecimal, since like ft_putnbr which divided by 10 until getting the minimum number to operate with, hexadecimals also have a process.

First, imagine a number that we want to convert to hexadecimal which in my case will be: 68702702552.

Next, if we look at the code, it first does a recursive operation to break down the number, which in this case does ft_puthex (nb / 16) until getting the minimum number to operate with. It would look like this:

68702702552
4293918909
268369931
16773120
1048320
65520
4095
255
15

Now what our program does is when it has already evaluated whether what it found was 'x' or 'X', it uses the corresponding base:

'x' : "0123456789abcdef"
'X' : "0123456789ABCDEF"

The next thing it will do is take the numbers in ascending order, so since 15 is already representable in hexadecimal, we will give it the value of 'f' and write it.

So the 15 in hexadecimal is 'f'.

Let's continue, now we take 255 and apply that weird operation between brackets (ft_putcharf("0123456789abcdef"[nb % 16])), which will take the modulo of 16 to all the numbers of the inverted pyramid above to get the hexadecimal number. It would look like this:

255 % 16 = 15. ('f')
4095 % 16 = 15 ('f')
65520 % 16 = 0 (It is equal to zero because the calculation gives an integer result, without decimals, therefore the hexadecimal is '0')
1048320 % 16 = 0
16773120 % 16 = 0
268369931 % 16 = 11 ('b')
4293918909 % 16 = 13 ('d')
68702702552 % 16 = 8 ('7')

HEX: 0xff000bd7

At the end, we have to do i++ so that the number can be calculated, if not, the process would only be done once.

We return 'i' since it is the counter (the counter contained in the function)

@params1: unsigned long long nb (It is a much larger number than an integer which is also unsigned)

@params2: char c (the char to check since we need to know if it is 'x' or 'X' to specify the base to operate with)

(%p)*ft_pointer*: This function will allow us to print in hexadecimal the memory address of a pointer. We are going to use a very useful new variable that will help you to pass this function in a more comfortable way, and it is called UINTPTR_T which is a cousin of SIZE_T.

This variable stands out because it is an unsigned integer type that is capable of storing a data pointer. Typically, this means it is the same size as a pointer, so it will help us to make our life easier.

Next, to accompany the variable type, we will create a counter of type size_t (they are compatible) and we will initialize it to 0 and it will be called 'counter'. Then we will include inside it the value of a write(1, "0x", 2), since we need to write and count the prefix that printf uses to indicate that what comes next is a hexadecimal. After this, counter stores by counting the ft_puthex function which, as you previously saw and YOU WILL HAVE STUDIED HARD, to print in hexadecimal the memory address of the pointer, which by default the computer provides you in decimal format (hence we convert it to hexadecimal).

Finally, we return the counter.

End of the Guide
I hope it serves as a help for anyone who is going to do the project, if anyone comes up with an idea to improve the code or whatever, please let me know. THANK YOU