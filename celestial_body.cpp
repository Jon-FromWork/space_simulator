#include "celestial_body.h"

celestial_body::celestial_body():position(vec2()),velocity(vec2()),mass(1),radius(1){}
celestial_body::celestial_body(std::string name,vec2 pos,vec2 vel, float ma, float r,Color color): name(name),position(pos),velocity(vel),mass(ma),radius(r),color(color){} 
celestial_body::~celestial_body(){}
vec2 celestial_body::vel_update(vec2 a_vec, float time ){
    return velocity+=a_vec*time;
}
vec2 celestial_body::pos_update(float time){
    return position+=velocity*time;
}
void celestial_body::print(){
    std::cout<<"\nBody position: ";
     position.print();
     std::cout<< "\nBody velocity: ";
     velocity.print();
     std::cout<<std::endl;
}