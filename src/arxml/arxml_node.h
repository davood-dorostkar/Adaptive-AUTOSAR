#ifndef ARXML_NODE_H
#define ARXML_NODE_H

#include <string>
#include "./pugixml.hpp"

namespace arxml
{
    /// @brief A class that represents a XML node within a ARXML configuration
    class ArxmlNode
    {
    private:
        pugi::xml_node mNode;

    public:
        ArxmlNode() = delete;

        /// @brief Constructor
        /// @param node XML node
        explicit ArxmlNode(pugi::xml_node &&node);

        /// @brief Get the node short name
        /// @return Short name child text of the node
        std::string GetShortName() const;

        /// @brief Try to get a reference node
        /// @param[in] sourceNode Source node name that is referring to another node
        /// @param[in] destinationType Expected reference destination node type 
        /// @param[out] referenceNode Reference node name
        /// @return True if the expected destination type matches the actual type; otherwise false
        /// @note Reference node argument will be untouched in case of destination type mismatch.
        bool TryGetReference(
            const std::string &sourceNode, const std::string &destinationType,
            std::string &referenceNode) const;
    };
}

#endif