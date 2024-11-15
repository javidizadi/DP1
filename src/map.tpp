#include "map.h"

#define MAP_TEMPLATE(X) template <class K, class V> X Map<K, V>

using namespace std;

MAP_TEMPLATE()::Map(size_t capacity) {

  countElements = 0;
  capacity = capacity;
  data = new MapNode<K, V>[capacity];

  if (!data)
    throw MapError::NotEnoughMemory;
}

MAP_TEMPLATE()::~Map() {
  if (data)
    delete[] data;
}

MAP_TEMPLATE(bool)::isUnique(K key) {

  for (size_t i = 0; i < countElements; i++) {
    if (data[i].key == key)
      return false;
  }

  return true;
}

MAP_TEMPLATE(void)::insert(K key, V value) {

  if (!isUnique(key))
    throw MapError::KeyAlreadyExists;

  if (count() >= capacity) {
    throw MapError::MapIsFull;
  }

  data[countElements++] = MapNode<K, V>{key, value};
}

MAP_TEMPLATE(V)::find(K key) {

  for (size_t i = 0; i < countElements; i++) {
    if (data[i].key == key)
      return data[i];
  }

  throw KeyNotFound;
}

MAP_TEMPLATE(void)::remove(K key) {

  size_t index = find(key);

  for (size_t i = index + 1; i < countElements; i++) {
    data[i - 1] = data[i];
  }
}

MAP_TEMPLATE(size_t)::count() { return countElements; }

MAP_TEMPLATE(void)::update(K key, V newValue) {
  size_t index = find(key);
  data[index].value = newValue;
}
