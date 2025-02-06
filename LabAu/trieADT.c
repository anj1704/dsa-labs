#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
#define ALPHABET_SIZE 128 //you can instead reduce the alphabet size and create your own mapping of character to index in array

int CHAR_TO_INDEX(char c)
{
    //custom mapping if alphabet size reduced
    return (int)c;
}

// trie node
struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
    // isEndOfWord is true if the node represent end of a word
    bool isEndOfWord;
    // void* data; 
    // instead of checking for the presence or absence of a string,
    // if we wish to assign some value with the key as a pair, then this could be
    // uncommented
    int childCount;
};

// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void)
{
    struct TrieNode *pNode = NULL;
    pNode = (struct TrieNode *)malloc(sizeof(struct TrieNode));
    if (pNode)
    {
        int i;
        pNode->isEndOfWord = false;
        pNode->childCount = 0;
        for (i = 0; i < ALPHABET_SIZE; i++)
            pNode->children[i] = NULL;
    }

    return pNode;
}

// If not present, inserts key into trie
// If the key is prefix of trie node, just marks leaf node
void insert(struct TrieNode *root, const char *key)
{
    int level;
    int length = strlen(key);
    int index;

    struct TrieNode *pCrawl = root;
    for (level = 0; level < length; level++)
    {
        index = CHAR_TO_INDEX(key[level]);
        if (!pCrawl->children[index]) 
        {
            pCrawl->children[index] = getNode();
            pCrawl->childCount++;
        }        
        pCrawl = pCrawl->children[index];
    }
    // mark last node as leaf
    pCrawl->isEndOfWord = true;
}

// Returns true if key presents in trie, else false
bool search(struct TrieNode *root, const char *key)
{
    int level;
    int length = strlen(key);
    int index;

    struct TrieNode *pCrawl = root;
    for (level = 0; level < length; level++)
    {
        index = CHAR_TO_INDEX(key[level]);
        if (!pCrawl->children[index])
            return false;
        pCrawl = pCrawl->children[index];
    }

    return (pCrawl->isEndOfWord);
}

bool delete(struct TrieNode *root, const char *key, int level)
{
    struct TrieNode *pCrawl = root;
    int index = CHAR_TO_INDEX(key[level]);
    int length = sizeof(key)/sizeof(key[0]);
   
    if (pCrawl->isEndOfWord && level == length) 
    {   
        if (pCrawl->childCount == 0)
        {
            free(pCrawl);
            // pCrawl == NULL ? printf("YYYY !\n") : printf("NNNNN\n");
            return true;
        }
        else
        {
            pCrawl->isEndOfWord = false;
            return false;
        }
    }

    if (!pCrawl->children[index])
        return false;

    if (delete(pCrawl->children[index], key, level + 1))
    {   
        pCrawl->childCount--;
        if (pCrawl->childCount == 0 && pCrawl->isEndOfWord == false)
        {   
            // free(pCrawl->children[index]);
            free(pCrawl);
            return true;
        }
        // need a recursive delete function
        // for (int i = 0; i < ALPHABET_SIZE; i++)
            // if (!pCrawl->children[i]) free(pCrawl->children[i]);
        free(pCrawl->children[index]);
        return false;
    }
    
    return false;    
}

// Driver
int main()
{
    // Input keys (use only 'a' through 'z' and lower case)
    char keys[][8] = {"the", "a", "there", "answer", "any", "by", "bye", "their"};
    char output[][32] = {"Not present in trie", "Present in trie"};
    struct TrieNode *root = getNode();
    
    // Construct trie
    int i;
    for (i = 0; i < sizeof(keys)/sizeof(keys[0]); i++)
        insert(root, keys[i]);
    
    // Search for different keys
    printf("%s --- %s\n", "the", output[search(root, "the")] );
    printf("%s --- %s\n", "these", output[search(root, "these")] );
    printf("%s --- %s\n", "their", output[search(root, "their")] );
    printf("%s --- %s\n", "thaw", output[search(root, "thaw")] );

    // Delete a particular key
    printf("\nDeleting the word - there \n");
    printf("%s --- %s\n", "there", output[search(root, "there")] );
    delete(root, "there", 0) ? printf("Word deleted !\n") : printf("Failed to delete word.\n");
    printf("%s --- %s\n", "there", output[search(root, "there")] );

    printf("\nDeleting the word - bye \n");
    printf("%s --- %s\n", "bye", output[search(root, "bye")] );
    delete(root, "bye", 0) ? printf("Word deleted !\n") : printf("Failed to delete word.\n");
    printf("%s --- %s\n", "bye", output[search(root, "bye")] );

    return 0;
}