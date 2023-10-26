#ifndef READ_LINE_H
#define READ_LINE_H

/*
    read_line(): Skips leading white-space characters,
                 then reads the remainder of the input
                 lineand stores it in str. Truncates the
                 line if it exceeds n. Returnes the number
                 of characters stored.
*/
int read_line(char str[], int n);

#endif