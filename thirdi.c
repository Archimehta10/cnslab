#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void encrypt()
{
    char pt[128];
    char key[16];
    printf("Enter plaintext:");
    scanf("%s", pt);
    printf("Enter key:");
    scanf("%s", key);

    for (int i = 0, j = 0; i < strlen(pt); i++, j++)
    {
        if (j >= strlen(key))
        {
            j = 0;
        }

        int shift = toupper(key[j]) - 'A';
        char encrypted = ((toupper(pt[i]) - 'A' + shift) % 26) + 'A';
        printf("%c", encrypted);
    }
    printf("\n");
}

void decrypt()
{
    char cipher[128];
    char key[16];
    printf("Enter ciphertext:");
    gets(cipher);
    printf("Enter key:");
    gets(key);

    for (int i = 0, j = 0; i < strlen(cipher); i++, j++)
    {
        if (j >= strlen(key))
        {
            j = 0;
        }
        int shift = toupper(key[j]) - 'A';
        char decrypted = ((toupper(cipher[i]) - 'A' - shift + 26) % 26) + 'A';
        printf("%c", decrypted);
    }
    printf("\n");
}

int main()
{
    int option;
    while (1)
    {
        printf("1.Encrypt\n");
        printf("2.Decrypt\n");
        printf("3.Exit");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            encrypt();
            break;
        case 2:
            decrypt();
            break;
        case 3:
            exit(0);

        default:
            printf("Enter correct option");
            break;
        }
    }
    return 0;
}

