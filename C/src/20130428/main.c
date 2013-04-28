/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:
 			1.Capital to  Lower case.
 			2.
 *
 *        Version:  1.0
 *        Created:  04/28/2013 12:29:43 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  BackGarden_Straw.Neo (BackGarden_Straw), 20549304@163.com
 *   Organization:  BackGarden_Straw
 *
 * =====================================================================================
 */

#include "header.h"

int main(int argc, const char *argv[])
{

    // variables define
    int 	i,j;
	int 	temp;
    int		Compile_Switch = 1;

    // 1
#if 1
	// 0:desc  1:asc
	int array_order = 0;
    int array[] = {6,5,7,1,3,8,9,1,0,10,55,46};
	int array_length = sizeof(array)/sizeof(int);

#endif

    // 2
#if 0

#endif

    // 255
#if 0

#endif

	// init the variables
	i = 0;
	j = 0;
	temp = 0;

    // welcome and tips
    printf("****************************************************************\n");
    printf("$\t0:\thello world!\n");
    printf("$\t1:\tbubble sort the array.\n");
    printf("$\t2:\t\n");
    printf("$\t3:\t\n");
    printf("$\t4:\t\n");
    printf("****************************************************************\n");

    // choose a box
    printf("please input compile_switch:");
    scanf("%d",&Compile_Switch);


    // highlight the answer.
    printf("********************************\n");
    printf("\n\n\n");

    // do job
    switch(Compile_Switch)
    {

        ///////////////////////////////////
    case 0:
        printf("hello world!\n");
        break;

        ///////////////////////////////////
    case 1:
		// get the length of array
		printf("array size:%d\n",array_length);

		printf("array original data:");
		// output the array data.
		for	(i=0; i < array_length; i++)
		{
			printf("%d ",array[i]);
		}

		printf("\nplease choose a order for array:\n");
		printf("\t0:desc\t1:asc\n");
		scanf("%d",&array_order);

		// desc
		if(0 == array_order)
		{
	        for(i=0; i < array_length-1; i++)
	        {
				for(j=i+1; j < array_length; j++)
				{
					if(array[i] < array[j])
					{
						temp = array[i];
						array[i] = array[j];
						array[j] = temp;
					}
				}

	        }
		}

		// asc
		else if(1 == array_order)
		{
	        for(i=0; i < array_length-1; i++)
	        {
				for(j=i+1; j < array_length; j++)
				{
					if(array[i] > array[j])
					{
						temp = array[i];
						array[i] = array[j];
						array[j] = temp;
					}
				}

	        }
		}

		// wrong
		else
		{
			printf("hi boy,are u 18 years?");
			break;
		}

		printf("array current data:");
		// output the array data.
		for	(i=0; i < array_length; i++)
		{
			printf("%d ",array[i]);
		}
	
        break;

        ///////////////////////////////////
    case 2:
		printf("please waitting for me,this is in building.");
        break;

        ///////////////////////////////////
    case 3:
		printf("please waitting for me,this is in building.");
        break;

        ///////////////////////////////////
    case 4:
		printf("please waitting for me,this is in building.");
        break;

        ///////////////////////////////////
    case 5:
		printf("please waitting for me,this is in building.");
        break;

        ///////////////////////////////////
    case 6:
		printf("please waitting for me,this is in building.");
        break;


        ///////////////////////////////////
    case 255:
		
        break;
    default:
        printf("sorry something wrong.");
    }


    // highlight the answer.
    printf("\n\n\n\n");
    printf("********************************\n");

    // over
    return 0;
}
