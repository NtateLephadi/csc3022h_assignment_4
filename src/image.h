#include <memory>
#include <iostream>
#include <string>

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

	void operator>>(const std::string filename);
	
	void operator<<(const std::string filename);

	int getHeight() const;

	int getWidth() const;

	class image_iterator{
		
		private:

			unsigned char *ptr;
			int index;
		
		public:
			
			image_iterator(unsigned char *ptr);

			image_iterator(unsigned char *ptr, int count);

			image_iterator(const image_iterator& rhs);

			image_iterator();
			
			image_iterator& operator=(const image_iterator& rhs);
			
			image_iterator& operator++();

			image_iterator operator++(int);

			image_iterator& operator--();

			image_iterator operator--(int);

			image_iterator& operator*();

			image_iterator operator!=(const image_iterator& rhs);

	};

	image_iterator& end();
	
	image_iterator& begin() const;
};

#endif