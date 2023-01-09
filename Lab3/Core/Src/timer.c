#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char operation[5][50];
void main(void){
	char a[10];
	char operator[10];
	char b[10];

	int comp = 1;
	int succeed = 0;

	float ans = 0;
	float result = 0;
	
	
	int floatc = 0;
	int ansc = 0; 

	int x =0;
	int y =0;

	int count =0;
	while (comp!=0){
		printf(">> ");
		scanf("%s",&a);
		if (strcmp(a,"EXIT")==0) break;
		else {
			if (strcmp(a,"HIST")!=0){
				scanf("%s%s",&operator,&b);
				if (strcmp(a,"ANS")==0) {
					x = ans;
					y = atoi(b);
					ansc = 1;
				}
				else {
					x = atoi(a);
					y = atoi(b);
				}
				succeed = 1;
				result = 0;
				floatc = 0;

				if (strcmp(operator,"+")==0) result=x+y;
				else if (strcmp(operator,"-")==0) result = x-y;
				else if (strcmp(operator,"*")==0) result = x*y;
				else if (strcmp(operator,"/")==0) 
					if (strcmp(b,"0")==0) {
						printf("MATH ERROR\n");
						succeed = 0;
					}
					else {
						result = (float)x/y;
						floatc = 1;
					}
				else if (strcmp(operator,"%")==0) 
					if (strcmp(b,"0")==0) {
						printf("MATH ERROR\n");
						succeed = 0;
					}
					else {
						result = (int)x/y;
						floatc = 1;
					}
				else {
					printf("SYNTAX ERROR\n");
					succeed=0;
				}

				if (succeed == 1){
					char write_temp[50]="";
					char result_temp[5]="";
					
					if (floatc==0) itoa((int)result,result_temp,10);
					else gcvt(result,5,result_temp);				
					
					printf("%s\n",result_temp);

					strcat(write_temp,a);
					strcat(write_temp,operator);
					strcat(write_temp,b);
					strcat(write_temp,"=");
					strcat(write_temp,result_temp);		

					strcpy(operation[count] ,write_temp);
					count = (count+1)%5;				
						
					ans = result; 	
							
				}
			}
			else{
				for (int i=0; i<count; i++) 
					printf("%d. %s \n",i+1,operation[i]);
			}
		}
	}

}


