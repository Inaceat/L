#pragma once

class Array
{
public:
	Array();
	
	Array(const Array& other);
	
	Array(Array&& other);



	Array& operator=(const Array& other);
	
	Array& operator=(Array&& other);



	~Array();
};