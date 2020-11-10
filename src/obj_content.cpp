#include "obj_parser/obj_content.hpp"

void ObjContent::addFace(const Face &face) { faces.push_back(face); }

int ObjContent::getFaceCount() const { return faces.size(); }

const Face &ObjContent::getFace(int index) const { return faces.at(index); }