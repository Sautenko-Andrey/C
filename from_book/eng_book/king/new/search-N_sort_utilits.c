// Searchinf and soring utilities

// Determing mileage programm

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct city_info {
    char *city;
    int miles;
};

static int compare_cities(const void *key_ptr, const void *element_ptr);

int main(void)
{   
    char city_name[81];

    struct city_info *ptr;

    const struct city_info milage[] = {
        {"Berlin", 3965}, {"Buenos Aires", 5297},{"Cairo", 5602},{"Calcutta", 7918},
        {"Cape Town", 7764},{"Caracas", 2132},{"Chicago", 713},{"Istanbul", 4975}
    };

    printf("Enter city name: ");
    scanf("%s", city_name);

    ptr = bsearch(city_name, milage, sizeof(milage) / sizeof(*milage), sizeof(*milage),compare_cities);

    if(ptr!= NULL){
        printf("%s is %d miles from New York city\n", city_name, ptr->miles);
    }
    else{
        printf("%s was not found\n", city_name);
    }

    return 0;
}

static int compare_cities(const void *key_ptr, const void *element_ptr)
{
    return strcmp( (char *)key_ptr, ( (struct city_info *)element_ptr )->city );
}