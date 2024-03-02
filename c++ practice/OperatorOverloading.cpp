// Boiler plate for c++ competative
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int val)
  {
    val = val;
    next = NULL;
  }
};

struct Vector2{
    float x, y;

    Vector2(float x, float y) :x(x),y(y) {}

    Vector2 Add(const Vector2 & other) const
    {
        return Vector2(x + other.x,y + other.y);
    }

    Vector2 Multi(const Vector2 & other) const
    {
        return Vector2(x * other.x,y * other.y);
    }

    Vector2 operator+(const Vector2 & other) const{
        return Add(other);
    }

      Vector2 operator*(const Vector2 & other) const{
        return Multi(other);
    }
    bool operator==(const Vector2& other)const{
        return x == other.x && y == other.y;
    }

    bool operator!=(const Vector2& other) const{
        return !(*this == other);
        //or
        //return !operator==(other);
    }
};

//overloading print of std
std::ostream& operator<<(std::ostream& stream,const Vector2& vector) {
    stream << vector.x << ", " << vector.y;
    return stream;
}


int main()
{
    Vector2 position(2.2f,1.5f);
    Vector2 speed (1.1f,3.4f);

    Vector2 boost (2.5f,4.2f);

    //too much code
    Vector2 result = position.Add(speed.Multi(boost));

    //this can be written after operator overloading
    Vector2 result2 = position + speed * boost;

    //we cant do that as compiler dont know that to print so we will overload it
    cout << result2 << endl;
    
}