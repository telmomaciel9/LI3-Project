#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "users.h"

void ex1() {
    FILE *data_file = fopen("users.csv","r");
    char buffer[200];
    int i = 0;
    struct user *users = NULL;

    if (data_file == NULL) {
        printf("Error when opening\n");
        return;
    }
    //users = malloc((300000)*sizeof(struct user));
    while(fgets(buffer, 200, data_file)){
        if (i%100 == 0) {
            users = realloc(users,(i+101)*sizeof(struct user));
        }

        //verifica que leu a linha toda
        if (buffer[strlen(buffer)-1] == '\n') {
            users[i] = init_user(buffer);
        }
        else {
            printf("linha %d demasiado comprida para processar", i);
        }

        if (users[i].id != NULL) {
            i++;
        }

        for (int k = 0; k < i; k++) {
            show_user(users[k]);
        }

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


