# 📖 Get Next Line - 42 School Project

Welcome to **Get Next Line (GNL)**! 🎉 This is a crucial project in **Rank 1** at 42 School that teaches us how to read files line by line using file descriptors. This project is essential for understanding file I/O operations and memory management in C.

The function reads from a file descriptor and returns one line at a time, making it perfect for processing large files efficiently without loading the entire file into memory. 🚀

---

### 📂 Project Structure

get_next_line/
├── get_next_line.h        # Header file (.h)  
├── get_next_line.c        # Main GNL function  
├── get_next_line_utils.c  # Utility functions  
├── .gitignore  
└── README.md              # This file  

---

### 📜 Function Overview

#### 🎯 Main Function
- **`get_next_line(int fd)`**: The core function that reads and returns one line at a time from a file descriptor

#### 🔧 Utility Functions
- **`ft_findnl(char *str)`**: Finds the position of a newline character in a string
- **`ft_strjoin(char *s1, char *s2)`**: Joins two strings together (custom implementation)
- **`ft_getline(char *str)`**: Extracts a line from the static buffer
- **`ft_updatestatic(char *str)`**: Updates the static variable after extracting a line
- **`ft_strlen(char *str)`**: Returns the length of a string (custom implementation)
- **`ft_calloc(size_t count, size_t size)`**: Allocates memory and initializes it to zero
- **`ft_read(int fd, char *remainder, char *buffer)`**: Reads data from file descriptor

---

### ⚙️ Key Features

#### 🎯 Functionality
- ✅ **Line-by-line reading**: Returns one line at a time, including the newline character
- ✅ **Multiple file descriptors**: Can handle multiple files simultaneously
- ✅ **Efficient memory usage**: Only reads what's necessary using a configurable buffer
- ✅ **EOF handling**: Properly handles end-of-file conditions
- ✅ **Error handling**: Returns NULL on error or when reaching EOF

#### 🔧 Technical Details
- **Static variables**: Uses static variables to maintain state between function calls
- **Dynamic buffer size**: Configurable `BUFFER_SIZE` via compilation flags
- **Memory management**: Proper allocation and deallocation to prevent memory leaks
- **File descriptor support**: Works with files, stdin, and other file descriptors

---

## 🛠️ How to Use

### 📦 Compilation

To compile the function with your project, include both source files:

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c your_main.c -o your_program
```

You can adjust the `BUFFER_SIZE` to optimize for your specific use case.

### 🧩 Include in Your Project

Include the header file in your code:

```c
#include "get_next_line.h"
```

### 💡 Usage Example

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd;
    char *line;
    
    // Open a file
    fd = open("example.txt", O_RDONLY);
    if (fd == -1)
        return (1);
    
    // Read file line by line
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);  // Don't forget to free each line!
    }
    
    close(fd);
    return (0);
}
```

### 📋 Reading from Standard Input

```c
#include "get_next_line.h"

int main(void)
{
    char *line;
    
    printf("Enter lines (Ctrl+D to exit):\n");
    while ((line = get_next_line(0)) != NULL)  // 0 = stdin
    {
        printf("You entered: %s", line);
        free(line);
    }
    
    return (0);
}
```

---

## 🎯 Key Learning Objectives

- **File I/O Operations**: Understanding how to read from file descriptors
- **Static Variables**: Learning to maintain state between function calls
- **Memory Management**: Proper allocation, reallocation, and deallocation
- **Buffer Management**: Efficient handling of data buffers
- **Error Handling**: Robust error checking and edge case management
- **System Calls**: Working with low-level system functions like `read()`

---

## ✅ Project Requirements

- ✅ Read line by line from any valid file descriptor
- ✅ Return the line including the newline character (when present)
- ✅ Return NULL when EOF is reached or an error occurs
- ✅ Work with different buffer sizes (configurable at compile time)
- ✅ Handle multiple file descriptors simultaneously
- ✅ No memory leaks
- ✅ Only allowed functions: `read`, `malloc`, `free`

---

## 🔧 Buffer Size Optimization

The `BUFFER_SIZE` can be adjusted based on your needs:

- **Small files**: `BUFFER_SIZE=1` (character by character)
- **Large files**: `BUFFER_SIZE=4096` or `BUFFER_SIZE=8192` (more efficient)
- **Memory-constrained**: `BUFFER_SIZE=42` (balanced approach)

Example compilation with different buffer sizes:
```bash
gcc -D BUFFER_SIZE=1 get_next_line.c get_next_line_utils.c main.c
gcc -D BUFFER_SIZE=4096 get_next_line.c get_next_line_utils.c main.c
```

---

## 🚨 Important Notes

- **Memory Management**: Always free the returned line after use
- **File Descriptors**: Remember to close file descriptors when done
- **NULL Handling**: Check for NULL return values to handle EOF and errors
- **Multiple FDs**: Each file descriptor maintains its own static buffer

---

## 🚀 Advanced Usage

### Reading Multiple Files Simultaneously

```c
int fd1 = open("file1.txt", O_RDONLY);
int fd2 = open("file2.txt", O_RDONLY);

char *line1 = get_next_line(fd1);  // Read from file1
char *line2 = get_next_line(fd2);  // Read from file2
char *line1_2 = get_next_line(fd1); // Read next line from file1

// Process lines...
free(line1);
free(line2);
free(line1_2);
```

---

*Made with ❤️ at 42 Madrid*