#include<stdio.h>
#include<string.h>


void hi_to_user(void){
    char user_name[25];

    printf("What is ypur name?\n");

    fgets(user_name, sizeof(user_name), stdin);

    //removing \n
    for(int i = 0; i < sizeof(user_name)/sizeof(*user_name); ++i){
        if (user_name[i] == '\n'){
	    user_name[i] = '\0';
	}
    }

    printf("Hello and welcome to your upgraded Laptop, %s !\n", user_name);
}

int main(void){

    hi_to_user();

    return 0;

}
