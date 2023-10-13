#include <sys/resource.h>
#include <sys/time.h>
#include "timeed.h"

double clock_time(struct timespec *start, struct timespec *end) {
  return (end->tv_sec - start->tv_sec) + 1e-9 * (end->tv_nsec - start->tv_nsec);
}

float user_time(struct rusage *start, struct rusage *end) {
  return (end->ru_utime.tv_sec - start->ru_utime.tv_sec) +
         1e-6 * (end->ru_utime.tv_usec - start->ru_utime.tv_usec);
}

float system_time(struct rusage *start, struct rusage *end) {
  return (end->ru_stime.tv_sec - start->ru_stime.tv_sec) +
         1e-6 * (end->ru_stime.tv_usec - start->ru_stime.tv_usec);
}
