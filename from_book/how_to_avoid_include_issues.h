//КАК ИЗБЕЖАТЬ МНОГОКРАТНОГО ВКЛЮЧЕНИЯ ЗАГОЛОВОЧНЫХ ФАЙЛОВ
//ВКЛЮЧАТЬ ТАКУЮ ЛОГИКУ ВО ВСЕ ЗАГОЛОВОЧНЫЕ ФАЙЛЫ!!!


#if defined(how_to_avoid_include_issues)
/*do nothing and skip to the end*/
#else
#define how_to_avoid_include_issues
//further we declare all funcs for this head file
//funcs
/*
...
...
...
...
...
*/
#endif