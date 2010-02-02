#include <fw/fw_core.h>
#include <fw/fw_hash.h>
#include <fw/fw_mesh.h>

/* ideas for databases */
/******************************************************************************/

typedef struct MeshDB {
	fw_hash* hash;
	char* name;
	fw_mesh* mesh_arr[100]; // highly temporary hack test
	fw_uint current;
} MeshDB;


MeshDB* mesh_db_create(const char* name)
{
	MeshDB* mdb = malloc(sizeof(MeshDB));
	mdb->hash = fw_hash_create();
	mdb->name = malloc(sizeof(name));
	strcpy(mdb->name, name);

	// hack
	mdb->current = 0;
	
	return mdb;
}


fw_int mesh_db_add(MeshDB* mdb, fw_mesh* mesh, const char* name)
{
	fw_hash_insert(mdb->hash, name, (void*)mesh); 
	mdb->mesh_arr[mdb->current++] = mesh;
	
	return 1;
}


fw_mesh* mesh_db_get(MeshDB* mdb, const char* name) 
{
	if (mdb != NULL) {
		fw_mesh* mesh = NULL;
		mesh = (fw_mesh*)fw_hash_find(mdb->hash, name);
		if (mesh != NULL) {
			return mesh;
		}
		else {
			fw_debug_printf("mesh_db_get failed. no mesh found\n");
			return NULL;
		}

	}
	return NULL;
}

void mesh_db_print(const MeshDB* mdb)
{
	printf("MeshDB: %s\n", mdb->name);
	int i=0;

		
	for (;i<mdb->current;i++) {
		printf("Mesh #%d __info_here__\n", i); 	
		
	}
}

/******************************************************************************/

#pragma mark globals

MeshDB* 				g_meshes 		= NULL;
//DeferredRenderer* 		g_renderer 		= NULL;

/******************************************************************************/


void setup()
{
	fw_set_notification_level(FW_NOTIFICATION_DEBUG);
    g_meshes = mesh_db_create("all my meshes");
	fw_mesh* mesh = fw_mesh_create_box(1.0);
	mesh_db_add(g_meshes, mesh, "box 0");
	
	fw_mesh* mesh2 = fw_mesh_create_box(3.0);
	mesh_db_add(g_meshes, mesh2, "box 0");
 	
    //g_renderer = deferred_renderer_create("Deferred renderer 0");
	
	mesh_db_print(g_meshes);
	
}

#pragma mark main

int main (int argc, char const *argv[])
{
    fw_info_printf("Testing renderer interface\n");
    
	setup();
	
    return 0;
}