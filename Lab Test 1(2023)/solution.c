#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXWORD 30
#define ALPHABET_SIZE 26

typedef struct wordsLLNode* NODE;
struct wordsLLNode{
    NODE next;
    char *word;
};

struct wordsLLHeader{
    NODE head;
};
typedef struct wordsLLHeader HEAD;

struct wordsLLTail{
    NODE tail;
};
typedef struct wordsLLTail TAIL;

struct record{
    HEAD ll;
    TAIL llt;
    int length;
};
typedef struct record REC;

REC *readData(char *filename)
{
    FILE *fptr = fopen(filename, "r");
    if (fptr == NULL)
    {
        printf("Unable to open file !\n");
        return NULL;
    }
    int n;
    fscanf(fptr, "%d", &n);
    char *line = (char*) malloc(sizeof(char)*MAXWORD);
    REC *wordBuckets = (REC*) malloc(sizeof(REC)*26);
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        REC rec;
        rec.ll.head = NULL;
        rec.llt.tail = NULL;
        wordBuckets[i] = rec;
        wordBuckets[i].length = 0;
    }
    while (fgets(line, MAXWORD, fptr))
    {   
        char top = line[0];
        int c = (int) top;
        c -= 97;
    
        NODE node = (NODE) malloc(sizeof(struct wordsLLNode));
        node->word = (char*) malloc(sizeof(char)*MAXWORD);
        strcpy(node->word, line);
        node->next = wordBuckets[c].ll.head;
        if (node->next == NULL) wordBuckets[c].llt.tail = node;
        wordBuckets[c].ll.head = node;
        wordBuckets[c].length++;
    }

    return wordBuckets;
}

int max(int a, int b)
{
    if(a>b) return a;
    else return b;
}

int findMaxGap(REC *wordBuckets)
{   
    int maxGap = 0;
    int a = -1;

    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        if (wordBuckets[i].length > 0)
        {
            if (a != -1)
            {
                maxGap = max(maxGap, i - a);
            }
            a = i;
        }
    }

    return maxGap;
}

// void partitionLists(REC *wordBuckets)
// {
//     for (int i = 0; i < ALPHABET_SIZE; i++)
//     {   
//         int n = wordBuckets[i].length;
//         NODE current = wordBuckets[i].ll.head;
//         HEAD h1
//         while (n--)
//         {
//             if (current->word[2] >= 'a' && current->word[2] <= 'm')
//             {   
//                 NODE prev = wordBuckets[i].ll.head;
//                 wordBuckets[i].ll.head = current;
//                 prev->next = current->next;
//                 current->next = prev;
//             }
//             else
//             {
//                 NODE prev = wordBuckets[i].llt.tail;
//                 wordBuckets[i].ll.head = current;
//                 prev->next = current->next;
//                 current->next = prev;
//             }
//             current = current->next;
//         }     
//     }
// }

int main()
{   
    char *filename = "testfile.txt";
    REC *wordBuckets = readData(filename);
    // printf("%s\n", wordBuckets[0].ll.head->word);
    // printf("%s\n", wordBuckets[1].ll.head->word);
    // printf("%s\n", wordBuckets[1].ll.head->next->word);
    // printf("%s\n", wordBuckets[7].ll.head->word);
    // printf("%s\n", wordBuckets[7].ll.head->next->word);
    
    int maxGap = findMaxGap(wordBuckets);
    printf("%d\n", maxGap);

    return 0;
}
