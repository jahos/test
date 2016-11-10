#include "dictionary.h"

#define TRUE 1
#define FALSE 0

Node* createNode(char sign, Node *parent)
{
    Node* node = (Node*) malloc (sizeof(Node));

    if(node != NULL)
    {
        node->parent = (parent == NULL) ? node : parent;
        node->sign = sign;
        node->childrenCount = 0;
        node->nodeLevel = (parent != NULL) ? (parent->nodeLevel + 1) : 0;
        for(int i=0; i < 27; ++i)
        {
            node->children[i] = NULL;
        }
    }
    return node;
}

int insertNode(Node* parent, Node *child)
{
    int result = FALSE;

    if( parent == NULL || child == NULL )
    {
        return result;
    }

    parent->children[parent->childrenCount] = child;
    parent->childrenCount++;

    return result;
}

void printNode(Node* nd)
{
    if(nd != NULL)
    {
        printf("node->sign %c\n",nd->sign);
        printf("node->nodeLevel %d\n",nd->nodeLevel);
//        printf("node->childrenCount %d\n\n",nd->childrenCount);
        for(unsigned int i=0; i < nd->childrenCount; ++i)
        {
            printNode(nd->children[i]);
        }
        printf("-------------------\n");
    }
}

int addToDictionary(Node* dict,const char* word)
{
    if(*word != '\0')
    {
        int x = isKeyOk(dict,word);
        Node* isChildKeyOk = searchChild(dict,word);
        if(isChildKeyOk != NULL)
        {
            addToDictionary(isChildKeyOk,++word);
        }
        if(x != TRUE && isChildKeyOk == NULL)
        {
            Node* newNode  = createNode(*word,dict);
            insertNode(dict,newNode);
            addToDictionary(newNode,++word);
        }
    }
}

int searchNode(Node*nd,const char* word)
{
    const char root = ROOT;
    int retVal = isKeyOk(nd,word);
    int isItRoot = isKeyOk(nd,&root);

    if(retVal || isItRoot)
    {
        Node* tmpNode = NULL;
        if(isItRoot)
        {
            tmpNode = searchChild(nd,word);
        }
        else
        {
            tmpNode = searchChild(nd,++word);
        }

        if(tmpNode != NULL)
        {
            retVal = searchNode(tmpNode,word);
        }
        else
        {
            if(*word == '\0')
            {
                retVal =  TRUE;
            }
            else
            {
                retVal =  FALSE;
            }
        }
    }
    return retVal;
}

Node* searchChild(Node*nd,const char* sign)
{
    Node* retNode = NULL;
    for(unsigned int i=0; i < nd->childrenCount; ++i)
    {
        int retVal = isKeyOk(nd->children[i],sign);
        if(retVal)
        {
            retNode = nd->children[i];
            break;
        }
    }
    return retNode;
}

int isKeyOk(Node* nd, const char* sign)
{
    int retVal = (nd->sign == *sign) ? TRUE : FALSE;
    return retVal;
}

