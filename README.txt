WHAT IS BFC?
bfc is a brainfuck compiler which uses assembly and c++.
Currently only works on Intel assembly(Windows).
Still in early development.Doesn't support all features of brainfuck.
________________________________________________________________________________________

Version : 0.1
________________________________________________________________________________________

HOW TO USE :
bfc.exe generates an assembly source file which can then be compiled into an executable.
To generate this assembly soure file :
(while in the same directory as bfc.exe)

bfc.exe <input_file> <output_file>

Then, you can transform the assembly source file(.s) into an executable using g++ :

g++ -o <name_of_exec> <asm_source>

You can also use help to get these instructions :
bfc.exe help

Or, to skip these 2 steps, you can use compile.exe.
The syntax is the same :
compile.exe <input_file> <output_file>
Still a little buggy.


_________________________________________________________________________________________

SUPPORT : 
Windows (Intel asm)
Might work on AT&T(Unix) asm later.

_________________________________________________________________________________________

FEATURES :
This compiler currently doesn't support all of the instructions that the brainfuck language has, as it's still very early in development.
It doesn't support the loops ( '[' and ']'). I'm trying to implement those in assembly, and hopefully, I will manage to do it.
Lists of currently supported instructions:
'>' - increment pointer
'<' - decrement pointer
'+' - increment value at pointer
'-' - decrement value at pointer
'.' - output value at pointer
',' - input value at pointer

Also, the array in which you are free to move supports only integers for the moment. I realized that it should have been characters way too late, so I'm going to make a proper version later(that will hopefully also have instructions for the loops)
__________________________________________________________________________________________

WHAT IS BRAINFUCK :
Brainfuck is an esoteric programming language, the ungodly creation of Urban Müller, whose goal was apparently to create a Turing-complete language for which he could write the smallest compiler ever, for the Amiga OS 2.0. His compiler was 240 bytes in size. (Though he improved upon this later -- he , at one point, said that he had managed to bring it under 200 bytes.) 

A Brainfuck program has an implicit byte pointer, called "the pointer", which is free to move around within an array of 30000 bytes, initially all set to zero. The pointer itself is initialized to point to the beginning of this array.

The Brainfuck programming language consists of eight commands, each of which is represented as a single character.

> 	Increment the pointer.
< 	Decrement the pointer.
+ 	Increment the byte at the pointer.
- 	Decrement the byte at the pointer.
. 	Output the byte at the pointer.
, 	Input a byte and store it in the byte at the pointer.
[ 	Jump forward past the matching ] if the byte at the pointer is zero.
] 	Jump backward to the matching [ unless the byte at the pointer is zero.

The semantics of the Brainfuck commands can also be succinctly expressed in terms of C, as follows (assuming that p has been previously defined as a char*):

> 	becomes 	++p;
< 	becomes 	--p;
+ 	becomes 	++*p;
- 	becomes 	--*p;
. 	becomes 	putchar(*p);
, 	becomes 	*p = getchar();
[ 	becomes 	while (*p) {
] 	becomes 	}

___________________________________________________________________________________________

MISC :
In ./asm_instructions you can find text files with the assembly instructions corresponding to some C/C++ statements/commands, both in AT&T(not yet finished) and Intel syntax.

./asm_test : used for finding out the corresponding assembly instructions.
You can compile a .cpp/.c file dirrectly into assembly source code with gcc/g++ :
g++ -S <input_file>

In ./src you can find the source code for the compiler, for both a char(WIP) and int version.

In ./tests you can find sample brainfuck sources you could compile. Not a whole lot of them so far.

____________________________________________________________________________________________

REASON OF PROJECT :
For fun and to exercise with assembly.
Also to test how github works :D .