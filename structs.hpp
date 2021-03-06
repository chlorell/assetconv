//
//  structs.hpp
//  assetconv
//
//  Created by Mateusz Bugaj on 16.05.2016.
//  Copyright © 2016 Ocean Planet Studios. All rights reserved.
//

#ifndef structs_hpp
#define structs_hpp

#include <glm/glm.hpp>

namespace assetconv {
    namespace storage {
        struct buffer_desc
        {
            unsigned long ptr;
            unsigned long length;
            unsigned char align;

            enum buffer_type : unsigned char
            {
                BUFFERS_LIST, //buffer_desc
                SCENE_NODES, //node
                TEXTURES_DESC, //texture
                VERTEX_DATA, //vertexes, indexes, animations
                MESHES_DESC,
                ANIMATIONS_DESC,
                NAMES
            } type;
        };
        
        struct name_desc{ //this is polymorphic but wont be in the engine
            char name[256];
            buffer_desc::buffer_type buffer_type;
            unsigned object_id;
        };
        
        struct animation_frame{
            float time;
            glm::mat4 transform;
        };
        
        
        struct animation {
            float duration;
            unsigned long offset;//all animation frames are stored in one big buffer
            unsigned count;
            unsigned bone_id;//relative to a mesh
            unsigned group_id;//animations doesn't have much sense with only one bone
        };
        
        struct pos3f_s
        {
            glm::vec3 pos;
        };
        
        struct pos3fnormal3f_s
        {
            glm::vec3 pos;
            glm::vec3 normal;
        };
        
        struct pos3fnormal3fuv2f_s
        {
            glm::vec3 pos;
            glm::vec3 normal;
            glm::vec2 uv;
        };

        
        struct pos3fnormal3fuv2ftangent3f_s
        {
            glm::vec3 pos;
            glm::vec3 normal;
            glm::vec2 uv;
            glm::vec3 tangent;
        };

        
        struct pos3fnormal3fuv2fmatrixes4iweights4f_s
        {
            glm::vec3 pos;
            glm::vec3 normal;
            glm::vec2 uv;
            glm::tvec4<unsigned char, glm::lowp> matrixes;
            glm::vec4 weights;
        };

        
        struct pos3fnormal3fuv2ftangent3fmatrixes4iweights4f_s
        {
            glm::vec3 pos;
            glm::vec3 normal;
            glm::vec2 uv;
            glm::vec3 tangent;
            glm::tvec4<unsigned char, glm::lowp> matrixes;
            glm::vec4 weights;
        };

        
        
        struct mesh {
            unsigned vertex_buffer_id;
            unsigned index_buffer_id;
            unsigned texture_ids[4];
            unsigned long vertex_buffer_offset;
            unsigned vertex_buffer_len;
            unsigned long index_buffer_offset;
            unsigned index_buffer_len;
            enum vertex_specs : unsigned char
            {
                pos3f,
                pos3fnormal3f,
                pos3fnormal3fuv2f,
                pos3fnormal3fuv2ftangent3f,
                pos3fnormal3fuv2fmatrixes4iweights4f,
                pos3fnormal3fuv2ftangent3fmatrixes4iweights4f
            } vertex_spec;
        };
        
        struct node {
            glm::mat4 transform;
            unsigned parent_id;
 
            enum node_types: unsigned char {
                mesh,
                camera,
                light,
                bone,
                empty
            } node_type;
            
            struct mesh_additional
            {
                unsigned mesh_id;

            };
            
            struct camera_additional
            {
                float fovx; //radians
                float fovy;
                float zfar, znear;
                float aspect;
            };
            
            struct light_additional
            {
                float intensity;
                glm::vec3 color;
                float angle; //if >= 2pi its omni
            };
            
            struct bone_additional
            {
                unsigned char bone_id;
                
            };
            
            struct empty{
                unsigned used_props;
                float props[4];
            };
            
            union {
                bone_additional bone;
                camera_additional camera;
                mesh_additional mesh;
                light_additional light;
                
            } additional;
            
        };
        
        struct texture {
            unsigned width, height;
            unsigned char type;
            char file_path[256];
            unsigned data_buffer_id; //0 if external
        };
    }
}


#endif /* structs_hpp */
