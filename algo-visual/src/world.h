#include <memory>
#include <utility>
#include <vector>
#include <unordered_map>

namespace algo_visual {

class Entity {
 public:
  virtual const std::pair<int, int> GetSize() = 0;
};

class Scene {
 private:
  std::vector<Entity*> entities_;

  // Position of entity at this scene.
  std::unordered_map<Entity*, std::pair<int, int>> pos_at_scene_;
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
