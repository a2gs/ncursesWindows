/* Andre Augusto Giannotti Scota (a2gs)
 * andre.scota@gmail.com
 *
 *
 *
 * MIT License
 *
 */


/*
 *
 *
 *  Who     | When       | What
 *  --------+------------+----------------------------
 *   a2gs   | 13/08/2018 | Creation
 *          |            |
 */


/* *** INCLUDES ************************************************************************ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <ncurses.h>

#include "wizard_by_return.h"


/* *** DEFINES AND LOCAL DATA TYPE DEFINATION ****************************************** */
#define STATUS_BAR_1                         "Connected [%s] User [%s]"
#define STATUS_BAR_2                         "[TAB] Next field | [ESC] Exit"

#define STATUS_BAR_1_LINE_N                  (LINES - 1)
#define STATUS_BAR_1_COL_N(__fmt_bar1_srt__) ((COLS - strlen(__fmt_bar1_srt__))/2)

#define STATUS_BAR_2_LINE_N                  (LINES - 2)
#define STATUS_BAR_2_COL_N                   ((COLS - sizeof(STATUS_BAR_2))/2)

#define FMT_STATUS_BAR_1_SZ                  (100)

#define ESC_KEY                              (27)

#define TOTAL_SCREEN                         (3)

/* *** LOCAL PROTOTYPES (if applicable) ************************************************ */


/* *** EXTERNS / LOCAL / GLOBALS VARIEBLES ********************************************* */


/* *** FUNCTIONS *********************************************************************** */
a2gs_ToolBox_WizardReturnFunc_t screen1(void *data);
a2gs_ToolBox_WizardReturnFunc_t screen2(void *data);
a2gs_ToolBox_WizardReturnFunc_t screen3(void *data);
a2gs_ToolBox_WizardReturnFunc_t screen4(void *data);

/* -------------------------------------------------------------------------------------------------------- */

void drawDefaultStatusBar(void)
{
	char fmt_STATUS_BAR_1[FMT_STATUS_BAR_1_SZ +1] = {0};

	snprintf(fmt_STATUS_BAR_1, FMT_STATUS_BAR_1_SZ, STATUS_BAR_1, "localhost:666", "Unknow");
	mvwprintw(stdscr, STATUS_BAR_1_LINE_N, STATUS_BAR_1_COL_N(fmt_STATUS_BAR_1), fmt_STATUS_BAR_1);
	mvwprintw(stdscr, STATUS_BAR_2_LINE_N, STATUS_BAR_2_COL_N, STATUS_BAR_2);

	refresh();
}

void signalHandle(int sig)
{
	switch(sig){
		case SIGWINCH:
			break;
		default:
			break;
	}
}

a2gs_ToolBox_WizardReturnFunc_t screen4(void *data)
{
	WINDOW *thisScreen = NULL;
	int lineCenter = 0, colCenter = 0;
	char *screenTitle = NULL;
	int thisScreen_maxx = 0, thisScreen_maxy = 0;

	screenTitle = "Title 5";

	lineCenter = LINES/2;
	colCenter = COLS/2;

	clear();
	drawDefaultStatusBar();

	thisScreen = newwin(2+2, 5+5, lineCenter-2, colCenter-5);
	box(thisScreen, 0, 0);

	thisScreen_maxx = getmaxx(thisScreen);
	thisScreen_maxy = getmaxy(thisScreen);

	wattron(thisScreen, A_UNDERLINE);
	mvwprintw(thisScreen, 1, ((thisScreen_maxx - strlen(screenTitle))/2), screenTitle);
	wattroff(thisScreen, A_UNDERLINE);


	/* ... */


	wrefresh(thisScreen);

	getch();

	delwin(thisScreen);

	return(NULL);
}

a2gs_ToolBox_WizardReturnFunc_t screen3(void *data)
{
	WINDOW *thisScreen = NULL;
	int lineCenter = 0, colCenter = 0;
	char *screenTitle = NULL;
	int thisScreen_maxx = 0, thisScreen_maxy = 0;

	screenTitle = "Title 3";

	lineCenter = LINES/2;
	colCenter = COLS/2;

	clear();
	drawDefaultStatusBar();

	thisScreen = newwin(5+5, 10+10, lineCenter-5, colCenter-10);
	box(thisScreen, 0, 0);

	thisScreen_maxx = getmaxx(thisScreen);
	thisScreen_maxy = getmaxy(thisScreen);

	wattron(thisScreen, A_UNDERLINE);
	mvwprintw(thisScreen, 1, ((thisScreen_maxx - strlen(screenTitle))/2), screenTitle);
	wattroff(thisScreen, A_UNDERLINE);


	/* ... */


	wrefresh(thisScreen);

	getch();

	delwin(thisScreen);

	return(screen4);
}

a2gs_ToolBox_WizardReturnFunc_t screen2(void *data)
{
	WINDOW *thisScreen = NULL;
	int lineCenter = 0, colCenter = 0;
	char *screenTitle = NULL;
	int thisScreen_maxx = 0, thisScreen_maxy = 0;

	screenTitle = "Title 2";

	lineCenter = LINES/2;
	colCenter = COLS/2;

	clear();
	drawDefaultStatusBar();

	thisScreen = newwin(10+10, 40+40, lineCenter-10, colCenter-40);
	box(thisScreen, 0, 0);

	thisScreen_maxx = getmaxx(thisScreen);
	thisScreen_maxy = getmaxy(thisScreen);

	wattron(thisScreen, A_UNDERLINE);
	mvwprintw(thisScreen, 1, ((thisScreen_maxx - strlen(screenTitle))/2), screenTitle);
	wattroff(thisScreen, A_UNDERLINE);


	/* ... */


	wrefresh(thisScreen);

	getch();

	delwin(thisScreen);

	return(screen3);
}

a2gs_ToolBox_WizardReturnFunc_t screen1(void *data)
{
	WINDOW *thisScreen = NULL;
	int lineCenter = 0, colCenter = 0;
	char *screenTitle = NULL;
	int thisScreen_maxx = 0, thisScreen_maxy = 0;

	screenTitle = "Title 1";

	lineCenter = LINES/2;
	colCenter = COLS/2;

	clear();
	drawDefaultStatusBar();

	thisScreen = newwin(20+20, 60+60, lineCenter-20, colCenter-60);
	box(thisScreen, 0, 0);

	thisScreen_maxx = getmaxx(thisScreen);
	thisScreen_maxy = getmaxy(thisScreen);

	wattron(thisScreen, A_UNDERLINE);
	mvwprintw(thisScreen, 1, ((thisScreen_maxx - strlen(screenTitle))/2), screenTitle);
	wattroff(thisScreen, A_UNDERLINE);


	/* ... */


	wrefresh(thisScreen);

	getch();

	delwin(thisScreen);

	return(screen2);
}

/* int main(int argc, char *argv[])
 *
 * INPUT:
 * OUTPUT (to SO):
 */
int main(int argc, char *argv[])
{
#define FIELD1_SZ 50
#define FIELD2_SZ 30

	int cursor = 0;

	if(initscr() == NULL){;
		printf("Erro initializating ncurses!\n");
		return(-1);
	}
	keypad(stdscr, TRUE);
	cbreak();
	noecho();

	/* https://invisible-island.net/ncurses/ncurses-intro.html */
	/* signal(SIGWINCH, signalHandle); */
	/* TODO: configurar o SCREEN RESIZE para nao ser recebido como user input: KEY_RESIZE */

	if((LINES < 24) || (COLS < 80)){
		endwin();
		printf("O terminal precisa ter no minimo 80x24");
		return(-2);
	}

	if(has_colors() == FALSE){
		endwin();
		printf("Terminal nao suporta cores (has_colors() = FALSE).\n");
		return(-2);
	}

	if(can_change_color() == FALSE){
		endwin();
		printf("Terminal nao suporta mudar as cores (can_change_colors() = FALSE).\n");
		return(-3);
	}

	if(start_color() != OK){
		endwin();
		printf("Erro em iniciar cores (start_colors() = FALSE).\n");
		return(-4);
	}

	set_escdelay(0);

	cursor = curs_set(0);

	a2gs_ToolBox_WizardReturn(screen1, NULL);

	curs_set(cursor);

	endwin();
	delwin(stdscr);

	return(0);
}
