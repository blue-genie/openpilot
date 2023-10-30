#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_err_fun(double *nom_x, double *delta_x, double *out_6224033064394232634);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_971149959087550599);
void car_H_mod_fun(double *state, double *out_7741368472678214347);
void car_f_fun(double *state, double dt, double *out_2360464133578240367);
void car_F_fun(double *state, double dt, double *out_2817467237859286032);
void car_h_25(double *state, double *unused, double *out_3522812589611560024);
void car_H_25(double *state, double *unused, double *out_632281976358579605);
void car_h_24(double *state, double *unused, double *out_5874268481103439627);
void car_H_24(double *state, double *unused, double *out_4190207575160902741);
void car_h_30(double *state, double *unused, double *out_7030991989213468233);
void car_H_30(double *state, double *unused, double *out_7548972317850196360);
void car_h_26(double *state, double *unused, double *out_643213206518356484);
void car_H_26(double *state, double *unused, double *out_3109221342515476619);
void car_h_27(double *state, double *unused, double *out_4466322442513222459);
void car_H_27(double *state, double *unused, double *out_5374209006049771449);
void car_h_29(double *state, double *unused, double *out_4623509110864351604);
void car_H_29(double *state, double *unused, double *out_3660846279180220416);
void car_h_28(double *state, double *unused, double *out_7503108493957555144);
void car_H_28(double *state, double *unused, double *out_1421552737889310158);
void car_h_31(double *state, double *unused, double *out_1322428690501830365);
void car_H_31(double *state, double *unused, double *out_662927938235540033);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}