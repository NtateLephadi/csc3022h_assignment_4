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

	std::string line;
	std::vector<std::string> line_vector;
	int height, width;

	while(!ifs.eof()){

		while(ifs.get() != '255'){
				getline(ifs, line, '\n');
				line_vector.push_back(line);
		}

		width = stoi(line_vector[line_vector.size() - 3]);
		height = stoi(line_vector[line_vector.size() - 2]);

		getline(ifs, line, '\n');
		line_vector.push_back(line);

		skipws(ifs);


		image::data.reset(new unsigned char[width * height]);
		ifs.read(data, width * height));
	}

}
