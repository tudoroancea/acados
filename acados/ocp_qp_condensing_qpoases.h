#ifndef ACADOS_OCP_QP_CONDENSING_QPOASES_H_
#define ACADOS_OCP_QP_CONDENSING_QPOASES_H_

#include "acados_types.h"
#include "ocp_qp_common.h"

typedef struct ocp_qp_condensing_qpoases_args_ {
    real_t dummy;
} ocp_qp_condensing_qpoases_args;

int_t ocp_qp_condensing_qpoases(ocp_qp_input *input, ocp_qp_output *output,
    ocp_qp_condensing_qpoases_args *args, double *work);

int_t ocp_qp_condensing_qpoases_workspace_size(ocp_qp_input *input,
    ocp_qp_condensing_qpoases_args *args);

void initialise_qpoases();

#endif  // ACADOS_OCP_QP_CONDENSING_QPOASES_H_