#include<stdio.h>
#include<stdlib.h>
int main(){
	int count = 0;
	FILE *fp = fopen("output.txt", "r");
	if(fp == NULL){
		printf("Error! Could not open file");
		exit(-1);
	}
	else{
		int num;
		while(fscanf(fp,"%d ",&num) == 1){
			count++;
		}
		printf("%d\n", count);
		fclose(fp);
	}
	return 0;
}
