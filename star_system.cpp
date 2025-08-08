#include "star_system.h"
#include <vector>


star_system::star_system(std::vector <celestial_body> bods,double duration):bodies(bods),duration(duration){}
star_system::~star_system(){};
void star_system::draw_simulation(float T,vec2 screen_center){
    int counter{0};
    vec2 a_force(0,0);
    while(WindowShouldClose&& counter* T <duration){
        counter++;
        // std::cout<<"\n=================== Bodies values at timestep: "<<counter<<"========================";
        // for(auto &body:bodies){
        //     body.print();
        //     std::cout<<"=========================================================================\n";
        // }
        for (auto &body:bodies)
            body.net_force=compute_net_force(body,bodies);
        for (auto &body:bodies){
            a_force=acceleration_vec(body.net_force,body.mass);
            body.vel_update(a_force,T);
            body.pos_update(T);

        }
        BeginDrawing();
        ClearBackground(BLACK);
        for (const auto& body : bodies) {
            DrawCircleV(Vector2{body.position.x+screen_center.x, body.position.y+screen_center.y}, body.radius, RAYWHITE);
        }
        EndDrawing();

        // Wait for the next frame
        WaitTime(T);
    }
    // ClearBackground(BLACK);

}
