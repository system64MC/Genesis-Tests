#include <genesis.h>
#include "joy.h"

u16 key_pressed = 0;
u16 old_key = 0;

bool JoyDown(u16 button) {
	return ((key_pressed&button) > 0) ? TRUE : FALSE ;
}

bool JoyPressed(u16 button) {
	bool result = FALSE;
	if(!(old_key&button) && key_pressed&button) result = TRUE;
	return result;
}

bool JoyRelease(u16 button) {
	bool result = FALSE;
	
	if((old_key&button)) {
		if(!(key_pressed&button)) result = TRUE;
	}

	return result;
}

void JoyBegin(void) {
	key_pressed = JOY_readJoypad(JOY_1);
}

void JoyFinish(void) {
	if(old_key != key_pressed) old_key = key_pressed;
}
