
/*
 * Rkfun.h
 *
 *  Created on: Aug 2, 2016
 *      Author: Devils
 */
#include <armadillo>
#include <vector>
#ifndef RKFUN_H_
#define RKFUN_H_

class Rkfun {
public:
	arma::vec nextStep(double t,arma::vec x);
	arma::vec fval(double t,arma::vec x);
	Rkfun();
	Rkfun(double h,double gamma,double tf,arma::vec x);
	virtual ~Rkfun();
	std::vector<double> t;
	std::vector<arma::vec> y;

private:
	double h;
	double gamma;
};

/* namespace std */

#endif /* RKFUN_H_ */
