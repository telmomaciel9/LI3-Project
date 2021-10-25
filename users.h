
struct user {
    int public_repos;
    char *id;
    int followers;
    char *followers_list;
    char *type;
    char *following_list;
    int public_gists;
    char created_at;
    int following;
    char *login;
};



struct user init_user(char *info);


void show_user(struct user);


//6;23609;2;[5877145, 3076393];User;[];0;2008-09-08 06:37:01;0;lmanolov
//public_repos;
//id;
//followers;
//follower_list;
//type;
//following_list;
//public_gists;
//created_at;
//following;
//login
