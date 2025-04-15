#include "Role.h"

void Model::Roles::Role::detect_objects(View::AntDrawable& drawable_ant, Core::EventManager& event_manager) {
    event_manager.detect_objects(drawable_ant);
}