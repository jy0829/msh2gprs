#pragma once

#include <uint256/uint256_t.h>
#include <angem/Point.hpp>
#include <angem/PointSet.hpp>
#include <Face.hpp>
#include <vector>
#include <unordered_map>
#include <mesh_methods.hpp>

namespace mesh
{
using Point = angem::Point<3,double>;
using FaceMap = std::unordered_map<hash_type, Face>;

class face_iterator
{
 public:
  face_iterator(const FaceMap::iterator            & it,
                angem::PointSet<3,double>          & vertices);
  face_iterator(const face_iterator & other);
  // comparison
  bool operator==(const face_iterator & other) const;
  bool operator!=(const face_iterator & other) const;
  // Setters
  face_iterator & operator=(const face_iterator & other);
  // Getters
  // get center of mass of a face
  Point center() const;
  // get face normal
  Point normal() const;
  // get face marker, (-1) if not defined
  int marker() const;
  // get hash value
  inline hash_type hash() const {return face_it->first;}
  std::size_t index() const {return face_it->second.index;}
  std::size_t master_index() const {return face_it->second.old_index;}
  int vtk_id() const {return face_it->second.vtk_id;}
  // get vector of neighbor indices
  inline
  const std::vector<std::size_t> & neighbors() const {return face_it->second.neighbors;}
  std::vector<Point> vertices() const;
  std::vector<std::size_t> vertex_indices() const;
  // incrementing
  face_iterator & operator++();
  face_iterator & operator--();

 private:
  FaceMap::iterator face_it;
  angem::PointSet<3,double>          & mesh_vertices;
};

}