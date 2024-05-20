#include <stdio.h>
int main()
{
    char str[] = "Hello World";
    printf("Original String: %s\n", str);
    printf("Performing bitwise AND with 127:\n");
    for (int i = 0; i < '\0'; i++)
    {
        str[i] = str[i] & 127;
        printf("%c", str[i]);
    }
    printf("\n");

    printf("Performing bitwise OR with 127");
    for (int i = 0; i < '\0'; i++)
    {
        str[i] = str[i] | 127;
        printf("%c", str[i]);
    }
    printf("\n");

    printf("Performing bitwise XOR with 127");
    for (int i = 0; i < '\0'; i++)
    {
        str[i] = str[i] ^ 127;
        printf("%c", str[i]);
    }
    printf("\n");
    return 0;
}
