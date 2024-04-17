
#include "utilities.h"

long map(long x, long in_min, long in_max, long out_min, long out_max) {

	return (x - in_min) * (out_max - out_min + 1) / (in_max - in_min + 1)
			+ out_min;
}
void clearMSG(char *msg,short *msgIDX) {
	*msgIDX = 0;
	memset(msg, '\0', strlen(msg));
}
