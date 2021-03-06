Computing coefficients for Gauss RK formulas.
============================================

----------
comp1.sage: 
----------
is a Sage (http://www.sagemath.org/) script to generate the 
coefficients of any Gaussian Runge-Kutta formula.

It computes coefficients for nsteps= 2 to 16 (bounds included), where
nsteps is the number of stages of the Gauss formula, and for "double" and
"long double" coefficients. This can be customized.


You can use comp1.sage like this:
```
>sage
sage: load("comp1.sage")
```

The coefficients generated in the form of C++ template functions, templatized
by nsteps and the "field" (double and long double) are written in generated_coeffs.hpp

-----------
compco.sage: 
-----------
is a Sage scripts to generate the coefficients for the starting
algorithm based on extrapolation for nsteps= 2 to 16 (bounds included),
for "double" and "long double" coefficients.

Use it like this:
```
>sage
sage: load("compco.sage")
```
The coefficients generated in the form of C++ template functions, templatized
by nsteps and the "field" (double and long double).

