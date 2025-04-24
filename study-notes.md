#  ft_print - my notes

available external functions we can use:
`malloc`, `free`, `write`,
`va_start`, `va_arg`, `va_copy`, `va_end`.
**BONUS:**
- Manage any combination of the following flags: ’-0.’ and the field minimum width
under all conversions.
- Manage all the following flags: ’# +’ (Yes, one of them is a space).
## variadic functions

Variadic functions are functions that can take a variable number of arguments.
This feature is useful when we don't know the number of arguments our function will take, like the printf() function.

prototype:
```
int    ft_printf(const char *, ...);
```
when called:
```
ft_printf("here is a string -> \"%s\"\nthis is it's length -> %u\n", (char *)s, (size_t)ft_strlen(s));
```
output:
```
here is a string -> "hi i'm a string!"
this is it's length -> 16
```
### Syntax
The `...` in the prototype represents the variable number and type of arguments the functin receives.
Variadic funtions take at least one fixed paramter and one ellipsis(...).

### Accessing Variable Arguments
The syntax above allows us to pass variable arguments to a function, but to actually *access* these arguments whe have to use the methods specified in the `<stdarg.h>` library. The process is:

0. **Include the lib**
``#include <stdarg.h>``;

1. **Create the variable argument list - Valets**
```
va_list list_name;
```
this `va_list` variable will store the contents of the our variable arguments
(anything that's not the `const char *` in `ft_printf()`);

example:
```
va_list vargs;

...

ft_printf("My name is %s and I'm %i years old\n", "Dino", 5);

//                           (va_list)vargs = ["Dino", 5];
```

2. **Initialize the Argument List - va_start() function macro**
this macro initializes the **va_list** variable to retrieve the arguments specified in the variable arguments section.
```
void    va_start(vargs, fixed_arg);
vargs = (void*) &fixed_arg + sizeof(fixed_arg);
```
**list** is the variable (we declared above called vargs) that will hold the V.A. table;
**fixed_arg** is the last *fixed* argument before the V.A.s, in our case the `const char *`;

3. **Retrieve the Arguments - va_arg()**
This macro returns the next argument from the list.
It must be used repeatedly to access all arguments.
Each time `va_arg` is called, you move to the next argument. 
```
type    va_arg(vargs, type);
type a = *((type *) vargs); vargs += sizeof(type);
```
va_arg will take as argument:
- **list** - the list of dynamic arguments we had defined (`va_list vargs`)
- **type** - the type of the variable (part of the list) we want to access

in this example:
```
ft_printf("My name is %s and I'm %i years old\n", "Dino", 5);

//                           (va_list)vargs = ["Dino", 5];
```
vargs (the va_list list) as a size of 2. the first element of this list is a string in the first and the second an **int** in the second position.

this is how we use va_arg to access each argument:
```
//the first argument (type "string")
va_arg( vargs,  char * ) // -> "Dino"

//the second argument (type "int")
va_arg( vargs, int ) // -> 5
```

4. **Clean up with va_end()** 
```
void    va_end(va_list list);

//in our example:
va_end (vargs);
```
va_end will free the allocated memory;

---

this is kinda like the `open`, `read` and `close` functions but to variable arguments instead of file descriptors.

---
## Printf Flags Behaviour

- '%n[spec]' -> n is a width (as in spaces) for variable to be printed into, i.e.: for n = 10
```
printf("||%10s||\n", "oi");
...
$> ./a.out
||        oi||
$>
```
- '-' -> left align indentation (default is right); can paired with the flag above and **it has to be before the given width (n)**
```
printf("||%-10s||\n", "oi");
...
$>./a.out
||oi        ||
$>
```
- '0' -> fills/preappends width with 0's
    - doesn't work with '-' flag and 'p' (void* aka print adress) specifier;
    - check other specs it doesnt work with (c,s,x,...);
- '.' -> precision field 
    - preappends 0's for numbers;
    - if we are trying to write a number (doesnt matter which base) -> (.n - len_nbr) times 0's; if res <= 0 then no 0s are written
    - if we are trying to write a string then -> (ft_strnlen(str, .n)) times 0's; if strlen >= .n then str is written 
- '#' -> format for hexadecimal (%x -> 0x[nbr]) or octal (%o -> 0[nbr]) base
- ' ' -> preappends a space character before number:
    - only works with the '%i' and '%d' specifiers and 
    - only positive values (with negative values it compiles but is ignored);
    - when paired with other specifiers (x,X,o,c,s,u) compiler reports undefined behaviour;
    - if it works (has prio) or not (program compiles but no space is shown) is dependant on where ' ' is placed;
    - is ignored (compiler warning) when '+' flag is present
- '+' -> preappends a plus sign for positive numbers
    - only works with the '%i' and '%d' specifiers; 
    - gets ignored (compiles, writes nothing) with negative input;

---
TODO: document flag hierarchy (see to-do file)
