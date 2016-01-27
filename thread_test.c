#include<stdio.h>
#include "threads.h"

int i = 0;
void ThreadFunction1() 
{
	int i1 = 0;
	while(i< 100) {
		i++;
		printf("In Thread 1:\nValue of global variable (i): %d\nValue of local variable(i1): %d\n", i, i1);
		printf("************************************************\n");		
		i1++;
		sleep(1);
		if(i>=4)
		{
			printf("Deleting Thread 1 from the queue!!\n");
			printf("************************************************\n");
			Delete();
		}	
		yield();
	}
}

void ThreadFunction2() 
{
	int i2 = 0;
	while(i< 100) {
		i++;
		printf("In Thread 2:\nValue of global variable (i): %d\nValue of local variable(i2): %d\n", i, i2);
		printf("************************************************\n");
		i2++;
		sleep(1);
		if(i>=10)
		{
			printf("Deleting Thread 2 from the queue!!\n");
			printf("************************************************\n");
			Delete();
		}
		yield();
	}
}

void ThreadFunction3() 
{
	int i3 =0;
	while(i< 100) {
		i++;
		printf("In Thread 3:\nValue of global variable (i): %d\nValue of local variable(i3): %d\n", i, i3);
		printf("************************************************\n");
		i3++;		
		sleep(1);
		if(i>=15)
		{
			printf("Deleting Thread 3 from the queue!!\n");
			printf("************************************************\n");
			Delete();
		}
		yield();
	}
}
void ThreadFunction4() 
{
	int i4=0;
	while(i< 100) {
		i++;
		printf("In Thread 4:\nValue of global variable (i): %d\nValue of local variable(i4): %d\n", i, i4);
		printf("************************************************\n");
		i4++;
		sleep(1);
		yield();
	}
}

int main() {
	start_thread(ThreadFunction1);
	start_thread(ThreadFunction2);
	start_thread(ThreadFunction3);
	start_thread(ThreadFunction4);
	run();
	return 0;
}
