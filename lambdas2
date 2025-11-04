#include <cstdio>
#include <functional>

int g(const std::function<int(int)>& f) {
    for(int i = 0; i < 3; i++) {
        printf("  g(%d) = %d\n", i, f(i));
    }
    return 0;
}

struct MyClass {
    int y = 1;

    void myf() {

        printf(" y = %d\n", y);
        auto lambda = [this](int a){
            return a + y;
        };

        g(lambda);
    }
};

int main() {


    printf("local lambda stuff\n");

    int x = 1;

    auto lambda = [&x](int a){
        return a + x;
    };

    printf(" x = %d\n", x);
    g(lambda);

    x++;
    printf(" x = %d\n", x);
    g(lambda);

    printf("MyClass stuff\n");
    
    MyClass c;
    c.myf();
    c.y = 2;
    c.myf();

    return 0;
}
