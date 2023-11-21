/**
 * @author Ahmed Ferganey
 * @email ahmedferganey707@gmail.com
 * @create date 2023-11-21 06:14:02
 * @modify date 2023-11-21 06:14:02
 * @desc [description]
 */



#include <stdio.h>
#include <stdlib.h>


#define DATA_MAX_SIZE   20
typedef unsigned int uint32;
typedef signed   int sint32;


sint32 Data[DATA_MAX_SIZE] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
sint32 BinarySearch (sint32 Array[], uint32 ReqVal, uint32 StartIndex, uint32 EndIndex);
sint32 BinarySearchEnhanced (sint32 Array[], uint32 ReqVal, uint32 StartIndex, uint32 EndIndex);
sint32 Return = -1;

///////////////////////////////////////////////////////////////////////////
int main()
{  
    Return = BinarySearch(Data, 0, 0, DATA_MAX_SIZE-1);
    printf("index : %i \n", Return);

    Return = BinarySearch(Data, 20, 0, DATA_MAX_SIZE-1);
    printf("index : %i \n", Return);

    Return = BinarySearch(Data, -5, 0, DATA_MAX_SIZE-1);
    printf("index : %i \n", Return);


    return 0;
}
///////////////////////////////////////////////////////////////////////////



sint32 BinarySearch (sint32 Array[], uint32 ReqVal, uint32 StartIndex, uint32 EndIndex)
{
    uint32 MiddleIndex =0;

    while (EndIndex >= StartIndex)
    {
        MiddleIndex = StartIndex + ((EndIndex - StartIndex) / 2);
        if (ReqVal == Array[MiddleIndex])
        {
            return MiddleIndex;
        }
        else if (ReqVal >= Array[MiddleIndex])
        {
            StartIndex = MiddleIndex + 1;
        }
        else
        {
            EndIndex = MiddleIndex - 1;
        }
    }
    return -1;

}

sint32 BinarySearchEnhanced (sint32 Array[], uint32 ReqVal, uint32 StartIndex, uint32 EndIndex)
{

}