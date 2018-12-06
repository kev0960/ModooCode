#include <memory>
#include <unordered_map>
#include <utility>
#include <vector>

namespace algo_visual {

class Entity {
 public:
  virtual const std::pair<int, int> GetSize() = 0;

  Entity() : base_x_(0), base_y_(0) {}

  // Base position of the object.
  void SetBasePosition(int x, int y) {
    base_x_ = x;
    base_y_ = y;
  }

 private:
  int base_x_, base_y_;
};

class Scene {
 private:
  std::vector<Entity*> entities_;

  // Offset of entity with respect to its base position.
  std::unordered_map<Entity*, std::pair<int, int>> entity_offsets_;
};

/*
 * Drawing is done by two passes of the same algorithm.
 *
 * First pass determines the orientation of every entities in the world.
 *
 * Second pass finally draws the entities as we decided every position of
 * the entities.
 *
 */
class World {
 public:
  World(int width, int height)
      : width_(width), height_(height), is_drawing_(false) {}

  /*
  void CreateNewFrame() { frames.push_back(Magick::Image(width_, height_)); }
  Magick::Image* GetLastImage() { return &frames[frames.size() - 1]; }
  */

 private:
  // List of frames. These frames will be generated as an animated gifs.
  std::vector<Scene> scenes_;

  // List of entities.
  std::vector<std::unique_ptr<Entity>> entities_;

  int width_, height_;
  bool is_drawing_;
};
}  // namespace algo_visual
