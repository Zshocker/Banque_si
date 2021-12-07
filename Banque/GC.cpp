#include "GC.h"

GC::GC(int i)
{
	this->compt = i;
}

void GC::incre()
{
	this->compt = this->compt + 1;
}

int GC::decr()
{
	this->compt = this->compt - 1;
	return this->compt;
}
