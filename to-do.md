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

- [ ] '#' '0' and width combination isn't working, not printing number after 0x
   - wrong allocation size
   - need to make it work for hash with and without '0's simmultansly;
- [ ] norm correct everything, mostly functions bigger than 25 lines;
no need - [ ] use unsigned int for all the "int values", only use long for the pointer adresses.
