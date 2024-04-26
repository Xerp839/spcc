#include <stdio.h>
#include <conio.h>
#include <string.h>
char op[2], arg1[5], arg2[5], result[5];
void main()
{
  FILE *fp1, *fp2;

  printf("Input File: input.txt\n");
  fp1 = fopen("input.txt", "r");
  if (fp1 == NULL)
  {
    printf("Error opening input.txt for reading.\n");
    return;
  }

  printf("Output File: output.txt\n");
  fp2 = fopen("output.txt", "w");
  if (fp2 == NULL)
  {
    printf("Error opening output.txt for writing.\n");
    fclose(fp1);
    return;
  }

  while (!feof(fp1))
  {

    fscanf(fp1, "%s%s%s%s", op, arg1, arg2, result);
    if (strcmp(op, "+") == 0)
    {
      fprintf(fp2, "\nMOV R0,%s", arg1);
      fprintf(fp2, "\nADD R0,%s", arg2);
      fprintf(fp2, "\nMOV %s,R0", result);
    }
    if (strcmp(op, "*") == 0)
    {
      fprintf(fp2, "\nMOV R0,%s", arg1);
      fprintf(fp2, "\nMUL R0,%s", arg2);
      fprintf(fp2, "\nMOV %s,R0", result);
    }
    if (strcmp(op, "-") == 0)
    {
      fprintf(fp2, "\nMOV R0,%s", arg1);
      fprintf(fp2, "\nSUB R0,%s", arg2);
      fprintf(fp2, "\nMOV %s,R0", result);
    }
    if (strcmp(op, "/") == 0)
    {
      fprintf(fp2, "\nMOV R0,%s", arg1);
      fprintf(fp2, "\nDIV R0,%s", arg2);
      fprintf(fp2, "\nMOV %s,R0", result);
    }
    if (strcmp(op, "=") == 0)
    {
      fprintf(fp2, "\nMOV R0,%s", arg1);
      fprintf(fp2, "\nMOV %s,R0", result);
    }
  }
  fclose(fp1);
  fclose(fp2);

  printf("\nContents of input.txt:\n");
  fp1 = fopen("input.txt", "r");
  if (fp1 == NULL)
  {
    printf("Error opening input.txt for reading.\n");
    return;
  }

  char ch;
  while ((ch = fgetc(fp1)) != EOF)
  {
    putchar(ch);
  }

  fclose(fp1);

  // Open and print the contents of output.txt
  printf("\n\nContents of output.txt:\n");
  fp2 = fopen("output.txt", "r");
  if (fp2 == NULL)
  {
    printf("Error opening output.txt for reading.\n");
    return;
  }

  while ((ch = fgetc(fp2)) != EOF)
  {
    putchar(ch);
  }

  fclose(fp2);

  getch();
}
