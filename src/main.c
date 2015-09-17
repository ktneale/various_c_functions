#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

///Acceptable...
int a_atoi(const char *a)
{
    int val = 0, i = 0, mulipler = 1, len = 0;

    len = strlen(a);

    while (a[i] != '\0') {
        if (i != 0) {
            mulipler = mulipler * 10;
            val += (mulipler * ((a[len - (i + 1)]) - 48));
        } else {
            val += ((a[len - (i + 1)]) - 48);
        }

        i++;
    }
    return val;
}

//Optimised
int b_atoi(const char *a)
{
    int i = 0, j = 0, sign = 1;

    if (!a) {
        return 0;
    } else if (a[j] == '-') {
        sign = -1;
        j++;
    } else if ((a[j] == '+')) {
        j++;
    }

    while (a[j] != '\0') {
        if (!isdigit(a[j]))
            return (sign * i);  //isdigit takes an int, but verifies if the value is in the ASCII range of char i.e. 48-57 not 0-9

        i = (i << 3) + (i << 1);        //Bitshift operators return the a 'bitshifted' copy of the object.
        i += (a[j] - 48);       //Use =<< or =>> to shift and update.
        j++;
    }
    return (sign * i);
}

//Optimised - minimal
int c_atoi(const char *a)
{
    int i = 0, j = 0;

    while (a[j] != '\0') {
        i = (i << 3) + (i << 1);        //Bitshift operators return the a 'bitshifted' copy of the object.
        i += (a[j] - '0');      //Use =<< or =>> to shift and update.
        j++;
    }
    return i;
}

#define DEBUG 1

const char *a_strstr(const char *str1, const char *str2)
{
    int i = 0, j = 0;

#ifdef DEBUG
    printf("\nstring [START]\n");

    while (str1[i] != '\0') {
        printf("%p\n", &str1[i]);
        i++;
    }
    printf("string [END]\n");

    i = 0;                      //Reset i;
#endif

    while (str1[i] != '\0') {
        if (str1[i] == str2[0]) //If the first character matches
        {
            j = 0;

            while (str2[j] != '\0') {
                if (str1[i + j] != str2[j]) {
                    break;
                }

                if (str2[j + 1] == '\0') {
                    return (const char *) &str1[i];
                }

                j++;
            }
        }

        i++;
    }

    return NULL;
}

int main()
{
    printf("%d\n", a_atoi("1782438"));
    printf("%d\n", b_atoi("1782438"));
    printf("%d\n", b_atoi("+1782438"));
    printf("%d\n", b_atoi("-1782438"));
    printf("%d\n", b_atoi("j1782438"));
    printf("%d\n", b_atoi("1782j438"));

    printf("%p\n", a_strstr("abcdefghi", "def"));
    printf("%p\n", a_strstr("abcdefghi", "efg"));
    printf("%p\n", a_strstr("abcdefghi", "efk"));
    return 0;
}
