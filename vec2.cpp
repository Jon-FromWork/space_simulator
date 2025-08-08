#include "vec2.h"


vec2::vec2():x(0),y(0){}
vec2::vec2(float _x,float _y):x(_x),y(_y){}
vec2::~vec2(){}


vec2 vec2::operator+(const vec2 &other){
    return vec2(x+other.x, y+other.y);
}
vec2 vec2::operator-(const vec2 &other)const{
    return vec2(x-other.x, y-other.y);
}
vec2 vec2::operator*(float multiplier){
    return vec2(x*multiplier, y*multiplier);
}
vec2 vec2::operator/(float divider){
    return vec2(x/divider,y/divider);
}
vec2 &vec2::operator+=(const vec2 &other){
    x+=other.x;
    y+=other.y;
    return *this;
}
vec2 &vec2::operator-=(const vec2 &other){
    x-=other.x;
    y-=other.y;
    return *this;
}
float vec2::length() const{
    return std::sqrt(x*x+y*y);
}
vec2 vec2::normalize(){
    float vec_length=length();
    if(vec_length>0)
        return (*this/vec_length);
    return *this;
}
float vec2::dot(const vec2 &other) const {
    return (x*other.x+y*other.y);
}
vec2 vec2::perpendicular() const {
    return vec2(-y,x);
}
bool vec2::operator==(const vec2 &other)const{
    if(x==other.x && y==other.y)
        return true;
    return false;
}
bool vec2::operator!=(const vec2 &other)const{
    if (*this==other)
        return false;
    return true;
}
void vec2::print() const {
    std::cout << "[" << x << ", " << y << "]";
}