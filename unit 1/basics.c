/* data structures- scheme of organizing data in memory locations in a way that various operationc can be perfomed efficiently on data  */

//pointers!!
/* #include<stdio.h>
int main()
{
    int x = 10;
    int *y;
    printf("%d\n",x);
    printf("%d\n",&x);
    y = &x;
    printf("%d\n",y);
    printf("%d\n",*y);
    printf("%d\n",*(&x));
    printf("%d\n",&y);
    return 0;
} */

/* #include<stdio.h>
int main()
{
    int x = 66;
    int *y=&x;
    int **z=&y;
    printf("%d\n",x);
    printf("%d\n",**z);
    printf("%d\n",*z);
    printf("%d\n",*y);
    return 0;
} */

/* #include<stdio.h>
int main()
{
    int a = 89;
    double *ptr = &a;
    printf("%d\n",*ptr); //error
    return 0;
} */

/* #include<stdio.h>
int main()
{
    // const int a =10;  //const = read only cant be changed
    // a=999;
    // printf("%d\n",a); //error
    // return 0;
    //const int a;
    //int a = 10;
    //again gives error cuz assignment should be done during initialisation
    // int const a=10;  //both are similar (no difference)
    // const int a = 10;
    const int a =10;  
    const int b=13;
    const int *ptr = &a;
    printf("%d\n",a);
    printf("%d\n",*ptr);
    ptr = &b;  //both are constant and hence can be changed
    printf("%d\n",*ptr);
} */

//ARRAY!!
//array is a constant pointer and hence can be accessed by a const pointer

/* #include<stdio.h>
int main()
{
    int a []={1,2,3,4,5,6,49,32,658,243,57};
    int *p = a; //int *p = &a[0];
    for(int i=0;i<11;i++)
    {
        //printf("%d\n",p[i]); //p+i (gives address of each element after incrementing)
        //printf("%d\t",*(p+i)); //*(a+i)
        //*p++ (post inc have higher precedence than *(dereferencing operator))
        //printf("%d\t",*p++);  //*a++ cant be done
        //*++p (both pre inc and dereferencing operator have same precedence)
        //printf("%d\t",*++p); //no documentation of y it gives that output

        //~~~avoid using pre inc while using pointers in arrays
        printf("%d\t",(*p)++);  //undefined behaviour  increments the base value
    }

    return 0;
} */

#include<stdio.h>
// void check(int a[],int n)  //or *a can be written
// {
//     printf("%d\n",sizeof(a)); //gives warning...avoid sizeof operator in functions
// }
int main()
{
    int a[]={1,20,13,4,5};
    int *ptr= a;
    int s = sizeof(a)/sizeof(a[0]);
    //check(a,s);   //remember to always take up size while using functions in array (good programming practise)
    printf("%d %d %d %d\n",a,a+1,a+2,&a+1);
    return 0;
}