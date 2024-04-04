#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_ID_LEN 20

int main() {
    FILE *fp, *fint, *fop, *fid;
    char c, id[MAX_ID_LEN];
    int i = 0;

    fp = fopen("input.txt", "r");
    fint = fopen("integers.txt", "w");
    fop = fopen("operators.txt", "w");
    fid = fopen("identifiers.txt", "w");

    if (fp == NULL) {
        printf("Cannot open file \n");
        return 0;
    }
    while ((c = fgetc(fp)) != EOF) {
        if (isdigit(c)) {
            fputc(c, fint);
            fputc('\n', fint);
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            fputc(c, fop);
            fputc('\n', fop);
        } else if (isalpha(c)) {
            id[i++] = c;
            id[i] = '\0';
            // if (i == MAX_ID_LEN) {
            //     fprintf(fid, "%s\n", id);
            //     i = 0;
            // }
        } else if (c == ' ' || c == '\n' || c == ',' || (c == '\\' && ((c=fgetc(fp)) == 'n')) || (c == '%' && ((c=fgetc(fp)) == 'd'))) {
            if (i != 0) {
                fprintf(fid, "%s\n", id);
                i = 0;
            }
        }
    }
    fclose(fp);
    fclose(fint);
    fclose(fop);
    fclose(fid);

    return 0;
}