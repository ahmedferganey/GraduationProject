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
typedef unsigned int u32;


void push();
void pop();
void show();

///////////////////////////////////////////////////////////////////////////
int main()
{
    u32 Choice = 5;

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

}
void pop()
{

}
void show()
{

}
