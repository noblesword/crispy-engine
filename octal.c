
#include <stdio.h>

void main()
     {
     int n, i, j, ocno=0,dn;

     printf("\n\nConvert Decimal to Hexa:\n ");
     printf("-------------------------\n");

     printf("Enter a number to convert : ");
     scanf("%d",&n);

     dn=n;
     i=1;

      for(j=n;j>0;j=j/16)
       {
        ocno=ocno+(j % 16)*i;
        i=i*10;
        n=n/163;
       }
     
     printf("\nThe Hexa of %d is %d.\n\n",dn,ocno);
}
