cmake_minimum_required(VERSION 3.6)
project(HM_Project)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")


set(SOURCE_FILES
        Actor/actor_class.cpp
        Actor/actor_class.h
        Actor/enemy/Boss_door.cpp
        Actor/enemy/Boss_door.h
        Actor/enemy/boss_fight_1.cpp
        Actor/enemy/boss_fight_1.h
        Actor/enemy/enemy_goomba.cpp
        Actor/enemy/enemy_goomba.h
        Actor/enemy/Firewall.cpp
        Actor/enemy/Firewall.h
        Actor/enemy/Flying_enemy.cpp
        Actor/enemy/Flying_enemy.h
        Actor/enemy/turret.cpp
        Actor/enemy/turret.h
        Actor/Hero.cpp
        Actor/Hero.h
        Actor/projectil/projectile.cpp
        Actor/projectil/projectile.h
        Actor/projectil/Shooting_Mechanic.cpp
        Actor/projectil/Shooting_Mechanic.h
        config.h
        Fysik/collision.cpp
        Fysik/collision.h
        Fysik/interacting.cpp
        Fysik/interacting.h
        game_timer.cpp
        game_timer.h
        Level.cpp
        Level.h
        main.cpp
        Sound.cpp
        Sound.h
        States/game_state.cpp
        States/game_state.h
        States/levelswich.cpp
        States/levelswich.h
        States/menu_state.cpp
        States/menu_state.h
        States/Pause_State.cpp
        States/Pause_State.h
        States/settings_state.cpp
        States/settings_state.h
        States/state_switcher.cpp
        States/state_switcher.h
        States/Super_State.cpp
        States/Super_State.h
        States/Window_State.cpp
        States/Window_State.h
        Super_Class.cpp
        Super_Class.h
        Tile/action_tile/Action_Tile.cpp
        Tile/action_tile/Action_Tile.h
        Tile/action_tile/Spawn_Tile.cpp
        Tile/action_tile/Spawn_Tile.h
        Tile/action_tile/Speed_Tile.cpp
        Tile/action_tile/Speed_Tile.h
        Tile/action_tile/Spike_Tile.cpp
        Tile/action_tile/Spike_Tile.h
        Tile/Finnish_tile.cpp
        Tile/Finnish_tile.h
        Tile/Semisolid_Tile.cpp
        Tile/Semisolid_Tile.h
        Tile/Solid_Tile.cpp
        Tile/Solid_Tile.h
        Tile/Super_Tile.cpp
        Tile/Super_Tile.h
        Tile/Tilemap.cpp
        Tile/Tilemap.h
        health_bar.cpp
        health_bar.h
        Actor/enemy/boss_enemy_2.cpp
        Actor/enemy/boss_enemy_2.h
        Actor/enemy/health_item.cpp
        Actor/enemy/health_item.h
        Actor/enemy/boss_fight_3.cpp
        Actor/enemy/boss_fight_3.h
        Actor/animatonsprites.cpp Actor/animatonsprites.h Actor/enemy/turret_N.cpp Actor/enemy/turret_N.h Actor/enemy/turret_S.cpp Actor/enemy/turret_S.h Actor/enemy/turret_E.cpp Actor/enemy/turret_E.h Actor/enemy/turret_W.cpp Actor/enemy/turret_W.h Actor/enemy/turret_all.cpp Actor/enemy/turret_all.h Actor/Textbox.cpp Actor/Textbox.h States/selectlvl_state.cpp States/selectlvl_state.h)

set(BUILD_SHARED_LIBS OFF)
set(CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} "-static")
add_executable(HM_Project ${SOURCE_FILES})
target_link_libraries (HM_Project sfml-graphics sfml-window sfml-system sfml-audio  )