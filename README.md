# get_next_line
**get_next_line** is a function that reads and returns a line from a file descriptor. This README provides details on the implementation, usage, and compilation instructions for the project.
### Function Prototype
``
char *get_next_line(int fd);
``
### Description
The **get_next_line** function reads from the file descriptor fd and returns the next line from the file.
Repeatedly calling get_next_line in a loop allows reading the file line by line until the end.
The function returns the line that has just been read.
If there is nothing more to read or an error occurs, it returns **NULL**.
The function should work properly when reading from both a file and stdin.
The returned line should end with the newline character **\n**, except if the end of the file is reached and it does not end with a newline.
### Parameters
**fd**: The file descriptor from which to read.
### Return Value
* Returns the line read if successful.
* Returns **NULL** in case of an error or when the end of the file is reached.
### Allowed Functions
* **read**
* **malloc**
* **free**
### Project Files
* **get_next_line.c**
* **get_next_line_utils.c**
* **get_next_line.h**
### Header File
The **get_next_line.h** header file should at least contain the prototype for the **get_next_line** function.
### Helper Functions
Add any necessary helper functions in the **get_next_line_utils.c** file.
### Buffer Size
the program must compile with the flag **-D BUFFER_SIZE=xx**. This flag will be used to set the buffer size for the reads in **get_next_line()**. This parameter will be changed by evaluators and the testing system to test the program.
The project must compile with and without the **-D BUFFER_SIZE** flag, along with the usual flags. You can choose any default buffer size.
### Compilation
Compile the project with the following command (using a buffer size of 42 as an example):  
``
cc -Wall -Werror -Wextra -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o get_next_line
``
### Usage
To use the get_next_line function in your project, include the **get_next_line.h** header and compile thr project with the appropriate source files. Below is an example:
````
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
    int fd = open("example.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }

    char *line;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    close(fd);
    return 0;
}
````
### Notes
* **get_next_line()** has undefined behavior if the file pointed to by **fd** changes after the last call, provided **read()** has not reached the end of the file.
* **get_next_line()** has undefined behavior when reading a binary file.
## _Bonus Part_
After completing the mandatory part, you can further enhance the functionality of get_next_line with these additional features:
### Bonus Requirements
* Implement **get_next_line()** using only one static variable.
* **get_next_line()** should be able to manage multiple file descriptors simultaneously. For example, if you have * * three file descriptors (e.g., 3, 4, and 5), you should be able to use **get_next_line** on fd 3, then on fd 4, and then on fd 5 alternately, without losing the reading thread of each **fd**.
### Bonus Files
In addition to the mandatory files, you need to deliver the following files for the bonus part:
get_next_line_bonus.c
get_next_line_bonus.h
get_next_line_utils_bonus.c
### Compilation for Bonus Part
Compile the bonus part with the following command (using a buffer size of 42 as an example):  
``cc -Wall -Werror -Wextra -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c -o get_next_line_bonus``
### Usage for Bonus Part
The usage remains the same as the mandatory part, but now **get_next_line** can handle multiple file descriptors.
### *Acknowledgements*
This project is part of the curriculum at [42 Madrid](https://www.42madrid.com/). Thanks to the 42 Network for providing the resources and guidance to complete this project.

