#pragma once
class AppLaucher
{
	AppLaucher();

public:
	static AppLaucher* instance();

	void init();
	void exit();

private:
	static AppLaucher* m_instance;
};

