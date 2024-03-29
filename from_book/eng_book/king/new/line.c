#include<stdio.h>
#include<string.h>
#include"line.h"

#define MAX_LINE_LEN 60

char line[MAX_LINE_LEN + 1];
// int line_len = 0;
// int num_words = 0;

int line_len = 0, num_words = 0;

void clear_line(void)
{
    line[0] = '\0';
    line_len = 0;
    num_words = 0;
}

void add_word(const char *word)
{   
    //if additional word is not the first we should add space after last word and
    //add "end of strung" symbol. Moreover we increment line_len variable
    if(num_words > 0){
        line[line_len] = ' ';
        line[line_len + 1] = '\0';
        line_len++;
    }

    //this code concatenates a new word to the string line
    //and increase line_len variable with number of symbols in additional "word".
    //moreover we increment num_words counter.
    strcat(line, word);
    line_len += strlen(word);
    num_words++;
}

int space_remaining(void)
{   
    //we compute how many space left in current line
    return MAX_LINE_LEN - line_len;
}

void write_line(void)
{
    int extra_spaces;
    int spaces_to_insert;
    int i, j;

    extra_spaces = MAX_LINE_LEN - line_len;
    for(i = 0; i < line_len; ++i){
        if(line[i] = ' '){
            putchar(line[i]);
        }
        else{
            spaces_to_insert = extra_spaces / (num_words - 1);
            for(j = 1; j <= spaces_to_insert; j++){
                putchar(' ');
            }
            extra_spaces -= spaces_to_insert;
            num_words--;
        }
    }
    putchar('\n');
}
void flush_line(void)
{
    if(line_len > 0){
        puts(line);
    }
}