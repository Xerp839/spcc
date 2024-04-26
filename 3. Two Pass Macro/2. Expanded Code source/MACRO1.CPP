#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

void main()
{
    FILE *f1, *f2, *f3;
    char mne[20], opnd[20], la[20];

    clrscr();
    f1 = fopen("minp2.txt", "r");
    f2 = fopen("ntab2.txt", "w+");
    f3 = fopen("dtab2.txt", "w+");

    if (f1 == NULL || f2 == NULL || f3 == NULL)
    {
        printf("Error: Unable to open files.\n");
        return;
    }

    printf("Processing input file...\n");

    fscanf(f1, "%s%s%s", la, mne, opnd);

    while (strcmp(mne, "MEND") != 0)
    {
        if (strcmp(mne, "MACRO") == 0)
        {
            fprintf(f2, "%s\n", la);
            fprintf(f3, "%s\t%s\n", la, opnd);
        }
        else
        {
            fprintf(f3, "%s\t%s\n", mne, opnd);
        }
        fscanf(f1, "%s%s%s", la, mne, opnd);
    }
    fprintf(f3, "%s", mne);

    fclose(f1);
    fclose(f2);
    fclose(f3);

    printf("PASS 1 is successful\n");

    // Print contents of the symbol table (ntab2.txt)
    printf("\nSymbol Table (ntab2.txt):\n");
    f2 = fopen("ntab2.txt", "r");
    if (f2 == NULL)
    {
        printf("Error: Unable to open ntab2.txt for reading.\n");
        return;
    }
    while (fscanf(f2, "%s", la) != EOF)
    {
        printf("%s\n", la);
    }
    fclose(f2);

    // Print contents of the definition table (dtab2.txt)
    printf("\nDefinition Table (dtab2.txt):\n");
    f3 = fopen("dtab2.txt", "r");
    if (f3 == NULL)
    {
        printf("Error: Unable to open dtab2.txt for reading.\n");
        return;
    }
    while (fscanf(f3, "%s%s", la, opnd) != EOF)
    {
        printf("%s\t%s\n", la, opnd);
    }
    fclose(f3);

    getch();
}
