#include "strings.h"


char* s_gets1(char* name, int Size) // working like fgets, but only don't take \n in the end of the string
{
    assert(name != NULL);
    char* pt = NULL;
    pt = fgets(name,Size,stdin);
    assert(pt != NULL);
    while(*pt != '\n' && *pt != '\0')
    {
        pt++;
    }
    if (*pt == '\n')
        *pt = '\0';
    else // if (pt[i] == '\0')
    {
        while (getchar() != '\n')
            continue;
    }
    return name;
}

char* s_gets2(char* name, int size) // analogue of s_gets1() but only with strchr()
{
    char* pt1 = NULL;
    char* pt2 = fgets(name,size,stdin);
    pt1 = strchr(name,'\n');
    if (pt1)
    {
        *pt1 = '\0';
    }
    else
    {
        while (getchar() != '\n')
            continue;
    }
    return pt2;
}



int str_length(const char* string) 
{
    int i = 0;
    assert(string != NULL);
    while (*string != '\0')
    {
        i++;
        string++;

    }

    return i;
}

char* str_cotia(char* string1,const char* string2) // my strcat
{
    int Size = strlen(string1);
    assert(string1 != NULL && string2 != NULL);
    int i = 0;
    while(string2[i] != '\0')
    {
        string1[Size++] = string2[i++];
    }
    string1[Size] = '\0';
    return string1;

}


int is_equal(const char* string1,const char* string2) //working like strcmp
{
    assert(string1 != NULL && string2 != NULL);

    if ((strlen(string1) != strlen(string2)))
        return (string1 - string2);

    int line = strlen(string1);
    for (int i = 0; i < line; i++)
    {
        if (string1[i] != string2[i])
            return (string1 - string2);

    }

    return 0;
}

char* get_first_symbol(char* name, int n) // analogue of strchr
{
    assert(name != NULL);
    int i = 0;
    while (name[i] != n && (i <= (str_length(name) + 1)))
    {
        i++;
    }
    if (name[i] == n)
        return &name[i];
    else
        return NULL;
}



char* strn_cotia(char* string1,const char* string2, int n)
{
    int Size = strlen(string1);
    assert(string1 != NULL && string2 != NULL);
    int i = 0;
    while(string2[i] != '\0' && i < n)
    {
        string1[Size++] = string2[i++];
    }
    string1[Size] = '\0';
    return string1;


}

char* strn_copy(char* pt1,const char* pt2, int n)
{
    int i = 0;
    char* pt = NULL;
    pt = pt1;
    assert(pt1 != NULL && pt2 != NULL);
    while (*pt2 && i < n)
    {
        *pt1++ = *pt2++;
        i++;
    }
    *pt1 = '\0';
    return pt;
}

char* str_copy(char* pt1,const char* pt2)
{
    char* pt = NULL;
    pt = pt1;
    assert(pt1 != NULL && pt2 != NULL);
    while (*pt2)
    {
        *pt1++ = *pt2++;
    }
    pt1 = pt;
    return pt1;
}


char* my_fgets(char* str, int size, FILE* stream){

    assert(stream != NULL);

    char chr = 0;

    for (int i = 0; i < size - 1; i++){ // - 1, ???????????? ?????? ?????? ?????????? ???????????? ?????????? ????????????

        chr = fgetc(stream);
        
        if (chr == EOF){
            break;
        }
        if (chr == '\n'){
            str[i] = '\n';
            break;
        }
        
        str[i] = chr;

    }
    str[size - 1] = '\0';

    return str;

}

char* my_strdup(const char* str){

    if (!str)
        return NULL;

    size_t size_of_string = strlen(str);

    char* str_pt = (char*) malloc((size_of_string + 1)* sizeof(char));

    if (!str_pt){
        free(str_pt);
        perror(str_pt);
    }

    int i = 0;

    for ( ; str[i] != '\0'; i++){
        str_pt[i] = str[i];
    }

    str_pt[i] = '\0';

    return str_pt;
}

size_t my_getline(char** string, size_t* size, FILE* stream){

    char is_string_null = 0;

    *size = 5;

    if (!stream){
        *size = -1;
        fprintf(stderr,"Error in line '%d', in function: <%s>: stream = nullptr\n", __LINE__, __FUNCTION__);
        return EOF;
    }

    if (!*string){
        *string = (char*) calloc(ConstMemory, sizeof(char));
        is_string_null = 1;
    }
    else{
        is_string_null = 0;
    }

    if (!*string){ // if calloc couldn't give memory
        *size = -1;
        fprintf(stderr,"Error in line '%d', in function: <%s>: segmantation fault\n", __LINE__, __FUNCTION__);
        return EOF;
    }

    char chr = 0;

    size_t i = 0;

    chr = fgetc(stream);

    for ( ; chr != EOF && chr != '\n'; i++, chr = fgetc(stream)){

        if (i == *size && is_string_null){

            *size += ConstMemory;

            *string = (char*) realloc(*string, *size * sizeof(char));
        }
        
        *(*string + i) = chr;


    }

    if (!*string){
        *size = -1;
        fprintf(stderr,"Error in line '%d', in function: <%s>: string = nullptr after realloc\n", __LINE__, __FUNCTION__);
        return EOF;
    }

    if (is_string_null)
        *string = (char*) realloc(*string, *size * sizeof(char));

    if (!*string){
        *size = -1;
        fprintf(stderr,"Error in line '%d', in function: <%s>: string = nullptr \n", __LINE__, __FUNCTION__);
        return EOF;
    }

    *size = i;

    return *size;

}
