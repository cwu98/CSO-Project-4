# Project 4

__Due date: Wednesday, April 24 at 11:55pm.__

---
**You may discuss any of the assignments with your classmates and instructors (or anyone else) but
all work for all assignments must be entirely your own.
Any sharing or copying of assignments will be considered cheating (this includes posting of partial or complete solutions on
Piazza, GitHub public repositories or any other public forum). If you get significant help
from anyone, you should acknowledge it in your submission (and your grade will be proportional to the part
that you completed on your own).
You are responsible for every line in your program: you need to know what it does and why.**

__Note:__ In this project you will be working with binary files that were compiled and build
on `crackle1`. There is no expectation that these files will behave correctly on any other platform.


## Programming requirements:

- __The programs should be leak-free: any memory that is allocated should be freed before the program terminates.__
- The programs have to be documented! Any file that you edit should have preamble
 including your name as the author, description of the purpose of the program and
 inline comments in the functions that you implement. All functions except for `main()` should
 have descriptions of function parameters, returned value and a summary of what the function does.
- The code has to build correctly using the provided `Makefile`.
- The code has to follow C programming conventions.
- The code has to be formatted properly.  

In addition, __you are required to make at least 5 commits to your repository.__ Each time you make a significant change/improvement to your solutions, you should commit and push the changes to the remote repository. This way, if there are any problems with your local copy of the files, you have a recent version of the code available.
Your commits should be distributed over time - they should not be all made within an hour before the due date.


## Problem 1 (40 points)

The source code for `problem1.c` is given. You may quickly realize that the code
has some serious issues. But it does compile and  run. In some cases the run
terminates with a segmentation fault.

You should compile this program using

```bash
gcc -g -Og problem1.c -o problem1
```

If you run this program with no command line arguments:

```bash
./problem1
```
it uses the default
values for the struct members. These values do not cause  any memory corruption
while the program is running and the run terminates normally after displaying:

```
First:     Joe                 
Last:      Fox                 
Initial:   L                   
Age:       21                  
Salary:    70000
```

The program can also be executed with user specified command line arguments. You
will investigate what happens when the program is given those command line
arguments.  The command line arguments should be a first name and a last name (in that order).

```bash
./problem1 first_name last_name
```

For the purpose of solving this problem you will
use _versions_ of your own name. Think of your first name and last name as
endless repeats of the same string (which is your actual first or last name).
For example, if your first name is "Joe", then for the purpose of this problem,
think of your first name as "JoeJoeJoeJoeJoeJoeJoe...." (repeating indefinitely).
Same applies to the last name.

You should run the program with the following command line arguments
- RUN 1: first __three__ letters of your first name, first __three__ letters of your last name
- RUN 2: first __five__ letters of your first name, first __three__ letters of your last name
- RUN 3: first __three__ letters of your first name, first __ten__ letters of your last name
- RUN 4: first __three__ letters of your first name, first __eleven__ letters of your last name
- RUN 5: first __three__ letters of your first name, first __thirteen__ letters of your last name

For each of the five program runs, you need to
- show the output of the program,
- state if the program run terminated normally or not,
- if the output of the program is not as expected, or if the program crashes,
explain what happened
-  show the byte by byte content
of the structure `p` at the three locations indicated in the code.

__Showing the structure__

You should realize that the structure `p` is 24 bytes in size with the following layout:

```
     5 bytes   5 bytes  1   5 bytes      8 bytes
   -----------------------------------------------------
   |         |         |  |         |                  |
   -----------------------------------------------------
     first      last    m   padding    personal_record
```

Assume that the address of `p` is `m`, and that `m+i` increments the address by
`i` bytes (for example, if `&p` is `0x7fffffffdb12`, then `m = 0x7fffffffdb12`,
  `m+1 = 0x7fffffffdb13` and   `m+5 = 0x7fffffffdb17`).

Then the byte by byte representation of the structure `p` can be shown using the
following table (the values
  for each byte in hex and as a `char` are for you to populate).


  memory address | m | m+1 | m+2 | m+3| m+4 | __m+5__ | __m+6__ | __m+7__
  ---|---|---|---|---|---|---|---|---
  hex representation| | | | | | | |
  char representation| | | | | | | |
  __memory address__ | __m+8__| __m+9__  | __m+10__  |  __m+11__ | __m+12__ | __m+13__| __m+14__ | __m+15__
  hex representation| | | | | | | |
  char representation| | | | | | | |
  __memory address__ | __m+16__| __m+17__  | __m+18__  |  __m+19__ | __m+20__ | __m+21__| __m+23__ | __m+24__
  hex representation| | | | | | | |
  char representation| | | | | | | |

_Note_: for some of the bytes, the character representation may be a char that is
not printable or that does not have standard "keyboard" representation. If that is
the case, then leave that entry in the table blank. You still should specify
the hex value stored in that byte.

_Hint 1_: remember that the multi-byte numerical values are stored using little-endian convention.

_Hint 2_: You should be using gdb to come up with the values of each byte (although at some point you may notice some patterns). The following cheatsheet may come in handy
http://darkdust.net/files/GDB%20Cheat%20Sheet.pdf (take a look at the instruction
`x/` and its options for ways of displaying values stored in memory in different formats).



__Sample content of the table when the program is run with no command line
arguments__
(some these values may change on different runs of the program)

_table 1_

memory address | m | m+1 | m+2 | m+3| m+4 | __m+5__ | __m+6__ | __m+7__
---|---|---|---|---|---|---|---|---
hex representation| 0xa0|0x59 |0xde |0xf7 |0xff |0x7f |0x00 | 0x00
char representation| |'Y' | | | | |'\0' |'\0'
__memory address__ | __m+8__| __m+9__  | __m+10__  |  __m+11__ | __m+12__ | __m+13__| __m+14__ | __m+15__
hex representation|0x00|	0x00|	0x00|	0x00|	0x00|	0x00|	0x00|	0x00
char representation|'\0' |'\0' |'\0' |'\0' |'\0' |'\0' |'\0' |'\0'
__memory address__ | __m+16__| __m+17__  | __m+18__  |  __m+19__ | __m+20__ | __m+21__| __m+23__ | __m+24__
hex representation|0x10|	0x49|	0x55|	0x55|	0x55|	0x55|	0x00|	0x00
char representation| | 'I'|'U' |'U' |'U' |'U' | '\0'|'\0'

_table 2_

memory address | m | m+1 | m+2 | m+3| m+4 | __m+5__ | __m+6__ | __m+7__
---|---|---|---|---|---|---|---|---
hex representation| 0xa0|0x59 |0xde |0xf7 |0xff |0x7f |0x00 | 0x00
char representation| |'Y' | | | | |'\0' |'\0'
__memory address__ | __m+8__| __m+9__  | __m+10__  |  __m+11__ | __m+12__ | __m+13__| __m+14__ | __m+15__
hex representation|0x00|	0x00|	0x4c|	0x00|	0x00|	0x00|	0x00|	0x00
char representation|'\0' |'\0' |'L' |'\0' |'\0' |'\0' |'\0' |'\0'
__memory address__ | __m+16__| __m+17__  | __m+18__  |  __m+19__ | __m+20__ | __m+21__| __m+23__ | __m+24__
hex representation|0x60|	0x62|	0x75|	0x55|	0x55|	0x55|	0x00|	0x00
char representation|'`' | 'b'| 'u'|'U' |'U' | 'U'|'\0' |'\0'

_table 3_


memory address | m | m+1 | m+2 | m+3| m+4 | __m+5__ | __m+6__ | __m+7__
---|---|---|---|---|---|---|---|---
hex representation|0x4a|	0x6f|	0x65|	0x00|	0xff|	0x46|	0x6f|	0x78
char representation|'J' | 'o'| 'e'|'\0' | | 'F'|'o' |'x'
__memory address__ | __m+8__| __m+9__  | __m+10__  |  __m+11__ | __m+12__ | __m+13__| __m+14__ | __m+15__
hex representation|0x00|	0x00|	0x4c|	0x00|	0x00|	0x00|	0x00|	0x00
char representation|'\0' |'\0' |'L' | '\0'|'\0' |'\0' |'\0' |'\0'
__memory address__ | __m+16__| __m+17__  | __m+18__  |  __m+19__ | __m+20__ | __m+21__| __m+23__ | __m+24__
hex representation|0x60|	0x62|	0x75|	0x55|	0x55|	0x55|	0x00|	0x00
char representation|'`' | 'b'| 'u'|'U' |'U' | 'U'|'\0' |'\0'



__Deliverables__

You should enter your answers in the Google doc document with the template
[here](https://docs.google.com/document/d/1x5QIZ3hKlbTD2DpFSw0IPlv8txMQqifUhcfCPcRiQus/edit?usp=sharing) (you will need to make a copy of the template so that you can
modify your own version).

Once completed, download the document as PDF and upload it to Gradescope.

You __should not__ change the page layout of that document (i.e., make sure that
the document you upload to gradescope has 10 pages: 2 pages for each execution of the program).



## Problem 2 (30 points)

You are given three object files `problem2_given`, `problem2.o` and `functions2_given.o`. The first file is executable binary that runs the entire program. The second one
contains the `main` function. The third one contains two  functions that you need to implement. The program uses a struct whose definition is provided in `given/functions2.h` file. Your task is to write C code for
the code in `functions2.o`. Your code may not end up being identical to
the one in the given file, but it should be equivalent (i.e., given the same
inputs, it should produce the same output).

The `main()` function executes a few tests of the functions implemented in `functions2.o`. These are not exhaustive tests and passing them does not
guarantee correctness, but it should be a pretty good indicator that your code is on the right track.



In order to build the object file, run :

```
make functions2.o
```

In order to build and run your code:

```
make problem2
make run_problem1
```

The output from the program will give you an idea if your functions perform
the task equivalent to the given version.

__Deliverables:__
Implementation of the function `fun1` and `fun2` in file `functions2.c`. The final
file has to be pushed to your GitHub repository in the course organization.




## Problem 3 (30 points)

Your task for this problem is to determine what keys _crack_ the functions in the given program.
`problem3` consists of several functions:`main`, `gate_one`, `gate_two`, and `gate_three`. You are only given the final binary. Your task is to discover three keys provided as
command line arguments to _open_ the three gates. The first command line argument should
be the key for gate 1, the second for gate 2 and the third one for gate 3.  

You need to study the assembly instructions for this program to determine what the
correct values for the keys are.


__Deliverables:__
Once you discover the three keys, you should enter them one per line in the
currently empty file called `problem3_keys`.  The final
file has to be pushed to your GitHub repository in the course organization.
