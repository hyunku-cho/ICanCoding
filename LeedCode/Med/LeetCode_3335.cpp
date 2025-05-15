#include <stdio.h>
#include <string.h>

int lengthAfterTransformations(char* s, int t) {

    register int i, j;
    int returnValue = 0;
    long long countData[26] = { 0 };
    int mod = 1e9 + 7;

    //First, simplify s to 26.
    for (i = 0; i < strlen(s); i++)
        countData[s[i] - 'a']++;

    for (i = 1; i <= t; i++)
    {
        // 'z' is stored in a temporary variable.
        long long temp = countData[25];

        //All characters move one space at a time, except 'z'.
        for (j = 25; j > 1; j--)
            countData[j] = countData[j - 1];

        // Add the number of 'z' chars to countData[0] and coundData[1]. (Split into 'a' and 'b'.)
        // At this time, to prevent mod overflow, only the remainder divided by mod is stored.
        countData[1] = (countData[0] + temp) % mod;
        countData[0] = temp;
    }

    for (i = 0; i < 26; i++)
    {
        returnValue = (returnValue + countData[i]) % mod;
    }


    return returnValue;
}

int main()
{
    char testCode[5] = "abcz";
    int t = 250;

    int result = lengthAfterTransformations(testCode, t);
    printf("%d", result);
}