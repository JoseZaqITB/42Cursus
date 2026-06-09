_Este proyecto ha sido creado como
parte del currículo de 42 por jzaquina._

# Description

This is a project that imitates the functionality of the printf C function.

Its primary purpose is to parse a format string, print characters to the standard output, handle specific % format specifiers by fetching variable arguments, and return the total number of characters printed.

Here is a breakdown of the algorithm, split by its two functions.

# Instructions

In order to use it you should first create the library with

## Create library
```
make
```
This will create all the .o files and the library libftprintf.a ( with all the libft functions )
Then you can compile your main file

if you want to ged rid of the .o files
```
make clean
```
if you want to remove the .a file
```
make fclean
```

and for a remake
```
make re
```

## execute the main.c
```
ccc main.c -L. -lftprintf -I.
```

# Resources

| Resource                                                                                                                                                  | Description                  |
| :-------------------------------------------------------------------------------------------------------------------------------------------------------- | :--------------------------- |
| [Makefile Tutorial](https://www.youtube.com/watch?v=BD0giwqBbm0&t=1800s)                                                                                  | How to create your make file |
| [Variadic Functions](https://www.makigas.es/series/tutorial-de-c/funciones-variadicas)                                                                    | What's variadic functions    |
| [About Printf](https://www.microfocus.com/documentation/silk-test/200/en/silktestclassic-help-en/index.html?t=STCLASSIC-B0791748-PRINTFFUNCTION-REF.html) | How does printf works?       |

## Uses of IA
- how to compile a makefile from a makefile.
- Uses of stdlib, unistd, stddef, stdint
- What are the uses of a library .a in C
- How to get tha maximum number of int programmaticly

# Algorithm and Data Structure

Here is a breakdown of the algorithm, split by its two functions.

### 1. Main Controller: ft_printf
This function acts as the coordinator. It initializes the variable argument list and iterates through the input string character by character.

Step-by-Step Logic
1. Initialization: It sets a counter n = 0 to track the total number of printed characters.

- It initializes the variadic arguments using va_start(vargs, str).

2. The Parsing Loop: It loops through the string str until it hits the null-terminator (\0).

- Case A: Format Specifier (*str == '%')

		- It immediately increments the string pointer (++str) to see the character after the % (the format type).

		- It passes this type and the argument list to printvar.

		- The number of characters printed by printvar is added to the total count n.

- Case B: Regular Character

		- It prints the character directly using ft_putchar_fd(*str, 1).

		- It increments the total count n by 1.

3. Advance: The str++ at the bottom of the loop moves the pointer to the next character for the next iteration.

4. Cleanup & Return: Once the string ends, it cleans up the variadic list with va_end(vargs) and returns the total count n.

### 2. The Dispatcher: printvar
This helper function handles the actual formatting and printing of the arguments based on the specifier passed to it. It defaults the character count c = 1 (since most single prints or percent signs equal 1 character) and overwrites it if a helper function returns a different length.

Argument Routing Table
Depending on the type char, the algorithm extracts the next argument from va_list using va_arg and routes it to a specific helper function:

| Specifier (type) | Expected Data Type | Action / Helper Function |
| :--- | :--- | :--- |
| `'c'` | `int` (promoted from `char`) | Prints a single character using `ft_putchar_fd`. |
| `'s'` | `char *` | Prints a string via `ft_putstr_count`; returns string length. |
| `'p'` | `unsigned long` | Prints a memory address pointer in hexadecimal via `ft_putptr_count`. |
| `'d'` or `'i'` | `int` | Prints a signed base-10 integer via `ft_putnbr_count`. |
| `'u'` | `unsigned int` | Prints an unsigned base-10 integer via `ft_putunbr_count`. |
| `'x'` | `unsigned int` | Prints a lowercase hexadecimal number via `ft_putnbrhex_count`. |
| `'X'` | `unsigned int` | Prints an uppercase hexadecimal number via `ft_putnbrhex_count`. |
| `'%'` | `None` | Prints a literal `%` character using `ft_putchar_fd`. |

Step-by-Step Logic
- It checks the type character against the list of supported specifiers using an if/else if chain.

- For the matched type, it retrieves the correct data type from va_list.

- It calls the respective helper function to print the data and captures how many characters that function printed into c.

- It returns c back to ft_printf.
