#include <stdio.h>
#include <conio.h>

struct symtab
{
    char sname[10];
    int addr;
} stab[10];

struct littab
{
    char lname[10];
    int addr;
} ltab[10];

void main()
{
    int lc = 0, i = 0, j = 0, x;
    FILE *fp1, *fp2;
    char str[80], *s1, *s2, *s3;
    int reg[16] = {0};
    clrscr();

    fp1 = fopen("pg1.ASM", "r");
    fp2 = fopen("new.txt", "w");

    while (!feof(fp1))
    {
        fgets(str, 80, fp1);
        sscanf(str, "%s %s %s", s1, s2, s3);

        if (strcmp(s2, "START") == 0)
        {
            lc = atoi(s3);
            strcpy(stab[i].sname, s1);
            stab[i].addr = lc;
            i++;
        }

        else if (strcmp(s1, "USING") == 0)
            reg[15] = 1;

        else if (strcmp(s2, "DC") == 0 || strcmp(s2, "DS") == 0)
        {
            strcpy(stab[i].sname, s1);
            stab[i].addr = lc;
            i++;
            lc += 4;
        }
        else if (strcmp(s1, "END") == 0)
        {
            for (x = 0; x < j; x++)
            {
                ltab[x].addr = lc;
                lc += 4;
            }
        }
        else
        {
            fprintf(fp2, "%d %s\n", lc, str);
            if (s3[0] == '=')
            {
                strcpy(ltab[j].lname, s3);
                j++;
            }
            lc += 4;
        }

        strcpy(s1, " ");
        strcpy(s2, " ");
        strcpy(s3, " ");
    }
    fcloseall();

    printf("Symbol Table\n");
    for (x = 0; x < i; x++)
        printf("%s %d \n", stab[x].sname, stab[x].addr);

    printf("Literal Table\n");
    for (x = 0; x < j; x++)
        printf("%s %d \n", ltab[x].lname, ltab[x].addr);

    getch();
}
