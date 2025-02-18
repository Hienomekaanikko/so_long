# 🖨️ Ft_printf

Ft_printf is like a lite version of printf in C. The idea was to replicate the behaviour of standard printf as closly as possible, except for buffer management.
Tests can be ran by first typing "make" inside main directory, and then typing "make test" inside the "tests" folder.

## 📊 Formats

| Format | Description |
|--------|-------------|
| `%c` | write character |
| `%s` | write string |
| `%p` | write pointer address |
| `%d` | write integer |
| `%i` | write integer (difference when using with scanf) |
| `%u` | write unsigned integer |
| `%x` | write lower case hexadecimal of an unsigned integer |
| `%X` | write upper case hexadecimal of an unsigned integer |
| `%%` | write % if called '%%' |

🛠️
I created a function ft_printf, which uses va_list to go through arguments of user input. (as in prototype: int    ft_printf(const char *, ...); I use while-loop to go thorugh the input string,
and every time '%' is encountered, it checks the next letter which is or isnt one of the formats shown above. Then it goes into a format function, through which the input will be 
written according to the format. Length of the string will be returned in the end, which also depends on what formats the user wanted to output.

## 💡 New things? 

Va_list was a cool new thing. If the number of arguments is not known, we can use that to just go through all of the arguments and use them as needed. First it's declared just like
any variable. For example:

```c
va_list  args;
```

Then we initialize the list with:

```c
va_start(args, (and for example 'str' here, depending on how you named the first parameter in the prototype));
```

To move to the next item in the va_list, we just call:

```c
va_args(args, type of the argument we want to retrieve)
```

To end going through the list, we call:

```c
va_end(args)
```

Pretty cool huh?

## 🔢 Hexadecimal Conversion

Working with hexadecimals, was very similar to how I learned to recursively convert integers to ascii during the piscine. Instead of calling recursively:

```c
nbr / 10
nbr % 10
```

We do:

```c
nbr / 16
nbr % 16
```

There's much more into that but I don't have time right now. One thing I'd like to add, I struggled for hours with why i had issues with multiple inputs such as %d %c %c %c, because
with that the output was always just the same. I had misunderstood how va_args worked when jumping into a helper function. Of course I had to make sure I work with the original 
memory address of args! Lets say I originally had this:

```c
va_start(args, str);
```

and I was calling my formating helper function like this:

```c
ft_format(args, str[++i]);
```

in which I was working like this

function itself: ft_format(va_list args, const char format)
and what I called inside it: ft_write_string(va_arg(args, char *));

What should've been was: 

```c
va_start(&args, str);
ft_format(va_list *args, const char format)
ft_write_string(va_arg(*args, char *));
```

Oh well, basic stuff. But fun project indeed, I'll be coming up with some test stuff because testing is super important thing in coding.
