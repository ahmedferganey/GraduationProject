/**
 * @author Ahmed Ferganey
 * @email ahmedferganey707@gmail.com
 * @create date 2023-12-04 12:41:28
 * @modify date 2023-12-04 12:41:28
 * @desc [description]
 */


#include <stdio.h>
#include <stdlib.h>


typedef unsigned int uint32;
typedef signed   int sint32;
struct node
{
    /* data */
    uint32 data;
    struct node *next; 
};
struct node *head; 

void beginsert ();
void lastinsert ();
void begindelete ();
void lastdelete ();
void randominsert ();
void display ();



///////////////////////////////////////////////////////////////////////////
int main()
{
    uint32 Choice = 8;

    while(1)
    {
        printf("\n              enter your choice              ");
        printf("\n1.beginsert");
        printf("\n2.lastinsert");
        printf("\n3.begindelete");
        printf("\n4.lastdelete");
        printf("\n5.randominsert");
        printf("\n6.display");
        printf("\n7.exit\n");       
        scanf("\n%d",&Choice);

        switch (Choice)
        {
        case 1 :
            /* code */
            beginsert ();
            break;
        case 2 :
            /* code */
            lastinsert ();
            break;
        case 3 :
            /* code */
            begindelete ();
            break;
        case 4 :
            /* code */
            lastdelete ();
            break;
        case 5 :
            /* code */
            randominsert ();
            break;
        case 6 :
            /* code */
            display ();
            break;
        case 7 :
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
void beginsert ()
{
    struct node *ptr;
    uint32 item;
    ptr = (struct node*) malloc(sizeof(struct node*));

    if (ptr == NULL)
    {
        printf("\nOverflow!!");
    }
    else
    {
        printf("\nEnter Your data");
        scanf("%d", &item);
        ptr->data = item;
        ptr->next = head;

        head = ptr;
        printf("\nNode inserted");
    }
    
}
void lastinsert ()
{

}
void begindelete ()
{

}
void lastdelete ()
{

}
void randominsert ()
{

}
void display ()
{
    struct node *ptr;
    ptr = head;

    if (ptr == NULL)
        printf("\nNothing to print");
    else
    {
        printf("\nValues are: \n");
        while (ptr != NULL)
        {
            printf("%d", ptr->data);
            ptr = ptr->next;
        }
    }
}


