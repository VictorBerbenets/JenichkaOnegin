#ifndef Onegin_proga
#define Onegin_proga


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <ctype.h>
#include "strings.h"

const char forbidden_symbols[20] = {',', '.', '!', '?', ' ', '(', ')', '\'', '{', '}', ';', ':'};


#define ASSERT(expression) \
\
    if (!(expression)) {\
\
        fprintf(stderr, "\033[0;31mERROR\033[0m!!!\nFile <%s>: in function <%s>, line '%d'\nThe expression: \"%s\" is false\n\n",\
         __FILE__, __PRETTY_FUNCTION__, __LINE__, #expression);\
\
    }\


struct buffer{ // Text 

    char* buf;

    size_t number_of_strings;

    size_t symbols_in_buffer;
};


struct strings_inform{

    char* string;

    size_t string_size;
};




strings_inform* Constructor(buffer* onegin_text);

long getFileSize(const char *file);

void ReadFile(const char* name_file, buffer* onegin_text);

void GetNumberOfStrings(buffer* onegin_text);

void SkipSimbolsEndOfString(char** is_eof, char** buf_pointer);

void SortFromBeginning(strings_inform* onegin_strings, buffer* onegin_text);

void PrintSortingText(strings_inform* onegin_strings, buffer* onegin_text, const char* where_to_sort);

void SortFromEnd(strings_inform* onegin_strings, buffer* onegin_text);

int compare (char* string1, char* string2);

int backward_compare (char* string1, char* string2);

bool notAlpha (char c);

void Destroyer(strings_inform* onegin_strings, buffer*  onegin_text);

void swap (char** string1, char** string2);


#endif