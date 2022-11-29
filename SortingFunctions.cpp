#include "onegin.h"


void SortFromBeginning(strings_inform* onegin_strings, buffer* onegin_text) {

    ASSERT(onegin_strings != nullptr);

    ASSERT(onegin_text != nullptr);

    qsort(onegin_strings, onegin_text->number_of_strings, sizeof(onegin_strings[0]),Compare);
}


void SortFromEnd(strings_inform* onegin_strings, buffer* onegin_text) {

    ASSERT(onegin_strings != nullptr);

    ASSERT(onegin_text != nullptr);

    qsort(onegin_strings, onegin_text->number_of_strings, sizeof(onegin_strings[0]), Backward_Compare);
}

int Backward_Compare (const void* string1, const void* string2) {

    ASSERT(string1 != nullptr);

    ASSERT(string2 != nullptr);

    char* pt1 = ((strings_inform*) string1)->string;

    char* pt2 = ((strings_inform*) string2)->string;

    long size1 = strlen(pt1);

    long size2 = strlen(pt2);

    pt1 = strchr(pt1, '\0');

    pt2 = strchr(pt2, '\0');

    while (size1 > 0 && size2 > 0) {

        while (NotAlpha(*pt1) && size1 > 0) {

            size1--;
            pt1--;
        }

        while (NotAlpha(*pt2) && size2 > 0) {

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


int Compare (const void* string1, const void* string2) { 

    ASSERT(string1 != nullptr);

    ASSERT(string2 != nullptr);

    char* pt1 = ((strings_inform*) string1)->string;

    char* pt2 = ((strings_inform*) string2)->string;

    while (*pt1 && *pt2) {

        while (NotAlpha(*pt1)) {

            if (!*pt1) {

                break; 
            }
            pt1++;
        }

        while (NotAlpha(*pt2)) {

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

bool NotAlpha (char c) {

    if (strchr(forbidden_symbols, c) != nullptr) {

        return true;

    }

    return false;
}

void PrintOriginalText(buffer* onegin_text) {

    ASSERT(onegin_text->buf != nullptr);

    FILE* OneginSort = fopen("SortOnegin.txt", "a");

    ASSERT(OneginSort != nullptr);

    fprintf(OneginSort, "***********************************************************\n");
    fprintf(OneginSort, "             %s\n", "Original Text");
    fprintf(OneginSort, "***********************************************************\n\n\n");

    PutStringsInFile(&OneginSort, onegin_text);

    ASSERT(fclose(OneginSort) == 0);
}

void PutStringsInFile(FILE** OneginSort, buffer* onegin_text) {

    char* pt_buf = onegin_text->buf;

    char* is_end_of_string = onegin_text->buf;

    int strings = 0;

    for (size_t string_size = 0; strings < onegin_text->number_of_strings; string_size++, is_end_of_string++) {
         
        if (*is_end_of_string == '\0') {

            fprintf(*OneginSort, "%s\n", pt_buf);

            pt_buf += string_size;

            strings++;

            string_size = 0;

            is_end_of_string++;

            while (*is_end_of_string == '\n') {

                is_end_of_string++;
            }

            pt_buf = is_end_of_string;

        }
    }
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

        if (!SkipString(onegin_strings[string_number].string)) {

            fprintf(OneginSort, "%s\n", onegin_strings[string_number].string);
        }
    }

    fprintf(OneginSort, "\n\n\n");

    ASSERT(fclose(OneginSort) == 0);
}

int SkipString(char* string) {

    ASSERT(string != nullptr);

    char* pt = string;


    while (NotAlpha(*pt) || isdigit(*pt) || *pt == 'X' || *pt == 'L' || *pt == 'I' || *pt == 'V') {

        pt++;

        if (!*pt) {

            return 1; 
        }
    }

    return 0;
}