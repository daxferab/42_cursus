*This project has been created as a part of the 42 curriculum by daxferna*
# 🐚 Minishell 🐚

Welcome to **Minishell**! 🎉 This is one of the most challenging projects at 42 School, where we recreate a functional Unix shell from scratch. This project challenges us to implement command parsing, execution, signal handling, and all the core features that make a shell work.

The goal is to create a shell that behaves like **bash**, handling commands, pipes, redirections, environment variables, and built-in commands!

---

## 🛠️ How to Use

### 📦 Compilation

To compile the shell, run:

```bash
make
```

This will generate the `minishell` executable.

### 🧩 Usage

Launch the shell:

```bash
./minishell
```

You'll see the custom prompt:
```
SMASH -> 
```

---

### 🚀 Features Implemented

#### 🛠️ Built-in Commands
- **`echo`** - Display text (with -n option support)
- **`cd`** - Change directory (relative and absolute paths)
- **`pwd`** - Print current working directory
- **`export`** - Set environment variables
- **`unset`** - Remove environment variables
- **`env`** - Display environment variables
- **`exit`** - Exit the shell (with exit codes)

#### 🔗 Advanced Shell Features
- **Pipes** (`|`) - Chain commands together
- **Input redirection** (`<`) - Redirect input from files
- **Output redirection** (`>`) - Redirect output to files
- **Append redirection** (`>>`) - Append output to files
- **Here documents** (`<<`) - Multi-line input with delimiters
- **Variable expansion** (`$VAR`, `$?`) - Expand environment variables and exit codes
- **Quote handling** - Single quotes, double quotes, and escaping
- **Signal handling** - Ctrl+C, Ctrl+D, Ctrl+\ behavior
- **Command history** - Navigate through previous commands

---

### 🧠 Core Components

#### 🎯 Parsing Engine
- **Tokenization**: Breaks input into tokens (commands, operators, arguments)
- **Syntax validation**: Checks for proper shell syntax
- **Variable expansion**: Handles `$VAR` and `$?` expansions
- **Quote processing**: Manages single and double quotes
- **Pipeline creation**: Builds command pipeline structures

#### 🔧 Execution Engine
- **Built-in detection**: Identifies and executes built-in commands
- **External commands**: Finds and executes system commands
- **Pipeline execution**: Handles pipes between commands
- **Redirection handling**: Manages input/output redirections
- **Process management**: Forks and manages child processes

#### 🌍 Environment Management
- **Variable storage**: Maintains environment variables
- **Variable expansion**: Expands variables in commands
- **Export/unset**: Manages variable lifecycle
- **Exit code tracking**: Maintains `$?` variable

---

### 💡 Usage Examples

#### Basic Commands
```bash
SMASH -> echo "Hello, World!"
Hello, World!

SMASH -> pwd
/home/user/minishell

SMASH -> ls -la
# Lists directory contents

SMASH -> cd ..
SMASH -> pwd
/home/user
```

#### Environment Variables
```bash
SMASH -> export NAME="42 Student"
SMASH -> echo $NAME
42 Student

SMASH -> env | grep NAME
NAME=42 Student

SMASH -> unset NAME
SMASH -> echo $NAME
# (empty output)
```

#### Pipes and Redirections
```bash
# Simple pipe
SMASH -> ls | grep ".c"

# Output redirection
SMASH -> echo "Hello" > output.txt
SMASH -> cat output.txt
Hello

# Input redirection
SMASH -> cat < input.txt

# Append redirection
SMASH -> echo "World" >> output.txt

# Here document
SMASH -> cat << EOF
> Line 1
> Line 2
> EOF
Line 1
Line 2
```

#### Complex Pipelines
```bash
# Multiple pipes
SMASH -> ls -la | grep ".c" | wc -l

# Mixed redirections and pipes
SMASH -> cat file.txt | grep "pattern" > results.txt

# Variable expansion
SMASH -> export PATH_BACKUP=$PATH
SMASH -> echo $PATH_BACKUP
```

---

## 🚨 Error Handling

The shell handles various error conditions:

- **Syntax errors**: Invalid command syntax
- **Command not found**: Non-existent commands
- **Permission denied**: Insufficient permissions
- **File not found**: Missing input files
- **Pipe errors**: Broken pipes
- **Memory allocation**: Out of memory conditions
- **Signal interruption**: Graceful signal handling

---

## 🏆 Project Challenges

- **Parsing complexity**: Handling quotes, variables, and special characters
- **Signal management**: Proper signal handling in different contexts
- **Memory management**: Preventing leaks in complex data structures
- **Process synchronization**: Managing multiple processes and pipes
- **Error compatibility**: Matching bash error messages and behavior
