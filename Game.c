#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void r1()
{
	srand(time(NULL));
    int r = rand() % 10 + 1;
    int correct = 0; 
    int guess; 
    int counter = 0; 
    
 
	
		system("cls");
    printf("\n\n\n\n\t----------------Round 1-------------------");
    printf("\n\nGuess the number of cookies in the jar(1-10)!!!!! "); 

    do {
        scanf("%d", &guess);
        if (guess == r) {
            counter++;
            printf("You guessed correctly in %d tries! Congratulations!\n", counter);
            getch();
            correct = 1; 
        }

        if (guess < r) {
            counter++;
            printf("Your guess is too low. Guess again. ");
        }

        if (guess > r) { 
            counter++; 
            printf("Your guess is too high. Guess again. ");
        }
    } while (correct == 0);
    
}


void r2()
{
int i;
    int response;
    int correctAnswers = 0;
    int incorrectAnswers = 0;
    
    Round2:
	system("cls");
	printf("\n\t----------------Round 2-------------------");
	      printf("\nMath Quiz\n");
    printf("Please enter # of problems you would wish to try:");
    scanf("%d", &response);

    if(response == 0)
    {
        printf("\nThanks for playing. \n\n\nGOODBYE!!!!!\n");
        return 0;
    }

    for(i=0; i<response; i++)
    {
        int answer = 0;
        int a = rand() % 12;
        int b = rand() % 12;
        printf("\n%d * %d = ",a ,b);
        scanf("%d", &answer);
        if((a * b) == answer){
            printf("\nCongratulations You are correct!\n");
            correctAnswers++;
        }
        else{
            printf("Sorry you were incorrect!\n");
            incorrectAnswers++;
        }

    }
    printf("\n\nYour Results:\n\n\n");
    printf("Number Incorrect: %d\n", incorrectAnswers);
    printf("Number Correct: %d\n", correctAnswers);
    if(correctAnswers > incorrectAnswers){
        printf("You Passed!\nGood work!\n\n");
    }
    else{
        printf("Well tried!!!\nPut in some more work!\n\n");
    }
getch();
}



int main(void) {
    
   
   int ch;
      printf("\n\n\n\n\n\t\tHello!!!!! This is a mini game.....Hope you enjoy it");
    	getch();
   r1();
   r2();
do{
    system("cls");
   printf("\nDo you wanna play Round 1 or 2 again?? \n If yes, press 1,2. To exit press 3 :\t");
   scanf("%d",&ch);
      switch(ch)
{
	case 1 : r1();
	         break;
    case 2 : r2();
	         break;
    case 3 : getch();
	         exit(1); 	         
    default : printf("\nInvalid choice");
              break;
              
}
}while(ch!=3);
   
    return 0;
}
