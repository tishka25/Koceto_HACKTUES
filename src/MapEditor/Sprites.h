
#ifndef SPRITES_H
#define SPRITES_H

#define AVAILABLE_SPRITES 10

#define MAP_WIDTH 0
#define MAP_HEIGHT 1

//Different sprites naming is here:
#define BRICKS_DESTRUCTIVE 1
#define BRICKS_INDESTRUCTIVE 2
//TODO all the sprites naming for the MapEditor

static unsigned char bullet_palette[15] = {0x00,0xff};
static unsigned char bullet[5] = {
	2,
	2,
	1,
0x00,
0x00};

static unsigned int MAP[]={
  20,15,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
};


static unsigned int MAP2[15][20]={
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,1},
	{1,0,0,0,1,0,1,0,0,1,0,1,0,0,0,0,0,0,0,1},
	{1,0,0,0,1,0,1,0,0,1,0,1,0,0,0,0,0,0,0,1},
	{1,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};


static unsigned char tank_left_palette[15] = {0xfc,0xf0,0xec,0x24,0x00,0xff,0xfc,0xf0,0xec,0x24,0x00,0xff,0xfc,0xf0,0xec};
static unsigned char tank_left[] = {
	16,
	16,
	2,
0x55,0x14,0x14,0x14,0x14,0x14,0x14,0x15,
0x55,0x24,0x24,0x24,0x24,0x24,0x24,0x24,
0x55,0x24,0x24,0x24,0x24,0x24,0x24,0x24,
0x55,0x34,0x34,0x34,0x34,0x34,0x34,0x35,
0x55,0x55,0x54,0x44,0x44,0x44,0x45,0x55,
0x55,0x55,0x44,0x11,0x11,0x11,0x44,0x55,
0x55,0x55,0x44,0x13,0x33,0x33,0x14,0x45,
0x11,0x11,0x11,0x13,0x11,0x13,0x34,0x45,
0x22,0x22,0x22,0x23,0x11,0x13,0x34,0x45,
0x55,0x55,0x44,0x23,0x33,0x33,0x24,0x45,
0x55,0x55,0x44,0x22,0x22,0x22,0x44,0x55,
0x55,0x55,0x54,0x44,0x44,0x44,0x45,0x55,
0x55,0x14,0x14,0x14,0x14,0x14,0x14,0x15,
0x55,0x24,0x24,0x24,0x24,0x24,0x24,0x24,
0x55,0x24,0x24,0x24,0x24,0x24,0x24,0x24,
0x55,0x34,0x34,0x34,0x34,0x34,0x34,0x35,
0x44,0x30,0x30,0x30,0x30,0x30,0x30,0x34,
0x44,0x31,0x31,0x31,0x31,0x31,0x31,0x31,
0x44,0x31,0x31,0x31,0x31,0x31,0x31,0x31,
0x44,0x32,0x32,0x32,0x32,0x32,0x32,0x34,
0x44,0x44,0x43,0x33,0x33,0x33,0x34,0x44,
0x44,0x44,0x33,0x00,0x00,0x00,0x33,0x44,
0x44,0x44,0x33,0x02,0x22,0x22,0x03,0x34,
0x00,0x00,0x00,0x02,0x00,0x02,0x23,0x34,
0x11,0x11,0x11,0x12,0x00,0x02,0x23,0x34,
0x44,0x44,0x33,0x12,0x22,0x22,0x13,0x34,
0x44,0x44,0x33,0x11,0x11,0x11,0x33,0x44,
0x44,0x44,0x43,0x33,0x33,0x33,0x34,0x44,
0x44,0x30,0x30,0x30,0x30,0x30,0x30,0x34,
0x44,0x31,0x31,0x31,0x31,0x31,0x31,0x31,
0x44,0x31,0x31,0x31,0x31,0x31,0x31,0x31,
0x44,0x32,0x32,0x32,0x32,0x32,0x32,0x34};

static unsigned char tank_up_palette[15] = {0xfc,0xf0,0xec,0x24,0x00,0xff,0xfc,0xf0,0xec,0x24,0x00,0xff,0xfc,0xf0,0xec};
static unsigned char tank_up[] = {
	16,
	16,
	2,
0x55,0x55,0x55,0x52,0x15,0x55,0x55,0x55,
0x55,0x55,0x55,0x52,0x15,0x55,0x55,0x55,
0x32,0x21,0x55,0x52,0x15,0x55,0x32,0x21,
0x44,0x44,0x55,0x52,0x15,0x55,0x44,0x44,
0x32,0x21,0x54,0x42,0x14,0x45,0x32,0x21,
0x44,0x44,0x44,0x42,0x14,0x44,0x44,0x44,
0x32,0x21,0x42,0x22,0x11,0x14,0x32,0x21,
0x44,0x44,0x42,0x33,0x33,0x14,0x44,0x44,
0x32,0x21,0x42,0x31,0x13,0x14,0x32,0x21,
0x44,0x44,0x42,0x31,0x13,0x14,0x44,0x44,
0x32,0x21,0x42,0x31,0x13,0x14,0x32,0x21,
0x44,0x44,0x42,0x33,0x33,0x14,0x44,0x44,
0x32,0x21,0x44,0x23,0x31,0x44,0x32,0x21,
0x44,0x44,0x54,0x44,0x44,0x45,0x44,0x44,
0x32,0x21,0x55,0x44,0x44,0x55,0x32,0x21,
0x54,0x45,0x55,0x55,0x55,0x55,0x54,0x45,
0x44,0x44,0x44,0x41,0x04,0x44,0x44,0x44,
0x44,0x44,0x44,0x41,0x04,0x44,0x44,0x44,
0x33,0x33,0x44,0x41,0x04,0x44,0x33,0x33,
0x21,0x10,0x44,0x41,0x04,0x44,0x21,0x10,
0x33,0x33,0x43,0x31,0x03,0x34,0x33,0x33,
0x21,0x10,0x33,0x31,0x03,0x33,0x21,0x10,
0x33,0x33,0x31,0x11,0x00,0x03,0x33,0x33,
0x21,0x10,0x31,0x22,0x22,0x03,0x21,0x10,
0x33,0x33,0x31,0x20,0x02,0x03,0x33,0x33,
0x21,0x10,0x31,0x20,0x02,0x03,0x21,0x10,
0x33,0x33,0x31,0x20,0x02,0x03,0x33,0x33,
0x21,0x10,0x31,0x22,0x22,0x03,0x21,0x10,
0x33,0x33,0x33,0x12,0x20,0x33,0x33,0x33,
0x21,0x10,0x43,0x33,0x33,0x34,0x21,0x10,
0x33,0x33,0x44,0x33,0x33,0x44,0x33,0x33,
0x41,0x14,0x44,0x44,0x44,0x44,0x41,0x14};

static unsigned char tank_down_palette[15] = {0xfc,0xf0,0xec,0x24,0x00,0xff,0xfc,0xf0,0xec,0x24,0x00,0xff,0xfc,0xf0,0xec};
static unsigned char tank_down[] = {
	16,
	16,
	2,
0x54,0x45,0x55,0x55,0x55,0x55,0x54,0x45,
0x12,0x23,0x55,0x44,0x44,0x55,0x12,0x23,
0x44,0x44,0x54,0x44,0x44,0x45,0x44,0x44,
0x12,0x23,0x44,0x13,0x32,0x44,0x12,0x23,
0x44,0x44,0x41,0x33,0x33,0x24,0x44,0x44,
0x12,0x23,0x41,0x31,0x13,0x24,0x12,0x23,
0x44,0x44,0x41,0x31,0x13,0x24,0x44,0x44,
0x12,0x23,0x41,0x31,0x13,0x24,0x12,0x23,
0x44,0x44,0x41,0x33,0x33,0x24,0x44,0x44,
0x12,0x23,0x41,0x11,0x22,0x24,0x12,0x23,
0x44,0x44,0x44,0x41,0x24,0x44,0x44,0x44,
0x12,0x23,0x54,0x41,0x24,0x45,0x12,0x23,
0x44,0x44,0x55,0x51,0x25,0x55,0x44,0x44,
0x12,0x23,0x55,0x51,0x25,0x55,0x12,0x23,
0x55,0x55,0x55,0x51,0x25,0x55,0x55,0x55,
0x55,0x55,0x55,0x51,0x25,0x55,0x55,0x55,
0x52,0x25,0x55,0x55,0x55,0x55,0x52,0x25,
0x44,0x44,0x55,0x44,0x44,0x55,0x44,0x44,
0x12,0x23,0x54,0x44,0x44,0x45,0x12,0x23,
0x44,0x44,0x44,0x13,0x32,0x44,0x44,0x44,
0x12,0x23,0x41,0x33,0x33,0x24,0x12,0x23,
0x44,0x44,0x41,0x31,0x13,0x24,0x44,0x44,
0x12,0x23,0x41,0x31,0x13,0x24,0x12,0x23,
0x44,0x44,0x41,0x31,0x13,0x24,0x44,0x44,
0x12,0x23,0x41,0x33,0x33,0x24,0x12,0x23,
0x44,0x44,0x41,0x11,0x22,0x24,0x44,0x44,
0x12,0x23,0x44,0x41,0x24,0x44,0x12,0x23,
0x44,0x44,0x54,0x41,0x24,0x45,0x44,0x44,
0x12,0x23,0x55,0x51,0x25,0x55,0x12,0x23,
0x44,0x44,0x55,0x51,0x25,0x55,0x44,0x44,
0x55,0x55,0x55,0x51,0x25,0x55,0x55,0x55,
0x55,0x55,0x55,0x51,0x25,0x55,0x55,0x55};


static unsigned char tank_right_palette[15] = {0xfc,0xf0,0xec,0x24,0x00,0xff,0xfc,0xf0,0xec,0x24,0x00,0xff,0xfc,0xf0,0xec};
static unsigned char tank_right[] = {
	16,
	16,
	2,
0x53,0x43,0x43,0x43,0x43,0x43,0x43,0x55,
0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x55,
0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x55,
0x51,0x41,0x41,0x41,0x41,0x41,0x41,0x55,
0x55,0x54,0x44,0x44,0x44,0x45,0x55,0x55,
0x55,0x44,0x22,0x22,0x22,0x44,0x55,0x55,
0x54,0x42,0x33,0x33,0x32,0x44,0x55,0x55,
0x54,0x43,0x31,0x11,0x32,0x22,0x22,0x22,
0x54,0x43,0x31,0x11,0x31,0x11,0x11,0x11,
0x54,0x41,0x33,0x33,0x31,0x44,0x55,0x55,
0x55,0x44,0x11,0x11,0x11,0x44,0x55,0x55,
0x55,0x54,0x44,0x44,0x44,0x45,0x55,0x55,
0x53,0x43,0x43,0x43,0x43,0x43,0x43,0x55,
0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x55,
0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x55,
0x51,0x41,0x41,0x41,0x41,0x41,0x41,0x55,
0x54,0x34,0x34,0x34,0x34,0x34,0x34,0x55,
0x24,0x24,0x24,0x24,0x24,0x24,0x24,0x55,
0x24,0x24,0x24,0x24,0x24,0x24,0x24,0x55,
0x54,0x14,0x14,0x14,0x14,0x14,0x14,0x55,
0x55,0x54,0x44,0x44,0x44,0x45,0x55,0x55,
0x55,0x44,0x22,0x22,0x22,0x44,0x55,0x55,
0x54,0x42,0x33,0x33,0x32,0x44,0x55,0x55,
0x54,0x43,0x31,0x11,0x32,0x22,0x22,0x22,
0x54,0x43,0x31,0x11,0x31,0x11,0x11,0x11,
0x54,0x41,0x33,0x33,0x31,0x44,0x55,0x55,
0x55,0x44,0x11,0x11,0x11,0x44,0x55,0x55,
0x55,0x54,0x44,0x44,0x44,0x45,0x55,0x55,
0x54,0x34,0x34,0x34,0x34,0x34,0x34,0x55,
0x24,0x24,0x24,0x24,0x24,0x24,0x24,0x55,
0x24,0x24,0x24,0x24,0x24,0x24,0x24,0x55,
0x54,0x14,0x14,0x14,0x14,0x14,0x14,0x55};


//
// static unsigned char tank[256] = {
// 	0x00,0x00,0xff,0x24,0xff,0x24,0xff,0x24,0xff,0x24,0xff,0x24,0xff,0x24,0xff,0x00,
// 	0x00,0x00,0xfc,0x24,0xfc,0x24,0xfc,0x24,0xfc,0x24,0xfc,0x24,0xfc,0x24,0xfc,0x24,
// 	0x00,0x00,0xf0,0x24,0xf0,0x24,0xf0,0x24,0xf0,0x24,0xf0,0x24,0xf0,0x24,0xf0,0x24,
// 	0x00,0x00,0xec,0x24,0xec,0x24,0xec,0x24,0xec,0x24,0xec,0x24,0xec,0x24,0xec,0x00,
// 	0x00,0x00,0x00,0x00,0x00,0x24,0x24,0x24,0x24,0x24,0x24,0x24,0x24,0x00,0x00,0x00,
// 	0x00,0x00,0x00,0x00,0x24,0x24,0xfc,0xff,0xff,0xff,0xff,0xfc,0x24,0x24,0x00,0x00,
// 	0x00,0x00,0x00,0x00,0x24,0x24,0xfc,0xec,0xec,0xec,0xec,0xec,0xfc,0x24,0x24,0x00,
// 	0xff,0xff,0xff,0xff,0xff,0xfc,0xfc,0xec,0xfc,0xff,0xff,0xec,0xec,0x24,0x24,0x00,
// 	0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0xec,0xfc,0xfc,0xfc,0xec,0xec,0x24,0x24,0x00,
// 	0x00,0x00,0x00,0x00,0x24,0x24,0xf0,0xec,0xec,0xec,0xec,0xec,0xf0,0x24,0x24,0x00,
// 	0x00,0x00,0x00,0x00,0x24,0x24,0xf0,0xf0,0xf0,0xf0,0xf0,0xf0,0x24,0x24,0x00,0x00,
// 	0x00,0x00,0x00,0x00,0x00,0x24,0x24,0x24,0x24,0x24,0x24,0x24,0x24,0x00,0x00,0x00,
// 	0x00,0x00,0xff,0x24,0xff,0x24,0xff,0x24,0xff,0x24,0xff,0x24,0xff,0x24,0xff,0x00,
// 	0x00,0x00,0xfc,0x24,0xfc,0x24,0xfc,0x24,0xfc,0x24,0xfc,0x24,0xfc,0x24,0xfc,0x24,
// 	0x00,0x00,0xf0,0x24,0xf0,0x24,0xf0,0x24,0xf0,0x24,0xf0,0x24,0xf0,0x24,0xf0,0x24,
// 	0x00,0x00,0xec,0x24,0xec,0x24,0xec,0x24,0xec,0x24,0xec,0x24,0xec,0x24,0xec,0x00};


static unsigned char bricks_destructive_palette[15] = {0x06,0x01,0xff,0xe4,0xb6,0xfe,0x6d,0xa0,0x88,0xf5,0xe0,0xc0,0xa0,0xff,0x00};
static unsigned char bricks_destructive[131] = {
	16,
	16,
	1,
0x8b,0xbb,0xbb,0xb3,0x8b,0xbb,0xbb,0xb3,
0x8c,0xcc,0xcc,0xb3,0x8c,0xcc,0xcc,0xb3,
0x88,0x88,0x88,0xb3,0x88,0x88,0x88,0xb3,
0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,
0xbb,0xb3,0x8b,0xbb,0xbb,0xb3,0x8b,0xbb,
0xcc,0xb3,0x8c,0xcc,0xcc,0xb3,0x8c,0xcc,
0x88,0xb3,0x88,0x88,0x88,0xb3,0x88,0x88,
0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,
0x8b,0xbb,0xbb,0xb3,0x8b,0xbb,0xbb,0xb3,
0x8c,0xcc,0xcc,0xb3,0x8c,0xcc,0xcc,0xb3,
0x88,0x88,0x88,0xb3,0x88,0x88,0x88,0xb3,
0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33,
0xbb,0xb3,0x8b,0xbb,0xbb,0xb3,0x8b,0xbb,
0xcc,0xb3,0x8c,0xcc,0xcc,0xb3,0x8c,0xcc,
0x88,0xb3,0x88,0x88,0x88,0xb3,0x88,0x88,
0x33,0x33,0x33,0x33,0x33,0x33,0x33,0x33};


#endif
