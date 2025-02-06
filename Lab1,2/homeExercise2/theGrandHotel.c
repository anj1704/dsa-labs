#define MAX 100
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct details{
    char* name;
    int age;
    char* address;

};

typedef struct details details;

struct hotel 
{
    char* nameOfHotel;
    char* address;
    int noOfRooms;
    details* occupants;

};

typedef struct hotel hotel;

void assignRoom(hotel* h){

    details d;
    d.name = (char *) malloc(sizeof(char)*MAX);
    d.address = (char *) malloc(sizeof(char)*MAX);
    printf("Enter occupant name.");
    scanf("%s", d.name);
    printf("Enter you age.");
    scanf("%d", &d.age);
    printf("Enter your address.");
    scanf("%s", d.address);
    h->noOfRooms++;
    h->occupants = realloc(h->occupants, (h->noOfRooms + 1)*sizeof(details));
    h->occupants[h->noOfRooms-1] = d;

}
void assignRoomZero(hotel* h){

    assignRoom(h);
    for (int i = h->noOfRooms - 1; i > 0 ; i--){

        details temp;
        temp = h->occupants[i];
        h->occupants[i] = h->occupants[i-1];
        h->occupants[i-1] = temp;

    }

}
void emptyRoom(hotel* h){

    int n;
    printf("Enter room number to empty.");
    scanf("%d",&n);
    
    if (h->noOfRooms <= n || n < 0){

        printf("Room not occupied.\n");
        return;

    }
    for (int i = n; i < h->noOfRooms - 1 ; i++){

        details temp;
        temp = h->occupants[i];
        h->occupants[i] = h->occupants[i+1];
        h->occupants[i+1] = temp;

    }

    h->noOfRooms--;

}
void displayInfo(hotel* h){

    int n;
    printf("Enter room number to display occupant info.");
    scanf("%d",&n);
    
    if (h->noOfRooms <= n || n < 0){

        printf("Room not occupied.\n");
        return;

    }

    printf("Occupant Name: %s\n", h->occupants[n].name);
    printf("Occupant Age: %d\n", h->occupants[n].age);
    printf("Occupant Address: %s\n", h->occupants[n].address);

}

void displayAll(hotel* h){

    for (int i = 0; i < h->noOfRooms; i++){

        printf("Occupant Name: %s\n", h->occupants[i].name);
        printf("Occupant Age: %d\n", h->occupants[i].age);
        printf("Occupant Address: %s\n", h->occupants[i].address);

    }
}

int main(){

    hotel* hilbert = (hotel *) malloc(sizeof(hotel));
    hilbert->address = (char *) malloc(sizeof(char)*MAX);
    hilbert->nameOfHotel = (char *) malloc(sizeof(char)*MAX);

    hilbert->nameOfHotel = "Hilbert";
    hilbert->address = "Earth";
    hilbert->noOfRooms = 0;
    hilbert->occupants = (details *) malloc(sizeof(details));

    if (hilbert == NULL || hilbert->occupants == NULL){

        printf("Unable to allocate memory\n");
        return -1;

    }

    int flag = -1;

    while(flag != 0){

        printf("\nWhat would you like to do ?\n");
        printf("1. Assign available room.\n");
        printf("2. Assign room 0.\n");
        printf("3. Empty a room.\n");
        printf("4. Display details of an occupant.\n");
        printf("5. Display details of all occupants.\n");
        printf("0. Exit.\n");

        printf("Enter your input.\n");
        scanf(" %d", &flag);

        switch(flag){

            case 1:
                assignRoom(hilbert);
                break;
            case 2:
                assignRoomZero(hilbert);
                break;
            case 3:
                emptyRoom(hilbert);
                break;
            case 4:
                displayInfo(hilbert);
                break;
            case 5:
                displayAll(hilbert);
                break;
            case 0:
                break;
            default:
                printf("Invalid input !\n");
                break;

        }

    }

    return 0;

}
