#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "users.h"



void ex1() {
    printf("exerci1");
    printf("exerci1");
    FILE *data_file = fopen("users100.csv","r");
    char buffer[200];
    int i = 0;

    struct user *users = NULL;

    if (data_file == NULL) {
        printf("Error when opening\n");
        return;
    }

    while(fgets(buffer, 200, data_file)){
        if (i%10000 == 0) {
            users = realloc(users,(i+10001)*sizeof(struct user));
        }
        users[i] = init_user(buffer);
        i++;
    }

    for (i = 0; i < 101; i++) {
        show_user(users[i]);
    }

    fclose(data_file);
}


void ex2(){
}


int main (int argc, char* argv[]){
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


