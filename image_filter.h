#include <string>
#include <fstream>

#ifndef IMAGE_FILTER_H_
#define IMAGE_FILTER_H_

class image_filter{
public:
  int N;
  float** values;
  std::string filename;

  void load(std::string filename){
    std::ifstream ifs(filename, std::ios::binary);

    ifs >> N;

    values = new float*[N];

    for(int i = 0; i < N; ++i){
      values[i] = new float [N];
      for(int j = 0; j < N; ++j){
        ifs >> values[i][j];
      }
    }

    ifs.close();
  }

  ~image_filter(){
    if(values != NULL){
      for(int i = 0; i < N; ++i){
        delete [] values[i];
      }
      delete [] values;
    }
  }
};

#endif
