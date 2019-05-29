#include "route_model.h"
#include <iostream>

RouteModel::RouteModel(const std::vector<std::byte> &xml) : Model(xml) {
    int counter = 0;
    for ( auto node : this->Nodes() ) { // this->Nodes() calls the func in Model class
                                        // and return a Model::Node
        m_Nodes.push_back( Node(counter, this, node) );
        counter++;
    }
}

float RouteModel::Node::distance(RouteModel::Node anotherNode) {
    return std::sqrt( std::pow(this->x - anotherNode.x, 2) + std::pow(this->y - anotherNode.y, 2) );
}