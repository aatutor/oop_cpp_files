#include <iostream>
#include <string>
using namespace std;

const int LEN_ROOF = 250;

struct Room {
    string name_;
    int width_;
    int height_;
    bool roof_;
}
struct Wallpaper {
    string name_;
    int width_;
    int length_;
    int price_;
    
    int CountForRoom(Room r){
        int s = (r.width_ + r.height_)* 2 * LEN_ROOF;
        if (r.roof_)
            s += r.width_ * r.height_;
            
        int sw = this->width_ * this->length_;
        double count = 1.0*s / sw;
        return (int)count + 1;
    }
}

int main()
{
    Room kidsRoom{ "Kids room", 300, 500, false};
    
    Wallpaper wpCars{ "Cars", 52, 1000, 500 };
    
    wpCars.CountForRoom(kidsRoom);

	return 0;
}