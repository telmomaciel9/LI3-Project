

int ex1() {
    FILE *data_file = fopen("users100.csv","r");
    char buffer[200];
    int i = 0;

    struct user *users = NULL;
    if (data_file == NULL) {
        printf("Error when opening\n");
        return 1;
    }

    while(fgets(buffer, 200, data_file)){
        if (i%10000 == 0) {
            users = realloc(users,(i+10001)*sizeof(struct user));
        }
        users[i] = init_user(buffer);
        i++;
    }

    for (i = 0; i < 10000000; i++) {
        show_user(users[i]);
    }

    fclose(data_file);
}



struct user init_user(char *info) {
    struct user k;
    //k.public_repos = atoi(strsep(&info, ";"));
    //k.id         = strdup(strsep(&info, ";"));
    sscanf(info, "%d;%m[0-9]",&k.public_repos, k.id );
    return k;
}

void show_user(struct user k){
    printf("public repos: %d, id: %s\n", k.public_repos, k.id);
}

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
