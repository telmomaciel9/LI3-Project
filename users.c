
#include <stdio.h>

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
        &k.followers_list,
        &k.following,
        &k.following_list,
        &k.public_gists,
        &k.public_repos);
//314442; mitchellshelton; User;2010-06-25 11:13:20;9;
//9;[272939, 1504500, 1031373, 7852646, 11890867, 3768562, 7041191, 6673982, 4955664];9;
//[518371, 1031373, 1504500, 2364769, 3768562, 4515014, 4955664, 6305433, 7852646];3;27;

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
    //        k.followers_list, 
    //        k.following, 
    //        k.following_list, 
    //        k.public_gists, 
    //        k.public_repos);
}


int follow_confirm (struct user k){
    int following_tam, follower_tam;

    //[518371, 1031373, 1504500]

    //comparar lista de followings

    if (k.following_list[1]=="]") following_tam=0;
    else following_tam=1;

    for (i=0; i++;k.following_list[i]=="]"){
        if (k.following_list[i]==",") following_tam++;
    }

    //comparar lista de followers

    if (k.follower_list[1]=="]") follower_tam=0;
    else follower_tam=1;

    for (i=0; i++;k.follower_list[i]=="]"){
        if (k.follower_list[i]==",") follower_tam++;
    }


    //compara o tamanho das listas com o valor dado

    if (follower_tam == followers) {
        if (following_tam == following) return 1;
    }

    return 0;
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
