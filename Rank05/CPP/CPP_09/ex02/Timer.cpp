#include "include/Timer.hpp"

#include <ctime>
#include <unistd.h>

/************************* ORTHODOX CANONICAL FORM ****************************/

Timer::Timer() {start();}

Timer::Timer(const Timer &other) : _start(other._start) {}

Timer& Timer::operator=(const Timer &other) {
	if (this != &other)
		_start = other._start;
	return (*this);
}

Timer::~Timer() {}

/***************************** MEMBER FUNCTIONS *******************************/

void	Timer::start()
{
	clock_gettime(CLOCK_MONOTONIC, &_start);
}

double	Timer::stop()
{
	struct timespec end;
	
	clock_gettime(CLOCK_MONOTONIC, &end);
	time_t	seconds = end.tv_sec - _start.tv_sec;
	time_t	nanoseconds = end.tv_nsec - _start.tv_nsec;

	if (nanoseconds < 0)
	{
		seconds--;
		nanoseconds += 1000000000;
	}

	double microseconds = seconds * 1000000 + nanoseconds * 0.001;
	return (microseconds);
}
