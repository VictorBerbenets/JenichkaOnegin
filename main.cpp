#include "onegin.h"


int main() {

    strings_inform* onegin_strings;

    buffer onegin_text;

    ReadFile("onegin.txt", &onegin_text);

    onegin_strings = Constructor(&onegin_text);

    //strings_inform* onegin_strings_copy = onegin_strings;
 
    SortFromBeginning(onegin_strings, &onegin_text);

    PrintSortingText(onegin_strings, &onegin_text, "SORT FROM THE BEGINNING OF THE LINES");

    SortFromEnd(onegin_strings, &onegin_text);

    PrintSortingText(onegin_strings, &onegin_text, "SORT FROM THE END OF THE LINES");

    //PrintSortingText(onegin_strings_copy, &onegin_text, "ORIGINAL TEXT");

    Destroyer (onegin_strings, &onegin_text);

    return 0;
}
