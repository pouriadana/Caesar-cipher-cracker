#include <stdio.h>
#include <ctype.h>

#define MAX_LEN 100

/*Helper functions*/
int readline(char *s, int n)
{
    char ch, *start_pos = s;
    while(isspace(ch = getchar())) ;
    while(ch != '\n')
    {
        if(s < start_pos + n)
            *s++ = ch;
        ch = getchar();
    }
    return s - start_pos;
}

void cracker(const char *s, int key)
{
    char *decrypt;
    char *decrypt_start = decrypt;
    while(*s)
    {
        if(65 <= *s && *s <= 90)
        {
            *decrypt = (*s - 65 + 26 - key) % 26 + 65;
        }
        else if(97 <= *s && *s <= 122)
        {
            *decrypt = (*s - 97 + 26 - key) % 26 + 97;
        }
        else
            *decrypt = *s;
        decrypt++;
        s++;
    }
    *decrypt = '\0';
    printf("%s", decrypt_start);
}


int main()
{
    char message[MAX_LEN] = {0};
    int i;

    printf("Enter encrypted message: ");
    readline(message, MAX_LEN);

    for(i = 1; i < 26; i++)
    {
        printf("\n%d. ", i);
        cracker(message, i);
    }
    return 0;
}