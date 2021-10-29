#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "ultra64.h"
#include "game/bondview.h"

typedef enum SHOT_REGISTER {
    SHOTS_FIRED = 0,
    HEAD_HITS,
    BODY_HITS,
    LEG_HITS,
    OTHER_HIT_WEAPON,
    OTHER_HIT_HAT,
    OTHER_HIT_OBJECTS
} SHOT_REGISTER;

struct player_data {
    s32 shot_count[7];
    int kill_count;
    int killed_gg_owner_count;
    int killed_p1;
    int killed_p2;
    int killed_p3;
    int killed_p4;
    int time_other_players_on_screen;
    float distance_traveled;
    int damage_to_backside;
    float body_armor_pickups;
    int min_time_between_kills;
    int max_time_between_kills;
    int longest_inning;
    s32 shortest_inning;
    int most_killed_one_life;
    int most_killed_one_time;
    float handicap;
    int flag_counter;
    float player_perspective_height;
    u8 order_out_in_yolt;
    u8 have_token_or_goldengun;
    u8 autoaim;
    u8 sight;
    int killed_civilians;
};

extern struct player *players[4];

extern struct player_data player1_player_data;
extern struct player_data player2_player_data;
extern struct player_data player3_player_data;
extern struct player_data player4_player_data;

extern struct player *currentplayer;
extern struct player_data *pPlayersPerm;
extern s32 player_num;
extern s32 random_byte;
extern PLAYER_ID array_PLAYER_IDs[4];


void reset_play_data_ptrs(void);
void init_player_data_ptrs_construct_viewports(int playercount);
void shuffle_player_ids(void);
s32 get_nth_player_from_shuffled(PLAYER_ID id);
void set_cur_player(s32 playernum);
s32 getPlayerCount(void);
void set_cur_player_screen_size(u32 width, u32 height);
void set_cur_player_viewport_size(u32 ulx, u32 uly);

#endif
