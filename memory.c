//
//	Example of gdb
//
//	compile with debug info
//	> gcc -ggdb -mpreferred-stack-boundary=3 -fno-stack-protector -o memory memory.c
//	-ggdb -> extra debugging information
// 	
//	> gdb -q memory
//	> (gdb) b main 			// set breakpont in main

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_index = 5;			// stored in the .data section
char *str;				// stored in the .bss section
char *hello = "hello";
int nothing;			// stored in the .bss section

void func1(int c) {
	int i = c;			// stored on the stack
	str = (char*)malloc(10*sizeof(char));	// stored in the heap

	strncpy(str,"abcde",5);

	printf("%s\n", str);
}

int main() {

	func1(1);

}