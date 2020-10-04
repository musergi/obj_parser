#pragma once

#include <cstring>
#include <string>
#include <sstream>
#include <exception>

template<int N>
class Vertex
{
private:
	float components[N];
	int used_components;

public:
	Vertex(const std::string &str);
	int getUsedComponents() const;
	float operator[](int index) const;
	void toBuffer(float *buffer, int desired_components) const;
	const std::string to_string() const;

private:
	static bool moveToNextFloat(const char **str_ptr);
};

template<int N>
Vertex<N>::Vertex(const std::string &str)
{
	int component_count = 0;
	const char *float_start = str.c_str();
	do
		sscanf(float_start, "%f", &components[component_count++]);
	while(moveToNextFloat(&float_start));
	used_components = component_count;
}

template<int N>
int Vertex<N>::getUsedComponents() const
{
	return used_components;
}

template<int N>
float Vertex<N>::operator[](int index) const
{
	if (index < used_components)
		return components[index];
	throw std::invalid_argument("Index out of bounds");
}

template<int N>
void Vertex<N>::toBuffer(float *buffer, int desired_components) const
{
	if (desired_components > used_components)
		throw std::invalid_argument("Index out of bounds");
	std::memcpy(buffer, components, desired_components * sizeof(float));
}

template<int N>
const std::string Vertex<N>::to_string() const
{
	std::ostringstream stream;
	stream << "(";
	for (int i = 0; i < used_components; i++)
	{
		if (i != 0)
			stream << ", ";
		stream << components[i];
	}
	stream << ")";
	return std::move(stream.str());
}

template<int N>
bool Vertex<N>::moveToNextFloat(const char **str_ptr)
{
	const char *next_space_ptr = std::strchr(*str_ptr, ' ');
	if (!next_space_ptr)
		return false;
	*str_ptr = next_space_ptr + 1;
	return true;
}
