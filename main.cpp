#include "onegin.h"


int main() {

    strings_inform* onegin_strings;

    buffer onegin_text;

    ReadFile("onegin.txt", &onegin_text);

    onegin_strings = Constructor(&onegin_text);
 
    SortFromBeginning(onegin_strings, &onegin_text);

    PrintSortingText(onegin_strings, &onegin_text, "SORT FROM THE BEGINNING OF THE LINES");

    SortFromEnd(onegin_strings, &onegin_text);

    PrintSortingText(onegin_strings, &onegin_text, "SORT FROM THE END OF THE LINES");

    PrintOriginalText(&onegin_text);

    Destroyer (onegin_strings, &onegin_text);

    return 0;
}
