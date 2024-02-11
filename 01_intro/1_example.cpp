
#include <stdio.h>
using namespace std;


// struct style
{
    struct Point {
        int x_;
        int y_;
    };
    void Print(Point p) {
        printf("(%d,%d)\n", p.x_, p.y_);
    }
    
    int main()
    {
        Point pointS{3, 4};
        Print(pointS);
    }
}

// class style 
{
    struct Point {
        int x_;
        int y_;
        void Print(){
            printf("(%d,%d)\n", x_, y_);
        }
    };
    int main() {
        Point pointC{6, 8};
        pointC.Print();
    }
}

