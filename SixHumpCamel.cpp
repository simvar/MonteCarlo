/*
 * SixHumpCamel.cpp
 *
 * Code generation for function 'SixHumpCamel'
 *
 * C source code generated on: Tue Dec 18 17:51:31 2012
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "SixHumpCamel.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static real_T rt_powd_snf(real_T u0, real_T u1);

/* Function Definitions */
static real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T d0;
  real_T d1;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = rtNaN;
  } else {
    d0 = fabs(u0);
    d1 = fabs(u1);
    if (rtIsInf(u1)) {
      if (d0 == 1.0) {
        y = rtNaN;
      } else if (d0 > 1.0) {
        if (u1 > 0.0) {
          y = rtInf;
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = rtInf;
      }
    } else if (d1 == 0.0) {
      y = 1.0;
    } else if (d1 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = rtNaN;
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

real_T SixHumpCamel(real_T x[2])
{
  return (((4.0 - 2.1 * rt_powd_snf(x[0], 2.0)) + 0.33333333333333331 *
           rt_powd_snf(x[0], 4.0)) * rt_powd_snf(x[0], 2.0) + x[0] * x[1]) +
    (-4.0 + 4.0 * rt_powd_snf(x[1], 2.0)) * rt_powd_snf(x[1], 2.0);
}

/* End of code generation (SixHumpCamel.cpp) */
