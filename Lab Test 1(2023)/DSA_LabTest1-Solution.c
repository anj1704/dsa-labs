#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 128
#define NUMBER_OF_ALPHABETS 26

/* structure to node the header of the linked list of words
        word: character array for the word string to be stored
        next: pointer to the next node in the linked list
*/
typedef struct wordsLLNode{
    char word[MAX_WORD_LEN];
    struct wordsLLNode * next;
} wordsLLNode;

/* structure to store the header of the linked list of words 
        node: pointer to the head node of the linked list
*/
typedef struct wordsLLHeader{
    wordsLLNode * node;
} wordsLLHeader;

/* structure to store the tail of the linked list of words 
        node: pointer to the tail node of the linked list
*/
typedef struct wordsLLTail{
    wordsLLNode * node;
} wordsLLTail;

/* structure to store the linked list of words 
        header: header of the linked list
        tail: tail of the linked list
        length: length of the linked list
*/
typedef struct record{
    wordsLLHeader header;
    wordsLLTail tail;
    int length;
} record;

// function to find max of two numbers
int max(int a, int b){
    if(a>b) return a;
    else return b;
}

// function to create a new node with a given word stored
wordsLLNode * createNewNode(char * word){
    wordsLLNode * newNode = (wordsLLNode *) malloc(sizeof(wordsLLNode));
    newNode->next = NULL;
    strncpy(newNode->word,word,strlen(word));
    newNode->word[strlen(word)] = '\0';
    return newNode;
}

// function to add a node to a record with given word string
void addNodeToRecord(record * r, char * word){
    wordsLLNode * newNode = createNewNode(word);
    if(r->length==0){
        r->header.node = newNode;
        r->tail.node = newNode;
    } else{
        r->tail.node->next = newNode;
        r->tail.node = newNode;
    }
    r->length++;
}

// function takes the name of the file as an input parameter, creates a wordBuckets array, reads the words from the input file line by line and inserts them into their appropriate buckets of the wordBuckets array, and returns the wordBuckets array
record * readData(char * fileName){
    FILE * fp = fopen(fileName, "r");
    record * wordBuckets = (record *) malloc(sizeof(record)*NUMBER_OF_ALPHABETS);

    char word[MAX_WORD_LEN];

    while(fgets(word,MAX_WORD_LEN,fp)){
        //removes newline character from tail if read
        if(word[strlen(word)-1]=='\n')
            word[strlen(word)-1] = '\0';
        
        int firstAlphabetNumber;
        if(word[0]<='z' && word[0]>='a')
            firstAlphabetNumber = word[0]-'a';
        else 
            firstAlphabetNumber = word[0]-'A';
        addNodeToRecord(wordBuckets + firstAlphabetNumber,word);
    }

    fclose(fp);
    return wordBuckets;
}

// function takes the wordBuckets array as an input parameter, and finds the maximum gap between any two adjacent words stored in the wordBuckets array, when they are lexicographically ordered
int findmaxGap(record * wordBuckets){
    int maxGap = 0;

    int currAlpha = -1;
    for(int i=0;i<NUMBER_OF_ALPHABETS;i++){
        if(wordBuckets[i].length!=0){
            if(currAlpha!=-1)
                maxGap = max(maxGap,i-currAlpha);
            currAlpha = i;
        }
    }

    return maxGap;
}

// function takes the head of a linked list as an input partitions that linked list into two partitions
wordsLLNode * partitionLinkedList(wordsLLHeader head, int numberOfNodes){
    wordsLLNode * part1head=NULL, * part1tail=NULL;
    wordsLLNode * part2head=NULL, * part2tail=NULL;

    wordsLLNode * currNode = head.node;
    for(int i=0;i<numberOfNodes;i++){
        if(currNode->word[2]>'m'){
            if(part2head==NULL){
                part2head = currNode;
                part2tail = currNode;
            }
            else{
                part2tail->next = currNode;
                part2tail = currNode;
            }
        } else{
            if(part1head==NULL){
                part1head = currNode;
                part1tail = currNode;
            }
            else{
                part1tail->next = currNode;
                part1tail = currNode;
            }
        }
        currNode = currNode->next;
    }
    if(part1head==NULL){
        part2tail->next=NULL;
        return part2head;
    }
    else{
        part1tail->next = part2head;
        if(part2tail) part2tail->next=NULL;
        return part1head;
    }
}

// function takes the wordBuckets array as an input parameter, and partitions each linked list into two partitions
void partitionLists(record * wordBuckets){
    for(int i=0; i<NUMBER_OF_ALPHABETS; i++){
        if(wordBuckets[i].length==0) continue;
        wordBuckets[i].header.node = partitionLinkedList(wordBuckets[i].header,wordBuckets[i].length);
    }
}

// function takes the wordBuckets array as an input parameter, and prints the words stored in it.
void printData(record * wordBuckets){
    for(int i=0; i<NUMBER_OF_ALPHABETS; i++){
        wordsLLNode * itr =  wordBuckets[i].header.node;
        while(itr!=NULL){
            printf("%s\n",itr->word);
            itr = itr->next;
        }
    }
}

// function takes 2 input strings returns 0 if 1st input is lexicographically bigger else returns 1
int stringCompare(char * a, char * b){
    int lena = strlen(a), lenb = strlen(b);
    int minLen = lena<lenb ? lena : lenb;
    for(int i=0; i<minLen; i++){
        if(a[i]<b[i]) return 1;
        else if(a[i]>b[i]) return 0;
        else continue;
    }
    if(lena>lenb) return 0;
    else return 1;
}

// Merges 2 paritioned sorted arrays
wordsLLNode * mergeIn(wordsLLNode * head, int st1, int st2, int en2){
    wordsLLNode * head1=head, * head2, * newListHead=NULL, * newListTail=NULL;
    wordsLLNode * insertStart = head, * insertEnd=NULL;
    for(int i=0;i<st1;i++){
        head1 = head1->next;
        if(i!=st1-1) insertStart = insertStart->next;
    }
    head2 = head1;
    for(int i=0;i<st2-st1;i++)
        head2 = head2->next;
    int len1 = st2-st1, len2 = en2-st2+1;
    int coveredLen1 = 0, coveredLen2 = 0;
    
    for(int i=0;i<len1+len2; i++){
        if(coveredLen1==len1){
            if(newListHead==NULL){
                newListHead = head2;
                newListTail = head2;
            } else{
                newListTail->next = head2;
                newListTail = head2;
            }
            head2 = head2->next;
            coveredLen2++;
        } else if(coveredLen2==len2){
            if(newListHead==NULL){
                newListHead = head1;
                newListTail = head1;
            } else{
                newListTail->next = head1;
                newListTail = head1;
            }
            head1 = head1->next;
            coveredLen1++;
        } else if(stringCompare(head1->word,head2->word)){
            if(newListHead==NULL){
                newListHead = head1;
                newListTail = head1;
            } else{
                newListTail->next = head1;
                newListTail = head1;
            }
            head1 = head1->next;
            coveredLen1++;
        } else{
            if(newListHead==NULL){
                newListHead = head2;
                newListTail = head2;
            } else{
                newListTail->next = head2;
                newListTail = head2;
            }
            head2 = head2->next;
            coveredLen2++;
        }
    }
    if(len2==0)
        newListTail->next = head1;
    else newListTail->next = head2;
    if(st1==0) return newListHead;
    else{
        insertStart->next = newListHead;
        return head;
    }
    return head;
}

// function takes the wordBuckets array as an input parameter, and lexicographically orders each linked list stored in it using iterative merge sort
void mergeSortBuckets(record * wordBuckets){
    for(int i=0; i<NUMBER_OF_ALPHABETS; i++){
        if(wordBuckets[i].length<=1) continue;
        int maxSlSz, slSz, st1, last=wordBuckets[i].length-1;
        for(maxSlSz=1; wordBuckets[i].length>maxSlSz; maxSlSz*=2) ;
        /* Postcondition: maxSlSz/2 < n <= maxSlSz */
        maxSlSz /= 2;
        /* Postcondition: maxSlSz < n <= 2*maxSlSz */
        for (slSz=1; slSz<=maxSlSz; slSz*=2) {
            for (st1=0; st1<=last; st1=st1+2*slSz) {
                int st2=st1+slSz;
                int en2=st2+slSz-1;
                if (st2 > last) continue;
                if (en2 > last){
                    en2 = last;
                }
                wordBuckets[i].header.node = mergeIn(wordBuckets[i].header.node, st1, st2, en2);
            }
        }
    }
}

int main(int noOfArgs, char* args[]){
    if(noOfArgs<2){
        printf("Enter file name\n");
        exit(0);
    }

    record * wordBuckets = readData(args[1]);

    int maxGap = findmaxGap(wordBuckets);
    printf("Maximum gap is: %d\n\n",maxGap);

    printf("Printing wordBuckets array after partitioning:\n");
    partitionLists(wordBuckets);
    printData(wordBuckets);

    printf("\nPrinting wordBuckets array after lexicographical ordering:\n");
    mergeSortBuckets(wordBuckets);
    printData(wordBuckets);
    return 0;
}
