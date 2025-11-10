#include <stdio.h>

int isMember(int set[],int size,int element) {
	for (int i = 0;i < size; i++) {
		if (set[i] == element)
			return 1;
	}
	return 0;
}
int unionSet(int A[], int n1,int B[],int n2,int result[]){
	int k = 0;
	for (int i = 0; i < n1; i++)
		result[k++] = A[i];
	for (int i = 0; i < n2; i++)	
		if (!isMember(result, k, B[i]))
				result[k++] = B[i];
	return k;			
}
int intersectionset(int A[], int n1, int B[],int n2, int result[]){
	int k = 0;
	for (int i = 0; i < n1; i++)
		if (isMember(B, n2,A[i]))
			result[k++] = A[i];
	return k;		
}
int differenceset(int A[], int n1, int B[],int n2, int result[]){
	int k = 0;
	for (int i = 0; i < n1; i++)
		if (isMember(B, n2,A[i]))
			result[k++] = A[i];
	return k;
}
void displaySet(int set[], int size){
	printf("{");
	for (int i = 0; i < size; i++)
		printf("%d", set[i]);
	printf("}");	
}
int main(){
	int A[20], B[20], result[40];
	int n1, n2, size;
	printf("Enter number of elements in set A: ");
	scanf("%d", &n1);
	printf("Enter element of set A: ");
	for (int i = 0; i< n1; i++)
		scanf("%d", &A[i]);
	printf("Enter number of elements in set B: ");
	scanf("%d", &n2);
	printf("Enter element of set B: ");
	for (int i = 0; i< n2; i++)
		scanf("%d", &B[i]);
	size = unionSet(A, n1, B, n2, result);
	printf("\nUnion: ");
	displaySet(result, size); 
		
	size = intersectionset(A, n1, B, n2, result);
	printf("\nIntersection: ");
	displaySet(result, size);
	 
	size = differenceset(A, n1, B, n2, result);
	printf("\nDifference: ");
	displaySet(result, size); 
	return 0;
}