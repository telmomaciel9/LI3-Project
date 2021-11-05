#define _XOPEN_SOURCE
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "commits.h"

struct commits init_commits(char *info) {
    //printf("chegou até aqui");
    struct commits k;
    //repo_id;author_id;committer_id;commit_at;message
    int a = sscanf(info,"%m[0-9];%m[0-9];%m[0-9];%m[\\-0-9 :];%m[^;]",
        &k.repo_id,
        &k.author_id,
        &k.committer_id,
        &k.commit_at,
        &k.message);

    if (a != 5) {
        k.repo_id = NULL;
        //printf("deu erro %d %s\n",a, info);
        //printf("%d %s %s \n",a, k.repo_id, k.author_id);
    }
    //else {
    //    printf("deu erro %d %s\n",a, info);
    //    k.repo_id = NULL;
    //    //convenção de repo_id ser NULL em caso de invalidaçao
    //}
    return k;
}

void show_commits(struct commits k){
    if (k.repo_id != NULL) {
        printf("rep_i : %s aut_i: %s com_id: %s com_at: %s m: %s\n", 
            k.repo_id,
            k.author_id,
            k.committer_id,
            k.commit_at,
            k.message);
    }
}


int check_datecommits (struct commits k){
    struct tm timet = {0};
    if(strptime(k.commit_at, "%Y-%m-%d %H:%M:%S",&timet) == NULL) {
        return 0;
    }
    return 1;



}
