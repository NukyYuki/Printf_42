# ft_printf to-do list

### 28/04

- [ ] *itoa_base* for char ***ft_see_format()**;
- [ ] function that receives ft_see_format's string (**ret**), t_list *fbool and the specifier as arguments:
   - this func is going to return either **ret** if no flag is **true** or
   - a **new string** that is the result of **ret** with the flags saved in *fbool* applied to it;
   - we need the *specifier* because we want the *flags* to behave according to it;
- [ ] use the free() func when mem allocation is used
