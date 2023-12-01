#include<stdio.h>

enum {max_name_len = 64, max_group_len = 8};

struct student {
    char name[max_name_len + 1];
    char sex; /* 'm' or 'f' */
    int year_of_birth;
    int major_code;
    int year;
    char group[max_group_len];
    float average;
};

void string_copy(const char *source, char *destination, int num);
void fill_student(struct student *ptr);
int main(void)
{
    struct student student_1, stud_2;
    struct student *ptr;
    ptr = &stud_2;

    string_copy("Ovcharenko Sergii Leonidovich", student_1.name, max_name_len);
    student_1.sex = 'm';
    student_1.year_of_birth = 1987;
    student_1.major_code = 33511;
    student_1.year = 3;
    string_copy("IP06-1", student_1.group, max_group_len);
    student_1.average = 4.7599;

    fill_student(&stud_2);
    printf("Name: %s\n", stud_2.name);
    
    printf("Name: %s\n", ptr->name);
    

    return 0;
}


void string_copy(const char *source, char *destination, int num)
{
    const char *ptr;
    int i;

    for(ptr = source, i = 0; i < num; ++ptr, ++destination, ++i){
        *destination = *ptr;
    }

    *destination = '\0';
}


void fill_student(struct student *ptr)
{
    /* Filling via pointer */
    string_copy("User", ptr->name, max_name_len);
    /* and so forth */
}
