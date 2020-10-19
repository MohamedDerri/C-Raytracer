/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mac.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 01:45:27 by slaanani          #+#    #+#             */
/*   Updated: 2020/03/25 01:45:27 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAC_H
# define MAC_H

/*
** KEYBOARD
*/

# define ESC 65307
# define UP 65362
# define DOWN 65364
# define RIGHT 65363
# define LEFT 65361
# define FORWARD 119
# define BACKWARD 115
# define PLUS 65451
# define MINUS 65453

/*
** MOUSE
*/

# define LEFT_CLICK 1
# define RIGHT_CLICK 3

/*
** X MASKS
*/

#define KeyPressMask	(1L<<0)
#define KeyReleaseMask	(1L<<1)
#define Button3MotionMask	(1L<<10)
#define Button4MotionMask	(1L<<11)
#define Button5MotionMask	(1L<<12)
#define ButtonMotionMask	(1L<<13)
#define KeymapStateMask	(1L<<14)
#define ExposureMask	(1L<<15)
#define VisibilityChangeMask	(1L<<16)
#define StructureNotifyMask	(1L<<17)
#define ResizeRedirectMask	(1L<<18)
#define SubstructureNotifyMask	(1L<<19)
#define ButtonPressMask	(1L<<2)
#define SubstructureRedirectMask	(1L<<20)
#define FocusChangeMask	(1L<<21)
#define PropertyChangeMask	(1L<<22)
#define ColormapChangeMask	(1L<<23)
#define ButtonReleaseMask	(1L<<3)
#define EnterWindowMask	(1L<<4)
#define LeaveWindowMask	(1L<<5)
#define PointerMotionMask	(1L<<6)
#define PointerMotionHintMask	(1L<<7)
#define Button1MotionMask	(1L<<8)
#define Button2MotionMask	(1L<<9)
#define NoEventMask	0L
#define FocusOut	10
#define KeymapNotify	11
#define Expose	12
#define GraphicsExpose	13
#define NoExpose	14
#define VisibilityNotify	15
#define CreateNotify	16
#define DestroyNotify	17
#define UnmapNotify	18
#define MapNotify	19
#define KeyPress	2
#define MapRequest	20
#define ReparentNotify	21
#define ConfigureNotify	22
#define ConfigureRequest	23
#define GravityNotify	24
#define ResizeRequest	25
#define CirculateNotify	26
#define CirculateRequest	27
#define PropertyNotify	28
#define SelectionClear	29
#define KeyRelease	3
#define SelectionRequest	30
#define SelectionNotify	31
#define ColormapNotify	32
#define ClientMessage	33
#define MappingNotify	34
#define LASTEvent	35
#define ButtonPress	4
#define ButtonRelease	5
#define MotionNotify	6
#define EnterNotify	7
#define LeaveNotify	8
#define FocusIn	9
#define ShiftMask	(1<<0)
#define LockMask	(1<<1)
#define ControlMask	(1<<2)
#define Mod1Mask	(1<<3)
#define Mod2Mask	(1<<4)
#define Mod3Mask	(1<<5)
#define Mod4Mask	(1<<6)
#define Mod5Mask	(1<<7)
#define ShiftMapIndex	0
#define LockMapIndex	1
#define ControlMapIndex	2
#define Mod1MapIndex	3
#define Mod2MapIndex	4
#define Mod3MapIndex	5
#define Mod4MapIndex	6
#define Mod5MapIndex	7
#define Button3Mask	(1<<10)
#define Button4Mask	(1<<11)
#define Button5Mask	(1<<12)
#define AnyModifier	(1<<15)
#define Button1Mask	(1<<8)
#define Button2Mask	(1<<9)

#endif