#define _XOPEN_SOURCE
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "repos.h"

struct repos init_repos(char *info) {
    //printf("chegou até aqui");
    struct repos k;

    //id;owner_id;full_name;license;has_wiki;description;language;default_branch;created_at;updated_at;forks_count;open_issues;stargazers_count;size
    int a = sscanf(info,"%d ;%d ;%m[^;] ;%m[^;] ;%m[a-zA-Z] ;%m[^;] ;%m[^;] ;%m[^;] ;%m[\\-0-9 :] ;%m[\\-0-9 :] ;%d ;%d ;%d ;%d ",
        &k.id,
        &k.owner_id,
        &k.full_name,
        &k.license,
        &k.has_wiki,
        &k.description,
        &k.language,
        &k.default_branch,
        &k.created_at,
        &k.updated_at,
        &k.forks_count,
        &k.open_issues,
        &k.stargazers_count,
        &k.size);

    if (a == 14) {
        printf("%d %d %d \n",a, k.id,k.owner_id);
    }
    else {
        printf("deu erro %d %s\n",a, info);
        k.id = NULL;
        //convenção de id ser NULL em caso de invalidaçao
    }
    return k;
}

void show_repos(struct repos k){
    /*
    printf("\n");
    printf("i : %d own_i: %d fn: %s lc: %s hw: %s d: %s lg: %s db: %s ca: %s ua: %s fc: %d oi: %d sc: %d s: %d", 
        &k.id,
        &k.owner_id,
        &k.full_name,
        &k.license,
        &k.has_wiki,
        &k.description,
        &k.language,
        &k.default_branch,
        &k.created_at,
        &k.updated_at,
        &k.forks_count,
        &k.open_issues,
        &k.stargazers_count,
        &k.size);
    */
}


int check_daterepos (struct repos k){
    struct tm timet = {0};

    if((strptime(k.created_at, "%Y-%m-%d %H:%M:%S",&timet) == NULL) && (strptime(k.updated_at, "%Y-%m-%d %H:%M:%S",&timet) == NULL))
        return 0;
    else {
        return 1;
    }
}
