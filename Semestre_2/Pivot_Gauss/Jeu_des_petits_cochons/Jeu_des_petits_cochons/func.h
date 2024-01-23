#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

struct Piece_s
{
	Coord startCoor;
	Coord endCoor;
	char*** piece;

}; typedef struct Piece_s Piece;

struct Coord_s
{
	int x;
	int y;

}; typedef struct Coord_s Coord;

