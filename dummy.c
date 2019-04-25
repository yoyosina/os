#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int main(){
	int i,j,num,m,n,p,q,x,g,e,r,h;
	bool request_prob_counter=true;
	int resources;
	int processes;
		int counter=0;
		int out_var=0;
		int safe_count=0;
	printf("Enter Number of Procsses and Resources respectively\n");
	scanf("%d",&processes);
	scanf("%d",&resources);
		int work[resources];
		int allocation[processes][resources];
	int max[processes][resources];
	int need[processes][resources];
	/*duplicates start*/
		int work_dup[resources];
		int allocation_dup[processes][resources];
		int need_dup[processes][resources];
	
	/*duplicates end*/
	bool finish[processes];
	int seq_list[processes];
	

	printf("Enter Allocation Matrix data\n");
	for(i=0;i<processes;i++){
		for(j=0;j<resources;j++){
			scanf("%d",&allocation[i][j]);
			allocation_dup[i][j]=0;
		}
	}
		printf("Enter Max Matrix data\n");
	for(i=0;i<processes;i++){
		for(j=0;j<resources;j++){
			scanf("%d",&max[i][j]);
		}
	}
	
	for(i=0;i<processes;i++){
		for(j=0;j<resources;j++){
			need[i][j]=max[i][j]-allocation[i][j];
				
		}
	}
	printf("Need Matrix is:-\n\n");
	for(i=0;i<processes;i++){
		for(j=0;j<resources;j++){
		printf("%d    ",need[i][j]);
		}
		printf("\n");
	}
		printf("Enter Available Resources data\n");
	for(i=0;i<resources;i++){
	
			scanf("%d",&work[i]);
		
	}
	

		printf("Enter Number of Requests you want to make and make sure it should be less than or equal to number of processes else you may lead to un expected results\n");
	scanf("%d",&num);
	if(num>processes){
		printf("Wrong Input\n");
		return 0;
	}
	int request[num][resources];
	int request_process[num];
	for(i=0;i<num;i++){
			printf("Enter %dth Request is for which process. Processes start from index 0\n",i+1);
			scanf("%d",&request_process[i]);
			if(request_process[i]>processes-1){
				printf("Wrong Input\n");
				return 0;
			}
				printf("Enter %dth Request's Request data \n",i+1);
	for(j=0;j<resources;j++){
		scanf("%d",&request[i][j]);
		}
	}

for(i=0;i<num;i++){
	
		for(g=0;g<processes;g++){
		finish[g]=false;
	}
	request_prob_counter=true;
		for(j=0;j<resources;j++){
			if(request[i][j]>work[j]||request[i][j]>need[request_process[i]][j]){
				request_prob_counter=false;
				break;
			}
		}
			if(!request_prob_counter){
					printf(" request is not possible for the P%dth process\n",request_process[i]);
					printf("---------------------------------------------------------------------------------\n\n");
		
			}
			else{
				printf(" request is possible for the P%dth process\nNow checking for safe state\n",request_process[i]);
					for(e=0;e<processes;e++){
		for(r=0;r<resources;r++){
		need_dup[e][r]=need[e][r];
		allocation_dup[e][r]=allocation[e][r];
		}
		
	}
		for(n=0;n<resources;n++){
			work_dup[n]=work[n]-request[i][n];
				
			allocation_dup[request_process[i]-1][n]=allocation[request_process[i]-1][n]+request[i][n];
			need_dup[request_process[i]-1][n]=need[request_process[i]-1][n]-request[i][n];
		}
		
		
		 counter=0;
		 out_var=0;
		 safe_count=0;	
while(1){

out_var=0;
	for( q=0;q<processes;q++){
		for( p=0;p<resources;p++){
			if(finish[q]!=false||need_dup[q][p]>work_dup[p]){
				break;
			}
			else{
				if(p==resources-1){
						for( x=0;x<resources;x++){
							work_dup[x]=work_dup[x]+allocation_dup[q][x];
							}
						seq_list[counter]=q;
						counter++;
						out_var++;
						safe_count++;
						finish[q]=true;
				}
			}
		}
	}
	if(out_var==0){
		break;
	}
	}
	if(safe_count!=processes){
		printf("\n\nSystem is in unsafe state. so you cant make %dth request\n\n\n\n",i+1);
			printf("---------------------------------------------------------------------------------\n\n");
		
	}
	else{
			printf("\n\nSystem is in safe state. So %dth request granted successfully\n",i+1);
			printf("\nSafe sequence is \n");
			for( h=0;h<processes;h++){
				printf("P%d -> ",seq_list[h]);
			}
			printf("end\n");
			printf("---------------------------------------------------------------------------------\n\n");
			
		
	}
	
				
			}
		
	}
		
	
	
}

