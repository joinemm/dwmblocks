//Modify this file to change what commands output to your statusbar, and recompile using the make command.

#ifdef laptop
static const Block blocks[] = {
	/*Icon	/Command				            /Interval   /Update Signal */
	{" ",	"free -h | awk '/^Mem/ {print $3}'",1,          1},
	{" ",	"status-cpu",                       1,          1},
	{"",	"status-volume",                    30,         10},
	{" ",	"light -r",                         30,         11},
    {"",	"status-battery",                   1,          1},
	{"",	"status-bt",                        30,         12},
	{"",	"status-wifi",                      1,          14},
	{"",	"status-layout",                    1,          13},
	{" ",	"date '+%b %d (%a) %H:%M:%S'",      1,          1},
};
#endif

#ifdef desktop
static const Block blocks[] = {
	/*Icon	/Command				            /Interval	/Update Signal */
    {" ",  "status-mic-volume",                1,          1},
    {" ",	"free -h | awk '/^Mem/ {print $3}'",1,          1},
	{" ",	"status-cpu",                       1,          1},
	{"",	"status-layout",                    1,          13},
	{" ",	"date '+%b %d (%a) %H:%M:%S'",      1,          1},
};
#endif

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char *delim = " / ";
