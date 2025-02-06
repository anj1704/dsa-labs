#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "binarySearchTree.h"

int main(){
    FILE *fp;
    fp =fopen("n_integers.txt","r");
    char line = (char )malloc(200 *sizeof(char));

    int ROWS=0;
    int *arr = (int *)malloc (sizeof(int*)* 1000);
    for(int i=0;i<1000;i++){
        arr[i] = (int *) calloc (1000,sizeof(int));
    }

    // for(int i=0;i<1000;i++){
    //     for(int j=0;j<1000 ;j++){
    //         printf("%d ",arr[i][j]);
    //     }
    // }

    while( fgets(line, 200 , fp)!= NULL){
        char *str = strtok(line, "[");
        int size = atoi(str);
        int i=0;

        str = strtok(NULL, " ");
        while(i<size){
            arr[ROWS][i]= atoi(str);
            i++;
            if(i== size) break;
            str = strtok(NULL, " ");
            if(str == NULL){
                fgets(line, 200 , fp);
                str = strtok(line," ");
            }
        }
        fgets(line, 200 , fp);
        ROWS++;
    }
    
    for(int i=0;i< ROWS;i++){
        printf("ROW NO: %d\n",i);
        for(int j=0;j<1000;j++){
            if(arr[i][j] == 0){
                break;
            }
            printf("%d ", arr[i][j]);
        }
        printf("\n\n");
    }
}
