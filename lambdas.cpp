#include <stdio.h>

int main()
{
    int x = 1;
    int y = 2;

    /*
    a blank lambda, of type "void lambda0()"
    the [] lists "captures", which is empty
    the () is for arguments, like a normal function
    the {} is where the definition goes, like a normal function
    the return type is determined automatically by the compiler based on the code inside the lambda
    */

    auto lambda0 = [](){};

    //lambda with no captures

    auto lambda1 = [](int a, int b){
        return a + b;
    };
    
    int result1 = lambda1(x, y);
    printf("lambda1(x, y) = %d\n", result1);

    //capture by copy

    auto lambda2 = [y](int a){
        return a + y;
    };
    
    int result2 = lambda2(x);
    printf("lambda2(x) = %d\n", result2);
    
    y++;
    int result3 = lambda2(x);
    printf("lambda2(x) = %d\n", result3);

    //capture by reference

    auto lambda3 = [&y](int a){
        return a + y;
    };
    
    int result4 = lambda3(x);
    printf("lambda3(x) = %d\n", result4);
    
    y++;
    int result5 = lambda3(x);
    printf("lambda3(x) = %d\n", result5);

    /*
    other options:
    [&] captures everything in scope by reference
    [this] captures pointer to current "this" (used for lambdas inside a member function, including in a constructor)
    */

    return 0;
}
