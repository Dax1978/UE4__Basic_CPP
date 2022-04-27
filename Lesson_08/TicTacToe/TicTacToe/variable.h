#pragma once

enum PLAYER { 
	HUMAN = 'X', 
	AI = 'O', 
	EMPTY = '_'
};

typedef struct {
	int szY;
	int szX;
	PLAYER** map;
	int towin;
	int game;
	int wingame;
	int losergame;
	bool bool_ai;
} Field;


