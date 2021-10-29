
#include <stdio.h>
#include <strptime.h>

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
    

int check_date (struct user k){
    struct tm time = {0};

    if(strptime(k.created_at, "%Y-%m-%d %H:%M:%S",&time) == NULL)
        return 0;
    else
        return (time.tm_year*365 + time.tm_mon*30 + time.tm_mday < 731954);

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
