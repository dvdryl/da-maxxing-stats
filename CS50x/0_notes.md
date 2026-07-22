# Week 0 &emsp;  CS50x 2026
July 20, 2026 &emsp; &emsp; [Official notes](https//cs50.harvard.edu/x/notes/0/)

&nbsp;

base 1 or unary is 1
base 2 has different weights per position, while the binary system is base 2
binary digit is called a **bit** a single binary digit, 0 or 1. 0 is off, 1 is on, in simple terms.

base 10 is the decimal system we use every day! ones, tens, hundreds, etc.

1 byte is 8 bits:
```
128 64 32 16 8 4 2 1
 0   0  0  0 0 0 0 0
```

```
00000000 = 0
00000001 = 1
...
11111111 = 255
```

with 8 bits there are 256 combinations
2^32 is about 4 billion
2^64 is an extremely high number of permutations!!

how do you represent the capital letter A in binary?
A is 01000001 = 65
B is 01000010 = 66
C is 01000011 = 67

computers use **ASCII**, the American Standard Code for Information Interchange.
it's the mapping of numbers to letters. 
> ASCII covers 0 to 127 !!

- 48–57 is 0–9
- 65–90 is A–Z
- 97–122 is a–z

capital and lowercase letters are **32 apart** from one another!!

exercise:
```
01001000 = 72 = H
01001001 = 73 = I
00100001 = 33 = !
```
so HI! in bits is `01001000 01001001 00100001`

```
01000001 = A
01100001 = a
```
you can flip between capital and lowercase by changing only 1 bit!!! so cool

exercise:
```
01000010 = 66 = B
01001111 = 79 = O
01010111 = 87 = W
```
ASCII is one of the earliest sets but not the only system and we now have a superset of ASCII called **Unicode**, which also includes emoji!!

the Unicode Consortium aims to make a digital representation of all human language. past, present, and future!! not just using 7 or 8 bits, but using more bits per character (16-bit, 32-bit) to allow way more combinations and more complex characters. 32 bits is enough to represent emoji!!!

😂 is `11110000100111111001100010000010` or 4,036,991,106

unicode is universal, but different apps/devices can display the same code with different fonts or graphics.

---

but how do we represent color?
using integers in the **RGB** color model, the fundamental color system, used in Photoshop.
> printers use the **CMYK** color model instead, to reproduce a vast spectrum of colors.

using our earlier "HI!" bytes as an example:
- R - 72/255
- G - 73/255
- B - 33/255
That RGB combo makes a dark shade of yellow.

0 = none, 255 = max amount of that color. 

`000` is black
`255 255 255` (or FFF) is white

Flipbook is an animation style in book form which is the same idea as motion pictures. Old-school films showed about 30 (or fewer) pictures per second, and it looks like motion.

Music can be represented in code using frequency, duration (speed of a note), and amplitude (how loud it is) and also representable in bytes.

the computer distinguishes between the letter A and the number 65 based on **context** while the programmer/software decides whether to interpret bits as a number or a letter, based on file type (GIF, JPEG, DOCX, etc.).
> that's why you set up the file type first, like in HTML you put `<!DOCTYPE html>` at the top of the file.

---

recap on base 10 and base 2:
base 10 is what we use every day, 0–9.
binary/base 2 is the same idea, just with only 0 and 1 available, and you need more digits to count higher (e.g. 255 needs a full byte, 8 bits), but that's still way more efficient than unary, where you'd need 255 individual marks lined up.

in conclusion:
- unary = base 1
- binary = base 2
- decimal = base 10

each pair names the same thing! and at the end of the day, computers only have zeros and ones to work with, the answer to "how do we represent X" is always about permuting 0s and 1s into patterns/numbers that represent X.

---

if we have a way to represent all inputs in the world, what's the process to get an output from a problem-solving process?
the answer is **algorithm** - a step-by-step set of instructions for solving a problem. that's what computer science is and not just representing information, but processing it to solve the problem you were given (the input) so you can produce the correct answer (the output).

algorithms are implemented in phones and PCs and that's what **software** is. code the computer understands, still fundamentally step-by-step instructions.

knowing more algorithms helps you find smarter, more efficient ways to solve a problem, and there's good, better, and best, differing fundamentally in efficiency and design quality.

computer science = the logic of solving problems not just correctly, but *efficiently*. which gives us algorithms.

**code** is the implementation of an algorithm, in a language the computer understands.

code takes input (like names and numbers) and spits out an answer.
> that's also what your phone does with autocomplete -> the efficient move is to cut the search space in half repeatedly, increasing speed. this is **logarithmic**, not linear, in nature.

---

## Pseudocode

english/human-like, step-by-step instructions, terse and correct. an algorithm for efficiently finding a contact in a phone book:

```
1  pick up phone book
2  open to middle of phone book
3  look at page
4  if person is on page
5      call person
6  else if person is earlier in book
7      open to middle of the left half of book
8      go back to line 3
9  else if person is later in book
10     open to middle of right half of the book
11     go back to line 3
12 else
13     quit
```

the bold words like *pick up* are **functions** - verbs/actions that get small work done.
*if* and *else* are **conditionals** - like splits in the road, deciding which way to go based on a question.
the questions inside the if/else are **boolean expressions** - a yes/no question, true or false, 0 or 1, binary in state.
"go back to line 3" is a **loop** - cyclical behavior.

that's the fundamentals of all code, in any language.

**compiler** - a program that translates one language into another.

**side effect** - what happens visually or audibly (out of a speaker) as a result of a function running.

algorithm implemented in code = a **function**, which is a piece of functionality that implements the algorithm.
- algorithm is the concept
- function is the incarnation of it in code

in Scratch:
- `hello world` is the input
- `say` is the function
- the side effect is the output = the cat/sprite showing a chat bubble saying "hello world!!"

**variables** can store values.

---

## Extra (from official notes, not yet in my notes)

- AI can remove a lot of human bottlenecks, but knowing the fundamentals is what lets you actually drive/create with it. CS50's policy only allows the **CS50 Duck** (https://cs50.ai) as an AI tool for coursework.
- The phone-book algorithms compare in **Big-O**: checking page by page is `n`, checking two pages at a time is `n/2`, and the halving approach is `log n` — all three approaches were discussed, mine only wrote the fastest one (halving) in pseudocode.
- **Abstraction** = simplifying a problem into smaller and smaller sub-problems (e.g. repeating "meow" 3 times manually vs. using a `repeat` loop vs. `define`-ing a custom `meow` block that takes `n` as input).
- Scratch's stage is a coordinate grid centered at `(0,0)`, roughly `(-240,-180)` to `(240,180)`.
