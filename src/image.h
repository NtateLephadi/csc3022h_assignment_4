#include "catch.hpp"
#include <memory>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

#ifndef IMAGE_H_
#define IMAGE_H_

class image{
private:

	int height, width;
	std::unique_ptr<unsigned char[]> data;

public:

	image();

	~image();

	image(const image& rhs);

	image(image&& rhs);

	void load(const std::string& filename);

	void save(const std::string& filename);

	image& operator=(const image& lhs);

	image& operator=(image&& rhs);

	image& operator+(const image& rhs);

	image& operator-(const image& rhs);

	image& operator/(const image& rhs);

	image operator!();

	image& operator*(const int threshold);

	bool operator==(image& lhs);

	friend std::ifstream& operator>>(const std::ifstream&, image& rhs);

	friend std::ofstream& operator<<(std::ofstream&, const image& rhs);

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

			unsigned char& operator*();

			bool operator!=(const image_iterator& rhs);

	};

	image_iterator end() const;

	image_iterator begin() const;


};




#endif
