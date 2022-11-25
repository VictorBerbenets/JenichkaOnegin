#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <malloc.h>
#include <stdlib.h>

#define ConstMemory 15

char* s_gets1(char* name, int Size);

char* s_gets2(char* name, int size);

int str_length(const char* string);

char* str_cotia(char* string1,const char* string2);

char* strn_cotia(char* string1,const char* string2, int n);

int is_equal(const char* string1,const char* string2);

char* get_first_symbol(char* name, int n); 

char* strn_copy(char* pt1,const char* pt2, int n);

char* str_copy(char* pt1,const char* pt2);

char* my_fgets(char* str, int size, FILE* stream);

char* my_strdup(const char* str);

size_t my_getline(char** string, size_t* size, FILE* stream);
