#include<stdio.h>
#include"word.h"

int read_char(void){

    //reading symbol
    int symbol = getchar();

    //if symbol is either 'next line symbol' or 'tabulate' we would return space
    //well, here we "cut" a long spaces beetween the words.
    // if (symbol == '\n' || symbol == '\t'){
    //     return ' ';
    // }
    //return regular symbol
    // return symbol;

    //we condenced program in the folowing way
    return ( (symbol == '\n' || symbol == '\t') ? ' ' : symbol );
}

int read_word(char *word, int len)
{   
    int symbol, position = 0; //position - same as index for array

    //while from the beginning line there are spaces,
    //we skip them till find first regular symbol

    while( (symbol = read_char()) == ' ' ){
        ;
    }

    //doing one more loop. we found first non-space symbol,
    //what means proboaly it's a word.
    //we should fetch the word, so every symbol we put into word
    //till it faces space(word ends) or file is ends(EOF). 

    while( symbol != ' ' && symbol != EOF ){
        if(position < len){
            word[position++] = symbol;
        }
        symbol = read_char();
    }

    word[position] = '\0';  //adding "end of string" symbol
    return position;
}