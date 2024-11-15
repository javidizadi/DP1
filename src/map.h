#pragma once
#include <cstdint>
#include <string>

enum MapError {
  NotEnoughMemory,
  KeyNotFound,
  KeyAlreadyExists,
  MapIsFull,
};

template <class K, class V> struct MapNode {
  K key;
  V value;
};

template <class K, class V> class Map {
private:
  MapNode<K, V> *data;
  size_t capacity;
  size_t countElements;

public:
  Map(size_t);
  ~Map();
  void insert(K, V);
  void remove(K);
  V find(K);
  void update(K, V);
  bool isUnique(K);
  size_t count();
};

#include "map.tpp"
