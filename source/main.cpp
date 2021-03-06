#include <3ds.h>
#include <stdio.h>

#include "menu.h"
#include "util.h"

void process_dumper();
void address_space_info();

static const char* module_names[] = {
	"Process Dumper",
	"Address Space Info",
};

int main(int argc, char** argv)
{
	gfxInitDefault();
	consoleInit(GFX_TOP, NULL);

	while (true) {
		int selection = do_simple_menu("Please select a demo/tool:\n", module_names, ARRAY_LEN(module_names));
		if (selection == -1)
			break;

		switch (selection) {
			case 0: process_dumper(); break;
			case 1: address_space_info(); break;
		}
		fprintf(stdout, "\nPress any key to return to menu.\n");
		wait_input();
	}

	gfxExit();
	return 0;
}
