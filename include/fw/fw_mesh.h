#ifndef __FW_MESH_H__
#define __FW_MESH_H__

#include <fw/fw_math.h>
#include <fw/fw_vec3f_array.h>


FW_EXTERN_C_BEGIN
//------------------------------------------------------------------------------

typedef struct _fw_fat_vertex
{
	float x, y, z;        // Vertex 0-12
	float nx, ny, nz;     // Normal 13-24
	float tx, ty, tz;     // Tangent 25-36
	float s, t, r;     // Texcoord0 37-48       
}fw_fat_vertex;

void fw_arrays_to_interlaced(
	fw_fat_vertex*	fatVertices,
	fw_uint num_vertices,
	fw_vec3f_array*	vertices,
	fw_vec3f_array*	normals,
	fw_vec3f_array*	tangents,
	fw_vec3f_array*	texCoords
);

typedef struct _fw_mesh
{
	// for temp, conveniece
	fw_vec3f_array*	vertices;
	fw_vec3f_array*	normals;
	fw_vec3f_array*	tangents;
	fw_vec3f_array*	texCoords;
	
	fw_fat_vertex* fat_vertices;// for hardware upload
	
	fw_uint*	indices;
	fw_uint		numIndices;

	fw_uint vbo;
	fw_uint ebo;
	fw_uint vao;	
	
}fw_mesh;

//------------------------------------------------------------------------------
fw_mesh* fw_mesh_create();
fw_mesh* fw_mesh_create_box();

void fw_mesh_destroy(fw_mesh* mesh);
void fw_mesh_print(fw_mesh* mesh);

// Helpers
void fw_mesh_generate_tangent_space(fw_mesh* mesh);

//------------------------------------------------------------------------------
FW_EXTERN_C_END

#endif /* __FW_MESH_H__ */