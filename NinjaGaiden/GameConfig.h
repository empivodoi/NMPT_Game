#pragma once
#pragma region TextureDefine
#define TEX_STAGE31 1
#define TEX_STAGE32 2
#define TEX_STAGE33 3
#define TEX_PLAYER 4
#define TEX_SPARTA 5
#define TEX_CAT 6
#define TEX_THROWER 7
#define TEX_EAGLE 8
#define TEX_SOLDIER 9
#define TEX_HOLDER 10
#define TEX_ITEM 11
#define TEX_EXPLODE_ENEMY 12
#define TEX_BLUE_SHURIKEN_SKILL 13
#define TEX_RED_SHURIKEN_SKILL 14
#define TEX_FLAME_WHEEL_SKILL 15
#define TEX_THROWER_BULLET 16
#define TEX_SOLDIER_BULLET 17
#define TEX_EXPLODE_WEAPON 18
#define TEX_RUNNER 19
#define TEX_CANNONER 20
#define TEX_CANNONER_BULLET 21
#define TEX_BLOOD 22
#define TEX_BLEED 23
#define TEX_POWER 24
#define TEX_BORDER 25
#define TEX_SKILL_1 26
#define TEX_SKILL_2 27
#define TEX_SKILL_3 28
#define TEX_BOSS 29
#define TEX_BOSS_BULLET 30
#define TEX_BOSS_EXPLODE 31
#pragma endregion

#define SPARTA_POWER 1
#define CAT_POWER 1
#define THROWER_POWER 1
#define THROWER_BULLLET_POWER 1
#define EAGLE_POWER 3
#define SOLDIER_POWER 1
#define SOLDIER_BULLET_POWER 2
#define RUNNER_POWER 1
#define CANNONER_POWER 1
#define CANNONER_BULLET_POWER 2
#define BOSS_POWER 2
#define BOSS_BULLET_POWER 1

#define PLAYER_SLASH_FRAME 7
#define PLAYER_RUNNING_FRAME 4
#define PLAYER_JUMPING_FRAME 2

#define SPARTA_FRAME 15
#define CAT_FRAME 15
#define THROWER_FRAME 15
#define EAGLE_FRAME 15
#define SOLDIER_FOLLOW_FRAME 14
#define SOLDIER_ATTACK_FRAME 2
#define RUNNER_FRAME 10
#define CANNONER_FRAME 15
#define CANNONER_ATTACK_FRAME 15
#define BOSS_FRAME 15
#define BOSS_EXPLODE_FRAME 10

#define SPARTA_SPEED 30.0f
#define THROWER_SPEED 30.0f
#define EAGLE_ACCELERATE 12.0f
#define CAT_SPEED 110.0f
#define CAT_JUMP_VELOCITY 120.0f
#define CAT_GRAVITY 6
#define SOLDIER_SPEED 30.0f
#define RUNNER_SPEED 110.0f
#define RUNNER_JUMP_SPEED 120.0f
#define CANNONER_SPEED 0.0f
#define BOSS_SPEED 0
#define BOSS_JUMP_SPEED 270.0f

//Thrower follow percent time is random!
#define SOLDIER_ATTACK_PERCENTTIME 3.0f
#define SOLDIER_FOLLOW_PERCENTTIME 2.5f
#define THROWER_ATTACK_PERCENTTIME 2.0f
#define CANNONER_ATTACK_PERCENTTIME 2.5f

#define HOLDER_FRAME 10
#define BLUE_SHURIKEN_SKILL_FRAME 15
#define RED_SHURIKEN_SKILL_FRAME 5
#define FLAME_WHEEL_SKILL_FRAME 3

#pragma region WeaponDefine
#define THROWER_BULLET_FRAME 45
#define THROWER_BULLET_VELOCITY_X 25
#define THROWER_BULLET_VELOCITY_Y 270
#define THROWER_BULLET_MAX_FALLING_VELOCITY -270

#define SOLDIER_BULLET_FRAME 60
#define SOLDIER_BULLET_VELOCITY_X 135
#define SOLDIER_BULLET_VELOCITY_Y 0

#define CANNONER_BULLET_FRAME 60
#define CANNONER_BULLET_VELOCITY_X 135
#define CANNONER_BULLET_VELOCITY_Y 0

#define BOSS_BULLET_FRAME 60
#define BOSS_BULLET_VELOCITY_X 90
#define BOSS_BULLET_VELOCITY_Y 0

#define BLUE_SHURIKEN_VELOCITY_X 135
#define BLUE_SHURIKEN_VELOCITY_Y 0

#define RED_SHURIKEN_VELOCITY_X 330
#define RED_SHURIKEN_VELOCITY_Y 0 //=> can't be a constant! 
#define RED_SHURIKEN_ACCELERATE_X 12
#define RED_SHURIKEN_ACCELERATE_Y 6

#define FLAME_WHEEL_1_VELOCITY_X 250
#define FLAME_WHEEL_1_VELOCITY_Y 91 //250*tan(20)
#define FLAME_WHEEL_2_VELOCITY_X 250
#define FLAME_WHEEL_2_VELOCITY_Y 175 //250*tan(35)
#define FLAME_WHEEL_3_VELOCITY_X 250
#define FLAME_WHEEL_3_VELOCITY_Y 298 //250*tan(50)
#pragma endregion

#define GRID_ROWS 4
#define GRID_COLUMNS 32
#define PLAYER_RUN_VELOCITY 90
#define PLAYER_JUMP_ACCELERATEX 15
#define GRAVITY 12
#define PLAYER_MIN_JUMP_VELOCITY 270
#define PLAYER_MAX_FALLING_VELOCITY -270
#define PLAYER_CLIMB_VELOCITY 50

#define PLAYER_OFFSET_GROUND PLAYER_MIN_JUMP_VELOCITY * 1.0 / 60
#define ENEMY_OFFSET_BORDER 2

#define PLAYER_MAX_HURTING_TIME 0.44f
#define PLAYER_BEATEN_VELOCITY_X 75
#define PLAYER_HURTING_TIME_ANIMATION 25 

#define ITEM_TIME_LIMIT 250 
#define ITEM_VY 80 

#define ANIMATION_ITEM_TIMEFREEZE 350 
