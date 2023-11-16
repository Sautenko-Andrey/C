// <string.h>

#include<string.h>
#include<stdio.h>


int main(void)
{   
    //Copying functions

    char source[] = {'h','o','t','\0','t','e','a'};
    char dest[7];
    char dest2[7];

    memcpy(dest, source,3);    // [hot    ]
    puts(dest);
    memcpy(dest, source,4);    // [hot\0  ]
    puts(dest);
    memmove(dest2, source,7);
    puts(dest2);
    strncpy(dest2, source, 7);
    puts(dest2);


    // Comparsion functions
    int nums1[5] = {1,3,5,7,9};
    int nums2[5] = {1,3,5,7,9};
    double val1[] = {0.1, 0.2, 0.3, 0.4, 0.5};
    double val2[] = {0.1, 0.2, 0.3, 0.4, 0.5};

    if(memcmp(nums1, nums2, sizeof(nums1) / sizeof(*nums1)) == 0){
        puts("Arrays are equal");
    }

    if(memcmp(val1, val2, 5) == 0){
        puts("Arrays are equal");
    }


    // Search functions
    char *ptr_res;
    char text[] = "What is your destinition ?!";

    if((ptr_res = strchr(text, 'a')) != NULL){
        printf("ptr_res = %c\n", *ptr_res);  //ptr_res = a
    }

    char *ptr_cres;
    char arr[5] = "abcde";

    if((ptr_cres = memchr(arr, 'a', 5)) != NULL){
        puts("We encountered the letter in the string.\n");
    }
    

    char *text2 = "Apart from that we foud Zippy.";
    if(strrchr(text2, 'Z') != NULL){                         // reverse searching
        puts("We found a letter.");
    }

    char *text3 = "Pure C is awesome!";
    if(strpbrk(text3, "xy") != NULL){
        puts("Ecnountered x or y in the string.");
    }

    size_t index;

    char *text4 = "Please, get lost!";
    index = strspn(text4, "elP");   // индекс первого несовпадающего символа
    printf("Index = %lu\n", index);   //3

    char *let;

    if((let = strstr("Kelly used to brings a paper from the office.", "brings")) != NULL){
        puts("<brings> is located!");
        printf("let = %c\n", *let);  //b
    }


    int points[] = {1,2,3,4,5};
    memset(points, 0, sizeof(points));   // 0 0 0 0 0 
    for(int i = 0; i < 5; ++i){
        printf("%d ", points[i]);
    }
    putchar('\n');
    
    


    return 0;
}