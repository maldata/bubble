#include "checkbox.h"

namespace bubble
{
    checkbox::checkbox(std::string label, bool checked)
        : _label(label), _checked(checked)
    {

    }

    checkbox::~checkbox()
    {

    }

    std::string checkbox::getLabel()
    {
        return _label;
    }

    bool checkbox::getChecked()
    {
        return _checked;
    }
}
