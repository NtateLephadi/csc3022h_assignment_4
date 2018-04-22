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
