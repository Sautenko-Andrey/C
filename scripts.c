double get_sqare(double height, double width)
{
    if(height < 0 || width < 0){
        return 0;
    }

    return height*width;
}

int get_even(int value)
{
    if(value % 2 == 0){
        return 0;
    }
    else{
        return 1;
    }
}