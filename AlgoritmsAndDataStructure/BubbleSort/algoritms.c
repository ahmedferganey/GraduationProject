/**
 * @author Ahmed Ferganey
 * @email ahmedferganey707@gmail.com
 * @create date 2023-11-22 03:16:37
 * @modify date 2023-11-22 03:16:37
 * @desc [description]
 */



#include <stdio.h>
#include <stdlib.h>


#define DATA_MAX_SIZE   20
typedef unsigned int uint32;
typedef signed   int sint32;



void SwapToNum (uint32 *p_NumOne, uint32 *p_NumTwo);
void PrintData(uint32 array[], uint32 ArrayLength);
void BubbleSort (uint32 Array[], uint32 ArrayLength);


uint32 Data[DATA_MAX_SIZE] = {0,5,4,9,6,7,2,1,3,8,10,18,19,15,14,17,16,11,12,13};

///////////////////////////////////////////////////////////////////////////
int main()
{  
    PrintData(Data, DATA_MAX_SIZE);
    BubbleSort(Data, DATA_MAX_SIZE);
    PrintData(Data, DATA_MAX_SIZE);

    return 0;
}
///////////////////////////////////////////////////////////////////////////

/// @brief 
/// @param p_NumOne 
/// @param p_NumTwo 
void SwapToNum (uint32 *p_NumOne, uint32 *p_NumTwo)
{
    uint32 l_TempNum = *p_NumOne;
    *p_NumOne = *p_NumTwo;
    *p_NumTwo = l_TempNum;
}


/// @brief 
/// @param array 
/// @param ArrayLength 
void PrintData(uint32 array[], uint32 ArrayLength)
{
    uint32 DataCounter = 0;

    for(DataCounter = 0; DataCounter < ArrayLength; DataCounter++)
    {
        printf("%i \t", array[DataCounter]);
    }
    printf("\n");
}

/// @brief 
/// @param Array 
/// @param ArrayLength 
void BubbleSort (uint32 Array[], uint32 ArrayLength)
{
    uint32 l_BubbleSortIteration =  0, l_CoupleIteration = 0;
    unsigned char l_Flag = 0;

    for (l_BubbleSortIteration = 0; l_BubbleSortIteration < ArrayLength-1; l_BubbleSortIteration++)
    {
        for (l_CoupleIteration = 0; l_CoupleIteration < ArrayLength-1-l_BubbleSortIteration; l_CoupleIteration++)
        {
            if (Array[l_CoupleIteration] > Array[l_CoupleIteration+1])
            {
                SwapToNum(&Array[l_CoupleIteration], &Array[l_CoupleIteration+1]);
                l_Flag = 1;
            }
            PrintData(Array, ArrayLength);
        }
        if (0 == l_Flag)
        {
            return ;
        }
    }
}

