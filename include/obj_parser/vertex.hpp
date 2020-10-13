#pragma once

#include <cstring>
#include <string>
#include <sstream>
#include <exception>
#include "vertex_parser.hpp"

template<int N>
class Vertex
{
private:
	float components[N];
	int used_components;

public:
	Vertex(VertexParser &vertex_parser);
	int getUsedComponents() const;
	float operator[](int index) const;
	void toBuffer(float *buffer, int desired_components) const;
	const std::string to_string() const;
};

template<int N>
Vertex<N>::Vertex(VertexParser &vertex_parser) : used_components(0)
{
	while (vertex_parser.hasFloat() && used_components < N)
		components[used_components++] = vertex_parser.getNextFloat();
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
