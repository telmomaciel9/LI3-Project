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


    char buffer [100000];

    int i = 0;
    int j = 0;
    int h = 0;

    //struct user *users = NULL;
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

    while(fgets(buffer, 100000, data_file)){
        //if (i%1000 == 0) {
        //    users = realloc(users,(i+1001)*sizeof(struct user));
        //}
        //users[i] = init_user(buffer);
        //if (users[i].id != NULL && check_date(users[i]) && follow_confirm(users[i]))  {
        //    fputs(buffer,ucsv);
        //    i++;
        //}
        if (valid_user(buffer)) {
            fputs(buffer,ucsv);
            i++;
        }
    }
    printf("%d\n",i);

    //commits
    while(fgets(buffer, 100000, data_file2)){
        if (j%1000 == 0) {
            commits = realloc(commits,(j+1001)*sizeof(struct commits));
        }
        commits[j] = init_commits(buffer);
        if (commits[j].repo_id != NULL && check_datecommits(commits[j]) )  {
            fputs(buffer,ucsv2);
            j++;
        }
    }

    //repos
    while(fgets(buffer, 100000, data_file3)){
        if (h%1000 == 0) {
            repos = realloc(repos,(h+1001)*sizeof(struct repos));
        }
        repos[h] = init_repos(buffer);
        if (repos[h].id != NULL && check_daterepos(repos[h]) )  {
            fputs(buffer,ucsv3);
            h++;
        }
    }

    //for (int k = 0; k < i; k++) {
    //    show_user(users[k]);
    //}

    fclose(ucsv);
    fclose(ucsv2);
    fclose(ucsv3);

    fclose(data_file);
    fclose(data_file2);
    fclose(data_file3);
}


void ex2(){
    //ficheiros do exercicio 1
    FILE *data_fileu = fopen("users-ok.csv"  ,"r");
    FILE *data_filec = fopen("commits-ok.csv","r");
    FILE *data_filer = fopen("repos-ok.csv"  ,"r");

    char buffer[100000];

    struct user    *users   = NULL;
    struct commits *commits = NULL;
    struct repos   *repos   = NULL;

    if (data_fileu == NULL) {
        printf("error when opening");
        return;
    }
    if (data_filer == NULL) {
        printf("error when opening");
        return;
    }
    if (data_filec == NULL) {
        printf("error when opening");
        return;
    }
    //users counter
    int uc = 0;
    //commits counter
    int cc = 0;
    //repos counter
    int rc = 0;

    //users
    while(fgets(buffer, 100000, data_fileu)){
        if (uc%1000 == 0) {
            users = realloc(users,(uc+1001)*sizeof(struct user));
        }
        users[uc] = init_user(buffer);
        uc++;
    }

    sort_users(users, uc);

    //commits
    while(fgets(buffer, 100000, data_filec)){
        if (cc%1000 == 0) {
            commits = realloc(commits,(cc+1001)*sizeof(struct commits));
        }
        commits[cc] = init_commits(buffer);
        cc++;
    }

    //repos
    while(fgets(buffer, 100000, data_filer)){
        if (rc%1000 == 0) {
            repos = realloc(repos,(rc+1001)*sizeof(struct repos));
        }
        repos[rc] = init_repos(buffer);
        rc++;
    }


    //show_user(users[100]);
    //show_user(users[200]);
    //swap_user(&users[100],&users[200]);
    //show_user(users[100]);
    //show_user(users[200]);

    fclose(data_fileu);
    fclose(data_filec);
    fclose(data_filer);
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
