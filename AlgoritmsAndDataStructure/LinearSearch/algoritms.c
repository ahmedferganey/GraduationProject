#include <stdio.h>
#include <stdlib.h>


#define DATA_MAX    20
typedef unsigned int u32;


u32 Data[DATA_MAX] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19}; 
u32 SearchAlgoritm (u32 Array[], u32 DataLength, u32 ReqData);

u32 u32_data = 200; // 200 is an indication for not valid

int main()
{
    u32_data = SearchAlgoritm(Data, DATA_MAX, 13);
    printf("element is found in index: %i \n", u32_data);



    u32_data = SearchAlgoritm(Data, DATA_MAX, 25);
    printf("element is not found: %i \n", u32_data);

    return 0;
}

u32 SearchAlgoritm (u32 Array[], u32 DataLength, u32 ReqData)
{
    u32 l_index = 0;

    for (l_index; l_index < DataLength; l_index++)
    {
        if (ReqData == Array[l_index])
        {
            return l_index;
        }
    } 
        return 200;

}