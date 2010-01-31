#include <fw/fw_glutil.h>
//------------------------------------------------------------------------------
void fw_matrix_identity(fw_real A[16])
{
    size_t bytes = 16*sizeof(fw_real);
    bzero(A, bytes);
    A[0] = A[5] = A[10] = A[15] = 1.0;
    
}
//------------------------------------------------------------------------------
void fw_matrix_translate(fw_real A[16], fw_real tx, fw_real ty, fw_real tz)
{
    bzero(A, 16*sizeof(fw_real));
    A[0] = A[5] = A[10] = A[15] = 1.0;
    A[12] = tx;
    A[13] = ty;
    A[14] = tz;
}
//------------------------------------------------------------------------------
void fw_matrix_rotate_z(fw_real A[16], fw_real angle)
{
    fw_real angled = FW_DEG2RAD*angle;
    bzero(A, 16*sizeof(fw_real));
    A[10] = A[15] = 1.0;
    
    A[0] = fw_cos(angled);
    A[1] = fw_sin(angled);
    A[4] = -fw_sin(angled);
    A[5] = fw_cos(angled);
}
//------------------------------------------------------------------------------
void fw_matrix_multiply(fw_real C[16], fw_real A[16], fw_real B[16])
{
    int i, j, k;
	for ( i=0;i<4;i++ ) {
		for ( j=0;j<4;j++ ) {
			C[FW_MAT4_INDEX(i,j)] =  A[FW_MAT4_INDEX(i,0)] * B[FW_MAT4_INDEX(0,j)];
			for (k=1;k<4;k++) {
				C[FW_MAT4_INDEX(i,j)] += A[FW_MAT4_INDEX(i,k)] * B[FW_MAT4_INDEX(k,j)];
			}   
		}
	}
}
//------------------------------------------------------------------------------
void fw_matrix_print(fw_real mat[16])
{
    int i, j;
    for (j=0;j<4;j++) {
        for (i=0;i<4;i++) {
            printf("%4.2f ", mat[FW_MAT4_INDEX(i,j)]);        
        }
        printf("\n");
    }
}
//------------------------------------------------------------------------------
void fw_matrix_create_perspective(
    fw_real *matrix, 
    fw_real fov_deg, 
    fw_real aspect, 
    fw_real znear, 
    fw_real zfar)
{
    fw_real ymax, xmax;
    ymax = znear * fw_tan(fov_deg * 2.0 *FW_PI / 360.0);
    xmax = ymax * aspect;
    fw_matrix_create_frustum(matrix, -xmax, xmax, -ymax, ymax, znear, zfar);
}
//------------------------------------------------------------------------------
void fw_matrix_create_frustum(
	fw_real     *mat,
	fw_real     left,
    fw_real     right,
    fw_real     bottom,
    fw_real     top,
    fw_real     nearVal,
    fw_real     farVal
)
{
    fw_real A = (right+left)/(right-left);
    fw_real B = (top+bottom)/(top-bottom);
    fw_real C = (farVal+nearVal)/(farVal-nearVal);
    fw_real D = (2.0*farVal*nearVal)/(farVal-nearVal);

    size_t bytes = 16*sizeof(fw_real);
    bzero(mat, bytes);
    
    mat[0] = (2.0*nearVal)/(right-left);
    mat[5] = (2.0*nearVal)/(top-bottom);
    mat[8] = A;
    mat[9] = B;
    mat[10] = C;
    mat[11] = -1.0;
    mat[14] = D;
}
//------------------------------------------------------------------------------
void fw_matrix_create_ortho(fw_real mat[16], fw_real w, fw_real h)
{
    fw_real        left = 0;
    fw_real        right = w;
    fw_real        bottom = 0;
    fw_real        top = h;
    fw_real        near = -1.0;
    fw_real        far = 1.0;
    
    fw_real tx = -(right+left)/(right-left);
    fw_real ty = -(top+bottom)/(top-bottom);
    fw_real tz = -(far+near)/(far-near);
    
   	size_t bytes = 16*sizeof(fw_real);
    bzero(mat, bytes);
    
    
    mat[0] = (2.0/(right-left));
    mat[5] = (2.0/(top-bottom));
    mat[10] = -(2.0/(far-near));
    mat[12] = tx;
    mat[13] = ty;
    mat[14] = tz;
    mat[15] = 1.0;
}