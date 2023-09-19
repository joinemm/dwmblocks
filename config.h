//Modify this file to change what commands output to your statusbar, and recompile using the make command.

#ifdef laptop
static const Block blocks[] = {
	/*Icon	/Command				            /Interval   /Update Signal */
	{"",	"status-wifi",                      1,          14},
	{"",	"status-bt",						30,         12},
	{"󰆼 ",	"status-memory",					1,          1},
	{" ",	"status-cpu",                       1,          2},
	{"",	"status-volume",                    30,         10},
	{" ",	"status-backlight",					30,         11},
    {"",	"status-battery",                   1,          3},
	{"",	"status-layout",                    1,          13},
	{"󰃭 ",	"status-date",						1,          4},
};
#endif

#ifdef desktop
static const Block blocks[] = {
	/*Icon	/Command				            /Interval	/Update Signal */
    {" ",  "status-mic-volume",                1,			1},
	{"",	"status-volume",                    30,         10},
    {"󰆼 ",	"status-memory",					1,          2},
	{" ",	"status-cpu",                       1,          3},
	{"",	"status-network-traffic",			1,          15},
	{"",	"status-layout",                    1,          13},
	{"󰃭 ",	"status-date",						1,          4},
};
#endif

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char *delim = " | ";
