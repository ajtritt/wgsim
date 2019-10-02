#include <stdio.h>
#include <time.h>
#include <stdarg.h>

void logmsg(const char * format,...) {
    char timebuf[32];
    time_t now = time(0);
    strftime(timebuf, 32, "%Y-%m-%d %H:%M:%S.000", localtime(&now));
    char format2[256];
    snprintf(format2, 256, "%s - %s\n", timebuf, format);
    format = format2;
    va_list args;
    va_start (args, format);
    vfprintf (stderr, format, args);
    va_end (args);
}

