#include <stdio.h>
#include <string.h>

int main (int argc, char* argv[]){
	printf ("Program name : %s\n", argv[0]);
	if (argc != 2){
        printf("Wrong nr of arguments");
    }
    else 
        if(strcmp(argv[1], "exercicio-1") == 0){
            ex1();
        }
    else 
        if(strcmp(argv[1], "exercicio-2") == 0){
            ex2();
        }
    return 0;
}
