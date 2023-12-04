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
        printf("\n7.exit");       
        scanf("\n%d",&Choice);

        switch (Choice)
        {
        case 1 :
            /* code */
            void beginsert ();
            break;
        case 2 :
            /* code */
            void lastinsert ();
            break;
        case 3 :
            /* code */
            void begindelete ();
            break;
        case 4 :
            /* code */
            void lastdelete ();
            break;
        case 5 :
            /* code */
            void randominsert ();
            break;
        case 6 :
            /* code */
            void display ();
            break;
        case 7 :
            /* code */
            exit(0);
            break;
        default:
            break;
        }
    }
}
///////////////////////////////////////////////////////////////////////////
void beginsert ()
{

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

}


