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
