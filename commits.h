
struct commits {
    char *repo_id;
    char *author_id;
    char *committer_id;
    char *commit_at;
    char *message;
};

//repo_id;author_id;committer_id;commit_at;message


struct commits init_commits(char *info);


void show_commits(struct commits);

int check_datecommits (struct commits k);
