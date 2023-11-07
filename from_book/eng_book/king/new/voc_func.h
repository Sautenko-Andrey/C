#ifndef VOC_FUNC_H
#define VOC_FUNC_H

#define MAX 20

struct word {
    char eng[MAX + 1];
    char ukr[MAX + 1];
    struct word *next;
};

void add_word(struct word **vocabulary);
void show_vocabulary(struct word *vocabulary);


#endif