#include "SDL.h"


class InputHandler
{
public:
	~InputHandler() {}
	static InputHandler* Instance()
	{
		if (s_pInstance == 0) {
			s_pInstance = new InputHandler();
		}
		return s_pInstance;
	}
	bool isKeyDown(SDL_Scancode key);
	void update();
	void clean();  // ����̽� ���� �ʱ�ȭ�� �κ��� clear 



private:
	InputHandler();
	const Uint8* m_keyStates;
	static InputHandler* s_pInstance;
};


typedef InputHandler TheInputHandler;