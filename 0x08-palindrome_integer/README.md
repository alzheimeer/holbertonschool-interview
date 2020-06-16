# 0x08. Palindrome integer


<article id="description" class="gap formatted-content"><h2>Requirements</h2><h3>General</h3><ul><li>Allowed editors: <code>vi</code>, <code>vim</code>, <code>emacs</code></li><li>All your files will be compiled on Ubuntu 14.04 LTS</li><li>Your programs and functions will be compiled with <code>gcc 4.8.4</code> using the flags <code>-Wall</code>¨NBSP;<code>-Werror</code><code>-Wextra</code><code>and -pedantic</code></li><li>All your files should end with a new line</li><li>Your code should use the <code>Betty</code> style. It will be checked using <a href="https://github.com/holbertonschool/Betty/blob/master/betty-style.pl" title="betty-style.pl" target="_blank">betty-style.pl</a> and <a href="https://github.com/holbertonschool/Betty/blob/master/betty-doc.pl" title="betty-doc.pl" target="_blank">betty-doc.pl</a></li><li>You are not allowed to use global variables</li><li>No more than 5 functions per file</li><li>In the following examples, the <code>main.c</code> files are shown as examples. You can use them to test your functions, but you don’t have to push them to your repo (if you do we won’t take them into account). We will use our own <code>main.c</code> files at compilation. Our <code>main.c</code> files might be different from the one shown in the examples</li><li>The prototypes of all your functions should be included in your header file called <code>palindrome.h</code></li><li>Don’t forget to push your header file</li><li>All your header files should be include guarded</li></ul></article>

---

## Tasks



<h4 class="modal-title">Students who are done with "0. Palindrome unsigned integer"</h4>

<h4 class="task"> 0. Palindrome unsigned integer <span class="alert alert-warning mandatory-optional"> mandatory </span></h4>
<p>Write a function that checks whether or not a given unsigned integer is a palindrome.</p><ul><li>Prototype: int is_palindrome(unsigned long n);</li><li>Where n is the number to be checked</li><li>Your function must return 1 if n is a palindrome, and 0 otherwise</li><li>You are <strong>not allowed</strong> to allocate memory dynamically (malloc, calloc, …)</li></ul>

```
alex@~/0x08-palindrome_integer$ cat 0-main.c 
#include <stdlib.h>
#include <stdio.h>

#include "palindrome.h"

/**
 * main - Entry point
 *
 * @ac: Arguments counter
 * @av: Arguments vector
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int ac, char **av)
{
    unsigned long n;
    int ret;

    if (ac < 2)
    {
        fprintf(stderr, "Usage: %s arg\n", av[0]);
        return (EXIT_FAILURE);
    }

    n = (unsigned long)(atol(av[1]));
    ret = is_palindrome(n);

    printf("%lu is ", n);
    if (ret == 0)
        printf("not ");
    printf("a palindrome.\n");

    return (EXIT_SUCCESS);
}
alex@~/0x08-palindrome_integer$ gcc -Wall -Wextra -Werror -pedantic -g3 -o palindrome 0-main.c 0-is_palindrome.c
alex@~/0x08-palindrome_integer$ ./palindrome 1
1 is a palindrome.
alex@~/0x08-palindrome_integer$ ./palindrome 11
11 is a palindrome.
alex@~/0x08-palindrome_integer$ ./palindrome 112
112 is not a palindrome.
alex@~/0x08-palindrome_integer$ ./palindrome 121
121 is a palindrome.
alex@~/0x08-palindrome_integer$ ./palindrome 12345678987654321
12345678987654321 is a palindrome.
alex@~/0x08-palindrome_integer$ ./palindrome 123456789987654321
123456789987654321 is a palindrome.
alex@~/0x08-palindrome_integer$ ./palindrome 1234567898654321
1234567898654321 is not a palindrome.
alex@~/0x08-palindrome_integer$

```


<strong>Repo:</strong></p>

<ul><li>GitHub repository: <code>holbertonschool-interview</code></li>
<li>Directory: <code>0x08-palindrome_integer</code></li><li>File: <code>0-is_palindrome.c, palindrome.h</code></li></ul><div class="student_correction_requests">



     