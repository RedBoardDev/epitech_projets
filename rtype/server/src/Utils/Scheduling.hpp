#ifndef SCHEDULING_HPP
#define SCHEDULING_HPP

#define SCREEN_WIDTH        3840
#define SCREEN_HEIGHT       2160

#define PLAYER_HEIGHT       65 * 2
#define PLAYER_WIDTH        113 * 2

#define LITTLE_MONSTER_HEIGHT      90
#define LITTLE_MONSTER_WIDTH       293

#define ZIGZAGER_MONSTER_HEIGHT    82
#define ZIGZAGER_MONSTER_WIDTH     305

#define FOLLOWER_MONSTER_HEIGHT    120
#define FOLLOWER_MONSTER_WIDTH     313

#define BURST_MONSTER_HEIGHT       120
#define BURST_MONSTER_WIDTH        313

#define BOSS1_MONSTER_HEIGHT       348
#define BOSS1_MONSTER_WIDTH        570

#define BOSS2_MONSTER_HEIGHT       348
#define BOSS2_MONSTER_WIDTH        321

#define BOSS3_MONSTER_HEIGHT       282
#define BOSS3_MONSTER_WIDTH        317

#define BOSS8_MONSTER_HEIGHT       600
#define BOSS8_MONSTER_WIDTH        450

#define BOMB_WIDTH         64
#define BOMB_HEIGHT        60

#define LASER_HEIGHT       160

#define RAY_HEIGHT         1
#define RAY_WIDTH          1


#define MISSILE_HEIGHT      1
#define MISSILE_WIDTH       1

#define FIRE_BALL_HEIGHT    127
#define FIRE_BALL_WIDTH     100

#define BOSS8_MISSILE_HEIGHT    92
#define BOSS8_MISSILE_WIDTH     95

#define BONUS_WIDTH   75
#define BONUS_HEIGHT  75

#define POD_ONE_SCORE       750
#define POD_TWO_SCORE       1500
#define POD_THREE_SCORE     3000

#define BOMB_SCORE          8
#define MISSILE_SCORE       10
#define LASER_SCORE         1
#define RAY_SCORE           5

// Progress steps
#define MAP_PROGRESS_STEP                       7

#define PLAYER_PROGRESS_STEP                    20
#define PLAYER_MISSILE_PROGRESS_STEP            50

#define LITTLE_MONSTER_PROGRESS_STEP            10
#define LITTLE_MONSTER_MISSILE_PROGRESS_STEP    30

#define ZIGZAGER_MONSTER_PROGRESS_STEP          10
#define ZIGZAGER_MONSTER_PROGRESS_STEP_VERTICAL 7
#define ZIGZAGER_MONSTER_MISSILE_PROGRESS_STEP  30

#define FOLLOWER_MONSTER_PROGRESS_STEP          10
#define FOLLOWER_MONSTER_MISSILE_PROGRESS_STEP  30

#define BURST_MONSTER_PROGRESS_STEP             10
#define BURST_MONSTER_MISSILE_PROGRESS_STEP     30

#define BOSS1_MONSTER_PROGRESS_STEP             5
#define BOSS1_MONSTER_MISSILE_PROGRESS_STEP     30

#define BOSS2_MONSTER_PROGRESS_STEP             5
#define BOSS2_MONSTER_MISSILE_PROGRESS_STEP     30

// Times
#define MAP_REFRESH_TIME                10 // ms

#define PLAYER_MOVE_TIME                10 // ms
#define PLAYER_FIRE_TIME                150 // ms
#define PLAYER_FIRE_BOMB_TIME           1000 // ms
#define PLAYER_FIRE_LASER_TIME          5000 //ms
#define PLAYER_FIRE_RAY_TIME            3000 //ms

#define MONSTER_MOVE_TIME               12 // ms
#define LITTLE_MONSTER_FIRE_TIME        1000 // ms
#define ZIGZAGER_MONSTER_FIRE_TIME      1000 // ms
#define FOLLOWER_MONSTER_FIRE_TIME      1000 // ms
#define BURST_MONSTER_FIRE_TIME         2000 // ms
#define BURST_FIRE_TIME                 300 // ms
#define BOSS2_MONSTER_FIRE_TIME         1000 // ms
#define BIG_FIRE_TIME                   8000 // ms

#define BONUS_SPAWN_TIME                20000 // ms

#define CHANGE_HORIZONTAL_DIRECTION     3 // second
#define CHANGE_VERTICAL_DIRECTION       5 // second

#define MISSILES_MOVE_TIME              10 // ms
#define BONUS_MOVE_TIME                 10 // ms
#define BOMB_MOVE_TIME                  10 // ms
#define LASER_MOVE_TIME                 50 // ms
#define RAY_MOVE_TIME                   10  // ms

#define SEND_WAIT_MESSAGE_TIME          200 // ms
#define PLAYER_ALIVE_MAX_TIME           10 // seconds
#define TIMEOUT_START_GAME              30000 // ms
#define TIMEOUT_BETWEEN_LEVELS          10000 // ms
#define GAME_OVER_REFRESH               500 // ms

// damages
#define BOMB_DAMAGE                     150
#define LASER_DAMAGE                    17
#define RAY_DAMAGE                      25


#endif
