#include <stdio.h>
#include <string.h>
int main()
{
    unsigned int encryptkey[3][3] = {{6, 24, 1}, {13, 16, 10}, {20, 17, 15}};
    unsigned int decryptkey[3][3] = {{8, 5, 10}, {21, 8, 21}, {21, 12, 8}};
    int c[20], d[20];
    char pt[20];
    int t = 0;
    printf("Enter plaintext:");
    scanf("%s", pt);

    for (int i = 0; i < 3; i++)
    {
        c[i] = pt[i] - 65;
        printf("%d", c[i]);
    }

    for (int i = 0; i < 3; i++)
    {
        t = 0;
        for (int j = 0; j < 3; j++)
        {
            t += encryptkey[i][j] * c[j];
        }
        d[i] = t % 26;
    }

    printf("Encrypted cipher text:\n");

    for (int i = 0; i < 3; i++)
        printf("%c", d[i] + 65);

    for (int i = 0; i < 3; i++)
    {
        t = 0;
        for (int j = 0; j < 3; j++)
        {
            t += decryptkey[i][j] * d[j];
        }
        c[i] = t % 26;
    }
    printf("Decrypted key:");
    for (int i = 0; i < 3; i++)
    {
        printf("%c", c[i] + 65);
    }
    return 0;
}
