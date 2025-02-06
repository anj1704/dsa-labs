#ifndef LL
#define LL

typedef struct llnode* NODE;
typedef struct linked_list* LIST;

LIST createNewList();

NODE createNewNode(int value);

void insertAfter(int searchEle, NODE n1, LIST l1);

void printList(LIST l1);

void deleteAt(int searchEle, LIST l1);

void insertFirst(NODE value, LIST l1);

void deleteFirst(LIST l1);

int searchll(int searchEle, LIST l1);

void rotate(int k, LIST l1);

bool hasCycle(LIST l1);

void circularLLCycleCheck(LIST l1);

void reverse(LIST l1);

#endif
