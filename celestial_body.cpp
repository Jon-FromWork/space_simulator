#include "celestial_body.h"
#include "physics.h"

celestial_body::celestial_body():position(vec2()),velocity(vec2()),mass(1),radius(1){}
celestial_body::celestial_body(std::string name,vec2 pos,vec2 vel, float ma, float r,Color color): name(name),position(pos),velocity(vel),mass(ma),radius(r),color(color){} 
celestial_body::~celestial_body(){}
vec2 celestial_body::vel_update(vec2 a_vec, float time ){
    return velocity+=a_vec*time;
}
vec2 celestial_body::pos_update(float time){
    return position+=velocity*time;
}
void celestial_body::calc_orbit_vel(vec2 star_position, float star_mass, float G){
    vec2 r_vec = position;
    float r = r_vec.length();
    if (r == 0) return; // Avoid division by zero

    float v = sqrt(G * star_mass / r);

    // Get perpendicular direction (rotate r_vec by 90 degrees)
    vec2 perp(-r_vec.y, r_vec.x);
    perp = perp.normalize();

    // Set velocity perpendicular to radius, with calculated magnitude
    velocity = perp * v;
}

void celestial_body::print(){
    std::cout<<"\nBody position: ";
     position.print();
     std::cout<< "\nBody velocity: ";
     velocity.print();
     std::cout<<std::endl;
}