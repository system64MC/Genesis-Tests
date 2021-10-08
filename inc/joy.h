#ifndef _JOY_H
#define _JOY_H

#pragma once

extern u16 key_pressed;
extern u16 old_key;

// ------------------------------
// Pad Functions
// ------------------------------

bool JoyDown(u16 button);
bool JoyPressed(u16 button);
bool JoyRelease(u16 button);
void JoyBegin(void);
void JoyFinish(void);

#endif