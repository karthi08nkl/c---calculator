#include <stdio.h>
#include <stdlib.h>

int main(){
    int choice = 0;
    int result = 0;

    printf("CALCULATOR\n\n");

    printf("How many numbers do you want to enter? ");
    scanf("%d", &choice);

    if (choice <= 0) {
        printf("Invalid number count.\n");
        return 0;
    }


    int *total = malloc(choice * sizeof(int));

    if (total == NULL) {
        printf("Memory allocation failed.\n");
        return 0;
    }

    for(int i =0;i<choice;i++){
        printf("Enter number %d : ",i+1);
        scanf("%d",&total[i]);
    }

    int operator = 0;
    printf("Choose the operator to perform :\n");
    printf("1. Addition (+)\n");
    printf("2. Subtraction (-)\n");
    printf("3. Multiplication (*)\n");
    printf("4. Divison (/)\n");
    printf("Choose (1/2/3/4) : ");
    scanf("%d",&operator);

    switch(operator){
        case 1:
           result = 0;
           for(int i =0; i<choice ; i++){
               result += total[i];
            }
            printf("Result = %d\n",result);
            break;
        
        case 2:
           result = total[0];
           for(int i =1; i<choice ; i++){
               result -= total[i];
            }
            printf("Result = %d\n",result);
            break;    

        case 3:
           result = 1;
           for(int i =0; i<choice ; i++){
               result *= total[i];
            }
            printf("Result = %d\n",result);
            break;
            
        case 4:
           result = total[0];
           for(int i =1; i<choice ; i++){
               if(total[i] == 0){
                printf("Cannot be divided with 0");
                return 0;
               }
               result /= total[i];
            }
            printf("Result = %d\n",result);
            break;  
            
        default:
            printf("Inavlid Operator choosen");    

    }
    
    free(total);
    return 0;
}

