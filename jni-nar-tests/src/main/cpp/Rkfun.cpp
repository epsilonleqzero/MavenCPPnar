
/*
 * Rkfun.cpp
 *
 *  Created on: Aug 2, 2016
 *      Author: Devils
 */

#include "Rkfun.h"
#include <cmath>

using namespace std;
using namespace arma;

Rkfun::Rkfun() {
	h=0.5;
	gamma=1;
}

Rkfun::Rkfun(double gamma,double h,double tf,vec x) {
	this->h=h;
	this->gamma=gamma;
	vec y1=x;
	t.push_back(0);
	y.push_back(y1);
	double tcurr=t[0]+h;
	int i=1;
	while(tcurr<=tf){
		y1=nextStep(t[i-1], y[i-1]);
		tcurr=t[i-1]+h;
		t.push_back(tcurr);
		y.push_back(y1);
		i++;
	}
}

vec Rkfun::fval(double t,vec x){
	vec u=zeros<vec>(2);
	u(0)=x(1);
	u(1)=x(0)-pow(x(0),3)-gamma*x(1);
	return u;
}

vec Rkfun::nextStep(double t, vec x){
	vec y1=zeros<vec>(2);
	vec k1=fval(t,x)*h;
	vec k2=fval(t+h/2,x+k1/2)*h;
	vec k3=fval(t+h/2,x+k2/2)*h;
	vec k4=fval(t+h,x+k3)*h;
	y1=x+(k1/6)+(k2/3)+(k3/3)+(k4/6);
	return y1;
}

Rkfun::~Rkfun() {

}

/* namespace std */
