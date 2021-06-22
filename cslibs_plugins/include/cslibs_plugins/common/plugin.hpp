#ifndef CSLIBS_PLUGINS_PLUGIN_HPP
#define CSLIBS_PLUGINS_PLUGIN_HPP

#include <string>

namespace cslibs_plugins {
template<typename ChildClass>
class Plugin {
 public:
  virtual inline ~Plugin() = default;

  inline std::string const& getName() const { return name_; }

  inline void setName(const std::string& name) { name_ = name; }

  inline std::size_t getId() const { return id_; }

 protected:
  inline Plugin() : id_{generateId()} {}

  inline static std::size_t generateId() {
    static std::size_t id{0};
    return id++;
  }

  const std::size_t id_;
  std::string name_;
};
}  // namespace cslibs_plugins

#endif  // CSLIBS_PLUGINS_PLUGIN_HPP
