#include "dictionary.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    Node* dictionary = createNode(ROOT,0);
    printf("%d %s\n",argc,argv[0]);


    const char napis[] = "MCDGA";
    const char* wsk = &napis[0];

    printf("Searched word: %s\n",napis);


    addToDictionary(dictionary,"Ala");
    addToDictionary(dictionary,"ma");
    addToDictionary(dictionary,"kota");
    addToDictionary(dictionary,"Alicja");
    addToDictionary(dictionary,"Alarm");
    addToDictionary(dictionary,"Alternator");
    printNode(dictionary);
    int x = 0;
    x = searchNode(dictionary,wsk);
    printf("Search result: %d\n",x);


    puts("koniec");
    free(dictionary);
    return 0;
}
