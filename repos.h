struct repos {
    int id;
    int owner_id;
    char *full_name;
    char *license;
    char *has_wiki;
    char *description;
    char *language;
    char *default_branch;
    char *created_at;
    char *updated_at;
    int forks_count;
    int open_issues;
    int stargazers_count;
    int size;
};

//id;owner_id;full_name;license;has_wiki;description;language;default_branch;created_at;updated_at;forks_count;open_issues;stargazers_count;size

struct repos init_repos(char *info);

void show_repos(struct repos k);

int check_daterepos (struct repos k);
