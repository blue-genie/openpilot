#include "gnss.h"

namespace {
#define DIM 11
#define EDIM 11
#define MEDIM 11
typedef void (*Hfun)(double *, double *, double *);
const static double MAHA_THRESH_6 = 3.8414588206941227;
const static double MAHA_THRESH_20 = 3.8414588206941227;
const static double MAHA_THRESH_7 = 3.8414588206941227;
const static double MAHA_THRESH_21 = 3.8414588206941227;

/******************************************************************************
 *                       Code generated with SymPy 1.12                       *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_4146341528858007965) {
   out_4146341528858007965[0] = delta_x[0] + nom_x[0];
   out_4146341528858007965[1] = delta_x[1] + nom_x[1];
   out_4146341528858007965[2] = delta_x[2] + nom_x[2];
   out_4146341528858007965[3] = delta_x[3] + nom_x[3];
   out_4146341528858007965[4] = delta_x[4] + nom_x[4];
   out_4146341528858007965[5] = delta_x[5] + nom_x[5];
   out_4146341528858007965[6] = delta_x[6] + nom_x[6];
   out_4146341528858007965[7] = delta_x[7] + nom_x[7];
   out_4146341528858007965[8] = delta_x[8] + nom_x[8];
   out_4146341528858007965[9] = delta_x[9] + nom_x[9];
   out_4146341528858007965[10] = delta_x[10] + nom_x[10];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_7655543901485109526) {
   out_7655543901485109526[0] = -nom_x[0] + true_x[0];
   out_7655543901485109526[1] = -nom_x[1] + true_x[1];
   out_7655543901485109526[2] = -nom_x[2] + true_x[2];
   out_7655543901485109526[3] = -nom_x[3] + true_x[3];
   out_7655543901485109526[4] = -nom_x[4] + true_x[4];
   out_7655543901485109526[5] = -nom_x[5] + true_x[5];
   out_7655543901485109526[6] = -nom_x[6] + true_x[6];
   out_7655543901485109526[7] = -nom_x[7] + true_x[7];
   out_7655543901485109526[8] = -nom_x[8] + true_x[8];
   out_7655543901485109526[9] = -nom_x[9] + true_x[9];
   out_7655543901485109526[10] = -nom_x[10] + true_x[10];
}
void H_mod_fun(double *state, double *out_2206412795536377560) {
   out_2206412795536377560[0] = 1.0;
   out_2206412795536377560[1] = 0;
   out_2206412795536377560[2] = 0;
   out_2206412795536377560[3] = 0;
   out_2206412795536377560[4] = 0;
   out_2206412795536377560[5] = 0;
   out_2206412795536377560[6] = 0;
   out_2206412795536377560[7] = 0;
   out_2206412795536377560[8] = 0;
   out_2206412795536377560[9] = 0;
   out_2206412795536377560[10] = 0;
   out_2206412795536377560[11] = 0;
   out_2206412795536377560[12] = 1.0;
   out_2206412795536377560[13] = 0;
   out_2206412795536377560[14] = 0;
   out_2206412795536377560[15] = 0;
   out_2206412795536377560[16] = 0;
   out_2206412795536377560[17] = 0;
   out_2206412795536377560[18] = 0;
   out_2206412795536377560[19] = 0;
   out_2206412795536377560[20] = 0;
   out_2206412795536377560[21] = 0;
   out_2206412795536377560[22] = 0;
   out_2206412795536377560[23] = 0;
   out_2206412795536377560[24] = 1.0;
   out_2206412795536377560[25] = 0;
   out_2206412795536377560[26] = 0;
   out_2206412795536377560[27] = 0;
   out_2206412795536377560[28] = 0;
   out_2206412795536377560[29] = 0;
   out_2206412795536377560[30] = 0;
   out_2206412795536377560[31] = 0;
   out_2206412795536377560[32] = 0;
   out_2206412795536377560[33] = 0;
   out_2206412795536377560[34] = 0;
   out_2206412795536377560[35] = 0;
   out_2206412795536377560[36] = 1.0;
   out_2206412795536377560[37] = 0;
   out_2206412795536377560[38] = 0;
   out_2206412795536377560[39] = 0;
   out_2206412795536377560[40] = 0;
   out_2206412795536377560[41] = 0;
   out_2206412795536377560[42] = 0;
   out_2206412795536377560[43] = 0;
   out_2206412795536377560[44] = 0;
   out_2206412795536377560[45] = 0;
   out_2206412795536377560[46] = 0;
   out_2206412795536377560[47] = 0;
   out_2206412795536377560[48] = 1.0;
   out_2206412795536377560[49] = 0;
   out_2206412795536377560[50] = 0;
   out_2206412795536377560[51] = 0;
   out_2206412795536377560[52] = 0;
   out_2206412795536377560[53] = 0;
   out_2206412795536377560[54] = 0;
   out_2206412795536377560[55] = 0;
   out_2206412795536377560[56] = 0;
   out_2206412795536377560[57] = 0;
   out_2206412795536377560[58] = 0;
   out_2206412795536377560[59] = 0;
   out_2206412795536377560[60] = 1.0;
   out_2206412795536377560[61] = 0;
   out_2206412795536377560[62] = 0;
   out_2206412795536377560[63] = 0;
   out_2206412795536377560[64] = 0;
   out_2206412795536377560[65] = 0;
   out_2206412795536377560[66] = 0;
   out_2206412795536377560[67] = 0;
   out_2206412795536377560[68] = 0;
   out_2206412795536377560[69] = 0;
   out_2206412795536377560[70] = 0;
   out_2206412795536377560[71] = 0;
   out_2206412795536377560[72] = 1.0;
   out_2206412795536377560[73] = 0;
   out_2206412795536377560[74] = 0;
   out_2206412795536377560[75] = 0;
   out_2206412795536377560[76] = 0;
   out_2206412795536377560[77] = 0;
   out_2206412795536377560[78] = 0;
   out_2206412795536377560[79] = 0;
   out_2206412795536377560[80] = 0;
   out_2206412795536377560[81] = 0;
   out_2206412795536377560[82] = 0;
   out_2206412795536377560[83] = 0;
   out_2206412795536377560[84] = 1.0;
   out_2206412795536377560[85] = 0;
   out_2206412795536377560[86] = 0;
   out_2206412795536377560[87] = 0;
   out_2206412795536377560[88] = 0;
   out_2206412795536377560[89] = 0;
   out_2206412795536377560[90] = 0;
   out_2206412795536377560[91] = 0;
   out_2206412795536377560[92] = 0;
   out_2206412795536377560[93] = 0;
   out_2206412795536377560[94] = 0;
   out_2206412795536377560[95] = 0;
   out_2206412795536377560[96] = 1.0;
   out_2206412795536377560[97] = 0;
   out_2206412795536377560[98] = 0;
   out_2206412795536377560[99] = 0;
   out_2206412795536377560[100] = 0;
   out_2206412795536377560[101] = 0;
   out_2206412795536377560[102] = 0;
   out_2206412795536377560[103] = 0;
   out_2206412795536377560[104] = 0;
   out_2206412795536377560[105] = 0;
   out_2206412795536377560[106] = 0;
   out_2206412795536377560[107] = 0;
   out_2206412795536377560[108] = 1.0;
   out_2206412795536377560[109] = 0;
   out_2206412795536377560[110] = 0;
   out_2206412795536377560[111] = 0;
   out_2206412795536377560[112] = 0;
   out_2206412795536377560[113] = 0;
   out_2206412795536377560[114] = 0;
   out_2206412795536377560[115] = 0;
   out_2206412795536377560[116] = 0;
   out_2206412795536377560[117] = 0;
   out_2206412795536377560[118] = 0;
   out_2206412795536377560[119] = 0;
   out_2206412795536377560[120] = 1.0;
}
void f_fun(double *state, double dt, double *out_1052288441262299862) {
   out_1052288441262299862[0] = dt*state[3] + state[0];
   out_1052288441262299862[1] = dt*state[4] + state[1];
   out_1052288441262299862[2] = dt*state[5] + state[2];
   out_1052288441262299862[3] = state[3];
   out_1052288441262299862[4] = state[4];
   out_1052288441262299862[5] = state[5];
   out_1052288441262299862[6] = dt*state[7] + state[6];
   out_1052288441262299862[7] = dt*state[8] + state[7];
   out_1052288441262299862[8] = state[8];
   out_1052288441262299862[9] = state[9];
   out_1052288441262299862[10] = state[10];
}
void F_fun(double *state, double dt, double *out_1013371314315383813) {
   out_1013371314315383813[0] = 1;
   out_1013371314315383813[1] = 0;
   out_1013371314315383813[2] = 0;
   out_1013371314315383813[3] = dt;
   out_1013371314315383813[4] = 0;
   out_1013371314315383813[5] = 0;
   out_1013371314315383813[6] = 0;
   out_1013371314315383813[7] = 0;
   out_1013371314315383813[8] = 0;
   out_1013371314315383813[9] = 0;
   out_1013371314315383813[10] = 0;
   out_1013371314315383813[11] = 0;
   out_1013371314315383813[12] = 1;
   out_1013371314315383813[13] = 0;
   out_1013371314315383813[14] = 0;
   out_1013371314315383813[15] = dt;
   out_1013371314315383813[16] = 0;
   out_1013371314315383813[17] = 0;
   out_1013371314315383813[18] = 0;
   out_1013371314315383813[19] = 0;
   out_1013371314315383813[20] = 0;
   out_1013371314315383813[21] = 0;
   out_1013371314315383813[22] = 0;
   out_1013371314315383813[23] = 0;
   out_1013371314315383813[24] = 1;
   out_1013371314315383813[25] = 0;
   out_1013371314315383813[26] = 0;
   out_1013371314315383813[27] = dt;
   out_1013371314315383813[28] = 0;
   out_1013371314315383813[29] = 0;
   out_1013371314315383813[30] = 0;
   out_1013371314315383813[31] = 0;
   out_1013371314315383813[32] = 0;
   out_1013371314315383813[33] = 0;
   out_1013371314315383813[34] = 0;
   out_1013371314315383813[35] = 0;
   out_1013371314315383813[36] = 1;
   out_1013371314315383813[37] = 0;
   out_1013371314315383813[38] = 0;
   out_1013371314315383813[39] = 0;
   out_1013371314315383813[40] = 0;
   out_1013371314315383813[41] = 0;
   out_1013371314315383813[42] = 0;
   out_1013371314315383813[43] = 0;
   out_1013371314315383813[44] = 0;
   out_1013371314315383813[45] = 0;
   out_1013371314315383813[46] = 0;
   out_1013371314315383813[47] = 0;
   out_1013371314315383813[48] = 1;
   out_1013371314315383813[49] = 0;
   out_1013371314315383813[50] = 0;
   out_1013371314315383813[51] = 0;
   out_1013371314315383813[52] = 0;
   out_1013371314315383813[53] = 0;
   out_1013371314315383813[54] = 0;
   out_1013371314315383813[55] = 0;
   out_1013371314315383813[56] = 0;
   out_1013371314315383813[57] = 0;
   out_1013371314315383813[58] = 0;
   out_1013371314315383813[59] = 0;
   out_1013371314315383813[60] = 1;
   out_1013371314315383813[61] = 0;
   out_1013371314315383813[62] = 0;
   out_1013371314315383813[63] = 0;
   out_1013371314315383813[64] = 0;
   out_1013371314315383813[65] = 0;
   out_1013371314315383813[66] = 0;
   out_1013371314315383813[67] = 0;
   out_1013371314315383813[68] = 0;
   out_1013371314315383813[69] = 0;
   out_1013371314315383813[70] = 0;
   out_1013371314315383813[71] = 0;
   out_1013371314315383813[72] = 1;
   out_1013371314315383813[73] = dt;
   out_1013371314315383813[74] = 0;
   out_1013371314315383813[75] = 0;
   out_1013371314315383813[76] = 0;
   out_1013371314315383813[77] = 0;
   out_1013371314315383813[78] = 0;
   out_1013371314315383813[79] = 0;
   out_1013371314315383813[80] = 0;
   out_1013371314315383813[81] = 0;
   out_1013371314315383813[82] = 0;
   out_1013371314315383813[83] = 0;
   out_1013371314315383813[84] = 1;
   out_1013371314315383813[85] = dt;
   out_1013371314315383813[86] = 0;
   out_1013371314315383813[87] = 0;
   out_1013371314315383813[88] = 0;
   out_1013371314315383813[89] = 0;
   out_1013371314315383813[90] = 0;
   out_1013371314315383813[91] = 0;
   out_1013371314315383813[92] = 0;
   out_1013371314315383813[93] = 0;
   out_1013371314315383813[94] = 0;
   out_1013371314315383813[95] = 0;
   out_1013371314315383813[96] = 1;
   out_1013371314315383813[97] = 0;
   out_1013371314315383813[98] = 0;
   out_1013371314315383813[99] = 0;
   out_1013371314315383813[100] = 0;
   out_1013371314315383813[101] = 0;
   out_1013371314315383813[102] = 0;
   out_1013371314315383813[103] = 0;
   out_1013371314315383813[104] = 0;
   out_1013371314315383813[105] = 0;
   out_1013371314315383813[106] = 0;
   out_1013371314315383813[107] = 0;
   out_1013371314315383813[108] = 1;
   out_1013371314315383813[109] = 0;
   out_1013371314315383813[110] = 0;
   out_1013371314315383813[111] = 0;
   out_1013371314315383813[112] = 0;
   out_1013371314315383813[113] = 0;
   out_1013371314315383813[114] = 0;
   out_1013371314315383813[115] = 0;
   out_1013371314315383813[116] = 0;
   out_1013371314315383813[117] = 0;
   out_1013371314315383813[118] = 0;
   out_1013371314315383813[119] = 0;
   out_1013371314315383813[120] = 1;
}
void h_6(double *state, double *sat_pos, double *out_281823431389829657) {
   out_281823431389829657[0] = sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2)) + state[6];
}
void H_6(double *state, double *sat_pos, double *out_529963587596744022) {
   out_529963587596744022[0] = (-sat_pos[0] + state[0])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_529963587596744022[1] = (-sat_pos[1] + state[1])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_529963587596744022[2] = (-sat_pos[2] + state[2])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_529963587596744022[3] = 0;
   out_529963587596744022[4] = 0;
   out_529963587596744022[5] = 0;
   out_529963587596744022[6] = 1;
   out_529963587596744022[7] = 0;
   out_529963587596744022[8] = 0;
   out_529963587596744022[9] = 0;
   out_529963587596744022[10] = 0;
}
void h_20(double *state, double *sat_pos, double *out_7332534737645198155) {
   out_7332534737645198155[0] = sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2)) + sat_pos[3]*state[10] + state[6] + state[9];
}
void H_20(double *state, double *sat_pos, double *out_1063331478846045498) {
   out_1063331478846045498[0] = (-sat_pos[0] + state[0])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_1063331478846045498[1] = (-sat_pos[1] + state[1])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_1063331478846045498[2] = (-sat_pos[2] + state[2])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_1063331478846045498[3] = 0;
   out_1063331478846045498[4] = 0;
   out_1063331478846045498[5] = 0;
   out_1063331478846045498[6] = 1;
   out_1063331478846045498[7] = 0;
   out_1063331478846045498[8] = 0;
   out_1063331478846045498[9] = 1;
   out_1063331478846045498[10] = sat_pos[3];
}
void h_7(double *state, double *sat_pos_vel, double *out_2678422718282197825) {
   out_2678422718282197825[0] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + state[7];
}
void H_7(double *state, double *sat_pos_vel, double *out_606349518386968416) {
   out_606349518386968416[0] = pow(sat_pos_vel[0] - state[0], 2)*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_606349518386968416[1] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[1] - state[1], 2)*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_606349518386968416[2] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[2] - state[2], 2)*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_606349518386968416[3] = -(sat_pos_vel[0] - state[0])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_606349518386968416[4] = -(sat_pos_vel[1] - state[1])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_606349518386968416[5] = -(sat_pos_vel[2] - state[2])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_606349518386968416[6] = 0;
   out_606349518386968416[7] = 1;
   out_606349518386968416[8] = 0;
   out_606349518386968416[9] = 0;
   out_606349518386968416[10] = 0;
}
void h_21(double *state, double *sat_pos_vel, double *out_2678422718282197825) {
   out_2678422718282197825[0] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + state[7];
}
void H_21(double *state, double *sat_pos_vel, double *out_606349518386968416) {
   out_606349518386968416[0] = pow(sat_pos_vel[0] - state[0], 2)*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_606349518386968416[1] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[1] - state[1], 2)*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_606349518386968416[2] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[2] - state[2], 2)*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_606349518386968416[3] = -(sat_pos_vel[0] - state[0])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_606349518386968416[4] = -(sat_pos_vel[1] - state[1])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_606349518386968416[5] = -(sat_pos_vel[2] - state[2])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_606349518386968416[6] = 0;
   out_606349518386968416[7] = 1;
   out_606349518386968416[8] = 0;
   out_606349518386968416[9] = 0;
   out_606349518386968416[10] = 0;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void gnss_update_6(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_6, H_6, NULL, in_z, in_R, in_ea, MAHA_THRESH_6);
}
void gnss_update_20(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_20, H_20, NULL, in_z, in_R, in_ea, MAHA_THRESH_20);
}
void gnss_update_7(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_7, H_7, NULL, in_z, in_R, in_ea, MAHA_THRESH_7);
}
void gnss_update_21(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_21, H_21, NULL, in_z, in_R, in_ea, MAHA_THRESH_21);
}
void gnss_err_fun(double *nom_x, double *delta_x, double *out_4146341528858007965) {
  err_fun(nom_x, delta_x, out_4146341528858007965);
}
void gnss_inv_err_fun(double *nom_x, double *true_x, double *out_7655543901485109526) {
  inv_err_fun(nom_x, true_x, out_7655543901485109526);
}
void gnss_H_mod_fun(double *state, double *out_2206412795536377560) {
  H_mod_fun(state, out_2206412795536377560);
}
void gnss_f_fun(double *state, double dt, double *out_1052288441262299862) {
  f_fun(state,  dt, out_1052288441262299862);
}
void gnss_F_fun(double *state, double dt, double *out_1013371314315383813) {
  F_fun(state,  dt, out_1013371314315383813);
}
void gnss_h_6(double *state, double *sat_pos, double *out_281823431389829657) {
  h_6(state, sat_pos, out_281823431389829657);
}
void gnss_H_6(double *state, double *sat_pos, double *out_529963587596744022) {
  H_6(state, sat_pos, out_529963587596744022);
}
void gnss_h_20(double *state, double *sat_pos, double *out_7332534737645198155) {
  h_20(state, sat_pos, out_7332534737645198155);
}
void gnss_H_20(double *state, double *sat_pos, double *out_1063331478846045498) {
  H_20(state, sat_pos, out_1063331478846045498);
}
void gnss_h_7(double *state, double *sat_pos_vel, double *out_2678422718282197825) {
  h_7(state, sat_pos_vel, out_2678422718282197825);
}
void gnss_H_7(double *state, double *sat_pos_vel, double *out_606349518386968416) {
  H_7(state, sat_pos_vel, out_606349518386968416);
}
void gnss_h_21(double *state, double *sat_pos_vel, double *out_2678422718282197825) {
  h_21(state, sat_pos_vel, out_2678422718282197825);
}
void gnss_H_21(double *state, double *sat_pos_vel, double *out_606349518386968416) {
  H_21(state, sat_pos_vel, out_606349518386968416);
}
void gnss_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
}

const EKF gnss = {
  .name = "gnss",
  .kinds = { 6, 20, 7, 21 },
  .feature_kinds = {  },
  .f_fun = gnss_f_fun,
  .F_fun = gnss_F_fun,
  .err_fun = gnss_err_fun,
  .inv_err_fun = gnss_inv_err_fun,
  .H_mod_fun = gnss_H_mod_fun,
  .predict = gnss_predict,
  .hs = {
    { 6, gnss_h_6 },
    { 20, gnss_h_20 },
    { 7, gnss_h_7 },
    { 21, gnss_h_21 },
  },
  .Hs = {
    { 6, gnss_H_6 },
    { 20, gnss_H_20 },
    { 7, gnss_H_7 },
    { 21, gnss_H_21 },
  },
  .updates = {
    { 6, gnss_update_6 },
    { 20, gnss_update_20 },
    { 7, gnss_update_7 },
    { 21, gnss_update_21 },
  },
  .Hes = {
  },
  .sets = {
  },
  .extra_routines = {
  },
};

ekf_init(gnss);
