#define _XOPEN_SOURCE
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "users.h"

struct user init_user(char *info) {
    //printf("chegou até aqui");
    struct user k;
    //k.public_repos = atoi(strsep(&info, ";"));
    //id;login;type;created_at;followers;follower_list;following;following_list;public_gists;public_repos
    int a = sscanf(info,"%m[0-9];%m[^;];%m[a-zA-Z];%m[\\-0-9 :];%d;%m[^;];%d;%m[^;];%d;%d",
        &k.id,
        &k.login,
        &k.type,
        &k.created_at,
        &k.followers,
        &k.follower_list,
        &k.following,
        &k.following_list,
        &k.public_gists,
        &k.public_repos);

    if (a == 10) {
        printf("%d %s %s \n",a, k.id,k.login);
    }
    else {
        printf("deu erro %d %s\n",a, info);
        k.id = NULL;
        //convenção de id ser NULL em caso de invalidaçao
    }
    return k;
}

void show_user(struct user k){
    ////printf("\n");
    //printf("i: %s l: %s t: %s ca: %s f: %d fl: %s flo:%d fol: %s pg: %d pr: %d", 
    //        k.id, 
    //        k.login, 
    //        k.type, 
    //        k.created_at, 
    //        k.followers, 
    //        k.follower_list, 
    //        k.following, 
    //        k.following_list, 
    //        k.public_gists, 
    //        k.public_repos);
}
    

int check_date (struct user k){
    struct tm timet = {0};
    struct tm *local;
    time_t mytime;
    //local = ctime(&mytime);
    time(&mytime);
    local = localtime(&mytime);
    int ndias;
    int atual = (local->tm_year+1900)*365 + local->tm_mon*30 + local->tm_mday; 
    //printf("atual :%d  ano:%d  mes:%d  dia:%d\n",atual,local->tm_year,local->tm_mon,local->tm_mday);
    if(strptime(k.created_at, "%Y-%m-%d %H:%M:%S",&timet) == NULL)
        return 0;
    else {

        ndias =  (timet.tm_year+1900)*365 + timet.tm_mon*30 + timet.tm_mday;

        //printf("tempo input atual :%d  ano:%d  mes:%d  dia:%d %s\n",ndias,timet.tm_year+1900,timet.tm_mon,timet.tm_mday,k.created_at);
        //printf("valido: %d ndias:%d 2005: 731954 atual:%d\n",(ndias > 731954) && (ndias < atual),ndias, atual);
        //printf ("%d %d %d\n", 731952, ndias, atual);
        return (ndias > 731952) && (ndias < atual);
    }
}

int follow_confirm (struct user k){
    int following_tam, follower_tam, i;
    //comparar lista de followings
    if (k.following_list[0]!='[') return 1;

    if (k.following_list[1]==']') {
        following_tam = 0;
    }
    else {
        following_tam = 1;
    }

    for (i=0; k.following_list[i] != ']';i++ ){
        if (k.following_list[i]==',') {
            following_tam++;
        }
    }
    //comparar lista de followers

    if (k.follower_list[0]!='[') return 1;

    if (k.follower_list[1]==']') {
        follower_tam = 0;
    }
    else { 
        follower_tam = 1;
    }
    for (i=0; k.follower_list[i] != ']'; i++){
        if (k.follower_list[i] == ',') {
            follower_tam++;
        }
    }
    //compara o tamanho das listas com o valor dado
    //printf("followint_tam:%d %d lista:%s\n", following_tam, k.following, k.following_list);
    //printf("follower_tam:%d %d lista:%s\n", follower_tam, k.followers, k.follower_list);

    return ((follower_tam == k.followers) && (following_tam == k.following));
}
//6611157;lorraine94588;User;2014-02-07 01:01:35;0;[];0;[];0;0
//char *id;
//char *login;
//char *type;
//char *created_at;
//int followers;
//char *follower_list;
//int following;
//char *following_list;
//int public_gists;
//int public_repos;


