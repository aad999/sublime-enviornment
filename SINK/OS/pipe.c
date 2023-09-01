#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<wait.h>
#include<errno.h>
#include<string.h>

void sort(int arr[], int begin, int end){
        for(int i = begin; i <= end; i++){
                int k = i;
                for(int j = i; j <= end; j++){
                        if(arr[j] <= arr[k])
                                k = j;
                }
                int x = arr[i];
                arr[i] = arr[k];
                arr[k] = x;
        }
        return;
}

int main(){

        int fd[2];
        pid_t pid;
        if(pipe(fd) == -1)
                exit(1);
        else
                printf("\n\n----- PIPE CREATED -----\n");
        if((pid = fork()) < 0)
                exit(1);
        else if(pid > 0){ // parent
        
                close(fd[0]);
                
                // get size
                int size = 0;
                printf("\n\n----- PARENT PROCESS (%d) -----\n\n", getpid());
                printf("size of the array : ");
                scanf("%d", &size);

                // write size
                write(fd[1], &size, sizeof(int));
                
                // get array
                int* arr = (int*)malloc(size * sizeof(int));
                printf("array : ");
                for(int i = 0; i < size; i++)
                        scanf("%d", &arr[i]);
                        
                // write array
                write(fd[1], arr, size * sizeof(int));

        }
        else { // child
        
                close(fd[1]);
                
                // read size
                int size = 0;
                read(fd[0], &size, sizeof(int));
                
                // read array
                int arr[size];
                read(fd[0], &arr, size * sizeof(arr));
                
                // sort array
                sort(arr, 0, size - 1);
                
                // print array
                printf("\n\n----- CHILD PROCESS (%d) -----\n\n", getpid());
                printf("sorted array : ");
                for(int i = 0; i < size; i++)
                        printf("%d ", arr[i]);
                printf("\n\n\n----- TERMINATED -----\n\n\n");

        }
        return 0;

}