//Modify this file to change what commands output to your statusbar, and recompile using the make command.

#ifdef LAPTOP_BAR
static const Block blocks[] = {
	/*Icon	/Command				/Update Interval	/Update Signal */
    {" ",	"echo \"$(free -h | awk '/^Mem/ { print $3 }' | sed s/i//g)\"", 1,  0},
	{" ",	"status-cpu",                                                   1,  0},
	{"",	"status-volume",		                                        60, 10},
	{" ",	"light | xargs printf '%.0f\n'",                                60,	11},
	{" ",	"acpi -b | cut -f 2 -d ',' | sed -r 's/( )+//g'",               10, 0},
	{"",	"status-bt",                                                    60, 12},
	{"",	"status-wifi",                                                  5,  4},
	{" ",	"printf \"%s\" \"$(date '+%b %d (%a) %H:%M:%S') \"",            1,  0},
};
#endif

#ifdef DESKTOP_BAR
static const Block blocks[] = {
	/*Icon	/Command				/Update Interval	/Update Signal */
    {" ",	"echo \"$(free -h | awk '/^Mem/ { print $3 }' | sed s/i//g)\"", 1,  0},
	{" ",	"status-cpu",                                                   1,  0},
	{" ",	"printf \"%s\" \"$(date '+%b %d (%a) %H:%M:%S') \"",            1,  0},
};
#endif

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char *delim = " / ";
