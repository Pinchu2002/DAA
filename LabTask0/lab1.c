#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
	int lower, upper, count;
	FILE *in_file =  fopen("input.txt","r");
	FILE *out_file = fopen("output.txt", "w");
	if(in_file  == NULL || out_file == NULL){
		printf("Error! File does not open\n");
		exit(-1);
	}
	else{
		fscanf(in_file, "%d %d %d", &lower, &upper, &count);
		srand(time(0));
		for(int i = 0; i < count; i++){
			int num = (rand()%(upper-lower + 1))+ lower;
			fprintf(out_file,"%d ",num);
		}
		fclose(in_file);
		fclose(out_file);
	}
	return 0;
}
