#ifndef SCOREBOARD_H
#define SCOREBOARD_H

const unsigned char Game_Over[] ={
 0x42, 0x4D, 0xF6, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x76, 0x00, 0x00, 0x00, 0x28, 0x00, 0x00, 0x00, 0x3A, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x00, 0x00, 0x01, 0x00, 0x04, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0xC4, 0x0E, 0x00, 0x00, 0xC4, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x80,
 0x00, 0x00, 0x00, 0x80, 0x80, 0x00, 0x80, 0x00, 0x00, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x80, 0x00, 0x00, 0x80, 0x80, 0x80, 0x00, 0xC0, 0xC0, 0xC0, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0xFF,
 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0xFF, 0xFF, 0xF0, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
 0xFF, 0x0F, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xF0, 0x0F, 0xFF, 0x00, 0xFF, 0xFF, 0xF0, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x0F, 0xF0, 0x00, 0x0F, 0x00, 0xF0, 0x0F,
 0x00, 0xF0, 0x00, 0x00, 0xF0, 0x00, 0x0F, 0x00, 0x00, 0x0F, 0xF0, 0x00, 0xFF, 0x00, 0x00, 0x0F, 0x00, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x0F, 0x00, 0xF0, 0x0F,
 0x00, 0xF0, 0x0F, 0xFF, 0xF0, 0x00, 0x0F, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x0F, 0x00, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x00, 0xF0, 0x0F, 0x00, 0xF0, 0x0F, 0x00, 0xF0, 0x0F,
 0x00, 0xF0, 0x00, 0x00, 0xF0, 0x00, 0x0F, 0x00, 0xF0, 0x0F, 0x00, 0xF0, 0x0F, 0x00, 0xFF, 0xFF, 0x00, 0xFF, 0xF0, 0x00, 0x00, 0x00, 0x0F, 0x00, 0xF0, 0x0F, 0x00, 0xF0, 0x0F, 0x00, 0xF0, 0x0F,
 0x00, 0xF0, 0x0F, 0x00, 0xF0, 0x00, 0x0F, 0x00, 0xF0, 0x0F, 0x00, 0xF0, 0x0F, 0x00, 0x00, 0x0F, 0x00, 0xF0, 0x0F, 0x00, 0x00, 0x00, 0x0F, 0x00, 0xF0, 0x0F, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00,
 0x00, 0xF0, 0x00, 0x00, 0xF0, 0x00, 0x0F, 0x00, 0xF0, 0x0F, 0x00, 0xF0, 0x0F, 0x00, 0xF0, 0x0F, 0x00, 0xF0, 0x0F, 0x00, 0x00, 0x00, 0x0F, 0x00, 0xFF, 0xF0, 0xF0, 0x00, 0x0F, 0x00, 0x00, 0x00,
 0x00, 0xF0, 0x00, 0x00, 0xF0, 0x00, 0x0F, 0x00, 0xF0, 0x0F, 0x00, 0xF0, 0x0F, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x0F, 0x00, 0xF0, 0x00, 0x0F, 0xFF, 0xF0, 0xFF, 0xFF, 0xFF,
 0xFF, 0x0F, 0xFF, 0xFF, 0x00, 0x00, 0x0F, 0x00, 0xF0, 0x0F, 0xFF, 0x0F, 0xF0, 0xFF, 0xFF, 0xF0, 0xFF, 0xFF, 0xF0, 0x00, 0x00, 0x00, 0x0F, 0x00, 0xFF, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x00, 0xF0, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF,

};

#endif