#include<stdio.h>
int main()
{
	int windowsize,sent=0,ack = 0,i,n,base,rec = 0;
	printf("Enter the number of packets to be sent:");
	scanf("%d",&n);
	printf("enter window size\n");
	scanf("%d",&windowsize);
	base = 0;
	while(base!=n-1)
	{
		for( i = 0; i < windowsize && sent<=n+1; i++){
			printf("Frame %d has been transmitted.\n",sent);
			sent++;
			if(sent >= n)
				break;
		}
		printf("ack = %d, sent = %d",ack,sent);
		rec = ack;
		printf("\nPlease enter the last Acknowledgement received.\n");
		scanf("%d",&ack);
		while(ack > n+1 || ack >sent || ack< rec ){
			printf("Invalid ACK : Fewer packets to be sent from source\n Enter thr correct ACK no:");			
		scanf("%d",&ack);
		}

		base = ack-1;
		
		if(ack >= n+1){
			printf("All packets have been transmitted");
			break;
		}
		if(ack == base+windowsize){
			printf("value of base: %d \n",base);
		}
		else 
			sent = ack;
	}
	printf("Your transmission is complete.");	
	return 0;
}
