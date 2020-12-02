#include "AppLaucher.h"

#include "Logger.h"

AppLaucher* AppLaucher::m_instance = nullptr;

AppLaucher::AppLaucher()
{
}

AppLaucher* AppLaucher::instance()
{
    if (nullptr == m_instance)
    {
        m_instance = new AppLaucher();
    }

    return m_instance;
}

void AppLaucher::init()
{
    Logger::Print("app start");
}

void AppLaucher::exit()
{
    Logger::Print("app exit");
}
