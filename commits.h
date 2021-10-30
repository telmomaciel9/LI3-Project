
struct commit {
    int repo_id;
    int author_id;
    int committer_id;
    char *commit_at;
    char *message;
};

//repo_id;author_id;committer_id;commit_at;message


struct commit init_commit(char *info);


void show_commit(struct commit);

int check_datecommits (struct commit k);
