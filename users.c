
#include <stdio.h>

#include "users.h"

struct user init_user(char *info) {
    struct user k;
    //k.public_repos = atoi(strsep(&info, ";"));
    //k.id ;

    //int public_repos;
    //char *id;
    //int followers;
    //char *followers_list;
    //char *type;
    //char *following_list;
    //int public_gists;
    //char created_at;
    //int following;
    //char *login;        = strdup(strsep(&info, ";"));

    sscanf(info, "%d;%m[0-9];%d;%m[a-z][A-Z];%m[a-z][A-Z];%m[a-z][A-Z];%d;%ms;%d;%m[a-z][A-Z]",
            &k.public_repos,
            &k.id,
            &k.followers,
            &k.followers_list,
            &k.type,
            &k.following_list,
            &k.public_gists,
            &k.created_at,
            &k.following,
            &k.login
          );
    return k;

}

void show_user(struct user k){
    printf("pr: %d id: %s fol: %d fl: %s t:%s fll:%s pg:%d ca:%s f: %d l: %s", k.public_repos, k.id, k.followers, k.followers_list, k.type, k.following_list, k.public_gists, k.created_at, k.following, k.login);
}

    //6;23609;2;[5877145, 3076393];User;[];0;2008-09-08 06:37:01;0;lmanolov
    //int public_repos;
    //char *id;
    //int followers;
    //char *followers_list;
    //char *type;
    //char *following_list;
    //int public_gists;
    //char *created_at;
    //int following;
    //char *login;        = strdup(strsep(&info, ";"));
