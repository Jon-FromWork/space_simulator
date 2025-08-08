#include "physics.h"

float distance(vec2 num1, vec2 num2){
    return std::sqrt((num1.x-num2.x)*(num1.x-num2.x)+(num1.y-num2.y)*(num1.y-num2.y));
}
vec2 gravitational_force_calculation(const celestial_body& body1, const celestial_body& body2){
    float r=distance(body1.position, body2.position);
    if(r==0)
        return vec2(0,0);
    //this is the actual gravitational force
    float F=G*( (body1.mass*body2.mass)/(r*r));
    vec2 displacement_vec= body2.position-body1.position;
    vec2 unit_vec=displacement_vec.normalize();
    //returning force vector
    return unit_vec*F;
}
vec2 compute_net_force(const celestial_body &target_body,const std::vector <celestial_body> &other_bodies){
    vec2 net_force(0.0f,0.0f);
    for (const auto &body : other_bodies){
        if(&body != &target_body)
            net_force += gravitational_force_calculation(target_body, body);
    }
    return net_force;
}
vec2 acceleration_vec(vec2 net_force, float mass){
    vec2 a_vec;
    return a_vec= net_force / mass;
}
