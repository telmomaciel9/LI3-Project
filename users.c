#define _XOPEN_SOURCE
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "users.h"

int procura_user(struct user *u, int id, int n, int k) {
    int vm = atoi(u[k].id);
    if (vm == id) return 1;
    if (vm >  id) return procura_user(u,id, k , k - k/2);
    if (vm <  id) return procura_user(u,id, n , k + k/2);
    if (n  ==  k) return 0;
}

int pmenor(struct user *u,int i , int n) {
    //if ( i == (n-1) ) return 1;
    //int rc = pmenor ( u, i+1,n);
    //int va = atoi((u[i ]).id);
    //int vm = atoi((u[rc]).id);
    //return va < vm ? i : rc;
    int va, midx = 0;
    int mv = atoi((u[midx]).id);
    for ( ; i < n; i++) {
        va = atoi((u[i ]).id);
        if (va < mv) {
            mv = va;
            midx = i;
        }
    }
    return midx;
} 


//selection sort
void sort_users(struct user *u, int n) {
    int im;
    int i;        
    for (i = 0; i < n; i++) {
        im = pmenor (u,i, n);
        swap_user(&u[i],&u[im]);
    }
}

void swap_user( struct user *a, struct user *b) {
    struct user aux = *b;
    *b = *a;
    *a = aux;
}

int valid_user(char *line) {
    char *id;
    char *login;
    char *type;
    char *created_at;
    int followers;
    char *follower_list;
    int following;
    char *following_list;
    int public_gists;
    int public_repos;
    // cv -> campos validos
    int cv = sscanf(line,"%m[0-9];%m[^;];%m[a-zA-Z];%m[\\-0-9 :];%d;%m[^;];%d;%m[^;];%d;%d",
        &id,
        &login,
        &type,
        &created_at,
        &followers,
        &follower_list,
        &following,
        &following_list,
        &public_gists,
        &public_repos);
    //aqui a ordem importa, só vou validar as cenas se os campos  forem validos
    //printf("%d %s %s \n",cv, id, login);
    return ( cv == 10  && valid_date(created_at) && valid_size(followers,follower_list,following,following_list));
    //return 1;
}



void get_userid(char *u,char *linha) {
    int a = sscanf(linha,"%m[0-9]", &u);
    if (!a) {};
}


struct user init_user(char *info) {
    //printf("chegou até aqui");
    struct user k;
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
    //if (a != 10) {
    //    k.id = NULL;
    //    printf("deu erro %d %s\n",a, info);
    //    printf("%d %s %s \n",a, id, login);
    //}
    //else {
    //    printf("deu erro %d %s\n",a, info);
    //    k.id = NULL;
    //CONVEÇAO de id ser NULL em caso de invalidaçao
    //}
    return k;
}

void show_user(struct user k){
    if (k.id != NULL) {
        printf("i: %s l: %s t: %s ca: %s f: %d fl: %s flo:%d fol: %s pg: %d pr: %d\n", 
            k.id, 
            k.login, 
            k.type, 
            k.created_at, 
            k.followers, 
            k.follower_list, 
            k.following, 
            k.following_list, 
            k.public_gists, 
            k.public_repos);
    }
}
    
int valid_date(char *date) {
    struct tm timet = {0};
    struct tm *local;
    time_t mytime;
    time(&mytime);
    local = localtime(&mytime);
    int ndias;
    int atual = (local->tm_year+1900)*365 + local->tm_mon*30 + local->tm_mday; 
    if(strptime(date, "%Y-%m-%d %H:%M:%S",&timet) == NULL)
        return 0;
    else {
        ndias =  (timet.tm_year+1900)*365 + timet.tm_mon*30 + timet.tm_mday;
        return (ndias > 731922) && (ndias < atual);
    }
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
        return (ndias > 731922) && (ndias < atual);
    }
}


int valid_size(int followers, char *follower_list, int following, char *following_list){ 
    int following_tam, follower_tam, i;
    if (following_list[0]!='[') return 1;
    if (following_list[1]==']') {
        following_tam = 0;
    }
    else {
        following_tam = 1;
    }
    for (i=0; following_list[i] != ']';i++ ){
        if (following_list[i]==',') {
            following_tam++;
        }
    }
    if (follower_list[0]!='[') return 1;
    if (follower_list[1]==']') {
        follower_tam = 0;
    }
    else { 
        follower_tam = 1;
    }
    for (i=0; follower_list[i] != ']'; i++){
        if (follower_list[i] == ',') {
            follower_tam++;
        }
    }
    return ((follower_tam == followers) && (following_tam == following));
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


