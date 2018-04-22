#include "catch.hpp"
#include <memory>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#ifndef IMAGE_H_
#define IMAGE_H_

class image{
private:

	int height, width;
	std::unique_ptr<unsigned char[]> data;

public:

	image(std::string filename);

	image();

	~image();

	image(const image& lhs);

	image(image&& lhs);

	void load(std::string filename);

	void save(std::string filename);

	image& operator=(const image& lhs);

	image& operator=(image&& lhs);

	image& operator+(const image& lhs);

	image& operator-(const image& lhs);

	image& operator/(const image& lhs);

	image& operator!();

	image& operator*(const int threshold);

	bool operator==(image& lhs);

	friend void operator>>(const std::string filename, image& rhs);

	friend void operator<<(const std::string filename, image& rhs);

	class image_iterator{

		private:

			unsigned char *ptr;

			image_iterator(unsigned char *ptr);

			image_iterator(const image_iterator& rhs);

			image_iterator();

		public:

			friend class image;

			image_iterator operator=(const image_iterator& rhs);

			image_iterator& operator++();

			image_iterator& operator--();

			image_iterator& operator*();

			bool operator!=(const image_iterator& rhs);

	};

	image_iterator end() const;

	image_iterator begin() const;

};

#endif
