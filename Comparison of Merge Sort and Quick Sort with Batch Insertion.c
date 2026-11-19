#include <stdio.h>
#include <stdlib.h>
#define MAX 100000

long long mergeCount = 0;
long long quickCount = 0;

void merge(int arr[] , int left , int mid , int right){

    int n1 = mid - left + 1;
    int n2 = right - mid;

    int i, j, k;

    int *a = malloc(n1 * sizeof(int));
    int *b = malloc(n2 * sizeof(int));

    for(i=0 ; i < n1 ; i++){
        a[i] = arr[left + i];
    }

    for(j=0 ; j < n2 ; j++){
        b[j] = arr[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;

    while(i < n1 && j < n2){
        mergeCount++;

        if(a[i] <= b[j]){
            arr[k] = a[i];
            i++;
        }
        else{
            arr[k] = b[j];
            j++;
        }

        k++;
    }

    while(i < n1){
        arr[k] = a[i];
        i++;
        k++;
    }

    while(j < n2){
        arr[k] = b[j];
        j++;
        k++;
    }

    free(a);
    free(b);
}
void mergeSort(int arr[] , int left , int right){
    if(left < right){
        int mid = (left + right) / 2;

        mergeSort(arr , left , mid);
        mergeSort(arr , mid + 1 , right);

        merge(arr , left , mid , right);
    }
}
int partition(int arr[] , int low , int high){
    int pivot = arr[high];
    int i = low - 1;
    int temp;

    for(int j=low ; j < high ; j++){
        quickCount++;

        if(arr[j] <= pivot){
            i++;

            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}
void quickSort(int arr[] , int low , int high){

    if(low < high){
        int p = partition(arr , low , high);

        quickSort(arr , low , p - 1);
        quickSort(arr , p + 1 , high);
    }
}
void printArray(char name[] , int arr[] , int n){

    printf("%s:" , name);

    for(int i=0 ; i < n ; i++){
        printf(" %d" , arr[i]);
    }

    printf("\n");
}



int main()
{
    FILE *file = fopen("input.txt" , "r");

    if(file == NULL){
        printf("File not found!\n");
        return 1;
    }

    int n, m;

    if(fscanf(file, "%d %d" , &n , &m) != 2 ||
       n < 1 || n > MAX || m < 0 || m > MAX){
        printf("Invalid input!\n");
        fclose(file);
        return 1;
    }

    int *original = malloc(n * sizeof(int));
    int *mergeArr = malloc(n * sizeof(int));
    int *quickArr = malloc(n * sizeof(int));
    int *batch = malloc((m > 0 ? m : 1) * sizeof(int));
    int *updated = malloc((n + m) * sizeof(int));

    if(original == NULL || mergeArr == NULL ||
       quickArr == NULL || batch == NULL || updated == NULL){

        printf("Memory allocation failed!\n");

        fclose(file);

        free(original);
        free(mergeArr);
        free(quickArr);
        free(batch);
        free(updated);

        return 1;
    }

    for(int i=0 ; i < n ; i++){
        if(fscanf(file, "%d" , &original[i]) != 1){
            printf("Invalid record input!\n");
            fclose(file);
            return 1;
        }

        mergeArr[i] = original[i];
        quickArr[i] = original[i];
    }

    for(int i=0 ; i < m ; i++){
        if(fscanf(file, "%d" , &batch[i]) != 1){
            printf("Invalid batch input!\n");
            fclose(file);
            return 1;
        }
    }

    fclose(file);

    mergeSort(mergeArr , 0 , n-1);
    quickSort(quickArr , 0 , n-1);

    printArray("Merge Sort" , mergeArr , n);
    printArray("Quick Sort" , quickArr , n);

    printf("Merge Comparisons: %lld\n" , mergeCount);
    printf("Quick Comparisons: %lld\n" , quickCount);

    int a=0, b=0, k=0;

    while(a < n && b < m){
        if(mergeArr[a] <= batch[b]){
            updated[k] = mergeArr[a];
            a++;
        }
        else{
            updated[k] = batch[b];
            b++;
        }

        k++;
    }

    while(a < n){
        updated[k] = mergeArr[a];
        a++;
        k++;
    }

    while(b < m){
        updated[k] = batch[b];
        b++;
        k++;
    }

    printArray("Updated Array" , updated , n+m);

    free(original);
    free(mergeArr);
    free(quickArr);
    free(batch);
    free(updated);

    return 0;
}
