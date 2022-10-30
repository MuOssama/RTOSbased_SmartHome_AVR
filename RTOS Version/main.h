/*
 * main.h
 *
 *  Created on: Aug 1, 2022
 *      Author: Mustapha
 */

#ifndef MAIN_H_
#define MAIN_H_
#include "Config.h"
#include "MCAL/DIO/DIO_INTERFACE.H"
#include "MCAL/DIO/DIO_REG.H"

/***********************************************************/
/******************    Command Codes    ********************/
/***********************************************************/
char shutdoor[5] = "Shut",
	 opendoor[5] = "Open",
	 heavyload1[5] = "HL1T",
	 heavyload2[5] = "HL2T",
	 heavyload3[5] = "HL3T",
	 heavyload4[5] = "HL4T",
	 heavyloadALLOFF[5] = "AOFF";


struct user {
	char username[5];
	char password[5];
};

struct user users[10] = {
		{ "Ahmd", "9991" },
		{ "Mstf", "9919" },
		{ "Isla","9911" },
		{ "Yosf", "9199" },
		{ "Amir", "9199" },
		{ "Omar", "9119" },
		{"Sami", "9111" },
		{ "Saed", "1999" },
		{ "Amar", "1991" },
		{ "Mhmd","1919" }};


#endif /* MAIN_H_ */
