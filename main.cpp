#include "onegin.h"

const char arr[] = {',', '.', '!', '?', ' '};

int main()
{      
    strings_inform* onegin_strings;

    buffer onegin_text;

     setlocale(LC_ALL, "RUS");

    ReadFile("onegin.txt", &onegin_text);

    onegin_strings = Constructor(&onegin_text);
 
    SortFromBeginning(onegin_strings, &onegin_text);

    PrintSortingText(onegin_strings, &onegin_text);

    // char name[50] = "МЫЛО";

    // printf("S = %s\n", name);

    // int i = 1;

    // printf("name[%d] = %c%c\n", i, name[2*i], name[2*i + 1]);


    // //putchar(name[0]);

    // printf("\n");

    // for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {

    //     printf("arr[%d] = %c\n", i, arr[i]);

    // }


    //SortFromEnd(onegin_strings, &onegin_text);

    //Destroyer(onegin_strings, &onegin_text);

    return 0;
}
