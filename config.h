//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
	//{" ₿ ", "~/code/crypto-cli/target/release/crypto-cli btcusdt", 60, 0},
	//{" Ξ ", "~/code/crypto-cli/target/release/crypto-cli ethusdt", 60, 0},
	//{" Ł ", "~/code/crypto-cli/target/release/crypto-cli ltcusdt", 60, 0},
	//{" ₳ ", "~/code/crypto-cli/target/release/crypto-cli adausdt", 60, 0},
    {" ", "echo \"$(free -h | awk '/^Mem/ { print $3\"/\"$2 }' | sed s/i//g)\"",	1,		0},
	{" ", "echo \"$(mpstat | awk '$12 ~ /[0-9.]+/ { print 100 - $13 }')\"%", 1, 0},
	{" ", "~/bin/audio-control current",					60,		10},
	{" ", "date '+%b %d (%a) %H:%M:%S'",					1,		0},
	{"", "~/.config/dwmblocks/modules/internet",					5,		4},
	{" ", "acpi -b | cut -f 2 -d ',' | sed -r 's/( )+//g'",					10,		0},
	{" ", "",					0,		0}, // for right padding
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char *delim = " ";
