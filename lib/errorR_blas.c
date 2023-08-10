/*
 * File: errorR_blas.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 09-Aug-2023 21:27:41
 */

/* Include Files */
#include "errorR_blas.h"

/* Function Definitions */
/*
 * Arguments    : const double R[9]
 *                const double Rdes[9]
 *                double eR[3]
 * Return Type  : void
 */
void errorR_blas(const double R[9], const double Rdes[9], double eR[3])
{
  double A[9];
  double b_R[9];
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
      A[R_tmp] =
          (Rdes[3 * i] * R[3 * i3] + Rdes[i1] * R[i4]) + Rdes[i2] * R[i5];
    }
  }
  for (i = 0; i < 9; i++) {
    A[i] -= b_R[i];
  }
  eR[0] = 0.5 * A[5];
  eR[1] = 0.5 * A[6];
  eR[2] = 0.5 * A[1];
}

/*
 * File trailer for errorR_blas.c
 *
 * [EOF]
 */
