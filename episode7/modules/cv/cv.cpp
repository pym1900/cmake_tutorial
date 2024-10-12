#include"cv.hpp"

namespace CMAKE_TUTORIAL{

    CV::CV(){
        cv::FileStorage file(PROJECT_DIR "/config/detect/detect.yaml",cv::FileStorage::READ);
        file["settings"]["rec_select"] >> rec_select;
        file["settings"]["H_min"] >> H_min;
        file["settings"]["H_max"] >> H_max;
        file["settings"]["s_min"] >> s_min;
        file["settings"]["s_max"] >> s_max;
        file["settings"]["v_min"] >> v_min;
        file["settings"]["v_max"] >> v_max;
        
    }
    
}