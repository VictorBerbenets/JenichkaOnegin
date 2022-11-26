#include "onegin.h"


void SortFromBeginning(strings_inform* onegin_strings, buffer* onegin_text) {

    ASSERT(onegin_strings != nullptr);

    ASSERT(onegin_text != nullptr);

    for (size_t i = 0; i < onegin_text->number_of_strings; i++) {

        for (size_t j = i + 1; j < onegin_text -> number_of_strings; j++){

            if (compare(onegin_strings[i].string, onegin_strings[j].string) > 0){

                swap(&onegin_strings[i].string, &onegin_strings[j].string);
            }
        }
    }
}


void SortFromEnd(strings_inform* onegin_strings, buffer* onegin_text) {

    ASSERT((bool)(onegin_strings != nullptr));

    ASSERT((bool)(onegin_text != nullptr));

    for (size_t i = 0; i < onegin_text -> number_of_strings; i++) {

        for (size_t j = i + 1; j < onegin_text -> number_of_strings; j++){

            if (backward_compare(onegin_strings[i].string, onegin_strings[j].string) > 0){

                swap(&onegin_strings[i].string, &onegin_strings[j].string);
            }
        }
    }
}

int backward_compare (char* string1, char* string2) {

    ASSERT(string1 != nullptr);

    ASSERT(string2 != nullptr);

    int size1 = strlen(string1);

    int size2 = strlen(string2);

    char* pt1 = string1 + size1;

    char* pt2 = string2 + size2;

    while (size1 > 0 && size2 > 0) {

        while (notAlpha(*pt1) && size1 > 0) {

            size1--;
            pt1--;
        }

        while (notAlpha(*pt2) && size2 > 0) {

            size2--;
            pt2--;
        }

        if (*pt1 == *pt2) {
            
            size1--;

            size2--;

            pt1--;

            pt2--;
        }

        else {

            break;
        }
    }

    return *pt1 - *pt2;
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

    while (*pt1 && *pt2) {

        while (notAlpha(*pt1)) {

            if (!*pt1) {

                break; 
            }
            pt1++;
        }

        while (notAlpha(*pt2)) {

            if (!*pt2) {

                break; 
            }

            pt2++;
        }
        if (*pt1 == *pt2) {

            pt1++;

            pt2++;
        }
        else {

            break;
        }
    }

    return *pt1 - *pt2;
}

bool notAlpha (char c) {

    if (strchr(forbidden_symbols, c) != nullptr) {

        return true;

    }

    return false;
}

void PrintSortingText(strings_inform* onegin_strings, buffer* onegin_text, const char* where_to_sort) {

    ASSERT(onegin_strings != nullptr);

    ASSERT(onegin_text != nullptr);

    FILE* OneginSort = fopen("SortOnegin.txt", "a");

    ASSERT(OneginSort != nullptr);

    fprintf(OneginSort, "***********************************************************\n");
    fprintf(OneginSort, "             %s\n", where_to_sort);
    fprintf(OneginSort, "***********************************************************\n\n\n");

    for (size_t string_number = 0; string_number < onegin_text -> number_of_strings; string_number ++) {

        fprintf(OneginSort, "%s\n", onegin_strings[string_number].string);
    }

    fprintf(OneginSort, "\n\n\n");

    ASSERT(fclose(OneginSort) == 0);
}