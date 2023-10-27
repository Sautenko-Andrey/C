#include<stdio.h>

#define NAME_LEN 40
#define COUNTRIES_AMOUNT 30

struct color {
    int red;
    int green;
    int blue;
};

typedef enum days {MONDAY, THUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY} Days;

struct pinball_machine {
    char name[NAME_LEN + 1];
    int year;
    enum type {EM, SS};
    int players;
};

enum {NORTH, SOUTH, EAST, WEST} direction;

struct dialing_code {
    char *country;
    int code;
};



void print_color(struct color user_color);
struct color darker(struct color user_color);
void find_country_by_phone_code(void);



int main(void)
{   
    struct color my_pixel = {255, 100, 50};
    struct color new_pix = darker(my_pixel);

    print_color(new_pix);

    int x, y;
    switch (direction)
    {
    case EAST:
        x++;
        break;

    case WEST:
        x--;
        break;

    case SOUTH:
        y++;
        break;

    case NORTH:
        y--;
        break;
    
    default:
        fprintf(stderr, "Error\n");
        break;
    }

    find_country_by_phone_code();



    return 0;
}

struct color darker(struct color user_color)
{
    user_color.red *= 0.7;
    user_color.green *= 0.7;
    user_color.blue *= 0.7;

    return user_color;
}

void print_color(struct color user_color)
{
    printf("red: %d\ngreen: %d\nblue: %d\n", user_color.red, user_color.green, user_color.blue);
}

void find_country_by_phone_code(void)
{
    const struct dialing_code country_codes[COUNTRIES_AMOUNT] = {
        {"Argentina", 54},{"Bangladesh", 880},
        {"Brazil", 55},{"Byrma", 95},
        {"China", 86},{"Colombia", 57},
        {"Congo", 243},{"Egypt", 20},
        {"Ethiopia", 251},{"France", 33},
        {"Germany", 49},{"India", 91},
        {"Indonesia", 62},{"Vietnam", 84},
        {"Italy",39},{"Japan", 81},
        {"Mexico", 52},{"Nigeria", 234},
        {"Pakistan",92},{"Philippines", 63},
        {"Poland", 48},{"South Korea", 82},
        {"South Africa", 27},{"Sudan", 249},
        {"Spain", 34},{"Turkey", 290},
        {"Thailand",66},{"United Kingdom", 44},
        {"Ukraine",380},{"United States", 1}
        
    };

    int code;

    printf("Enter an international dialing code: ");
    scanf("%d", &code);

    for(int i = 0; i < COUNTRIES_AMOUNT; ++i){
        if ( code == country_codes[i].code ){
            printf("Country: %s\n", country_codes[i].country);
            return;
        }
    }
    puts("Country code error.");
}