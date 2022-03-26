#ifndef KEY_H
#define KEY_H

# ifdef LINUX_BUILD
// Key code defines for linux
# else
#  define M_LMB		1
#  define M_RMB		2
#  define M_SCRL_UP	4
#  define M_SCRL_DW	5

#  define KEY_ESC	65307

#  define KEY_A		97
#  define KEY_S		115
#  define KEY_D		100
#  define KEY_W		119
#  define KEY_C		99

#  define KEY_Q		113
#  define KEY_E		101

#  define KEY_LEFT	65361
#  define KEY_RIGHT	65363
#  define KEY_DOWN	65364
#  define KEY_UP	65362

#  define KEY_MINUS	65453
#  define KEY_PLUS	65451
#  define KEY_SPACE	32
# endif

#endif