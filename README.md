# SPL01 System Programming in Linux - Unix Utilities

This repository contains custom, simplified implementations of standard Unix utilities written in C. This project is part of the **SPL01 System Programming in Linux** course.

Each utility is implemented in a separate `.c` file and utilizes Linux system calls and standard C library routines.

## Utilities Included

1. `pwd` - Prints the absolute path of the current working directory.
2. `echo` - Prints user input strings to standard output, separated by spaces.
3. `cp` - Copies a source file to an explicit destination path.
4. `mv` - Moves or renames a file to an explicit destination path.

---

## Compilation Instructions

You can compile each utility separately using the GNU Compiler Collection (`gcc`).

Run the following commands in your terminal:

```bash
# Compile pwd
gcc pwd.c -o my_pwd

# Compile echo
gcc echo.c -o my_echo

# Compile cp
gcc cp.c  -o my_cp

# Compile mv
gcc mv.c -o my_mv
```

---

## Example Usage and Output

### 1. `pwd`

Prints the absolute path of the current working directory.

```bash
$ ./my_pwd
/home/user/spl01-assignments
```

### 2. `echo`

Prints the provided arguments separated by spaces, followed by a newline.

```bash
$ ./my_echo Hello World
Hello World
```

### 3. `cp`

Copies the contents of a source file to an explicit destination path.

```bash
$ echo "Test content" > file.txt
$ ./my_cp file.txt /tmp/file_copy.txt
$ cat /tmp/file_copy.txt
Test content
```

### 4. `mv`

Moves a file from the source path to an explicit destination path.

```bash
$ touch /tmp/file.txt
$ ./my_mv /tmp/file.txt /tmp/new_name.txt
$ ls /tmp/new_name.txt
/tmp/new_name.txt
```

---

## Requirements

* Linux operating system
* GCC compiler
* Standard C development tools

## Notes

These utilities are simplified educational implementations intended for the **SPL01 System Programming in Linux** course. Their behavior may not exactly match the full-featured Unix/Linux versions of the corresponding commands.
