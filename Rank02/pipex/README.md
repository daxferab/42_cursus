# 🔗 Pipex - 42 School Project

Welcome to **Pipex**! 🎉 This is a project from **Rank 2** at 42 School that introduces us to the world of **pipes**, **processes**, and **inter-process communication** in Unix systems. The goal is to recreate the behavior of shell pipes using system calls like `pipe()`, `fork()`, `dup2()`, and `execve()`.

This project simulates the shell command: `< file1 cmd1 | cmd2 > file2` 🚀

---

### 📂 Project Structure

pipex/
├── include/pipex.h        # Header file (.h)  
├── src/                   # Source files (.c)  
│   ├── main.c             # Main program logic  
│   ├── processes.c        # Process management  
│   ├── execution.c        # Command execution  
│   └── errorhandler.c     # Error handling  
├── obj/                   # Object files directory  
├── libft/                 # Libft library  
├── .gitignore  
├── Makefile               # Makefile to compile the project  
└── README.md              # This file  

---

### 📜 Function Overview

#### 🎯 Main Functions
- **`main(int argc, char **argv, char **envp)`**: Entry point, validates arguments and orchestrates the pipeline
- **`child_process(int *pipe, char **argv, char **envp)`**: Handles the first command execution
- **`parent_process(int *pipe, char **argv, char **envp)`**: Handles the second command execution

#### 🔧 Utility Functions
- **`execute(char **envp, char *argv)`**: Executes commands using execve()
- **`error(int code)`**: Handles different types of errors
- **`free_split(char **split)`**: Frees memory allocated for split arrays

---

### ⚙️ How It Works

#### 🎯 Program Flow
1. **Argument Validation**: Checks for exactly 4 arguments (input file, cmd1, cmd2, output file)
2. **Pipe Creation**: Creates a pipe for inter-process communication
3. **Process Forking**: Creates child and parent processes
4. **File Redirection**: Redirects input/output using `dup2()`
5. **Command Execution**: Executes commands using `execve()`

#### 🔧 Technical Implementation
- **Pipes**: Used for communication between processes
- **Fork**: Creates separate processes for each command
- **Dup2**: Redirects file descriptors for input/output
- **Execve**: Replaces process image with command execution
- **Wait**: Parent process waits for child completion

---

## 🛠️ How to Use

### 📦 Compilation

To compile the program, run:

```bash
make
```

This will generate the `pipex` executable.

### 🧩 Usage

The program takes exactly 4 arguments:

```bash
./pipex file1 cmd1 cmd2 file2
```

**Where:**
- `file1`: Input file to read from
- `cmd1`: First command to execute
- `cmd2`: Second command to execute  
- `file2`: Output file to write to

### 💡 Usage Examples

#### Basic Example
```bash
./pipex input.txt "grep hello" "wc -l" output.txt
```
*Equivalent to:* `< input.txt grep hello | wc -l > output.txt`

#### More Examples
```bash
# Count lines containing "error" in a log file
./pipex server.log "grep error" "wc -l" error_count.txt

# Extract and sort unique usernames
./pipex users.txt "cut -d: -f1" "sort -u" sorted_users.txt

# Find and count .c files
./pipex file_list.txt "grep '\.c$'" "wc -l" c_files_count.txt
```

---

## 🎯 Key Learning Objectives

- **Process Management**: Understanding how to create and manage processes with `fork()`
- **Inter-Process Communication**: Learning to use pipes for data transfer between processes
- **File Descriptor Manipulation**: Mastering `dup2()` for input/output redirection
- **System Calls**: Working with low-level system functions
- **Command Execution**: Understanding how shells execute commands with `execve()`
- **Error Handling**: Proper error management in system programming

---

## ✅ Project Requirements

- ✅ Handle exactly 4 arguments
- ✅ Create a pipe between two commands
- ✅ Execute commands in separate processes
- ✅ Handle input/output file redirection
- ✅ Proper error handling for all edge cases
- ✅ No memory leaks
- ✅ Handle command not found errors
- ✅ Behave exactly like shell pipes

---

## 🔧 System Calls Used

- **`pipe()`**: Creates a pipe for inter-process communication
- **`fork()`**: Creates a new process
- **`dup2()`**: Duplicates file descriptors for redirection
- **`execve()`**: Executes a command
- **`wait()`**: Waits for child process completion
- **`open()`**: Opens files for reading/writing
- **`close()`**: Closes file descriptors

---

## 🚨 Error Handling

The program handles various error conditions:

- **Invalid arguments**: Wrong number of arguments
- **File errors**: Input file not found, output file creation failed
- **Pipe errors**: Pipe creation failure
- **Fork errors**: Process creation failure
- **Command errors**: Command not found or execution failure
- **Permission errors**: Insufficient file permissions

---

## 🚀 Advanced Features

### Multiple Command Support
While the basic version handles two commands, the implementation can be extended to support multiple commands in a pipeline.

### Here_doc Support (Bonus)
The project can be extended to support here_doc functionality:
```bash
./pipex here_doc LIMITER cmd1 cmd2 file
```

---

## 🔍 Testing

Test your pipex with various commands:

```bash
# Test basic functionality
./pipex /etc/passwd "grep root" "wc -l" output.txt
< /etc/passwd grep root | wc -l

# Compare outputs - they should be identical
```

---

## 💡 Tips for Success

1. **Understand the pipe mechanism** - Data flows from write end to read end
2. **Close unnecessary file descriptors** - Prevent resource leaks
3. **Handle edge cases** - Empty files, non-existent commands, etc.
4. **Test with real shell commands** - Compare behavior with actual pipes
5. **Use proper error codes** - Different errors should have different codes

---

*Made with ❤️ at 42 Madrid*