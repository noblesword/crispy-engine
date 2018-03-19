#include<stdio.h>
#include<time.h>
#include<process.h>

void main()
{
	int pos=-1,state=1,floor,inside;
	do
	{
		
	   printf("\nEnter to which floor you wish to (-1 to 5). 6 to get out ");   //Prompting user inside the lift to enter a floor no.
	   scanf("%d",&inside);
        
		    if(inside==6)
		         exit(1);
			 if(inside==pos)
	                printf("\n You are already in same floor. Please get down!");
	        
			else if(inside>pos)
	           	     {  
						while(inside!=pos)
						   {    srand(time(NULL));
						        state=rand() % (1 + 1 - 0) + 0; //rand() % (max_number + 1 - minimum_number) + minimum_number
						        if(state==1)
	                                {
									  printf("\n Elevator is moving UP");
                                      ++pos;
                                      printf("\n Elevator is in %d",pos);
								    }
								else
								    printf("\nSomeone is waiting outside");
						            
					           	      
			                }
                     }
			else
			                          
	   

			                         
	}while(inside!=6);
}
