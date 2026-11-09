*This project has been created as part of the 42 curriculum by abronner*

libft
=====

## Description

This project compiles a static library that provides a set of functions from the standard C library plus a couple of additional functions required by the subject.

The project is intended to provided an introduction to C programming (working with strings, pointers, etc), compilation of C libraries, and usage of build systems like GNU Make.

The library is used throughout most of 42's core curriculum and got a couple of additions with projectes being built on top of the library and latter added to if (f.e. ft_printf).

The main takeaway from the project for me was the introduction to proper documentation of functions, interation with arrays (strings), usage of pointers for data or functions (striteri, strmapi), first interactions with dynamic memory allocation (calloc, realloc), and linked lists as a way to create dynamically growing data structures.

Over time and progression in the Core curriculum the library was modified since the original (restircted) requirements of the library weren't necessary to uphold and the functions were adjusted to my needs, resulting in a wider set of `ctype` functions, modifications to the list structure, etc.

With a growing set of functions beign added to the library the code was split into differnet sets that could individually be compiled and added into the library if needed to avoid the need to compile the whole library with unecessary functions.

## Instructions

To build this library we were instructed to read the Man pages for a given set of functions and implement the functions as they were described in the Man pages. The set of was to be compiled into a static library that could be linked with other programs.

The functions from the libc we were supposed to implement are:

* isalpha
* memcpy
* strrchr
* isdigit
* memmove
* strncmp
* isalnum
* isascii
* isprint
* strlen
* strlcpy
* memchr
* strlcat
* memcmp
* toupper
* memset
* tolower
* strnstr
* bzero
* strchr
* atoi
* calloc
* strdup

The non-libc functions that we were supposed to implement in addition were:

* ft_substr
* ft_strjoin
* ft_strtim
* ft_split
* ft_itoa
* ft_strmapi
* ft_striteri
* ft_putchar_fd
* ft_pustst_fd
* ft_putendl_fd
* ft_putnbr_fd

Outside of these functions a couple of functions that operate on linked lists were supposed to be implemnted:

* ft_lstnew
* ft_lstadd_front
* ft_lstsize
* ft_lstadd_back
* ft_lstdelone
* ft_lstclear
* ft_lstmap

## Resources

For the creation of this project the Man pages for the different functions were consulted. The GNU Make documentation was used for the creation of the Makefile. 
