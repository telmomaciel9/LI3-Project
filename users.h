
struct user {
    char *id;
    char *login;
    char *type;
    char *created_at;
    int followers;
    char *followers_list;
    int following;
    char *following_list;
    int public_gists;
    int public_repos;
};



struct user init_user(char *info);


void show_user(struct user);


//6;23609;2;[5877145, 3076393];User;[];0;2008-09-08 06:37:01;0;lmanolov
//public_repos;
//id;
//followers; 
////follower_list; //type; //following_list; //public_gists;
//created_at;
//following;
//login
