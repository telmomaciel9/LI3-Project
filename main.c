#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "users.h"
#include "commits.h"
#include "repos.h"

void ex1() {
    FILE *data_file = fopen("users.csv","r");
    FILE *data_file2 = fopen("commits.csv","r");
    FILE *data_file3 = fopen("repos.csv","r");


    char buffer[1000000];
    char buffer2[1000000];
    char buffer3[1000000];

    int i = 0;
    int j = 0;
    int h = 0;

    struct user *users = NULL;
    struct commits *commits = NULL;
    struct repos *repos = NULL;

    //ficheiro de output
    FILE *ucsv = fopen("users-ok.csv","w");
    FILE *ucsv2 = fopen("commits-ok.csv","w");
    FILE *ucsv3 = fopen("repos-ok.csv","w");

    if (data_file == NULL) {
        printf("Error when opening users\n");
        return;
    }

    if (data_file2 == NULL) {
        printf("Error when opening commits\n");
        return;
    }

    if (data_file3 == NULL) {
        printf("Error when opening repos\n");
        return;
    }

    //users = malloc((300000)*sizeof(struct user));
    while(fgets(buffer, 1000000, data_file)){
        if (i%1000 == 0) {
            users = realloc(users,(i+1001)*sizeof(struct user));
        }
        //verifica que leu a linha toda
        //if (buffer[strlen(buffer)-1] == '\n') {
        //    users[i] = init_user(buffer);}
        //else {
        //    printf("linha %d demasiado comprida para processar", i);}
        users[i] = init_user(buffer);

        if (users[i].id != NULL && check_date(users[i]) && follow_confirm(users[i]))  {
            fputs(buffer,ucsv);
            i++;
        }
    }
    
    //commits
    while(fgets(buffer2, 1000000, data_file2)){
        if (j%1000 == 0) {
            commits = realloc(commits,(j+1001)*sizeof(struct commits));
        }

        commits[j] = init_commits(buffer2);

        if (commits[j].repo_id != NULL && check_datecommits(commits[j]) )  {
            fputs(buffer2,ucsv2);
            j++;
        }
    }

    //repos
    while(fgets(buffer3, 1000000, data_file3)){
        if (h%1000 == 0) {
            repos = realloc(repos,(h+1001)*sizeof(struct repos));
        }

        repos[h] = init_repos(buffer3);

        if (repos[h].id != NULL && check_daterepos(repos[h]) )  {
            fputs(buffer3,ucsv3);
            h++;
        }
    }



    for (int k = 0; k < i; k++) {
        show_user(users[k]);
    }

    for (int k = 0; k < j; k++) {
        show_commits(commits[k]);
    }

    for (int k = 0; k < h; k++) {
        show_repos(repos[k]);
    }

    fclose(ucsv);
    fclose(ucsv2);
    fclose(ucsv3);


    fclose(data_file);
    fclose(data_file2);
    fclose(data_file3);

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


