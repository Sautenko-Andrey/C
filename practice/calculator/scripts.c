#include<stdio.h>
#include<string.h>

void sorting_array(void)
{

    //let's fill empty array by user
    size_t size;

    printf("Let us know how many elements will be in array: ");
    scanf("%ld", &size);
    
    //our array
    int array[size];

    puts("All right, let's fill our array!");
    for (int temp, i = 0; i < size; ++i){
        printf("Enter value : ");
	scanf("%d", &temp);
	array[i] = temp;
    }
    
    puts("Construction of array is completed!");
    
    printf("Your array consist of : ");
    //let's look at our array
    for (int i = 0; i < size; ++i){
        printf("%d ", array[i]);
    }

    puts("");

    //let's begin sorting array
    int min_index;

    for (int i = 0; i < size - 1; ++i){
        min_index = i;

	for (int j = i + 1; j < size; ++j){
	    if(array[min_index] > array[j]){
	        min_index = j;
	    }
	}
	if(array[min_index]!=array[i]){
	    int temp = array[i];
	    array[i] = array[min_index];
	    array[min_index] = temp;
	}
    }

    printf("Your sorted array looks now as : ");
    //let's look at our sorted array
    for (int i = 0; i < size; ++i){
        printf("%d ", array[i]);
    }

    puts("");
}

int ask_user(void)
{
    char user_respond[4];
    printf("Would you like to sort array ? Say: ");
    fgets(user_respond, sizeof(user_respond), stdin);
    user_respond[strlen(user_respond) - 1] = '\0';
    if(strstr(user_respond, "yes") != NULL){
        return 0;
    }
    else{
        return 1;
    }
}




