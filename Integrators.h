/*
 * Integrators.h
 *
 *  Created on: Oct 15, 2015
 *      Author: thomas
 */

#ifndef INTEGRATORS_H_
#define INTEGRATORS_H_

#include "nbsys.h"

class Integrator {
public:
	nbsys *nbs;		// N-body system.
	double dt;
	double *rx_next, *ry_next, *rz_next, *vx_next, *vy_next, *vz_next; 	// Position, velocity and acceleration components.

	Integrator(std::string filename);
	virtual ~Integrator();

	virtual void iterate() = 0;		// Iterate once.
};

class Euler: public Integrator {
public:

	Euler(std::string filename, double dt);
	virtual ~Euler();

	void iterate();
	void iterate_ind(int i);
};

class Euler_Comer: public Integrator {
public:

	Euler_Comer(std::string filename, double dt);
	virtual ~Euler_Comer();

	void iterate();
	void iterate_ind(int i);
};

#endif /* INTEGRATORS_H_ */