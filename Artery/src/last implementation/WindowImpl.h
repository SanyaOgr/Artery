#pragma once
#include <string>
#include <queue>
#include <functional>

#include "Events/Event.h"
#include "Platform/WindowHandle.h"

namespace engine
{
    //class Event;

    class WindowImpl
    {
    public:
        static WindowImpl* Create(const std::string& title, unsigned int width, unsigned int height);

        virtual ~WindowImpl();

        virtual WindowHandle GetHandle() const = 0;

        virtual void SetTitle(const std::string& title) = 0;

        virtual void Update();

    protected:
        WindowImpl();
    };

}