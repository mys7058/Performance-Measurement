#include <time.h>
#include <stdio.h>

/*The program uses two algorithms: Binary Search & Sequential Search (Iterative & Recursive version for each).
Given a list of ordered N integers, numbered from 0 to N-1, the program looks for the N value (N is out of range).
The program measures the duration that it takes to go through the list (=the worst case performances)*/

clock_t start,stop;

double duration, total;

//***Binary Search Iterative version. (Search part)

int binarySearchIt(int list[], int init, int max, int value){
	//If the value is greater than the middle number, ignore the left half.
	//If the value is smaller than the middle number, ignore the right half
	while (init <= max)
	{int mid= init+(max-init)/2;

    if (list[mid] == value){
		return mid;}

    if (list[mid] < value){
        init =mid+1;}

    else 
        max =mid-1; 
	}
	//Reaches this point after the search is over.
	return 0; 
}

//***Main for Binary Search Iterative version

int BinarySearchIt(int N)
{
	int list[N];
	
	//set the array from 0 to N-1
	int i;
	for (i=0; i<(N-1); i++){
		list[i]=i+1;
	}
	
	//set Max value
	int n = sizeof(list)/ sizeof(list[0]);
	
	//opens the searching part of the program
	//N is the value that the program is looking for, and it would not be present in the array
	int result = binarySearchIt(list, 0, n-1, N);
   
	return 0;
}


//***Binary Search Recursive version. (Search part)

int binarySearchRec(int value, int list[], int init, int max)
{
	if (max >=init){

	//The midddle number = initial + (max-initial)/2
		int mid = init+(max-init)/2;

	//If the value is smaller than the middle number, then it should be on the left side.
		if (list[mid] > value) return binarySearchRec(value, list, init, mid-1);

	//Return the middle number if the value equals to it 
		if (list[mid] == value) return mid;

	//If the value is bigger than the middle number, then it should be on the right side
		if (list[mid] < value) return binarySearchRec(value, list, mid+1, max);
	}
	return 0;
}

//***Main for Binary Search Recursive version
int BinarySearchRec(int N){
	
	//set the array from 0 to N-1
	int list[N];

	int i;
	for (i =0; i<N-1; i++ ) {
		list[i] =i +1; /* set element at location i to i + 100 */
	}	
	//set the max number
	int max = sizeof(list)/ sizeof(list[0]);
	
	//open the searching part of the program
	int result = binarySearchRec(N, list, 0, max-1);
	
	return 0;
}


//***Sequential Search Iterative version. Searches every number from 0 to N-1.
int SequentialSearchIt(int N){
	int loc;
	
	//the array is made from 0 to N-1
	int array [N];
	int i;
	for ( i= 0; i <N-1; i++ ){
		array[i] = i + 1;
	}
	
	//goes through every number from 0 until the value is found	
	for (loc = 0; loc < N; loc++){
    		if (array[loc] == N){
			break;
    		}
	}
	
	return 0;
}

//***Sequential Search recursive version.
int sequentialSearchRec(int list[], int init, int max, int x)
{
	if (max<init){
		return 0;
	}
	//if the number is found, return 1.
	if (list[init]==x){
		return 1;
	}
	
	//repeat
	return sequentialSearchRec(list, init+1, max, x);
}

//Main part of Sequential Search Recursive version
int SequentialSearchRec(int N){	
	int list[N];
	
	//create the list 
	int i, j;
		for ( i= 0; i < N-1; i++ ) {
			list[i] = i +1;
		}	

	int max = sizeof(list)/sizeof(list[0]);

	int result = sequentialSearchRec(list, 0, max-1, N);
    return 0;
}

/*
MAIN***
*/

int main(void)
{
	/*The user decides number of iterations
	Function runs too fast and it takes less than a tick to finish
	Iteration (repeat) is done and the total run time is calculated. 
	Then divide the total time by # of iteration to calculate duration*/
	
	int iteration;
	printf("Number of iterations: ");
	scanf("%d", &iteration);
	
	int N=0;
	printf("N: ");
	scanf("%d", &N);
	
	int num, run;
	
	
	for(num=0; num<4; num++){
		//records the ticks at the beginning of the function call
		start= clock();
		run=0;
		//run the function (search)
		for(run; run<iteration; run++){
			if (num==0){
				BinarySearchIt(N);
				}
			if (num==1){
				BinarySearchRec(N);
				}
			if (num==2){
				SequentialSearchIt(N);
				}
			if (num==3){
				SequentialSearchRec(N);
				}	
			}
			
		//records the ticks at the end of the function call
		stop=clock();
		
		//# of ticks calculated
		int tick=stop-start;
		printf("Tick= %d\n", tick);
		
		//total run time is printed	
		total = ((double)(tick))/CLK_TCK;
		printf("Total time = %fs\n",total);
			
		//duration is printed
		duration = total/iteration;
		printf("Duration= %fs\n\n", duration);	
		
	}
	return 0;
}

