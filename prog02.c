#include <stdio.h>
#include <stdlib.h>
//Code that is a lot better than the previous, with different logic
//No longer does it take half a minute to perform 500!, it actually performs 10000! in a couple of seconds

void printArray(int *array){
	int i;
	for (i = 40000;i>0;i--)
		if (array[i]!=0)
			break;
	for (;i>=0;i--)//Fun fact : this used to be for(i;i>=0;i--) but run.codes bitched about it and CLion considers it an unused integer
		printf("%d",array[i]);
	printf("\n");
}

void resetArray(int *array){
	for(int i = 0;i<40000;i++)
		array[i] = 0;
}

void fac(int *resultVector,int num){//Function that does the operation proper
	resultVector[0] = 1;
	int j,i;
	for (j = 1;j<=num;j++){
		for (i = 0;i<39999;i++){
			resultVector[i]=resultVector[i]*j;
		}
		for(i = 0;i<39999;i++)
			if(resultVector[i]>9){
				resultVector[i+1]=resultVector[i+1]+(resultVector[i]/10);
				resultVector[i]=resultVector[i]%10;
			}
	}
	printf("Resultado: ");
	printArray(resultVector);
}

int main(){
	int num;
	int *resultVector;
	resultVector = (int *) malloc(40000 * sizeof(int));//Vector is 40000 positions long since the largest number this program will support is 10!, which should have around 36000 positions. Otherwise, realloc() should be used
	if(resultVector==NULL){
		printf("Memory allocation failure!\n");//In case your PC can't allocate the memory, in which case the program will terminate itself
		return 0;
	}
	resetArray(resultVector);
	printf("Digite um numero inteiro: ");
	scanf("%d",&num);
	fac (resultVector,num);
}