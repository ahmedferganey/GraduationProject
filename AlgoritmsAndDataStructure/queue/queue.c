/**
 * @author Ahmed Ferganey
 * @email ahmedferganey707@gmail.com
 * @create date 2023-12-04 11:26:36
 * @modify date 2023-12-04 11:26:36
 * @desc [description]
 */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 4

typedef unsigned int uint32;
typedef signed   int sint32;

void enqueue();
void dequeue();
void show();

uint32 Array[SIZE];
sint32 Front = -1;
sint32 Rear  = -1;

///////////////////////////////////////////////////////////////////////////
int main()
{
    uint32 Choice = 5;
    while(1)
    {
        printf("\n1.enqueue");
        printf("\n2.dequeue");
        printf("\n3.show");
        printf("\n4.exit");
        printf("\nenter your choice");
        scanf("\n%d",&Choice);

        switch (Choice)
        {
        case 1 :
            /* code */
            enqueue();
            break;
         case 2 :
            /* code */
            dequeue();
            break;
        case 3 :
            /* code */
            show();
            break;
        case 4 :
            /* code */
            exit(0);
            break;
        default:
            printf("\ninvalid choice");
            break;
        }
    }
}
///////////////////////////////////////////////////////////////////////////
void enqueue()
{
    uint32 InsertedItem;

    if (Rear == SIZE - 1)
    {
        printf("\n overflow!!");
    }
    else
    {
        if (Front == -1)
        Front = 0;

        printf("\n please enter your data in the queue \n");
        scanf("%d", &InsertedItem);
        Rear += 1;
        Array[Rear] = InsertedItem;
    }
}
void dequeue()
{
    if (Front == -1 || Front > Rear)
    {
        printf("\n underflow!!");
        return;
    }
    else
    {
        printf("\nelement deleted from the queue is: %d", Array[Front]);
        Front += 1;
    }
}
void show()
{

}
