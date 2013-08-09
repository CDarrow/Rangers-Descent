#include "pstypes.h"
#include "vecmat.h"
#include "object.h"

#define spec 1
#define display_spec_text 1

#define SPEC_SPEED_MOD	1

int spec_trigger;
int in_free;
int piggy_and_free_switch;
int piggy_num;
int last_piggy_num;
int first_piggy;
int ignore_last_spec_text;

void do_spectator_frame();

void multi_make_player_spec();
void multi_send_spec_status(int type);
void multi_do_spec_status(char * buf);

void multi_send_spectator_status_to_new_player(int pnum);
void multi_do_spectator_status_to_new_player(char * buf);

void kill_all_objects_linked_to_player();
void reset_stats_spec();

void make_piggy_invisible(int piggy_num);
void make_last_piggy_visible(int piggy_num);
void make_all_spectators_invisible();

void switch_between_piggy_and_free(); 
void switch_between_piggies();

void init_all_spectator_stuff();
void render_spec_status();

void spec_kill_movement();
void send_i_am_spectating_you(int pnum);
void do_i_am_spectating_you(char * buf);
void send_i_am_no_longer_spectating_you(int pnum);
void do_i_am_no_longer_spectating_you(char * buf);

void multi_send_spec_flags(char pnum);
void multi_do_spec_flags(char * buf);

void calculate_rotation_interpolation(vms_matrix original_orient, object *plobj);

vms_matrix orient_interpolation_matrix;	// only need one since it's only applied to the piggy

int global_fps;