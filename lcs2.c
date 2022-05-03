#include <stdio.h>
char str1[20] = "0abcbdab"; //string 1
char str2[20] = "0bdcaba";  //string 2
int m[20][20] = {0};        //matrix
char ma[20][20] = {0};      //matrix of arrorws
int len1 = 7;               //len of string 1
int len2 = 6;               //len of string 2
char output[100];
int outputCount = -1;
void logic() // main logic here
{
    for (int i = 1; i <= len1; i++)
    {
        for (int j = 1; j <= len2; j++)
        {
            if (str2[j] == str1[i])
            {
                m[i][j] = 1 + m[i - 1][j - 1];
                ma[i][j] = 'D';
            }
            else
            {
                int a = m[i - 1][j];
                int b = m[i][j - 1];
                if (a >= b)
                {
                    m[i][j] = a;
                    ma[i][j] = 'U';
                }
                else
                {
                    m[i][j] = b;
                    ma[i][j] = 'L';
                }
            }
        }
    }
}
void display()
{
    printf(" ");
    for (int k = 0; k <= len2; k++)
    {
        printf("%c\t", str2[k]);
    }
    printf("\n");

    for (int i = 0; i <= len1; i++)
    {
        printf("%c ", str1[i]);
        for (int j = 0; j <= len2; j++)
        {
            printf("%d ", m[i][j]);
            printf("%c\t", ma[i][j]);
        }
        printf("\n");
    }
}

void Generate_Subsequence()
{ //genreates subsequence
    for (;;)
    {
        if (len1 == 0 || len2 == 0)
        {
            break;
        }
        char c = ma[len1][len2];
        if (c == 'D')
        {
            output[++outputCount] = str2[len2];
            len2--;
            len1--;
        }
        if (c == 'U')
            len1--;
        if (c == 'L')
            len2--;
    }
}
void input() //takes input
{
    printf("Enter len of string 1 and 2 respectively");
    scanf("%d %d", &len1, &len2);
    printf("%d %d\n", len1, len2);
    printf("enter string 1\n");
    scanf("%s", str1);
    for (int i = len1; i >= 1; i--)
    {
        str1[i] = str1[i - 1];
    }
    printf("enter string 2\n");
    scanf("%s", str2);
    str1[0] = 0;
    for (int i = len2; i >= 1; i--)
    {
        str2[i] = str2[i - 1];
    }
        str2[0] = 0;
}
void outputDisplay() //displays the generates subsequence
{
    for (int i = outputCount; i >= 0; i--)
    {
        printf("%c ", output[i]);
    }
}
int main()
{
    input();
    logic();
    display();
    printf("\n");
    Generate_Subsequence();
    outputDisplay();
}