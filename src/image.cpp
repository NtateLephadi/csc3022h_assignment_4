#include "image.h"

image::image_iterator::image_iterator(unsigned char *ptr){
	image_iterator::ptr = ptr;
}

image::image_iterator::image_iterator(){
	image_iterator::ptr = nullptr;
}

image::image_iterator::image_iterator(const image_iterator& rhs){
	this->ptr = rhs.ptr;
}

image::image_iterator image::image_iterator::operator=(const image_iterator& rhs){
	if(*this != rhs){
		return *this;
	}

	this->ptr = rhs.ptr;

	return *this;
}

bool image::image_iterator::operator!=(const image_iterator& rhs){
		return (!(this->ptr == rhs.ptr));
}

image::image_iterator& image::image_iterator::operator++(){
	++this->ptr;
	return *this;
}

image::image_iterator& image::image_iterator::operator--(){
	--this->ptr;
	return *this;
}

image::image_iterator& image::image_iterator::operator*(){
	return *this;
}

image::image_iterator image::begin() const{
	return data.get();
}

image::image_iterator image::end() const{
	unsigned char* endptr = &data[image::height * image::width - 1];
	return image::image_iterator(++endptr);
}

void image::load(const std::string& filename){

	std::ifstream ifs(filename, std::ios::binary);


	if(!ifs){
		std::cerr << "File open failed!" << std::endl;
	}

	else{
		std::string line;
		std::vector<std::string> line_vector;

		getline(ifs, line);
		if(line.compare("P5") == 0){
			getline(ifs, line);
			while(line.compare("255") != 0){
				line_vector.push_back(line);
				getline(ifs, line);
			}
		}

		std::cout << line << '\n';

		std::stringstream line_string_stream(line_vector.at(line_vector.size() - 1));
		std::string height_string, width_string;
		getline(line_string_stream, height_string, ' ');
		image::height = stoi(height_string);
		getline(line_string_stream, width_string, ' ');
		image::width = stoi(width_string);

		std::cout << height << '\n' << width << '\n';

		skipws(ifs);

		unsigned char* image_data = new unsigned char [height * width];
		ifs.read((char*)&image_data[0], height * width);
		data.reset(image_data);
	}

	ifs.close();


}

image::image(){
	height = 0;
	width = 0;
	data = nullptr;
}

image::~image(){
	data.reset();
}

// std::ifstream& operator>>(std::ifstream&, image& rhs){
//
// }
