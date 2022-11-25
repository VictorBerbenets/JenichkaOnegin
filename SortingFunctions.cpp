#include "onegin.h"


const char arr[10] = {',', '.', '!', '?', ' '};
const char tree[] = "»";

const char* forbidden_symbols = arr;

void SortFromBeginning(struct strings_inform* onegin_strings, struct buffer* onegin_text) {

    ASSERT(onegin_strings != nullptr);

    ASSERT(onegin_text != nullptr);

    for (size_t i = 0; i < onegin_text -> number_of_strings; i++) {
        //fprintf(stderr, "s = %s\n", onegin_strings[i].string);
        for (size_t j = i + 1; j < onegin_text -> number_of_strings; j++){
            
            if (compare(onegin_strings[i].string, onegin_strings[j].string) > 0){

                swap(&onegin_strings[i].string, &onegin_strings[j].string);
            }
        }
    }
}


void SortFromEnd(struct strings_inform* onegin_strings, struct buffer* onegin_text) {

    
    ASSERT((bool)(onegin_strings != nullptr));

    ASSERT((bool)(onegin_text != nullptr));

    char* replace = nullptr;

    for (size_t i = 0; i < onegin_text -> number_of_strings; i++) {

        for (size_t j = i + 1; j < onegin_text -> number_of_strings; j++){

            //replace = IterateOverTheLines(onegin_strings[i].string, onegin_strings[j].string);

            fprintf(stderr, "i = %zd, j = %zd, replace = %s\n", i, j, replace);

            fprintf(stderr, "onegin_strings[%zd].string= %s, onegin_strings[%zd].string = %s\n", i, onegin_strings[i].string, j, onegin_strings[j].string);
            if (replace == nullptr) {

                fprintf(stderr, "");

            }
            else if (replace != onegin_strings[i].string) {
 
                onegin_strings[j].string = onegin_strings[i].string; 

                onegin_strings[i].string = replace;
            }

            //if (backward_strcmp(onegin_strings[i], onegin_strings[j]) > 0) swap (onegin_strings[i], onegin_strings[j]);
        
       //IterateOverTheLines(onegin_strings[i].string, onegin_strings[j].string);

        }
    }

    PrintSortingText(onegin_strings, onegin_text);

}


void swap (char** string1, char** string2) {

    ASSERT(string1 != nullptr);

    ASSERT(string2 != nullptr);

    char* save_the_line = nullptr;

    save_the_line = *string1;

    *string1 = *string2;

    *string2 = save_the_line;
}

int compare (char* string1, char* string2) {

    ASSERT(string1 != nullptr);

    ASSERT(string2 != nullptr);

    char* pt1 = string1;

    char* pt2 = string2;

    int counter = 0;

    //fprintf(stderr, "string1 = <%s>;   string2 = <%s>\n", string1, string2);


    while (true) {

        while (notAlpha(*pt1)) {
            //fprintf(stderr, "*pt1 = %c\n", *pt1);
            pt1 ++;

            if (!*pt1) {
                break;
            }
        }

        while (notAlpha(*pt2)) {
            //fprintf(stderr, "*pt1 = %c\n", *pt1);
            pt2 ++;

            if (!*pt2) {
                break;
            }
        }

        if (*pt1 != *pt2) {

            pt1++;

            pt2++;
        }

        else {

            break;
        }


    }

    return *pt1 - *pt2;

    // do {

    // // *pt1 = tolower(*pt1);

    // // *pt2 = tolower(*pt2);
    
    // if (counter > 0) {

    //     pt1 ++; 

    //     pt2 ++;

    // }
    // else {

    //     counter++;
    // }

    // while (notAlpha(*pt1)) {
    //     //fprintf(stderr, "*pt1 = %c\n", *pt1);
    //     pt1 ++;
    // }

    // while (notAlpha(*pt2)) {
    //     //fprintf(stderr, "*pt1 = %c\n", *pt1);
    //     pt2 ++;
    // }
    // // while (!isalpha(*pt1)) {
    // //     //fprintf(stderr, "notalpha\n");
    // //     pt1 ++;
    // // }

    // // while (!isalpha(*pt2)) {
    // //     //fprintf(stderr, "notalpha\n");
    // //     pt2 ++;
    // // }

    // } while(*pt1 && *pt2 && (*(pt1) == *(pt2)));

    // //fprintf(stderr, "string1 = <%s>;   string2 = <%s>\n", string1, string2);

    // return *pt1 - *pt2;
}

bool notAlpha (char c) {

    //fprintf(stderr, "c = %c\n", c);

    if (strchr (forbidden_symbols, c) != nullptr) {
        
        return true;

    }

    return false;
}

//cmit

// backward compare. strcmp => backward_strcmp

// int IterateOverTheLines(char* string1, char* string2){

    // ASSERT(string1 != nullptr);

    // ASSERT(string2 != nullptr);

//     size_t size_string1 = str_length(string1);
//     size_t size_string2 = str_length(string2);

//     char* pt1 = string1 + size_string1 - 1;
//     char* pt2 = string2 + size_string2 - 1;

//     //fprintf(stderr, "*pt1 = %c\n", *pt1);
//     fprintf(stderr, "*pt2 = %c\n", *pt2);

//     // while (pt1 != string1 || pt2 != string2)
//     // {
        



//     //     pt1--;
//     //     pt2--;
//     // }



//     for ( ; size_string1 >= 0 && size_string2 >= 0 ; pt1 --, pt2 --, size_string1 --, size_string2 --) {

//         for( ; (unsigned char) !isalpha(*pt1) && size_string1 >= 0 ; ) {

//             pt1 --;
//             size_string1 --;
//             //fprintf(stderr, "*pt1 = %c\n", *pt1);
//         }

//         for( ; !isalpha((unsigned char) *pt2) && size_string2 >= 0; ) {

//             pt2 --;
//             size_string2 --;
//             //fprintf(stderr, "*pt2 = %c\n", *pt2);
//         }

//         if (tolower(*pt1) != tolower(*pt2)) {

//             // if (*pt1 >= *pt2) {

//             //     return string1;
//             // }

//             // return string2;          
        
//             return *pt1 - *pt2;
//         }

//     }

//     return 0;
// }

// В хедере char forbidde_symbols[] = "./\}|{}{- ";

void PrintSortingText(struct strings_inform* onegin_strings, struct buffer* onegin_text) {

    ASSERT((bool)(onegin_strings != nullptr));

    ASSERT((bool)(onegin_text != nullptr));

    FILE* OneginSort = fopen("SortOnegin.txt", "a");

    for (size_t string_number = 0; string_number < onegin_text -> number_of_strings; string_number ++) {

        fprintf(OneginSort, "%s\n", onegin_strings[string_number].string);
    }

    fprintf(OneginSort, "\n\n\n");

    fclose(OneginSort);

}