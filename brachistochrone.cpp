// find the vector of del u's that satisfies convergence tolerance
// and use that vector to find the time of travel

#include <iostream>
#include <cmath>

using namespace std;

// decalration of functions
double GetOptTime(double x0, double u0, double xn, double un);

// initialize set of starting and ending points
double x0 = sin(0);
double u0 = 0.25;
double xn = M_PI/2.;
double un = 1.;
double dx = (xn-x0)/100.
int brachistochrone()
{



	cout << "Minimum time to travel between ("
		<< x0 <<"," << u0 << ") and ("
		<< xn << ","<< un << ") : "
		<< GetOptTime(x0,u0,xn,un) << endl;
	return 0;
}

// tridiagonal matrix algorithm to get the optimal time
double GetOptTime(double x0, double u0, double xn, double un)
{


return x0+u0+xn+un; // dummy return value
}

// returns true if convergence tolerance has reached
bool IsConverged(double n2, double n1)
{
	if(abs(n2-n1) <= 1e-8) return 1;
	else return 0;
}

// 1] function to return f_j+(1/2) // 
double Get_f_jPlusHalf(double uj, double ujPlus1)
{
	return 2.*((1.+(1/(dx*dx))*(ujPlus1*ujPlus1 - 2.*uj*ujPlus1+uj*uj))/(uj + ujPlus1));
}

// 2] function to return (del^2t_(j+1/2))/(delu^2_j) // uses 1, 5 and 6
double d2tdu2(double uj, double ujPlus1)
{
return (-1./4.)*pow(Get_f_jPlusHalf(uj, ujPlus1),-3./2.)*pow(d_f_jPlusHalfByd_u_j(uj, ujPlus1, dx),2.) 
	+ (1./(2.*sqrt(f_jPlusHalf)))*d2fBydu2(uj, ujPlus1, dx); 
}

// 3] function to return (del^2t_(j+1/2))/(delu^2_(j+1)) // uses 1, 8 and 9
double d2tdu2_jPlus1(double uj, double ujPlus1)
{
return (-1./4.)*pow(Get_f_jPlusHalf(uj, ujPlus1),-3./2.)*pow(d_f_jPlusHalfByd_u_jPlus1(uj, ujPlus1, dx),2.) // TODO check if this is right
	+ (1./(2.*sqrt(Get_f_jPlusHalf(uj, ujPlus1))))*d2fBydu2_jPlus1(uj, ujPlus1, dx) ;
}

// 4] function to return (del^2t_(j+1/2))/(delu_j_times_delu_(j+1)) // uses 1, 5, 7 and 8
double d2tduj_dujPlus1(double uj, double ujPlus1)
{
return (-1./4.)*pow(Get_f_jPlusHalf(uj, ujPlus1),-3./2.)* d_f_jPlusHalfByd_u_j(uj, ujPlus1, dx) * d_f_jPlusHalfByd_u_jPlus1(uj, ujPlus1, dx) // verified
	+ (1./(2.*sqrt(Get_f_jPlusHalf(uj, ujPlus1))))*d2fBydu_j_du_jPlus1(uj, ujPlus1, dx) ;
}

// 5] function of 1
double d_f_jPlusHalfByd_u_j(double uj, double ujPlus1, double dx) // verified
{
return -Get_f_jPlusHalf(uj, ujPlus1)/(uj + ujPlus1) - 4.*(ujPlus1 - uj)/(dx*dx*(uj + ujPus1));
}

// 6] function of 1
double d2fBydu2(double uj, double ujPlus1, double dx) // verified
{
return (1./pow(uj + ujPlus1,2.))*(2*Get_f_jPlusHalf(uj, ujPlus1) + (12.*ujPlus1 - 4*uj)/(dx*dx));
}

// 7] function of 1
double d2fBydu_j_du_jPlus1(double uj, double ujPlus1, double dx)// verified
{
return (1./pow(uj + ujPlus1,2.))*(2*Get_f_jPlusHalf(uj, ujPlus1) - 4.*(ujPlus1 + uj)/(dx*dx));
}


// 8] function of 1
double d_f_jPlusHalfByd_u_jPlus1(double uj, double ujPlus1, double dx) // verified
{
return -Get_f_jPlusHalf(uj, ujPlus1)/(uj + ujPlus1) + 4.*(ujPlus1 - uj)/(dx*dx*(uj + ujPus1));
}

// 9] function of 1
double d2fBydu2_jPlus1(double uj, double ujPlus1, double dx)// verified
{
return (1./pow(uj + ujPlus1,2.))*(2*Get_f_jPlusHalf(uj, ujPlus1) + (12.*uj - 4*ujPlus1)/(dx*dx));
}

// TODO created functions 1 through 9, need to verify 2,3 and 4
