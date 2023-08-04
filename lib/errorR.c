/*
 * File: errorR.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 02-Jul-2023 23:57:30
 */

/* Include Files */
#include "errorR.h"

/* Function Definitions */
/*
 * Arguments    : const double R[9]
 *                const double Rdes[9]
 *                double out[3]
 * Return Type  : void
 */
void errorR(const double R[9], const double Rdes[9], double out[3])
{
  double b_R[9];
  double eR[9];
  int i;
  int i3;
  for (i = 0; i < 3; i++) {
    int i1;
    int i2;
    i1 = 3 * i + 1;
    i2 = 3 * i + 2;
    for (i3 = 0; i3 < 3; i3++) {
      int R_tmp;
      int i4;
      int i5;
      i4 = 3 * i3 + 1;
      i5 = 3 * i3 + 2;
      R_tmp = i + 3 * i3;
      b_R[R_tmp] =
          (R[3 * i] * Rdes[3 * i3] + R[i1] * Rdes[i4]) + R[i2] * Rdes[i5];
      eR[R_tmp] =
          (Rdes[3 * i] * R[3 * i3] + Rdes[i1] * R[i4]) + Rdes[i2] * R[i5];
    }
  }
  for (i = 0; i < 9; i++) {
    eR[i] = 0.5 * (eR[i] - b_R[i]);
  }
  out[0] = eR[5];
  out[1] = eR[6];
  out[2] = eR[1];
}

/*
 * File trailer for errorR.c
 *
 * [EOF]
 */
