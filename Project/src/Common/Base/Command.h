#ifndef _COMMAND_H
#define _COMMAND_H

class Command {

public:

	virtual ~Command() {
	}
	virtual void run() = 0;
};

#endif
