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

The core logic of `get_next_line` is divided into four main modular functions. Each handles a specific phase of the reading, extraction, and memory lifecycle to ensure stability across multiple file descriptors and high buffer sizes.

---

### 1. `get_next_line(int fd)`
* **Description:** The entry point of the module. It orchestrates the line extraction process and maintains state between function calls.
* **Key Mechanics:**
  * Uses a static pointer array `static char *leftover[FD_SETSIZE]` to store unread buffer data individually for each open file descriptor.
  * Validates the input parameters (`fd` range and `BUFFER_SIZE > 0`).
  * Triggers the reading engine (`read_and_stash`), pulls the next available line (`extract_line`), and updates the persistent storage (`save_leftover`).

---

### 2. `read_and_stash(int fd, char *stash)`
* **Description:** Reads chunks of data from the file descriptor into a heap buffer until a newline (`\n`) character is found or the end of the file (EOF) is reached.
* **Key Mechanics:**
  * Dynamically allocates a buffer of size `BUFFER_SIZE + 1`.
  * Loops with `read()` calls, continuously joining newly read strings onto the existing `stash`.
  * Safely frees temporary intermediate strings during the `ft_strjoin` loops to prevent memory leaks.
  * Handles read errors by clearing allocated memory and returning `NULL`.

---

### 3. `extract_line(char *stash)`
* **Description:** Scans the accumulated `stash` string to isolate and extract a single, complete line to be returned to the caller.
* **Key Mechanics:**
  * Searches for the index of the first occurrence of `\n`.
  * Extracts the string from index `0` up to and including the newline character (if present) using `ft_substr`.
  * Returns `NULL` if the input `stash` is empty or invalid.

---

### 4. `save_leftover(char *stash)`
* **Description:** Cleans up the `stash` by trimming away the line that was just extracted, retaining only the remaining data for future calls.
* **Key Mechanics:**
  * Finds the position of the `\n` character and isolates everything *after* it.
  * Creates a new heap-allocated string containing only the leftover characters.
  * Frees the old `stash` memory to avoid dangling pointers and leaks.
  * Returns `NULL` and frees memory if no leftover data remains.
