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

image::image_iterator& image::image_iterator::operator=(const image_iterator& rhs){
	if(*this != rhs){
		return *this;
	}

	this->ptr = rhs.ptr;

	return *this;
}

bool image::image_iterator::operator!=(const image_iterator& rhs){
		return (!(this->ptr == rhs.ptr));
}

image::image_iterator image::image_iterator::operator++(){
	++this->ptr;
	return *this;
}

image::image_iterator image::image_iterator::operator--(){
	--this->ptr;
	return *this;
}

unsigned char& image::image_iterator::operator*(){
	return *ptr;
}

image::image_iterator image::begin() const{
	return image::image_iterator(data.get());
}

image::image_iterator image::end() const{
	unsigned char* endptr = &data[image::height * image::width - 1];
	return image::image_iterator(++endptr);
}

image::image(){
	height = 0;
	width = 0;
	data = nullptr;
}

image::image(int width, int height, unsigned char* holder){
	this->width = width;
	this->height = height;

	unsigned char* data = new unsigned char[width*height];

	for(int i = 0; i < width * height; ++i){
		data[i] = holder[i];
	}

	this->data.reset(data);
}

image::~image(){
	data.reset();
}

image::image(const image& rhs){

	this->height = rhs.height;
	this->width = rhs.width;

	data.reset(new unsigned char [width*height]);

	image::image_iterator beg = this->begin(), end = this->end();
	image::image_iterator inStart = rhs.begin(), inEnd = rhs.end();
	while (beg != end) {

		*beg = *inStart;
		++beg;
		++inStart;
	}
}

image::image(image&& rhs){

	this->height = rhs.height;
	this->width = rhs.width;

	data.reset(new unsigned char [width*height]);

	image::image_iterator beg = this->begin(), end = this->end();
	image::image_iterator inStart = rhs.begin(), inEnd = rhs.end();
	while (beg != end) {

		*beg = *inStart;
		++beg;
		++inStart;
	}

	rhs.height = 0;
	rhs.width = 0;
	data = nullptr;
}

image& image::operator=(const image& rhs){

		this->height = rhs.height;
		this->width = rhs.width;

		data.reset(new unsigned char [width*height]);

		image::image_iterator beg = this->begin(), end = this->end();
		image::image_iterator inStart = rhs.begin(), inEnd = rhs.end();

		while (beg != end) {
			*beg = *inStart;
			++beg;
			++inStart;
		}

		return *this;
}

image& image::operator=(image&& rhs){

		this->height = rhs.height;
		this->width = rhs.width;

		data.reset(new unsigned char [width*height]);

		image::image_iterator beg = this->begin(), end = this->end();
		image::image_iterator inStart = rhs.begin(), inEnd = rhs.end();

		while (beg != end) {
			*beg = *inStart;
			++beg;
			++inStart;
		}

		rhs.height = 0;
		rhs.width = 0;
		data = nullptr;

		return *this;
}

image image::operator+(const image& rhs){

	image temp = *this;

	image::image_iterator beg = this->begin(), end = this->end();
	image::image_iterator inStart = rhs.begin(), inEnd = rhs.end();
	image::image_iterator temp_beg = temp.begin(), temp_end = temp.end();

	if(this->height == rhs.height && this->width == rhs.width){
		while (beg != end) {
			if(*beg + *inStart >= 255){
				*temp_beg = 255;
			}
			else{
				*temp_beg = *beg + *inStart;
			}
			++beg;
			++inStart;
			++temp_beg;
		}
		return temp;
	}
	else{
		std::cout << "Images have different dimensions" << '\n';
	}
}

image image::operator-(const image& rhs){
	image temp = *this;

	image::image_iterator beg = this->begin(), end = this->end();
	image::image_iterator inStart = rhs.begin(), inEnd = rhs.end();
	image::image_iterator temp_beg = temp.begin(), temp_end = temp.end();

	if(this->height == rhs.height && this->width == rhs.width){
		while (beg != end) {
			if(*beg - *inStart < 0){
				*temp_beg = 0;
			}
			else{
				*temp_beg = *beg - *inStart;
			}
			++beg;
			++inStart;
			++temp_beg;
		}
		return temp;
	}
	else{
		std::cout << "Images have different dimensions" << '\n';
	}
}

image image::operator/(const image& rhs){
	image temp = *this;

	image::image_iterator beg = this->begin(), end = this->end();
	image::image_iterator inStart = rhs.begin(), inEnd = rhs.end();
	image::image_iterator temp_beg = temp.begin(), temp_end = temp.end();

	if(this->height == rhs.height && this->width == rhs.width){
		while (beg != end) {

			if(*inStart == 255){
				*temp_beg = *beg;
			}
			else{
				*temp_beg = 0;
			}
			++beg;
			++inStart;
			++temp_beg;

		}
		return temp;
	}
	else{
		std::cout << "Images have different dimensions" << '\n';
	}
}

image image::operator!(){
	image temp = *this;

	image::image_iterator beg = this->begin(), end = this->end();
	image::image_iterator temp_beg = temp.begin(), temp_end = temp.end();

	while (beg != end) {
		*temp_beg = 255 - *beg;
		++beg;
		++temp_beg;
	}
	return temp;
}

image image::operator*(const int& threshold){
	image temp = *this;

	image::image_iterator beg = this->begin(), end = this->end();
	image::image_iterator temp_beg = temp.begin(), temp_end = temp.end();

	while (beg != end) {
		if(*beg > threshold){
			*temp_beg = 255;
		}
		else{
			*temp_beg = 0;
		}
		++beg;
		++temp_beg;
	}
	return temp;
}

std::ifstream& operator>>(std::ifstream& ifs, image& rhs){

	std::string line;
	std::vector<std::string> line_vector;

	getline(ifs, line);

	if(line.compare("P5") == 0){
		getline(ifs, line);
		while(line.compare("255") != 0){
			line_vector.push_back(line);
			getline(ifs, line);
		}

		std::stringstream line_string_stream(line_vector.at(line_vector.size() - 1));
		std::string height_string, width_string;

		getline(line_string_stream, height_string, ' ');
		rhs.height = stoi(height_string);

		getline(line_string_stream, width_string, ' ');
		rhs.width = stoi(width_string);

		skipws(ifs);

		unsigned char* image_data = new unsigned char [rhs.height * rhs.width];
		ifs.read((char*)&image_data[0], rhs.height * rhs.width);
		rhs.data.reset(image_data);
		return ifs;
	}
}

void image::load(const std::string& filename){

	std::ifstream ifs(filename, std::ios::binary);

	if(!ifs){
		std::cerr << "File open failed!" << std::endl;
	}
	else{
		ifs >> *this;
		ifs.close();
	}
}

std::ofstream& operator<<(std::ofstream& ofs, const image& rhs){

	ofs << "P5" << '\n';
	ofs << "# CREATOR: LPHTUM003" << '\n';
	ofs << rhs.height << ' ' << rhs.width << '\n';
	ofs << 255 << '\n';

	ofs.write((char*)&rhs.data[0], rhs.height * rhs.width);

	return ofs;

}

void image::save(const std::string& filename){
	std::ofstream ofs(filename, std::ios::binary);
	ofs << *this;
	ofs.close();
}
