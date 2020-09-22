#ifndef OBJECT_LOADER_HPP
#define OBJECT_LOADER_HPP

#include "i_object_loader.hpp"
#include "i_object_parser.hpp"

namespace d_d {

class ObjectLoader : public IObjectLoader {
public:
    ObjectLoader(const std::shared_ptr<IObjectParser>& a_parser);
    virtual void Load(const std::string& a_filename, std::unordered_map<std::string, std::shared_ptr<IRoom>>& a_rooms) const;

private:
    std::shared_ptr<IObjectParser> m_parser;
};

} //d_d

#endif //OBJECT_LOADER_HPP