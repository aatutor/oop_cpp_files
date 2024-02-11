
struct Point {
    int x_;
    int y_;
    void Print('Point *this'){
        printf("(%d,%d)\n", this->x_, this->y_);
    }
};
int main() {
    Point p{6, 8};
    p.Print('&p');
}