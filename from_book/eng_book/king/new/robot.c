#include"robot_commands.h"
#include"robot_interactive.h"


#define SORT_ARRAY '0'
#define FIND_MAX '1'
#define FIND_MIN '2'


int main(void)
{   
    char user_choice = greetings();

    switch (user_choice)
    {
    case SORT_ARRAY:
        char type = get_type();
        int len = get_len();
        sort_array(get_array(type, len), type, len);
        break;

    case FIND_MAX:
        find_max(get_array(type, len), type, len);

    case FIND_MIN:
        find_min(get_array(type, len), type, len);
    
    default:
        break;
    }



    return 0;
}