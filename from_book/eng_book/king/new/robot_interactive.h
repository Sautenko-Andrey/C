#ifndef ROBOT_INTERACTIVE_H
#define ROBOT_INTERACTIVE_H


/*
    greetings: Greats user and prompts to select a command for the robot.
               Returns user's choice.
*/
char greetings(void);

/*
    get_array: Gets an array from user.
*/
void* get_array(char type, int len);

/*
    get_type: Gets type of the array from user.
*/
char get_type(void);


/*
    get_len: Gets length of the array from user.
*/
int get_len(void);

#endif