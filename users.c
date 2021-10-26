
#include <stdio.h>

#include "users.h"

struct user init_user(char *info) {
    //printf("chegou até aqui");
    struct user k;
    //k.public_repos = atoi(strsep(&info, ";"));
    int a = sscanf(info,"%m[0-9];%m[^;];%m[a-zA-Z];%m[\\-0-9 :];%d;%m[^;];%d;%m[^;];%d;%d",
        &k.id,
        &k.login,
        &k.type,
        &k.created_at,
        &k.followers,
        &k.followers_list,
        &k.following,
        &k.following_list,
        &k.public_gists,
        &k.public_repos);
//314442; mitchellshelton; User;2010-06-25 11:13:20;9;
//[272939, 1504500, 1031373, 7852646, 11890867, 3768562, 7041191, 6673982, 4955664];9;
//[518371, 1031373, 1504500, 2364769, 3768562, 4515014, 4955664, 6305433, 7852646];3;27

    if (a == 10) {
        printf("%d %s %s \n",a, k.id,k.login);
    }
    else {
        printf("deu erro%d %s\n",a, info);
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
    //        k.followers_list, 
    //        k.following, 
    //        k.following_list, 
    //        k.public_gists, 
    //        k.public_repos);
}

//6611157;lorraine94588;User;2014-02-07 01:01:35;0;[];0;[];0;0
//char *id;
//char *login;
//char *type;
//char *created_at;
//int followers;
//char *followers_list;
//int following;
//char *following_list;
//int public_gists;
//int public_repos;
