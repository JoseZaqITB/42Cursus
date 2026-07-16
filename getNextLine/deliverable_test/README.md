_Este proyecto ha sido creado como parte del currículo de 42 por jzaquina._

# Description

This is a project that returns a line of a string/text.

when you give a file descriptor as parameter the function will start to read all the content and it will look for a breakline, when found it, the function will return you the entire line until the breakline. Then, when you call it again, it will remember the last position of the breakline and it will start from there to find the next line.


Step-by-Step Flow:
Check for Leftovers: If there is data saved from the previous run (stored in the static variable), we start with that. If not, we perform an initial read from the file.

Read Until Newline: We look for a \n in our current data. If we don't find it, we keep reading from the fd and appending the new data to our accumulated string until a \n (or EOF) is found.

Extract the Line: Once we know where the newline is, we slice the string from the beginning up to that newline to return it.

Save the Leftovers: We slice everything after the newline and store it back into our static variable so it's ready for the next time get_next_line is called.

# Instructions

To use it, you will need to compile all the .c files

## execute the main.c
```
ccc ./*.c -I.
```

# Resources

| Resource                                                                                                                          | Description              |
| :-------------------------------------------------------------------------------------------------------------------------------- | :----------------------- |
| [File Descriptor](https://medium.com/@dhzdynamic/file-handling-in-c-exploring-i-o-system-calls-and-file-descriptors-b581b42616f8) | How a fd works           |
| [Static Variables](https://www.youtube.com/watch?v=Hm5Jc7ajZsk)                                                                   | Uses of static variables |
| [Preprocesador y Macros](https://www.youtube.com/watch?v=teamA4rft1E)                                                                   | What is exactly the BUFFER_SIZE ? |

## Uses of IA
- what is the use of static in variables.
- Diferent ways of remember read content.
- how file descriptors works internally, is it possible to remember the last read char position?

## Details and Algorithm

### get_next_line(int fd)
Purpose: The main conductor of the operation. It manages the lifecycle of the string extraction and maintains state between function calls using a static variable.

How it works: * It initializes or recovers the data (tempbuffer) using the static pointer leftover.

It calls readbreakline to find out exactly where the current line ends.

It uses ft_substr to extract the line to return, and updates leftover using ft_substr_from to hold any remaining characters for the next call.

### readline(int fd)
Purpose: A helper function that reads a small chunk of data (up to BUFFER_SIZE) from the file.

How it works: * Allocates a stack-based buffer of size BUFFER_SIZE + 1.

Calls read(). If it hits EOF or an error, it returns 0.

Null-terminates the buffer at readcount and duplicates it into a heap-allocated string via ft_strjoin("", &buffer[0]) so it can be safely manipulated and freed later.

### get_breakline(const char *s)
Purpose: Scans a single string to find the index of the first newline character (\n).

How it works: * Loops through the string s.

If it finds \n, it immediately returns its index (i).

If it hits the null-terminator (\0) without finding a newline, it returns -1.

### readbreakline(int fd, char s)
Purpose: The engine that driving the reading loop. It ensures that the accumulation string *s contains at least one newline or has reached the end of the file.

How it works: * It checks if a newline exists in the current chunk using get_breakline.

If no newline is found, it updates breakpos (keeping track of the total characters scanned so far), reads the next chunk with readline, joins it to the accumulating string *s, and loops again.

Once a newline is found, it calculates and returns the absolute index of the newline relative to the start of the whole accumulated string.

### ft_substr_from(char *s, int start)
Purpose: A syntactic sugar wrapper around your standard ft_substr.

How it works: It extracts everything from the index start right up to the very end of the string s. This is specifically used to isolate the remaining data for the leftover static variable.
