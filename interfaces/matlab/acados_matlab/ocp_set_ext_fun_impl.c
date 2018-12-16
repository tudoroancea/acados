// system
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// acados
#include "acados/utils/external_function_generic.h"
#include "acados_c/external_function_interface.h"
// mex
#include "mex.h"



// casadi functions for the model
#include "model.h"



void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
	{

//	mexPrintf("\nin sim_impl_ext_fun_create\n");

	// sizeof(long long) == sizeof(void *) = 64 !!!
	long long *ptr;



	/* RHS */

	// C_ocp_ext_fun

	// opts

//	bool sens_forw = mxGetScalar( mxGetField( prhs[0], 0, "sens_forw" ) );
//	mexPrintf("\n%d\n", sens_forw);
	char *sim_solver = mxArrayToString( mxGetField( prhs[1], 0, "sim_solver" ) );
//	mexPrintf("\n%s\n", sim_solver);



	/* LHS */




	/* populate input struc */

	external_function_casadi *ext_fun_ptr;

	// TODO templetize the casadi function names !!!
	if(!strcmp(sim_solver, "irk"))
		{
		// impl_ode_fun
		ext_fun_ptr = (external_function_casadi *) malloc(1*sizeof(external_function_casadi));
		ext_fun_ptr->casadi_fun = &model_impl_ode_fun;
		ext_fun_ptr->casadi_work = &model_impl_ode_fun_work;
		ext_fun_ptr->casadi_sparsity_in = &model_impl_ode_fun_sparsity_in;
		ext_fun_ptr->casadi_sparsity_out = &model_impl_ode_fun_sparsity_out;
		ext_fun_ptr->casadi_n_in = &model_impl_ode_fun_n_in;
		ext_fun_ptr->casadi_n_out = &model_impl_ode_fun_n_out;
		external_function_casadi_create(ext_fun_ptr);
		// populate output struct
		mxArray *impl_ode_fun_mat  = mxCreateNumericMatrix(1, 1, mxINT64_CLASS, mxREAL);
		ptr = mxGetData(impl_ode_fun_mat);
		ptr[0] = (long long) ext_fun_ptr;
		mxSetField((mxArray*) prhs[0], 0, "impl_ode_fun", impl_ode_fun_mat);

		// impl_ode_fun_jac_x_xdot
		ext_fun_ptr = (external_function_casadi *) malloc(1*sizeof(external_function_casadi));
		ext_fun_ptr->casadi_fun = &model_impl_ode_fun_jac_x_xdot;
		ext_fun_ptr->casadi_work = &model_impl_ode_fun_jac_x_xdot_work;
		ext_fun_ptr->casadi_sparsity_in = &model_impl_ode_fun_jac_x_xdot_sparsity_in;
		ext_fun_ptr->casadi_sparsity_out = &model_impl_ode_fun_jac_x_xdot_sparsity_out;
		ext_fun_ptr->casadi_n_in = &model_impl_ode_fun_jac_x_xdot_n_in;
		ext_fun_ptr->casadi_n_out = &model_impl_ode_fun_jac_x_xdot_n_out;
		external_function_casadi_create(ext_fun_ptr);
		// populate output struct
		mxArray *impl_ode_fun_jac_x_xdot_mat  = mxCreateNumericMatrix(1, 1, mxINT64_CLASS, mxREAL);
		ptr = mxGetData(impl_ode_fun_jac_x_xdot_mat);
		ptr[0] = (long long) ext_fun_ptr;
		mxSetField((mxArray*) prhs[0], 0, "impl_ode_fun_jac_x_xdot", impl_ode_fun_jac_x_xdot_mat);

		// impl_ode_jac_x_xdot_u
		ext_fun_ptr = (external_function_casadi *) malloc(1*sizeof(external_function_casadi));
		ext_fun_ptr->casadi_fun = &model_impl_ode_jac_x_xdot_u;
		ext_fun_ptr->casadi_work = &model_impl_ode_jac_x_xdot_u_work;
		ext_fun_ptr->casadi_sparsity_in = &model_impl_ode_jac_x_xdot_u_sparsity_in;
		ext_fun_ptr->casadi_sparsity_out = &model_impl_ode_jac_x_xdot_u_sparsity_out;
		ext_fun_ptr->casadi_n_in = &model_impl_ode_jac_x_xdot_u_n_in;
		ext_fun_ptr->casadi_n_out = &model_impl_ode_jac_x_xdot_u_n_out;
		external_function_casadi_create(ext_fun_ptr);
		// populate output struct
		mxArray *impl_ode_jac_x_xdot_u_mat  = mxCreateNumericMatrix(1, 1, mxINT64_CLASS, mxREAL);
		ptr = mxGetData(impl_ode_jac_x_xdot_u_mat);
		ptr[0] = (long long) ext_fun_ptr;
		mxSetField((mxArray*) prhs[0], 0, "impl_ode_jac_x_xdot_u", impl_ode_jac_x_xdot_u_mat);
		}
	else
		{
		mexPrintf("\nocp_set_ext_fun_impl: sim_solver not supported %s\n", sim_solver);
		return;
		}
	
	return;

	}



