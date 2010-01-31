#include <stdio.h>

#include <fw/fw_math.h>
#include <fw/fw_vec3f_array.h>
#include <fw/fw_mesh.h>
#include <fw/fw_glutil.h>

#include <GLUT/glut.h>

// Globals
GLuint  g_window_width;
GLuint  g_window_height;
GLuint  g_buffer_width = 1024;
GLuint  g_buffer_height = 1024;
GLuint  g_window_has_been_resized = 0;
fw_real  g_projection_matrix[16];
float   g_ortho_projection_matrix[16];
fw_real  g_model_view_matrix[16];
//------------------------------------------------------------------------------
void init_mesh()
{
	// this is a test of the conversion from separate arrays to one interlaced array
	// This functionality should not be directly. It will be used internally
	// in mesh to create a good hardware friendly vertex format

	// Create arrays with positions, normals, tangents and texture coords
	// Observe: tangent are usually not added manually
	// but created using : fw_mesh_generate_tanget_space
	
	fw_vec3f_array* v = fw_vec3f_array_create();
	fw_vec3f_array* n = fw_vec3f_array_create();
	fw_vec3f_array* t = fw_vec3f_array_create();
	fw_vec3f_array* tx = fw_vec3f_array_create();
	
	for(int i=0; i<16;i++) 
	{
		fw_vec3f a = fw_vec3f_create(1.0*i, 2.0*i, 3.0*i);
		fw_vec3f_array_push_back(v, a);
		fw_vec3f_array_push_back(n, a);
		fw_vec3f_array_push_back(t, a);
		fw_vec3f_array_push_back(tx, a);
	}
	
	fw_fat_vertex fat[16];
	
	fw_arrays_to_interlaced(&fat[0], 16, v,n,t,tx);
	
	printf("Printing fat vertices\n");
	for(int i=0; i<16;i++) 
	{
		printf("(x: %2.2f y: %2.2f z: %2.2f) ", fat[i].x, fat[i].y, fat[i].z);
		printf("(nx: %2.2f ny: %2.2f nz: %2.2f) ", fat[i].nx, fat[i].ny, fat[i].nz);
		printf("(tx: %2.2f ty: %2.2f tz: %2.2f) ", fat[i].tx, fat[i].ty, fat[i].tz);
		printf("(s: %2.2f t: %2.2f r: %2.2f)\n", fat[i].s, fat[i].t, fat[i].r);
	}
	
	
}
//------------------------------------------------------------------------------
void cb_display(void)
{
	glViewport(0, 0, g_buffer_width, g_buffer_height);
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	
	glutSwapBuffers();
}
//------------------------------------------------------------------------------

void cb_reshape(int width, int height)
{
    g_window_width = width;
	g_window_height = height;
	g_window_has_been_resized = 1;
	
	// set viewport
	
	// set view frustum
	
}
//------------------------------------------------------------------------------

void cb_idle(void)
{
    glutPostRedisplay();
}
//------------------------------------------------------------------------------
int main(int argc, char** argv)
{
	printf("Testing mesh using glut \n");
    glutInit(&argc, argv);
    
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Mesh test");

	init_mesh();

    glutDisplayFunc(cb_display);
    glutReshapeFunc(cb_reshape);
    glutIdleFunc(cb_idle);
    
    glutMainLoop();

    return EXIT_SUCCESS;
}