# get_next_line

This is a project that implements the `get_next_line` function.

## Description

The `get_next_line` function reads a file descriptor line by line and returns each line as a string. It is implemented in C language and is designed to handle large files efficiently.

## Features

- Reads a file descriptor line by line
- Handles large files efficiently
- Supports multiple file descriptors simultaneously

## Usage

To use the `get_next_line` function in your project, follow these steps:

1. Include the `get_next_line.h` header file in your source code.
2. Compile your project and link it with the implementation file that contains the `get_next_line` function.
3. Call the `get_next_line` function, passing the file descriptor as a parameter.
4. The function will return the next line read from the file descriptor as a string.

```c
#include "get_next_line.h"

int main()
{
    int fd;  // File descriptor
    char *line;

    // Open the file descriptor (fd) here

    while ((line = get_next_line(fd)) != NULL)
    {
        // Process the line here
        
        // Free the line after processing
        free(line);
    }

    // Close the file descriptor (fd) here

    return 0;
}
```

## Installation
To install and use this project, follow these steps:

1. Clone the repository to your local machine using :
```bash
git clone <project repo address>
```
2. Copy the necessary files to your project directory.
3. Include the get_next_line.h header file in your source code.
4. Compile your project and link it with the implementation file that contains the get_next_line function.
5. Use the get_next_line function in your code as described in the Usage section. You can also use the main provided in the `/root` folder of the project.
