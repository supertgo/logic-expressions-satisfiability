#ifndef TIMEEDH
#define TIMEEDH

#include <sys/resource.h>
#include <sys/time.h>

double clock_time(struct timespec *start, struct timespec *end);
float user_time(struct rusage *start, struct rusage *end);
float system_time(struct rusage *start, struct rusage *end);

#endif
