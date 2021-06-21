#include "ultra64.h"

void sub_GAME_7F007770(void) {
    int right_hand;
    int left_hand;
    int player_count;
    int current_player;
    int player;

    player_count = getPlayerCount();
    current_player = get_cur_playernum();
    player = 0;
    
    if (player_count > 0) {
        do {
            set_cur_player(player);
            get_weapon_of_choice(&right_hand, &left_hand);
            store_favorite_weapon_current_player(right_hand, left_hand);
            player += 1;
        } while (player != player_count);
    }

    set_cur_player(current_player);
}

