#include"robot_commands.h"

void sort_array(void *array, char type, int len)
{   

    if(type == 's'){

        //sorting

        int min_index = 0;

        for(int i = 0; i < len - 1; ++i){
            min_index = i;

            for(int j = i + 1; j < len; ++j){
                if ( *(short*)(array + min_index) > *(short*)(array + j) ){
                    min_index = j;
                }
            }

            if(min_index != i){
                int temp = *(short*)(array + i);
                *(short*)(array + i) = *(short*)(array + min_index);
                *(short*)(array + min_index) = temp;
            }
        }

        //printing result
        for(int i = 0; i < len; ++i){
            printf("%hu ", *(short*)(array + i));
        }
        putchar('\n');

    }

    else if(type == 'i'){

        //sorting

        int min_index = 0;

        for(int i = 0; i < len - 1; ++i){
            min_index = i;

            for(int j = i + 1; j < len; ++j){
                if ( *(int*)(array + min_index) > *(int*)(array + j) ){
                    min_index = j;
                }
            }

            if(min_index != i){
                int temp = *(int*)(array + i);
                *(int*)(array + i) = *(int*)(array + min_index);
                *(int*)(array + min_index) = temp;
            }
        }

        //printing result
        for(int i = 0; i < len; ++i){
            printf("%d ", *(int*)(array + i));
        }
        putchar('\n');

    }
}