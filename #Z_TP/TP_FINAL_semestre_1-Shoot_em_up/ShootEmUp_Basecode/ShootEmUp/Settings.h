#pragma once

#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//#define FHD
//#define FULLSCREEN

#define UNUSED(v) (void)v
static inline void nofunc() {};

#define PIX_TO_WORLD (1.0f / 48.0f)

#ifdef _WIN32
#  include "SDL.h"
#  include "SDL_image.h"
//#  include "SDL_ttf.h"
#  include "SDL_mixer.h"

//These are not provided in MS libs.

# define M_PI		3.14159265358979323846f	/* pi */
# define M_PI_2		1.57079632679489661923f	/* pi/2 */
# define M_PI_4		0.78539816339744830962f	/* pi/4 */

#else
#  include <SDL2/SDL.h>
#  include <SDL2/SDL_image.h>
//#  include <SDL2/SDL_ttf.h>
#  include <SDL2/SDL_mixer.h>
#endif

#ifdef _WIN32
#  define INLINE inline
#else
#  define INLINE static inline
#endif

#define AssertNew(ptr) { if (ptr == NULL) { assert(false); abort(); } }

#define HD_WIDTH 1280
#define HD_HEIGHT 720

#define FHD_WIDTH 1920
#define FHD_HEIGHT 1080

#ifdef FHD
#  define WINDOW_WIDTH   FHD_WIDTH
#  define WINDOW_HEIGHT  FHD_HEIGHT
#  define LOGICAL_WIDTH  FHD_WIDTH
#  define LOGICAL_HEIGHT FHD_HEIGHT
#else
#  define WINDOW_WIDTH   HD_WIDTH
#  define WINDOW_HEIGHT  HD_HEIGHT
#  define LOGICAL_WIDTH  HD_WIDTH
#  define LOGICAL_HEIGHT HD_HEIGHT
#endif

#define SDL_MIXER_CHANNELS 8
