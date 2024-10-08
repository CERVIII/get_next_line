# Get_next_line

The `get_next_line` project of 42 school aims to create a function in C that reads a line from a file descriptor efficiently.

## Description

The `get_next_line` function allows reading a complete line from a file descriptor each time it is called, returning the line read including the newline character (`\n`) if present. The function should handle multiple calls continuously, allowing successive lines to be read from the file.

## Functions

The project includes the following functions:

- **ft_read_write**: Reads from the file descriptor and saves the content in a buffer until a newline character is found.
- **ft_print**: Extracts and returns the line read from the buffer.
- **ft_cleansave**: Cleans and updates the buffer by removing the line that has already been read.
- **get_next_line**: The main function that coordinates the reading, printing, and cleaning of the buffer.

## Usage

To use the `get_next_line` function, follow these steps:

1. Compile the code along with a main file (`main.c`) that calls `get_next_line`.
2. Open a file using the `open` function to obtain its file descriptor.
3. Call `get_next_line` passing the file descriptor and process the returned line.
4. Repeat the process until `get_next_line` returns `NULL`, indicating there are no more lines to read.

### Example Usage

```c
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    int fd;
    char *line;

    fd = open("example.txt", O_RDONLY);
    if (fd < 0)
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
