

#include<stdio.h>      
#include<process.h>  //For exit function
#include <time.h> //For Randomize
#include <stdlib.h>
#define rate 4.75

int r;  
float acnum;                      
float dep;
void creation();
void deposit(); 
void withdraw(); 
void bal(); 
void FD();
int i = 101; 

        void main() 
       { 
                  int ch; 
                  while(1) 
                        { 
                              
                              printf("\n BANKING "); 
                              printf("\n1-Creation"); 
                              printf("\n2-Deposit"); 
                              printf("\n3-Withdraw"); 
                              printf("\n4-Balance Enquiry"); 
                              printf("\n5-Fixed Deposit"); 
                              printf("\n6-Exit");
                              printf("\nEnter your choice (1-6)"); 
                              scanf("%d",&ch); 
                              switch(ch) 
                                       { 
                                              case 1: creation(); 
                                                         break; 
                                              case 2: deposit(); 
                                                         break; 
                                              case 3: withdraw(); 
                                                         break; 
                                              case 4: bal(); 
                                                         break; 
                                              case 5: FD();
                                                      break;
											  case 6: exit(0); 
                                              
                                                         default: printf("Enter 1-6 only"); 
                                                         getch(); 
                                        } 
                         } 
        } 
             void creation() 
        { 
                  
                   printf("\n ACCOUNT CREATION "); 
                   srand(time(NULL)); 
				   r=rand();
                   printf("\nYour Account Number is :%d",r); 
                   acnum=r;
                   printf("\nYour Deposit is Minimum Rs.500"); 
                              dep=500; 
                              getch(); 
         } 
              void deposit() 
        { 
                   int no; 
                   float aa; 
                   
                   printf("\n DEPOSIT "); 
                   
                   printf("\nEnter your Account Number"); 
                   scanf("%d",&no); 
                   if(acnum == no) 
                             { 
                                        printf("\n Account Number : %f",acnum); 
                                        dep=500;
                                        printf("\n Deposit : %f",dep); 
                                        printf("\n How Much Deposited Now:"); 
                                        scanf("%f",&aa); 
                                        dep+=aa; 
                                        printf("\nDeposit Amount is :%f",dep); 
                                        getch(); 
                             } 
                            else 
                             { 
                                       printf("\nACCOUNT NUMBER IS INVALID"); 
                                       getch(); 
                              } 
         } 
           void withdraw() 
         { 
                    int no; 
                    float aa; 
                    printf("\n WITHDRAW "); 
                     
                    printf("\nEnter your Account Number"); 
                    scanf("%d",&no); 
                     
                              if(acnum== no) 
                                 { 
                                        printf("\n Account Number : %f",acnum); 
                                      
                                        printf("\n Deposit : %f",dep); 
                                        printf("\n How Much Withdraw Now:"); 
                                        scanf("%f",&aa); 
                                        if(aa>500 && aa>dep) 
                                           { 
                                                  printf("\nCANNOT WITHDRAW YOUR ACCOUNT HAS MINIMUM BALANCE"); 
                                                  getch(); 
                                           } 
                                          else 
                                           { 
                                                  dep-=aa; 
                                                  printf("\nThe Balance Amount is:%f",dep); 
                                            } 
                                 } 
                               else 
                                { 
                                      printf("INVALID"); 
                                      getch(); 
                                } 
                                      getch(); 
          } 
                void bal() 
          { 
                  int no; 
                  float aa; 
                  printf("\n BALANCE ENQUIRY "); 
                  printf("\nEnter your Account Number"); 
                  scanf("%d",&no); 
                  
				   if(acnum==no) 
                              { 
                                    printf("\n Account Number : %f",acnum); 
                                    
                                    printf("\n Deposit : %f",dep); 
                                    getch(); 
                              } 
                             else 
                             { 
                                    printf("INVALID"); 
                                    getch(); 
                              } 
            } 
            void FD()
           { 
                   int no; 
                   float y, fd=0; 
                   
                   printf("\n FIXED DEPOSIT "); 
                   
                   printf("\nEnter your Account Number"); 
                   scanf("%d",&no); 
                   if(acnum == no) 
                             { 
                                        printf("\n Account Number : %f",acnum); 
                                        
                                        printf("\n Deposit : %f",dep); 
                                        printf("\n Enter no. of years"); 
                                        scanf("%f",&y); 
                                        fd=dep*rate*y; 
                                        printf("\nYour estimated deposit after %f years is :%f",y,fd); 
                                        getch(); 
                             } 
                            else 
                             { 
                                       printf("\nACCOUNT NUMBER IS INVALID"); 
                                       getch(); 
                              } 
         }
            
