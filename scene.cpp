//
//  scene.cpp
//  assetconv
//
//  Created by Mateusz Bugaj on 16.05.2016.
//  Copyright © 2016 Ocean Planet Studios. All rights reserved.
//

#include "scene.hpp"

#include <assimp/Importer.hpp>      // C++ importer interface
#include <assimp/scene.h>           // Output data structure
#include <assimp/postprocess.h>     // Post processing flags

#include <iostream>
#include <string>

namespace assetconv {
    bool convert_scene(const char * input_file_name, const char * output_file_name)
    {
 
        Assimp::Importer importer;
 
        const aiScene* scene = importer.ReadFile( input_file_name,
                                                 aiProcess_CalcTangentSpace       |
                                                 aiProcess_Triangulate            |
                                                 aiProcess_JoinIdenticalVertices  |
                                                 aiProcess_SortByPType |
                                                 aiProcess_LimitBoneWeights |
                                                 aiProcess_ImproveCacheLocality
                                                 );
        
 
        if( !scene)
        {
            std::cerr<<  "Import error for file: "<<input_file_name<<std::endl;
            std::cerr<<  importer.GetErrorString() << std::endl;
            return false;
        }else
        {
            
            
            
            return true;
        }
    }
}

