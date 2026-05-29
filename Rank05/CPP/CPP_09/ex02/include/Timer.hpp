#ifndef TIMER_HPP
#define TIMER_HPP

#include <ctime>
class Timer
{
	private:
		struct timespec	_start;

	public:
		Timer();
		Timer(const Timer &other);
		Timer &operator=(const Timer &other);
		~Timer();

		void	start();
		double	stop();
};

#endif
