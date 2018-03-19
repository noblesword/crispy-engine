 #include<stdio.h>
 int fact(int n)   //function definition for computing factorial of a 'n' 
{ 
 int i, fact=1; 
 for(i=2;i<=n;i++)  
        fact=fact*i;
  return fact;
 } 
int main() 
{
  int i,n;  
printf("\nHow many factorails you would like to find: ");
  scanf("%d",&n);  
for(i=1;i<=n;++i)
     printf("\n%3d! = %d",i,fact(i));  //function fact() is called 'n' times  
return 0;
} 
 

