_Este proyecto ha sido creado como
parte del currículo de 42 por jzaquina._

# Description

it is library with a set of useful functions that will be useful for the 42 cursus.

# Instructions

## execute the main.c ( tests )
```
ccc main.c -L. -lft
```

# Resources

| Resource                                     | Description                                           |
| :------------------------------------------- | :---------------------------------------------------- |
| man                                          | the manual you have in the terminal, part of the libc |
| [ASCII 0-255](https://elcodigoascii.com.ar/) | the ascii code                                        |
| [size_t](https://shorturl.at/wJ7dJ)          | why and when to use it                                |

## Uses of IA
- To answer specific doubts:
  - why isascii(c) checks c to be a 7-bits char if 1 byte has 8-bits?
  - where should I add the includes, in the c file or in the h file and then include the h file in the c file ?
  - what does "void s[.n]" mean and why the linter throws an error ?
  - I call a function that uses write() to print in the standard output, but i use the printf() before and after the function calling. why the two prints by printf() are printed after the function print.

# Libft
| Function                                             | Description                                                                                                                                                          |
| :--------------------------------------------------- | :------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| [ft_isalpha(c)](./ft_isalpha.c)                      | returns 1 if character `c` is alphabetic                                                                                                                             |
| [ft_isdigit(c)](./ft_isdigit.c)                      | returns 1 if character `c` is digit                                                                                                                                  |
| [ft_isalnum(c)](./ft_isalnum.c)                      | returns 1 if character `c` is digit or alphabetic                                                                                                                    |
| [ft_isascii(c)](./ft_isascii.c)                      | returns 1 if character `c` is 7-bit character                                                                                                                        |
| [ft_isprint(c)](./ft_isprint.c)                      | returns 1 if character `c` is  printable                                                                                                                             |
| [ft_strlen(c)](./ft_strlen.c)                        | returns the length of a string ( without \0 character)                                                                                                               |
| [ft_memset(s, c, n)](./ft_memset.c)                  | it changes the first `n` bytes of `s` for `c` char                                                                                                                   |
| [ft_bzero(s, n)](./ft_bzero.c)                       | it changes the first `n` bytes of `s` for `\0` char                                                                                                                  |
| [ft_memcpy(dest, src, n)](./ft_memcpy.c)             | it copies the first `n` bytes of `src` to `dest`                                                                                                                     |
| [ft_memmove(dest, src, n)](./ft_memmove.c)           | same as memcpy, but it works even when the 2 strings overlaps                                                                                                        |
| [ft_strlcpy(dest, src, n)](./ft_strlcpy.c)           | to complete                                                                                                                                                          |
| [ft_strlcat(dest, src, n)](./ft_strlcat.c)           | it apppends the string `src` in `dest`. `size` is the total size of `dest`, it returns the size of final string                                                      |
| [ft_toupper(c)](./ft_toupper.c)                      | it converts `c` to uppercase                                                                                                                                         |
| [ft_tolower(c)](./ft_tolower.c)                      | it converts `c` to lowercase                                                                                                                                         |
| [ft_strchr(s, c)](./ft_strchr.c)                     | it returns the pointer of the FIRST `c` in `s`                                                                                                                       |
| [ft_strrchr(s, c)](./ft_strrchr.c)                   | it returns the pointer of the LAST `c` in `s`                                                                                                                        |
| [ft_strncmp(s1, s2, n)](./ft_strncmp.c)              | it compares the first `n` bytes of two strings and returns -> `s1`- `s2`                                                                                             |
| [ft_memchr(s1, c, n)](./ft_memchr.c)                 | it scans the first `n` bytes of `s` for `c`, it returns the pointer of the first `c` or  `null` if not found                                                         |
| [ft_memcmp(s1, s2, n)](./ft_memcmp.c)                | it scans the first `n` bytes of `s1` and `s2` and returns `s1` - `s2`, if n = 0 it returns 0                                                                         |
| [ft_strnstr(s1, s2, len)](./ft_strnstr.c)            | it scans the first `len` chars of `s1` for `s2` and returns the pointer of the first char or `null` if not found                                                     |
| [ft_calloc(nelem, size)](./ft_calloc.c)              | it saves enough memory for an array of ´nelem´ elements of ´size´ bytes and returns a pointer to the allocated memory, null if integer overflow or 0 if a param is 0 |
| [ft_strdup(str)](./ft_strdup.c)                      | it duplicates ´str´ and saves and return a pointer to the new string                                                                                                 |
| [ft_substr(str, start, len)](./ft_substr.c)          | it returns a substring from `str` starting at `start` char with  `len` size, null if memory allocation fails                                                         |
| [ft_strjoin(s1, s2)](./ft_strjoin.c)                 | it returns a new string concatenating `s1` and `s2`, null if memory allocation fails                                                                                 |
| [ft_split(s, c)](./ft_split.c)                       | it returns a set of substrings given by the split of the string `s` using a delimiter `c`, the last item is a null pointer                                           |
| [ft_itoa(n)](./ft_itoa.c)                            | it returns a string that represents the number `n`                                                                                                                   |
| [ft_strmapi(s, fn)](./ft_strmapi.c)                  | it returns a string with all chars of `s` but mapped using `fn` function                                                                                             |
| [ft_striteri(s, fn)](./ft_striteri.c)                | it iterates on `s` and apply the `fn` function on every character                                                                                                    |
| [ft_putchar_fd(c, fd)](./ft_putchar_fd.c)            | it uses a file descriptor `fd` to add a char `c`                                                                                                                     |
| [ft_putstr_fd(s, fd)](./ft_putstr_fd.c)              | it uses a file descriptor `fd` to add a string `s`                                                                                                                   |
| [ft_putendl_fd(s, fd)](./ft_putendl_fd.c)            | it uses a file descriptor `fd` to add a string `s` + `\n`                                                                                                            |
| [ft_putnbr_fd(s, fd)](./ft_putnbr_fd.c)              | it uses a file descriptor `fd` to add a number `n`                                                                                                                   |
| [ft_lstnew(cnt)](./ft_lstnew.c)                      | it creates a new node and returns a pointer to it, use `cnt` as content and `null` as next by default                                                                |
| [ft_lstadd_front(lst, newnode)](./ft_lstadd_front.c) | it creates a new node `newnode` and add it to the list `lst` at the first position                                                                                   |
| [ft_lstsize(lst)](./ft_lstsize.c)                    | it returns the number of nodes of the list `lst`                                                                                                                     |
| [ft_lstlast(lst)](./ft_lstlast.c)                    | it returns the last node of the list `lst`                                                                                                                           |
| [ft_lstadd_back(lst)](./ft_lstadd_back.c)            | it creates a new node `newnode` and add it to the list `lst` at the end                                                                                              |
| [ft_lstdelone(lst, del())](./ft_lstdelone.c)         | it frees the memory of the content using the function `del` and also the memory of the node itself                                                                   |
| [ft_lstclear(lst, del())](./ft_lstclear.c)           | it frees the memory of all the nodes of a list and the list itself                                                                                                   |
| [ft_lstiter(lst, fn())](./ft_lstiter.c)              | it iterates all the list nodes and apply the function `fn` to each content                                                                                           |
