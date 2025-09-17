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
    Nyx_star_system.push_back(celestial_body("Nyxar",   vec2(0.0, 0.0),        vec2(0.0, 0.0),       500.0,  25.0, (Color){YELLOW})); 
    
    // Aureon — Inner planet
    
    Nyx_star_system.push_back(celestial_body("Aureon",  vec2(45.0, 0.0),       vec2(0.0,1 ),       0.3,     5.0,  (Color){RED}));

    // Veridia — Habitable Earth-like
    Nyx_star_system.push_back(celestial_body("Veridia", vec2(120.0, 0.0),      vec2(0.0, 30.0),       6.0,     8.0,  (Color){BLUE}));
    Nyx_star_system.push_back(celestial_body("Thalos",  vec2(120.4, 0.0),      vec2(0.0, 30.9),       0.07,    3.0,  (Color){GREEN}));
    Nyx_star_system.push_back(celestial_body("Kera",    vec2(120.8, 0.0),      vec2(0.0, 31.1),       0.02,    2.0,  (Color){WHITE}));

    // Draxus — Volcanic super-Earth
    Nyx_star_system.push_back(celestial_body("Draxus",  vec2(210.0, 0.0),      vec2(0.0, 25.5),       10.0,    10.0, (Color){RED}));
    Nyx_star_system.push_back(celestial_body("Volar",   vec2(210.6, 0.0),      vec2(0.0, 26.5),       0.15,    4.0,  (Color){ORANGE}));

    // Cryon — Ice giant
    Nyx_star_system.push_back(celestial_body("Cryon",   vec2(410.0, 0.0),      vec2(0.0, 15.0),       95.0,    12.0, (Color){BLUE}));
    Nyx_star_system.push_back(celestial_body("Shard",   vec2(410.9, 0.0),      vec2(0.0, 15.8),       0.2,     4.0,  (Color){BLUE}));
    Nyx_star_system.push_back(celestial_body("Echo",    vec2(411.4, 0.0),      vec2(0.0, 16.2),       0.08,    3.0,  (Color){WHITE}));

    // Nerion — Rogue planet
    Nyx_star_system.push_back(celestial_body("Nerion",  vec2(500.0, 0.0),      vec2(0.0, 10.5),       3.0,     6.0,  (Color){PINK}));
    Nyx_star_system.push_back(celestial_body("Umbra",   vec2(500.5, 0.0),      vec2(0.0, 11.1),       0.03,    2.0,  (Color){PURPLE}));

    star_system Nyx(Nyx_star_system,210);
    Nyx.orbit_vel_updater();
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