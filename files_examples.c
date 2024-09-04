#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;

    // "w" - write (creates new or overrides the existent file)
    // "r" - read
    // "a" - append
    fp = fopen("./pointers.c", "r");
    if (fp == NULL)
    {
        printf("cannot open the file\n");
        return -1;
    }
    char content[256];
    for (int i = 0; i < 32; i++)
    {
        if (feof(fp) == EOF)
        {
            printf("End of file (EOF)\n");
            break;
        }
        char ch = fgetc(fp);
        // some processing...
    }
    fgets(content, 256, fp);
    printf("Read line from file:\n");
    printf("%s\n", content);
    fclose(fp);

    fp = fopen("./tmp.log", "w");
    if (fp == NULL)
    {
        printf("Failed to create/open file for write");
        return -2;
    }
    char some_text[50] = "Hello World";
    for (int i = 0; i < 50; i++)
    {
        char ch = some_text[i];
        if (ch == '\0')
        {
            fputc('\n', fp);
            break;
        }
        fputc(ch, fp);
    }
    fprintf(fp, "%d-%d-%d\n", 2024, 9, 4);
    fputs("Another line\n", fp);
    fclose(fp);

    return 0;
}
