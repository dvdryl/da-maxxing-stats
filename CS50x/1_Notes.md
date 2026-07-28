# Week 1 &emsp; CS50x 2026
July 25, 2026 &emsp; &emsp; [Official notes](https://cs50.harvard.edu/x/notes/1/)

&nbsp;

In Week 0 we learned Scratch, a visual/drag-and-block programming language. Week 1 is about taking those same building blocks (functions, conditionals, loops, variables) and using them in an actual text-based language called **C**.



## Source code vs machine code

- **source code** - code that humans can read and write, like the C code we type ourselves
- **machine code** - the binary (1s and 0s) that the computer itself understands
- a **compiler** is a special program that converts source code into machine code

```
source code -> [compiler] -> machine code
```

so basically, we write in a language we understand, and the compiler translates it into a language the machine understands.



## GUI vs CLI

- **GUI** (graphical user interface) - the visual system with windows, icons, a file explorer, and buttons you click
- **CLI** (command line interface) - a text-based way to send commands directly to the computer, also called the "terminal" or "command line"

CS50 uses an online IDE (code editor) called **VS Code**, accessible at [cs50.dev](https://cs50.dev). It already has everything installed, so it's recommended over installing things locally.

The IDE has 3 main parts:
1. file explorer (left) - shows your files
2. text editor (middle) - where you write code
3. terminal / CLI (bottom) - where you run commands



## Terminal commands

| command | what it does |
|---|---|
| `ls` | list files in current folder |
| `mkdir` | make a new directory (folder) |
| `rm` | remove a file |
| `rmdir` | remove a directory/folder |
| `mv` | move or rename a file |
| `cp` | copy a file |
| `cd` | change directory (change folder) |

CLI lets you navigate and manage files way faster than clicking around a GUI once you're used to it.



## Hello, world!

3 commands to write, compile, and run a program:

```
code hello.c
make hello
./hello
```

- `code hello.c` creates the file and opens it so you can type in it
- `make hello` **compiles** the code (turns source code into machine code), creating a runnable file called `hello`
- `./hello` actually runs the program

```c
// A program that says hello to the world
#include <stdio.h>

int main(void)
{
    printf("hello, world\n");
}
```

- `printf` is a function that prints (outputs) text, it's basically the C version of Scratch's "say" block
- every character matters here, missing a `;` or a quote will break the program
- `\n` creates a new line after the text

**pattern to remember:**
```
argument -> [function] -> side effect
```
the side effect is what happens as a result, like text showing up on screen.

### escape sequences
special characters that need a backslash `\` to work properly inside a string:

- `\n` - new line
- `\r` - carriage return (goes back to start of line)
- `\"` - prints an actual double quote
- `\'` - prints an actual single quote
- `\\` - prints a backslash



## Header files / libraries

A **library** is pre-written code made by someone else that we can use in our own program. To use one, you `#include` it at the top of your file.

- `stdio.h` - standard input/output header, has `printf` and other basic I/O functions
- `cs50.h` - CS50's own custom header, makes getting user input way simpler (like "training wheels" while learning C)

`cs50.h` functions:
- `get_char`
- `get_double`
- `get_float`
- `get_int`
- `get_long`
- `get_string`

example using `get_string`:
```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string answer = get_string("What's your name? ");
    printf("hello, %s\n", answer);
}
```
`answer` is a **variable** here, a place to store a value. `%s` is a placeholder that tells `printf` "expect a string here."


## Types

data types available in C:
- **string** - text (a series of characters)
- **bool** - true or false only
- **char** - a single character (not a whole string), uses single quotes like `'y'`
- **float** - decimal/real number, uses 32 bits
- **double** - decimal/real number, uses 64 bits (more precise than float)
- **int** - whole numbers, uses 32 bits, can go up to about 4 billion combos (roughly -2 billion to +2 billion if signed)
- **long** - whole numbers, uses 64 bits, so it can store much bigger numbers than int

float and double are "limited" in the sense that they can't represent every possible decimal number since real numbers are infinite. this leads to **floating point imprecision** - the computer sometimes can't store a decimal exactly, so tiny rounding errors happen.

## Format codes
used with `printf` to tell it what type of value to expect:

| code | type |
|---|---|
| `%c` | char |
| `%f` | float |
| `%i` | int |
| `%li` | long |
| `%s` | string |


## Variables and operators

```c
int counter = 0;
counter = counter + 1;   // long way
counter += 1;             // shorter
counter++;                // shortest
counter--;                 // subtract 1
```

**assignment vs equality** - this trips a lot of people up:
- `=` is the **assignment operator**, it stores a value
- `==` is the **equality operator**, it checks if two things are equal

**comparison operators:**
- `<` less than, `>` greater than
- `<=` less than or equal, `>=` greater than or equal
- `!=` not equal to ("bang equal")
- `!` negate / opposite (flips true to false and vice versa)

**logical operators:**
- `||` means OR
- `&&` means AND

**math operators:**
- `+` addition, `-` subtraction, `*` multiplication, `/` division, `%` remainder (modulo)


## Conditionals

same idea as Scratch's if/else blocks:

```c
if (x < y)
{
    printf("x is less than y\n");
}
else if (x > y)
{
    printf("x is greater than y\n");
}
else
{
    printf("x is equal to y\n");
}
```

for a char comparison, single quotes are used since it's one character, not a string:

```c
char c = get_char("Do you agree? ");

if (c == 'Y' || c == 'y')
{
    printf("Agreed.\n");
}
else
{
    printf("Not agreed.\n");
}
```
(`||` here means "if it's either uppercase Y or lowercase y")



## Loops

C doesn't have a built-in "forever" block like Scratch, loops have to be written out.

### while loop
runs as long as the condition is true:
```c
int i = 0;
while (i < 3)
{
    printf("meow\n");
    i++;
}
```
we usually count starting from 0 in computer science, not 1.

### for loop
more efficient way to write a loop with a known number of repeats, combines the counter setup, condition, and increment into one line:
```c
for (int i = 0; i < 3; i++)
{
    printf("meow\n");
}
```

### infinite loop
```c
while (true)
{
    printf("meow\n");
}
```
this will run forever and lock up the terminal. **Ctrl+C** stops it (sends a signal called SIGINT to kill the program).

### asking for valid input (getting better over time)

first attempt - only checks once, bad design:
```c
int n = get_int("What's n? ");
if (n < 0)
{
    n = get_int("What's n? ");
}
```

better - using `continue` and `break` in a while loop:
```c
int n;
while (true)
{
    n = get_int("What's n? ");
    if (n < 0)
    {
        continue;   // skip to next loop iteration
    }
    else
    {
        break;      // exit the loop
    }
}
```

even simpler, since `continue` isn't needed if there's nothing after it:
```c
while (true)
{
    n = get_int("What's n? ");
    if (n >= 0)
    {
        break;
    }
}
```

### do-while loop
guarantees the code runs **at least once** before checking the condition, good for "ask first, validate after":
```c
int n;
do
{
    n = get_int("What's n? ");
}
while (n < 0);
```


## Functions

functions let us **abstract** away repeated code into a reusable block, same idea as Scratch's "define" blocks.

```c
void meow(void);

int main(void)
{
    for (int i = 0; i < 3; i++)
    {
        meow();
    }
}

void meow(void)
{
    printf("meow\n");
}
```

- `void` before the function name means it doesn't return a value
- `(void)` in the parentheses means it doesn't take any input
- the line `void meow(void);` near the top is called a **prototype** - it tells the compiler "this function exists, its full definition is further down the file"

functions can also take input (parameters) and give back a value:
```c
int get_positive_int(void)
{
    int n;
    do
    {
        n = get_int("Number: ");
    }
    while (n < 1);
    return n;
}
```
`return` sends a value back to wherever the function was called from.

### scope
a variable only exists within the function it was created in. if `main` has a variable `n` and passes it to another function, that other function actually gets its **own copy** of `n`, not the original.



## Correctness, design, style

code can be judged on 3 axes:
- **correctness** - does it actually work as intended? (checked with `check50`)
- **design** - is it efficient and well thought out, not just "technically works"? (checked with `design50`)
- **style** - is it clean and consistent to read? (checked with `style50`)



## Operators and overflow

```c
int x = get_int("What's x? ");
int y = get_int("What's y? ");
printf("%i\n", x + y);
```

### integer overflow
integers can only count so high. an `int` (32 bits) can normally hold up to about 2,147,483,647. if a calculation goes past that limit, it **overflows** and wraps around to a negative number or an unexpected value. using `long` (64 bits) instead of `int` delays this problem since it can hold much bigger numbers, but it doesn't remove the problem completely.

### truncation
dividing two integers in C cuts off (truncates) the decimal part instead of rounding:
```c
7 / 2   // gives 3, not 3.5
```
to actually get the decimal answer, you need to **cast** one of the numbers to a float:
```c
printf("%f\n", (float) x / y);
```


## Real-world bugs caused by number limits

- **Y2K problem** - old systems only stored the last 2 digits of a year (like `98` instead of `1998`) to save space, so when 2000 hit, systems couldn't tell if it meant 1900 or 2000
- **Year 2038 problem** - some systems store time using a 32-bit counter, which will overflow on January 19, 2038. if not fixed, affected devices could think it's December 13, 1901 instead

both are examples of what happens when a program's number type can't hold a big enough value for the real world.


## Summing up

- how to write, compile, and run a program in C
- how to use the CLI (terminal commands)
- built-in functions from `stdio.h` and `cs50.h`
- variables, conditionals, and loops (while, for, do-while)
- how to write your own functions and understand scope
- evaluating code by correctness, design, and style
- types, operators, casting, and why overflow/truncation happen

&nbsp;

## Problem Set 1 - Hello, Mario and Cash

Working through Problem Set 1 (Mario less/more, and Cash) helped reinforce the core building blocks from lecture in a hands-on way.

### Getting user input

- `get_int`, `get_string`, and `get_char` all come from `cs50.h`, not standard C.
- Each function grabs a specific data type, so picking the right one matters. For example, `get_char` only grabs a single character, so it's the wrong choice for something like a dollar amount or number of cents.

### Re-prompting for valid input (do-while loops)

Used to keep asking the user for input until they give something valid (like a non-negative number).

```c
int c;
do
{
    c = get_int("Change owed: ");
}
while (c < 0);
```

- The variable needs to be declared before the loop, then assigned to inside the loop body.
- The `while (condition);` line needs a semicolon at the end, easy to forget, but the code won't compile without it.

### Variable scope

- A variable declared inside `{ }` only exists inside those braces.
- Redeclaring a variable inside a loop (like writing `int c = ...` a second time inside a do-while) creates a brand new, separate variable that "shadows" the outer one. This causes bugs where the outer variable never actually gets updated.

### for loops vs while loops

- `for` loops work best when the number of repetitions is known ahead of time (e.g. printing a fixed width row in Mario).
- `while`/`do-while` loops work best when the number of repetitions depends on a condition being checked as you go (e.g. re-prompting for valid input).

### Division and modulo can replace loops

Instead of subtracting a value repeatedly in a loop to count how many times it fits, `/` and `%` can do it in one step:

```c
coins += c / 25;  // how many quarters fit
c = c % 25;       // what's left over
```

- `/` between two ints in C truncates (drops the decimal), so it tells you how many whole times one number fits into another.
- `%` gives the remainder after that division.
- This can turn a several line loop into two simple lines, with no loop needed at all.

### Nested loops for 2D shapes

- Printing shapes like pyramids needs a loop inside a loop, an outer loop for each row, inner loops for spaces vs. hashes.
- Alignment (left vs. right) comes from where the spaces are placed relative to the hashes, not from separate logic for each side.

### Brace and syntax bookkeeping

- An extra or misplaced closing brace `}` can accidentally close `main()` early, leaving code stranded outside the function so it won't compile.
- Small syntax details (missing semicolons, mismatched braces) are common early bugs worth double checking every time.

### General approach that helped

1. Write pseudocode first, describe the logic in plain steps.
2. Map each step to a C construct already learned (loop, conditional, function).
3. Write the code.
4. Test against edge cases (negative numbers, zero, letters, no input).

### Bugs I actually hit while doing this pset

- Redeclared `c` inside the do-while loop body (`int c = get_int(...)` a second time), which shadowed the outer `c` and left it uninitialized. Fixed by removing the `int` on the second one, since the variable already existed.
- Forgot the semicolon after `while (c < 0)` in the do-while loop. This is required for do-while specifically and caused a compile error.
- Left an extra closing brace `}` before `printf`, which closed `main()` early and left `printf` stranded outside the function.
- Initially used `get_char` for change owed instead of `get_int`, which only grabbed a single character instead of the full number.
- Tried subtracting coin values in a loop before realizing `/` and `%` could do the same thing in
- types, operators, casting, and why overflow/truncation happen
