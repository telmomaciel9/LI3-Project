
struct user {
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
};



struct user init_user(char *info);


void show_user(struct user);

int check_date (struct user k);

int follow_confirm (struct user k);
