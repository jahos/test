#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <cstdlib>
#include <cstdio>

#define ROOT '#'

typedef struct Node
{
    Node*   parent;
    char    sign;
    int     nodeLevel;
    size_t  childrenCount;
    Node*   children[27];
}root;

Node* createNode(char sign, Node *parent = NULL);
int addToDictionary(Node* dict,const char* word);
void printNode(Node* nd);
int searchNode(Node*nd,const char *word);
Node* searchChild(Node*nd,const char* sign);
int isKeyOk(Node* nd, const char* word);
int insertNode(Node* parent, Node *children);
void print(Node* n);

#endif // DICTIONARY_H
