#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void live_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_9(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_12(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_35(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_32(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_33(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_H(double *in_vec, double *out_2052578109245956760);
void live_err_fun(double *nom_x, double *delta_x, double *out_2955813261680985274);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_6823828827816290775);
void live_H_mod_fun(double *state, double *out_2985667548384257886);
void live_f_fun(double *state, double dt, double *out_73431672034252871);
void live_F_fun(double *state, double dt, double *out_2606842634982064754);
void live_h_4(double *state, double *unused, double *out_4699131035468602842);
void live_H_4(double *state, double *unused, double *out_1730352758191188936);
void live_h_9(double *state, double *unused, double *out_5006875366254992025);
void live_H_9(double *state, double *unused, double *out_9017571693455636406);
void live_h_10(double *state, double *unused, double *out_3665285765631362774);
void live_H_10(double *state, double *unused, double *out_2156039251673525070);
void live_h_12(double *state, double *unused, double *out_1134922651370459992);
void live_H_12(double *state, double *unused, double *out_6749809166223150731);
void live_h_35(double *state, double *unused, double *out_1193505332566396006);
void live_H_35(double *state, double *unused, double *out_8951371875161387176);
void live_h_32(double *state, double *unused, double *out_4072999739146036077);
void live_H_32(double *state, double *unused, double *out_5228179600504536781);
void live_h_13(double *state, double *unused, double *out_2333393268437977079);
void live_H_13(double *state, double *unused, double *out_5541564132305385138);
void live_h_14(double *state, double *unused, double *out_5006875366254992025);
void live_H_14(double *state, double *unused, double *out_9017571693455636406);
void live_h_33(double *state, double *unused, double *out_1869384587041613534);
void live_H_33(double *state, double *unused, double *out_5800814870522529572);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}