# ft_printf to-do list

### 29/04

- [x] *itoa_base* for char ***ft_see_format()**;
- [x] function that receives ft_see_format's string (**ret**), t_list *fbool and the specifier as arguments:
   - this func is going to return either **ret** if no flag is **true** or
   - a **new string** that is the result of **ret** with the flags saved in *fbool* applied to it;
   - we need the *specifier* because we want the *flags* to behave according to it;
- [x] use the free() func when mem allocation is used
- [x] deal with '%p', currently not printing correct adress when compared with printf();

### 30/04

- [x] determine final length of the string we are trying to create, WITHOUT WIDTH:
   - ret string
   - '#'
   - .precision (number or string);
   - '+' && ' '
- [x] so that we can add width if > than strlen(final_str) AND
   - padd with '0's if needed
- [x] IF '-' flag exists then identation to the left (default is right);

### 2/05

- [x] '#' '0' and width combination ~~isn't~~ *is now* working, not printing number after 0x
   - wrong allocation size
   - need to make it work for hash with and without '0's simmultansly;
- [x] norm correct everything, mostly functions bigger than 25 lines;

~~- [ ] use unsigned int for all the "int values", only use long for the pointer adresses.~~

### 5/05

- [ ] paco reports conditional jump when specifier refers to a number
- [ ] NULL values print "(null)", but some flags dont work like
   - `char *s = NULL; ft_printf("%.5s", s)` should print nothing, ours is printing `$>(null`
- [x] change struct boolean types to char to minimise memory usage

### 06/05

**It's almost done!! yay us!!!11!1!!1**

- [ ] only thing missing is the things left to-do from yesterday
   - need to detect null values for the va_arg variable and skip the print
   - with this we could avoid both errors above w/o having to hard code edge cases
- [ ] when everything is done try to implement ft_sub_printf
- [ ] change headers/var names, make each project unique
