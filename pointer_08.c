// void *指针: 无类型指针, 可以指向任何类型的地址,也可以强转为任意类型的指针, void *指针不能进行解引用操作;不能进行+-运算;
// int a = 10;
// void *p = &a;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN        20
#define arr_size(arr)      sizeof((arr)) / sizeof((arr)[0])
struct stu {
        char name[NAME_LEN];
        int age;
};

static int cmp_int(const void *a, const void *b)
{
        return *(int *)a - *(int *)b;
}

static int cmp_float(const void *a, const void *b)
{
        return *(float *)a - *(float *)b;
}

static int cmp_str(const void *a, const void *b)
{
        return strcmp(*(char **)a, *(char **)b);
}

static int cmp_stu_by_name(const void *a, const void *b)
{
        return strcmp(((struct stu *)a)->name, ((struct stu *)b)->name);
}

static int cmp_stu_by_age(const void *a, const void *b)
{
        return ((struct stu *)a)->age - ((struct stu *)b)->age;
}

static void qsort_int(int *arr, int size, int width)
{
        printf("\n-----------%s----------\n", __func__);
        qsort(arr, size, width, cmp_int);
        for (int i = 0; i < size; i++) {
                printf("%d ", *(arr + i));
        }
        putchar('\n');
}

static void qsort_float(float *arr, int size, int width)
{
        printf("\n-----------%s----------\n", __func__);
        qsort(arr, size, width, cmp_float);
        for (int i = 0; i < size; i++) {
                printf("%0.2f", *(arr + i));
        }
        putchar('\n');
}

static void qsort_stu_by_age(struct stu *arr, int size, int width)
{
        printf("\n-----------%s----------\n", __func__);
        qsort(arr, size, width, cmp_stu_by_age);
        for (int i = 0; i < size; i++) {
                printf("%s, %d\n", (arr + i)->name, (arr + i)->age);
        }
        putchar('\n');
}

static void qsort_stu_by_name(struct stu *arr, int size, int width)
{
        printf("\n-----------%s----------\n", __func__);
        qsort(arr, size, width, cmp_stu_by_name);
        for (int i = 0; i < size; i++) {
                printf("%s, %d\n", (arr + i)->name, (arr + i)->age);
        }
        putchar('\n');
}

static void qsort_str(char *arr[], int size, int width)
{
        printf("\n-----------%s----------\n", __func__);
        qsort(arr, size, width, cmp_str);
        for (int i = 0; i < size; i++) {
                printf("%s\n", arr + i);
        }
}

static void swap(char *a, char *b, int width)
{
        for (int i = 0; i < width; i++) {
                char tmp = *a;
                *a = *b;
                *b = tmp;
                a++;
                b++;
        }
}

static void bubble_sort(void *arr,
                        int size,
                        int width,
                        int (*cmp)(const void *a, const void *b))
{
        for (int i = 0; i < size - 1; i++) {
                for (int j = 0; j < size - 1 - i; j++) {
                        // 将void *指针转为char *后, 移动width个长度后正好指向下一个元素;
                        if (cmp((char *)arr + j * width, (char *)arr + (j + 1) * width) > 0) {
                                swap((char *)arr + j * width, (char *)arr + (j + 1) * width, width);
                        }
                }
        }
}

static void bubble_sort_int(int *arr, int size, int width)
{
        printf("\n-----------%s----------\n", __func__);
        bubble_sort(arr, size, width, cmp_int);
        for (int i = 0; i < size; i++) {
                printf("%d ", *(arr + i));
        }
        putchar('\n');
}

int main(void)
{
        int int_arr[] = {100, 213, 43, 234, 495, 9, 129, 99, 2};
        float float_arr[] = {100.22, 213.11, 43.53, 234.03, 495.4, 9.11, 129.44, 99.66, 2.88};
        struct stu stu_arr[] = {
                {"zhangsan", 19},
                {"lisi", 28},
                {"wangwu", 18},
                {"wanger", 35},
        };
        char *str_arr[] = {
                "hello World",
                "goodbye World",
                "hello China",
                "goodbye China",
                "hello England",
                "goodbye England"
        };

        qsort_int(int_arr, arr_size(int_arr), sizeof(int));
        qsort_str(str_arr, arr_size(str_arr), sizeof(char *));
        qsort_float(float_arr, arr_size(float_arr), sizeof(float));
        qsort_stu_by_age(stu_arr, arr_size(stu_arr), sizeof(struct stu));
        qsort_stu_by_name(stu_arr, arr_size(stu_arr), sizeof(struct stu));

        bubble_sort_int(int_arr, arr_size(int_arr), sizeof(int));
        return 0;
}
