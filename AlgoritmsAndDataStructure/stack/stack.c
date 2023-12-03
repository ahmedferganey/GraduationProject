/**
 * @author Ahmed Ferganey
 * @email ahmedferganey707@gmail.com
 * @create date 2023-12-03 10:51:36
 * @modify date 2023-12-03 10:51:36
 * @desc [description]
 */


#include <stdio.h>
#include <stdlib.h>

#define SIZE    5
typedef unsigned int uint32;
typedef signed   int sint32;

sint32 top = -1;
uint32 stack[SIZE];

void push();
void pop();
void show();

///////////////////////////////////////////////////////////////////////////
int main()
{
    uint32 Choice = 5;

    while (1)
    {
        printf("\nPerform your operations on the stack:");
        printf("\n1.PUSH    \n2.POP    \n3.SHOW    \n4.END");
        printf("\nEnter The Choice:");
        scanf("%d", &Choice);


        switch (Choice)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                show();
                break;
            case 4:
                exit(0);
            default:
                printf("\ninvalid choice");
        }
    }
}
///////////////////////////////////////////////////////////////////////////

void push()
{
    uint32 x;

    if(SIZE-1 == top)
    {
        printf("\nOverflow!!");
    }
    else
    {
        printf("\nEnter your element");
        scanf("%d",&x);
        top+=1;
        stack[top] = x;
    }
}
void pop()
{
    sint32 x = -1;
    if (top == -1)
    {
        printf("\nStack is empty");
    }
    else
    {
        printf("\nthe poped data is: %d", stack[top]);
        top-=1;
    }
}
void show()
{
    if ( -1 == top )
    {
        printf("\nStack is empty");
    }
    else
    {
        printf("\nelements in stack are: \n");
        for(int i = top; i >= 0; --i)
        {
            printf("index num %d  is: %d \n", i, stack[i]);
        }
    }
}


