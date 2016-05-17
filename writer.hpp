//
//  writer.hpp
//  assetconv
//
//  Created by Mateusz Bugaj on 16.05.2016.
//  Copyright © 2016 Ocean Planet Studios. All rights reserved.
//

#ifndef writer_hpp
#define writer_hpp

#include "structs.hpp"
#include <vector>

namespace assetconv {
    
   
    
    
    struct writer{
        //buffers_list
        std::vector<storage::buffer_desc> buffers;
        std::vector<storage::name_desc> names;
        std::vector<storage::node> scene_nodes;
        std::vector<storage::animation> animations;
        std::vector<storage::mesh> meshes;
        std::vector<storage::texture> textures;
        
        //buffers
        
        
        
        unsigned long add_node(const storage::node& n){return scene_nodes.push_back(n), scene_nodes.size()-1;};
        unsigned long add_buffer_desc(const storage::buffer_desc& n){return buffers.push_back(n), buffers.size()-1;};
        unsigned long add_name(const storage::name_desc& n){return names.push_back(n), names.size()-1;};
        unsigned long add_animation(const storage::animation& n){return animations.push_back(n), animations.size()-1;};
        unsigned long add_mesh(const storage::mesh& n){return meshes.push_back(n), meshes.size()-1;};
        unsigned long add_texture(const storage::texture& n){return textures.push_back(n), textures.size()-1;};
        
        writer(){add_buffer_desc({0,0,1, storage::buffer_desc::BUFFERS_LIST});}
    };
    
    
    
}



#endif /* writer_hpp */
