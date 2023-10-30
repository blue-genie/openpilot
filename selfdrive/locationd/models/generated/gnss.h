#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void gnss_update_6(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_20(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_7(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_update_21(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void gnss_err_fun(double *nom_x, double *delta_x, double *out_4146341528858007965);
void gnss_inv_err_fun(double *nom_x, double *true_x, double *out_7655543901485109526);
void gnss_H_mod_fun(double *state, double *out_2206412795536377560);
void gnss_f_fun(double *state, double dt, double *out_1052288441262299862);
void gnss_F_fun(double *state, double dt, double *out_1013371314315383813);
void gnss_h_6(double *state, double *sat_pos, double *out_281823431389829657);
void gnss_H_6(double *state, double *sat_pos, double *out_529963587596744022);
void gnss_h_20(double *state, double *sat_pos, double *out_7332534737645198155);
void gnss_H_20(double *state, double *sat_pos, double *out_1063331478846045498);
void gnss_h_7(double *state, double *sat_pos_vel, double *out_2678422718282197825);
void gnss_H_7(double *state, double *sat_pos_vel, double *out_606349518386968416);
void gnss_h_21(double *state, double *sat_pos_vel, double *out_2678422718282197825);
void gnss_H_21(double *state, double *sat_pos_vel, double *out_606349518386968416);
void gnss_predict(double *in_x, double *in_P, double *in_Q, double dt);
}