#include "onegin.h"

void Destroyer(strings_inform* onegin_strings, buffer*  onegin_text) {

    for (size_t string_number = 0; string_number < onegin_text -> number_of_strings; string_number ++) {

        onegin_strings[string_number].string_size = 0;
    }

    free(onegin_strings);

    free(onegin_text -> buf);

    onegin_text -> number_of_strings = 0;
}

long getFileSize(const char *file) {
    
    ASSERT(file != nullptr);

    struct stat buf = {};

    if (stat(file, &buf)) {

        fprintf(stderr, "\033[0;31mERROR\033[0m!!!\nFile <%s>: in function <%s>,  in line '%d' - error in function \"stat\"\n", __FILE__, __PRETTY_FUNCTION__, __LINE__);

        return -1;
    }

    return buf.st_size;
}

void ReadFile(const char* name_file, buffer* onegin_text) {

    FILE*  stream = fopen(name_file, "r");

    ASSERT(stream != nullptr);

    size_t tekst_size = getFileSize(name_file) + 2;

    onegin_text -> buf = (char*) calloc(tekst_size, sizeof(char));

    ASSERT(onegin_text -> buf != nullptr);

    onegin_text->symbols_in_buffer = tekst_size;

    size_t number_of_simbols = 0;

    if ((number_of_simbols = fread(onegin_text -> buf, sizeof(char), tekst_size, stream)) != (tekst_size - 2)) {

        ASSERT(!feof(stream));

    }

    ASSERT(onegin_text -> buf != nullptr);

    *(onegin_text -> buf + number_of_simbols)     = '\n';

    *(onegin_text -> buf + number_of_simbols + 1) = '\0';
   
    GetNumberOfStrings(onegin_text);

    ASSERT(fclose(stream) == 0);
}

void GetNumberOfStrings(struct buffer* onegin_text) {

    ASSERT(onegin_text -> buf != nullptr);

    onegin_text -> number_of_strings = 0;
    
    char* pt = onegin_text -> buf;

    for (size_t symbols = 0 ; symbols < onegin_text->symbols_in_buffer; symbols++) {  
        if (*pt == '\n'){
            onegin_text -> number_of_strings ++;
        }
        pt++;
    }
}

strings_inform* Constructor(buffer* onegin_text){

    ASSERT(onegin_text->buf != nullptr); 
    
    strings_inform* onegin_strings = (strings_inform*) calloc(onegin_text->number_of_strings, sizeof(strings_inform));

    char* is_eof = onegin_text->buf;

    char* buf_pointer = onegin_text->buf;

    size_t not_empty_strings = 0;

    size_t symbols = 0;

    for (size_t symbols_in_one_string = 0; symbols < onegin_text->symbols_in_buffer; is_eof++, symbols ++) {  

        if (*is_eof != '\n') {

            symbols_in_one_string++;
            
            continue;
        } 

        else {

            *is_eof = '\0';

            onegin_strings[not_empty_strings].string_size = symbols_in_one_string;

            onegin_strings[not_empty_strings].string = buf_pointer;

            not_empty_strings++;

            buf_pointer += symbols_in_one_string + 1;
            
            symbols_in_one_string = 0;

            if (*(is_eof + 1) == '\n') {

                SkipSimbolsEndOfString(&is_eof, &buf_pointer);  
            }       
        }       
    }

    onegin_strings = (strings_inform*) realloc(onegin_strings, sizeof(strings_inform) * not_empty_strings);

    onegin_text->number_of_strings = not_empty_strings;

    return onegin_strings;
}

void SkipSimbolsEndOfString(char** is_eof, char** buf_pointer) {

        int counter = 0;

        while (*(++(*is_eof)) == '\n'){
            counter ++;
        }

        (*is_eof)--;

        *buf_pointer += counter;   
}