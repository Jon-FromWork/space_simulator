#include <iostream>
#include "vec2.h"
#include "celestial_body.h"
#include "physics.h"
#include "raylib.h"
#include "star_system.h"
#include <cmath>
#include <vector>
int main(){
    
    std::cout<<"Hello orbit!"<<std::endl;
    
    const int screen_width{800};
    const int screen_height{800};
    const vec2 screen_center = vec2(screen_width/2, screen_height/2);
    InitWindow(screen_width, screen_height, "orbit");
    const int FPS=60;
    const float sim_time =210;
    SetTargetFPS(FPS);

    std::vector <celestial_body> Nyx_star_system{};
    
    // Star
    Nyx_star_system.push_back(celestial_body("Nyxar",   vec2(0.0, 0.0),        vec2(0.0, 0.0),       2500.0,  25.0, (Color){255, 255, 120})); 

    // Aureon — Inner planet
    Nyx_star_system.push_back(celestial_body("Aureon",  vec2(45.0, 0.0),       vec2(0.0, 45.0),       0.3,     5.0,  (Color){255, 180, 80}));

    // Veridia — Habitable Earth-like
    Nyx_star_system.push_back(celestial_body("Veridia", vec2(120.0, 0.0),      vec2(0.0, 30.0),       6.0,     8.0,  (Color){80, 180, 255}));
    Nyx_star_system.push_back(celestial_body("Thalos",  vec2(120.4, 0.0),      vec2(0.0, 30.9),       0.07,    3.0,  (Color){200, 200, 200}));
    Nyx_star_system.push_back(celestial_body("Kera",    vec2(120.8, 0.0),      vec2(0.0, 31.1),       0.02,    2.0,  (Color){170, 170, 170}));

    // Draxus — Volcanic super-Earth
    Nyx_star_system.push_back(celestial_body("Draxus",  vec2(210.0, 0.0),      vec2(0.0, 25.5),       10.0,    10.0, (Color){180, 60, 60}));
    Nyx_star_system.push_back(celestial_body("Volar",   vec2(210.6, 0.0),      vec2(0.0, 26.5),       0.15,    4.0,  (Color){255, 100, 100}));

    // Cryon — Ice giant
    Nyx_star_system.push_back(celestial_body("Cryon",   vec2(410.0, 0.0),      vec2(0.0, 15.0),       95.0,    12.0, (Color){180, 180, 255}));
    Nyx_star_system.push_back(celestial_body("Shard",   vec2(410.9, 0.0),      vec2(0.0, 15.8),       0.2,     4.0,  (Color){200, 200, 255}));
    Nyx_star_system.push_back(celestial_body("Echo",    vec2(411.4, 0.0),      vec2(0.0, 16.2),       0.08,    3.0,  (Color){150, 150, 255}));

    // Nerion — Rogue planet
    Nyx_star_system.push_back(celestial_body("Nerion",  vec2(750.0, 0.0),      vec2(0.0, 10.5),       3.0,     6.0,  (Color){100, 100, 100}));
    Nyx_star_system.push_back(celestial_body("Umbra",   vec2(750.5, 0.0),      vec2(0.0, 11.1),       0.03,    2.0,  (Color){80, 80, 80}));

    star_system Nyx(Nyx_star_system,210);
    
    vec2 net_force(0,0);
    vec2 a_force(0,0);
    int counter{0};
    const float T = 1.0/FPS;
    //Simulation loop


    while(!WindowShouldClose() && counter * T <sim_time){
        counter++;
        // std::cout<<"\n=================== Bodies values at timestep: "<<counter<<"========================";
        // for(auto &body:bodies){
        //     body.print();
        //     std::cout<<"=========================================================================\n";
        // }
        Nyx.draw_simulation(T,screen_center);

        // Wait for the next frame
        //WaitTime(T);
    }
    CloseWindow();

    return 0;
}