#ifndef CHECKBOX_H
#define CHECKBOX_H

#include <string>

namespace bubble
{
    class checkbox
    {
    public:
        checkbox(std::string label, bool checked);
        virtual ~checkbox();

        std::string getLabel();
        bool getChecked();

    private:
        std::string _label;
        bool _checked;
    };
}
#endif // CHECKBOX_H
