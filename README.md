# FT_PRINTF 🖨️
## The second project i did of the 42 curriculum!

This project constisted of rewriting a simple version of the standard library fuction printf().
This function takes in a string to print as well as a variable amount of arguments that represent changing values which are supposed to be displayed in the first argument.
the original function has a lot more utility as it can fully format the input, but i implemented only the following conversions: 
|escape character | action|
|-|-|
| %c | Prints a single character.|
| %s | Prints a string (as defined by the common C convention).|
| %p | The void * pointer argument has to be printed in hexadecimal format.|
| %d | Prints a decimal (base 10) number.|
| %i | Prints an integer in base 10.|
| %u | Prints an unsigned decimal (base 10) number.|
| %x | Prints a number in hexadecimal (base 16) lowercase format.|
| %X | Prints a number in hexadecimal (base 16) uppercase format.|
| %% | Prints a percent sign.|

### Usage: 
**printf("<string\> %\<escape character\> ", <variable corresponding to escape char in order\>);**

### Cloning and making
```
git clone git@github.com:strohhelm/ftprintf_42.git && make -C ftprintf_42
```

now you can use the ft_printf function inside of your program if you include the ftprintf.h file and compile it with the libftprintf.a file.

### Example: 
```
int i = 83154;
ft_printf("Hallo %s World%c This is interesting stuff!\n%p is the address where the number %d is stored.\n%x is %d expressed in hexadecimal base!", "beautiful",'!', &i, i, i, i);
```
output:
```
Hallo beautiful World! This is interesting stuff!
0x7ffee4a9f668 is the address where the number 83154 is stored.
144d2 is 83154 expressed in hexadecimal base!
```

Unlike the standard implementation of printf() my function is not buffered but
it will return the amount of bytes written and -1 on error just like the original.
The function is compiled into an archive file just like the libft project and thus can be linked into other programs.

I learned a lot about how this function works, and how it deepened my understanding of pointers.
Especially in the regard of for the first time using a struct to keep all my neccessary information in one place. At first i passed this struct as a value to each function instead of a pointer,
which made the function incredibly slow since it has to copy all the values every time. After understanding structs and pointers better i changed the functions to pass a pointer
to the main struct instead of the value of it, thus improving efficiency.

Before starting the curriculum i remember being incredibly astounded by the fact that we would rewrite this function and felt overwhelmed how i could do hat this quickly in the curriculum.
But after learning about VA-lists and understanding the main concept of the function, it was rather well managable.
