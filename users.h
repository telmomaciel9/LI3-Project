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

void swap_user( struct user *a,struct user *b);

void sort_users( struct user *a, int n);

int pmenor ( struct user *u,int i, int n);

int procura_user(struct user *u, int id, int n, int k);

int valid_user(char *line);
int valid_date(char *date);
int valid_size(int followers, char *follower_list, int following, char *following_list);
void get_userid( char *user_id , char *buffer );
