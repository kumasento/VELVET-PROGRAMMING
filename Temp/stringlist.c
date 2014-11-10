#include <stdio.h>

typedef struct {
    unsigned int size;
    char* list[];

} STRLIST;

static STRLIST listMediaType = {
    7, 
    {
        "Book",
        "Map",
        "Booklet",
        "Pamphlet",
        "Magazine",
        "Report",
        "Journal"
    }
};

int main() {
    printf("struct size: %d\n", listMediaType.size);
    int i;
    for (i = 0; i < listMediaType.size; i++) 
        printf("struct elem[%d] = \"%s\"\n", 
                i, 
                listMediaType.list[i]);

    return 0;
}
