#include<stdio.h>
#include"dstqueue.h"
int main()
{
    char ch;
    Q pq;
    int choice1, choice2, value;
    printf("\n******* Type of Double Ended Queue *******\n");
    create(&pq);
     do
     {
          printf("\n1.Input-restricted deque \n");
          printf("2.output-restricted deque \n");
          printf("\nEnter your choice of Queue Type : ");
          scanf("%d",&choice1);
          switch(choice1)
          {
               case 1: 
                    printf("\nSelect the Operation\n");
                    printf("1.Insert\n2.Delete from Rear\n3.Delete from Front\n4. Display");
                    do
                    {
                      printf("\nEnter your choice for the operation in c deque: ");
                       scanf("%d",&choice2);
                       switch(choice2)
                       {   
                          case 1: enQueueRear(&pq,value);
                                  display(&pq);
                       		  break;
                       	  case 2: value = deQueueRear(&pq);
                       		  printf("\nThe value deleted is %d",value);
                                  display(&pq);
                       		  break;
                          case 3: value=deQueueFront(&pq);
                       	          printf("\nThe value deleted is %d",value);
                                  display(&pq);
                       	          break;
                          case 4: display(&pq);
                                  break;
                          default:printf("Wrong choice");
                       }
                       printf("\nDo you want to perform another operation (Y/N): ");
                       ch=getchar();
                    }while(ch=='y'||ch=='Y');
                    break; 
     
               case 2 :
                   printf("\n---- Select the Operation ----\n");
                   printf("1. Insert at Rear\n2. Insert at Front\n3. Delete\n4. Display");
                   do
                   {
                      printf("\nEnter your choice for the operation: ");
                      scanf("%d",&choice2);
                      switch(choice2)
                      {   
                         case 1: enQueueRear(&pq,value);
                                 display(&pq);
                                 break;
                         case 2: enQueueFront(&pq,value);
                                 display(&pq);
                                 break;
                         case 3: value = deQueueFront(&pq);
                                 printf("\nThe value deleted is %d",value); 
                                 display(&pq);
                                 break;
                         case 4: display(&pq);
                                 break;
                         default:printf("Wrong choice");
                       }
                       printf("\nDo you want to perform another operation (Y/N): ");
			ch=getchar();
                    } while(ch=='y'||ch=='Y');
                    //getch();
                    break ;
            }
            printf("\nDo you want to continue(y/n):");
            ch=getchar();
      }while(ch=='y'||ch=='Y');
}
/*
void enQueue(int);
int deQueueFront();
int deQueueRear();
void enQueueRear(int);
void enQueueFront(int);
void display();

*/
