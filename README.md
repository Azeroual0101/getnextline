# get_next_line

**42 Network | 1337 Coding School | C Programming**

## 📖 Overview

**get_next_line** is a C programming project developed as part of the 42 Network curriculum at 1337 Coding School.

The goal is to implement a function that reads and returns one line at a time from a file descriptor, using a configurable buffer size.

This project focuses on file handling, static variables, memory allocation, and buffered reading.

## ✨ Features

- Reads files line by line.
- Supports configurable buffer sizes.
- Preserves unread data between function calls using static variables.
- Handles lines of different lengths, including lines without a trailing newline.
- Supports reading from standard input.
- Handles end-of-file and reading errors.
- **Bonus:** Supports reading from multiple file descriptors independently.

## 🛠️ Technologies & Concepts

- **Language:** C
- **System calls:** `read()`
- **Memory management:** `malloc()`, `free()`
- **Core concepts:** File descriptors, static variables, buffers, string manipulation

## 📂 Project Structure

```text
get_next_line/
├── get_next_line.c              # Main line-reading function
├── get_next_line.h              # Mandatory header
├── get_next_line_utils.c        # String utility functions
├── get_next_line_bonus.c        # Multiple file descriptor support
├── get_next_line_bonus.h        # Bonus header
└── get_next_line_utils_bonus.c  # Bonus utility functions
```

## ⚙️ Compilation

Clone the repository:


The project provides a function rather than a standalone executable. To test it, create a separate `main.c` file.

### Mandatory Part

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
get_next_line.c get_next_line_utils.c main.c -o gnl
```

### Bonus Part

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
get_next_line_bonus.c get_next_line_utils_bonus.c main.c -o gnl_bonus
```

## 💻 Usage

Function prototype:

```c
char *get_next_line(int fd);
```

Example:

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int fd;
    char *line;

    fd = open("example.txt", O_RDONLY);
    if (fd == -1)
        return (1);

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

Compile and execute:

```bash
./gnl
```

## 🧠 How It Works

1. **Read:** Fetch up to `BUFFER_SIZE` bytes using `read()`.
2. **Store:** Keep the retrieved characters in a persistent buffer.
3. **Search:** Look for the newline character (`\n`).
4. **Extract:** Return the next complete line.
5. **Preserve:** Save any remaining characters for subsequent calls.
6. **Repeat:** Continue until the end of the file.

## 🚀 Bonus: Multiple File Descriptors

The bonus implementation allows independent reading from several file descriptors.

```c
char *line1 = get_next_line(fd1);
char *line2 = get_next_line(fd2);
char *line3 = get_next_line(fd1);
```

Each file descriptor maintains its own unread data, allowing calls to alternate between files without losing the reading position.

## 🧪 Testing

Recommended test cases:

- Empty files
- Single-line and multiline files
- Files without a final newline
- Very long lines
- Different `BUFFER_SIZE` values (1, 42, 1024)
- Invalid file descriptors
- Interleaved reads from multiple file descriptors
- Memory leaks

On Linux, memory leaks can be checked with Valgrind:

```bash
valgrind --leak-check=full ./gnl
```

## 🎯 Learning Outcomes

This project strengthens understanding of:

- File descriptors and low-level file I/O
- Static variable lifetime and persistence
- Dynamic memory allocation
- Buffer management
- String manipulation
- Error handling and memory safety
- Multiple input stream management

## 📚 References

- [42 School](https://42.fr/en/homepage/)
- [read(2) — Linux Manual](https://man7.org/linux/man-pages/man2/read.2.html)
- [malloc(3) — Linux Manual](https://man7.org/linux/man-pages/man3/malloc.3.html)

---

**1337 Coding School — 42 Network**
