int global_var = 100;

static int sum(int x, int y) //глобальная ф-я,которая видна только в этом модуле и нигде больше
{
    return x + y;
}

static int st_gl_x = 10000;