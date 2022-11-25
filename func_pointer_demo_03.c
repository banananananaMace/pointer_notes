#include <stdio.h>
#include <string.h>

int fun1()
{
    return 1;
}

int fun2()
{
    return 2;
}

int fun3()
{
    return 3;
}

int fun4()
{
    return 4;
}

struct {
    char *name;
    int (*func)();
}symtab[] = {
    "fun1", fun1,
    "fun2", fun2,
    "fun3", fun3,
    "fun4", fun4,
};

typedef int (*func_type)();
func_type find(const char *name)
{
    for (int i = 0; i < sizeof(symtab) / sizeof(symtab[0]); i++){
        if (0 == strcmp(name, symtab[i].name)){
            return symtab[i].func;
        }
    }
    return NULL;
}

int main()
{
    func_type func = find("fun1");
    if (func){
        printf("%d\n", func());
    }
    return 0;
}
