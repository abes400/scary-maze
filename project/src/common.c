#include "common.h"

Texture2D logo, endimg, play;
Sound endsound;
Font font;

void draw_cursor(Vector2 mouse_pos) 
{ DrawRectangle(mouse_pos.x - 4, mouse_pos.y - 4, 8, 8, DARKBLUE); }