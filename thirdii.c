#include <stdio.h>
#include <string.h>

void main()
{
    int i, j, k, length;
    char input[20], cipher[20], decipher[20];
    printf("Enter the string to be encrypted: ");
    gets(input);
    length = strlen(input);
    printf("Ciphered text:");
    j = 0;
    for (int i = 0; i < length; i++)
    {
        if (i % 2 == 0)
        {
            cipher[j++] = input[i];
        }
    }
    for (int i = 0; i < length; i++)
    {
        if (i % 2 == 1)
        {
            cipher[j++] = input[i];
        }
    }
    cipher[length] = '\0';
    printf("%s", cipher);

    if (length % 2 == 0)
    {
        k = length / 2;
    }
    else
    {
        k = (length + 1) / 2;
    }

    j = 0;
    for (int i = 0; i < k; i++)
    {
        decipher[j] = cipher[i];
        j += 2;
    }
    j = 1;
    for (int i = k; i < length; i++)
    {
        decipher[j] = cipher[i];
        j += 2;
    }
    decipher[length] = '\0';
    printf("deciphered text: %s ", decipher);
}