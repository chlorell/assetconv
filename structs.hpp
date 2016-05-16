//
//  structs.hpp
//  assetconv
//
//  Created by Mateusz Bugaj on 16.05.2016.
//  Copyright © 2016 Ocean Planet Studios. All rights reserved.
//

#ifndef structs_hpp
#define structs_hpp

namespace assetconv {
    struct buffer_desc
    {
        unsigned long ptr;
        unsigned long length;
        char name[128];
    };
    
}


#endif /* structs_hpp */
