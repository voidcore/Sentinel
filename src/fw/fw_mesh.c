#include <fw/fw_mesh.h>
//------------------------------------------------------------------------------
void fw_arrays_to_interlaced(
	fw_fat_vertex*	fatVertices,
	fw_uint num_vertices,
	fw_vec3f_array*	vertices,
	fw_vec3f_array*	normals,
	fw_vec3f_array*	tangents,
	fw_vec3f_array*	texCoords
)
{
	fw_vec3f* vdata = fw_vec3f_array_get_data(vertices);
	fw_vec3f* ndata = fw_vec3f_array_get_data(normals);
	fw_vec3f* tdata = fw_vec3f_array_get_data(tangents);
	fw_vec3f* txdata = fw_vec3f_array_get_data(texCoords);
		
	for (int i=0;i<num_vertices;i++)
	{
		fw_fat_vertex* f = &fatVertices[i];
		fw_vec3f v = vdata[i];
		fw_vec3f n = ndata[i];	
		fw_vec3f t = tdata[i];
		fw_vec3f tx = txdata[i];	
		
		f->x = v.x;
		f->y = v.y;
		f->z = v.z;
		
		f->nx = n.x;
		f->ny = n.y;
		f->nz = n.z;
		
		f->tx = t.x;
		f->ty = t.y;
		f->tz = t.z;
		
		f->s = v.x;
		f->t = v.y;
		f->r = v.z;
		
	}
	
}
//------------------------------------------------------------------------------
fw_mesh* fw_mesh_create()
{
}
//------------------------------------------------------------------------------
fw_mesh* fw_mesh_create_box()
{
}
//------------------------------------------------------------------------------
void fw_mesh_destroy(fw_mesh* mesh)
{
}
//------------------------------------------------------------------------------
void fw_mesh_print(fw_mesh* mesh)
{
}
//------------------------------------------------------------------------------
void fw_mesh_generate_tangent_space(fw_mesh* mesh)
{
	
}