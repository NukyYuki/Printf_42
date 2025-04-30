# ft_printf to-do list

### 30/04

- [x] *itoa_base* for char ***ft_see_format()**;
- [ ] function that receives ft_see_format's string (**ret**), t_list *fbool and the specifier as arguments:
   - this func is going to return either **ret** if no flag is **true** or
   - a **new string** that is the result of **ret** with the flags saved in *fbool* applied to it;
   - we need the *specifier* because we want the *flags* to behave according to it;
- [ ] use the free() func when mem allocation is used
- [x] deal with '%p', currently not printing correct adress when compared with printf();

### 30/04
- [ ] determine final length of the string we are trying to create, WITHOUT WIDTH:
   - ret string
   - '#'
   - .precision
   - '+' && ' '
- [ ] so that we can add width if > than strlen(final_str) AND
   - padd with '0's if needed
- [ ] IF '-' flag exists then identation to the left (default is right);
