# Libft
## Description
Basically, we need to replicate the functions found in <string.h> plus some additional and bonus functions not belonging to the library. The key is patience, perseverance, daily progress.

Whenever you need information, RTFM, and if not, search on Google.

## Function Descriptions
*ft_atoi*: In this function, we'll ignore symbols or spaces until reaching the numbers to obtain and operate with negative symbols to achieve our goal.

@params1: unsigned int (to iterate over the string, and it's unsigned to operate with signs)
@params2: int res (variable that comes into play to store the value of the operation to convert the numbers appearing as char to int type (str[i] - '\0'))
@params3: int sign (variable that comes into play when operating with signs and to convert them if necessary or directly skip them with our i++)

*ft_bzero*: In this function, we have a void *str and a size_t n(len), and what we'll do is an index and while the traversal of it is less than n(len), we cast the *str to give it a value (char) and fill it with '\0'.

@params1: void *str (string to traverse).
@params2: size_t n (to get the length).

*ft_calloc*: Basically, it consists of memory allocation with malloc and within this, securing it with your (!buffer). Then, you'll fill that secured memory with '\0' (it's faster using bzero inside).

@params1: size_t count (memory width).
@params2: size_t size (memory length).

*ft_isalnum*: Auxiliary function to detect if there's any uppercase or lowercase letter, and also if there's any number.

@params1: int c (variable used to check if there's a match with what the function is looking for, returning (1) if found, and (0) otherwise).

*ft_isalpha*: Auxiliary function to detect whether what is found is an uppercase or lowercase letter.

@params1: int c (the variable does the same as in ft_isalnum, but only searches for letters).

*ft_isascii*: Auxiliary function to detect ASCII characters, ranging from 0 to 127 within the table.

@params1: int c (Like the previous functions, it returns (1) if the character to search for is found, and (0) otherwise).

*ft_isdigit*: Auxiliary function to detect if there's any base 10 number (from 0 to 9).

@params1: int c (If any of the mentioned digits are found, it returns (1), and otherwise returns (0)).

*ft_isprint*: Auxiliary function to find a match of printable ASCII characters, ranging from 32 to 127.

@params1: int c (With this variable, you help to detect if there's any printable ASCII character and returns (1) if correct, and (0) otherwise).

*ft_memchr*: This function locates the match of a character that will be passed as type (int) and that you'll have to cast to (char) inside your function. We'll need an index to traverse the string. This string is of type void *, so we'll have to create a variable to store the value of the original pointer, but casting it to type (const char) [str = (char *)s]. When the char match is finally found within your str[i] (using the condition (i < n)), the memory address of the first char pointed by the pointer is returned, and consequently the index (return(&str[i])).

@params1: const void *s (original pointer pointing to the string)
@params2: int c (character to search for (CAST IT FOR GOD'S SAKE))
@params3: size_t n (parameter that will be the 'n' positions to be traversed in memory, will serve as 'len')

*ft_memcmp*: This function will compare two strings (s1 and s2), it will always return an int result since the character value in s1 will be subtracted from the one in the same position in s2. Therefore, if you pass size_t n as a parameter like 4, it will check the fourth position of s1 and s2 and compare them (s1 - s2). It should be noted that when playing with memory and providing const void *s1/s2 as a parameter, we'll need to create variables to store the casting of each void string to char. In this case, since a negative or positive result can be issued, we'll cast with (unsigned char).

@params1: const void *s1 (pointer pointing to the first string to compare)
@params2: const void *s2 (pointer pointing to the second string to compare)
@params3: size_t n (position within both strings to compare)

*ft_itoa*: This function is complex and needs some auxiliary function. Firstly, we'll make a function that checks whether the number is negative, and through division by 10 and an increment of the number received, it extracts the total length of the number to operate on, already broken down number by number (length of the number string). Next, I'll use a function that when a negative sign is encountered, transforms it into a positive one. The third function is the memory allocation that will be necessary in this exercise and we'll do it outside to not exceed 25 lines in the main function.

Inside the main function, we'll check if the number is negative, and if so, the sign variable takes the value of 1 so that if it is negative, it returns 1, as the condition is true. Next, the variable 'len' will store the result of our function that extracted the length of the number received. Then in the buffer variable (which will store the function that allocates memory), we'll apply the 'memnum' function and then ensure with (!buffer) / return (NULL);. Next, we'll make a loop that decrements (since we have the length of the number), and the buffer (memory) + len (length of the number received), will transform it to char, using 48 + nbr % 10, which will transform digit by digit thanks to % 10 and / 10. Finally, if the sign condition is true and therefore negative, the '-' symbol is added, which is 45 in ASCII, to the first character of the buffer. At the end, we return buffer which contains the number in char format.

@params1: int n (The number you receive as a parameter and that you'll convert to char)

*ft_memcpy*: This function will copy the src memory block to dest. We'll create 3 variables, the first one is a size_t that we'll call 'i' and that we'll use to traverse the next two variables containing src and dst (originals). The second variable (called *source) will store the *src parameter cast to (char *), because we want to work on a const void. The last variable is of type char and stores the casting of dst. Next, we'll enter the code and check that source (containing src) and dest (containing dst) are not null. In the opposite case, we'll enter the code and while 'i' is less than the n characters (coming from the main) that we want to copy from src to dst (ALWAYS THE VARIABLE THAT TRAVERSES MUST BE ++ OR -- (depending on the case)). Finally, we return dest (variable that stores the copy made in dst), where the copy is done.

@params1: void *dst (Destination of the future copy)
@params2: const void *src (Origin of the 'n' characters to be searched to make the copy in dst)

*ft_memmove*: This function will copy a memory block over another, even if they overlap. First, we need to create 3 variables, the first one will be a size_t called 'i' that will basically traverse dest and src during memory copy (in case the blocks don't overlap). Secondly, we'll create a variable called dest that will store the value of the original dst pointer cast to (char *). Lastly, we'll create another variable called source that will store the value of the original src pointer with its respective cast to (char *).

We'll continue getting into the code, and what we'll do is check if dst and src are NULL (it would be done like this. if (!dest && !source) / return (NULL);. Now, we'll put ourselves in the case that dest is > than src (to allow for the possibility of overlapping), then we'll decrement i (i--) since we have the length of both sources (source and dest), and we decrement because when overlapping, copying from front to back is the safest way to do it. The way to copy them would be dest[len] = source[len] (PLEASE ALWAYS REFLECT THE GROWTH OR DECREASE OF THE VARIABLE THAT TRAVERSES DURING THE COPY).

Finally, if the previous case doesn't happen and the memory blocks don't overlap, we directly put the condition (i < len) and then make the copy but with our index 'i'. The copy would be dest[i] = source[i]; (REMEMBER THE I++).

Finally, we'll return dest which is where the copy will have been made.

@params1: void *dst (where you'll make the copy of src according to the len passed by the main)
@params2: const void *src (source from where you'll copy)
@params3: len (the length of characters you want to copy and that will be sent by the main)

*ft_memset*: This function will be used to fill a block of memory with x characters pointed by a specific pointer. What we need is a counter that will be of type size_t and will be called 'i'. Additionally, we need to create a pointer that will be of type char, which will store the value of the specific pointer (void) we want to fill with x characters (that pointer variable that stores the original pointer, we have to cast it to unsigned char because we need to fill with characters and therefore we have to move through the pointer created byte by byte to fill 1 by 1).

Now we get into the code and make the case that i is < than len, and if so, we'll enter the pointer we've created (which will be called buffer), iterating with our counter 'i' (buffer[i]) and we'll set it equal to (unsigned char) c to fill the buffer with these x characters. You may wonder why the char is casted, and it's because we need it to be forced to be char since it's passed to us as an integer, and as we said we need characters that will go 1 by 1 because they weigh 1 byte (unlike integers that weigh 4 bytes each). PUT THE FUCKING I++ OTHERWISE THE CODE WILL GO TO HELL.

Finally, we return the buffer which basically contains the value of the original pointer that comes in the prototype.

*ft_strchr*: In this function, what we'll do is traverse a string and if we find the first match of a char c that will enter by main as int c (IT MUST BE CASTED), it will return the memory address of s pointing to the char match + i so that the char found and what comes after it appears on the screen. We'll need a counter of type size_t called 'i' and initialized to 0. That counter will traverse 's' until it reaches null, and we'll also put the possibility that s[i] != (char) c, and in those cases, we'll move forward. Now after advancing if the case s[i] == (char) c occurs, then what we'll do is return the pointer pointing to the char c that matches plus what follows using [i].

@params1: const char *s (string we'll work on).
@params2: int c (char c that will be casted to be converted and that we'll search as a match within s).

*ft_strrchr*: This function is responsible for finding the last occurrence of a character that you'll pass by main. First, we'll create a counter of type int that in this case instead of initializing at 0, we'll put inside an ft_strlen (s) to know the total length of the string and start looking for the character from the end. Therefore, as long as i is > or = to 0 if s[i] == (char) c, it will return the memory address that points to that character found from the end plus i so that the matching character plus the rest of the string appears on screen.

@params1: const char *s (string we'll work on).
@params2: int c (char c that will be casted to be converted and that we'll search as a match within s).

*ft_strlcat*: In this function, we'll concatenate src and dest without overflow. First, we have 3 variables which are 'i' that will traverse dest, 'res' that will traverse src and will be returned with the concatenation at the end, and finally we have 'j' that traverses src when we need to concatenate. Looking at the code first, we'll traverse dst with 'i' and src with 'res' (USING ++ TO REACH NULL), then if the size to concatenate is less than or equal to 'i' that runs destination, then we'll add src + 'i' (which runs dest). If this doesn't happen and therefore if there's space for concatenation, we'll traverse src with 'j' and make sure it doesn't reach null and also make sure that 'i' + 1 (to ensure space for the null we'll add at the end) is less than the size to concatenate, if so we'll make the concatenation as follows (dst[i] = src[j]), always including our I++ and J++.

Finally, after concatenation, we'll put a null at the end of the concatenation that is in dst[i] and return res which contains the concatenation.

@params1: char *dst (destination where we'll deposit the total concatenation)
@params2: char *src (it's the source origin from which we'll extract what to concatenate)
@params3: size_t dstsize (it's the amount to concatenate)

*ft_strlcpy*: In this function, we'll make a copy of a given string, starting from the end to ensure the copy is safe. Firstly, we initialize a size_t counter called 'i', which is set to 0. Then, we check if the amount to copy is 0, and if so, we return ft_strlen(s), which is the length of the original string, as there is nothing to copy. Now, if the case arises where while src[i] does not reach null and i is less than dstsize - 1 (translated to Spanish, the end), then we'll copy src into dst with our i++ (dst[i] = src[i]), furthermore, after this, we'll put the null at the end of dst by setting (dst[i] = '\0'). Additionally, in this function, we return the copy and its size, which is done by returning ft_strlen(src).

@params1: char *dst (destination where the copy will be made)
@params2: const char *src (source origin to be copied into dst)
@params3: size_t dstsize (amount we want to copy, indicated in the main)

*ft_strlen*: Basic function that determines the length of a string (no need to review it).

*ft_strncmp*: This function will help us compare characters between two string chains. For this, we need a size_t counter called 'i', initialized to 0. While s1 and s2 do not reach null and 'i' is less than n. If s1 is different from s2, it will return s1 - s2, and don't forget to increment i outside the loop (i++). Now, we specify to ensure that if i is less than n, it will return the same subtraction we did in the previous lines.

@params1: const char *s1 (first string)
@params2: const char *s2 (second string)
@params3: size_t n (number of characters to compare, provided by the main)

*ft_tolower*: Function that converts any uppercase character it finds into lowercase.

@params1: int c (character to analyze, which will be converted to lowercase if it's uppercase)

*ft_toupper*: Function that converts any lowercase character it finds into uppercase.

@params1: int c (character to analyze, which will be converted to uppercase if it's lowercase)

*ft_substr*: We'll use this function literally to extract a substring from a main string, creating memory for it with malloc and ensuring it properly. First, we declare a char pointer variable where we'll reserve memory for the substring we want to obtain.

Firstly, we check if the string passed as a parameter is not null (if(!s) / return (NULL)), this way if it's not null, the process continues. Now we have to provide the function's cases. First, if ft_strlen(s) < start, we return a duplication of a null string with ft_strdup(""), which will create a null memory space with malloc (this is good practice). Then, if the length to be searched is greater than the length of the word + start (start is the starting point of our substring), then the len variable of the prototype becomes the length of the string thanks to ft_strlen + start.

Now it's time to create memory, and we'll do it like this (buffer = (char )malloc(sizeof(char) (len + 1))). The next step after any memory creation is to ensure it with the negation. So we'll do if(!buffer)/return (NULL);.

The last thing to do, now that we have created memory, we have the length of the entire string and also our start, is to use the ft_strlcpy function (since there could be an overflow), and it will contain ft_strlcpy(buffer, s + start, len + 1);.

Finally, we just return the buffer, which is our memory created with malloc that will contain the substring.

@params1: char const *s (main string).
@params2: unsigned int start (starting point of our future new substring)
@params3: size_t len (length we want to extract as a new substring from the main string)

*ft_strjoin*: This function will be used to create memory with malloc of the dimension of two different strings to store them together, as if, so to speak, joining them.

We'll need 4 variables, first a size_t type that will be called totallen, another size_t i, another size_t j, and the last one will be a char pointer where memory will be created and will be called buffer.

Totallen will be = ft_strlen(s1) + ft_strlen(s2) and we'll initialize both 'i' and 'j' to 0. Now that we have the total length of what we need to use, we'll create memory and we'll do it like this, buffer = [(char )malloc(sizeof(char)] totallen + 1);. Next, we ensure our new memory by saying that: if (!buffer)/return (NULL).

As it turns out that in this case it won't be NULL, we'll go through s1 with a while loop and using the 'i' counter, and inside we'll copy normally what is in s1(src) into buffer(dest), and remember the i++. After copying the first s1, we'll do exactly the same process with the while loop of s2 but with the 'j' variable and we'll also copy into buffer, as it will continue from where it left off. Now we advance both j++ and i++ to finish the copy. The copy would be (buffer[i] = s2[j]). Finally, we close the string with a NULL (buffer[i] = '\0') and return buffer.

@params1: char const s1 (first string)
@params2: char const s2 (second string)

*ft_strtrim*: This function basically serves to remove any excess, character, space, tab, or whatever surrounds a string (both from the right and from the left).

First, we need to create a counter to traverse the string, which will be an unsigned int called 'i' initialized to 0. Next, we check if s1 or set (set are the characters we want to remove) with their negation and if so, return NULL.

We'll look from the left searching for the elements to remove and we'll do it with a while loop to which we apply the ft_strchr function on set and *s1 and considering that s1[i] doesn't reach null. That is, if it analyzes the string and finds any set it will skip it until it finds something that is not a set, by doing s1++;

Now our variable i will take the value of ft_strlen((char *)s1), and we'll do this to now check the string from the right, going from the end to the beginning. We'll do it using a while loop to traverse and we'll apply ft_strchr if and s1[i] and while i != 0, and decrementing with i--; to go backwards looking for matches to skip until it finds something that is not equal to set.

Once the string is delimited, we'll return the function ft_substr((char *)s1, 0, i + 1);

@params1: char const *s1 (string we're going to work with)
@params2: char const *set (pointer pointing to the delimiter character or what we want to remove, better said)

*ft_strnstr*: This function will be responsible for extracting a string (substring) from a main string. First, we'll start by creating two counters, one of them will be responsible for traversing the main string (in this case we call it 'i'), and the other will traverse the substring or tofind according to my prototype. We'll start 'i' at 0, and first, if the word to search for (tofind[i]) is null (basically we don't have a word to search for within our main string), we return the main string directly with a cast to (char *), as it is a const char (return (char *)str1). Next, we check the main string by starting a loop, which will be, as long as str[i] does not reach null and i is less than 'n' size to extract, the counter 'j' is initialized to 0, and if str1[i] is == tofind[j], while (while) str[j + i] == tofind[j] and if (&&) i + j is less than 'n' size, then if tofind [j + 1] already reaches null (end of the substring), we return str1 + i cast to (char *). Finally, we increment j++ and outside the last while we increment i++. If none of this happens return (0).

@params1: const char *str1 (main string where we'll search our substring)
@params2: const char *tofind (it's the string we'll search for within the main string)
@params3: size_t n (size we're going to search within the main string)

*ft_strdup*: This function is useful when we want to create a memory space where we'll make a copy of a specific memory block. For this, we need to create a char * variable called buffer where we'll store the memory allocation with malloc. Of course, we need a counter to traverse the string (memory block to copy).

Next, we'll give our size_t variable called count the value of an ft_strlen of the string (thus we have the total length of the string found in the memory block). After this, we'll make the memory allocation and we'll do it like this: (char *)malloc(sizeof(char) * count + 1). Now we ensure our new memory by saying: if (!buffer)/return (NULL). After this check, and inside an else, we'll do the copy using ft_memcpy(buffer, str, count + 1);

Finally, we return the buffer that already has the copy.

@params1: const char *str (string we're going to copy using ft_memcpy into the memory we create with malloc)

*ft_striteri*: This function basically allows us to apply an undefined function to the iterations of the counter that traverses the string and of the same pointer that moves with the iterator. We'll create a counter/iterator that is of type size_t and called 'i'. Before setting it to 0, first we'll say that if the string and the function exist and are given at the same time, then the counter is positioned at 0 and while the string doesn't reach null, the function is applied on i++ and s++.

It won't return anything since it's a void-initiated function.

@params1: char *s (string to be analyzed and on which the undefined function will be applied)
@params2: void (f) (it's void since it's unknown which function will be used and what it will return)
@params3: unsigned int, char * (the unsigned int since it will be the iterator that traverses the string and the char since it's the pointer of the string that moves along with the iterator)

*ft_putchar_fd*: It's a very basic function that is responsible for writing character by character and what will vary from the original is that we can choose the file descriptor (which can be 1, 2, or 3, generally). The code will look like this:

void ft_putchar_fd(char c, int fd)
{
write(fd, &c, 1);
}

@params1: char c (character to print)
@params2: int fd (file descriptor or better known as fd)

*ft_putendl_fd*: Function that basically writes a complete string through an fd using the ft_putstr_fd function on the string, and then as it asks for a newline, we'll use the ft_putchar_fd function that will output a \n and through the specified fd.

@params1: char *s (string to work on)
@params2: int fd (file descriptor through which the program will be launched)

*ft_putstr_fd*: This function is basically like the regular ft_putstr but with the addition of specifying the file descriptor (fd). The code would be as follows:

char    ft_putstr_fd(char *s, int fd)
{
    size_t  i;

    i = 0;
    while (s[i])
    {
        ft_putchar_fd(s[i], fd);
        i++;
    }
    return (s);
}
@params1: char *s (string to work on)
@params2: int fd (file descriptor to be specified)

*ft_putnbr_fd*: This function is basically similar to the putnbr from the pool but it uses ft_putchar_fd to print signs or numbers. If you haven't forgotten, this function uses recursion. It takes a number as input from the main and operates on it by dividing it by 10 and taking the modulus of 10 to extract each digit one by one and then outputting them through the specified file descriptor, converted one by one to type char.

@params1: int n (number to operate on)
@params2: int fd (file descriptor)

*ft_split*: The purpose of this function is to first detect the length of all possible words, excluding delimiters (this will be done thanks to the auxiliary function word() // LOOK AT CODE ON GITHUB). Secondly, we will use the wordlen() function (LOOK AT CODE) to obtain the length of each word to be extracted and convert it to an individual array with its own memory allocation within the main allocation. Thirdly, we have a function called free_array() that allows us to free all the memory that will be created to avoid memory leaks.

Finally, using the three auxiliary functions, we get into the meat of it, and within the main function, we need to create a variable char **buffer (main memory allocation that is a pointer pointing to sub-pointers), an int called 'i' that will serve as an iterator over the string, and an int 'is' that iterates over the **buffer.

First, we do as we know the memory allocation of the **buffer with malloc and then ensure the allocation:

buffer = malloc(sizeof(char *) * (word(s, c) + 1));
if (!buffer)
    return (NULL);
Then we enter the buffer with the condition while 'is', which increments, is less than the function word(s, c), and while s[i] is equal to c, we increment i++ to skip the delimiter and interpret that we are in a new word. Then we use malloc again to allocate memory individually for each word:

buffer[is] = ft_substr(s, i, wordlen(s, c, i));
After this, instead of ensuring memory in the usual way, we will free all the memory created with the function free_array():

if (!(buffer[is]))
{
    free_array(buffer, is);
    return (0);
}
After this, we add the total length of all the words to the index i (one by one since it is a loop).

Finally, we put the null in the large memory allocation and return the buffer:

buffer[is] = NULL;
return (buffer);
word()

@params1: char const *s (string to be analyzed)
@params2: char c (delimiter character)

wordlen()

@params1: char const *s (string to be analyzed)
@params2: char c (delimiter character)
@params3: int i (iterator working on *s)

free_array()

@params1: char **buffer (future memory allocation in Split (buffer **))
@params2: int is (future iterator that traverses the **buffer)

split()

@params1: char const *s (string to be analyzed)
@params2: char c (delimiter character)

*ft_strmapi*: This function will help us create a memory allocation with malloc of the size of the specified string, as we will use ft_strlen(s), and then we will iterate over the string by iterating over the memory buffer and incrementing ++, and within it, we will use f(i++, s++) to iterate with an as yet undefined function moving both the iterator and the pointer of s to execute said function in each iteration.

newbuff()

@params1: size_t n (size of memory allocation)

Execution:

static char *newbuff(size_t n)
{
    char *buffer;

    buffer = (char *)malloc(sizeof(char) * (n + 1));
    if (!buffer)
        return (NULL);
    return (buffer);
}
ft_strmapi()

@params1: char const *s (string to be analyzed)
@params2: char (f) (determines that we will work byte by byte, and also sets the stage for the function to be used)
@params3: unsigned int, char * (the unsigned int as it will be the iterator traversing the string and the char as it is the pointer of the string moving along with the iterator)

*ft_lstnew*: This function basically creates a new list using the t_list structure provided by the subject's pdf. The structure is as follows:

typedef struct      s_list
{
    void            *content;
    struct s_list   *next;
}                   t_list;

As in any memory allocation, we use malloc in the following way:

t_list *list;

list = (t_list *)malloc(sizeof(t_list));
if (!list)
    return (NULL);

The next step is to understand lists and how they work with it, I will give examples of this exercise to understand more:

list->content = content; // Here we access the list and with '->' we indicate that we want to point with the list's pointer to 'content' and that it will be equal to 'content'.

list->next = NULL; // Now we access the list and use the intermediary 'next' which allows us to point to the next node, but since in this case there is none, it points to NULL, to indicate that there is nothing else after the first node.
Finally, it returns (list).

@params1: void *content (The function to create a new list directly provides this pointer that points to the content of this)

*ft_lstsize*: This function will help us count the size of a previously created node. As usual, we need a counter of type int and initialized to 0, we will call it 'count'. We traverse the node using a while(lst != NULL) loop, increment the count++ and move to the next element of the node using the following:

lst = lst->next;
Finally, outside the loop, we return the count.

@params1: t_list *lst (It will be the pointer that points to the beginning of the list (the declaration t_list appears which is the structure of the lists)).

*ft_lstadd_back*: The ft_lstadd_back function takes a pointer to the first element of a linked list (lst) and a pointer to the element to be added (new). It begins by checking if 'lst' or 'new' is NULL. If either of them is NULL, it indicates an invalid operation and the function returns without making any changes. It checks if the pointer to the first element of the list (*lst) is NULL. If it is NULL, it means the list is empty. In this case, it assigns the 'new' element to the pointer of the first element (*lst) and returns. This step is necessary to handle the case where the list is initially empty. If the list is not empty, it initializes a temporary pointer 'temp' and assigns it the value of the pointer to the first element (*lst). Then it traverses the list using a loop until it reaches the last element, which is indicated by a NULL pointer 'next'. Inside the loop, it updates the 'temp' pointer to point to the next element in each iteration. Once the loop reaches the last element, it assigns the 'new' element to the 'next' pointer of the last element, effectively adding it to the end of the list. Finally, the function returns and the list now contains the new element at the end.

@params1: t_list **lst (Here we are already receiving a double pointer which basically is an initial pointer that contains other pointers inside and therefore the first pointer points to the first memory location of the main pointer, and that point in turn points to the first element that it contains).
@params2: t_list *new (Here we have the internal pointer that is inside lst, to which the second pointer of lst points [**lst], in this case it is called new since it does not contain anything).

*ft_lstadd_front*: The ft_lstadd_front function takes a pointer to the first element of a linked list (lst) and a pointer to the element to be added (new). It begins by checking if 'lst' or 'new' is NULL. If either of them is NULL, it indicates an invalid operation and the function returns without making any changes. It assigns the 'next' pointer of the 'new' element to the pointer of the first element (*lst), effectively making the 'new' element point to the current first element of the list. Then, it updates the pointer to the first element (*lst) to point to the 'new' element, making it the new first element of the list. This step ensures that the 'new' element is added to the beginning of the list. Finally, the function returns and the list now contains the new element at the beginning.

@params1: t_list **lst (Here we are already receiving a double pointer which basically is an initial pointer that contains other pointers inside and therefore the first pointer points to the first memory location of the main pointer, and that point in turn points to the first element that it contains).
@params2: t_list *new (Here we have the internal pointer that is inside lst, to which the second pointer of lst points [**lst], in this case it is called new since it does not contain anything).

*ft_lstdelone*: This function will be used to delete the content of a list, and then free it with a free. At the end, when deleting the content of it. a NULL is added to interpret that it is created but empty.

void    ft_lstdelone(t_list *lst, void (*del)(void*))
{
    if (!lst || !del)
        return ;
    (del)(lst->content);
    free(lst);
    lst = NULL;
}
@params1: t_list *lst (Pointer pointing to the first element of an existing list)
@params2: void (*del) (it is a pointer that will basically go through the list deleting its content if required. Hence it is called (*del), from the word DELETE).

*ft_lstclear*: This function will help us delete the content of a list. First, we check with an if (lst) if a list exists, and if so, we enter the code and traverse the *lst with a while loop. And now through a previously declared variable with the name *aux (pointer since we are working on a list of lists), and we give it the value of (*lst)->next. After this, we will use the ft_lstdelone function on (*lst) and using del (since it will be asked by the parameters of the function to delete). Finally, * lst is equal to aux to return the value.

@params1: t_list **lst (Here we are already receiving a double pointer which basically is an initial pointer that contains other pointers inside and therefore the first pointer points to the first memory location of the main pointer, and that point in turn points to the first element that it contains)
@params2: void (*del) (it is a pointer that will basically go through the list deleting its content if required. Hence it is called (*del), from the word DELETE)

*ft_lstiter*: This function will be useful for iterating with a function 'f' (it should be specified if using ft_lstiter in another code), over the content of the list. So, after the negation of lst and f (in case either is NULL), we loop through 'lst' and inside the loop, we apply the function on the content of 'lst'.

@params1: t_list *lst (pointer directly to the first memory address of the list)
@params2: void (*f)(void *) (Here we have the pointer on f since the function you apply will iterate over each memory location of lst, and we also have void * since we will be applying this function on a pointer that is not explicitly known what type it will be).

*ft_lstlast*: This function will help us position the first pointer, which points to the first memory address of lst, at the last place, thus positioning what would be the last element as the first, of course, as long as the last element of the list contains data and is not NULL.

@params1: t_list *lst (pointer pointing to the first memory address of the list, and on which we will be working).

*ft_lstmap*: In this function, we will receive a pointer to an existing element that is *lst, and we will need a pointer to a new element that in this case will be called *new, and we will also need a pointer called *node in which we will give the value of the function ft_lstnew to apply, on the content of lst, that is, we will create a new node with the content of lst. We also create a variable void *set to store the previous operation (f(lst->content))

We will go step by step, first we do inside an if, the negation of lst, del and f to avoid errors, since if any of them is null, we have to return NULL and exit the process.

After this, we will work inside lst as long as it exists (we will traverse it with a while). Inside lst, we introduce/set our set variable with the value of f(lst->content), and then to node we introduce/set the value of the function to create a new node (ft_lstnew) which will take set as a parameter.

Then if the negation of node occurs, we delete the set (which is basically the content of lst), and after this we use the ft_lstclear function on the memory address of new, thus eliminating the null it contained. After this, we return new.

Finally, we add node to the end of the list and position new in first place.

We return new.

This function is a madness and is difficult to understand so it is better to look at references and videos to understand it better.

@params1: t_list *lst (pointer to the first memory location of lst)
@params2: void *(*f)(void *) (pointer to apply a function iterating through the elements of a node)
@params3: void (*del)(void *) (pointer to delete the content of a node)




