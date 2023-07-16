/*
 * impl_tsk.h
 *
 *  Created on: Sep 18, 2022
 *      Author: SysIDEA_OSAKE
 */

#ifndef INC_IMPL_TSK_H_
#define INC_IMPL_TSK_H_


void motor_trqctrl(float *des_curr_m1,float *des_curr_m2){

/**************code here**********************/



/**************code here**********************/
float x = 0.1*cos(th1)+ 0.1*cos(th1+th2);
float y = 0.1*sin(th1) + 0.1*sin(th1+th2);
float x0 = 0.007;
float y0 = 0.141;
float k1 = 100;
float k2 = 100;
float k3 = 0;
float k4 = 0;
//float J[2][2] = {{-0.1*sin(th1)-0.1*sin(th1+th2),0.1*cos(th1) + 0.1*cos(th1+th2)},{-0.1*sin(th1+th2), 0.1*cos(th1+th2)}};
//float K[2][2] = {{100,0},{0,100}};

//float XX[2][1] = {{(xx-x0)*k1*(-0.1*sin(th1)-0.1*sin(th1+th2))+(yy-y0)*k2*(0.1*cos(th1) + 0.1*cos(th1+th2))},{(xx-x0)*k1*(-0.1*sin(th1+th2))+(yy-y0)*k2*(0.1*cos(th1+th2))}};
//float tau_1 =(xx-x0)*k1*(-0.1*sin(th1)-0.1*sin(th1+th2))+(yy-y0)*k2*(0.1*cos(th1) + 0.1*cos(th1+th2));
//float tau_2 = (xx-x0)*k1*(-0.1*sin(th1+th2))+(yy-y0)*k2*(0.1*cos(th1+th2));


//float tau_1 = (k4*(cos(th1 + th2)/10 + cos(th1)/10) - k1*(sin(th1 + th2)/10 + sin(th1)/10))*(x - x0) + (k2*(cos(th1 + th2)/10 + cos(th1)/10) - k3*(sin(th1 + th2)/10 + sin(th1)/10))*(y - y0);
//float tau_2 = ((k4*cos(th1 + th2))/10 - (k1*sin(th1 + th2))/10)*(x - x0) + ((k2*cos(th1 + th2))/10 - (k3*sin(th1 + th2))/10)*(y - y0);

float tau_1 = (x - x0)*((k4*cos(th1))/10 - (k1*sin(th1))/10) + (y - y0)*((k2*cos(th1))/10 - (k3*sin(th1))/10);
float tau_2 = ((k4*cos(th1 + th2))/10 - (k1*sin(th1 + th2))/10)*(x - x0) + ((k2*cos(th1 + th2))/10 - (k3*sin(th1 + th2))/10)*(y - y0);


float c121 = -0.05*0.1*0.05*sin(th2);
float kd = 1;
float c211 = c121;
float c221 = c121;
float c112_t2 = -c121;
//float tau_1 = c121*estimate3*estimate4 + c211*estimate3*estimate4 + c221*estimate4*estimate4 + (k4*(cos(th1 + th2)/10 + cos(th1)/10) - k1*(sin(th1 + th2)/10 + sin(th1)/10))*(x - x0) + (k2*(cos(th1 + th2)/10 + cos(th1)/10) - k3*(sin(th1 + th2)/10 + sin(th1)/10))*(y - y0);
//float tau_2 =c112_t2*estimate3*estimate3 + ((k4*cos(th1 + th2))/10 - (k1*sin(th1 + th2))/10)*(x - x0) + ((k2*cos(th1 + th2))/10 - (k3*sin(th1 + th2))/10)*(y - y0);

*des_curr_m1=-10*tau_1;//write ur calculated current variable here for motor1
*des_curr_m2=-10*tau_2;//write ur calculated current variable here for motor2

//*des_curr_m1=-2.83;//write ur calculated current variable here for motor1
//*des_curr_m2=-0.00225;//write ur calculated current variable here for motor2
}

void traj_ctrl(float *des_theta1,float *des_theta2,float *des_thetad1,float *des_thetad2){
/**************code here**********************/



/**************code here**********************/

//	if(arr_indx>=499){
//		*des_theta1=thd1_trac[499];
//		*des_theta2=thd2_trac[499];
//		*des_thetad1=vel_track_d2[499];
//		*des_thetad2=vel_track_d2[499];
//	}
//	else{
//		*des_theta1=thd1_trac[arr_indx];
//		*des_theta2=thd2_trac[arr_indx];
//		*des_thetad1=vel_track_d2[arr_indx];
//		*des_thetad2=vel_track_d2[arr_indx];
//	}

}

#endif /* INC_IMPL_TSK_H_ */


//////////////////////////////////////////////////////////////////////
//***********variable===>description and use********************//////
//raw current:
//current===>motor1
//current2==>motor2
//
//filtered current:
//estimate===>motor1
//estimate2==>motor2
//
//angle in radians
//th1===>theta1
//th2==>theta2
//
//estimate3===>theat1_dot
//estimate4===>theat2_dot
//
//arr_indx===>index to manipulate array for trajectory
//
//spth1===>initial position of manipulator theta1
//spth2===>initial position of manipulator theta2

//time_vectt==>time
//////////////////////////////////////////////////////////////////////



