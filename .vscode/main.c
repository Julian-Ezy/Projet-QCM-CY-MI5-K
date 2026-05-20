int main() {
    char mdp[20] = "1234";
    FILE *f = fopen("mdp.txt", "r");
    if (f != NULL) {
        if (fgets(mdp, sizeof(mdp), f) == NULL) {
            strcpy(mdp, "1234");
        }
        fclose(f);
    }
    choix_utilisateur(mdp);
    return 0;
}