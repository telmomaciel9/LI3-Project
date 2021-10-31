#define _XOPEN_SOURCE
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "commits.h"

struct commit init_commit(char *info) {
    //printf("chegou até aqui");
    struct commit k;
    //repo_id;author_id;committer_id;commit_at;message
    int a = sscanf(info,"%m[0-9];%m[0-9];%m[0-9];%m[\\-0-9 :];%m[^;]",
        &k.repo_id,
        &k.author_id,
        &k.committer_id,
        &k.commit_at,
        &k.message);

    if (a == 5) {
        printf("%d %s %s \n",a, k.repo_id, k.author_id);
    }
    else {
        printf("deu erro %d %s\n",a, info);
        k.repo_id = NULL;
        //convenção de repo_id ser NULL em caso de invalidaçao
    }
    return k;
}

void show_commit(struct commit k){
    /*
    printf("\n");
    printf("rep_i : %d aut_i: %d com_id: %d com_at: %s m: %s ", 
        &k.repo_id,
        &k.author_id,
        &k.committer_id,
        &k.commit_at,
        &k.message);
    */
}


int check_datecommits (struct commit k){
    struct tm timet = {0};

    if(strptime(k.commit_at, "%Y-%m-%d %H:%M:%S",&timet) == NULL)
        return 0;
    else {
        return 1;
    }
}
